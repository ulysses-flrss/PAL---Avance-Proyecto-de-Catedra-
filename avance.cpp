#include <iostream>
#include <conio.h>
using namespace std;
void smsBienvenida();
void mostrarMenu();
int menuP();
void menuEspera();

int main () {
	setlocale(LC_ALL, "spanish");
    bool opcionV = true;
    smsBienvenida();
	
    do{
		switch (menuP()){

        case 1:
			cout<<"Has seleccionado Sucursal"<<endl;
			opcionV = true;
            break;

        case 2:
            cout<<"Has seleccionado Proveedores"<<endl;
			opcionV = true;
            break;

        case 3:
            cout<<"Has seleccionado Artículos"<<endl;
			opcionV = true;
            break;

        case 4:
            cout<<"Has seleccionado Movimientos artículados"<<endl;
			opcionV = true;
            break;

        case 5:
    		cout<<"Has seleccionado Reportes"<<endl;
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
