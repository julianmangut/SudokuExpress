#pragma once
#include <iostream>

typedef int matrizRegion[3][3];

class region
{
private:
	int id = NULL;
	matrizRegion matrizReg;
	
public:
	region();
	region(int id, int matriz[3][3]);
};
