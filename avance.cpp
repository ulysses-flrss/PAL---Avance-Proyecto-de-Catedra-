#include <iostream>
using namespace std;
void smsBienvenida();
int menuP();

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
            cout<<"Error. Ha ingresado una opci�n incorrecta. Int�ntelo de nuevo";
			opcionV = false;
            break;
    	}
	} while(opcionV == false);
}

void smsBienvenida () {
    cout<<"\t\t Sistema de Control de Inventarios\n";
    cout<<"\t\tEmpresa Salesiana Mar�a Auxiliadora\n";
    cout<<"\t\t      Versi�n del Sistema 1.0\n";
    cout<<"\t\t        Techno Developers\n";
}

int menuP (){
    int menuOpc;
	cout<<"1)   Sucursal \n";
    cout<<"2)   Proveedores \n";
    cout<<"3)   Art�culos \n";
    cout<<"4)   Movimientos art�culos \n";
    cout<<"5)   Reportes \n";
    cout<<"6)   Salir\n";     
	
	cout<<"Ingrese un numero del menu"<<endl;
	cin>>menuOpc;
	return menuOpc;
}
