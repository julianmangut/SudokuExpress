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
	void inicializarTablero();
	bool comprobarIguales(int pos[],int seleccion, int tamActual);
	void crearMatriz(int posicion[], int valores[]);
	void crearRegion();
};

