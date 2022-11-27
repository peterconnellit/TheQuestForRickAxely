//Implementation of math functionality
//Return a random integer in range from low to high
#include<cstdlib>

int Random(int low, int high)
{		//Generates random number betveen 0 and max value of int	
	return low + rand() % ((high + 1) - low);
}