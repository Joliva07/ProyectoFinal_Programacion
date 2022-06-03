
#include <stdio.h>
#include <iostream>
#include "Empleado.h"
#include <string.h>
#include <conio.h>
#include "Compra.h"
//nueva libreria, time.h
#include <time.h>
#include "Cliente.h"
#include "Puesto.h"
#include "Proveedor.h"
#include "Producto.h"
#include "Marca.h"

using namespace std;
int busqueda = 0;
int op=0, op2=0, op3=0;
string calcular_hora();
int main()
{

	string nombres="", apellidos="", direccion="", dpi="", fecha_inicio_lab="", fechaingreso="", fecha_nac="",nit="",correo="";
	int idpuesto = 0, telefono = 0;
	
	bool genero=1;

	string idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, idpd[40];
	int cantidad = 0, costo = 0, total = 0, can[40], i = 0;
	float PrecioCostoUnitario = 0, pcu[40];
	char opcion;

	string puesto = "";
	

	char genero1;
	//variables para instanciar objetos productos
	string producto = "", idmarca = "", descripcion = "";
	string id_producto = "";
	int existencia = 0;
	float p_venta = 0, p_costo = 0;
	string img = "";
	
	string marca = "";

	bool ciclo = true;
	do
	{
		system("cls");
		bool ciclo2 = true;
		cout << "BIENVENIDO AL SISTEMA DE EL_BUEN_ZAPATO" << endl;
		cout << "1. CRUD empleados" << endl;
		cout << "2. CRUD clientes" << endl;
		cout << "3. CRUD PUESTOS" << endl;
		cout << "4. CRUD PRODUCTOS" << endl;
		cout << "7. COMPRAR" << endl;
		cout << "8. MARCAS" << endl;
		cout << "9. SALIR" << endl;
		cout << "ELIJA !" << endl;
		cin >> op;

		do {
		switch (op) {
			
				{
		case 1:
			system("cls");
			bool ciclo3 = true;
			//al cambiar el persona.h el constructor tambien cambió, solo miren como se construye el objeto segun personas.h
			Empleado obj = Empleado(nombres, apellidos, direccion, fecha_nac, telefono, genero, dpi, idpuesto, fecha_inicio_lab, fechaingreso);
			
			cout << "\t\t_________________________________________________" << endl;
			cout << "\t\t-------------- TABLA EMPLEADOS -------------------- " << endl;
			cout << "\t\tINGRESE OPCION" << endl;
			cout << "\t\t1 CREAR" << endl;
			cout << "\t\t2 LEER" << endl;
			cout << "\t\t3 ACTUALIZAR" << endl;
			cout << "\t\t4 ELIMINAR" << endl;
			cout << "\t\t5. SALIR" << endl;
			cout << "\t\tELIJA !" << endl;
			cin >> op2;

			switch (op2) {

				{
			case 1:
				system("cls");
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
				cout << "ingrese genero (m = masculino / f = femenino)" << endl;
				cin >> genero1;
				genero = genero1 == 'm' ? 1 : 0;
				
				cout << "ingrese id puesto" << endl;
				cin >> idpuesto;
				cin.ignore();
				cout << "ingrese fecha que inicio labores" << endl;
				getline(cin, fecha_inicio_lab);
				fechaingreso = calcular_hora();
				cout << "fecha/hora de ingreso" << fechaingreso << endl;;
				obj.setNombre(nombres);
				obj.setApellido(apellidos);
				obj.setDireccion(direccion);
				obj.setTelefono(telefono);
				obj.setGenero(genero);
				obj.setDpi(dpi);
				obj.setIDpuesto(idpuesto);
				obj.setF_nacimiento(fecha_nac);
				obj.setF_inilab(fecha_inicio_lab);
				obj.setF_ingre(fechaingreso);


				obj.crear();
				break;
				}
				{
			case 2:
				system("cls");
				cout << "INFORMACION REVELADA" << endl;
				obj.leer();
				system("pause");
				break;
				}
				{
			case 3:
				system("cls");
				char valor;
				cout << "ingrese el DPI del empleado a modificar" << endl;
				cin >> busqueda;
				obj.leer(busqueda);
				cout << "\nDesea modificar ? (s/n): ";
				cin >> valor;
				if (valor == 'n') {
					break;
				}
			
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
						//cout << "ingrese DPI" << endl;
						//cin >> dpi;
						cout << "ingrese genero m/f (masculino = n / femenino = f)" << endl;
						cin >> genero1;
						genero = genero1 == 'm' ? 1 : 0;
						cout << "ingrese id puesto" << endl;
						cin >> idpuesto;
						cin.ignore();
						cout << "ingrese fecha que inicio labores" << endl;
						getline(cin, fecha_inicio_lab);
						fechaingreso = calcular_hora();
						cout << "fecha/hora en que fue hecho el UPDATE : " << fechaingreso << endl;;
						obj.setNombre(nombres);
						obj.setApellido(apellidos);
						obj.setDireccion(direccion);
						obj.setTelefono(telefono);
						obj.setGenero(genero);
						obj.setDpi(dpi);
						obj.setIDpuesto(idpuesto);
						obj.setF_nacimiento(fecha_nac);
						obj.setF_inilab(fecha_inicio_lab);
						obj.setF_ingre(fechaingreso);
						obj.actualizar(busqueda);

						system("pause");
						system("cls");
					
			
				break;

				}
				{
			case 4:
				system("cls");
				int valor = 0;
				cout << "id a eliminar" << endl;
				cin >> busqueda;
				obj.leer(busqueda);
				cout << "ELIMINAR? (1/0)" << endl;
				cin >> valor;
					if (valor == 1) {
						obj.eliminar(busqueda);
						}
						else {
							cout << "Accion cancelada" << endl;
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
			system("cls");
			bool ciclo4 = true;
			Cliente obj2 = Cliente(nombres, apellidos, direccion, fecha_nac, telefono, genero, nit, correo, fechaingreso);

			cout << "\t\t_________________________________________________" << endl;
			cout << "\t\t-------------- TABLA CLIEHTES -------------------- " << endl;
			cout << "\t\tINGRESE OPCION" << endl;
			cout << "\t\t1 CREAR" << endl;
			cout << "\t\t2 LEER" << endl;
			cout << "\t\t3 ACTUALIZAR" << endl;
			cout << "\t\t4 ELIMINAR" << endl;
			cout << "\t\t5. SALIR" << endl;
			cout << "\t\tELIJA !" << endl;
			cin >> op2;

			switch (op2) {

				{
			case 1:
				system("cls");
				cin.ignore();
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
				getline(cin, correo);
				fechaingreso = calcular_hora();
				cout << "fecha/hora de ingreso" << fechaingreso << endl;;
				obj2.setNombre(nombres);
				obj2.setTelefono(telefono);
				obj2.setNit(nit);
				obj2.setGen(genero);
				obj2.setFecha_in(fechaingreso);
				obj2.setE_mail(correo);
				obj2.setApellido(apellidos);
				obj2.crear();
				

				break;
				}
				{
			case 2:

				system("cls");
				obj2.leer();
				system("pause");
				break;
				}

				{
			case 3:
				system("cls");
				char valor;
				cout << "ingrese nit para modificar" << endl;
				cin >> busqueda;
				obj2.leer(busqueda);
				cout << "\nDesea modificar ? (s/n): ";
				cin >> valor;
				if (valor == 'n') {
					break;
				}
				cin.ignore();
				//cout << "ingrese NIT" << endl;
				//getline(cin, nit);
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
				getline(cin, correo);
				fechaingreso = calcular_hora();
				cout << "fecha/hora de ingreso" << fechaingreso << endl;
				obj2.setNombre(nombres);
				obj2.setTelefono(telefono);
				obj2.setNit(nit);
				obj2.setGen(genero);
				obj2.setFecha_in(fechaingreso);
				obj2.setE_mail(correo);
				obj2.setApellido(apellidos);
				obj2.actualizar(busqueda);
				system("pause");
				system("cls");

				break;
				}

				{
			case 4:
				system("cls");
				char valor;
				cout << "ingrese nit para eliminar" << endl;
				cin >> busqueda;
				obj2.leer(busqueda);
				cout << "\nDesea eliminar ? (s/n): ";
				cin >> valor;
				if (valor == 'n') {
					break;
				}

				obj2.eliminar(busqueda);

				break;
				}

				{
			case 5:
				ciclo4 = false;
				ciclo2 = false;
				break;
				}

			}
			break;
			}

	{
	case 3:
		system("cls");
		bool ciclo5 = true;
		Puesto pu = Puesto(puesto);
		cout << "\t\t_______________________________________________________" << endl;
		cout << "\t\t------------------CRUD PUESTOS-------------------------" << endl;
		cout << "\t\tINGRESE OPCION" << endl;
		cout << "\t\t1 CREAR" << endl;
		cout << "\t\t2 LEER" << endl;
		cout << "\t\t3 ACTUALIZAR" << endl;
		cout << "\t\t4 ELIMINAR" << endl;
		cout << "\t\t5. SALIR" << endl;
		cout << "\t\tELIJA !" << endl;
		cin >> op2;

		switch (op2) {

			{
		case 1:
			system("cls");
			cout << "ingrese puesto" << endl;
			cin.ignore();
			getline(cin, puesto);
			pu.setPuesto(puesto);
			pu.crear();
			break;
			}

			{
		case 2:

			system("cls");
			cout << "INFORMACION REVELADA" << endl;
			pu.leer();
			system("pause");
			break;
			}

			{
		case 3:
			system("cls");
			char eleccion;
			cout << "ingrese id a modificar" << endl;
			cin >> busqueda;
			pu.leer(busqueda);
			cout << "\nDesea modificar ? (s/n): ";
			cin >> eleccion;
			if (eleccion == 'n') {
				break;
			}

			cout << "ingrese puesto" << endl;
			cin.ignore();
			getline(cin, puesto);
			pu.setPuesto(puesto);
			pu.actualizar(busqueda);

			system("pause");
			system("cls");


			break;

			}
			{
		case 4:
			system("cls");
			char eleccion;
			cout << "ingrese ID a eliminar: ";
			cin >> busqueda;
			pu.leer(busqueda);
			cout << "\nELIMINAR? (s/n)" << endl;
			cin >> eleccion;
			if (eleccion == 's') {
				pu.eliminar(busqueda);
			}
			else {
				cout << "Accion cancelada" << endl;
			}
			break;
			}
			
		case 5:
			ciclo5 = false;
			ciclo2 = false;
			break;

		}
		
	break;
	}

	{
	case 4:
		system("cls");
		bool ciclo6 = true;
		Producto pro = Producto(producto, idmarca, descripcion, img, p_costo, p_venta, existencia, fechaingreso);
		cout << "\t\t_______________________________________________________" << endl;
		cout << "\t\t------------------productos-------------------------" << endl;
		cout << "\t\tINGRESE OPCION" << endl;
		cout << "\t\t1 CREAR" << endl;
		cout << "\t\t2 LEER" << endl;
		cout << "\t\t3 ACTUALIZAR" << endl;
		cout << "\t\t4 ELIMINAR" << endl;
		cout << "\t\t5. SALIR" << endl;
		cout << "\t\tELIJA !" << endl;
		cin >> op2;

		switch (op2) {

			{
		case 1:
			system("cls");
			cout << "ingrese producto" << endl;
			cin >> producto;
			cout << "ingrese id_marca" << endl;
			cin >> idmarca;
			cin.ignore();
			cout << "ingrese descripcion" << endl;
			getline(cin, descripcion);
			cout << "ingrese precio costo" << endl;
			cin >> p_costo;
			cout << "ingrese precio venta" << endl;
			cin >> p_venta;
			cout << "ingrese existencia" << endl;
			cin >> existencia;
			fechaingreso = calcular_hora();
			cout << "fecha/hora ingreso: " << fechaingreso;
			img = "0";
			pro.setProducto(producto);
			pro.setIDmarca(idmarca);
			pro.setDescrip(descripcion);
			pro.setPrecio_c(p_costo);
			pro.setPrecio_v(p_venta);
			pro.setEXIST(existencia);
			pro.setF_ingre(fechaingreso);
			pro.setIMG(img);
			pro.crear();
			break;
			}

			{
		case 2:
			system("cls");
			cout << " Mostrar registros" << endl;
			
			pro.leer();
			system("pause");
			break;
			}

			{
		case 3:
			system("cls");
			cout << "---------ACTUALIZACION---------------" << endl;
			cout << "Ingrese el id del producto que desea actualizar: " << endl;
			cin >> busqueda;
			cout << "ingrese producto" << endl;
			cin >> producto;
			cout << " ingrese id_marca" << endl;
			cin >> idmarca;
			cin.ignore();
			cout << "ingrese descripcion" << endl;
			getline(cin, descripcion);
			cout << "ingrese precio costo" << endl;
			cin >> p_costo;
			cout << "ingrese precio venta" << endl;
			cin >> p_venta;
			cout << "ingrese existencia" << endl;
			cin >> existencia;
			fechaingreso = calcular_hora();
			cout << "fecha/hora ingreso: " << fechaingreso;
			pro.setProducto(producto);
			pro.setIDmarca(idmarca);
			pro.setDescrip(descripcion);
			pro.setPrecio_c(p_costo);
			pro.setPrecio_v(p_venta);
			pro.setEXIST(existencia);
			pro.setF_ingre(fechaingreso);

			pro.actualizar(busqueda);
			
			break;


			}
			{
		case 4:
			system("cls");
			int op3 = 0;
			cout << "ingrese registro a eliminar" << endl;
			cin >> busqueda;
			pro.leer(busqueda);

			cout << "desea eliminar? (1/0)" << endl;
			cin >> op3;

			if (op3 == 1) {
				pro.eliminar(busqueda);
			}
			else {
				cout << "Accion cancelada" << endl;
			}
			break;
			
			}

		case 5:
			ciclo6 = false;
			ciclo2 = false;
			break;

		}

		break;
	}


			{
	case 7:
		system("cls");
		cout << "REALIZAR COMPRA PARA ADQUIRIR MAS PRODUCTOS" << endl;
		cout << "ingrese opcion" << endl;
			cout << "1. ingresar compra" << endl;
			cout << "2. ver compras" << endl;
			cout << "3. eliminar" << endl;
			cout << "4. actualizar" << endl;
			cout << "ELIJA!!!" << endl;
			cin >> op;
		if (op == 1) {
			system("cls");
			//cout << "Ingrese el No. de orden de compra: ";
			//cin >> noOrdenCompra;
			cout << "Ingrese el Id del Proveedor: ";
			cin >> idProveedor;
			Compra cm = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
			cm.ingresoCompras();
			do {
				cout << "\nIngrese Id del Producto: ";
				cin >> idProducto;
				Compra cm = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
				cm.ingresoCompraDet();
				cout << "Cantidad adquirida: ";
				cin >> cantidad;
				cout << "Costo unitario: ";
				cin >> PrecioCostoUnitario;
				idpd[i] = idProducto;
				can[i] = cantidad;
				pcu[i] = PrecioCostoUnitario;
				if (i < 40) {
					i++;
				}
				cout << "Desea ingresar otro producto? (s/n): ";
				cin >> opcion;
			} while (opcion == 's' || opcion == 'S');
			cout << endl;
			cm.insertCompra();
			for (int x = 0; x < i; x++) {
				idProducto = idpd[x];
				cantidad = can[x];
				PrecioCostoUnitario = pcu[x];
				Compra in = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
				in.insertComprasDet();
			}
		}

		if (op == 2) {
			system("cls");
			cout << "Que desea visualizar: " << endl;
			cout << "1. Todas las compras\n2. Buscar compra especifica";
			cin >> op2;
			if (op2 == 1) {
				Compra cm = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
				cm.lecturacompra();
				system("pause");
			}
			if (op == 2) {
				cout << "Ingrese el No. de orden de compra que desea consultar: ";
				cin >> idCompra;
				Compra cm = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
				cm.lecturacompra(idCompra);
				system("pause");
			}
		}

			if (op == 3) {
				system("cls");
				cout << "Ingrese el id de la compra que desea Eliminar: ";
				cin >> idCompra;
				Compra cm = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
				cm.eliminar(idCompra);
			}

			if (op == 4) {
				system("cls");
				cout << "Seleccione que tipo de actualizacion desea realizar, escriba el numero de la orden de compra: \n";
				cout << "1. Actualizar datos de compra\n2. Actualizar los detalles de una compra\n";
				cin >> op2;

				if (op2 == 1) {
					cout << "escriba el numero de la orden de compra que desea visualizar y actualizar: ";
					cin >> noOrdenCompra;
					Compra cm = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
					cm.lecturacompra(noOrdenCompra);

					cout << "Ingrese el Id del Proveedor: ";
					cin >> idProveedor;
					Compra c = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
					c.actualizarcompra(noOrdenCompra);
				}
				if (op2 == 2) {
					cout << "escriba el numero de la orden de compra que desea visualizar: ";
					cin >> noOrdenCompra;
					Compra cm = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
					cm.lecturacompra(noOrdenCompra);
					do {
						cout << "Indique cual detalle de la compra desea actualizar, escriba el id de esta misma: ";
						cin >> idCompraDetalle;
						cout << "Id de producto: ";
						cin >> idProducto;
						cout << "cantidad: ";
						cin >> cantidad;
						cout << "Precio c/u: ";
						cin >> PrecioCostoUnitario;
						Compra c = Compra(idCompra, idCompraDetalle, noOrdenCompra, idProveedor, idProducto, cantidad, PrecioCostoUnitario, costo, total);
						c.actualizardet(idCompraDetalle);
						cout << "Desea ingresar otro producto? (s/n): ";
						cin >> opcion;
					} while (opcion == 's' || opcion == 'S');
				}

			}

		
			}
			
			{
		case 8:
			system("cls");
			bool ciclo7 = true;
			Marcas ma = Marcas(marca);

			cout << "\t\t_________________________________________________" << endl;
			cout << "\t\t-------------- TABLA MARCAS -------------------- " << endl;
			cout << "\t\tINGRESE OPCION" << endl;
			cout << "\t\t1 CREAR" << endl;
			cout << "\t\t2 LEER" << endl;
			cout << "\t\t3 ACTUALIZAR" << endl;
			cout << "\t\t4 ELIMINAR" << endl;
			cout << "\t\t5. SALIR" << endl;
			cout << "\t\tELIJA !" << endl;
			cin >> op2;

			switch (op2) {
				{
			case 1:
				system("cls");
				cout << "ingrese marca" << endl;
				cin.ignore();
				getline(cin, marca);
				ma.setMarca(marca);


				ma.crear();
				break;
				}


				{
			case 2:
				system("cls");
				cout << "INFORMACION REVELADA" << endl;
				ma.leer();
				system("pause");
				break;
				}
				{
			case 3:
				system("cls");
				char eleccion;
				cout << "ingrese id a modificar" << endl;
				cin >> busqueda;
				ma.leer(busqueda);
				cout << "\nDesea modificar ? (s/n): ";
				cin >> eleccion;
				if (eleccion == 'n') {
					break;
				}

				cout << "ingrese marca" << endl;
				cin.ignore();
				getline(cin, marca);
				ma.setMarca(marca);
				ma.actualizar(busqueda);

				system("pause");
				system("cls");


				break;

				}
				{
			case 4:
				system("cls");
				char eleccion;
				cout << "id a eliminar" << endl;
				cin >> busqueda;
				ma.leer(busqueda);
				cout << "ELIMINAR? (s/n)" << endl;
				cin >> eleccion;
				if (eleccion == 's') {
					ma.eliminar(busqueda);
				}
				else {
					cout << "no hiciste nada" << endl;
				}
				break;
				}

			case 5:
				ciclo7 = false;
				ciclo2 = false;
				break;

			}
			break;
	}



			{
	case 9:
		ciclo = false;	
		ciclo2 = false;
		break;
			}
		} 
		} while (ciclo2 != 0);

	
	} while (ciclo!=0);
	
	
	return 0;
}
;
//metodo nuevo
string calcular_hora() {
	time_t now = time(NULL);
	struct tm tm_now;
	localtime_s(&tm_now, &now);
	char buff[100];
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", &tm_now);
	return buff;
};
