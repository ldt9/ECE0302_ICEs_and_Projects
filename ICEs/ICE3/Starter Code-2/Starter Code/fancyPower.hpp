#ifndef FANCYPOWER_HPP
#define FANCYPOWER_HPP

int fancyPower(int n, int x){
	//used to hold the output
	int result;

	if(n == 1) result = x; // initial condition to stop the recursion for n=1
	if(n == 0) result = 1; // initial condition to stop recursion for n=0

	else{
		if (n%2 == 0){
			result = fancyPower((n/2), (x*x)); //if n is an even power
		}
		else{
			result = x*fancyPower(((n-1)/2),(x*x)); //if n is an odd power
		}
	}
	//return final value
	return result;

}

#endif
