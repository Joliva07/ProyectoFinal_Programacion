#pragma once
#include<iostream>
#include "Persona.h"
#include"ConexionBD.h"
#include<string.h>
#include<string>
using namespace std;

class Proveedor : public Persona {


public: string nit;

public:
	Proveedor() {
	}
	/*a y g son solo variables que no tienen proposito, solo estan ahi porque la clase persona las necesita instanciadas
	ademas el nombre del proveedor aqui lo estoy considerando como nombre de la clase persona*/
	Proveedor(string nom,string ape,string dir,string fn,int tel, bool gen, string numero_identificacion_t) :Persona (nom,ape,dir,fn,tel,gen) {
		
		nit = numero_identificacion_t;
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		
		string t = to_string(telefono);
		

		if (cn.getconectar()) {
			string insert =
				//corregir 
				"INSERT INTO proveedores(proveedor, nit, direccion,telefono) VALUES('" + nombres + "', '" + nit + "', '" + direccion + "'," + t + ");";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "ingreseo exitoso !!!!!!!!" << endl;
			}
			else {
				cout << "xxx ERROR AL HACER INSERT xxx" << endl;
			}
		}
		else {
			cout << " xxx ERROR en LA CONEXION xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_query;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select * from proveedores";
			const char* c = consulta.c_str();
			q_query = mysql_query(cn.getconectar(), c);
			cout << "\n---------- PROVEEDORES ----------\n";
			//cout << "\nidproveedores, nombres, nit, direccion, telefono\n\n";
			if (!q_query) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					/*for (int i = 0; i <= 4; i++) {
						cout << fila[i] << " , ";
					}
					cout << endl;*/
					cout << "Nit: " << fila[2] << endl;
					cout << "Proveedor: " << fila[1] << endl;
					cout << "Direccion: " << fila[3] << "\tTelefono: " << fila[4] << endl << endl;

				}
			}
			else {
				cout << "Error al consultar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.cerrar_conexion();
	}

	void leer(int x) {
		int q_query;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string ip = to_string(x);
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select * from proveedores where nit=" + ip + ";";
			const char* c = consulta.c_str();
			q_query = mysql_query(cn.getconectar(), c);
			cout << "\n---------- PROVEEDORES ----------\n";
			//cout << "\nidproveedores, nombres, nit, direccion, telefono\n\n";
			if (!q_query) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					/*for (int i = 0; i <= 4; i++) {
						cout << fila[i] << " , ";
					}
					cout << endl;*/
					cout << "Nit: " << fila[2] << endl;
					cout << "Proveedor: " << fila[1] << endl;
					cout << "Direccion: " << fila[3] << "\tTelefono: " << fila[4] << endl << endl;

				}
			}
			else {
				cout << "Error al consultar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.cerrar_conexion();
	}

	void actualizar(int x) {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		
		string ip = to_string(x);
		string t = to_string(telefono);
		

		if (cn.getconectar()) {
			string update = "update proveedores SET proveedor = '"+nombres+"',  direccion = '"+direccion+"',telefono= '"+t+"' where nit = "+ip+ ";";
			const char* upda = update.c_str();
			q_estado = mysql_query(cn.getconectar(), upda);
			if (!q_estado) {
				cout << " modificado " << endl;
			}
			else {
				cout << "error xxx" << endl;
			}

		}
		else {
			cout << " error de conexion xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar(int x) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string where = to_string(x);
		if (cn.getconectar()) {
			string eliminar = "delete from proveedores where nit = " + where + ";";
			const char* eli = eliminar.c_str();
			q_estado = mysql_query(cn.getconectar(), eli);
			if (!q_estado) {
				cout << " BORRADO EXITOSO !!!!!" << endl;
			}
			else {
				cout << " xxx ERROR al hacer DELETE xxx " << endl;
			}
		}
		else {
			cout << "xxx ERROR DE CONEXION xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	//void setProducto(string pro) { producto = pro; }
	void setProveedor(string nom) { nombres = nom; }
	void setNit(string n) { nit = n; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }


};


