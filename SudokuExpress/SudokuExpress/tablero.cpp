#include "tablero.h"
using namespace std;

tablero::tablero() 
{
	inicializarTablero();
}

void tablero::inicializarTablero()
{
	int m[3][3] = { {0,1,2},{3,4,5},{6,7,8} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			matrizTab[i][j] = region(3 * i + j, m);
	}
}

bool tablero::comprobarIguales(int pos[], int seleccion, int tamActual) {

	bool iguales = false;

	for (int i = 0; i < tamActual && iguales == false; i++) {
		if (pos[i] == seleccion) {
			iguales = true;
		}
	}

	return iguales;
}

void tablero::crearRegion() 
{
	int num = rand() % 4 + 1;
	int pos[4], valores[4];	//cambiar 4 por num (encontrar el modo)
	int seleccion;

	for (int i = 0; i < 4; i++) {
		if (i < num) {

			seleccion = rand() % 9;
			while (comprobarIguales(pos, seleccion, i) == true) {
				seleccion = rand() % 9;
			}

			pos[i] = seleccion;
		}
		else
			pos[i] = -1;
	}

	for (int i = 0; i < 4; i++) {
		if (i < num) {

			seleccion = rand() % 9 + 1;
			while (comprobarIguales(pos, seleccion, i) == true) {
				seleccion = rand() % 9 + 1;
			}

			pos[i] = seleccion;
		}
		else
			pos[i] = -1;
	}
}