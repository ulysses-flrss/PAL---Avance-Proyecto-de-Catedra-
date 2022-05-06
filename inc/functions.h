#include <iostream>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include "movimiento_articulos.h"
using namespace std;
//0303 = ñ
//0301 = á

struct Usuario
{
	char username[15];
	char password[15];

	
};

// DECLARACION DE FUNCIONES
void almacenarUsuarios (Usuario admin, Usuario supervisor);

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

void welcome()
{
	cout << "MENSAJE DE EJEMPLO\n";
}

void menu_login(struct Usuario admin, struct Usuario supervisor)
{
	int opc = 0;

	do
	{
		welcome();
		cout << "\nQue\u0301 desea hacer? (Di\u0301gite un nu\u0301mero)\n";
		cout << "1- Iniciar sesio\u0301n\n";
		cout << "2- Cambiar Contrasen\u0303a\n";
		cout << "3- Recuperar Contrasen\u0303a\n";
		cout << "4- Salir\n";

		while (!(cin>>opc)) {
			cin.clear();
			cin.ignore(255, '\n');
			cout<<"No se permiten letras, presione ENTER e intentelo de nuevo\n";
			getch();
			system("clear");
			system("cls");
			
			welcome();
			cout << "\nQue\u0301 desea hacer? (Di\u0301gite un nu\u0301mero)\n";
			cout << "1- Iniciar sesio\u0301n\n";
			cout << "2- Cambiar Contrasen\u0303a\n";
			cout << "3- Recuperar Contrasen\u0303a\n";
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

	cout << "Ingrese su contrasen\u0303a: \n";
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
		cout << "ERROR: Nombre o Usuario Incorrectos. Presione ENTER e Inte\u0301ntelo de Nuevo \n";
		cin.ignore();
		getch();
		login(admin, supervisor);
	};
}

// MENU ADMINISTRADOR
void menuAdmin() {
	int menuOpc = 0;

	do{
		welcome();
		cout<<"Elija una opcio\u0301n (Di\u0301gite un nu\u0301mero)\n";
		cout << "1)   Sucursales \n";
		cout << "2)   Proveedores \n";
		cout << "3)   Arti\u0301culos \n";
		cout << "4)   Movimientos arti\u0301culos \n";
		cout << "5)   Reportes \n";
		cout << "6)   Salir\n";
		cout << "Seleccione la opcio\u0301n requerida: \n";

		while (!(cin>>menuOpc)) {
			cin.clear();
			cin.ignore(255, '\n');
			cout<<"No se permiten letras, presione ENTER e intentelo de nuevo\n";
			getch();
			system("clear");
			system("cls");
			
			welcome();
			cout<<"Elija una opci\u0301n (Di\u0301gite un nu\u0301mero)\n";
			cout << "1)   Sucursales \n";
			cout << "2)   Proveedores \n";
			cout << "3)   Arti\u0301culos \n";
			cout << "4)   Movimientos arti\u0301culos \n";
			cout << "5)   Reportes \n";
			cout << "6)   Salir\n";
			cout << "Seleccione la opcio\u0301n requerida: \n";
		}
			validacionOpciones(menuOpc, 1, 6);
			menuAdmin2(menuOpc);

	} while (menuOpc < 1 || menuOpc > 6 || menuOpc != 6);
}

void menuAdmin2(int opcion) {
	char titulo[5][25] = {"Sucursal", "Proveedor", "Arti\u0301culo", "Movimientos Arti\u0301culos", "Reportes"};

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

void subMenuAdmin(int opcion, char area[25]) {
	int subMenu = 0;
	switch (opcion) {
	case 1: case 2: case 3:
		cout << "Ingresado a " << area << endl;
		cout<<"Elija una opción (Di\u0301gite un nu\u0301mero)\n";
		cout << "1) Registrar " << area << endl;
		cout << "2) Modificar " << area << endl;

		if (opcion == 3) cout << "3) Ver registro de " << area << "s\n";	
		else cout << "3) Ver registro de " << area << "es\n";

		cout << "4) Regresar al menu\u0301\n";
		while (!(cin>>subMenu)) {
			cin.clear();
			cin.ignore(255, '\n');
			cout<<"No se permiten letras, presione ENTER e intentelo de nuevo\n";
			getch();
			system("clear");
			system("cls");
			
			welcome();
			cout << "Ingresado a " << area << endl;
			cout<<"Elija una opción (Di\u0301gite un nu\u0301mero)\n";
			cout << "1) Registrar " << area << endl;
			cout << "2) Modificar " << area << endl;

			if (opcion == 3) cout << "3) Ver registro de " << area << "s\n";	
			else cout << "3) Ver registro de " << area << "es\n";

			cout << "4) Regresar al menu\u0301\n";
			}
				validacionOpciones(subMenu, 1, 6);
			// if(opcion == 1) sucursales(subMenu);
			// else if (opcion == 2) proveedores (subMenu);
			break;

	case 4:
		welcome();
		cout << "Ingresando a " << area << "...\n";
		cout<<"Elija una opción (Di\u0301gite un nu\u0301mero)";
		cout << "1) Registro de entrada de inventarios\n";
		cout << "2) Registro de salida de inventarios\n";
		cout << "3) Regresar al menu\u0301\n";
		while (!(cin>>subMenu)) {
			cin.clear();
			cin.ignore(255, '\n');
			cout<<"No se permiten letras, presione ENTER e intentelo de nuevo\n";
			getch();
			system("clear");
			system("cls");
			
			welcome();
			cout << "Ingresando a " << area << "...\n";
			cout<<"Elija una opción (Di\u0301gite un nu\u0301mero)";
			cout << "1) Registro de entrada de inventarios\n";
			cout << "2) Registro de salida de inventarios\n";
			cout << "3) Regresar al menu\u0301\n";
		}
			validacionOpciones(subMenu, 1, 3);
		break;

	case 5:
		welcome();
		cout << "Ingresando a " << area << "...\n";
		cout<<"Elija una opción (Di\u0301gite un nu\u0301mero)";
		cout << "1) Reporte de Inventarios\n";
		cout << "2) Reporte de Movimientos\n";
		cout << "3) Regresar al menu\u0301\n";
		while (!(cin>>subMenu)) {
			cin.clear();
			cin.ignore(255, '\n');
			cout<<"No se permiten letras, presione ENTER e intentelo de nuevo\n";
			getch();
			system("clear");
			system("cls");
			
			welcome();
			cout << "Ingresando a " << area << "...\n";
			cout<<"Elija una opción (Di\u0301gite un nu\u0301mero)";
			cout << "1) Reporte de Inventarios\n";
			cout << "2) Reporte de Movimientos\n";
			cout << "3) Regresar al menu\u0301\n";
		}
			validacionOpciones(subMenu, 1, 3);
		
		break;

	default:
		break;
	}
}

void menuSupervisor() {
}


void validacionOpciones(int opcionElegida, int primeraOpcion, int ultimaOpcion) {
	if (!(opcionElegida) && opcionElegida != 0){
		cout << "ERROR: OPCIO\u0301N INVA\u0301LIDA \n";
		cout << "Presione ENTER e inte\u0301ntelo de Nuevo...\n";
		cin.clear();
		cin.ignore();
		getch();
		system("clear");
		system("cls");
	} else if (opcionElegida < primeraOpcion || opcionElegida > ultimaOpcion) {
		cout << "ERROR: OPCIO\u0301N INVA\u0301LIDA \n";
		cout << "Presione ENTER e inte\u0301ntelo de Nuevo...\n";

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

	cout << "A continuacio\u0301n procedera\u0301 a cambiar su contrasen\u0303a\n";
	do {
		intento--;
		cout << "Ingrese su usuario:\n";
		cin >> user;

		if (strcmp(user, admin.username) == 0) {
			cout << "Ingrese su contrasen\u0303a actual\n";
			cin >> currentPassword;
			if (strcmp(currentPassword, admin.password) == 0) {
				cout << "Ingrese su nueva contrasen\u0303a\n";
				cin >> admin.password;
				cout << "CONTRASEN\u0303A VALIDA. PROCEDA A INICIAR SESIO\u0301N";
				almacenarUsuarios(admin, supervisor);
				menu_login(admin, supervisor);
			} else {
				cout << "Contrasen\u0303a incorrecta...Le restan " << intento << " Intentos\n";
				if (intento == 0) {
					cout<<"INTENTOS MA\u0303XIMOS. REGRESANDO AL MENU PRINCIPAL";
				break;
				}
			}
		} else if (strcmp(user, supervisor.username) == 0) {
			cout << "Ingrese su contrasen\u0303a actual\n";
			cin >> currentPassword;
			if (strcmp(currentPassword, admin.password) == 0) {
				cout << "Ingrese su nueva contrasen\u0303a\n";
				cin >> admin.password;
				almacenarUsuarios(admin, supervisor);
				cout << "CONTRASEN\u0303A VALIDA. PROCEDA A INICIAR SESIO\u0301N";
				login(admin, supervisor);
			} else {
				cout << "Contrasen\u0303a incorrecta...Le restan " << intento << " Intentos\n";
				if (intento == 0) {
					cout<<"INTENTOS MA\u0303XIMOS. REGRESANDO AL MENU PRINCIPAL";
				break;
				}
			}
		} else{
			cout << "Usuario invalido. Le restan " << intento << " Intentos\n";
			if (intento == 0) {
				cout<<"INTENTOS MA\u0303XIMOS. REGRESANDO AL MENU PRINCIPAL";
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
	cout << "A continuacio\u0301n procedera\u0301 a cambiar su contrasen\u0303a\n";
	do {
		intento--;
		cout << "Ingrese su usuario:\n";
		cin >> user;

		if (strcmp(user, admin.username) == 0) {
			cout << "Ingrese su contrasen\u0303a actual\n";
			cin >> currentPassword;
			if (strcmp(currentPassword, admin.password) == 0) {
				cout << "Ingrese su nueva contrasen\u0303a\n";
				cin >> admin.password;
				cout << "CONTRASEN\u0303A VALIDA\n";
				cin.ignore();
				getch();
				
				menu_login(admin, supervisor);
			} else {
				cout << "Contrasen\u0303a incorrecta...Le restan " << intento << " Intentos\n";
				if (intento == 0) {
				cout<<"INTENTOS MA\u0303XIMOS. REGRESANDO AL MENU PRINCIPAL";
				break;
			}
			}
		} else if (strcmp(user, supervisor.username) == 0) {
			cout << "Ingrese su contrasen\u0303a actual\n";
			cin >> currentPassword;
			if (strcmp(currentPassword, admin.password) == 0) {
				cout << "Ingrese su nueva contrasen\u0303a\n";
				cin >> admin.password;
				cout << "CONTRASEN\u0303A VALIDA";
				almacenarUsuarios(admin, supervisor);
				login(admin, supervisor);
			} else {
				cout << "Contrasen\u0303a incorrecta...Le restan " << intento << " Intentos\n";
				if (intento == 0) {
					cout<<"INTENTOS MA\u0303XIMOS. REGRESANDO AL MENU PRINCIPAL";
				break;
				}
			}
		} else{
			cout << "Usuario invalido. Le restan " << intento << " Intentos\n";
			if (intento == 0) {
				cout<<"INTENTOS MA\u0303XIMOS. REGRESANDO AL MENU PRINCIPAL";
				cin.ignore();
				getch();
				break;
			}

		}

	} while (intento >= 0);

}

void almacenarUsuarios (Usuario admin, Usuario supervisor) {
	ofstream archivoUsuarios;

	archivoUsuarios.open("usuario.dat", ios::binary);

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