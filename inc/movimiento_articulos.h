#include <iostream>
using namespace std;

//Definicion de Funciones

struct Movimiento {
    bool tipo; //entrada (true), salida (false)
    int id; //numero incrementable de 1 en uno
    int tipo_origen; // 1- proveedor ; 2-sucursal
    int id_origen; // id del proveedor/sucursal de origen
    int tipo_destino; // 1-venta ; 2-sucursal ; 3-venta
    int id_destino; // id del proveedor/sucursal de destino 
    int id_articulo; //id articulo existente
    int cantidad; //cantidad de articulos
    char motivo_movimiento[30]; //Entradas: "Compra de articulos", "Movimientos entre sucursales", ; Salidas: "", "Venta de articulos", "Devolucion";
    char tipo_movimiento[]; //E = Entrada, S = Salida


    void crearMovimiento (int tipo) {

    cout<<"Ingrese el Tipo de Origen (Elija un nu\u0303mero) \n";
    cout<<"1- Proveedor";
    cout<<"2- Sucursal";
    cin>>this->tipo_origen;

    cout<<"Di\u0301gite el ID de origen de acuerdo al tipo de origen previamente seleccionado\n";
    cin>>this->id_origen;

    cout<<"Ingrese el Tipo de Destino (Elija un nu\u0303mero)\n";
    cout<<"1- Proveedor";
    cout<<"2- Sucursal";
    cout<<"3- Venta";
    cin>>this->tipo_destino;

    cout<<"Di\u0301gite el ID de destino de acuerdo al tipo de destino previamente seleccionado\n";
    cin>>this->id_destino;

    cout<<"Di\u0301gite el ID del articulo previamente existente\n";
    cin>>this->id_articulo;

    cout<<"Escriba la cantidad de arti\u0301 que movera\u0301\n";
    cin>>this->cantidad;

    cout<<"Escriba la razo\u0301 del movimiento(Elija un nu\u0301mero\n";
    if (tipo == 0) {
        cout<<"1- Compra de Arti\u0301culos\n";
        cout<<"2- Movimientos entre sucursales\n";
    } else if (tipo == 1) {
        cout<<"1- Venta de Arti\u0301culos\n";
        cout<<"2- Devolucio\u0301n\n";
    }
    cin>>this->motivo_movimiento;

    if (tipo == 0) {
        this->tipo_movimiento = 'E';
    } else if (tipo == 1) {
        this->tipo_movimiento = 'S';
    }

    cout<<"Ingrese la fecha del movimiento:\n";
    cout<<"Ingrese el día\n";
    cout<<"1- Domingo\n";
    cout<<"2- Lunes\n";
    cout<<"3- Martes\n";
    cout<<"4- Mie\u0301rcoles\n";
    cout<<"5- Jueves\n";
    cout<<"6- Viernes\n";
    cout<<"7- Sa\u0301bado\n";
    // cin>>this->fecha.dia;

    // cout<<"Ingrese el nu\u0301mero de mes\n [1- Enero.....12- Diciembre]";
    // cin>>this->fecha.mes;

    // cout<<"Di\u0301gite el an\u0303o";
    // cin>>this->fecha.anio;
    }
};
