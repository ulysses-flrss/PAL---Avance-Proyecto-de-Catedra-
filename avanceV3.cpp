#include <iostream>
#include <conio.h>
#define SUCURSALES_MAX 100
#ifdef __linux__
    #define OS 0
#elif _WIN32
    #define OS 1
#else
    #define OS 2
#endif

using namespace std;
//Declaracion de funciones ----------------------------
    void smsBienvenida();
    int menuP();
    void menu (int opcion);
    bool isWindows();
    void subMenu(int opcion, char area [12]);
    int subMenuOpcs (int opcion, char area[25]);
    int validacionOpciones (int opcionElegida, int primeraOpcion, int ultimaOpcion);
    void enConstruccion();
    void subMenu2 (int opcion);
    void sucursales (int opcion);
    //char campos[6] = {"Id", "Descripci�n", "Direcci�n","Tel�fono", "Encargado", "Pa�s"};
    string camposSu[] = {"Id", "Descripci�n", "Direcci�n","Tel�fono", "Encargado", "Pa�s"};
    string sucursalesM [SUCURSALES_MAX][6];
//-----------------------------------------------------
int main () {
    setlocale(LC_ALL, "spanish");
	sucursalesM[0][0] = "S001";
	sucursalesM[0][1] = "Sucursal Principal";
	sucursalesM[0][2] = "Km 1 1/2 Calle a Plan del Pino, Ciudadela Don Bosco 884204 Soyapango, El Salvador";
	sucursalesM[0][3] = "2251 5000";
	sucursalesM[0][4] = "Leandro Garc�a";
	sucursalesM[0][5] = "El Salvador";
    int menuOpc;
    int validacion;
    
    do {
        smsBienvenida();
        menuOpc = menuP();
        
        validacion = validacionOpciones(menuOpc, 1, 6);
        
        if(validacion)
            menu(menuOpc);
        
    } while (menuOpc < 1 || menuOpc > 6);
}

void smsBienvenida () {
    cout<<"\t\t Sistema de Control de Inventarios\n";
    cout<<"\t\tEmpresa Salesiana Mar�a Auxiliadora\n";
    cout<<"\t\t      Versi�n del Sistema 1.0\n";
    cout<<"\t\t        Techno Developers\n";
}

int menuP (){
	int opcionUs = 0;
    cout << "1)   Sucursal \n";
    cout << "2)   Proveedores \n";
    cout << "3)   Art�culos \n";
    cout << "4)   Movimientos art�culos \n";
    cout << "5)   Reportes \n";
    cout << "6)   Salir\n";
    cout<<"Seleccione la opción requerida: \n";

    cin>>opcionUs;
    
    return opcionUs;
}

void menu(int opcion) {

    char titulo [5][25] = {"Sucursal", "Proveedor", "Articulo","Movimientos Artículos", "Reporte"};

    switch (opcion) {
        case 1: 
            subMenu(1, titulo[0]);
            break;

        case 2:
            subMenu(2, titulo[1]);
            break;

        case 3:
            subMenu(3, titulo[2]);
            break;

        case 4:
            subMenu(4, titulo[3]);
            break;

        case 5:
            subMenu(5, titulo[4]);
            break;

        case 6:
            if (isWindows()) {
                system("cls");
            } else {
                system("clear");
            }
            cout<<"Saliendo del programa...\n";
            break;

        default:
            break;
    }
}


void subMenu (int opcion, char area[25]) {
    int subMenu = 0;
    int validacion;
    switch (opcion) {
        case 1: case 2: case 3:
	        do{
				smsBienvenida();
	    		subMenu = subMenuOpcs(opcion, area);
        		validacion = validacionOpciones(subMenu, 1, 4);
		        if(validacion){
		            switch (opcion){
		            	case 1:
		            		sucursales(validacion);
		            		break;
		            	case 2:
		            	case 3:
		            		enConstruccion();
		            		break;
					}	
				}
	            /*if(!(subMenu)) {
	                validacionOpciones (subMenu, 1, 4);
	            }
	            else {
	                subMenu2(subMenu);
	            }*/
			}while(subMenu >= 1 && subMenu <= 4);
            break;

        case 4:
            smsBienvenida();
            cout<<"Ingresando a "<<area<<"...\n";
            cout<<"1) Registro de entrada de inventarios\n";
            cout<<"2) Registro de salida de inventarios\n";
            cin>>subMenu;
            validacionOpciones (subMenu, 1, 2);
            if(!(subMenu)) {
                validacionOpciones (subMenu, 1, 4);
            } else {
                subMenu2(subMenu);
            }
            break;

        case 5:
            smsBienvenida();
            cout<<"Ingresando a "<<area<<"...\n";
            cout<<"1) Reporte de Inventarios\n";
            cout<<"2) Reporte de Movimientos\n";
            cin>>subMenu;
            validacionOpciones (subMenu, 1, 2);
            if(!(subMenu)) {
                validacionOpciones (subMenu, 1, 4);
            } else {
                subMenu2(subMenu);
            }
            break;

        default:
            break;
    }
}

int subMenuOpcs (int opcion, char area[25]){
	int subMenu = 0;
    if (opcion == 3)cout<<"Ingresando a "<<area<<"s...\n";
	else cout<<"Ingresando a "<<area<<"es...\n";
	cout<<"1) Registrar "<<area<<endl;
    cout<<"2) Modificar "<<area<<endl;
    if (opcion == 3) cout<<"3) Ver registro de "<<area<<"s\n";
    else cout<<"3) Ver registro de "<<area<<"es\n";
    cout<<"4) Regresar al men�\n";
    cin>>subMenu;
    return subMenu;
}

void subMenu2 (int opcion) {
    switch (opcion) {
        case 1: case 2: default:
            enConstruccion();
            break;

    }
}

bool isWindows () {
    if (OS == 0) {
        return false;
    } else if(OS == 1) {
        return  true;
    }
}

int validacionOpciones (int opcionElegida, int primeraOpcion, int ultimaOpcion) {
    if (!(opcionElegida)) {
            cin.clear();
            cin.ignore();
            cout<<"ERROR: OPCI�N INV�LIDA \n";
            cout<<"Presione ENTER e int�ntelo de Nuevo...\n";

            if (isWindows()) {
                system("pause");
                system("cls");
            } else {
                cin.ignore();
                getch();
                system("clear");
            }
        } else if (opcionElegida < primeraOpcion || opcionElegida > ultimaOpcion){
            cin.clear();
            cin.ignore();
            cout<<"ERROR: OPCI�N INV�LIDA \n";
            cout<<"Presione ENTER e int�ntelo de Nuevo...\n";

            if (isWindows()) {
                system("pause");
                system("cls");
            } else {
                getch();
                system("clear");
            }
            //HASTA AQUI-----
        } 
}


void enConstruccion () {
    cout<<"\nEsta función actualmente se encuentra en construcción, regrese cuando se lance el programa de forma completa.\n";
    cout<<"Presione ENTER para regresar al inicio...\n";

    if (isWindows()) {
        system("pause");
        main();
    } else {
        cin.ignore();
        getch();
        main();
    }
}

void sucursales (int opcion){
	switch (opcion){
		case 1:
			enConstruccion ();
			break;
		
		case 2:
			enConstruccion ();
			break;
		
		case 3:
			for	(int i = 0; i < SUCURSALES_MAX; i++){
				for (int j = 0; j < 6; j++){
					cout<<camposSu[j]<<": ";
					cout<<sucursalesM[i][j]<<endl;
				}
			}
			break;
		
		case 4:
			main();
            
			break;
	}
}

/*string getCorrelativo (){
	
}*/
