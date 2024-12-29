#ifndef NORMALIZAR_H
#define NORMALIZAR_H
#include <cmath>
using namespace std;
Vector2f normal_v(Vector2f& v){
	float magnitud= sqrt(v.x * v.x + v.y * v.y);
	v.x=v.x/magnitud;
	v.y=v.y/magnitud;
	return v;

}
#endif
