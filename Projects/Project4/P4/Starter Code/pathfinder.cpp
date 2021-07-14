#include <iostream>
#include <cassert>
#include "string"
#include "image.cpp"
#include "deque.hpp"

//stores matrix coordinates of relevant pixels
struct Coord{
  int x;
  int y;
};

//stores the Coord and distance from source
struct qNode{
  Coord pt;
  int dist;
};
/**
bool isValid(int row, int col){
  //return true if the coordinate is within bounds of the image
  return (row>=0) && (col>=0) && (row < imageInput.height()) && (col < imageInput.width())
}
*/
int main(int argc, char *argv[])
{
  // TODO

  //-1. reading file
  //0. scan map to find source node from 0 to height-1 and 0 to width-1
  //1. put source in a queue at the begining
  //2. do a BFS to add all new white spaces to the queue and then popFront to release the source, and add it to a visited deque
  //3. treat each new white space as a source, but also don't let them visit visited whitespaces in the second deque
  //4. continue until a while space is reached at either height == width == 0, or height = height-1, or width = width-1
  //5. make that space GREEN
  //6. writing to file and compare with output map

  if (argc != 3) return EXIT_FAILURE; //need 3 arguments to run program

  //gathering inFile, outfile strings
  std:: string inputFile = argv[1];
  std:: string outputFile = argv[2];

  Image<Pixel> imageInput = readFromFile(argv[1]); //reading imagefile from string

  //searching for source node (RED PIXEL)
  int startH, startW, redPix = 0;
  for(int i = 0; i < imageInput.height(); i++){
    for(int j = 0; j < imageInput.width(); j++){
      if(imageInput(i, j) == RED){
        startH = i;
        startW = j;
        redPix++;
      }
      //make sure there are no mis colored pixels
      if(imageInput(i, j) != WHITE && imageInput(i, j) != RED && imageInput(i, j) != BLACK) return EXIT_FAILURE;
      //map cannot have more than one red pixel
      if(redPix > 1) return EXIT_FAILURE;
    }
  }

  //testing source node location
  //std::cout << "height: " << startH << " width: " << startW << std:: endl;
  /***********************************
  //Now do BFS to find the maze path//
  **********************************/
  bool visited[imageInput.width()][imageInput.height()];
  memset(visited, false, sizeof visited);

  //mark source as visited
  visited[startW][startH] = true;

  //create a node to hold each coord
  Deque<qNode> q;

  //distance of source cell is 0
  Coord s;
  s.x = startW;
  s.y = startH;
  qNode src = {s, 0};
  //push back starting point
  q.pushBack(src);
/**
  bool validW = imageInput(s.y, s.x) == WHITE;
  bool validB = imageInput(s.y, s.x) == BLACK;
  bool validG = imageInput(s.y, s.x) == GREEN;
  bool validR = imageInput(s.y, s.x) == RED;
  std:: cout << "Pixel origin is white: " << validW << std:: endl;
  std:: cout << "Pixel origin is black: " << validB << std:: endl;
  std:: cout << "Pixel origin is green: " << validG << std:: endl;
  std:: cout << "Pixel origin is red: " << validR << std:: endl;
*/
  //do BFS from source cell
  while(!q.isEmpty()){
    qNode current = q.front();
    Coord pt = current.pt;

/**  std:: cout << "x coord: " << pt.x << " y coord: " << pt.y << std:: endl;
    validW = imageInput(pt.x, pt.y) == WHITE;
     validB = imageInput(pt.x, pt.y) == BLACK;
     validG = imageInput(pt.x, pt.y) == GREEN;
     validR = imageInput(pt.x, pt.y) == RED;
    std:: cout << "Pixel origin is white: " << validW << std:: endl;
    std:: cout << "Pixel origin is black: " << validB << std:: endl;
    std:: cout << "Pixel origin is green: " << validG << std:: endl;
    std:: cout << "Pixel origin is red: " << validR << std:: endl;
     validW = imageInput(pt.x+1, pt.y) == WHITE;
     validB = imageInput(pt.x+1, pt.y) == BLACK;
     validG = imageInput(pt.x+1, pt.y) == GREEN;
     validR = imageInput(pt.x+1, pt.y) == RED;
    std:: cout << "Pixel right is white: " << validW << std:: endl;
    std:: cout << "Pixel right is black: " << validB << std:: endl;
    std:: cout << "Pixel right is green: " << validG << std:: endl;
    std:: cout << "Pixel right is red: " << validR << std:: endl;
     validW = imageInput(pt.x-1, pt.y) == WHITE;
     validB = imageInput(pt.x-1, pt.y) == BLACK;
     validG = imageInput(pt.x-1, pt.y) == GREEN;
     validR = imageInput(pt.x-1, pt.y) == RED;
    std:: cout << "Pixel left is white: " << validW << std:: endl;
    std:: cout << "Pixel left is black: " << validB << std:: endl;
    std:: cout << "Pixel left is green: " << validG << std:: endl;
    std:: cout << "Pixel left is red: " << validR << std:: endl;
     validW = imageInput(pt.x, pt.y-1) == WHITE;
     validB = imageInput(pt.x, pt.y-1) == BLACK;
     validG = imageInput(pt.x, pt.y-1) == GREEN;
     validR = imageInput(pt.x, pt.y-1) == RED;
    std:: cout << "Pixel above is white: " << validW << std:: endl;
    std:: cout << "Pixel above is black: " << validB << std:: endl;
    std:: cout << "Pixel above is green: " << validG << std:: endl;
    std:: cout << "Pixel above is red: " << validR << std:: endl;
     validW = imageInput(pt.x, pt.y+1) == WHITE;
     validB = imageInput(pt.x, pt.y+1) == BLACK;
     validG = imageInput(pt.x, pt.y+1) == GREEN;
     validR = imageInput(pt.x, pt.y+1) == RED;
    std:: cout << "Pixel below is white: " << validW << std:: endl;
    std:: cout << "Pixel below is black: " << validB << std:: endl;
    std:: cout << "Pixel below is green: " << validG << std:: endl;
    std:: cout << "Pixel below is red: " << validR << std:: endl;
*/
    //if we reach the destination cell, end the pathfinder
    if(pt.x == 0 || pt.y == 0 || pt.x == imageInput.width()-1 || pt.y == imageInput.height()-1){
      //found the pixel, make it green
      imageInput(pt.y, pt.x) = GREEN;
      //write to file the new image
      writeToFile(imageInput, outputFile);
       std:: cout << "Solution Found" << std:: endl;
      return EXIT_SUCCESS;
    }

    //current pixel matter no more because it is not the edge
    q.popFront();

    if(imageInput(pt.y+1, pt.x) != BLACK && !visited[pt.x][pt.y+1]){
      //add it to the visited array
      visited[pt.x][pt.y+1] = true;
      //create a new coord
      Coord c;
      c.x = pt.x;
      c.y = pt.y+1;
      //new qNode to push back
      //std:: cout << "Enqueued below neighbor at (" << c.x << ", " << c.y << ")" << std:: endl;
      qNode cNew = {c, cNew.dist++};
      q.pushBack(cNew);
    }

    if(imageInput(pt.y, pt.x-1) != BLACK && !visited[pt.x-1][pt.y]){
      //add it to the visited array
      visited[pt.x-1][pt.y] = true;
      //create a new coord
      Coord c;
      c.x = pt.x-1;
      c.y = pt.y;
      //new qNode to push back
      //std:: cout << "Enqueued left neighbor at (" << c.x << ", " << c.y << ")" << std:: endl;
      qNode cNew = {c, cNew.dist++};
      q.pushBack(cNew);
    }

    if(imageInput(pt.y, pt.x+1) != BLACK && !visited[pt.x+1][pt.y]){
      //add it to the visited array
      visited[pt.x+1][pt.y] = true;
      //create a new coord
      Coord c;
      c.x = pt.x+1;
      c.y = pt.y;
      //new qNode to push back
      //std:: cout << "Enqueued right neighbor at (" << c.x << ", " << c.y << ")" << std:: endl;
      qNode cNew = {c, cNew.dist++};
      q.pushBack(cNew);
    }

    if(imageInput(pt.y-1, pt.x) != BLACK && !visited[pt.x][pt.y-1]){
      //add it to the visited array
      visited[pt.x][pt.y-1] = true;
      //create a new coord
      Coord c;
      c.x = pt.x;
      c.y = pt.y-1;
      //new qNode to push back
      //std:: cout << "Enqueued above neighbor at (" << c.x << ", " << c.y << ")" << std:: endl;
      qNode cNew = {c, cNew.dist++};
      q.pushBack(cNew);
    }
  }

  std:: cout << "No Solution Found" << std:: endl;
  return EXIT_FAILURE;
}
