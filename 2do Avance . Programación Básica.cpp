#include <iostream>
#include <clocale>
#include <string>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <wchar.h>
#include <math.h>

using namespace std;

struct id //Estructura
{
	int numitem, agecls; //Número de item y Clasificación por Edad
	float fltprice, tax, ttlprice; //Precio Bruto, Impuesto y Precio Neto
	char itemname[40], gnre[40], consl[40]; // Nombre del item, Género y Consola
};
id articulo[3]; //Declaración del arreglo con tres casillas de almacenamiento

int main() { //Función Principal
	int opc, empty = 0; //Declaracion de la variable OPC para el switch | variable empty que se utilizará para revisar si no se han ingresado datos a la hora de imprimir
	printf("\n\n--------------------------------------| Menu de Opciones |--------------------------------------"); //Elemento decorativo
	printf("\n\n\t1.Dar Articulo de Alta\n\t2.Modificar Informacion de Articulo Existente\n\t3.Dar Articulo de Baja\n\t4.Lista de Articulos en Stock\n\t5.Limpiar Pantalla\n\t6.Salir");//Menu de opciones
	printf("\n\n\t\tIngresar Opcion A Ejecutar (valor numerico entero):"); //Instrucciones a usuario
	scanf_s("%i", &opc); //Lectura de datos de que opion a ejecutar del menu de opciones
	switch (opc) { //Inicio de switch
	case 1:
			printf("\n------------------------------------| Dar Articulo de Alta |------------------------------------"); //Elemento Decorativo
			for (int i = 0; i < 3; i++) { //Inicio de ciclo for para ingresar datos
				printf("\n\n\t* Ingrese el numero de item: item#"); //Instrucciones a usuario
				scanf_s("%i", &articulo[i].numitem); //Letura de datos
				printf("\n\t* Ingrese el titulo del item: "); //Instrucciones a usuario
				cin.ignore(); //Ignorar el \n de la anterior lectura ya que gets no ignora los separadores
				gets_s(articulo[i].itemname); //Lectura de datos
				printf("\n\t* Ingrese el genero del item: "); //Instrucciones a usuario
				gets_s(articulo[i].gnre);//Lectura de datos
				printf("\n\t* CLasificaciones por edad:\n\t1.eC (Infancia Temprana)\n\t2.E (Publico General)\n\t3.E 10+ (Arriba de 10)\n\t4.T (Adolecentes)\n\t5.M (Arriba de 17)\n\t6.A +18 (Adultos)\n\t7.RP (Clasificacion Pendiente)"); //Impresión de tipos de clasificación
				printf("\n\n\t* Ingrese la clasificacion del item (valor numerico entero): "); //Instrucciones a usuario
				scanf_s("%i", &articulo[i].agecls);//Lectura de datos, El usuario ingresa un numero que corresponde a la opción dentro del menú
				printf("\n\t* Ingrese la consola del item: "); //Instrucciones a usuario
				cin.ignore(); //Ignorar el \n de la anterior lectura ya que gets no ignora los separadores
				gets_s(articulo[i].consl); //Lectura de datos
				printf("\n\t* Ingrese el precio del item: $"); //Instrucciones a usuario
				scanf_s("%f", &articulo[i].fltprice); //Lectura de datos
				articulo[i].tax = articulo[i].fltprice * .16; //Operaación para calcular el impuesto de 16%
				articulo[i].ttlprice = articulo[i].tax + articulo[i].fltprice; //Operación para calculalar el Precio Neto
				printf("\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--"); //Elemento deorativo
				printf("\n\tInformacion ingresada:\n\t\t* item#%i", articulo[i].numitem); printf("\n\t\t* titulo: %s", articulo[i].itemname); printf("\n\t\t* genero: %s", articulo[i].gnre); printf("\n\t\t* clasificacion de edad: "); //Impresión de datos
				if (articulo[i].agecls == 1) { //Si el usuario ingresó 1 en la clasificación por edad, entra en este condiional e ignora los demas
					printf("eC (Infancia Temprana)"); //Se imprime lo que correspende a la opción 1
				}
				if (articulo[i].agecls == 2) { //Si el usuario ingresó 2 en la clasificación por edad, entra en este condiional e ignora los demas
					printf("E (Publico General)");//Se imprime lo que correspende a la opción 2
				}
				if (articulo[i].agecls == 3) { //Si el usuario ingresó 3 en la clasificación por edad, entra en este condiional e ignora los demas
					printf("E 10+ (Arriba de 10)"); //Se imprime lo que correspende a la opción 3
				}
				if (articulo[i].agecls == 4) { //Si el usuario ingresó 4 en la clasificación por edad, entra en este condiional e ignora los demas
					printf("T (Adolecentes)"); //Se imprime lo que correspende a la opción 4
				}
				if (articulo[i].agecls == 5) { //Si el usuario ingresó 5 en la clasificación por edad, entra en este condiional e ignora los demas
					printf("M (Arriba de 17)"); //Se imprime lo que correspende a la opción 5
				}
				if (articulo[i].agecls == 6) { //Si el usuario ingresó 6 en la clasificación por edad, entra en este condiional e ignora los demas
					printf("A +18 (Adultos)"); //Se imprime lo que correspende a la opción 6
				}
				if (articulo[i].agecls == 7) { //Si el usuario ingresó 7 en la clasificación por edad, entra en este condiional e ignora los demas
					printf("RP (Clasificacion Pendiente)"); //Se imprime lo que correspende a la opción 7
				}
				printf("\n\t\t* consola: %s", articulo[i].consl); //Impresión de datos
				if (articulo[i].fltprice == 0) { //Si el usuario ingresó un precio de 0 entra en este condiional e ignora lo demas
					printf("\n\t\t* precio neto: gratis"); //Se impreme gratis ya que como el precio es 0, no hay impuesto ni precio neto bruto
				}
				else { //Si el usuario ingresó un precio positivo entra en este condiional e ignora lo demas
					printf("\n\t\t* precio neto: $%f", articulo[i].ttlprice); printf("\n\t\t\t* precio bruto: $%f", articulo[i].fltprice); printf("\n\t\t\t* impuesto(16%%): $%f", articulo[i].tax); //Impresión de datos
				}
				printf("\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--\n\n"); //Elemento decorativo
			} //Fin del ciclo for para ingresar datos
		return(main()); //Regresa al menú
		break;
	case 2:
		printf("\n-------------------------| Modificar Informacion de Articulo Existente |------------------------"); //Elemento decorativo
		printf("\n\n\tOpcion No Disponible Por El Momento\n"); //Impresión de aviso
		return(main()); //Regresa al menú
		break;
	case 3:
		printf("\n------------------------------------| Dar Articulo de Baja |------------------------------------"); //Elemento decorativo
		printf("\n\n\tOpcion No Disponible Por El Momento\n"); //Impresión de aviso
		return(main()); //Regresa al menú
		break;
	case 4:
		printf("\n--------------------------------| Lista de Articulos en Stock |---------------------------------\n"); //Elemento decorativo
		for (int i = 0; i < 4; i++) { //Inicio de ciclo for para observar todos los datos guardados
			if (articulo[i].numitem != 0) { // Condicional para revisar que la casilla de almacenamiento está ocupada
				printf("\n\t\t* item#%i", articulo[i].numitem); printf("\n\t\t* titulo: %s", articulo[i].itemname); printf("\n\t\t* genero: %s", articulo[i].gnre); printf("\n\t\t* clasificacion de edad: "); //Impresión de datos
				if (articulo[i].agecls == 1) { //Si el item tiene un valor de 1 en la clasificación por edad, entra en este condiional e ignora los demas
					printf("eC (Infancia Temprana)"); //Se imprime lo que correspende a la opción 1
				}
				if (articulo[i].agecls == 2) { //Si el item tiene un valor de 2 en la clasificación por edad, entra en este condiional e ignora los demas
					printf("E (Publico General)");//Se imprime lo que correspende a la opción 2
				}
				if (articulo[i].agecls == 3) { //Si el item tiene un valor de 3 en la clasificación por edad, entra en este condiional e ignora los demas
					printf("E 10+ (Arriba de 10)"); //Se imprime lo que correspende a la opción 3
				}
				if (articulo[i].agecls == 4) { //Si el item tiene un valor de 4 en la clasificación por edad, entra en este condiional e ignora los demas
					printf("T (Adolecentes)"); //Se imprime lo que correspende a la opción 4
				}
				if (articulo[i].agecls == 5) { //Si el item tiene un valor de 5 en la clasificación por edad, entra en este condiional e ignora los demas
					printf("M (Arriba de 17)"); //Se imprime lo que correspende a la opción 5
				}
				if (articulo[i].agecls == 6) { //Si el item tiene un valor de 6 en la clasificación por edad, entra en este condiional e ignora los demas
					printf("A +18 (Adultos)"); //Se imprime lo que correspende a la opción 6
				}
				if (articulo[i].agecls == 7) { //Si el item tiene un valor de 7 en la clasificación por edad, entra en este condiional e ignora los demas
					printf("RP (Clasificacion Pendiente)"); //Se imprime lo que correspende a la opción 7
				}
				printf("\n\t\t* consola: %s", articulo[i].consl); //Impresión de datos
				if (articulo[i].fltprice == 0) { //Si el item tiene un precio de 0 entra en este condiional e ignora lo demas
					printf("\n\t\t* precio neto: gratis"); //Se impreme gratis ya que como el precio es 0, no hay impuesto ni precio neto bruto
				}
				else { //Si el item tiene un precio positivo entra en este condicional e ignora lo demas
					printf("\n\t\t* precio neto: $%f", articulo[i].ttlprice); printf("\n\t\t\t* precio bruto: $%f", articulo[i].fltprice); printf("\n\t\t\t* impuesto(16%%): $%f", articulo[i].tax); //Impresión de datos
				}
				if (i < 2) { //Se cuenta cuantes veces se ha repetido el ciclo, para que cuando el ciclo este por terminar no se imprima el saparador
					printf("\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--\n"); //Elemento decorativo
				}
			}
			else { //Si la casilla de almacenamiento está vacia entra aquí
				empty++; // Y la varaible empty acumula valor
			}
			if (empty == 4) { //Si al final del ciclo, la variable empty aumuló un valor de 4, eso significa que ninguna casilla estaba acupada
				printf("\n\n\t//Error: No Hay Articulos Registrados//\n\n"); //Se imprime este mensaje
			}
		} //Fin del ciclo for para observar todos los datos guardados
		return(main()); //Regresa al menú
		break;
	case 5:
		printf("\n\t*limpiando pantalla*"); //Impresión de aviso
		system("cls"); //Limpiar la pantalla
		return(main()); //Regresa al menú
		break;
	case 6:
		printf("\n\t*saliendo*"); //Impresión de aviso
		exit(1); //Cerrar el programa
		break;
	default:
		printf("\n\t//Error: Opcion No Existente//\n\n"); //Impresión de aviso
		return(main()); //Regresa al menú
		break;
	}
}