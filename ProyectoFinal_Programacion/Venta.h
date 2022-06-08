#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string.h>
#include "Cliente.h"
#include <cstdlib>

using namespace std;



class Venta{

private: string idventa, idcliente, idVenta_detalle;

public: string fechafactura, idempleado, fechaingreso,idproducto,serie="A";
	  int cantidad = 0, noFacrura=0;
	  float precioUnitario = 0.0, total = 0;

public: 
	Venta() {
	}
	Venta(string idv, int nF, string Fcfa,string idcl, string idem, string fcin, string idvd, string idp, int cant /*float pcu,*/) {
		idventa = idv;
		noFacrura = nF;
		fechafactura = Fcfa;
		idcliente = idcl;
		idempleado = idem;
		fechaingreso = fcin;
		idVenta_detalle = idvd;
		idproducto = idp;
		cantidad = cant;
		//precioUnitario = pcu;
	}

	void SetVenta(string idv) { idventa = idv; }
	void SetNoFa(int nF) { noFacrura = nF; }
	void SetFeFa(string Fcfa) { fechafactura = Fcfa; }
	void SetCl(string idcl) { idcliente = idcl; }
	void SetIdEm(string idem) { idempleado = idem; }
	void SetFeIn(string fcin) { fechaingreso = fcin; }
	void SetDet(string idvd) { idVenta_detalle = idvd; }
	void SetidP(string idp) { idproducto = idp; }
	void Setcant(int cant) { cantidad = cant; }
	void SetPCU(float pcu) { precioUnitario = pcu; }

	/*void ingresoCompras() {
		int q_consulta;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select * from proveedores where nit =" + idProveedor + ";";
			const char* c = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), c);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());

				if (fila = mysql_fetch_row(resultado)) {
					idProveedor = fila[0];
					cout << "Nombre del Proveedor: " << fila[1] << endl;
					cout << "Nit: " << fila[2] << endl;
					cout << "Direccion: " << fila[3] << endl;
					cout << "Telefono: " << fila[4] << endl;
				}
				else {
					cout << "El nit ingresado no existe, ingrese datos del proveesor" << endl;
					string nit, nombres, direccion, n;
					int telefono = 0;
					bool n1 = true;
					Proveedor p = Proveedor(nombres, n, direccion, n, telefono, n1, nit);
					cin.ignore();
					cout << "Ingrese el nombre del proveedor:" << endl;
					getline(cin, nombres);
					cout << "Ingrese la direccion: " << endl;
					getline(cin, direccion);
					cout << "Ingrese el numero de telefono: " << endl;
					cin >> telefono;
					p.setProveedor(nombres);
					p.setNit(idProveedor);
					p.setDireccion(direccion);
					p.setTelefono(telefono);
					p.crear();
				}

			}
			else {
				cout << "Error select";
			}
		}
		else {
			cout << "Error";
		}
		cn.cerrar_conexion();
	}*/

	void ingresoVentas() {
		int q_consulta;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		ConexionBD cn = ConexionBD();
		string nit, nombres, apellidos, direccion, n, correoEl, fechain, fechan;
		int telefono = 0;
		char genero1;
		bool genero = true;
		Cliente obj2 = Cliente(nombres, apellidos, n, fechan, telefono, genero, nit, correoEl, fechain);
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select * from clientes where nit ='" + idcliente + "';";
			const char* c = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), c);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());

				if (fila = mysql_fetch_row(resultado)) {
					idcliente = fila[0];
					cout << "Nombre: " << fila[1] << " " << fila[2] << endl;
					cout << "fecha: " << fechafactura << "\t\tSerie: " << serie << endl;
					//cout << "Nit: " << fila[2] << endl;
				}
				else {
					if (idcliente == "CF") {
						string insert =
							"insert into clientes (nombres,apellidos,nit,genero,telefono,correo_electronico,fechaingreso) values('CF', ' ', 'CF',1, '0', '0', '" + fechaingreso + "'); ";
						const char* i = insert.c_str();
						q_consulta = mysql_query(cn.getconectar(), i);
						if (!q_consulta) {
							cout << "ingreso exitoso !!!!!!!!" << endl;
						}
						else {
							cout << "xxx ERROR AL HACER INSERT xxx" << endl;
						}
					}
					else {
						cout << "El nit ingresado no existe, ingrese datos del proveesor" << endl;
						cin.ignore();/*
						cout << "Ingrese el nombre del proveedor:" << endl;
						getline(cin, nombres);
						cout << "Ingrese la direccion: " << endl;
						getline(cin, direccion);
						cout << "Ingrese el numero de telefono: " << endl;
						cin >> telefono;
						p.setProveedor(nombres);
						p.setNit(idProveedor);
						p.setDireccion(direccion);
						p.setTelefono(telefono);
						p.crear();*/
						cout << "ingrese NIT" << endl;
						getline(cin, nit);
						cout << "ingrese nombres" << endl;
						getline(cin, nombres);
						cout << "ingrese apellidos" << endl;
						getline(cin, apellidos);
						cout << "ingrese telefono" << endl;
						cin >> telefono;
						cout << "ingrese genero (m = masculino / f = femenino)" << endl;
						cin >> genero1;
						genero = genero1 == 'm' ? 1 : 0;
						cin.ignore();
						cout << "ingrese correo electronico" << endl;
						getline(cin, correoEl);
						//fechaingreso = calcular_hora();
						cout << "fecha/hora de ingreso" << fechaingreso << endl;;
						obj2.setNombre(nombres);
						obj2.setTelefono(telefono);
						obj2.setNit(nit);
						obj2.setGen(genero);
						obj2.setFecha_in(fechaingreso);
						obj2.setE_mail(correoEl);
						obj2.setApellido(apellidos);
						obj2.crear();
					}
				}

			}
			else {
				cout << "Error select";
			}
		}
		else {
			cout << "Error";
		}
		cn.cerrar_conexion();
	}

	void ingresoCompraDet(string prod) {
		int q_consulta;
		float cant=0.0;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select p.producto, m.marca, p.precio_venta from productos as p inner join marcas as m on p.idmarca=m.idmarca where idproductos =" + prod + ";";
			const char* c = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), c);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				if (fila = mysql_fetch_row(resultado)) {
					fila[0];
					precioUnitario = atof(fila[2]);
					total = cantidad * precioUnitario;
					SetPCU(precioUnitario);
					cout << prod <<"\t" << fila[0] << "\t\t" << fila[1] << "\t\t" << fila[2] << "\t\t" << cantidad << "\t\t" << total << endl;
				}
				else {
					cout << "El producto no existe" << endl;
				}
			}
			else {
				cout << "Error select";
			}
		}
		else {
			cout << "Error consulta";
		}
		cn.cerrar_conexion();
	}
	
	float getPrecio() { return precioUnitario; }

	void insertVenta(string nit) {
		int q_consulta, id = 0;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select max(idventa) from ventas;";
			const char* i = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				if(fila[0]!=NULL) {
					id = atoi(fila[0]);
					id += 1;
				} else {
					id = 1;
				}
			}
			else {
				cout << "error al consultar";
			}
		}
		else {
			cout << "Error al conectar";
		}

		if (cn.getconectar()) {
			string consulta = "select idclientes from clientes where nit='" + nit + "';";
			const char* i = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				idcliente = fila[0];
			}
			else {
				cout << "error al consultar";
			}
		}
		else {
			cout << "Error al conectar";
		}
		if (cn.getconectar()) {
			//noOrdenCompra++;
			string no = to_string(id);
			//añadir las fechas y hora
			string insertar = "insert into ventas(nofactura,serie,fechafactura,idcliente,idempleado,fechaingreso) values(" + no + ",'" + serie + "','" + fechafactura + "'," + idcliente + "," + idempleado + ",'" + fechaingreso + "');";
			const char* i = insertar.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				cout << "Ingreso exitoso\n";
			}
			else {
				cout << "Error al insertar\n";
			}
		}
		else {
			cout << "error conexion\n";
		}
		cn.cerrar_conexion();
	}

	void insertDetalle() {
		string c = to_string(cantidad);
		//string p = to_string(precioUnitario);
		int q_consulta;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select max(idventa) from ventas;";
			const char* i = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				idventa = fila[0];
			}
			else {
				cout << "error al consultar";
			}
		}
		else {
			cout << "Error al conectar";
		}
		if (cn.getconectar()) {
			string consulta = "select precio_venta from productos;";
			const char* i = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				precioUnitario = atof(fila[0]);
			}
			else {
				cout << "error al consultar";
			}
		}
		else {
			cout << "Error al conectar";
		}
		if (cn.getconectar()) {
			string p = to_string(precioUnitario);
			string insert = "insert into ventas_detalle(idventa,idproducto,cantidad,precio_unitario) values(" + idventa + "," + idproducto + "," + c + "," + p + ");";
			const char* i = insert.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				cout << "Ingreso Exitoso";
			}
			else {
				cout << "Error al insertar;";
			}
		}
		else {
			cout << "Error conexion";
		}
		if (cn.getconectar()) {
			string update = "update productos set existencia=existencia-" + c + " where idproductos=" + idproducto + ";";
			const char* i = update.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				cout << "actualizacion exitosa\n";
			}
			else {
				cout << "error al actualiza\n";
			}
		}
		else {
			cout << "Error conexion\n";
		}
		cn.cerrar_conexion();
	}

	void factura() {
		int q_consulta;
			float t2=0;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select max(nofactura), v.*,c.*,e.* from ventas as v inner join clientes as c on v.idcliente = c.idclientes inner join empleados as e on v.idempleado=e.idempleado;";
			const char* c = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), c);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				cout << "\nNo. Factura: " << fila[0] << "\tSerie: " << fila[3] << endl;
				cout << "Fecha: " << fila[4] << endl;
				cout << "Nombre: " << fila[9] << " " << fila[10] << endl;
				cout << "Nit: " << fila[11] << endl;
				cout << "Atendido por: " << fila[17] << " " << fila[18] << endl;
			}
			else {
				cout << "Error select";
			}
		}
		else {
			cout << "Error consulta";
		}
		cout << "___________________________________________" << endl;
		if (cn.getconectar()) {
			string consulta = "select max(idventa),d.*,p.*,m.* from ventas_detalle as d inner join productos as p on d.idproducto=p.idproductos inner join marcas as m on p.idmarca=m.idmarca;";
			const char* c = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), c);
			if (!q_consulta) {
				float cant = 0.0;
				cout << "Id\tproducto\tMarca\t\tcantidad\tprecio\t\tTotal" << endl;
				while (resultado = mysql_store_result(cn.getconectar())) {
					fila = mysql_fetch_row(resultado);
					cant = atof(fila[4]);
					precioUnitario = atof(fila[5]);
					total = cant * precioUnitario;
					cout << fila[3] << "\t" << fila[7] << "\t\t" << fila[16] << "\t\t" << fila[4] << "\t\t" << fila[5]<<"\t\t"<<total;
					t2 = t2 + total;
				}
			}
			else {
				cout << "Error select";
			}
		}
		else {
			cout << "Error consulta";
		}
		cout << "\n\t\t\t\t\t\t    Total de la compra: " << t2 << endl;
		cn.cerrar_conexion();

	}

	void Tventas() {
		int q_consulta,id=0;
		float t2 = 0;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select max(nofactura) from ventas;";
			const char* i = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
					id = atoi(fila[0]);
			}
			else {
				cout << "error al consultar";
			}
		}
		else {
			cout << "Error al conectar";
		}
		for (int i=1; i <= id; i++) {
			if (cn.getconectar()) {
				string consulta = "select v.*,c.*,e.* from ventas as v inner join clientes as c on v.idcliente = c.idclientes inner join empleados as e on v.idempleado=e.idempleado;";
				const char* c = consulta.c_str();
				q_consulta = mysql_query(cn.getconectar(), c);
				if (!q_consulta) {
					resultado = mysql_store_result(cn.getconectar());
					fila = mysql_fetch_row(resultado);
					idventa = fila[0];
					cout << "\nNo. Factura: " << fila[1] << "\tSerie: " << fila[2] << endl;
					cout << "Fecha: " << fila[3] << endl;
					cout << "Nombre: " << fila[8] << " " << fila[9] << endl;
					cout << "Nit: " << fila[10] << endl;
					cout << "Atendido por: " << fila[16] << " " << fila[17] << endl;
				}
				else {
					cout << "Error select";
				}
			}
			else {
				cout << "Error consulta";
			}
			cout << "___________________________________________" << endl;
			if (cn.getconectar()) {
				total = 0; t2 = 0;
				string consulta = "select d.*,p.*,m.* from ventas_detalle as d inner join productos as p on d.idproducto=p.idproductos inner join marcas as m on p.idmarca=m.idmarca where d.idventa="+idventa+";";
				const char* c = consulta.c_str();
				q_consulta = mysql_query(cn.getconectar(), c);
				if (!q_consulta) {
					float cant = 0.0;
					cout << "Id Producto\tproducto\tMarca\t\tcantidad\tprecio\t\tTotal" << endl;
					while (resultado = mysql_store_result(cn.getconectar())) {
						fila = mysql_fetch_row(resultado);
						cant = atof(fila[3]);
						precioUnitario = atof(fila[4]);
						total = cant * precioUnitario;
						cout << fila[2] << "\t\t" << fila[6] << "\t\t" << fila[15] << "\t\t" << fila[3] << "\t\t" << fila[4] << "\t\t" << total;
						t2 = t2 + total;
					}
				}
				else {
					cout << "Error select";
				}
			}
			else {
				cout << "Error consulta";
			}
			cout << "\n\t\t\t\t\t\t\t    Total de la compra: " << t2 << endl << endl << endl;
		}
		cn.cerrar_conexion();
	}

	void Tventas(string nf) {
		int q_consulta;
		float t2 = 0;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select v.*,c.*,e.* from ventas as v inner join clientes as c on v.idcliente = c.idclientes inner join empleados as e on v.idempleado=e.idempleado where nofactura="+nf+";";
			const char* c = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), c);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				idventa = fila[0];
				cout << "\nNo. Factura: " << fila[0] << "\tSerie: " << fila[3] << "\tFecha: " << fila[4] << endl;
				cout << "Nombre: " << fila[8] << " " << fila[9] << endl;
				cout << "Nit: " << fila[10] << endl;
				cout << "Atendido por: " << fila[16] << " " << fila[17] << endl;
			}
			else {
				cout << "Error select";
			}
		}
		else {
			cout << "Error consulta";
		}
		cout << "___________________________________________" << endl;
		if (cn.getconectar()) {
			total = 0; t2 = 0;
			string consulta = "select d.*,p.*,m.* from ventas_detalle as d inner join productos as p on d.idproducto=p.idproductos inner join marcas as m on p.idmarca=m.idmarca where d.idventa=" + idventa + ";";
			const char* c = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), c);
			if (!q_consulta) {
				float cant = 0.0;
				cout << "Id\tId producto\tproducto\tMarca\t\tcantidad\tprecio\t\tTotal" << endl;
				while (resultado = mysql_store_result(cn.getconectar())) {
					fila = mysql_fetch_row(resultado);
					cant = atof(fila[4]);
					precioUnitario = atof(fila[5]);
					total = cant * precioUnitario;
					cout << fila[0]<<"\t"<<fila[2] << "\t\t" << fila[6] << "\t\t" << fila[15] << "\t\t" << fila[3] << "\t\t" << fila[4] << "\t\t" << total;
					t2 = t2 + total;
				}
			}
			else {
				cout << "Error select";
			}
		}
		else {
			cout << "Error consulta";
		}
		cout << "\n\t\t\t\t\t\t\t\t    Total de la compra: " << t2 << endl << endl << endl;
	}

	void acVenta(string nf,string idc) {
		int q_consulta,id=0;
		float t2 = 0;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select idclientes from clientes where nit='" + idc + "';";
			const char* i = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				idcliente = fila[0];
			}
			else {
				cout << "error al consultar";
			}

		}
		else {
			cout << "Error al conectar";
		}

		if (cn.getconectar()) {
			string update = "update ventas set idcliente=" + idcliente + ",idempleado="+idempleado+",fechaingreso='" + fechaingreso + "'  where nofactura=" + nf + ";";
			const char* i = update.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				cout << "actualizacion exitosa\n";
			}
			else {
				cout << "error al actualiza\n";
			}

		}
		else {
			cout << "Error conexion\n";
		}
		cn.cerrar_conexion();



	}

	void acDentalle(string iddet) {
		int q_consulta;
		string c = to_string(cantidad);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string update = "update ventas_detalle set idproducto=" + idproducto + ",cantidad=" + c + "where idventas_detalle=" + iddet + " ;";
			const char* i = update.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				cout << "actualizacion exitosa\n";
			}
			else {
				cout << "error al actualiza\n";
			}

		}
		else {
			cout << "Error conexion\n";
		}
	}

	void eliminar(string no) {
		int q_consulta;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select idventa from ventas where nofactura=" + no + ";";
			const char* i = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				idventa = fila[0];
			}
			else {
				cout << "error al consultar";
			}

		}
		if (cn.getconectar()) {
			string elim = "delete from ventas_detalle where idventa=" + idventa + ";";
			const char* i = elim.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				cout << "Eliminacion exitosa\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		if (cn.getconectar()) {
			string elim = "delete from ventas where idventa=" + idventa + ";";
			const char* i = elim.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				cout << "Eliminacion exitosa\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		cn.cerrar_conexion();
	}
};

