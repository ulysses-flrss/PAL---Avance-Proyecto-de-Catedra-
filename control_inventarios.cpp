#include <iostream>
#include <conio.h>
#include <string.h>
#include <cstring>
#define USUARIO_MAX 100

using namespace std;

    char usuarioAdmin[6] = "admin";
    char contraAdmin[6] = "12345";

    char crearCuenta [10] = "";

bool verificarAdmin (char usuarioIngresado[13], char contraIngresada[16]);

int main () {

    

    int numUsuario = 0;
    char usuario [USUARIO_MAX][13];
    char contras [USUARIO_MAX][16];

    char usuarioIngresado [13];
    char contraIngresada [16];

    int menu;

    cout<<"\t\t\tBienvenido al Control de Inventario de\n\t\t\t- Empresa Salesiana María Auxiliadora -"<<endl<<endl;

    do {
        
        cout<<"Opciones"<<endl;
        cout<<"1- Crear un usuario"<<endl;
        cout<<"2- Iniciar sesión"<<endl;
        cout<<"3- Salir del programa"<<endl;
        
    // cin.ignore();
    // menu = getch();
    cout<<"Elija una opción[1-3]: ";
    while(!(cin>>menu)){
			cin.clear();
			cin.ignore(255, '\n');
			cout<<"Error, vuelva a ingresar el dato... '\n'";
		}



    system("clear");

    } while (menu < 1 || menu > 3);

    switch (menu) {
        case 1:
            cout<<"Procederá a crear una cuenta"<<endl;
            cout<<"Usuario: ";
            cin.ignore();
            cin.getline(usuario[numUsuario], 13, '\n');

            cout<<"Contraseña: ";
            cin>>contras[numUsuario];
            cout<<"Creando Usuario, Espere Un Momento..."<<endl<<endl;
            sleep(2);

            usuarioIngresado = usuario[numUsuario];
            contraIngresada = contras[numUsuario];

            cout<<"Tu Usuario Ha Sido Creado De Manera Satisfactoria"<<endl;
            cout<<"Usuario: "<<usuario[numUsuario]<<endl;
            cout<<"Usuario: "<<contras[numUsuario]<<endl<<endl;
            sleep(3);
            system("clear");
        
            break;

        case 2:
            break;

        case 3:
            cout<<"Bienvenido..."<<endl;
            cout<<"Ingrese su Usuario: "<<endl;
            cin>>usuarioIngresado;

            cout<<"Ingrese su contraseña: "<<endl;
            cin>>contraIngresada;

            
            if (verificarAdmin(usuarioIngresado, contraIngresada) == true) {
                cout<<"Admin";
            } else if () {
                cout<<"Supervisor";
            } else {
                
            }
            break;

        default:
            break;
    }

}

bool verificarAdmin (char usuario[12], char contra[15]) {
    if (strcmp(usuario, usuarioAdmin) == 0 && strcmp(contra, contraAdmin) == 0) {
        return true;
    } else {
        return false;
    }
}

void menu () {

}








