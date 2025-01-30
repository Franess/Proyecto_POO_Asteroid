#ifndef TABLA_DE_PUNTOS_H
#define TABLA_DE_PUNTOS_H
#include <string>
#include <vector>

using namespace std;
struct puntaje{
	int puntos;
	char nombre[16];
};
class tabla_de_puntos {
public:
	tabla_de_puntos();
	void actualizar_archivo_puntaje();
	void actualizar_puntos_j(int puntos_a_sumar);
	void recibir_nombre_j(string nombre_j);
	int get_puntos();
	vector<puntaje> cargar_lista();

private: 
	string archivo_puntos;
	puntaje puntos_jugador;
};
#endif
