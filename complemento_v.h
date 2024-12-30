#ifndef NORMALIZAR_H
#define NORMALIZAR_H
#include <cmath>
#include <SFML/System/Vector2.hpp>
using namespace sf;
using namespace std;

Vector2f normal_v(Vector2f &v);
bool operator> (Vector2f v1,Vector2f v2);
#endif
