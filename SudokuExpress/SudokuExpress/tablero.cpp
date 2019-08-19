#include "tablero.h"
#include "time.h"
#include "math.h"
using namespace std;

tablero::tablero() 
{
	inicializarTablero();
}

void tablero::inicializarTablero()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			matrizTab[i][j] = region(3 * i + j, m);
	}

	crearRegion();
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

void tablero::crearMatriz(int posicion[], int valores[]) {

	int matriz[3][3] = { {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1} };
	int fila, columna;

	for (int i = 0; i < 4; i++) {

		if (posicion[i] != -1) {

			fila = ceil(posicion[i] / 3);	//Puede ser que se pueda quitar el redondeo
			columna = posicion[i] % 3;

			matriz[columna][fila] = valores[i];
		}
	}
}

void tablero::crearRegion() 
{
	srand(time(NULL));	//Generador de semilla para random

	int num = rand() % 4 + 1;	// Número de números con los que va a contar esa región
	int pos[4], valores[4];	//cambiar 4 por num (encontrar el modo)
	int seleccion;

	for (int i = 0; i < 4; i++) {
		if (i < num) {

			seleccion = rand() % 9;	//Posición en la que se va a encontrar cada número
			while (comprobarIguales(pos, seleccion, i) == true) {
				seleccion = rand() % 9;
			}

			pos[i] = seleccion;
		}
		else
			pos[i] = -1;	// Arreglar, se puede mejorar TODO
	}

	for (int i = 0; i < 4; i++) {
		if (i < num) {

			seleccion = rand() % 9 + 1;	//Número que se va a poner en la región
			while (comprobarIguales(valores, seleccion, i) == true) {
				seleccion = rand() % 9 + 1;
			}

			valores[i] = seleccion;
		}
		else
			valores[i] = -1; //Arreglar, se puede mejorar TODO
	}

	crearMatriz(pos, valores);
}