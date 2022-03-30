#include <iostream>
#include <conio.h>
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
    void menu (int opcion);
    bool isWindows();
    void subMenu(int opcion, char area [12]);
    void validacionOpciones (int opcionElegida, int primeraOpcion, int ultimaOpcion);
    void enConstruccion();
    void subMenu2 (int opcion);
//-----------------------------------------------------
int main () {
    setlocale(LC_ALL, "spanish");
    int menuOpc;

    do {
        smsBienvenida();
        cout << "1)   Sucursal \n";
        cout << "2)   Proveedores \n";
        cout << "3)   Artículos \n";
        cout << "4)   Movimientos artículos \n";
        cout << "5)   Reportes \n";
        cout << "6)   Salir\n";
        cout<<"Seleccione la opción requerida: \n";

        cin>>menuOpc;

        if(!(menuOpc)) {
            validacionOpciones (menuOpc, 1, 6);
        }
        else {
            menu(menuOpc);
        }
        
    } while (menuOpc < 1 || menuOpc > 6);
}

void smsBienvenida () {
    cout<<"\t\t Sistema de Control de Inventarios\n";
    cout<<"\t\tEmpresa Salesiana María Auxiliadora\n";
    cout<<"\t\t      Versión del Sistema 1.0\n";
    cout<<"\t\t        Techno Developers\n";
}

void menu(int opcion) {

    char titulo [5][25] = {"Sucursal", "Proveedor", "Articulo","Movimientos Artículos", "Reporte"};

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
            smsBienvenida();
            if (opcion == 3)cout<<"Ingresando a "<<area<<"s...\n";
            else cout<<"Ingresando a "<<area<<"es...\n";
            cout<<"1) Registrar "<<area<<endl;
            cout<<"2) Modificar "<<area<<endl;
            if (opcion == 3) cout<<"3) Ver registro de "<<area<<"s\n";
            else cout<<"3) Ver registro de "<<area<<"es\n";
            cout<<"4) Regresar al menú\n";
            cin>>subMenu;
            if(!(subMenu)) {
                validacionOpciones (subMenu, 1, 4);
            }
            else {
                subMenu2(subMenu);
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
            cout<<"ERROR: OPCIÓN INVALIDA \n";
            cout<<"Presione ENTER e intentelo de Nuevo...\n";

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
            cout<<"ERROR: OPCIÓN INVALIDA \n";
            cout<<"Presione ENTER e intentelo de Nuevo...\n";

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
    cout<<"\nEsta función actualmente se encuentra en construcción, regrese cuando se lance el programa de forma completa.\n";
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

