#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream >
using namespace std;

struct Sucursal{
	char id[5];
	char descripcion[100];
	char direccion[100];
	char telefono[10];
	char encargado[50];
	char pais[15];
};

struct Proveedores{
	char id[5];
	char nombre[30];
	char apellido[50];
	char identificacion[20];
	char tipoIdentificacion[5];
	char telefono[9];
	char email[100];
	char direccion[100];
};

struct Articulos{
	char id[5];
	char tipoArticulo[25];
	char nombre[50];
	char caracteristicas[100];
	float precioVenta;
	float costo;
	char idProveedor[5];
};

void crearSucursal();
void guardarSucursal(Sucursal, char tareaSel[15], int posicion);
void mostrar(char idIng[5], char mostrarTipo[25], char areaSel[25]);
void modificarSucursal(char idIng[5], char areaSel[25], int opcionSel);
int crearCorrelativo(char areaSel[25]);
int correlativo(char areaSel[25]);
bool validarDatos(char datosIng[100], int numDato);
bool validarTel(char numTel[9]);

int crearCorrelativo(char areaSel[25]){
	int correlativo;
	char areas[3][25] = {"sucursales", "proveedores", "articulos"};
	
	ifstream correlativoget;
	
	if (strcmp(areaSel, areas[0]) == 0){
		correlativoget.open("archivos/contsucursales.dat", ios::binary);
		
		if (correlativoget.fail()){
			cout << "ERROR";
		}
		
		correlativoget.seekg(0);
		correlativoget.read((char *)&correlativo, sizeof(int));
		
		correlativo = 1;
		
		correlativoget.close();
		
		ofstream correlativosave;
		
		correlativosave.open("archivos/contsucursales.dat", ios::binary);
		
		correlativosave.write((char *)&correlativo, sizeof(int));
		
		correlativosave.close();
	}else if(strcmp(areaSel, areas[1]) == 0){
		
		correlativoget.open("archivos/contproveedores.bin", ios::binary);
		
		if (correlativoget.fail()){
			cout << "ERROR";
		}
		
		correlativoget.seekg(0);
		correlativoget.read((char *)&correlativo, sizeof(int));
		
		correlativo += 1;
		
		correlativoget.close();
		
		ofstream correlativosave;
		
		correlativosave.open("archivos/contproveedores.bin", ios::binary);
		
		correlativosave.write((char *)&correlativo, sizeof(int));
		
		correlativosave.close();
	}else if(strcmp(areaSel, areas[2]) == 0){
		correlativoget.open("archivos/contarticulos.bin", ios::binary);
		
		if (correlativoget.fail()){
			cout << "ERROR";
		}
		
		correlativoget.seekg(0);
		correlativoget.read((char *)&correlativo, sizeof(int));
		
		correlativo += 1;
		
		correlativoget.close();
		
		ofstream correlativosave;
		
		correlativosave.open("archivos/contarticulos.bin", ios::binary);
		
		correlativosave.write((char *)&correlativo, sizeof(int));
		
		correlativosave.close();
	}
	
	return correlativo;
}

int correlativo(char areaSel[25]){
	int correlativo;
	char areas[3][25] = {"Sucursales", "Proveedores", "Articulos"};
	
	ifstream correlativoget;
	
	correlativoget.open("archivos/contsucursales.dat", ios::binary);
	
	if (correlativoget.fail())
		cout << "ERROR. No se pudo abrir el archivo.";

	correlativoget.read((char *)&correlativo, sizeof(int));
	
	cout << correlativo;
	
	correlativoget.close();
	
	return correlativo;
}

void crearSucursal(){
	char id[4];
	char area[] = "sucursales";
	int correlativo = crearCorrelativo(area);
	Sucursal sucursalNew;
	if (correlativo < 10){
		id[0] = 'S';
		id[1] = '0';
		id[2] = '0';
		id[3] = correlativo + 0x30;
	} else if (correlativo < 100){
		id[0] = 'S';
		id[1] = '0';
		id[2] = correlativo + 0x30;
	} else{
		id[0] = 'S';
		id[1] = correlativo + 0x30;
	}
	
	cout << "El id de la sucursal a crear es: ";
	
	for (int i = 0; i < 4; i++){
		cout << id[i];
	}
	cout << endl;
	
	strcpy(sucursalNew.id, id);
	
	char desc[100], direc[100], tel[9], encar[50], pais[15], tarea[15] = "crear", vacio[2][2] = {" ", ""};
	char datosIng[5][100];
	char datos[5][100] = {"Ingrese la descripcion:", "Ingrese la dirección:", "Ingrese el número de teléfono:",
	"Ingrese el nombre del encargado:", "Seleccione el país de la sucursal:"};
	int size[5] = {100, 100, 9, 50, 15}, opcPais, posicion = 0;
	bool repetir;
	do{
		repetir = true;
		cout << "\nIngrese la descripción: " << endl;
		cin.getline(sucursalNew.descripcion, 100, '\n');
		fflush(stdin);
		if (strcmp(sucursalNew.descripcion, vacio[0]) == 0 || strcmp(sucursalNew.descripcion, vacio[1]) == 0){
			cout<<"\nERROR: No puede dejar vacío este campo" << endl;
		}else{
			repetir = false;
		}
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nIngrese la dirección: " << endl;
		cin.getline(sucursalNew.direccion, 100, '\n');
		fflush(stdin);
		if (strcmp(sucursalNew.direccion, vacio[0]) == 0 || strcmp(sucursalNew.direccion, vacio[1]) == 0){
			cout<<"\nERROR: No puede dejar este campo vacío." << endl;
		}else{
			repetir = false;
		}
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nIngrese el número de teléfono: " << endl;
		cin.getline(sucursalNew.telefono, 10, '\n');
		fflush(stdin);
		repetir = validarTel(sucursalNew.telefono);
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nIngrese el nombre del encargado: " << endl;
		cin.getline(sucursalNew.encargado, 50, '\n');
		fflush(stdin);
		if (strcmp(sucursalNew.encargado, vacio[0]) == 0 || strcmp(sucursalNew.encargado, vacio[1]) == 0){
			cout<<"\nERROR: No puede dejar este campo vacío." << endl;
		}else{
			repetir = false;
		}
	}while(repetir);
	
	do{
		repetir = true;
		cout << "\nSeleccione el pais donde estará ubicada la sucursal: " << endl;
			cout << "1. El Salvador" << endl;
			cout << "2. México" << endl;
			cout << "3. Panamá" << endl;
			cin >> opcPais;
			switch (opcPais){
				case 1:
					strcat(sucursalNew.pais, "El Salvador");
					break;

				case 2:
					strcat(sucursalNew.pais, "México");
					break;

				case 3:
					strcat(sucursalNew.pais, "Panamá");
					break;

				default:
					cout << "ERROR. Ha seleccionado una opción inválida"<<endl;
			}
		fflush(stdin);
	}while(opcPais < 1 || opcPais > 3);
		//}while(repetir = true);
	//}
	
	guardarSucursal(sucursalNew, tarea, posicion);
	
	/*cout << "Ingrese la descripcion: ";
	cin.getline(sucursalNew.descripcion, 100, '\n');
	
	cout << "Ingrese la descripcion: ";
	cin.getline(sucursalNew.descripcion, 100, '\n');
	
	cout << "Ingrese la descripcion: ";
	cin.getline(sucursalNew.descripcion, 100, '\n');
	
	cout << "Ingrese la descripcion: ";
	cin.getline(sucursalNew.descripcion, 100, '\n');*/
}

bool validarTel(char numTel[9]){
	//   INICIO VALIDACIÓN DE TELÉFONO   //
	char guion []= "-", num[1], auxiliar[1], auxiliar2;
	int contador = 0;
	fflush(stdin);
	
	
	for (int i = 0; i < 9; i++){
		for (int j = 0; j <= 9; j++){
			num[0] = j + 0x30;
			if (i == 4){
				if (numTel[i] == guion[0]){
					contador += 1;
					break;
				}else if(numTel[i] == num[0]){
					auxiliar[0] = numTel[i];
					//agreGuion = true;
					numTel[i] = guion[0];
					auxiliar2 = numTel[i+1];
					for (int m = 5; m < 9; m++){
						numTel[m] = auxiliar[0];
						auxiliar[0] = auxiliar2;
						auxiliar2 = numTel[m+1];
					}
					contador += 1;
					break;
				}
			}else{
				if (numTel[i] == num[0]){
					contador += 1;
					break;
				}
			}
		}
	}
	
	if (contador == 9){
		return false;
	}else{
		cout << "ERROR. Ha Ingresado un número de télefono inválido." << endl;
		return true;
	}
	
	//   FINAL VALIDACIÓN DE TELÉFONO   //
}

/*bool validarDatos(char datosIng[100], int numDato){
	switch (numDato){
		case 1:
			
			break;
			
		case 2:
			break;
			
		case 3:
			int contador = 0;
			char guion []= "-";
			char num[1], auxiliar[1], auxiliar2;
			for (int i = 0; i < 9; i++){
				for (int j = 0; j <= 9; j++){
					num[0] = j + 0x30;
					if (i == 4){
						if (datosIng[2][i] == guion[0]){
							contador += 1;
							break;
						}else if(datosIng[2][i] == num[0]){
							auxiliar[0] = datosIng[2][i];
							agreGuion = true;
							datosIng[2][i] = guion[0];
							auxiliar2 = datosIng[2][i+1];
							for (int m = 5; m < 9; m++){
								datosIng[2][m] = auxiliar[0];
								auxiliar[0] = auxiliar2;
								auxiliar2 = datosIng[2][m+1];
							}
							contador += 1;
							break;
						}
					}else{
						if (numTel[i] == num[0]){
							contador += 1;
							break;
						}
					}
				}
			}
			if (contador == 9){
				cout << "Ha Ingresado un número de télefono válido" << endl;
				return false;
			}else{
				cout << "ERROR. Ha Ingresado un número de télefono inválido";
				return true;
			}
			break;
			
		case 4:
			break;
			
		case 5:
			break;

		default:
			break;
	}
}*/

void guardarSucursal(Sucursal sucursalCreada, char tareaSel[15], int posicion){
	char tarea[15] = "modificar";
	ofstream sucursalSave;
	
	if (sucursalSave.fail())
		cout << "Hubo error al abrir el archivo" << endl;
		
	if (strcmp(tareaSel, tarea) == 0){
		sucursalSave.open("archivos/sucursales.dat", ios::binary);
		sucursalSave.seekp(sizeof(Sucursal)*posicion);
		cout << "NUEVOS CAMPOS" << endl;
		cout << "Descripción: " << sucursalCreada.descripcion << endl;
		cout << "Dirección: " << sucursalCreada.direccion << endl;
		cout << "Teléfono: " << sucursalCreada.telefono << endl;
		cout << "Encargado: " << sucursalCreada.encargado << endl;
		cout << "Pais: " << sucursalCreada.pais << endl;
	}else{
		sucursalSave.open("archivos/sucursales.dat", ios::binary | ios::app);
	}
	
	sucursalSave.write((char *)&sucursalCreada, sizeof(Sucursal));
	
	cout << "\nSUCURSAL GUARDADA CON ÉXITO";
	
	sucursalSave.close();
}

void mostrar(char idIng[5], char mostrarTipo[25], char areaSel[25]){
	int cantidadMax, contador;
	char areas[3][25] = {"Sucursales", "Proveedores", "Articulos"}, mostrarTipos[2][25] = {"especifico", "todo"};
	
	if (strcmp(areaSel, areas[0]) == 0){
		Sucursal sucursalMostrar;
		
		cantidadMax = correlativo(areas[0]);
		
		if(strcmp(mostrarTipo, mostrarTipos[0]) == 0){
			ifstream sucursalView;
			sucursalView.open("archivos/sucursales.dat", ios::binary);
			for (int i = 0; i < cantidadMax; i++){
				
				if (sucursalView.fail()){
					cout << "Hubo error al abrir el archivo";
				}
				
				sucursalView.seekg(sizeof(Sucursal)*i);
				sucursalView.read((char *)&sucursalMostrar, sizeof(Sucursal));
				
				if (strcmp(sucursalMostrar.id, idIng) == 0){
					sucursalView.close();
					
					cout << "\nId de la sucursal: " << sucursalMostrar.id << endl;
					cout << "Descripcion de la sucursal: " << sucursalMostrar.descripcion << endl;
					cout << "Dirección de la sucursal: " << sucursalMostrar.direccion << endl;
					cout << "Teléfono de la sucursal: " << sucursalMostrar.telefono << endl;
					cout << "Encargardo de la sucursal: " << sucursalMostrar.encargado << endl;
					cout << "País de la sucursal: " << sucursalMostrar.pais << endl;
					cout << "\n";
					break;
				}
			}
		}else if(strcmp(mostrarTipo, mostrarTipos[1]) == 0){
			int i = 0;
			cout << cantidadMax;
			for (int i = 0; i < cantidadMax; i++){
				ifstream sucursalView;
				
				sucursalView.open("archivos/sucursales.dat", ios::binary);
				
				if (sucursalView.fail()){
					cout << "Hubo error al abrir el archivo";
				}
				
				sucursalView.seekg(sizeof(Sucursal)*i);
				//sucursalView.seekg(0);
				sucursalView.read((char *)&sucursalMostrar, sizeof(Sucursal));
				
				sucursalView.close();
				
				cout << "El id de la sucursal: " << sucursalMostrar.id << endl;
				cout << "El descripcion de la sucursal: " << sucursalMostrar.descripcion << endl;
				cout << "El dirección de la sucursal: " << sucursalMostrar.direccion << endl;
				cout << "El teléfono de la sucursal: " << sucursalMostrar.telefono << endl;
				cout << "El encargardo de la sucursal: " << sucursalMostrar.encargado << endl;
				cout << "El pais de la sucursal: " << sucursalMostrar.pais << endl;
				cout << "\n";
				i += 1;
			}
		}
	}else if(strcmp(areaSel, areas[1]) == 0){
		Proveedores proveedorMostrar;
		
		cantidadMax = crearCorrelativo(areas[1]);
		
		if (strcmp(mostrarTipo, mostrarTipos[0]) == 0){
			ifstream proveedorView;
			proveedorView.open("archivos/proveedores.dat", ios::binary);
			for (int i = 0; i < cantidadMax; i++){
				
				if (proveedorView.fail()){
					cout << "Hubo error al abrir el archivo";
				}
				
				proveedorView.seekg(sizeof(Proveedores)*i);
				proveedorView.read((char *)&proveedorMostrar, sizeof(Proveedores));
				
				if (strcmp(proveedorMostrar.id, idIng)){
					proveedorView.close();
					
					cout << "Id del proveedor: " << proveedorMostrar.id << endl;
					cout << "Nombre del proveedor: " << proveedorMostrar.nombre << endl;
					cout << "Apellido del proveedor: " << proveedorMostrar.apellido << endl;
					cout << "Identificación del proveedor: " << proveedorMostrar.identificacion << endl;
					cout << "Tipo de identificación: " << proveedorMostrar.tipoIdentificacion << endl;
					cout << "Teléfono del proveedor: " << proveedorMostrar.telefono << endl;
					cout << "Email del proveedor: " << proveedorMostrar.email << endl;
					cout << "Direccion del proveedor: " << proveedorMostrar.direccion << endl;
					cout << "\n";
				}
			}
		}else{
			for (int i = 0; i < cantidadMax; i++){
				ifstream proveedorView;
				
				proveedorView.open("archivos/proveedores.dat", ios::binary);
				
				if (proveedorView.fail()){
					cout << "Hubo error al abrir el archivo";
				}
				
				proveedorView.seekg(sizeof(Proveedores)*i);
				//sucursalView.seekg(0);
				proveedorView.read((char *)&proveedorMostrar, sizeof(Proveedores));
				
				if (strcmp(proveedorMostrar.id, idIng) == 0){
					proveedorView.close();
					
					cout << "Id del proveedor: " << proveedorMostrar.id << endl;
					cout << "Nombre del proveedor: " << proveedorMostrar.nombre << endl;
					cout << "Apellido del proveedor: " << proveedorMostrar.apellido << endl;
					cout << "Identificación del proveedor: " << proveedorMostrar.identificacion << endl;
					cout << "Tipo de identificación: " << proveedorMostrar.tipoIdentificacion << endl;
					cout << "Teléfono del proveedor: " << proveedorMostrar.telefono << endl;
					cout << "Email del proveedor: " << proveedorMostrar.email << endl;
					cout << "Direccion del proveedor: " << proveedorMostrar.direccion << endl;
					cout << "\n";
				}
			}
		}
	}else if(strcmp(areaSel, areas[2]) == 0){
		Articulos articuloMostrar;
		
		cantidadMax = crearCorrelativo(areas[2]);
		
		if (strcmp(mostrarTipo, mostrarTipos[0]) == 0){
			ifstream articuloView;
			articuloView.open("archivos/articulos.dat", ios::binary);
			for (int i = 0; i < cantidadMax; i++){
				
				if (articuloView.fail()){
					cout << "Hubo error al abrir el archivo";
				}
				
				articuloView.seekg(sizeof(Articulos)*i);
				//sucursalView.seekg(0);
				articuloView.read((char *)&articuloMostrar, sizeof(Articulos));
				
				if (strcmp(articuloMostrar.id, idIng) == 0){
					articuloView.close();
					
					cout << "Id del articulo: " << articuloMostrar.id << endl;
					cout << "Tipo de artículo: " << articuloMostrar.tipoArticulo << endl;
					cout << "Nombre del articulo: " << articuloMostrar.nombre << endl;
					cout << "Características del articulo: " << articuloMostrar.caracteristicas << endl;
					cout << "Precio de venta del articulo: " << articuloMostrar.precioVenta << endl;
					cout << "Costo del articulo: " << articuloMostrar.costo << endl;
					cout << "Id del proveedor: " << articuloMostrar.idProveedor << endl;
					cout << "\n";
				}
			}
		}else{
			for (int i = 0; i < cantidadMax; i++){
				ifstream articuloView;
				
				articuloView.open("archivos/articulos.dat", ios::binary);
				
				if (articuloView.fail()){
					cout << "Hubo error al abrir el archivo";
				}
				
				articuloView.seekg(sizeof(Articulos)*i);
				//sucursalView.seekg(0);
				articuloView.read((char *)&articuloMostrar, sizeof(Articulos));
				
				articuloView.close();
				
				cout << "Id del articulo: " << articuloMostrar.id << endl;
				cout << "Tipo de artículo: " << articuloMostrar.tipoArticulo << endl;
				cout << "Nombre del articulo: " << articuloMostrar.nombre << endl;
				cout << "Características del articulo: " << articuloMostrar.caracteristicas << endl;
				cout << "Precio de venta del articulo: " << articuloMostrar.precioVenta << endl;
				cout << "Costo del articulo: " << articuloMostrar.costo << endl;
				cout << "Id del proveedor: " << articuloMostrar.idProveedor << endl;
				cout << "\n";
			}
		}
	}
}

int lastId(){
	int num;
	
	ifstream id;
	
	id.open("archivos/contsucursales.dat");
	id.seekg(0);
	id.read((char *)&num, sizeof(int));
	id.close();
	return num;
}

bool validarId(char id[5], char areaSel[25]){
	char areas[3][25] = {"Sucursales", "Proveedores", "Articulos"};
	int cantidad = lastId();
	
	ifstream valiId;
	
	if (strcmp(areaSel, areas[0]) == 0){
		Sucursal sucursalUsar;
		valiId.open("archivos/contsucursales.dat", ios::binary);
		valiId.read((char *)&cantidad, sizeof(int));
		valiId.close();
		for	(int i = 0; i < cantidad; i++){
			valiId.open("archivos/sucursales.dat", ios::binary);
			valiId.seekg(sizeof(Sucursal)*i);
			valiId.read((char *)&sucursalUsar, sizeof(Sucursal));
			valiId.close();
			if (strcmp(id, sucursalUsar.id) == 0){
				return false;
			}
		}
		return true;
	}else if (strcmp(areaSel, areas[1]) == 0){
		Proveedores proveedorUsar;
		valiId.open("archivos/contsucursales.dat", ios::binary);
		valiId.read((char *)&cantidad, sizeof(int));
		valiId.close();
		for	(int i = 0; i < cantidad; i++){
			valiId.open("archivos/proveedores.dat", ios::binary);
			valiId.seekg(sizeof(Proveedores)*i);
			valiId.read((char *)&proveedorUsar, sizeof(Proveedores));
			valiId.close();
			if (strcmp(id, proveedorUsar.id) == 0){
				return false;
			}
		}
		return true;
	}else if (strcmp(areaSel, areas[2]) == 0){
		Articulos articuloUsar;
		valiId.open("archivos/contarticulos.dat", ios::binary);
		valiId.read((char *)&cantidad, sizeof(int));
		valiId.close();
		for	(int i = 0; i < cantidad; i++){
			valiId.open("archivos/sucursales.dat", ios::binary);
			valiId.seekg(sizeof(Articulos)*i);
			valiId.read((char *)&articuloUsar, sizeof(Articulos));
			valiId.close();
			if (strcmp(id, articuloUsar.id) == 0){
				return false;
			}
		}
		return true;
	}
}

void modificar(char idIng[5], char areaSel[25], int opcionSel){
	int cantidad = lastId(), opcion, posicion;
	char areas[3][25] = {"Sucursales", "Proveedores", "Articulos"}, paises[3][15] = {"El Salvador", "México", "Panamá"};
	char tarea[15] = "modificar";
	Sucursal sucursalModificar;
	cin.ignore();
	fstream modificar;
	fflush(stdin);
	
	cout << "Ha ingresado a modificar" << endl;
	
	if (strcmp(areaSel, areas[0]) == 0){
		modificar.open("archivos/sucursales.dat", ios::out | ios::in | ios::binary);
		for (int i = 0; i < cantidad; i++){
			modificar.seekg(sizeof(Sucursal)*i);
			modificar.read((char *)&sucursalModificar, sizeof(Sucursal));
			if (strcmp(idIng,sucursalModificar.id) == 0){
				posicion = i;
				break;
			}
		}
		
		switch (opcionSel){
			case 1:
				cout << "\nIngrese la nueva descripción: " << endl;
				cin.getline(sucursalModificar.descripcion, 100, '\n');
				cout << endl;
			break;
			
			case 2:
				cout << "\nIngrese la nueva dirección: " << endl;
				cin.getline(sucursalModificar.direccion, 100, '\n');
				cout << endl;
			break;
			
			case 3:
				cout << "\nIngrese el nuevo número de teléfono: " << endl;
				cin.getline(sucursalModificar.telefono, 100, '\n');
				cout << endl;
			break;
			
			case 4:
				cout << "\nIngrese el nombre del nuevo encargado: " << endl;
				cin.getline(sucursalModificar.encargado, 100, '\n');
				cout << endl;
			break;
			
			case 5:
				do{
					cout << "\nSeleccione el nuevo país: " << endl;
					cout << "1. El Salvador" << endl;
					cout << "2. México" << endl;
					cout << "3. Panamá" << endl;
					cin >> opcion;
					switch(opcion){
						case 1:
							strcpy(sucursalModificar.pais, paises[0]);
						break;
						
						case 2:
							strcpy(sucursalModificar.pais, paises[1]);
						break;
						
						case 3:
							strcpy(sucursalModificar.pais, paises[2]);
						break;
						
						default:
							cout << "ERROR. HA INGRESADO UNA OPCIÓN INVÁLIDA." << endl;
						break;
					}
				}while(opcion < 1 || opcion > 3);
			break;
		}
		fflush(stdin);
		if(modificar.is_open()){
			modificar.seekp(cantidad*sizeof(Sucursal));
			modificar.write((char*)&sucursalModificar, sizeof(Sucursal));
			modificar.close();
		}
	} else if(strcmp(areaSel, areas[1]) == 0){
		switch (opcionSel){
			case 1:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 2:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 3:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 4:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 5:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 6:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 7:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 8:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
		}
	} else if(strcmp(areaSel, areas[2]) == 0){
		switch (opcionSel){
			case 1:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 2:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 3:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 4:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 5:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 6:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
			
			case 7:
				cout << "\nHa seleccionado modificar nombre" << endl;
			break;
		}
	}
}

int main(){
	setlocale(LC_ALL, "spanish");
	char idSucursal[5] = "", areaSel[25] = "Sucursales", mostrarTipo[2][25] = {"especifico", "todo"};
	int opcionP, opcion;
	fflush(stdin);
	Sucursal sucursalUsar;
	do{
		bool repetir = true, regresar = false;
		cout << "1. Registrar sucursal." << endl;
		cout << "2. Ver registro de sucursales." << endl;
		cout << "3. Regresar al menú." << endl;
		cout << "\nSeleccione la opción que prefiera: ";
		cin >> opcionP; cout << endl;
		fflush(stdin);
		switch (opcionP){
			case 1:
				crearSucursal();
			break;
				/**/
			case 2:
				do{
					cout << "\n¿Qué desea ver?" << endl;
					cout << "1. Registros de una sucursal específica." << endl;
					cout << "2. Registros de todas las sucursales." << endl;
					cout << "3. Regresar al menú anterior." << endl;
					cout << "Seleccione la opción que prefiera: ";
					cin >> opcion; cout << endl;
					if(opcion >= 1 && opcion <= 3){
						switch (opcion){
							case 1:
								do{
									cout << "Ingrese el Id de la sucursal: " << endl;
									cin >> idSucursal;
									repetir = validarId(idSucursal, areaSel);
									if (repetir){
										cout << "ERROR. Sucursal no encontrada" << endl;
										do{
											cout << "\n¿Qué desesa hacer?" << endl;
											cout << "1. Buscar con otro id." << endl;
											cout << "2. Cancelar (lo llevará al menú anterior)." << endl;
											cin >> opcion; cout << endl;
											if (opcion < 1 || opcion > 2){
												cout << "ERROR. HA INGRESADO UNA OPCIÓN INVÁLIDA" << endl;
											}else if(opcion == 1){
												cout << endl;
												regresar = true;
												system("cls");
											}else{
												system("cls");
												main();
											}
										}while(opcion < 1 || opcion > 2 || regresar == false);
									}
								}while(repetir);
								cout << "Entramos case 1" << endl;
								mostrar(idSucursal, mostrarTipo[0], areaSel);
							break;
							
							case 2:
								cout << "Entramos case 2" << endl;
								mostrar(idSucursal, mostrarTipo[1], areaSel);
							break;
							
							case 3:
								cout << "Entramos case 3" << endl;
								system("cls");
								main();
							break;
							
							default:
								cout << "Entramos default" << endl;
							break;
						}
					}
				}while(opcion < 1 || opcion > 3 && opcion != 3);
			break;
			
			case 3:
				system("cls");
			break;
				/**/
			default:
				cout << "ERROR. HA INGRESADO UNA OPCIÓN INVÁLIDA.\n" << endl;
			break;
		}
	}while(opcionP < 1 || opcionP > 4 && opcionP != 4);
}
