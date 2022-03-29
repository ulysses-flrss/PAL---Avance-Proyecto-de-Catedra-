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
//Funciones
    void smsBienvenida();
    void menu (int opcion);
    bool isWindows();
    void subMenu(int opcion, char area [12]);

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

        if (!(menuOpc)) {
            cin.clear();
            cin.ignore();
            cout<<"ERROR: OPCIÓN INVALIDA \n";
            cout<<"Presione ENTER e intentelo de Nuevo...\n";

            //OPTIMIZAR DESDE AQUÍ....
            if (isWindows()) {
                system("pause");
                system("cls");
            } else {
                cin.ignore();
                getch();
                system("clear");
            }
        } else if (menuOpc < 1 || menuOpc > 6){
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
        } else {
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

    char titulo [5][20] = {"Sucursal", "Proveedor", "Articulo", "Reportes"};

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

//Registrar sucursal
// Modificar sucursal
// Ver registro de sucursales
// Regresar al menú


void subMenu (int opcion, char area[25]) {
    int subMenu = 0;
    switch (opcion) {
        case 1: case 2:
            smsBienvenida();
            cout<<"Ingresando a "<<area<<"es...\n";
            cout<<"1) Registrar "<<area<<endl;
            cout<<"2) Modificar "<<area<<endl;
            cout<<"3) Ver registro de "<<area<<"es";
            cout<<"4) Regresar al menú";
            break;

        case 3:
            smsBienvenida();
            cout<<"Ingresando a "<<area<<"es...\n";
            cout<<"1) Registrar "<<area<<endl;
            cout<<"2) Modificar "<<area<<endl;
            cout<<"3) Ver registro de "<<area<<"s\n";
            cout<<"4) Regresar al menú\n";
            break;

        case 4:
            smsBienvenida();
            cout<<"Ingresando a "<<area<<"es...\n";
            cout<<"1) Registro de entrada de inventarios\n";
            cout<<"2) Registro de salida de inventarios\n";
            break;

        case 5:
            smsBienvenida();
            cout<<"Reporte de Inventarios";
            cout<<"Reporte de Movimientos";
            break;

        default:
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

