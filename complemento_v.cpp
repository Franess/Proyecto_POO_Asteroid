#include "complemento_v.h"

Vector2f normal_v(Vector2f &v){
float magnitud= sqrt(v.x * v.x + v.y * v.y);
v.x=v.x/magnitud;
v.y=v.y/magnitud;
return v;
}
bool operator> (Vector2f v1,Vector2f v2){
	if ((v1.x > v2.x)or(v1.y > v2.y)){
		return true;
	}
	return false;
};
