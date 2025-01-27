#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct puntaje{
	int puntos;
	char nombre[16];
};

int main() {
	fstream archi("puntaje.poo", ios::binary|ios::in);
	if (!archi.is_open()){
		cout<<"error al abrir el archivo"<<endl;
	}
	puntaje aux;
	for(int i=0;i<10;i++) { 
	archi.read(reinterpret_cast<char*>(&aux),sizeof(puntaje));
	
	cout<<setw(20)<<left<<aux.nombre<<right<<aux.puntos<<endl;
	}
	archi.close();
	return 0;
}

