#include <iostream>
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
        } else {
            menu(menuOpc);
        }

        if (isWindows()) {
            system("pause");
            system("cls");
        } else {
            system("sleep 2s");
            system("clear");
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
    switch (opcion) {
        case 1:
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            if (isWindows()) {
                system("cls");
            } else {
                system("clear");
            }
            cout<<"Saliendo del programa...";
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

