

void smsBienvenida();
int menuP();
void menu (int opcion);
bool isWindows();
void subMenu(int opcion, char area [25]);
int subMenuOpcs (int opcion, char area[25]);
void validacionOpciones (int opcionElegida, int primeraOpcion, int ultimaOpcion);
void enConstruccion();
void subMenu2 (int opcion);
void sucursales (int accion);
void proveedores (int accion);

struct Sucursal {
	char id[5];
	char descripcion[90];
	char direccion[75];
	char telefono[9];
	char encargado[35];
	
	
	void rellenarSucursales () {
	}
};


struct Proveedor {
	char id[5];
	char nombres[90];
	char apellidos[75];
	char identificacion[15];
	char tipo_identificacion[25] ;
	char telefono[9];
};

void prueba () {

    int menuOpc = 0;
    
    
    do {
        smsBienvenida();
        cout << "1)   Sucursal \n";
	    cout << "2)   Proveedores \n";
	    cout << "3)   Art�culos \n";
	    cout << "4)   Movimientos art�culos \n";
	    cout << "5)   Reportes \n";
	    cout << "6)   Salir\n";
	    cout<<"Seleccione la opci�n requerida: \n";
	    cin>>menuOpc;
		
        if(!(menuOpc)){
        	validacionOpciones(menuOpc, 1, 6);
        } else {
            validacionOpciones(menuOpc, 1, 6);
			menu(menuOpc);
        }

        
    } while (menuOpc < 1 || menuOpc > 6 || menuOpc != 6);
}

void smsBienvenida () {
    cout<<"\t\t Sistema de Control de Inventarios\n";
    cout<<"\t\tEmpresa Salesiana Mar�a Auxiliadora\n";
    cout<<"\t\t      Versi�n del Sistema 1.0\n";
    cout<<"\t\t        Techno Developers\n\n";
}

void menu(int opcion) {

    char titulo [5][25] = {"Sucursal", "Proveedor", "Articulo","Movimientos Art�culos", "Reporte"};

    switch (opcion) {
        case 1: 
            subMenu(1, titulo[0]);
            break;

        case 2:
            subMenu(2, titulo[1]);
            break;

        case 3:
            subMenu(3, titulo[2]);
            break;

        case 4:
            subMenu(4, titulo[3]);
            break;

        case 5:
            subMenu(5, titulo[4]);
            break;

        case 6:
            system("clear");
            system("cls");
            cout<<"Saliendo del programa...\n";
            break;

        default:
            break;
    }
}


void subMenu (int opcion, char area[25]) {
    int subMenu = 0;
    switch (opcion) {
        case 1: case 2: case 3:
            cout<<"Ingresado a "<<area<<endl;
            cout<<"1) Registrar "<<area<<endl;
            cout<<"2) Modificar "<<area<<endl;
            cout<<"3) Ver registro de "<<area<<"s\n";
            cout<<"4) Regresar al men�\n";
            cin>>subMenu;

            if(!(subMenu)){
        	    validacionOpciones(subMenu, 1, 4);
            } else {
                validacionOpciones(subMenu, 1, 4);
                if(opcion == 1) sucursales(subMenu);
                else if (opcion == 2) proveedores (subMenu);
            }
            break;

        case 4:
            smsBienvenida();
            cout<<"Ingresando a "<<area<<"...\n";
            cout<<"1) Registro de entrada de inventarios\n";
            cout<<"2) Registro de salida de inventarios\n";
            cin>>subMenu;
            validacionOpciones (subMenu, 1, 2);
            if(!(subMenu)) {
                validacionOpciones (subMenu, 1, 4);
            } else {
                subMenu2(subMenu);
            }
            break;

        case 5:
            smsBienvenida();
            cout<<"Ingresando a "<<area<<"...\n";
            cout<<"1) Reporte de Inventarios\n";
            cout<<"2) Reporte de Movimientos\n";
            cin>>subMenu;
            validacionOpciones (subMenu, 1, 2);
            if(!(subMenu)) {
                validacionOpciones (subMenu, 1, 4);
            } else {
                subMenu2(subMenu);
            }
            break;

        default:
            break;
    }
}



void sucursales (int accion) {
	char titulo [5][25] = {"Sucursal", "Proveedor", "Articulo","Movimientos Art�culos", "Reporte"};
	int numSucursal = 1;
	Sucursal S00[numSucursal];

    switch (accion) {
        case 1:
            cout<<"Ingrese el ID (esto es temporal): \n";
            cin.ignore();
            cin.getline(S00[numSucursal].id , 5, '\n');
            fflush(stdin);  

            cout<<"Ingrese la descripción de la sucursal: \n";
            cin.getline(S00[numSucursal].descripcion , 90, '\n');
            fflush(stdin);  

            cout<<"Ingrese la direccion de la sucursal: \n";
            cin.getline(S00[numSucursal].direccion , 75, '\n');
            fflush(stdin);

            cout<<"Ingrese el telefono de la sucursal: \n";
            cin.getline(S00[numSucursal].telefono , 9, '\n');
            fflush(stdin);

            cout<<"Ingrese el nombre del encargado de la sucursal: \n";
            cin.getline(S00[numSucursal].encargado , 35, '\n');
            fflush(stdin);

            numSucursal++;
            fflush(stdin);
            cout<<"SUCURSAL REGISTRADA CORRECTAMENTE...\n";
            cout<<"Presione ENTER para volver al menú";

                cin.ignore();
                getch();
                
            
            numSucursal++;
            break;

        case 2:
            enConstruccion();
            break;

        case 3:
        	
            cout<<"Sucursales Ingresadas: \n";
            for (int i = 0; i<numSucursal; i++) {
                cout<<"ID: "<<S00[i+1].id<<endl;
                cout<<"Descripcion: "<<S00[i+1].descripcion<<endl;
                cout<<"Direcci�n: "<<S00[i+1].direccion<<endl;
                cout<<"T�lefono: "<<S00[i+1].telefono<<endl;
                cout<<"Encargado: "<<S00[i+1].encargado<<endl;
                
            }

                cin.ignore();
                getch();
                subMenu(1, titulo[0]);
            }
            break;
            
        case 4:
            break;
    }
}

void proveedores (int accion) {

char titulo [5][25] = {"Sucursal", "Proveedor", "Articulo","Movimientos Art�culos", "Reporte"};

int numProveedor = 1;
Proveedor P00[numProveedor];

    switch (accion) {
        case 1:
            cout<<"Ingrese el ID (esto es temporal): \n";
            cin.ignore();
            cin.getline(P00[numProveedor].id , 5, '\n');
            fflush(stdin);  

            cout<<"Ingrese un nombre del proveedor: \n";
            cin.getline(P00[numProveedor].nombres , 90, '\n');
            fflush(stdin);  

            cout<<"Ingrese un apellido del proveedor: \n";
            cin.getline(P00[numProveedor].apellidos , 75, '\n');
            fflush(stdin);

            cout<<"Ingrese el número de identificación del proveedor: \n";
            cin.getline(P00[numProveedor].tipo_identificacion , 15, '\n');
            fflush(stdin);

            cout<<"Ingrese el tipo de identificación del proveedor: \n";
            cin.getline(P00[numProveedor].identificacion , 25, '\n');
            fflush(stdin);

             cout<<"Ingrese el telefono del proveedor: \n";
            cin.getline(P00[numProveedor].telefono , 9, '\n');
            fflush(stdin);

            numProveedor++;
            fflush(stdin);
            cout<<"PROVEEDOR REGISTRADO CORRECTAMENTE...\n";
            cout<<"Presione ENTER para volver al menú";

            if (isWindows()) {
                system("pause");
                subMenu(2, titulo[1]);
            } else {
                getch();
                subMenu(2, titulo[1]);
            }
            break;

        case 2:
            enConstruccion();
            break;

        case 3:
            cout<<"Proveedores Ingresados: \n";
            for (int i = 0; i<numProveedor; i++) {
                cout<<"ID: "<<P00[numProveedor].id<<endl;
                cout<<"Nombre: "<<P00[numProveedor].nombres<<endl;
                cout<<"Apellido: "<<P00[numProveedor].apellidos<<endl;
                cout<<"Identificación: "<<P00[numProveedor].identificacion<<endl;
                cout<<"Tipo de Identificación: "<<P00[numProveedor].tipo_identificacion<<endl;
                cout<<"Telefono: "<<P00[numProveedor].telefono<<endl;

            }

            if (isWindows()) {
                system("pause");
                subMenu(2, titulo[1]);
            } else {
                cin.ignore();
                getch();
                subMenu(2, titulo[1]);
            }
            break;
            
        case 4:
            break;
    }
}

void subMenu2 (int opcion) {
    switch (opcion) {
        case 1: case 2: default:
            enConstruccion();
            break;

    }
}

void validacionOpciones (int opcionElegida, int primeraOpcion, int ultimaOpcion) {
    if (!(opcionElegida)) {
            cin.clear();
            cin.ignore();
            cout<<"ERROR: OPCI�N INV�LIDA \n";
            cout<<"Presione ENTER e int�ntelo de Nuevo...\n";

            if (isWindows()) {
                system("pause");
                system("cls");
            } else {
                cin.ignore();
                getch();
                system("clear");
            }
        } else if (opcionElegida < primeraOpcion || opcionElegida > ultimaOpcion){
            cin.clear();
            cin.ignore();
            cout<<"ERROR: OPCI�N INV�LIDA \n";
            cout<<"Presione ENTER e int�ntelo de Nuevo...\n";

            if (isWindows()) {
                system("pause");
                system("cls");
            } else {
                getch();
                system("clear");
            }
            //HASTA AQUI-----
        } 
}


void enConstruccion () {
    cout<<"\nEsta funci�n actualmente se encuentra en construcci�n, regrese cuando se lance el programa de forma completa.\n";
    cout<<"Presione ENTER para regresar al inicio...\n";

    if (isWindows()) {
        system("pause");
        main();
    } else {
        cin.ignore();
        getch();
        main();
    }
}