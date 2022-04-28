#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;


struct Usuario {
	char username[15];
	char password[15];
};

//DECLARACION DE FUNCIONES
void welcome();
void login();
int validarUsuario (char userBuff[15], char passBuff[15]);

void welcome () {
	cout<<"MENSAJE DE EJEMPLO";
}


void login () {
	char userBuff[15];
	char passBuff[15];
    int intentos = 0;
	
	cout<<"Ingrese su nombre de usuario: \n";
	cin>>userBuff;
	
	cout<<"Ingrese su contrase�a: \n";
	cin>>passBuff;

	validarUsuario(userBuff, passBuff);
}

int validarUsuario (char userBuff[15], char passBuff[15]) {

	Usuario admin;
	strcpy(admin.username, "admin");
	strcpy(admin.password, "1234");

	Usuario supervisor;
	strcpy(supervisor.username, "super");
	strcpy(supervisor.password, "4321");	


	if (strcmp (admin.username, userBuff) ==0 && strcmp (admin.password, passBuff ) == 0) {
		return 0;
	} else if (strcmp (supervisor.username, userBuff) == 0 && strcmp (supervisor.password, passBuff ) == 0) {
		return 1;
	} else {
		cout<<"ERROR: Nombre o Usuario Incorrectos. Presione ENTER e Intentelo de Nuevo \n";
		cin.ignore();
		getch();
		login();
		
		return 2;
	};
}



