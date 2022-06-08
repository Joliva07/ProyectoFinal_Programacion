//CRUD DE EMPLEADOS
#pragma once
#include "ConexionBD.h"
#include <iostream>
#include "Persona.h"
#include <mysql.h>
#include <string>
#include <string.h>

using namespace std;

class Empleado :public Persona{
private:
	string DPI;
	
private:
	string fecha_nacimiento, fecha_inicio_labores, fechaingreso;
	int idpuesto = 0;

public:
	Empleado() {
	}
	Empleado(string nom, string ape, string dir,string fn, int tel, bool gen,string dpi,int id_puesto, string fecha_inilab, string fecha_ingre) : Persona(nom,ape,dir,fn,tel,gen) {

		//fecha_nacimiento = fn;
		fecha_inicio_labores = fecha_inilab;
		fechaingreso = fecha_ingre;
		DPI = dpi;
		idpuesto = id_puesto;
	}


	///////////////////////METODOS//////////////////////////////

	void leer() {
		ConexionBD cn = ConexionBD();
		int q_estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		//cout << "id_e" << "| " << "nombres" << " | " << "apellidos" << " | " << "direccion" << " | " << "telefono" << " | " << "DPI\t\t" << " | " << "SEXO" << " | " << "F_NAC" << " | " << "PUESTO" << " | " << "F_INICIO_LABORAR" << " | " << "F_INGRESO" << " | " << endl;

		if (cn.getconectar()) {
			string consulta =
				"select e.idempleado,e.nombres,e.apellidos,e.direccion,e.telefono,e.dpi, CASE when e.genero = 1 then 'masculino' when e.genero = 0 then 'femenino' end as generotext,e.fecha_nacimiento, p.puesto, e.fecha_inicio_labores, e.fechaingreso from empleados as e inner join puestos as p on e.idpuesto=p.idPuesto;";
			const char* con = consulta.c_str(); //convertimos a char
			q_estado = mysql_query(cn.getconectar(), con);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());

				while (fila = mysql_fetch_row(resultado)) {
					/*for (int i = 0; i <= 10; i++) {
						cout << fila[i] << " , ";
					}
					cout << endl;*/
					cout << "Id empleado: " << fila[0] << "\tDPI: " << fila[5] <<"\tPuesto:"<<fila[8] << endl;
					cout << "Nombre: " << fila[1] << " " << fila[2] << endl;
					cout << "Direccion: " << fila[3] << "\tTelefono: " << fila[4] << "\tGenero: " << fila[6] << endl;
					cout << "Fecha de nacimiento: " << fila[7] << endl;
					cout << "Inicio de labores: " << fila[9] << "\tFecha ingreso: " << fila[10] << endl << endl;
				}
			}
			else {
				cout << " error al hacer select XXX" << endl;
			}
		}
		else {
			cout << " xxx sin conexion xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		string ip = to_string(idpuesto);
		string gen = to_string(genero);

		if (cn.getconectar()) {
			string insert =
				"INSERT INTO empleados(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, idpuesto, fecha_inicio_labores, fechaingreso)VALUES('"+ nombres +"', '"+ apellidos +"', '"+ direccion +"', '"+ t +"', '"+ DPI +"', "+ gen +", '"+ fecha_nacimiento+ "', '"+ ip +"', '"+ fecha_inicio_labores +"', '"+ fechaingreso+ "');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "ingreso exitoso !!!!!!!!" << endl;
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
	/*
	void actualizar(int x) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string aux_j = to_string(telefono);
		string auxi = to_string(genero);
		string auxii = to_string(idpuesto);
		string where = to_string(x);
		if (cn.getconectar()) {
			string act = "update empleados SET nombres = '" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono = '" + aux_j + "',dpi = '" + DPI + "', genero =" + auxi + ", fecha_nacimiento = '" + fecha_nacimiento + "', idpuesto = " + auxii + ", fecha_inicio_labores = '" + fecha_inicio_labores + "', fechaingreso = '" + fechaingreso + "',where idempleado = " + where + ";";
			const char* a = act.c_str();
			q_estado = mysql_query(cn.getconectar(), a);
			if (!q_estado) {
				cout << " REGISTRO MODIFICADO !!!!!!!" << endl;
			}

			else {
				cout << "  xxx error al hacer update xxx  " << endl;
			}
		}
		else {
			cout << " xxx ERROR AL CONECTAR xxx" << endl;
		}
		cn.cerrar_conexion();
	}
	*/

	void eliminar(int x) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string where = to_string(x);
		if (cn.getconectar()) {
			string eliminar = "delete from empleados where idempleado= " + where + ";";
			const char* eli = eliminar.c_str();
			q_estado = mysql_query(cn.getconectar(), eli);
			if (!q_estado) {
				cout << " BORRADO EXITOSO !!!!!" << endl;
			}
			else {
				cout << " Este empleado no puede ser borrado en este momento " << endl;
			}
		}
		else {
			cout << "xxx ERROR DE CONEXION xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer(int x) {
		ConexionBD cn = ConexionBD();
		int q_estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string aux_busqueda = to_string(x);
		cn.abrir_conexion();
		//cout << "id_e" << "| " << "nombres" << " | " << "apellidos" << " | " << "direccion" << " | " << "telefono" << " | " << "DPI\t\t" << " | " << "SEXO" << " | " << "F_NAC" << " | " << "PUESTO" << " | " << "F_INICIO_LABORAR" << " | " << "F_INGRESO" << " | " << endl;

		if (cn.getconectar()) {
			string consulta = "select e.idempleado,e.nombres,e.apellidos,e.direccion,e.telefono,e.dpi, CASE when e.genero = 1 then 'masculino' when e.genero = 0 then 'femenino' end as generotext,e.fecha_nacimiento, p.puesto, e.fecha_inicio_labores, e.fechaingreso from empleados as e inner join puestos as p on e.idpuesto=p.idPuesto where dpi="+aux_busqueda+";";
			const char* con = consulta.c_str(); //convertimos a char
			q_estado = mysql_query(cn.getconectar(), con);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());

				while (fila = mysql_fetch_row(resultado)) {
				/*	for (int i = 0; i <= 10; i++) {
						cout << fila[i] << " , ";
					}
					cout << endl;*/
					cout << "Id empleado: " << fila[0] << "\tDPI: " << fila[5] << "\tPuesto:" << fila[8] << endl;
					cout << "Nombre: " << fila[1] << " " << fila[2] << endl;
					cout << "Direccion: " << fila[3] << "\tTelefono: " << fila[4] << "\tGenero: " << fila[6] << endl;
					cout << "Fecha de nacimiento: " << fila[7] << endl;
					cout << "Inicio de labores: " << fila[9] << "\tFecha ingreso: " << fila[10] << endl << endl;

				}
			}
			else {
				cout << " error al hacer select XXX" << endl;
			}
		}
		else {
			cout << " xxx sin conexion xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	///////////////////////////
	void actualizar(int x) {
	
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		
		string tel = to_string(telefono);
		string gentext = to_string(genero);
		string id_puesto = to_string(idpuesto);
		string i = to_string(x);
		if (cn.getconectar()) {
			string update = "update empleados SET nombres = '" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono = '" + tel + "', genero =" + gentext + ", fecha_nacimiento = '" + fecha_nacimiento + "', idpuesto = " + id_puesto + ", fecha_inicio_labores = '" + fecha_inicio_labores + "', fechaingreso = '" + fechaingreso + "' where dpi = " + i + ";";
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
	///////////////////////////

	void setNombre(string nom) {nombres = nom;}
	void setApellido(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setGenero(bool gen) { genero = gen; }
	void setDpi(string dpi) { DPI=dpi; }
	void setIDpuesto(int id_puesto) { idpuesto = id_puesto; }
	void setF_nacimiento(string fn) { fecha_nacimiento = fn; }
	void setF_inilab(string f_inilab) { fecha_inicio_labores = f_inilab; }
	void setF_ingre(string fecha_ingre) { fechaingreso = fecha_ingre; }
};



