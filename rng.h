#ifndef RNG_H
#define RNG_H
#include <ctime>
#include <random>
using namespace std;
int RNG (int max, int min=0){
	mt19937 gen(time(nullptr));
	uniform_int_distribution<> range(min, max);
	return range(gen);
}	
	
#endif
