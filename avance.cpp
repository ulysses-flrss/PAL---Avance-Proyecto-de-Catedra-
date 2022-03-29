#include <iostream>
#include <conio.h>
using namespace std;
void smsBienvenida();
void mostrarMenu();
int menuP();
void menuEspera();
void subMenu (int numArea, char area[15]);

int main () {
    setlocale(LC_ALL, "spanish");
    bool opcionV = true;
    smsBienvenida();
    do{
        switch (menuP()){

        case 1:
			cout<<"Has seleccionado Sucursal"<<endl;
            subMenu (1, "Sucursal");
			opcionV = true;
            break;

        case 2:
            cout<<"Has seleccionado Proveedores"<<endl;
            subMenu (2, "Proveedor");
			opcionV = true;
            break;

        case 3:
            cout<<"Has seleccionado Artículos"<<endl;
            subMenu (3, "Articulo");
			opcionV = true;
            break;

        case 4:
            cout<<"Has seleccionado Movimientos articulados"<<endl;
            subMenu (4, "Movimientos Artículos");
			opcionV = true;
            break;

        case 5:
    		cout<<"Has seleccionado Reportes"<<endl;
            subMenu (5, "Reportes");
			opcionV = true;
            break;

        case 6:
    		cout<<"Has seleccionado Salir"<<endl;
			opcionV = true;
            break;
    
        default:
            cout<<"Error. Ha ingresado una opción incorrecta. Inténtelo de nuevo\n";
			opcionV = false;
            break;
    	}
    } while (opcionV = false);
}

    void smsBienvenida () {
        cout<<"\t\t Sistema de Control de Inventarios\n";
        cout<<"\t\tEmpresa Salesiana María Auxiliadora\n";
        cout<<"\t\t      Versión del Sistema 1.0\n";
        cout<<"\t\t        Techno Developers\n";
    }

int menuP (){
    int menuOpc = 0;

        
        mostrarMenu();
        cout << "Ingrese una opción de acuerdo al número de menú" << endl;
        

        while(!(cin>>menuOpc)){
			cin.clear();
			cin.ignore();
            //(system("cls") //para windows

            system("clear");
            cout<<"Validando Opción...\n";
            sleep(2);
            system("clear");
            
            smsBienvenida();
            mostrarMenu();
			cout<<"ERROR: Ingrese un número de acuerdo al menú...\n";

            
		}

            
            cout<<"Validando Opción...\n";
            sleep(1);
            

    return menuOpc;  
}

void mostrarMenu () {
        cout << "1)   Sucursal \n";
        cout << "2)   Proveedores \n";
        cout << "3)   Artículos \n";
        cout << "4)   Movimientos artículos \n";
        cout << "5)   Reportes \n";
        cout << "6)   Salir\n";
}

void subMenu (int numArea, char area [15]) {
    system("clear");
    smsBienvenida();
    cout<<"Usted ha seleccionado "<<area<<endl;

    switch (numArea) {
        case 1: case 2: 
            cout<<"1- Registrar "<<area<<endl;
            cout<<"2- Modificar "<<area<<endl;
            cout<<"3- Ver registro de  "<<area<<"es"<<endl;
            cout<<"4- Regresar al Menú"<<endl;
            break;

        case 3:
            cout<<"1- Registrar "<<area<<endl;
            cout<<"2- Modificar "<<area<<endl;
            cout<<"3- Ver registro de  "<<area<<"s"<<endl;
            cout<<"4- Regresar al Menú"<<endl;
            break;

        case 4:
            cout<<"Registro de entrada de inventarios\n";
            cout<<"Registro de salida de inventarios\n";
            break;


        case 5:
            cout<<"Reporte de Invetarios";
            cout<<"Reporte de Movimientos";
            break;

        default:
            break;        

    }
}
