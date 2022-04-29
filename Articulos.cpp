#include <iostream>
using namespace std;

struct Articulos{
int id; 
char tipo_articulo[10];
char nombre[20];
char caracteristicas [20];
float Precio_venta;
float costo;
int idProveedor;
};

int main (){

	Articulos shampoo;

cout<<"Ingrese su id";
  cin>>shampoo.id;
  
  cout<<"Ingrese el tipo de articulo";
  cin.getline(shampoo.tipo_articulo,10,'\n');

  cout<<"Ingrese el nombre del articulo";
  cin.getline(shampoo.nombre,20,'\n');

  cout<<"Ingrese las caracteristicas";
  cin.getline(shampoo.caracteristicas,20,'\n');

  cout<<"Ingrese el precio del articulo";
  cin>>shampoo.Precio_venta;

  cout<<"Ingrese el costo del articulo";
  cin>>shampoo.costo;

  cout<<"Ingrese el id del Proveedor";
  cin>>shampoo.idProveedor;
  
}