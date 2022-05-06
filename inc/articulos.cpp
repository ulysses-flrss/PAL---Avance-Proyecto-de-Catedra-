#include <iostream>
#include <conio.h>
#define MAX 100
using namespace std;

void registrarArticulo();

struct Articulo {
    char id [5];
    char tipo_articulo[30];
    char nombre[30];
    char caracteristicas [90];
    int precioVenta;
    int costo;
    char idProveedor[100];

    void registrarArticulo(){
        cout<<"Elija el tipo de articulo (Di\u0301gite un nu\u0301mero\n";
        cout<<"1- Papeleri\u0301a\n";
        cout<<"2- Libros\n";
        cout<<"3- Arti\u0301culos\n";
        cout<<"4- Souvenirs\n";
        cout<<"5- Arti\u0301culos religiosos\n";
        cin>>

        
    }
}

int main () {
    return 0;
}


