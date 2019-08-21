#include "tablero.h"
#include "time.h"
#include "math.h"
using namespace std;

tablero::tablero() 
{
	inicializarTablero();
}

void tablero::reiniciarMatriz(matrizRegion &matrizReg) 
{

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrizReg[i][j] = -1;
		}
	}
}

void tablero::inicializarTablero()
{
	matrizRegion matrizReg;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {

			reiniciarMatriz(matrizReg);

			crearRegion(matrizReg, 3*i+j);

			matrizTab[i][j] = region(3 * i + j, matrizReg);
		}
	}
}

bool tablero::comprobarFila(int seleccion, int posActual, int posiciones[], int idRegion) {

	int filaValor, filaRegion, columnaRegion;
	region region;
	bool iguales = false;

	filaValor = ceil(posiciones[posActual] / 3);	//Puede ser que se pueda quitar el redondeo

	filaRegion = ceil(idRegion / 3);
	columnaRegion = idRegion % 3;

	region = matrizTab[filaRegion][columnaRegion]; // CAMBIAR EL 0 0

	iguales = region.comprobarFila(filaValor, seleccion);
	
	return iguales;
}

bool tablero::comprobarColumna() {

}

bool tablero::comprobarIgualesPosicionValores(int posVal[], int seleccion, int tamActual) {

	bool iguales = false;

	for (int i = 0; i < tamActual && iguales == false; i++) {
		if (posVal[i] == seleccion) {
			iguales = true;
		}
	}

	return iguales;
}

bool tablero::comprobarIguales(int comprobar[], int seleccion, int tamActual, int posiciones[], int idRegion) {

	bool iguales = false;

	iguales = comprobarIgualesPosicionValores(comprobar, seleccion, tamActual);

	if (posiciones != NULL) {
		if (iguales == false && (ceil(idRegion / 3)) != 0) {
			iguales = comprobarFila(seleccion, tamActual, posiciones, idRegion - 1);
		}
	}
	
	return iguales;
}


void tablero::crearMatriz(int posicion[], int valores[], matrizRegion &matrizReg) {

	int fila, columna;

	for (int i = 0; i < 4; i++) {

		if (posicion[i] != -1) {

			fila = ceil(posicion[i] / 3);	//Puede ser que se pueda quitar el redondeo
			columna = posicion[i] % 3;
			matrizReg[fila][columna] = valores[i];
		}
	}
}

void tablero::crearRegion(matrizRegion &matrizReg, int idRegion) 
{

	int num = rand() % 4 + 1;	// Número de números con los que va a contar esa región
	int pos[4], valores[4];	//cambiar 4 por num (encontrar el modo)
	int seleccion;

	for (int i = 0; i < 4; i++) {
		if (i < num) {

			seleccion = rand() % 9;	//Posición en la que se va a encontrar cada número
			while (comprobarIguales(pos, seleccion, i, NULL, NULL) == true) {
				seleccion = rand() % 9;
			}

			pos[i] = seleccion;

			seleccion = rand() % 9 + 1;	//Número que se va a poner en la región

			while (comprobarIguales(valores, seleccion, i, pos, idRegion) == true) {
				seleccion = rand() % 9 + 1;
			}

			valores[i] = seleccion;

		}
		else {
			pos[i] = -1;	// Arreglar, se puede mejorar TODO
			valores[i] = -1; //Arreglar, se puede mejorar TODO
		}
	}

	crearMatriz(pos, valores, matrizReg);
}