#include "rng.h"
int RNG (int max, int min)
{
	static mt19937 gen(time(nullptr));
	uniform_int_distribution<> range(min, max);
	return range(gen);
}	
