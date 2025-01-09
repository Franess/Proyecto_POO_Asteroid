#include "complemento_v.h"

Vector2f normal_v(Vector2f &v){
float magnitud= sqrt(v.x * v.x + v.y * v.y);
	v.x=v.x/magnitud;
	v.y=v.y/magnitud;
return v;
}
float producto_escalar(Vector2f a, Vector2f b){
	return a.x*b.x+a.y*b.y;
}
	
	
bool operator> (Vector2f v1,Vector2f v2){
	if ((v1.x > v2.x)or(v1.y > v2.y)){
		return true;
	}
	return false;
};
Vector2f operator* (int a, Vector2f v){
	v.x=a*v.x;
	v.y=a*v.x;
	return v;
}
Vector2f operator/ (int a, Vector2f v){
	v.x=a/v.x;
	v.y=a/v.x;
	return v;
}
Vector2f operator* (Vector2f v1, Vector2f v2){
	Vector2f aux;
	aux.x=v1.x*v2.x;
	aux.y=v1.y*v2.y;
	return aux;
}
