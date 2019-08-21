#include "region.h"
using namespace std;

region::region()
{
}

region::region(int id, int matriz[3][3])
{
	this->id = id;

	int i = 0;
	int j = 0;
	cout << "Region con id: " << id << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrizReg[i][j] = matriz[i][j];

			cout << matrizReg[i][j] << endl;
		}
	}
}

bool region::comprobarFila(int fila, int seleccion) {

	int valor;

	bool iguales = false;

	for (int i = 0; i < 3 && iguales == false; i++) {

		valor = matrizReg[fila][i];

		if (seleccion == valor) {
			iguales = true;
		}
	}

	return iguales;
}
