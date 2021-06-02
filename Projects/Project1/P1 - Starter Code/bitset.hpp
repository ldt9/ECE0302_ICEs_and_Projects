#ifndef BITSET_HPP
#define BITSET_HPP

#include <cstdlib>
#include <inttypes.h>
#include <string>

class Bitset{
public:

  // sets default valid bitset of width 8, with all bits set to 0
  Bitset();

  // construction of a valid bitset of width "size", where "size" is of type intmax_t, with all bits set to 0, bitset is invalid if "size" <= 0
  Bitset(intmax_t size);

  // bitset initialized with a string in the form "0001000" if the string contains any character other than 0 or 1, bitset is invalid
  Bitset(const std::string & value);

  // deconstructor to delete the memory inside a bitset
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // returns the size of the bitset
  intmax_t size() const;

  // determines if the bitset is valid, can be used in constructors to test if size <= 0 or the string contains characters other than 1 or 0, return true if both condiitons fail
  bool good() const;

  // set the bit to 1 at a specific index, if index not between 0 to (size-1), bitset becomes invalid
  void set(intmax_t index);

  // set the bit to 0 at a specific index, if index not between 0 to (size-1), bitset becomes invalid
  void reset(intmax_t index);

  // toggle the bit at a specific index, if index not between 0 to (size-1), bitset becomes invalid
  void toggle(intmax_t index);

  // test the bit at a specific index, if index not between 0 to (size-1), bitset becomes invalid, if 1 return true, if 0 return false
  bool test(intmax_t index);

  // return the bitset as a string of 0 or 1, MSB to the left, LSB to the right
  std::string asString() const;

private:

  //tells if instance of the class is valid
  bool validity;

  //hold the width of of the bitset, default is 8
  intmax_t width;

  //array of characters to hold each number, bitset width is set to width
  char* bitset;

};

#endif
