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
	bool comprobarFila();
	bool comprobarColumna();
	bool comprobarIgualesPosicion(int pos[],int seleccion, int tamActual);
	bool comprobarIgualesValor(int valores[], int seleccion, int tamActual, int posiciones[]);
	void crearMatriz(int posicion[], int valores[], matrizRegion &matrizReg);
	void crearRegion(matrizRegion &matrizReg);
};

