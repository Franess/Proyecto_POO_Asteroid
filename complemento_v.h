#ifndef NORMALIZAR_H
#define NORMALIZAR_H
#include <cmath>
#include <SFML/System/Vector2.hpp>
using namespace sf;
using namespace std;

Vector2f normal_v(Vector2f &v);
float producto_escalar(Vector2f a, Vector2f b);
bool operator> (Vector2f v1,Vector2f v2);
Vector2f operator* (int a, Vector2f v);
Vector2f operator/ (int a, Vector2f v);
Vector2f operator* (Vector2f v1, Vector2f v2);
Vector2f operator/ (Vector2f v1, Vector2f v2);
#endif
