#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

struct Usuario {
	char username[15];
	char password[15];
};

// DECLARACION DE FUNCIONES
void welcome();
void menu_login(struct Usuario &admin, struct Usuario &supervisor);
void login(struct Usuario &admin, struct Usuario &supervisor);
void validarUsuario(char userBuff[15], char passBuff[15]);
void menuAdmin();
void menuSupervisor();
void validacionOpciones(int opcionElegida, int primeraOpcion, int ultimaOpcion);
void menuAdmin2(int opcion);
void subMenuAdmin(int opcion, char area[25]);
void changePassword (int cargo, struct Usuario &admin, struct Usuario &supervisor);
void recoverPassword (int cargo, 0, );

void welcome() {
	cout << "MENSAJE DE EJEMPLO\n";
}

void menu_login(struct Usuario &admin, struct Usuario &supervisor) {
	int opc = 0;

	do {
	cout<<"\nQué desea hacer?\n";
	cout<<"1- Iniciar sesión\n";
	cout<<"2- Cambiar Contraseña\n";
	cout<<"3- Recuperar Contraseña\n";
	cout<<"4- Salir\n";
	cin>>opc;

	if (!(opc)) {
		validacionOpciones(opc, 1, 6);
	} else {
		validacionOpciones(opc, 1, 6);
	}

	switch (opc)
	{
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
		break;
	
	default:

		break;
	}
	} while (opc < 1 || opc > 6 || opc != 6);


	} 

void login(struct Usuario &admin, struct Usuario &supervisor) {
	char userBuff[15];

	char passBuff[15];
	int intentos = 0;
	cout << "Ingrese su nombre de usuario: \n";
	cin >> userBuff;

	cout << "Ingrese su contrase\06a: \n";
	cin >> passBuff;

	validarUsuario(userBuff, passBuff);
}


void validarUsuario(char userBuff[15], char passBuff[15]) {

		Usuario admin;
		strcpy(admin.username, "admin");
		strcpy(admin.password, "1234");

		Usuario supervisor;
		strcpy(supervisor.username, "super");
		strcpy(supervisor.password, "4321");
	

	if (strcmp(admin.username, userBuff) == 0 &&
		strcmp(admin.password, passBuff) == 0) {
		menuAdmin();

	} else if (
		strcmp(supervisor.username, userBuff) == 0 &&
		strcmp(supervisor.password, passBuff) == 0) {
		menuSupervisor();
	} else {
		cout << "ERROR: Nombre o Usuario Incorrectos. Presione ENTER e "
				"Intentelo de Nuevo \n";
		cin.ignore();
		getch();
		login();
	};
}

// MENU ADMINISTRADOR
void menuAdmin() {
	int menuOpc = 0;

	do {
		welcome();
		cout << "1)   Sucursal \n";
		cout << "2)   Proveedores \n";
		cout << "3)   Art\241culos \n";
		cout << "4)   Movimientos art�culos \n";
		cout << "5)   Reportes \n";
		cout << "6)   Salir\n";
		cout << "Seleccione la opci�n requerida: \n";
		cin >> menuOpc;

		if (!(menuOpc)) {
			validacionOpciones(menuOpc, 1, 6);
		} else {
			validacionOpciones(menuOpc, 1, 6);
			menuAdmin2(menuOpc);
		}

	} while (menuOpc < 1 || menuOpc > 6 || menuOpc != 6);
}

void menuAdmin2(int opcion) {
	char titulo[5][25] = {"Sucursal",
						  "Proveedor",
						  "Articulo",
						  "Movimientos Art�culos",
						  "Reporte"};

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
		cout << "Saliendo del programa...\n";
		break;

	default:
		break;
	}
}

void subMenuAdmin(int opcion, char area[25]) {
	int subMenu = 0;
	switch (opcion) {
	case 1:
	case 2:
	case 3:
		cout << "Ingresado a " << area << endl;
		cout << "1) Registrar " << area << endl;
		cout << "2) Modificar " << area << endl;
		cout << "3) Ver registro de " << area << "s\n";
		cout << "4) Regresar al men�\n";
		cin >> subMenu;

		if (!(subMenu)) {
			validacionOpciones(subMenu, 1, 4);
		} else {
			validacionOpciones(subMenu, 1, 4);
			// if(opcion == 1) sucursales(subMenu);
			// else if (opcion == 2) proveedores (subMenu);
		}
		break;

	case 4:
		welcome();
		cout << "Ingresando a " << area << "...\n";
		cout << "1) Registro de entrada de inventarios\n";
		cout << "2) Registro de salida de inventarios\n";
		cin >> subMenu;
		validacionOpciones(subMenu, 1, 2);
		if (!(subMenu)) {
			validacionOpciones(subMenu, 1, 4);
		} else {
			// subMenu2(subMenu);
		}
		break;

	case 5:
		welcome();
		cout << "Ingresando a " << area << "...\n";
		cout << "1) Reporte de Inventarios\n";
		cout << "2) Reporte de Movimientos\n";
		cin >> subMenu;
		validacionOpciones(subMenu, 1, 2);
		if (!(subMenu)) {
			validacionOpciones(subMenu, 1, 4);
		} else {
			// subMenu2(subMenu);
		}
		break;

	default:
		break;
	}
}

void menuSupervisor() {
}

void validacionOpciones(
	int opcionElegida,
	int primeraOpcion,
	int ultimaOpcion) {
	if (!(opcionElegida)) {
		cin.clear();
		cin.ignore();
		cout << "ERROR: OPCI�N INV�LIDA \n";
		cout << "Presione ENTER e int�ntelo de Nuevo...\n";
		cin.ignore();
		getch();
		system("clear");
		system("cls");
	} else if (opcionElegida < primeraOpcion || opcionElegida > ultimaOpcion) {
		cin.clear();
		cin.ignore();
		cout << "ERROR: OPCI�N INV�LIDA \n";
		cout << "Presione ENTER e int�ntelo de Nuevo...\n";

		cin.ignore();
		getch();
		system("cls");
		system("clear");
	}
	// HASTA AQUI-----
}

void changePassword(int cargo, struct Usuario &admin, struct Usuario &supervisor){
	char password[15];

	if (cargo == 0) {
		strcpy(password, admin.password);
	} else if (cargo == 1) {
		strcpy(password, supervisor.password);
	}


	char currentPassword[15];
	char user[15];

	int intento = 2;
	do {


		cout<<"A continuación procederá a cambiar su contraseña\n";
		cout<<"Ingrese su usuario\n";
		cin>>user;

		if (strcmp(user, admin.username) == 0) {
			cout<<"Ingrese su contraseña actual\n";
			cin>>currentPassword;
			if (strcmp(currentPassword, admin.password) == 0){
				cout<<"Ingrese su nueva contraseña\n";
				cin>>admin.password;
				cout<<"CONTRASEÑA VALIDA";
				login();
			} else {
				cout<<"Contraseña incorrecta...Le restan "<<intento<<" Intentos\n";
			}
		} else if (strcmp(user, supervisor.username) == 0) {
			cout<<"Ingrese su contraseña actual\n";
			cin>>currentPassword;
			if (strcmp(currentPassword, admin.password) == 0){
				cout<<"Ingrese su nueva contraseña\n";
				cin>>admin.password;
				cout<<"CONTRASEÑA VALIDA";
				login();
			} else {
				cout<<"Contraseña incorrecta...Le restan "<<intento<<" Intentos\n";
			}
		} else {
			cout<<"Usuario invalido. Le restan "<<intento<<" Intentos";

		}

		intento--;
	} while (intento >= 0);
}


void recoverPassword(int cargo){

	Usuario admin;
	strcpy(admin.username, "admin");
	strcpy(admin.password, "1234");

	Usuario supervisor;
	strcpy(supervisor.username, "super");
	strcpy(supervisor.password, "4321");
	

char password[15];

	if (cargo == 0) {
		strcpy(password, admin.password);
	} else if (cargo == 1) {
		strcpy(password, supervisor.password);
	}


	char currentPassword[15];

	cout<<"A continuación procederá a cambiar su contraseña";
	cout<<"Ingrese su contraseña actual";
	cin>>currentPassword;

	if (strcmp(password, currentPassword) == 0) {
		char new_password[15];
		cout<<"Escriba su nueva contraseña";
		cin>>new_password;
	}
}
