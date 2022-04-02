#include <iostream>
#include <conio.h>
#define CANTIDAD_MAX 10
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
    void subMenu(int opcion, char area [25]);
    int subMenuOpcs (int opcion, char area[25]);
    void validacionOpciones (int opcionElegida, int primeraOpcion, int ultimaOpcion);
    void enConstruccion();
    void subMenu2 (int opcion);
    void sucursales (int opcion, int opcMenuAnt, char area[25]);
    int getCorrelativo(char tipo[25]);
    string crearId(int correlativo);
    //char campos[6] = {"Id", "Descripci�n", "Direcci�n","Tel�fono", "Encargado", "Pa�s"};
    string camposSu[] = {"Id", "Descripci�n", "Direcci�n","Tel�fono", "Encargado", "Pa�s"};
    string camposPro[] = {"Id", "Nombre", "Apellido","Identificaci�n", "Tipo de Identificaci�n", "Tel�fono", "Email", "Direcci�n"};
    string sucursalesM [CANTIDAD_MAX][6];
    string proveedoresM [CANTIDAD_MAX][8];
//-----------------------------------------------------
int main () {
    setlocale(LC_ALL, "spanish");
	sucursalesM[0][0] = "S001";
	sucursalesM[0][1] = "Sucursal Principal";
	sucursalesM[0][2] = "Km 1 1/2 Calle a Plan del Pino, Ciudadela Don Bosco 884204 Soyapango, El Salvador";
	sucursalesM[0][3] = "2251-5000";
	sucursalesM[0][4] = "Leandro Garc�a";
	sucursalesM[0][5] = "El Salvador";
    int menuOpc;
    int validacion;
    
    do {
        smsBienvenida();
        cout << "1)   Sucursal \n";
	    cout << "2)   Proveedores \n";
	    cout << "3)   Art�culos \n";
	    cout << "4)   Movimientos art�culos \n";
	    cout << "5)   Reportes \n";
	    cout << "6)   Salir\n";
	    cout<<"Seleccione la opci�n requerida: \n";
	    cin>>menuOpc;
		        
        if(!(menuOpc))
        	validacionOpciones(menuOpc, 1, 6);
        else
			menu(menuOpc);
        
    } while (menuOpc < 1 || menuOpc > 6 || menuOpc != 6);
}

void smsBienvenida () {
    cout<<"\t\t Sistema de Control de Inventarios\n";
    cout<<"\t\tEmpresa Salesiana Mar�a Auxiliadora\n";
    cout<<"\t\t      Versi�n del Sistema 1.0\n";
    cout<<"\t\t        Techno Developers\n\n";
}

void menu(int opcion) {

    char titulo [5][25] = {"Sucursal", "Proveedor", "Articulo","Movimientos Art�culos", "Reporte"};

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
		        if(!(subMenu))
        			validacionOpciones(subMenu, 1, 4);
		        else{
					switch (opcion){
		            	case 1:
		            		sucursales(subMenu, opcion, area);
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

void validacionOpciones (int opcionElegida, int primeraOpcion, int ultimaOpcion) {
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
    cout<<"\nEsta funci�n actualmente se encuentra en construcci�n, regrese cuando se lance el programa de forma completa.\n";
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

int getCorrelativo (char tipo[25]){
	int contador = 0;
	if (tipo == "sucursales"){
		for (int i = 0; i < CANTIDAD_MAX; i++){
			if (sucursalesM[i][0]!= "")
				contador ++;
		}
	}else{
		for (int i = 0; i < CANTIDAD_MAX; i++){
			if (proveedoresM[i][0] != "")
				contador ++;
		}
	}
	
	return contador+1;
}

string crearId(int correlativo){
	string id;
	if (correlativo >= 0 && correlativo < 9){
		correlativo ++;
		id = "00"+correlativo;
	}
	else if(correlativo >=9 && correlativo < 99){
		correlativo ++;
		id = "0"+correlativo;
	}
	else
		correlativo ++;
		id = correlativo;
		
	return id;
}

void sucursales (int opcion, int opcMenuAnt, char area[25]){
	int correlativo;
	string descrip;
	string direc;
	string tel;
	string name;
	string pais;
	char *id;
	switch (opcion){
		case 1:
			// correlativo = getCorrelativo("sucursales");
			// // cout<<"Ingrese su ID [Esto es temporal, mas adelante ser� automatico]: "<<id<<endl;
			// // sucursalesM[correlativo][0] = id;
			// cout<<"\n\nIngrese la descripci�n de la nueva sucursal:\n"<<endl;
			// cin.getline(sucursalesM[correlativo][1],100,'\n');
			// cout<<"\n\nIngrese la direcci�n de la nueva sucursal:\n"<<endl;
			// cin.getline(sucursalesM[correlativo][2],100,'\n');
			// cout<<"\n\nIngrese el tel�fono de la nueva sucursal:\n"<<endl;
			// cin.getline(sucursalesM[correlativo][3],100,'\n');
			// cout<<"\n\nIngrese el nombre del encargado de la nueva sucursal:\n"<<endl;
			// cin.getline(sucursalesM[correlativo][4],100,'\n');
			// cout<<"\n\nIngrese el pa�s donde estar� situada la nueva sucursal:\n"<<endl;
			// cin.getline(sucursalesM[correlativo][5],100,'\n');
			// cout<<"\n\n";
			// enConstruccion();
			break;
		
		case 2:
			enConstruccion ();
			break;
		
		case 3:
			cout << "\n\n";
			//for	(int i = 0; i < CANTIDAD_MAX; i++){
				for (int j = 0; j < 6; j++){
					cout<<camposSu[j]<<": ";
					cout<<sucursalesM[0][j]<<endl;
				}
			//}
			cout << "\n\n";
			subMenu(opcMenuAnt, area);
			break;
		
		case 4:
			main();
			break;
	}
}
