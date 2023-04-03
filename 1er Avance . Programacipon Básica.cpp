#include <iostream>
#include <clocale>

using namespace std;

int main() {
	int opc;
	cout << "\n--------------------------------------| Menu de Opciones |--------------------------------------";
	cout << "\n\n\t1.Dar Articulo de Alta\n\t2.Modificar Informacion de Articulo Existente\n\t3.Dar Articulo de Baja\n\t4.Lista de Articulos en Stock\n\t5.Limpiar Pantalla\n\t6.Salir";
	cout << "\n\n\t\tIngresar Opcion A Ejecutar (valor numerico entero):";
	cin >> opc;
	switch (opc) {
		case 1:
			int numitem, agecls, opc1;
			float fltprice, ttlprice, tax;
			char itemname[40], gnre[40], consl[40];
			cout << "\n------------------------------------| Dar Articulo de Alta |------------------------------------";
			cout << "\n\n\t* Ingrese el numero de item: item#";
			cin >> numitem;
			cout << "\n\t* Ingrese el titulo del item (remplazar espacios por un -): ";
			cin >> itemname;
			cout << "\n\t* Ingrese el genero del item (remplazar espacios por un -): ";
			cin >> gnre;
			cout << "\n\t* CLasificaciones por edad:\n\t1.eC (Infancia Temprana)\n\t2.E (Publico General)\n\t3.E 10+ (Arriba de 10)\n\t4.T (Adolecentes)\n\t5.M (Arriba de 17)\n\t6.A +18 (Adultos)\n\t7.RP (Clasificacion Pendiente)";
			cout<<"\n\n\tIngrese la clasificacion del item (valor numerico entero): ";
			cin >> agecls;
			cout << "\n\t* Ingrese la consola del item (remplazar espacios por un -): ";
			cin >> consl;
			cout << "\n\t* Ingrese el precio del item: $";
			cin >> fltprice;
			tax = fltprice * .16;
			ttlprice = tax + fltprice;
			cout<<"\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--";
			cout << "\n\tInformacion ingresada:\n\t\t* item#"<<numitem<<"\n\t\t* titulo: "<<itemname<<"\n\t\t* genero: "<<gnre<<"\n\t\t* clasificacion de edad: ";
			if (agecls == 1) {
				cout << "eC (Infancia Temprana)";
			}
			if (agecls == 2) {
				cout << "E (Publico General)";
			}
			if (agecls == 3) {
				cout << "E 10+ (Arriba de 10)";
			}
			if (agecls == 4) {
				cout << "T (Adolecentes)";
			}
			if (agecls == 5) {
				cout << "M (Arriba de 17)";
			}
			if (agecls == 6) {
				cout << "A +18 (Adultos)";
			}
			if (agecls == 7) {
				cout << "RP (Clasificacion Pendiente)";
			}
			cout << "\n\t\t* consola: " << consl << "\n\t\t* precio neto: $" << ttlprice << "\n\t\t\t* precio bruto: $" << fltprice << "\n\t\t\t* impuesto(16%): $"<<tax;
			cout << "\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--\n\n";
			return(main());
			break;
		case 2:
			(cout << "\n-------------------------| Modificar Informacion de Articulo Existente |------------------------");
			cout << "\n\n\tOpcion No Disponible Por El Momento\n";
			return(main());
			break;
		case 3:
			(cout << "\n------------------------------------| Dar Articulo de Baja |------------------------------------");
			cout << "\n\n\tOpcion No Disponible Por El Momento\n";
			return(main());
			break;
		case 4:
			(cout << "\n--------------------------------| Lista de Articulos en Stock |---------------------------------");
			cout << "\n\n\tOpcion No Disponible Por El Momento\n";
			return(main());
			break;
		case 5:
			(cout << "\n\t*limpiando pantalla*");
			system("cls");
			return(main());
			break;
		case 6:
			(cout << "\n\t*saliendo*");
			exit(1);
			break;
		default:
			cout << "\n\t//Error: Opcion No Existente//\n\n";
			return(main());
			break;
	}
}