#include <iostream>
#include "inc/functions.h"
using namespace std;



int main()
{
	setlocale(LC_ALL, "spanish");
	
	Usuario admin;
	strcpy(admin.username, "admin");
	strcpy(admin.password, "1234");

	Usuario supervisor;
	strcpy(supervisor.username, "super");
	strcpy(supervisor.password, "4321");

	cargarUsuarios(admin, supervisor);

	menu_login(admin, supervisor);
	return 0;
}