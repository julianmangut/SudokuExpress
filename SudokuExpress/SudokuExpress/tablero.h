#pragma once
#include <iostream>
#include "region.h"

typedef region matrizTablero[3][3];

class tablero
{
private:
	matrizTablero matrizTab;

public:
	tablero();
	void reiniciarMatriz(matrizRegion &matrizReg);
	void inicializarTablero();
	bool comprobarFila(int seleccion, int posActual, int posiciones[], int idRegion);
	bool comprobarColumna();
	bool comprobarIgualesPosicionValores(int posVal[],int seleccion, int tamActual);
	bool comprobarIguales(int comprobar[], int seleccion, int tamActual, int posiciones[], int idRegion);
	void crearMatriz(int posicion[], int valores[], matrizRegion &matrizReg);
	void crearRegion(matrizRegion &matrizReg, int idRegion);
};

