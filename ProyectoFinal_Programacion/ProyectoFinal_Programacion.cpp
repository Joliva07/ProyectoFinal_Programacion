
#include <stdio.h>
#include <iostream>
#include "Empleados.h"
#include <string.h>
using namespace std;
int x = 0;
int op=0, op2=0, op3=0;
int main()
{

	string nombres, apellidos, direccion, dpi, fecha_inicio_lab, fechaingreso,fecha_nac;
	int genero = 0, idpuesto = 0, telefono = 0;
	int op;
	bool ciclo = true;
	do
	{
		bool ciclo2 = true;
		cout << "BIENVENIDO AL SISTEMA DE EL_BUEN_ZAPATO" << endl;
		cout << "1. CRUD empleados" << endl;
		cout << "2. CRUD clientes" << endl;
		cout << "3. SALIR" << endl;
		cout << "ELIJA !" << endl;
		cin >> op;

		do {
		switch (op) {
			
				{
		case 1:
			
			bool ciclo3 = true;
			Empleado obj = Empleado(nombres, apellidos, direccion, telefono, genero, dpi, idpuesto, fecha_nac, fecha_inicio_lab, fechaingreso);

			cout << "INGRESE OPCION" << endl;
			cout << "1 CREAR" << endl;
			cout << "2 LEER" << endl;
			cout << "3 ACTUALIZAR" << endl;
			cout << "4 ELIMINAR" << endl;
			cout << "5. SALIR" << endl;
			cout << "ELIJA !" << endl;
			cin >> op2;

			switch (op2) {

				{
			case 1:
				cout << "ingrese nombres" << endl;
				cin.ignore();
				getline(cin, nombres);
				cout << "ingrese apellidos" << endl;
				getline(cin, apellidos);
				cout << "ingrese fecha nacimiento" << endl;
				getline(cin, fecha_nac);
				cout << "ingrese direccion" << endl;
				getline(cin, direccion);
				cout << "ingrese telefono" << endl;
				cin >> telefono;
				cout << "ingrese DPI" << endl;
				cin >> dpi;
				cout << "ingrese genero (1/0)" << endl;
				cin >> genero;
				cout << "ingrese id puesto" << endl;
				cin >> idpuesto;
				cin.ignore();
				cout << "ingrese fecha que inicio labores" << endl;
				getline(cin, fecha_inicio_lab);
				cout << "ingrese fecha/hora ingreso" << endl;
				getline(cin, fechaingreso);

				obj.crear();
				break;
				}
				{
			case 2:
				system("cls");
				cout << "INFORMACION REVELADA" << endl;
				obj.leer();
				break;
				}
				{
			case 3:
				int busqueda = 0;
				cout << "id a modificar" << endl;
				cin >> x;
				obj.leer(x);
				cout << "MODIFICAR ? (1/0)" << endl;
				cin >> busqueda;
					if (busqueda == 1) {
					obj.actualizar(x);
					}
					else {
						cout << "no hiciste nada" << endl;
					}
				break;

				}
				{
			case 4:
				int busqueda = 0;
				cout << "id a eliminar" << endl;
				cin >> x;
				obj.leer(x);
				cout << "ELIMINAR? (1/0)" << endl;
				cin >> busqueda;
					if (busqueda == 1) {
						obj.eliminar(x);
						}
						else {
							cout << "no hiciste nada" << endl;
						}
						break;
				}

				
			case 5:
				
				ciclo2 = false;
				ciclo3 = false;

				break;
				
			}
			break;
			}

			{
	case 2:
		cout << "hola mundo jajaja" << endl;
		return 0;
		break;
			}

			{
	case 3:
		ciclo = false;
		ciclo2 = false;
		break;
			}
		} 
		} while (ciclo2 != 0);

	
	} while (ciclo!=0);
	
	
	return 0;
}

