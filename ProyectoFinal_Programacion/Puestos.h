#pragma once
#include<iostream>
#include<string.h>
using namespace std;

class Puestos{
private: int idpuesto=0;
public: string puesto;

public:
	Puestos() {
	}
	Puestos(int idpue,string pue) {
		idpuesto = idpue;
		puesto = pue;
	}
};

