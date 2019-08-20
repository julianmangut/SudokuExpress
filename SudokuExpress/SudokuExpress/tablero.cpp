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

			crearRegion(matrizReg);

			matrizTab[i][j] = region(3 * i + j, matrizReg);
		}
	}
}

bool tablero::comprobarFila() {

}

bool tablero::comprobarColumna() {

}

bool tablero::comprobarIgualesPosicion(int pos[], int seleccion, int tamActual) {

	bool iguales = false;

	for (int i = 0; i < tamActual && iguales == false; i++) {
		if (pos[i] == seleccion) {
			iguales = true;
		}
	}

	return iguales;
}

bool tablero::comprobarIgualesValor(int valores[], int seleccion, int tamActual, int posiciones[]) {

	bool iguales = false;

	for (int i = 0; i < tamActual && iguales == false; i++) {
		if (valores[i] == seleccion) {
			iguales = true;
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

void tablero::crearRegion(matrizRegion &matrizReg) 
{

	int num = rand() % 4 + 1;	// Número de números con los que va a contar esa región
	int pos[4], valores[4];	//cambiar 4 por num (encontrar el modo)
	int seleccion;

	for (int i = 0; i < 4; i++) {
		if (i < num) {

			seleccion = rand() % 9;	//Posición en la que se va a encontrar cada número
			while (comprobarIgualesPosicion(pos, seleccion, i) == true) {
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
			
			while (comprobarIgualesValor(valores, seleccion, i, pos) == true) {
				seleccion = rand() % 9 + 1;
			}
			valores[i] = seleccion;
		}
		else
			valores[i] = -1; //Arreglar, se puede mejorar TODO
	}

	crearMatriz(pos, valores, matrizReg);
}