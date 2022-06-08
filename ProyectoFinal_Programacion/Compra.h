#pragma once
#include "ConexionBD.h"
#include "Proveedor.h"
#include <iostream>
#include <string.h>
#include <mysql.h>
#include <cstdlib>
#include <stdio.h>

using namespace std;

class Compra {


public: string idCompra, idCompraDetalle, idProveedor;

public: string idProducto,fecha_orden,fechaingreso;
	  int cantidad = 0, noOrdenCompra = 0;
	  float PrecioCostoUnitario = 0.0, /*costo = 0,*/ total = 0.0;

public:
	Compra() {
	}
	Compra(string idcom,string idcomDet, int noOrCom, string idProv, string idprod, int cant, float precioCU,/* float cost, float tot,*/ string fn_or, string fn_in) {
		idCompra = idcom;
		idCompraDetalle = idcomDet;
		noOrdenCompra = noOrCom;
		idProveedor = idProv;
		idProducto = idprod;
		cantidad = cant;
		PrecioCostoUnitario = precioCU;
		//costo = cost;
		//total = tot;
		fechaingreso = fn_in;
		fecha_orden = fn_or;
	}

	void setProveedor(string ip) { idProveedor = ip; }
	void setICompra(string ic) { idCompra = ic; }
	void setCompraDet(string icd) { idCompraDetalle = icd; }
	void setProducto(string idp) { idProducto = idp; }
	void setFeOr(string fno) { fecha_orden = fno; }
	void setFeIn(string fni) { fechaingreso = fni; }
	void setCant(int cant) { cantidad = cant; }
	void setPCU(float Pcu) { PrecioCostoUnitario = Pcu; }
	void setNoOrden(int noor) { noOrdenCompra = noor; }

	void ingresoCompras() {
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
					string nit, nombres, direccion,n;
					int telefono=0;
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
	}
	   
	void ingresoCompraDet(string prod) {
		int q_consulta;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select p.producto, m.marca, p.descripcion, p.existencia, p.fecha_ingreso from productos as p inner join marcas as m on p.idmarca=m.idmarca where idproductos =" + prod + ";";
			const char* c = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), c);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				cout << "Nombre del producto: " << fila[0] << endl;
				cout << "Marca: " << fila[1] << endl;
				cout << "Descripcion: " << fila[2] << endl;
				cout << "existencias: " << fila[3] << endl;
				cout << "Fecha de ingreso: " << fila[4] << endl;
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

	void insertCompra(string nit) {
		int q_consulta,id=0;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select max(idcompra) from compras;";
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
			string consulta = "select idproveedores from proveedores where nit=" + nit + ";";
			const char* i = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				idProveedor = fila[0];
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

			string no = to_string(noOrdenCompra);
			//añadir las fechas y hora
			string insertar = "insert into compras(no_orden_compra,idproveedor,fecha_orden,fechaingreso) values(" + no + "," + idProveedor + ",'" + fecha_orden + "','" + fechaingreso + "');";
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
	
	void insertComprasDet() {
		string c = to_string(cantidad);
		string p = to_string(PrecioCostoUnitario);
		int q_consulta;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select max(idcompra) from compras;";
			const char* i = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				idCompra = fila[0];
			}
			else {
				cout << "error al consultar";
			}
		}
		else {
			cout << "Error al conectar";
		}

		if (cn.getconectar()) {
			string insert = "insert into compras_detalle(idcompra,idproducto,cantidad,precio_costo_unitario) values('" + idCompra + "','" + idProducto + "'," + c + "," + p + ");";
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
			string update = "update productos set existencia=existencia+" + c + ", precio_costo=" + p + " where idproductos=" + idProducto + ";";
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
	
	void lecturacompra() {
		int q_consulta;
		float cant=0.0;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string consulta = "select c.*, pr.*,p.*,m.*,d.* from compras_detalle as d inner join productos as p on d.idproducto=p.idproductos inner join marcas as m on p.idmarca=m.idmarca inner join compras as c on d.idcompra=c.idcompra inner join proveedores as pr on c.idproveedor = pr.idproveedores order by no_orden_compra;";
			const char* c = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), c);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				if (fila = mysql_fetch_row(resultado)) {
					while (fila = mysql_fetch_row(resultado)) {
						cout << "___________________________________________________\n";
						cout << "Id compra: " << fila[0] << "\t\tNo. orden de compra: " << fila[1] << endl;
						cout << "Proveedores: " << fila[6] << "\t\tNit: " << fila[7] << endl;
						cout << "Direccion: " << fila[8] << "\t\tTelefono: " << fila[9] << endl;
						cout << "Fecha de orden: " << fila[3] << "\t\tFecha de ingreso: " << fila[4] << endl;
						cout << endl;
						cout << "Detalle de compra: " << fila[21] << endl << "Id Producto: " << fila[10] << endl;
						cout << "Producto: " << fila[11] << "\t\tMarca: " << fila[20] << endl;
						cout << "Descripcion: " << fila[13] << endl;
						cant = atof(fila[24]);
						PrecioCostoUnitario = atof(fila[25]);
						total = cant * PrecioCostoUnitario;
						cout << "Cantidad: " << fila[24] << "\tPrecio c/u: " << fila[25] << "\tTotal de compra: " << total << endl;
						cout << "___________________________________________________\n";
					}
				} else {
					cout << "No hay datos" << endl;
				}
				
			}
			else {
				cout << "Error select\n";
			}
		}
		else {
			cout << "Error\n";
		}
		cn.cerrar_conexion();
	}
	
	void lecturacompra(string idcompra) {
		int q_consulta;
		float cant = 0.0;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string consulta = "select c.*, pr.*,p.*,m.*,d.* from compras_detalle as d inner join productos as p on d.idproducto=p.idproductos inner join marcas as m on p.idmarca=m.idmarca inner join compras as c on d.idcompra=c.idcompra inner join proveedores as pr on c.idproveedor = pr.idproveedores where c.no_orden_compra=" + idcompra + ";";
			const char* c = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), c);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				if (fila = mysql_fetch_row(resultado)) {
					while (fila = mysql_fetch_row(resultado)) {
						cout << "___________________________________________________\n";
						cout << "Id compra: " << fila[0] << "\t\tNo. orden de compra: " << fila[1] << endl;
						cout << "Proveedores: " << fila[6] << "\t\tNit: " << fila[7] << endl;
						cout << "Direccion: " << fila[8] << "\t\tTelefono: " << fila[9] << endl;
						cout << "Fecha de orden: " << fila[3] << "\t\tFecha de ingreso: " << fila[4] << endl;
						cout << endl;
						cout << "Detalle de compra: " << fila[21] << endl << "Id Producto: " << fila[10] << endl;
						cout << "Producto: " << fila[11] << "\t\tMarca: " << fila[20] << endl;
						cout << "Descripcion: " << fila[13] << endl;
						cant = atof(fila[24]);
						PrecioCostoUnitario = atof(fila[25]);
						total = cant * PrecioCostoUnitario;
						cout << "Cantidad: " << fila[24] << "\tPrecio c/u: " << fila[25] << "\tTotal de compra: " << total << endl;
						cout << "___________________________________________________\n";
					}
				} else {
					cout << "No hay datos" << endl;
				}
				
			}
			else {
				cout << "Error select\n";
			}
		}
		else {
			cout << "Error\n";
		}
		cn.cerrar_conexion();
	}

	void eliminar(string no) {
		int q_consulta;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select idcompra from compras where no_orden_compra=" + no + ";";
			const char* i = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				idCompra = fila[0];
			}
			else {
				cout << "error al consultar";
			}

		}
		if (cn.getconectar()) {
			string elim = "delete from compras_detalle where idcompra=" + idCompra + ";";
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
			string elim = "delete from compras where idcompra=" + idCompra + ";";
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
	
	void actualizarcompra(string idcompra,string idPro) {
		int q_consulta;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select idproveedores from proeveedores where nit='" + idPro + "';";
			const char* i = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				idProveedor = fila[0];
			}
			else {
				cout << "error al consultar";
			}

		}
		else {
			cout << "Error al conectar";
		}

		if (cn.getconectar()) {
			string update = "update compras set idproveedor=" + idProveedor + ",fechaingreso='" + fechaingreso + "'  where no_orden_compra='" + idcompra + "';";
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
	
	void actualizardet(string idcompradet) {
		int q_consulta;
		string c = to_string(cantidad);
		string p = to_string(PrecioCostoUnitario);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string update = "update compras_detalle set idproducto=" + idProducto + ",cantidad=" + c + ",precio_costo_unitario=" + p + "where idcompra_detalle=" + idcompradet + " ;";
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
		if (cn.getconectar()) {
			string update = "update productos set existencia=existencia+" + c + ", precio_costo=" + p + " where idproductos=" + idProducto + ";";
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

};