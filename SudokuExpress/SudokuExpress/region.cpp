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
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrizReg[i][j] = matriz[i][j];
		}
	}

}
