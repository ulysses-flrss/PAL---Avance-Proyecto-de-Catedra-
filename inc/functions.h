#include<iostream>
#include<stdio.h>
#include <cstring>
#include <conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream >
#define MAX 50
using namespace std;
//0303 = Ã±
//0301 = Ã¡

int cant = 0;

struct Usuario{
	char username[15];
	char password[15];
};

struct Movimiento {
    int id = 0; //numero incrementable de 1 en uno
    char tipo_origen[10]; // 1- proveedor ; 2-sucursal
    char id_origen[10]; // id del proveedor/sucursal de origen
    char tipo_destino[10]; // 1-venta ; 2-sucursal ; 3-venta
    char id_destino[10]; // id del proveedor/sucursal de destino 
    char id_articulo[10]; //id articulo existente
    int cantidad; //cantidad de articulos
    char motivo_movimiento[30]; //Entradas: "Compra de articulos", "Movimientos entre sucursales", ; Salidas: "", "Venta de articulos", "Devolucion";
    char tipo_movimiento[2]; //E = Entrada, S = Salida
};

struct Sucursal{
	char id[5];
	char descripcion[100];
	char direccion[100];
	char telefono[10];
	char encargado[50];
	char pais[15];
};

struct Proveedores{
	char id[5];
	char nombre[30];
	char apellido[50];
	char identificacion[20];
	char tipoIdentificacion[5];
	char telefono[9];
	char email[100];
	char direccion[100];
};

struct Articulos{
	char id[5];
	char tipoArticulo[25];
	char nombre[50];
	char caracteristicas[100];
	float precioVenta;
	float costo;
	char idProveedor[5];
};

// DECLARACION DE FUNCIONES
void crearMovimiento (int tipo);
void almacenarUsuarios (Usuario admin, Usuario supervisor);
void cargarUsuarios (Usuario admin, Usuario supervisor);
void crearMovimiento (int tipo);
void almacenarMovimientos (Movimiento listado_movimientos[]);
void verMovimientos (Movimiento listado_movimientos[MAX]);
void cargarMovimientos (Movimiento listado_movimientos[]);
void welcome();
void menu_login(Usuario admin, Usuario supervisor);
void login(Usuario admin, Usuario supervisor);
void validarUsuario(char userBuff[15], char passBuff[15], Usuario admin, Usuario supervisor);
void menuAdmin();
void menuSupervisor();
void validacionOpciones(int opcionElegida, int primeraOpcion, int ultimaOpcion);
void menuAdmin2(int opcion);
void subMenuAdmin(int opcion, char area[25]);
void changePassword(int cargo, Usuario admin, Usuario supervisor);
void recoverPassword(int cargo, Usuario admin, Usuario supervisor);
void crearSucursal();
void crearProveedor();
void crearArticulo();
void guardarSucursal(Sucursal, char tareaSel[15], int posicion);
void guardarProveedor(Proveedores, char tareaSel[15], int posicion);
void guardarArticulo(Articulos, char tareaSel[15], int posicion);
void mostrar(char idIng[5], char mostrarTipo[25], char areaSel[25]);
void modificarSucursal(char idIng[5], char areaSel[25], int opcionSel);
int menuAreas(int opcion, char area[25]);
int crearCorrelativo(char areaSel[25]);
int correlativo(char areaSel[25]);
bool validarDatos(char datosIng[100], int numDato);
bool validarTel(char numTel[9]);
bool validarId(char id[5], char areaSel[25]);

void welcome()
{
	cout<<"\t\t Sistema de Control de Inventarios\n";
    cout<<"\t\tEmpresa Salesiana Maria Auxiliadora\n";
    cout<<"\t\t      Version del Sistema 1.0\n";
    cout<<"\t\t        Techno Developers\n\n";
}

void menu_login(struct Usuario admin, struct Usuario supervisor)
{
	int opc = 0;

	do
	{
		welcome();
		cout << "\nQue desea hacer? (Digite un numero)\n";
		cout << "1- Iniciar sesion\n";
		cout << "2- Cambiar Contrasena\n";
		cout << "3- Recuperar Contrasena\n";
		cout << "4- Salir\n";

		while (!(cin>>opc)) {
			cin.clear();
			cin.ignore(255, '\n');
			cout<<"No se permiten letras, presione ENTER e intentelo de nuevo\n";
			getch();
			system("clear");
			system("cls");
			
			welcome();
			cout << "\nQue desea hacer? (Digite un numero)\n";
			cout << "1- Iniciar sesion\n";
			cout << "2- Cambiar Contrasena\n";
			cout << "3- Recuperar Contrasena\n";
			cout << "4- Salir\n";
		}
		
			validacionOpciones(opc, 1, 4);

		switch (opc) {
		case 1:
			login(admin, supervisor);
			break;

		case 2:
			changePassword(0, admin, supervisor);
			break;

		case 3:
			recoverPassword(0, admin, supervisor);
			break;

		case 4:
		exit(1);
			break;

		default:
			break;
		}
	} while (opc < 1 || opc > 4 || opc != 4);
}

void login(struct Usuario admin, struct Usuario supervisor)
{

	char userBuff[15];
	char passBuff[15];

	int intentos = 3 ;

	cout << "Ingrese su nombre de usuario: \n";
	cin >> userBuff;

	cout << "Ingrese su contrasena: \n";
	cin >> passBuff;

	validarUsuario(userBuff, passBuff, admin, supervisor);
}

void validarUsuario(char userBuff[15], char passBuff[15], struct Usuario admin, struct Usuario supervisor)
{
	if (strcmp(admin.username, userBuff) == 0 && strcmp(admin.password, passBuff) == 0) {
		menuAdmin();
	}else if (strcmp(supervisor.username, userBuff) == 0 && strcmp(supervisor.password, passBuff) == 0) {
		menuSupervisor();
	} else {
		cout << "ERROR: Nombre o Usuario Incorrectos. Presione ENTER e Intentelo de Nuevo \n";
		cin.ignore();
		getch();
		login(admin, supervisor);
	};
}

// MENU ADMINISTRADOR
void menuAdmin() {
	int menuOpc = 0;

	do{
		system("cls");
		welcome();
		cout<<"\n";
		cout<<"Elija una opción (Digite un número)\n";
		cout << "1)   Sucursales \n";
		cout << "2)   Proveedores \n";
		cout << "3)   Articulos \n";
		cout << "4)   Movimientos articulos \n";
		cout << "5)   Reportes \n";
		cout << "6)   Salir\n";
		cout << "Seleccione la opcion requerida: \n";

		while (!(cin>>menuOpc)) {
			cin.clear();
			cin.ignore(255, '\n');
			cout<<"No se permiten letras, presione ENTER e intentelo de nuevo\n";
			getch();
			system("clear");
			system("cls");
			
			welcome();
			cout<<"Elija una opción (Digite un número)\n";
			cout << "1)   Sucursales \n";
			cout << "2)   Proveedores \n";
			cout << "3)   Articulos \n";
			cout << "4)   Movimientos articulos \n";
			cout << "5)   Reportes \n";
			cout << "6)   Salir\n";
			cout << "Seleccione la opcion requerida: \n";
		}
			validacionOpciones(menuOpc, 1, 6);
			menuAdmin2(menuOpc);

	} while (menuOpc < 1 || menuOpc > 6 || menuOpc != 6);
}

void menuAdmin2(int opcion) {
	char titulo[5][25] = {"Sucursal", "Proveedor", "Articulo", "Movimientos Articulos", "Reportes"};

	switch (opcion) {
	case 1:
		subMenuAdmin(1, titulo[0]);
		break;

	case 2:
		subMenuAdmin(2, titulo[1]);
		break;

	case 3:
		subMenuAdmin(3, titulo[2]);
		break;

	case 4:
		subMenuAdmin(4, titulo[3]);
		break;

	case 5:
		subMenuAdmin(5, titulo[4]);
		break;

	case 6:
		system("clear");
		system("cls");
		cin.ignore();
		getch();
		break;

	default:
		break;
	}
}

int menuAreas(int opcion, char area[25]){
	int subMenu = 0;
	cout << "Ingresado a " << area << endl;
	cout<<"Elija una opción (Digite un número)\n";
	cout << "1) Registrar " << area << endl;
	cout << "2) Modificar " << area << endl;

	if (opcion == 3) cout << "3) Ver registro de " << area << "s\n";	
	else cout << "3) Ver registro de " << area << "es\n";

	cout << "4) Regresar al menu\n";
	while (!(cin>>subMenu)) {
		cin.clear();
		cin.ignore(255, '\n');
		cout<<"No se permiten letras, presione ENTER e intentelo de nuevo\n";
		getch();
		system("clear");
		system("cls");
		
		welcome();
		cout << "Ingresado a " << area << endl;
		cout<<"Elija una opciÃ³n (Digite un numero)\n";
		cout << "1) Registrar " << area << endl;

		if (opcion == 3) cout << "2) Ver registro de " << area << "s\n";	
		else cout << "2) Ver registro de " << area << "es\n";

		cout << "3) Regresar al menu\n";
		}
		validacionOpciones(subMenu, 1, 3);
		// if(opcion == 1) sucursales(subMenu);
		// else if (opcion == 2) proveedores (subMenu);
	return subMenu;
}

void subMenuAdmin(int opcion, char area[25]) {
	int subMenu = 0, opcionP, opcion1;
	fflush(stdin);
	cout<<"\n";
	switch (opcion) {
	case 1:
	{
		//subMenu = menuAreas(opcion, area);
		char idSucursal[5] = "", areaSel[25] = "Sucursales", mostrarTipo[2][25] = {"especifico", "todo"};
		int opcionP, opcion;
		fflush(stdin);
		Sucursal sucursalUsar;
		do{
			bool repetir = true, regresar = false;
			cout << "1. Registrar sucursal." << endl;
			cout << "2. Ver registro de sucursales." << endl;
			cout << "3. Regresar al menú." << endl;
			cout << "\nSeleccione la opción que prefiera: ";
			cin >> opcionP; cout << endl;
			fflush(stdin);
			switch (opcionP){
				case 1:
					crearSucursal();
				break;
					/**/
				case 2:
					do{
						cout << "\n¿Qué desea ver?" << endl;
						cout << "1. Registros de una sucursal específica." << endl;
						cout << "2. Registros de todas las sucursales." << endl;
						cout << "3. Regresar al menú anterior." << endl;
						cout << "Seleccione la opción que prefiera: ";
						cin >> opcion1; cout << endl;
						if(opcion1 >= 1 && opcion1 <= 3){
							switch (opcion1){
								case 1:
									do{
										cout << "Ingrese el Id de la sucursal: " << endl;
										cin >> idSucursal;
										repetir = validarId(idSucursal, areaSel);
										if (repetir){
											cout << "ERROR. Sucursal no encontrada" << endl;
											do{
												cout << "\n¿Qué desesa hacer?" << endl;
												cout << "1. Buscar con otro id." << endl;
												cout << "2. Cancelar (lo llevará al menú anterior)." << endl;
												cin >> opcion1; cout << endl;
												if (opcion1 < 1 || opcion1 > 2){
													cout << "ERROR. HA INGRESADO UNA OPCIÓN INVÁLIDA" << endl;
												}else if(opcion1 == 1){
													cout << endl;
													regresar = true;
													system("cls");
												}else{
													system("cls");
													subMenuAdmin(opcion, area);
												}
											}while(opcion1 < 1 || opcion1 > 2 || regresar == false);
										}
									}while(repetir);
									mostrar(idSucursal, mostrarTipo[0], areaSel);
								break;
								
								case 2:
									mostrar(idSucursal, mostrarTipo[1], areaSel);
								break;
								
								case 3:
									system("cls");
									menuAdmin();
								break;
								
								default:
								break;
							}
						}
					}while(opcion < 1 || opcion > 3 && opcion != 3);
				break;
				
				case 3:
					system("cls");
					menuAdmin();
				break;
					/**/
				default:
					cout << "ERROR. HA INGRESADO UNA OPCIÓN INVÁLIDA.\n" << endl;
				break;
			}
		}while(opcionP < 1 || opcionP > 4 && opcionP != 4);
	}
	break;
	
	case 2:
	{
		char idProveedor[5] = "", areaSelP[25] = "Proveedores", mostrarTipoP[2][25] = {"especifico", "todo"};
		Proveedores proveedorUsar;
		do{
			bool repetir = true, regresar = false;
			cout << "1. Registrar proveedor." << endl;
			cout << "2. Ver registros de proveedores." << endl;
			cout << "3. Regresar al menú." << endl;
			cout << "\nSeleccione la opción que prefiera: ";
			cin >> opcionP; cout << endl;
			fflush(stdin);
			switch (opcionP){
				case 1:
					crearProveedor();
				break;
					/**/
				case 2:
					do{
						cout << "\n¿Qué desea ver?" << endl;
						cout << "1. Registros de un proveedor específico." << endl;
						cout << "2. Registros de todos los proveedores." << endl;
						cout << "3. Regresar al menú anterior." << endl;
						cout << "Seleccione la opción que prefiera: ";
						cin >> opcion1; cout << endl;
						if(opcion1 >= 1 && opcion1 <= 3){
							switch (opcion1){
								case 1:
									do{
										cout << "Ingrese el Id del proveedor: " << endl;
										cin >> idProveedor;
										repetir = validarId(idProveedor, areaSelP);
										if (repetir){
											cout << "ERROR. Proveedor no encontrado" << endl;
											do{
												cout << "\n¿Qué desesa hacer?" << endl;
												cout << "1. Buscar con otro id." << endl;
												cout << "2. Cancelar (lo llevará al menú anterior)." << endl;
												cin >> opcion1; cout << endl;
												if (opcion1 < 1 || opcion1 > 2){
													cout << "ERROR. HA INGRESADO UNA OPCIÓN INVÁLIDA" << endl;
												}else if(opcion1 == 1){
													cout << endl;
													regresar = true;
													system("cls");
												}else{
													system("cls");
													subMenuAdmin(opcion, area);
												}
											}while(opcion1 < 1 || opcion1 > 2 || regresar == false);
										}
									}while(repetir);
									mostrar(idProveedor, mostrarTipoP[0], areaSelP);
								break;
								
								case 2:
									mostrar(idProveedor, mostrarTipoP[1], areaSelP);
								break;
								
								case 3:
									system("cls");
									menuAdmin();
								break;
								
								default:
								break;
							}
						}
					}while(opcion1 < 1 || opcion1 > 3 && opcion1 != 3);
				break;
				
				case 3:
					system("cls");
					menuAdmin();
				break;
					/**/
				default:
					cout << "ERROR. HA INGRESADO UNA OPCIÓN INVÁLIDA.\n" << endl;
				break;
			}
		}while(opcionP < 1 || opcionP > 4 && opcionP != 4);
	}
	break;
	
	case 3:
	{
		char idArticulo[5] = "", areaSelA[25] = "Articulos", mostrarTipoA[2][25] = {"especifico", "todo"};
		fflush(stdin);
		Articulos articuloUsar;
		do{
			bool repetir = true, regresar = false;
			cout << "1. Registrar articulo." << endl;
			cout << "2. Ver registros de articulos." << endl;
			cout << "3. Regresar al menú." << endl;
			cout << "\nSeleccione la opción que prefiera: ";
			cin >> opcionP; cout << endl;
			fflush(stdin);
			switch (opcionP){
				case 1:
					crearArticulo();
				break;
					/**/
				case 2:
					do{
						cout << "\n¿Qué desea ver?" << endl;
						cout << "1. Registros de un artículo específico." << endl;
						cout << "2. Registros de todos los articulos." << endl;
						cout << "3. Regresar al menú anterior." << endl;
						cout << "Seleccione la opción que prefiera: ";
						cin >> opcion1; cout << endl;
						if(opcion1 >= 1 && opcion1 <= 3){
							switch (opcion1){
								case 1:
									do{
										cout << "Ingrese el Id del artículo: " << endl;
										cin >> idArticulo;
										repetir = validarId(idArticulo, areaSelA);
										if (repetir){
											cout << "ERROR. Artículo no encontrado" << endl;
											do{
												cout << "\n¿Qué desesa hacer?" << endl;
												cout << "1. Buscar con otro id." << endl;
												cout << "2. Cancelar (lo llevará al menú anterior)." << endl;
												cin >> opcion1; cout << endl;
												if (opcion1 < 1 || opcion1 > 2){
													cout << "ERROR. HA INGRESADO UNA OPCIÓN INVÁLIDA" << endl;
												}else if(opcion1 == 1){
													cout << endl;
													regresar = true;
													system("cls");
												}else{
													system("cls");
													subMenuAdmin(opcion, area);
												}
											}while(opcion1 < 1 || opcion1 > 2 || regresar == false);
										}
									}while(repetir);
									mostrar(idArticulo, mostrarTipoA[0], areaSelA);
								break;
								
								case 2:
									mostrar(idArticulo, mostrarTipoA[1], areaSelA);
								break;
								
								case 3:
									system("cls");
									menuAdmin();
								break;
								
								default:
								break;
							}
						}
					}while(opcion1 < 1 || opcion1 > 3 && opcion1 != 3);
				break;
				
				case 3:
					system("cls");
					menuAdmin();
				break;
					/**/
				default:
					cout << "ERROR. HA INGRESADO UNA OPCIÓN INVÁLIDA.\n" << endl;
				break;
			}
		}while(opcionP < 1 || opcionP > 4 && opcionP != 4);
	}
	break;

	case 4:
		welcome();
		cout << "Ingresando a " << area << "...\n";
		cout<<"Elija una opciÃ³n (Digite un numero)\n";
		cout << "1) Registro de entrada de inventarios\n";
		cout << "2) Registro de salida de inventarios\n";
		cout << "3) Regresar al menu\n";
		while (!(cin>>subMenu)) {
			cin.clear();
			cin.ignore(255, '\n');
			cout<<"No se permiten letras, presione ENTER e intentelo de nuevo\n";
			getch();
			system("clear");
			system("cls");
			
			welcome();
			cout << "Ingresando a " << area << "...\n";
			cout<<"Elija una opciÃ³n (Digite un numero)\n";
			cout << "1) Registro de entrada de inventarios\n";
			cout << "2) Registro de salida de inventarios\n";
			cout << "3) Regresar al menu\n";
		}
			validacionOpciones(subMenu, 1, 3);
			
			switch (subMenu)
			{
			case 1:
				crearMovimiento(0);
				break;

			case 2:
				crearMovimiento(1);
				
				break;

			case 3:
				menuAdmin();
				break;
			
			default:
				break;
			}
		break;

	case 5:
		welcome();
		cout << "Ingresando a " << area << "...\n";
		cout<<"Elija una opciÃ³n (Digite un numero)";
		cout << "1) Reporte de Inventarios\n";
		cout << "2) Reporte de Movimientos\n";
		cout << "3) Regresar al menu\n";
		while (!(cin>>subMenu)) {
			cin.clear();
			cin.ignore(255, '\n');
			cout<<"No se permiten letras, presione ENTER e intentelo de nuevo\n";
			getch();
			system("clear");
			system("cls");
			
			welcome();
			cout << "Ingresando a " << area << "...\n";
			cout<<"Elija una opciÃ³n (Digite un numero)";
			cout << "1) Reporte de Inventarios\n";
			cout << "2) Reporte de Movimientos\n";
			cout << "3) Regresar al menu\n";
		}
			validacionOpciones(subMenu, 1, 3);

			
		
		break;

	default:
		break;
	}
}

void menuSupervisor() {
	int opcion = 0;
	welcome();
	cout<<"Elija una opcion (Digite un numero)\n";
	cout<<"1- Reportes";
	cout<<"2- Cerrar Sesion";
	cin>>opcion;

	switch (opcion)
	{
	case 1:
		//reportes();
		break;

	case 2:
		//menu_login();
		break;

	default:
		break;
	}

}

void reportes() {

}


void validacionOpciones(int opcionElegida, int primeraOpcion, int ultimaOpcion) {
	if (!(opcionElegida) && opcionElegida != 0){
		cout << "ERROR: OPCION INVALIDA \n";
		cout << "Presione ENTER e intentelo de Nuevo...\n";
		cin.clear();
		cin.ignore();
		getch();
		system("clear");
		system("cls");
	} else if (opcionElegida < primeraOpcion || opcionElegida > ultimaOpcion) {
		cout << "ERROR: OPCION INVALIDA \n";
		cout << "Presione ENTER e intentelo de Nuevo...\n";

		cin.ignore();
		getch();
		system("cls");
		system("clear");
	}
}

void changePassword(int cargo, struct Usuario admin, struct Usuario supervisor) {
	char currentPassword[15];
	char user[15];

	int intento = 3;

	cout << "A continuacion procedera a cambiar su contrasena\n";
	do {
		intento--;
		cout << "Ingrese su usuario:\n";
		cin >> user;

		if (strcmp(user, admin.username) == 0) {
			cout << "Ingrese su contrasena actual\n";
			cin >> currentPassword;
			if (strcmp(currentPassword, admin.password) == 0) {
				cout << "Ingrese su nueva contrasena\n";
				cin >> admin.password;
				cout << "CONTRASENA VALIDA. PROCEDA A INICIAR SESION";
				almacenarUsuarios(admin, supervisor);
				menu_login(admin, supervisor);
			} else {
				cout << "Contrasena incorrecta...Le restan " << intento << " Intentos\n";
				if (intento == 0) {
					cout<<"INTENTOS MAXIMOS. REGRESANDO AL MENU PRINCIPAL";
				break;
				}
			}
		} else if (strcmp(user, supervisor.username) == 0) {
			cout << "Ingrese su contrasena actual\n";
			cin >> currentPassword;
			if (strcmp(currentPassword, admin.password) == 0) {
				cout << "Ingrese su nueva contrasena\n";
				cin >> admin.password;
				almacenarUsuarios(admin, supervisor);
				cout << "CONTRASENA VALIDA. PROCEDA A INICIAR SESION";
				login(admin, supervisor);
			} else {
				cout << "Contrasena incorrecta...Le restan " << intento << " Intentos\n";
				if (intento == 0) {
					cout<<"INTENTOS MAXIMOS. REGRESANDO AL MENU PRINCIPAL";
				break;
				}
			}
		} else{
			cout << "Usuario invalido. Le restan " << intento << " Intentos\n";
			if (intento == 0) {
				cout<<"INTENTOS MAXIMOS. REGRESANDO AL MENU PRINCIPAL";
				cin.ignore();
				getch();

				break;
			}

		}

	} while (intento >= 0);
}

void recoverPassword(int cargo,struct Usuario admin, struct Usuario supervisor) {

	char currentPassword[15];
	char user[15];

	int intento = 3;
	cout << "A continuacion procedera a recuperar su contrasena\n";
	do {
		intento--;
		cout << "Ingrese su usuario:\n";
		cin >> user;

		if (strcmp(user, admin.username) == 0) {
			cout << "Su contrasena es: "<<admin.password;
			cin.ignore();
			getch();
			menu_login(admin, supervisor);
		} else if (strcmp(user, supervisor.username) == 0) {
			cout << "Su contrasena es: "<<supervisor.password;
			cin.ignore();
			getch();
			menu_login(admin, supervisor);
		} else{
			cout << "Usuario invalido. Le restan " << intento << " Intentos\n";
			if (intento == 0) {
				cout<<"INTENTOS MAXIMOS. REGRESANDO AL MENU PRINCIPAL";
				cin.ignore();
				getch();
				break;
			}
		}
	} while (intento >= 0);

}

void almacenarUsuarios (Usuario admin, Usuario supervisor) {
	ofstream archivoUsuarios;

	archivoUsuarios.open("usuario.dat", ios::binary );

	archivoUsuarios.seekp(0, ios::beg);
	archivoUsuarios.write((char *)(&admin.username), sizeof(Usuario));
	archivoUsuarios.write((char *)(&admin.password), sizeof(Usuario));
	archivoUsuarios.write((char *)(&supervisor.username), sizeof(Usuario));
	archivoUsuarios.write((char *)(&supervisor.username), sizeof(Usuario));
	archivoUsuarios.close();
}

void cargarUsuarios (Usuario admin, Usuario supervisor) {
	ifstream archivoUsuarios("usuario.dat", ios::binary);
	int tam;	
	if (archivoUsuarios.is_open()) {
		archivoUsuarios.seekg(0, ios::end);
		tam = archivoUsuarios.tellg();
		archivoUsuarios.seekg(0, ios::beg);
		archivoUsuarios.read((char *)(&admin.username), sizeof(Usuario));
		archivoUsuarios.read((char *)(&admin.password), sizeof(Usuario));
		
		archivoUsuarios.read((char *)(&supervisor.username), sizeof(Usuario));
		archivoUsuarios.read((char *)(&supervisor.username), sizeof(Usuario));
		archivoUsuarios.close();
	}
}


void crearMovimiento (int tipo) {


	Movimiento listado_movimientos[MAX];
	cargarMovimientos(listado_movimientos);

	int origen;
    cout<<"Ingrese el Tipo de Origen (Elija un numero) \n";
    cout<<"1- Proveedor\n";
    cout<<"2- Sucursal\n";
    
	while (!(cin>>origen)) {
			cin.clear();
			cin.ignore(255, '\n');
			cout<<"No se permiten letras, presione ENTER e intentelo de nuevo\n";
			getch();
			system("clear");
			system("cls");			
}
	
	validacionOpciones(origen, 1, 2);
	if (origen == 1) strcpy(listado_movimientos[cant].tipo_origen, "Proveedor");
	else if (origen == 2) strcpy(listado_movimientos[cant].tipo_origen, "Sucursal");

	fflush(stdin);
    cout<<"Digite el ID de origen de acuerdo al tipo de origen previamente seleccionado\n";
    cin>>listado_movimientos[cant].id_origen;

	int destino;
    cout<<"Ingrese el Tipo de Destino (Elija un numero)\n";
    cout<<"1- Proveedor\n";
    cout<<"2- Sucursal\n";
    cout<<"3- Venta\n";
	while (!(cin>>destino)) {
			cin.clear();
			cin.ignore(255, '\n');
			cout<<"No se permiten letras, presione ENTER e intentelo de nuevo\n";
			getch();
			system("clear");
			system("cls");
			
			cout<<"Ingrese el Tipo de Destino (Elija un numero)\n";
    		cout<<"1- Proveedor\n";
		    cout<<"2- Sucursal\n";
    		cout<<"3- Venta\n";
		}
	validacionOpciones(destino, 1, 3);
	if (destino == 1) strcpy(listado_movimientos[cant].tipo_destino, "Proveedor");
	else if(destino == 2) strcpy(listado_movimientos[cant].tipo_destino, "Sucursal");
	else if(destino == 3) strcpy(listado_movimientos[cant].tipo_destino, "Venta"); 

    cout<<"Digite el ID de destino de acuerdo al tipo de destino previamente seleccionado\n";
    cin>>listado_movimientos[cant].id_destino;

    cout<<"Digite el ID del articulo previamente existente\n";
    
	while (!(cin>>listado_movimientos[cant].id_articulo)) {
			cin.clear();
			cin.ignore(255, '\n');
			cout<<"No se permiten letras, presione ENTER e intentelo de nuevo\n";
			getch();
			system("clear");
			system("cls");
			
			cout<<"Digite el ID del articulo previamente existente\n";
		}

    cout<<"Escriba la cantidad de articulo que movera\n";
    cin>>listado_movimientos[cant].cantidad;


	int razonMovimiento;
    cout<<"Escriba la razo del movimiento(Elija un numero\n";
    if (tipo == 0) {
        cout<<"1- Compra de Articulos\n";
        cout<<"2- Movimientos entre sucursales\n";
    } else if (tipo == 1) {
        cout<<"1- Venta de Articulos\n";
        cout<<"2- Devolucion\n";
    }
    cin>>razonMovimiento;

	if (tipo == 0 && razonMovimiento == 1) {
		strcpy(listado_movimientos[cant].motivo_movimiento, "Compra de Articulos");
	} else if (tipo == 0 && razonMovimiento == 2) {
		strcpy(listado_movimientos[cant].motivo_movimiento, "Movimientos entre sucursales");
	} else if (tipo == 1 && razonMovimiento == 1) {
		strcpy(listado_movimientos[cant].motivo_movimiento, "Venta de Articulos");
	} else if (tipo == 1 && razonMovimiento == 1) {
		strcpy(listado_movimientos[cant].motivo_movimiento, "Devolucion");
	}

    if (tipo == 0) {
		strcpy(listado_movimientos[cant].tipo_movimiento, "E");
    } else if (tipo == 1) {
        strcpy(listado_movimientos[cant].tipo_movimiento, "S");
    }

	cout<<"MOVIMIENTO REGISTRADO CORRECTAMENTE\n";
	cin.ignore();
	getch();


	cant++;
	almacenarMovimientos(listado_movimientos);
	verMovimientos(listado_movimientos);
}

void almacenarMovimientos(Movimiento listado_movimientos[]) {
	ofstream movimientos;

	movimientos.open("movimientos.dat", ios::binary | ios::app);

	movimientos.seekp(0, ios::beg);
	for(int i=0; i<cant; i++) {
		movimientos.write((char *)(&listado_movimientos[i].tipo_origen), sizeof(Movimiento));
		movimientos.write((char *)(&listado_movimientos[i].id_origen), sizeof(Movimiento));
		movimientos.write((char *)(&listado_movimientos[i].tipo_destino), sizeof(Movimiento));
		movimientos.write((char *)(&listado_movimientos[i].id_destino), sizeof(Movimiento));
		movimientos.write((char *)(&listado_movimientos[i].id_articulo), sizeof(Movimiento));
		movimientos.write((char *)(&listado_movimientos[i].cantidad), sizeof(Movimiento));
		movimientos.write((char *)(&listado_movimientos[i].motivo_movimiento), sizeof(Movimiento));
		movimientos.write((char *)(&listado_movimientos[i].tipo_destino), sizeof(Movimiento));
	}
	movimientos.close();
}

void cargarMovimientos (Movimiento listado_movimientos[]) {
	ifstream movimientos ("movimientos.dat", ios::binary);

	int tam;
	cant = 0;
	if (movimientos.is_open()) {
		movimientos.seekg(0, ios::end);
		tam = movimientos.tellg();
		cant = tam/sizeof(Movimiento);
		movimientos.seekg(0, ios::beg);

		for(int i=0;i<cant; i++) {

			movimientos.read((char *)(&listado_movimientos[i].tipo_origen), sizeof(Movimiento));
			movimientos.read((char *)(&listado_movimientos[i].id_origen), sizeof(Movimiento));
			movimientos.read((char *)(&listado_movimientos[i].tipo_destino), sizeof(Movimiento));
			movimientos.read((char *)(&listado_movimientos[i].id_destino), sizeof(Movimiento));
			movimientos.read((char *)(&listado_movimientos[i].id_articulo), sizeof(Movimiento));
			movimientos.read((char *)(&listado_movimientos[i].cantidad), sizeof(Movimiento));
			movimientos.read((char *)(&listado_movimientos[i].motivo_movimiento), sizeof(Movimiento));
			movimientos.read((char *)(&listado_movimientos[i].tipo_destino), sizeof(Movimiento));
		}
		movimientos.close();

	}

}

void verMovimientos (Movimiento movimientos[]) {
	cout.setf(ios::left);
	for(int i=0;i<cant;i++){
			cout<<"Motivo:\t\t\t"<<movimientos[i].motivo_movimiento<<endl;
			cout<<"ID Articulo:\t\t\t"<<movimientos[i].id_articulo<<endl;
			cout<<cant;
		}
	cout.unsetf(ios::left);
	}

int crearCorrelativo(char areaSel[25]){
	int correlativo;
	char areas[3][25] = {"sucursales", "proveedores", "articulos"};
	
	ifstream correlativoget;
	
	if (strcmp(areaSel, areas[0]) == 0){
		correlativoget.open("archivos/contsucursales.dat", ios::binary);
		
		if (correlativoget.fail()){
			cout << "ERROR";
		}
		
		correlativoget.seekg(0);
		correlativoget.read((char *)&correlativo, sizeof(int));
		
		correlativo += 1;
		
		correlativoget.close();
		
		ofstream correlativosave;
		
		correlativosave.open("archivos/contsucursales.dat", ios::binary);
		
		correlativosave.write((char *)&correlativo, sizeof(int));
		
		correlativosave.close();
	}else if(strcmp(areaSel, areas[1]) == 0){
		
		correlativoget.open("archivos/contproveedores.bin", ios::binary);
		
		if (correlativoget.fail()){
			cout << "ERROR";
		}
		
		correlativoget.seekg(0);
		correlativoget.read((char *)&correlativo, sizeof(int));
		
		correlativo += 1;
		
		correlativoget.close();
		
		ofstream correlativosave;
		
		correlativosave.open("archivos/contproveedores.bin", ios::binary);
		
		correlativosave.write((char *)&correlativo, sizeof(int));
		
		correlativosave.close();
	}else if(strcmp(areaSel, areas[2]) == 0){
		correlativoget.open("archivos/contarticulos.bin", ios::binary);
		
		if (correlativoget.fail()){
			cout << "ERROR";
		}
		
		correlativoget.seekg(0);
		correlativoget.read((char *)&correlativo, sizeof(int));
		
		correlativo += 1;
		
		correlativoget.close();
		
		ofstream correlativosave;
		
		correlativosave.open("archivos/contarticulos.bin", ios::binary);
		
		correlativosave.write((char *)&correlativo, sizeof(int));
		
		correlativosave.close();
	}
	
	return correlativo;
}

int correlativo(char areaSel[25]){
	int correlativo;
	char areas[3][25] = {"Sucursales", "Proveedores", "Articulos"};
	
	ifstream correlativoget;
	
	correlativoget.open("archivos/contsucursales.dat", ios::binary);
	
	if (correlativoget.fail())
		cout << "ERROR. No se pudo abrir el archivo.";

	correlativoget.read((char *)&correlativo, sizeof(int));
	
	correlativoget.close();
	
	return correlativo;
}

void crearSucursal(){
	char id[4];
	char area[] = "sucursales";
	int correlativo = crearCorrelativo(area);
	Sucursal sucursalNew;
	if (correlativo < 10){
		id[0] = 'S';
		id[1] = '0';
		id[2] = '0';
		id[3] = correlativo + 0x30;
	} else if (correlativo < 100){
		id[0] = 'S';
		id[1] = '0';
		id[2] = correlativo + 0x30;
	} else{
		id[0] = 'S';
		id[1] = correlativo + 0x30;
	}
	
	cout << "El id de la sucursal a crear es: ";
	
	for (int i = 0; i < 4; i++){
		cout << id[i];
	}
	cout << endl;
	
	strcpy(sucursalNew.id, id);
	
	char desc[100], direc[100], tel[9], encar[50], pais[15], tarea[15] = "crear", vacio[2][2] = {" ", ""};
	char datosIng[5][100];
	char datos[5][100] = {"Ingrese la descripcion:", "Ingrese la dirección:", "Ingrese el número de teléfono:",
	"Ingrese el nombre del encargado:", "Seleccione el país de la sucursal:"};
	int size[5] = {100, 100, 9, 50, 15}, opcPais, posicion = 0;
	bool repetir;
	do{
		repetir = true;
		cout << "\nIngrese la descripción: " << endl;
		cin.getline(sucursalNew.descripcion, 100, '\n');
		fflush(stdin);
		if (strcmp(sucursalNew.descripcion, vacio[0]) == 0 || strcmp(sucursalNew.descripcion, vacio[1]) == 0){
			cout<<"\nERROR: No puede dejar vacío este campo" << endl;
		}else{
			repetir = false;
		}
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nIngrese la dirección: " << endl;
		cin.getline(sucursalNew.direccion, 100, '\n');
		fflush(stdin);
		if (strcmp(sucursalNew.direccion, vacio[0]) == 0 || strcmp(sucursalNew.direccion, vacio[1]) == 0){
			cout<<"\nERROR: No puede dejar este campo vacío." << endl;
		}else{
			repetir = false;
		}
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nIngrese el número de teléfono: " << endl;
		cin.getline(sucursalNew.telefono, 10, '\n');
		fflush(stdin);
		repetir = validarTel(sucursalNew.telefono);
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nIngrese el nombre del encargado: " << endl;
		cin.getline(sucursalNew.encargado, 50, '\n');
		fflush(stdin);
		if (strcmp(sucursalNew.encargado, vacio[0]) == 0 || strcmp(sucursalNew.encargado, vacio[1]) == 0){
			cout<<"\nERROR: No puede dejar este campo vacío." << endl;
		}else{
			repetir = false;
		}
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nSeleccione el pais donde estará ubicada la sucursal: " << endl;
			cout << "1. El Salvador" << endl;
			cout << "2. México" << endl;
			cout << "3. Panamá" << endl;
			cin >> opcPais;
			switch (opcPais){
				case 1:
					strcat(sucursalNew.pais, "El Salvador");
					break;

				case 2:
					strcat(sucursalNew.pais, "México");
					break;

				case 3:
					strcat(sucursalNew.pais, "Panamá");
					break;

				default:
					cout << "ERROR. Ha seleccionado una opción inválida"<<endl;
			}
		fflush(stdin);
	}while(opcPais < 1 || opcPais > 3);
	
	guardarSucursal(sucursalNew, tarea, posicion);
}

void crearProveedor(){
	char id[4];
	char area[] = "proveedores";
	int correlativo = crearCorrelativo(area);
	Proveedores proveedorNew;
	if (correlativo < 10){
		id[0] = 'P';
		id[1] = '0';
		id[2] = '0';
		id[3] = correlativo + 0x30;
	} else if (correlativo < 100){
		id[0] = 'P';
		id[1] = '0';
		id[2] = correlativo + 0x30;
	} else{
		id[0] = 'P';
		id[1] = correlativo + 0x30;
	}
	
	cout << "El id del proveedor a crear es: ";
	
	for (int i = 0; i < 4; i++){
		cout << id[i];
	}
	cout << endl;
	
	strcpy(proveedorNew.id, id);
	
	char desc[100], direc[100], tel[9], encar[50], pais[15], tarea[15] = "crear", vacio[2][2] = {" ", ""};
	char datosIng[5][100];
	int size[5] = {100, 100, 9, 50, 15}, opcIden, posicion = 0;
	bool repetir;
	do{
		repetir = true;
		cout << "\nIngrese el nombre: " << endl;
		cin.getline(proveedorNew.nombre, 100, '\n');
		fflush(stdin);
		if (strcmp(proveedorNew.nombre, vacio[0]) == 0 || strcmp(proveedorNew.nombre, vacio[1]) == 0){
			cout<<"\nERROR: No puede dejar vacío este campo" << endl;
		}else{
			repetir = false;
		}
	}while(repetir);
	
	repetir = true;
	cout << "\nIngrese el apellido: " << endl;
	cin.getline(proveedorNew.apellido, 100, '\n');
	fflush(stdin);
	
	do{
		repetir = true;
		cout << "\nIngrese la identificiacion: " << endl;
		cin.getline(proveedorNew.identificacion, 20, '\n');
		fflush(stdin);
		if (strcmp(proveedorNew.identificacion, vacio[0]) == 0 || strcmp(proveedorNew.identificacion, vacio[1]) == 0){
			cout<<"\nERROR: No puede dejar este campo vacío." << endl;
		}else{
			repetir = false;
		}
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nSeleccione el tipo de identificación: " << endl;
			cout << "1. DUI" << endl;
			cout << "2. NIT" << endl;
			cin >> opcIden;
			switch (opcIden){
				case 1:
					strcat(proveedorNew.tipoIdentificacion, "DUI");
					break;

				case 2:
					strcat(proveedorNew.tipoIdentificacion, "NIT");
					break;

				default:
					cout << "ERROR. Ha seleccionado una opción inválida"<<endl;
			}
		fflush(stdin);
	}while(opcIden < 1 || opcIden > 2);
	
	do{
		repetir = true;
		cout << "\nIngrese el número de teléfono: " << endl;
		cin.getline(proveedorNew.telefono, 10, '\n');
		fflush(stdin);
		repetir = validarTel(proveedorNew.telefono);
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nIngrese el email: " << endl;
		cin.getline(proveedorNew.email, 100, '\n');
		fflush(stdin);
		if (strcmp(proveedorNew.email, vacio[0]) == 0 || strcmp(proveedorNew.email, vacio[1]) == 0){
			cout<<"\nERROR: No puede dejar vacío este campo" << endl;
		}else{
			repetir = false;
		}
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nIngrese la dirección: " << endl;
		cin.getline(proveedorNew.direccion, 100, '\n');
		fflush(stdin);
		if (strcmp(proveedorNew.direccion, vacio[0]) == 0 || strcmp(proveedorNew.direccion, vacio[1]) == 0){
			cout<<"\nERROR: No puede dejar este campo vacío." << endl;
		}else{
			repetir = false;
		}
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nIngrese la identificiacion: " << endl;
		cin.getline(proveedorNew.identificacion, 11, '\n');
		fflush(stdin);
		if (strcmp(proveedorNew.apellido, vacio[0]) == 0 || strcmp(proveedorNew.apellido, vacio[1]) == 0){
			cout<<"\nERROR: No puede dejar este campo vacío." << endl;
		}else{
			repetir = false;
		}
	}while(repetir);
	
	guardarProveedor(proveedorNew, tarea, posicion);
}



void crearArticulo(){
	char id[4];
	char area[] = "articulos", areaSel[25] = "Proveedores";
	int correlativo = crearCorrelativo(area);
	Articulos articuloNew;
	if (correlativo < 10){
		id[0] = 'A';
		id[1] = '0';
		id[2] = '0';
		id[3] = correlativo + 0x30;
	} else if (correlativo < 100){
		id[0] = 'A';
		id[1] = '0';
		id[2] = correlativo + 0x30;
	} else{
		id[0] = 'A';
		id[1] = correlativo + 0x30;
	}
	
	cout << "El id del articulo a crear es: ";
	
	for (int i = 0; i < 4; i++){
		cout << id[i];
	}
	cout << endl;
	
	strcpy(articuloNew.id, id);
	
	char desc[100], direc[100], tel[9], encar[50], pais[15], tarea[15] = "crear", vacio[2][2] = {" ", ""};
	char datosIng[5][100];
	int size[5] = {100, 100, 9, 50, 15}, opcArt, posicion = 0;
	bool repetir;
	do{
		repetir = true;
		cout << "\nSeleccione el tipo de articulo: " << endl;
			cout << "1. Papelería." << endl;
			cout << "2. Libros." << endl;
			cout << "3. Souvenirs." << endl;
			cout << "4. Artículos religiosos." << endl;
			cin >> opcArt;
			switch (opcArt){
				case 1:
					strcat(articuloNew.tipoArticulo, "Papeleria");
					break;

				case 2:
					strcat(articuloNew.tipoArticulo, "Libros");
					break;

				case 3:
					strcat(articuloNew.tipoArticulo, "Souvenirs");
					break;
					
				case 4:
					strcat(articuloNew.tipoArticulo, "Articulos religiosos");
					break;

				default:
					cout << "ERROR. Ha seleccionado una opción inválida"<<endl;
			}
		fflush(stdin);
	}while(opcArt < 1 || opcArt > 4);
	
	do{
		repetir = true;
		cout << "\nIngrese el nombre: " << endl;
		cin.getline(articuloNew.nombre, 100, '\n');
		fflush(stdin);
		if (strcmp(articuloNew.nombre, vacio[0]) == 0 || strcmp(articuloNew.nombre, vacio[1]) == 0){
			cout<<"\nERROR: No puede dejar este campo vacío." << endl;
		}else{
			repetir = false;
		}
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nIngrese las características: " << endl;
		cin.getline(articuloNew.caracteristicas, 100, '\n');
		fflush(stdin);
		if (strcmp(articuloNew.caracteristicas, vacio[0]) == 0 || strcmp(articuloNew.caracteristicas, vacio[1]) == 0){
			cout<<"\nERROR: No puede dejar este campo vacío." << endl;
		}else{
			repetir = false;
		}
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nIngrese el precio de venta: " << endl;
		cout << "$";
		cin >> articuloNew.precioVenta;
		fflush(stdin);
		repetir = false;
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nIngrese el costo: " << endl;
		cin >> articuloNew.costo;
		fflush(stdin);
		repetir = false;
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nIngrese el id del proveedor: " << endl;
		cin.getline(articuloNew.idProveedor, 6, '\n');
		fflush(stdin);
		repetir = validarId(articuloNew.idProveedor, areaSel);
	}while(repetir);
	
	guardarArticulo(articuloNew, tarea, posicion);
}

bool validarTel(char numTel[9]){
	//   INICIO VALIDACIÓN DE TELÉFONO   //
	char guion []= "-", num[1], auxiliar[1], auxiliar2;
	int contador = 0;
	fflush(stdin);
	
	
	for (int i = 0; i < 9; i++){
		for (int j = 0; j <= 9; j++){
			num[0] = j + 0x30;
			if (i == 4){
				if (numTel[i] == guion[0]){
					contador += 1;
					break;
				}else if(numTel[i] == num[0]){
					auxiliar[0] = numTel[i];
					//agreGuion = true;
					numTel[i] = guion[0];
					auxiliar2 = numTel[i+1];
					for (int m = 5; m < 9; m++){
						numTel[m] = auxiliar[0];
						auxiliar[0] = auxiliar2;
						auxiliar2 = numTel[m+1];
					}
					contador += 1;
					break;
				}
			}else{
				if (numTel[i] == num[0]){
					contador += 1;
					break;
				}
			}
		}
	}
	
	if (contador == 9){
		return false;
	}else{
		cout << "ERROR. Ha Ingresado un número de télefono inválido." << endl;
		return true;
	}
	
	//   FINAL VALIDACIÓN DE TELÉFONO   //
}

void guardarSucursal(Sucursal sucursalCreada, char tareaSel[15], int posicion){
	char tarea[15] = "modificar";
	ofstream sucursalSave;
	
	if (sucursalSave.fail())
		cout << "Hubo error al abrir el archivo" << endl;
		
	if (strcmp(tareaSel, tarea) == 0){
		sucursalSave.open("archivos/sucursales.dat", ios::binary);
		sucursalSave.seekp(sizeof(Sucursal)*posicion);
		cout << "NUEVOS CAMPOS" << endl;
		cout << "Descripción: " << sucursalCreada.descripcion << endl;
		cout << "Dirección: " << sucursalCreada.direccion << endl;
		cout << "Teléfono: " << sucursalCreada.telefono << endl;
		cout << "Encargado: " << sucursalCreada.encargado << endl;
		cout << "Pais: " << sucursalCreada.pais << endl;
	}else{
		sucursalSave.open("archivos/sucursales.dat", ios::binary | ios::app);
	}
	
	sucursalSave.write((char *)&sucursalCreada, sizeof(Sucursal));
	
	cout << "\nSUCURSAL GUARDADA CON ÉXITO";
	
	sucursalSave.close();
}

void guardarProveedor(Proveedores proveedorCreado, char tareaSel[15], int posicion){
	char tarea[15] = "modificar";
	ofstream proveedorSave;
	
	if (proveedorSave.fail())
		cout << "Hubo error al abrir el archivo" << endl;
		
	if (strcmp(tareaSel, tarea) == 0){
		proveedorSave.open("archivos/proveedores.dat", ios::binary);
		proveedorSave.seekp(sizeof(Proveedores)*posicion);
		/*cout << "NUEVOS CAMPOS" << endl;
		cout << "Descripción: " << proveedorSave.descripcion << endl;
		cout << "Dirección: " << sucursalCreada.direccion << endl;
		cout << "Teléfono: " << sucursalCreada.telefono << endl;
		cout << "Encargado: " << sucursalCreada.encargado << endl;
		cout << "Pais: " << sucursalCreada.pais << endl;*/
	}else{
		proveedorSave.open("archivos/proveedores.dat", ios::binary | ios::app);
	}
	
	proveedorSave.write((char *)&proveedorCreado, sizeof(Proveedores));
	
	cout << "\nPROVEEDOR GUARDADO CON ÉXITO";
	
	proveedorSave.close();
}

void guardarArticulo(Articulos articuloCreado, char tareaSel[15], int posicion){
	char tarea[15] = "modificar";
	ofstream articuloSave;
	
	if (articuloSave.fail())
		cout << "Hubo error al abrir el archivo" << endl;
		
	if (strcmp(tareaSel, tarea) == 0){
		/*sucursalSave.open("archivos/sucursales.dat", ios::binary);
		sucursalSave.seekp(sizeof(Sucursal)*posicion);
		cout << "NUEVOS CAMPOS" << endl;
		cout << "Descripción: " << sucursalCreada.descripcion << endl;
		cout << "Dirección: " << sucursalCreada.direccion << endl;
		cout << "Teléfono: " << sucursalCreada.telefono << endl;
		cout << "Encargado: " << sucursalCreada.encargado << endl;
		cout << "Pais: " << sucursalCreada.pais << endl;*/
	}else{
		articuloSave.open("archivos/articulos.dat", ios::binary | ios::app);
	}
	
	articuloSave.write((char *)&articuloCreado, sizeof(Articulos));
	
	cout << "\nARTICULO GUARDADO CON ÉXITO";
	
	articuloSave.close();
}

void mostrar(char idIng[5], char mostrarTipo[25], char areaSel[25]){
	int cantidadMax, contador;
	char areas[3][25] = {"Sucursales", "Proveedores", "Articulos"}, mostrarTipos[2][25] = {"especifico", "todo"};
	
	if (strcmp(areaSel, areas[0]) == 0){
		Sucursal sucursalMostrar;
		
		cantidadMax = correlativo(areas[0]);
		
		if(strcmp(mostrarTipo, mostrarTipos[0]) == 0){
			ifstream sucursalView;
			sucursalView.open("archivos/sucursales.dat", ios::binary);
			for (int i = 0; i < cantidadMax; i++){
				
				if (sucursalView.fail()){
					cout << "Hubo error al abrir el archivo";
				}
				
				sucursalView.seekg(sizeof(Sucursal)*i);
				sucursalView.read((char *)&sucursalMostrar, sizeof(Sucursal));
				
				if (strcmp(sucursalMostrar.id, idIng) == 0){
					sucursalView.close();
					
					cout << "\nId de la sucursal: " << sucursalMostrar.id << endl;
					cout << "Descripcion de la sucursal: " << sucursalMostrar.descripcion << endl;
					cout << "Dirección de la sucursal: " << sucursalMostrar.direccion << endl;
					cout << "Teléfono de la sucursal: " << sucursalMostrar.telefono << endl;
					cout << "Encargardo de la sucursal: " << sucursalMostrar.encargado << endl;
					cout << "País de la sucursal: " << sucursalMostrar.pais << endl;
					cout << "\n";
					break;
				}
			}
		}else if(strcmp(mostrarTipo, mostrarTipos[1]) == 0){
			for (int i = 0; i < cantidadMax; i++){
				ifstream sucursalView;
				
				sucursalView.open("archivos/sucursales.dat", ios::binary);
				
				if (sucursalView.fail()){
					cout << "Hubo error al abrir el archivo";
				}
				
				sucursalView.seekg(sizeof(Sucursal)*i);
				sucursalView.read((char *)&sucursalMostrar, sizeof(Sucursal));
				
				sucursalView.close();
				
				cout << "El id de la sucursal: " << sucursalMostrar.id << endl;
				cout << "El descripcion de la sucursal: " << sucursalMostrar.descripcion << endl;
				cout << "El dirección de la sucursal: " << sucursalMostrar.direccion << endl;
				cout << "El teléfono de la sucursal: " << sucursalMostrar.telefono << endl;
				cout << "El encargardo de la sucursal: " << sucursalMostrar.encargado << endl;
				cout << "El pais de la sucursal: " << sucursalMostrar.pais << endl;
				cout << "\n";
			}
		}
	}else if(strcmp(areaSel, areas[1]) == 0){
		Proveedores proveedorMostrar;
		
		cantidadMax = crearCorrelativo(areas[1]);
		
		if (strcmp(mostrarTipo, mostrarTipos[0]) == 0){
			ifstream proveedorView;
			proveedorView.open("archivos/proveedores.dat", ios::binary);
			for (int i = 0; i < cantidadMax; i++){
				
				if (proveedorView.fail()){
					cout << "Hubo error al abrir el archivo";
				}
				
				proveedorView.seekg(sizeof(Proveedores)*i);
				proveedorView.read((char *)&proveedorMostrar, sizeof(Proveedores));
				
				if (strcmp(proveedorMostrar.id, idIng)){
					proveedorView.close();
					
					cout << "Id del proveedor: " << proveedorMostrar.id << endl;
					cout << "Nombre del proveedor: " << proveedorMostrar.nombre << endl;
					cout << "Apellido del proveedor: " << proveedorMostrar.apellido << endl;
					cout << "Identificación del proveedor: " << proveedorMostrar.identificacion << endl;
					cout << "Tipo de identificación: " << proveedorMostrar.tipoIdentificacion << endl;
					cout << "Teléfono del proveedor: " << proveedorMostrar.telefono << endl;
					cout << "Email del proveedor: " << proveedorMostrar.email << endl;
					cout << "Direccion del proveedor: " << proveedorMostrar.direccion << endl;
					cout << "\n";
				}
			}
		}else{
			for (int i = 0; i < cantidadMax; i++){
				ifstream proveedorView;
				
				proveedorView.open("archivos/proveedores.dat", ios::binary);
				
				if (proveedorView.fail()){
					cout << "Hubo error al abrir el archivo";
				}
				
				proveedorView.seekg(sizeof(Proveedores)*i);
				//sucursalView.seekg(0);
				proveedorView.read((char *)&proveedorMostrar, sizeof(Proveedores));
				
				if (strcmp(proveedorMostrar.id, idIng) == 0){
					proveedorView.close();
					
					cout << "Id del proveedor: " << proveedorMostrar.id << endl;
					cout << "Nombre del proveedor: " << proveedorMostrar.nombre << endl;
					cout << "Apellido del proveedor: " << proveedorMostrar.apellido << endl;
					cout << "Identificación del proveedor: " << proveedorMostrar.identificacion << endl;
					cout << "Tipo de identificación: " << proveedorMostrar.tipoIdentificacion << endl;
					cout << "Teléfono del proveedor: " << proveedorMostrar.telefono << endl;
					cout << "Email del proveedor: " << proveedorMostrar.email << endl;
					cout << "Direccion del proveedor: " << proveedorMostrar.direccion << endl;
					cout << "\n";
				}
			}
		}
	}else if(strcmp(areaSel, areas[2]) == 0){
		Articulos articuloMostrar;
		
		cantidadMax = crearCorrelativo(areas[2]);
		
		if (strcmp(mostrarTipo, mostrarTipos[0]) == 0){
			ifstream articuloView;
			articuloView.open("archivos/articulos.dat", ios::binary);
			for (int i = 0; i < cantidadMax; i++){
				
				if (articuloView.fail()){
					cout << "Hubo error al abrir el archivo";
				}
				
				articuloView.seekg(sizeof(Articulos)*i);
				//sucursalView.seekg(0);
				articuloView.read((char *)&articuloMostrar, sizeof(Articulos));
				
				if (strcmp(articuloMostrar.id, idIng) == 0){
					articuloView.close();
					
					cout << "Id del articulo: " << articuloMostrar.id << endl;
					cout << "Tipo de artículo: " << articuloMostrar.tipoArticulo << endl;
					cout << "Nombre del articulo: " << articuloMostrar.nombre << endl;
					cout << "Características del articulo: " << articuloMostrar.caracteristicas << endl;
					cout << "Precio de venta del articulo: " << articuloMostrar.precioVenta << endl;
					cout << "Costo del articulo: " << articuloMostrar.costo << endl;
					cout << "Id del proveedor: " << articuloMostrar.idProveedor << endl;
					cout << "\n";
				}
			}
		}else{
			for (int i = 0; i < cantidadMax; i++){
				ifstream articuloView;
				
				articuloView.open("archivos/articulos.dat", ios::binary);
				
				if (articuloView.fail()){
					cout << "Hubo error al abrir el archivo";
				}
				
				articuloView.seekg(sizeof(Articulos)*i);
				//sucursalView.seekg(0);
				articuloView.read((char *)&articuloMostrar, sizeof(Articulos));
				
				articuloView.close();
				
				cout << "Id del articulo: " << articuloMostrar.id << endl;
				cout << "Tipo de artículo: " << articuloMostrar.tipoArticulo << endl;
				cout << "Nombre del articulo: " << articuloMostrar.nombre << endl;
				cout << "Características del articulo: " << articuloMostrar.caracteristicas << endl;
				cout << "Precio de venta del articulo: " << articuloMostrar.precioVenta << endl;
				cout << "Costo del articulo: " << articuloMostrar.costo << endl;
				cout << "Id del proveedor: " << articuloMostrar.idProveedor << endl;
				cout << "\n";
			}
		}
	}
}

int lastId(){
	int num;
	
	ifstream id;
	
	id.open("archivos/contsucursales.dat");
	id.seekg(0);
	id.read((char *)&num, sizeof(int));
	id.close();
	return num;
}

bool validarId(char id[5], char areaSel[25]){
	char areas[3][25] = {"Sucursales", "Proveedores", "Articulos"};
	int cantidad = lastId();
	
	ifstream valiId;
	
	if (strcmp(areaSel, areas[0]) == 0){
		Sucursal sucursalUsar;
		valiId.open("archivos/contsucursales.dat", ios::binary);
		valiId.read((char *)&cantidad, sizeof(int));
		valiId.close();
		for	(int i = 0; i < cantidad; i++){
			valiId.open("archivos/sucursales.dat", ios::binary);
			valiId.seekg(sizeof(Sucursal)*i);
			valiId.read((char *)&sucursalUsar, sizeof(Sucursal));
			valiId.close();
			if (strcmp(id, sucursalUsar.id) == 0){
				return false;
			}
		}
		return true;
	}else if (strcmp(areaSel, areas[1]) == 0){
		Proveedores proveedorUsar;
		valiId.open("archivos/contsucursales.dat", ios::binary);
		valiId.read((char *)&cantidad, sizeof(int));
		valiId.close();
		for	(int i = 0; i < cantidad; i++){
			valiId.open("archivos/proveedores.dat", ios::binary);
			valiId.seekg(sizeof(Proveedores)*i);
			valiId.read((char *)&proveedorUsar, sizeof(Proveedores));
			valiId.close();
			if (strcmp(id, proveedorUsar.id) == 0){
				return false;
			}
		}
		return true;
	}else if (strcmp(areaSel, areas[2]) == 0){
		Articulos articuloUsar;
		valiId.open("archivos/contarticulos.dat", ios::binary);
		valiId.read((char *)&cantidad, sizeof(int));
		valiId.close();
		for	(int i = 0; i < cantidad; i++){
			valiId.open("archivos/sucursales.dat", ios::binary);
			valiId.seekg(sizeof(Articulos)*i);
			valiId.read((char *)&articuloUsar, sizeof(Articulos));
			valiId.close();
			if (strcmp(id, articuloUsar.id) == 0){
				return false;
			}
		}
		return true;
	}
}

void modificar(char idIng[5], char areaSel[25], int opcionSel){
	int cantidad = lastId(), opcion, posicion;
	char areas[3][25] = {"Sucursales", "Proveedores", "Articulos"}, paises[3][15] = {"El Salvador", "México", "Panamá"};
	char tarea[15] = "modificar";
	Sucursal sucursalModificar;
	cin.ignore();
	fstream modificar;
	fflush(stdin);
	
	cout << "Ha ingresado a modificar" << endl;
	
	if (strcmp(areaSel, areas[0]) == 0){
		modificar.open("archivos/sucursales.dat", ios::out | ios::in | ios::binary);
		for (int i = 0; i < cantidad; i++){
			modificar.seekg(sizeof(Sucursal)*i);
			modificar.read((char *)&sucursalModificar, sizeof(Sucursal));
			if (strcmp(idIng,sucursalModificar.id) == 0){
				posicion = i;
				break;
			}
		}
		
		switch (opcionSel){
			case 1:
				cout << "\nIngrese la nueva descripción: " << endl;
				cin.getline(sucursalModificar.descripcion, 100, '\n');
				cout << endl;
			break;
			
			case 2:
				cout << "\nIngrese la nueva dirección: " << endl;
				cin.getline(sucursalModificar.direccion, 100, '\n');
				cout << endl;
			break;
			
			case 3:
				cout << "\nIngrese el nuevo número de teléfono: " << endl;
				cin.getline(sucursalModificar.telefono, 100, '\n');
				cout << endl;
			break;
			
			case 4:
				cout << "\nIngrese el nombre del nuevo encargado: " << endl;
				cin.getline(sucursalModificar.encargado, 100, '\n');
				cout << endl;
			break;
			
			case 5:
				do{
					cout << "\nSeleccione el nuevo país: " << endl;
					cout << "1. El Salvador" << endl;
					cout << "2. México" << endl;
					cout << "3. Panamá" << endl;
					cin >> opcion;
					switch(opcion){
						case 1:
							strcpy(sucursalModificar.pais, paises[0]);
						break;
						
						case 2:
							strcpy(sucursalModificar.pais, paises[1]);
						break;
						
						case 3:
							strcpy(sucursalModificar.pais, paises[2]);
						break;
						
						default:
							cout << "ERROR. HA INGRESADO UNA OPCIÓN INVÁLIDA." << endl;
						break;
					}
				}while(opcion < 1 || opcion > 3);
			break;
		}
		fflush(stdin);
		if(modificar.is_open()){
			modificar.seekp(cantidad*sizeof(Sucursal));
			modificar.write((char*)&sucursalModificar, sizeof(Sucursal));
			modificar.close();
		}
	} else if(strcmp(areaSel, areas[1]) == 0){
		switch (opcionSel){
			case 1:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 2:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 3:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 4:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 5:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 6:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 7:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 8:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
		}
	} else if(strcmp(areaSel, areas[2]) == 0){
		switch (opcionSel){
			case 1:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 2:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 3:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 4:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 5:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 6:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 7:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
		}
	}
}
