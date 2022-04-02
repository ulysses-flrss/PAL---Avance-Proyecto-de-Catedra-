#include <iostream>
#include <conio.h>
#define CANTIDAD_MAX 10
#ifdef __linux__
    #define OS 0
#elif _WIN32
    #define OS 1
#else
    #define OS 2
#endif


using namespace std;
//Declaracion de funciones ----------------------------
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
    // int getCorrelativo(char tipo[25]);
    // string crearId(int correlativo);
    
//-----------------------------------------------------


    int numSucursal = 0;
    char id[CANTIDAD_MAX][5];
    char descripcion [CANTIDAD_MAX][90];
    char direccion [CANTIDAD_MAX][75];
    char telefono [CANTIDAD_MAX][9];
    char encargado [CANTIDAD_MAX][35];

    int numProveedor = 0;
    char id2[CANTIDAD_MAX][5];
    char nombre [CANTIDAD_MAX][30];
    char apellido [CANTIDAD_MAX][30];
    char identificacion [CANTIDAD_MAX][15];
    char tipo_identificacion [CANTIDAD_MAX][25];
    char telefono2 [CANTIDAD_MAX][9];

int main () {
    setlocale(LC_ALL, "spanish");



    int menuOpc;
    menuOpc = 0;
    
    
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
            if (isWindows()) {
                system("cls");
            } else {
                system("clear");
            }
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
            cout<<"Ingresado a "<< area <<endl;
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

    switch (accion) {
        case 1:
            cout<<"Ingrese el ID (esto es temporal): \n";
            cin.ignore();
            cin.getline(id[numSucursal], 5, '\n');
            fflush(stdin);  

            cout<<"Ingrese la descripción de la sucursal: \n";
            cin.getline(descripcion[numSucursal], 90, '\n');
            fflush(stdin);  

            cout<<"Ingrese la direccion de la sucursal: \n";
            cin.getline(direccion[numSucursal], 75, '\n');
            fflush(stdin);

            cout<<"Ingrese el telefono de la sucursal: \n";
            cin.getline(telefono[numSucursal], 9, '\n');
            fflush(stdin);

            cout<<"Ingrese el nombre del encargado de la sucursal: \n";
            cin.getline(encargado[numSucursal], 35, '\n');
            fflush(stdin);

            numSucursal++;
            fflush(stdin);
            cout<<"SUCURSAL REGISTRADA CORRECTAMENTE...\n";
            cout<<"Presione ENTER para volver al menú";

            if (isWindows()) {
                system("pause");
                subMenu(1,"Sucursal");
            } else {
                getch();
                subMenu(1, "Sucursal");
            }
            break;

        case 2:
            enConstruccion();
            break;

        case 3:
            cout<<"Sucursales Ingresadas: \n";
            for (int i = 0; i<numSucursal; i++) {
                cout<<"ID: "<<id[i]<<endl;
                cout<<"Descripcion: "<<descripcion[i]<<endl;
                cout<<"Dirección: "<<direccion[i]<<endl;
                cout<<"Télefono: "<<telefono[i]<<endl;
                cout<<"Encargado: "<<encargado[i]<<endl;
                
            }

            if (isWindows()) {
                system("pause");
                subMenu(1, "Sucursal");
            } else {
                cin.ignore();
                getch();
                subMenu(1, "Sucursal");
            }
            break;
            
        case 4:
            break;
    }
}

void proveedores (int accion) {


    switch (accion) {
        case 1:
            cout<<"Ingrese el ID (esto es temporal): \n";
            cin.ignore();
            cin.getline(id2[numProveedor], 5, '\n');
            fflush(stdin);  

            cout<<"Ingrese un nombre del proveedor: \n";
            cin.getline(nombre[numProveedor], 30, '\n');
            fflush(stdin);  

            cout<<"Ingrese un apellido del proveedor: \n";
            cin.getline(apellido[numProveedor], 30, '\n');
            fflush(stdin);

            cout<<"Ingrese el número de identificación del proveedor: \n";
            cin.getline(identificacion[numProveedor], 15, '\n');
            fflush(stdin);

            cout<<"Ingrese el tipo de identificación del proveedor: \n";
            cin.getline(tipo_identificacion[numProveedor], 25, '\n');
            fflush(stdin);

             cout<<"Ingrese el telefono del proveedor: \n";
            cin.getline(telefono2[numProveedor], 9, '\n');
            fflush(stdin);

            numProveedor++;
            fflush(stdin);
            cout<<"PROVEEDOR REGISTRADO CORRECTAMENTE...\n";
            cout<<"Presione ENTER para volver al menú";

            if (isWindows()) {
                system("pause");
                subMenu(2, "Proveedor");
            } else {
                getch();
                subMenu(2, "Proveedor");
            }
            break;

        case 2:
            enConstruccion();
            break;

        case 3:
            cout<<"Proveedores Ingresados: \n";
            for (int i = 0; i<numProveedor; i++) {
                cout<<"ID: "<<id2[i]<<endl;
                cout<<"Nombre: "<<nombre[i]<<endl;
                cout<<"Apellido: "<<apellido[i]<<endl;
                cout<<"Identificación: "<<identificacion[i]<<endl;
                cout<<"Tipo de Identificación: "<<tipo_identificacion[i]<<endl;
                cout<<"Telefono: "<<telefono2[i]<<endl;

            }

            if (isWindows()) {
                system("pause");
                subMenu(2, "Proveedor");
            } else {
                cin.ignore();
                getch();
                subMenu(2, "Proveedor");
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

bool isWindows () {
    if (OS == 0) {
        return false;
    } else if(OS == 1) {
        return  true;
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

// int getCorrelativo (char tipo[25]){
// 	int contador = 0;
// 	if (tipo == "sucursales"){
// 		for (int i = 0; i < CANTIDAD_MAX; i++){
// 			if (sucursalesM[i][0]!= "")
// 				contador ++;
// 		}
// 	}else{
// 		for (int i = 0; i < CANTIDAD_MAX; i++){
// 			if (proveedoresM[i][0] != "")
// 				contador ++;
// 		}
// 	}
	
// 	return contador+1;
// }

// string crearId(int correlativo){
// 	string id;
// 	if (correlativo >= 0 && correlativo < 9){
// 		correlativo ++;
// 		id = "00"+correlativo;
// 	}
// 	else if(correlativo >=9 && correlativo < 99){
// 		correlativo ++;
// 		id = "0"+correlativo;
// 	}
// 	else
// 		correlativo ++;
// 		id = correlativo;
		
// 	return id;
// }


