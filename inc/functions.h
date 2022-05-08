#include <iostream>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#define MAX 50
using namespace std;
//0303 = ñ
//0301 = á

int cant = 0;

struct Usuario{
	char username[15];
	char password[15];
};

struct Movimiento {
    int id = 0; //numero incrementable de 1 en uno
    int tipo_origen; // 1- proveedor ; 2-sucursal
    char id_origen[10]; // id del proveedor/sucursal de origen
    int tipo_destino; // 1-venta ; 2-sucursal ; 3-venta
    char id_destino[10]; // id del proveedor/sucursal de destino 
    char id_articulo[10]; //id articulo existente
    int cantidad; //cantidad de articulos
    char motivo_movimiento[30]; //Entradas: "Compra de articulos", "Movimientos entre sucursales", ; Salidas: "", "Venta de articulos", "Devolucion";
    char tipo_movimiento[2]; //E = Entrada, S = Salida
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

void welcome()
{
	cout<<"\t\t Sistema de Control de Inventarios\n";
    cout<<"\t\tEmpresa Salesiana Mar�a Auxiliadora\n";
    cout<<"\t\t      Versi�n del Sistema 1.0\n";
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
		welcome();
		cout<<"Elija una opcion (Digite un numero)\n";
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
			cout<<"Elija una opcin (Digite un numero)\n";
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

void subMenuAdmin(int opcion, char area[25]) {
	int subMenu = 0;
	switch (opcion) {
	case 1: case 2: case 3:
		cout << "Ingresado a " << area << endl;
		cout<<"Elija una opción (Digite un numero)\n";
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
			cout<<"Elija una opción (Digite un numero)\n";
			cout << "1) Registrar " << area << endl;
			cout << "2) Modificar " << area << endl;

			if (opcion == 3) cout << "3) Ver registro de " << area << "s\n";	
			else cout << "3) Ver registro de " << area << "es\n";

			cout << "4) Regresar al menu\n";
			}
				validacionOpciones(subMenu, 1, 6);
			// if(opcion == 1) sucursales(subMenu);
			// else if (opcion == 2) proveedores (subMenu);
			break;

	case 4:
		welcome();
		cout << "Ingresando a " << area << "...\n";
		cout<<"Elija una opción (Digite un numero)\n";
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
			cout<<"Elija una opción (Digite un numero)\n";
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
		cout<<"Elija una opción (Digite un numero)";
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
			cout<<"Elija una opción (Digite un numero)";
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


    cout<<"Ingrese el Tipo de Origen (Elija un numero) \n";
    cout<<"1- Proveedor\n";
    cout<<"2- Sucursal\n";
    cin>>listado_movimientos[cant].tipo_origen;

	fflush(stdin);
    cout<<"Digite el ID de origen de acuerdo al tipo de origen previamente seleccionado\n";
    cin>>listado_movimientos[cant].id_origen;

    cout<<"Ingrese el Tipo de Destino (Elija un numero)\n";
    cout<<"1- Proveedor\n";
    cout<<"2- Sucursal\n";
    cout<<"3- Venta\n";
    cin>>listado_movimientos[cant].tipo_destino;

    cout<<"Digite el ID de destino de acuerdo al tipo de destino previamente seleccionado\n";
    cin>>listado_movimientos[cant].id_destino;

    cout<<"Digite el ID del articulo previamente existente\n";
    cin>>listado_movimientos[cant].id_articulo;

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
		stpcpy(listado_movimientos[cant].tipo_movimiento, "E");
    } else if (tipo == 1) {
        stpcpy(listado_movimientos[cant].tipo_movimiento, "S");
    }

	cout<<"MOVIMIENTO REGISTRADO CORRECTAMENTE\n";
	cin.ignore();
	getch();


	cant++;
	almacenarMovimientos(listado_movimientos);
	verMovimientos(listado_movimientos);

}

void almacenarMovimientos (Movimiento listado_movimientos[]) {
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


