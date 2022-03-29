#include <iostream>
using namespace std;
void smsBienvenida();

int main () {
    smsBienvenida();
    cout<<"1)Sucursal \n";
    cout<<"2)Proveedores \n";
    cout<<"3)Artículos \n";
    cout<<"4)Movimientos artículos \n";
    cout<<"5)Reportes \n";
    cout<<"6) \n";

    int menu;
     
	 cout<<"Ingrese un numero del menu"<<endl;
	 cin>>menu;

        switch (menu){
           case 1:
             cout<<"Has seleccionado Sucursal";
        break;
            case 2:
            cout<<"Has seleccionado Proveedores";
        break;
            case 3:
            cout<<"Has seleccionado Artículos";
        break;
            case 4:
            cout<<"Has seleccionado Movimientos artículados";
        break;
            case 5:
           cout<<"Has seleccionado Reportes";
        break;
    
           default:
           	cout<<"Ingrese una opcion correcta";
        break;
        }
}



void smsBienvenida () {
    cout<<"\t\t Sistema de Control de Inventarios\n";
    cout<<"\t\tEmpresa Salesiana María Auxiliadora\n";
    cout<<"\t\t      Versión del Sistema 1.0\n";
    cout<<"\t\t        Techno Developers\n";
}