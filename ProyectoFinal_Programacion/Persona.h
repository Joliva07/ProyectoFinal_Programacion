#pragma once
#include<iostream>
using namespace std;

class Persona{
protected: string nombres, apellidos, direccion;
		 int telefono = 0;
		 bool genero = true;

public:
	Persona() {
	}
	Persona(string nom, string ape, string dir, int tel, bool gen) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		genero = gen;
		

	}

};

