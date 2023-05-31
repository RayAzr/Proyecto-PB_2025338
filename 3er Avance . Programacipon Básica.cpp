#include <iostream>//LIBRERIAS
#include <clocale>
#include <string>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <wchar.h>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>

using namespace std;//ESPACIO DE TRABAJO

struct id//INCIO DE ESTRUCTURA
{
	int numitem, agecls, status;
	float fltprice, tax, ttlprice;
	char itemname[40], gnre[40], consl[40];
};
id articulo[21];//ARREGLO DE 21 ELEMENTOS PARA GUARDAR LOS DATOS DE LOS ELEMENTOS MIENTRAS EL PROGRAMA EST� ACTIVO

void alta(); //DECLARACI�N DE FUNCIONES
void modificar();
void lista();
void baja();
void salir();

int main() { //INICIO DE FUNCI�N MADRE
	int opc; ; //DECLARACI�N DE VARIABLE QUE SE UTILIZA PARA GUARDAR LA OPCI�N ELEJIDA
	float v = 1, valtemp, ent, j;
	printf("\n\n--------------------------------------| Men%c de Opciones |--------------------------------------", 163); //T�TULO Y SEPARADOR DEL MODULO "MEN�"
	printf("\n\n\t1.Dar Art%cculo de Alta\n\t2.Modificar Informaci%cn de Art%cculo Existente\n\t3.Dar Art%cculo de Baja\n\t4.Lista de Art%cculos en Stock\n\t5.Limpiar Pantalla\n\t6.Salir", 161, 162, 161, 161, 161); //MUESTRA DE OPCIONES
	while (v != 0) {//INICIO DE CICLO VALIDACI�N
		printf("\n\n\t\tIngresar Opci%cn A Ejecutar (valor n%cmerico entero):", 162, 163); //INSTRUCCI�N AL USUARIO
		scanf_s("%f", &valtemp);//LECTURA DE DATOS EN UNA VARIABLE TEMPORAL
		v = modf(valtemp, &ent);//CALCULACI�N DE LA VALIDACI�N DONDE SE BUSCA SI ES UN NUMERO ENTERO(SI V=0, EL NUMERO ES ENTERO)
		if (v != 0) {//SI EL NUMERO ES FLOTANTE
			printf("\n\n\t//Error: Debe ser entero//\n");//SE IMPRIME UN MENSAJE MARCANDO EL ERROR
		}
	}//FIN DEL CICLO VALIDACI�N
	opc = valtemp;//SE PASAN LOS DATOS DE LA VARIABLE TEMPORAL A LA VARIABLE OPC
	switch (opc) { //INICIO DE ESTRUCCTURA DE SELECCI�N
		case 1:
			alta();//LLAMADO A FUNCI�N
			return(main());
			break;
		case 2:
			modificar();//LAMADO A FUNCI�N
			return(main());
			break;
		case 3:
			baja();//LAMADO A FUNCI�N
			return(main());
			break;
		case 4:
			lista();//LAMADO A FUNCI�N
			return(main());
			break;
		case 5:
			printf("\n\t*limpiando pantalla*");//MENSAJE PARA INDICARLE AL USUARIO QUE LA ACCI�N EST� EN PROCESO
			system("cls");//LIMPIAR PANTALLA
			return(main());
			break;
		case 6:
			salir();//LAMADO A FUNCI�N
			break;
		default:
			printf("\n\n\t//Error: Opci%cn No Existente//\n", 162);//MENSAJE DE ERROR POR INGRESAR UNA OPCI�N FUERA DEL MENU
			return(main());
			break;
	}//FIN DE ESTRUCTURA DE SELECCI�N
}//FIN DE FUNCI�N MADRE

void alta() {//INICIO DE FUNCI�N PARA DAR DE ALTA
	float i = 1;//DELCARACI�N DE VARIABLE INICIADA EN 1 PARA INDICAR QUE SE EJECUTAR� EL PROCESO
	while (i == 1) {//INICIO DE CICLO DAR DE ALTA
		double tax, ttlprice;//DECLARACI�N DE VARIABLES
		float valtemp, v = 0, ent;
		int item = 0, cls, j;
		printf("\n------------------------------------| Dar Art%cculo de Alta |------------------------------------", 161);//SEPARADOR Y T�TULO DEL MODULO "dar de alta"
		do {//INICIO DEL CICLO VALIDACI�N
			printf("\n\n\t* Ingrese el n%cmero de item (valor num%crico entero): item#", 163, 130);//INTRUCCI�N AL USUARIO
			scanf_s("%f", &valtemp);//LECTURA DE DATOS EN UNA VARIABLE TEMPORAL PARA QUE NO SE GUARDE EN EL ARREGLO HASTA SER VALIDADO
			v = modf(valtemp, &ent);//CALCULACI�N DE LA VALIDACI�N DONDE SE BUSCA SI ES UN NUMERO ENTERO(SI V=0, EL NUMERO ES ENTERO)
			if (v != 0) {//SI EL NUMERO ES FLOTANTE...
				printf("\n\t\t//Error: Falla de Captura (el n%cmero debe ser entero)//", 163);//SE IMPRIME MENSAJE INDICANDO EL ERROR
			}
			else {//SI EL NUMERO ES ENTERO...
				if (valtemp < 1 || valtemp > 20) {//SE BUSCA SI EL N�MERO EST� FUERA DEL RANGO DE ESPACIOS DE GUARDADO
					printf("\n\t\t//Error: Opci%cn Fuera de Rango (debe ser mayor o igual a 1 y menor o igual a 20)//", 162);//SE IMPRIME MENSAJE INDICANDO EL ERROR
				}
				else {//SI EL N�MERO EST� DENTRO DEL RANGO...
					item = valtemp;//SE PASA DE LA VARIABLE TEMPORAL FLOTANTE A UNA VARIABLE TEMPORAL ENTERA
					if (articulo[item].status == 1 || articulo[item].status == 2) {//SI EL N�MERO INDICA UN ESPACIO QUE YA EST� OCUPADO...
						printf("\n\t\t//Aviso: Art%cculo Ya Existente//", 161);//SE IMPRIME MENSAJE INDICANDO EL ERROR
					}
				}
			}
		} while (articulo[item].status==1 || articulo[item].status==2 || valtemp == 0 || valtemp < 0 || v != 0 || valtemp > 20);//FIN DEL CILO VALIDACI�N DONDE SE REPETIR� SI EL NUMERO NO PAS� LA VALIDACI�N
		articulo[item].numitem = item;//SE PASAN LOS DATOS DE LA VARIABLE TEMPORAL A LA VARIABLE ITEM PARA SER GUARDADA EN EL ARREGLO YA QUE YA SE PAS� LA VALIDACI�N
		printf("\n\t* Ingrese el t%ctulo del item (texto): ", 161);//INSTRUCCI�N AL USUARIO
		cin.ignore();//IGNORAR EL ESPACIO DE LA ENTERIOR LECTURA YA QUE GETS NO IGNORA SEPARADORES
		gets_s(articulo[item].itemname);//LECTURA DE DATOS
		printf("\n\t* Ingrese el g%cnero del item (texto): ", 130);//INSTRUCCI�N AL USUARIO
		gets_s(articulo[item].gnre);//LECTURA DE DATOS
		printf("\n\t* CLasificaciones por edad:\n\t1.eC (Infancia Temprana)\n\t2.E (P%cblico General)\n\t3.E 10+ (Arriba de 10)\n\t4.T (Adolecentes)\n\t5.M (Arriba de 17)\n\t6.A +18 (Adultos)\n\t7.RP (Clasificacion Pendiente)", 163);//IMPRESI�N DE MEN� DE OPCIONES
		valtemp = 0; ent = 0; v = 0;//LIMPIEZA DE VARIABLES PARA REUTILIZAR
		do {//INICIO DEL CICLO VALIDACI�N
			printf("\n\n\t* Ingrese la clasificaci%cn del item (valor n%cmerico entero): ", 162, 163);//INSTRUCCI�N AL USUARIO
			scanf_s("%f", &valtemp);//LECTURA DE DATOS EN VARIABLE TEMPORAL
			v = modf(valtemp, &ent);//CALCULACI�N DE LA VALIDACI�N DONDE SE BUSCA SI ES UN NUMERO ENTERO(SI V=0, EL NUMERO ES ENTERO)
			if (v != 0) {//SI EL NUMERO ES FLOTANTE...
				printf("\n\t\t//Error: Falla de Captura (el n%cmero debe ser entero)//", 163);//SE IMPRIME UN MENSAJE DE ERROR POR SER FLOTANTE
			}
			else {//SI EL NUMERO ES ENTERO...
				if (valtemp <= 0 || valtemp > 7) {//SE REVISA SI CAE DENTRO DEL RANGO DE OPCIONES
					printf("\n\t\t//Error: Opci%cn No Existente//", 162);//SE IMPRIME UN MENSAJE INDICANDO QUE EL NUMERO EST� FUERA DE RANGO
				}
			}
		} while (valtemp < 1 || valtemp > 7 || valtemp <= 0 || v != 0);//FIN DE CICLO VALIDACI�N DONDE SE REPETIR� SI EL NUMERO NO PASO LAS VALIDACIONES
		articulo[item].agecls = valtemp;//SE PASAN LOS DATOS DE LA VARIABLE TEMPORAL A LA VARIABLE AGECLS PARA SER GUARDADA EN EL ARREGLO
		printf("\n\t* Ingrese la consola del item (texto): ");//INSTRUCCIONES AL USUARIO
		cin.ignore();//IGNORAR EL ESPACIO DE LA ENTERIOR LECTURA YA QUE GETS NO IGNORA SEPARADORES
		gets_s(articulo[item].consl);//LECTURA DE DATOS
		do {//INICIO DE CICLO VALIDACI�N
			valtemp = 0;//SE LIMPIAN LAS VARIABLES TEMPORALES
			printf("\n\t* Ingrese el precio del item (valor num%crico): $", 130);//INSTRUCCIONES AL USUARIO
			scanf_s("%f", &valtemp);//LECTURA DE DATOS EN VARIABLE TEMPORAL
			if (valtemp < 0) {//SI EL PRECIO ES NEGATIVO...
				printf("\n\t\t//Error: El Precio no puede ser menor a 0//\n");//SE LE INDICA AL USUARIO EL ERROR
			}
		} while (valtemp < 0);//FIN DEL CICLO VALIDACI�N DONDE SE REPETIR� SI EL PRECIO NO PAS� LAS VALIDACIONES
		articulo[item].fltprice = valtemp;
		tax = articulo[item].fltprice * .16;//CALCULACI�N DEL IMPUESTO
		articulo[item].tax = tax;//SE PASAN LOS DATOS DE LA VARIABLE TEMPORAL A LA VARIABLE TAX PARA SER GUARDADA EN EL ARREGLO
		ttlprice = articulo[item].tax + articulo[item].fltprice;//CALCULACI�N DEL PRECIO TOTAL
		articulo[item].ttlprice = ttlprice;//SE PASAN LOS DATOS DE LA VARIABLE TEMPORAL A LA VARIABLE TTLPRICE PARA SER GUARDADA EN EL ARREGLO
		articulo[item].status = 1;//SE CAMBIA EL VALOR DE STATUS A 1 PARA INDICAR QUE ESE ESPACIO DEL ARREGLO EST� OCUPADO
		printf("\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--");//SEPARADOR
		printf("\n\tInformaci%cn ingresada:\n\t\t* item#%i", 162, articulo[item].numitem); printf("\n\t\t* t%ctulo: %s", 161, articulo[item].itemname); printf("\n\t\t* g%cnero: %s", 130, articulo[item].gnre); printf("\n\t\t* clasificaci%cn de edad: ", 162);//SE IMPRIME LA INFORMACI�N REGISTRADA
		if (articulo[item].agecls == 1) {//CADENA DE CONDICIONALES PARA IMPRIMIR LA OPCI�N QUE EL USUARIO ECOJI�
			printf("eC (Infancia Temprana)");
		}
		if (articulo[item].agecls == 2) {
			printf("E (P%cblico General)", 163);
		}
		if (articulo[item].agecls == 3) {
			printf("E 10+ (Arriba de 10)");
		}
		if (articulo[item].agecls == 4) {
			printf("T (Adolecentes)");
		}
		if (articulo[item].agecls == 5) {
			printf("M (Arriba de 17)");
		}
		if (articulo[item].agecls == 6) {
			printf("A +18 (Adultos)");
		}
		if (articulo[item].agecls == 7) {
			printf("RP (Clasificaci%cn Pendiente)", 162);
		}
		printf("\n\t\t* consola: %s", articulo[item].consl);//IMPRESI�N DE INFORMACI�N REGISTRADA
		if (articulo[item].fltprice == 0) {//SI EL PRECIO ES 0...
			printf("\n\t\t* precio neto: gratis");//EN VEZ DE IMPRIMIR EL PRECIO 0 SE IMPRIME "GRATIS"
		}
		else {//SI EL PRECIO ES MAYOR A 0
			printf("\n\t\t* precio neto: $%f", articulo[item].ttlprice); printf("\n\t\t\t* precio bruto: $%f", articulo[item].fltprice); printf("\n\t\t\t* impuesto(16%%): $%f", articulo[item].tax); //SE IMPRIMEN LOS DATOS REGISTRADOS
		}
		printf("\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--\n\n"); //SEPARADOR
		printf("\t\tSi desea ingresar otro art%cculo, presione 1.\n\t\tSi desea terminar, presione cualquier otro n%cmero:", 161, 163);//INTRUCCIONES AL USUARIO
		scanf_s("%f", &i);//SI EL USUARIO INGRESA "1" SE CUMPLIR� LA CONDICI�N Y SE REINICIAR� EL PROCESO, SI SE ESCOJE CUALQUIER OTRO SE SALDR� DEL CICLO Y REGRESAR� A LA FUNCI�N MADRE
	}//FIN DEL CICLO DAR DE ALTA
}//FIN DE FUNCI�N PARA DAR DE ALTA

void modificar() {//INICIO DE LA FUNCI�N MODIFICAR
	int opc;//DECLARACI�N DE VARIABLES
	float i = 1;
	while(i==1){//INICIO DE CICLO MODIFICAR
		double tax, ttlprice;//DECLARACI�N DE VARIABLES
		float valtemp, v = 0, ent, j;
		int item = 0, cls;
		printf("\n-------------------------| Modificar Informaci%cn de Art%cculo Existente |------------------------\n", 162, 161);//SEPARADOR Y TITULO DEL MODULO MODIFICAR
		do {//INICIO DEL CICLO VALIDACI�N NUMERO DE ITEM
			printf("\n\n\t* Ingrese el #item del item que desea modificar (valor num%crico entero): ", 163, 130);//INTRUCCI�N AL USUARIO
			scanf_s("%f", &valtemp);//LECTURA DE DATOS EN UNA VARIABLE TEMPORAL
			v = modf(valtemp, &ent);//CALCULACI�N DE LA VALIDACI�N DONDE SE BUSCA SI ES UN NUMERO ENTERO(SI V=0, EL NUMERO ES ENTERO)
			if (v != 0) {//SI EL NUMERO ES FLOTANTE...
				printf("\n\t\t//Error: Falla de Captura (el n%cmero debe ser entero)//", 163);//SE IMPRIME MENSAJE INDICANDO EL ERROR
			}
			else {//SI EL NUMERO ES ENTERO...
				if (valtemp < 1 || valtemp > 20) {//SE BUSCA SI EL N�MERO EST� FUERA DEL RANGO DE ESPACIOS DE GUARDADO
					printf("\n\t\t//Error: Opci%cn Fuera de Rango (debe ser mayor o igual a 1 y menor o igual a 20)//", 162);//SE IMPRIME MENSAJE INDICANDO EL ERROR
				}
				else {//SI EL N�MERO EST� DENTRO DEL RANGO...
					item = valtemp;//SE PASA DE LA VARIABLE TEMPORAL FLOTANTE A UNA VARIABLE TEMPORAL ENTERA
					if (articulo[item].status == 0) {//SI EL N�MERO INDICA UN ESPACIO VACIO
						printf("\n\t\t//Aviso: Art%cculo Inexistente//", 161);//SE IMPRIME MENSAJE INDICANDO EL ERROR
						main();//SE REGRESA AL MENU 
					}
					if (articulo[item].status == 2) {//SI EL NUMERO INDICA QUE EL ARTICUO ESTA DADO DE BAJA...
						printf("\n\t\t//Aviso: Art%cculo Dado de Baja//", 161);//SE LE AVISA AL USUARIO
						printf("\n\t\tDesea reactivar el art%cculo? (Presione 1 para 'si' y cualquier otro n%cmero para 'no'): ", 161, 163);//Y SE LE DA LA OPCI�N DE REACTIVARLO
						scanf_s("%f", &j);//LECTURA DE DATOS
						if (j == 1) {//SI EL USUARIO ESCOJI� REACTIVAR EL ARTICULO...
							articulo[item].status = 1;//SE CAMBIA EL ESTATUS A ACTIVO
							printf("\n\t\t//Aviso: Art%cculo Reactivado Exitosamente//\n", 161);//MENSAJE DE CONFIRMACI�N
						}
						else {//SI EL USUARIO DECIDE NO REACTIVAR EL ARTICULO
							printf("\n\t\t//Aviso: Art%cculo No Reactivado//\n", 161);//MENSAJE DE CONFIRMACI�N
						}
					}
				}
			}
		} while (valtemp == 0 || valtemp < 0 || v != 0 || valtemp > 20);//FIN DEL CILO VALIDACI�N NUMERO DE ITEM DONDE SE REPETIR� SI EL NUMERO NO PAS� LA VALIDACI�N
		printf("\n\t1.T%ctulo\n\t2.G%cnero\n\t3.Clasificaci%cn de Edad\n\t4.Consola\n\t5.Precio\n\t", 161, 130, 162); //MUESTRA DE OPCIONES
		valtemp = 0; ent = 0; v = 0;//LIMPIEZA DE VARIABLES PARA REUTILIZAR
		while (v == 0) {//INICIO DE CICLO VALIDACI�N OPCIONES EDITAR
			printf("\n\n\t\tIngresar Dato a Editar (valor n%cmerico entero):", 163); //INSTRUCCI�N AL USUARIO
			scanf_s("%f", &valtemp);//LECTURA DE DATOS EN UNA VARIABLE TEMPORAL
			v = modf(valtemp, &ent);//CALCULACI�N DE LA VALIDACI�N DONDE SE BUSCA SI ES UN NUMERO ENTERO(SI V=0, EL NUMERO ES ENTERO)
			if (v != 0) {//SI EL NUMERO ES FLOTANTE
				printf("\n\n\t//Error: Debe ser entero//\n");//SE IMPRIME UN MENSAJE MARCANDO EL ERROR
				return(modificar());//SE REGRESA AL INICIO
			}
			else {//SI EL NUMERO PASA LA VALIDACI�N...
				v = 1;//SE LE PERMITE SALIR DEL CILCO VALIDACI�N OPCIONES EDITAR
			}
		}//FIN DEL CICLO VALIDACI�N OPCIONES EDITAR
		opc = valtemp;//SE PASAN LOS DATOS DE LA VARIABLE TEMPORAL A LA VARIABLE OPC
		switch (opc) { //INICIO DE ESTRUCCTURA DE SELECCI�N
		case 1:
			printf("\n\t* Ingrese el nuevo t%ctulo del item (texto): ", 161);//INSTRUCCI�N AL USUARIO
			cin.ignore();//IGNORAR EL ESPACIO DE LA ENTERIOR LECTURA YA QUE GETS NO IGNORA SEPARADORES
			gets_s(articulo[item].itemname);//LECTURA DE DATOS
			break;
		case 2:
			printf("\n\t* Ingrese el nuevo g%cnero del item (texto): ", 130);//INSTRUCCI�N AL USUARIO
			cin.ignore();//IGNORAR EL ESPACIO DE LA ENTERIOR LECTURA YA QUE GETS NO IGNORA SEPARADORES
			gets_s(articulo[item].gnre);//LECTURA DE DATOS
			break;
		case 3:
			printf("\n\t* CLasificaciones por edad:\n\t1.eC (Infancia Temprana)\n\t2.E (P%cblico General)\n\t3.E 10+ (Arriba de 10)\n\t4.T (Adolecentes)\n\t5.M (Arriba de 17)\n\t6.A +18 (Adultos)\n\t7.RP (Clasificacion Pendiente)", 163);//IMPRESI�N DE MEN� DE OPCIONES
			valtemp = 0; ent = 0; v = 0;//LIMPIEZA DE VARIABLES PARA REUTILIZAR
			do {//INICIO DEL CICLO VALIDACI�N EDAD
				printf("\n\n\t* Ingrese la nueva clasificaci%cn del item (valor n%cmerico entero): ", 162, 163);//INSTRUCCI�N AL USUARIO
				scanf_s("%f", &valtemp);//LECTURA DE DATOS EN VARIABLE TEMPORAL
				v = modf(valtemp, &ent);//CALCULACI�N DE LA VALIDACI�N DONDE SE BUSCA SI ES UN NUMERO ENTERO(SI V=0, EL NUMERO ES ENTERO)
				if (v != 0) {//SI EL NUMERO ES FLOTANTE...
					printf("\n\t\t//Error: Falla de Captura (el n%cmero debe ser entero)//", 163);//SE IMPRIME UN MENSAJE DE ERROR POR SER FLOTANTE
				}
				else {//SI EL NUMERO ES ENTERO...
					if (valtemp <= 0 || valtemp > 7) {//SE REVISA SI CAE DENTRO DEL RANGO DE OPCIONES
						printf("\n\t\t//Error: Opci%cn No Existente//", 162);//SE IMPRIME UN MENSAJE INDICANDO QUE EL NUMERO EST� FUERA DE RANGO
					}
				}
			} while (valtemp < 1 || valtemp > 7 || valtemp <= 0 || v != 0);//FIN DE CICLO VALIDACI�N EDAD DONDE SE REPETIR� SI EL NUMERO NO PASO LAS VALIDACIONES
			articulo[item].agecls = valtemp;//SE PASAN LOS DATOS DE LA VARIABLE TEMPORAL A LA VARIABLE AGECLS PARA SER GUARDADA EN EL ARREGLO
			break;
		case 4:
			printf("\n\t* Ingrese la nueva consola del item (texto): ", 130);//INSTRUCCI�N AL USUARIO
			cin.ignore();//IGNORAR EL ESPACIO DE LA ENTERIOR LECTURA YA QUE GETS NO IGNORA SEPARADORES
			gets_s(articulo[item].consl);//LECTURA DE DATOS
			break;
		case 5:
			do {//INICIO DE CICLO VALIDACI�N PRECIO
				valtemp = 0;//SE LIMPIAN LAS VARIABLES TEMPORALES PARA REUTILIZAR
				printf("\n\t* Ingrese el precio del item (valor num%crico): $", 130);//INSTRUCCIONES AL USUARIO
				scanf_s("%f", &valtemp);//LECTURA DE DATOS EN VARIABLE TEMPORAL
				if (valtemp < 0) {//SI EL PRECIO ES NEGATIVO...
					printf("\n\t\t//Error: El Precio No Puede Ser Menor a 0//\n");//SE LE INDICA AL USUARIO EL ERROR
				}
			} while (valtemp < 0);//FIN DEL CICLO VALIDACI�N PRECIO DONDE SE REPETIR� SI EL PRECIO NO PAS� LAS VALIDACIONES
			articulo[item].fltprice = valtemp;//SE PASAN LOS DATOS DE LA VARIABLE TEMPORAL A LA VARIABLE FLTPRICE PARA SER GUARDADOS EN EL ARREGLO
			tax = articulo[item].fltprice * .16;//CALCULACI�N DEL IMPUESTO
			articulo[item].tax = tax;//SE PASAN LOS DATOS DE LA VARIABLE TEMPORAL A LA VARIABLE TAX PARA SER GUARDADA EN EL ARREGLO
			ttlprice = articulo[item].tax + articulo[item].fltprice;//CALCULACI�N DEL PRECIO TOTAL
			articulo[item].ttlprice = ttlprice;//SE PASAN LOS DATOS DE LA VARIABLE TEMPORAL A LA VARIABLE TTLPRICE PARA SER GUARDADA EN EL ARREGLO
			break;
		default:
			printf("\n\n\t//Error: Opci%cn Inexistente//\n", 162);//MENSAJE DE ERROR POR INGRESAR UNA OPCI�N FUERA DEL MENU
			return(modificar());
			break;
		}//FIN DE ESTRUCTURA DE SELECCI�N
		printf("\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--");//SEPARADOR PARA EL APARTADO DE MOSTRAR CAMBIOS
		printf("\n\tInformaci%cn ingresada:\n\t\t* item#%i", 162, articulo[item].numitem); printf("\n\t\t* t%ctulo: %s", 161, articulo[item].itemname); printf("\n\t\t* g%cnero: %s", 130, articulo[item].gnre); printf("\n\t\t* clasificaci%cn de edad: ", 162);//SE IMPRIME LA INFORMACI�N REGISTRADA
		if (articulo[item].agecls == 1) {//CADENA DE CONDICIONALES PARA IMPRIMIR LA OPCI�N QUE EL USUARIO ECOJI�
			printf("eC (Infancia Temprana)");
		}
		if (articulo[item].agecls == 2) {
			printf("E (P%cblico General)", 163);
		}
		if (articulo[item].agecls == 3) {
			printf("E 10+ (Arriba de 10)");
		}
		if (articulo[item].agecls == 4) {
			printf("T (Adolecentes)");
		}
		if (articulo[item].agecls == 5) {
			printf("M (Arriba de 17)");
		}
		if (articulo[item].agecls == 6) {
			printf("A +18 (Adultos)");
		}
		if (articulo[item].agecls == 7) {
			printf("RP (Clasificaci%cn Pendiente)", 162);
		}
		printf("\n\t\t* consola: %s", articulo[item].consl);//IMPRESI�N DE INFORMACI�N REGISTRADA
		if (articulo[item].fltprice == 0) {//SI EL PRECIO ES 0...
			printf("\n\t\t* precio neto: gratis");//EN VEZ DE IMPRIMIR EL PRECIO 0 SE IMPRIME "GRATIS"
		}
		else {//SI EL PRECIO ES MAYOR A 0
			printf("\n\t\t* precio neto: $%f", articulo[item].ttlprice); printf("\n\t\t\t* precio bruto: $%f", articulo[item].fltprice); printf("\n\t\t\t* impuesto(16%%): $%f", articulo[item].tax); //SE IMPRIMEN LOS DATOS REGISTRADOS
		}
		printf("\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--\n\n"); //SEPARADOR
		printf("\t\tSi desea editar otro art%cculo, presione 1.\n\t\tSi desea terminar, presione cualquier otro n%cmero:", 161, 163);//INTRUCCIONES AL USUARIO
		scanf_s("%f", &i);//SI EL USUARIO INGRESA "1" SE CUMPLIR� LA CONDICI�N Y SE REINICIAR� EL PROCESO, SI SE ESCOJE CUALQUIER OTRO SE SALDR� DEL CICLO Y REGRESAR� A LA FUNCI�N MADRE
	}//FIN DEL CICLO MODIFICAR
}//FIN DE LA FUNCI�N MODIFICAR

void baja() {//INICIO DE LA FUNCI�N BAJA
	printf("\n------------------------------------| Dar Art%cculo de Baja |------------------------------------\n", 161);//TITULO Y SEPARADOR DEL MOUDLO BAJA
	float valtemp, v = 0, ent;//DECLARACI�N DE VARIABLES
	int item = 0;
	do {//INICIO DEL CICLO VALIDACI�N
		printf("\n\n\t* Ingrese el #item del item que desea dar de baja (valor num%crico entero): ", 130);//INTRUCCI�N AL USUARIO
		scanf_s("%f", &valtemp);//LECTURA DE DATOS EN UNA VARIABLE TEMPORAL
		v = modf(valtemp, &ent);//CALCULACI�N DE LA VALIDACI�N DONDE SE BUSCA SI ES UN NUMERO ENTERO(SI V=0, EL NUMERO ES ENTERO)
		if (v != 0) {//SI EL NUMERO ES FLOTANTE...
			printf("\n\t\t//Error: Falla de Captura (el n%cmero debe ser entero)//", 163);//SE IMPRIME MENSAJE INDICANDO EL ERROR
		}
		else {//SI EL NUMERO ES ENTERO...
			if (valtemp < 1 || valtemp > 20) {//SE BUSCA SI EL N�MERO EST� FUERA DEL RANGO DE ESPACIOS DE GUARDADO
				printf("\n\t\t//Error: Opci%cn Fuera de Rango (debe ser mayor o igual a 1 y menor o igual a 20)//", 162);//SE IMPRIME MENSAJE INDICANDO EL ERROR
			}
			else {//SI EL N�MERO EST� DENTRO DEL RANGO...
				item = valtemp;//SE PASA DE LA VARIABLE TEMPORAL FLOTANTE A UNA VARIABLE TEMPORAL ENTERA
				if (articulo[item].status == 1) {//SI EL N�MERO INDICA UN ESPACIO ACTIVO...
					articulo[item].status = 2;//SE CAMBIA SU ESTADO A INACTIVO(SE DA DE BAJA)
					printf("\n\t\t//Aviso: Art%cculo Dado de Baja Exitosamente//", 161);//MENSAJE DE CONFIRMACI�N
				}
				else {//SI EL N�MERO NO ES UN ESPACIO ACTIVO, ENTONCES...
					if (articulo[item].status == 2) {//SI EL NUMERO INDICA QUE EL ARTICUO ESTA DADO DE BAJA...
						printf("\n\t\t//Error: Art%cculo Ya Dado de Baja//", 161);//SE LE AVISA AL USUARIO
					}
					if (articulo[item].status == 0) {//SI EL NUMERO INDICA QUE EL ARTICULO NO EXISTE...
						printf("\n\t\t//Error: Art%cculo Inexistente//", 161);//SE LE AVISA AL USUARIO
					}
				}
			}
		}
	} while (valtemp == 0 || valtemp < 0 || v != 0 || valtemp > 20);//FIN DEL CILO VALIDACI�N DONDE SE REPETIR� SI EL NUMERO NO PAS� LA VALIDACI�N
}//FIN DE LA FUNCI�N BAJA

void lista() {
	int empty = 0, match = 0, opc;
	float valtemp, ent, v, filtronum;
	char filtrochar[40];
	printf("\n--------------------------------| Lista de Art%cculos en Stock |---------------------------------\n", 161);//T�TULO Y SEPARADOR DEL MODULO LISTA
	printf("\n\t1.G%cnero\n\t2.Clasificaci%cn de Edad\n\t3.Consola\n\t4.Imprimir Toda la Lista", 130, 162); //MUESTRA DE OPCIONES
	valtemp = 0; ent = 0; v = 0;//LIMPIEZA DE VARIABLES PARA REUTILIZAR
	while (v == 0) {//INICIO DE CICLO VALIDACI�N OPCIONES
		printf("\n\n\t\tSeleccione Un Filtro a Aplicar a\n\t\tla Hora de Imprimir la Lista (valor n%cmerico entero):", 163); //INSTRUCCI�N AL USUARIO
		scanf_s("%f", &valtemp);//LECTURA DE DATOS EN UNA VARIABLE TEMPORAL
		v = modf(valtemp, &ent);//CALCULACI�N DE LA VALIDACI�N DONDE SE BUSCA SI ES UN NUMERO ENTERO(SI V=0, EL NUMERO ES ENTERO)
		if (v != 0) {//SI EL NUMERO ES FLOTANTE
			printf("\n\n\t//Error: Debe ser entero//\n");//SE IMPRIME UN MENSAJE MARCANDO EL ERROR
			return(lista());//SE REGRESA AL INICIO
		}
		else {//SI EL NUMERO PASA LA VALIDACI�N...
			v = 1;//SE LE PERMITE SALIR DEL CILCO VALIDACI�N OPCIONES
		}
	}//FIN DEL CICLO VALIDACI�N OPCIONES
	opc = valtemp;//SE PASAN LOS DATOS DE LA VARIABLE TEMPORAL A LA VARIABLE OPC
	switch (opc) { //INICIO DE ESTRUCCTURA DE SELECCI�N
	case 1:
		printf("\n\t* Ingrese el g%cnero a filtrar (texto): ", 130);//INSTRUCCI�N AL USUARIO
		cin.ignore();//IGNORAR EL ESPACIO DE LA ENTERIOR LECTURA YA QUE GETS NO IGNORA SEPARADORES
		gets_s(filtrochar);//LECTURA DE DATOS
		for (int i = 0; i < 21; i++) {//INICIO DE CICLO IMPRESI�N
			if (strcmp(filtrochar, articulo[i].gnre) == 0) {//SI EL ARTICULO COINCIDE CON EL NOMBRE A FILTRAR...
				if (articulo[i].status == 1) {//SI EL ARTICULO TIENE EL ESTATUS DE ACTIVO...
					printf("\n\t\t* item#%i", articulo[i].numitem); printf("\n\t\t* t%ctulo: %s", 161, articulo[i].itemname); printf("\n\t\t* g%cnero: %s", 130, articulo[i].gnre); printf("\n\t\t* clasificaci%cn de edad: ", 162);//SE IMPRIME LA INFORMACI�N REGISTRADA
					if (articulo[i].agecls == 1) {//CADENA DE CONDICIONALES PARA IMPRIMIR LA OPCI�N QUE EL USUARIO ECOJI�
						printf("eC (Infancia Temprana)");
					}
					if (articulo[i].agecls == 2) {
						printf("E (P%cblico General)", 163);
					}
					if (articulo[i].agecls == 3) {
						printf("E 10+ (Arriba de 10)");
					}
					if (articulo[i].agecls == 4) {
						printf("T (Adolecentes)");
					}
					if (articulo[i].agecls == 5) {
						printf("M (Arriba de 17)");
					}
					if (articulo[i].agecls == 6) {
						printf("A +18 (Adultos)");
					}
					if (articulo[i].agecls == 7) {
						printf("RP (Clasificaci%cn Pendiente)", 162);
					}
					printf("\n\t\t* consola: %s", articulo[i].consl);//IMPRESI�N DE INFORMACI�N
					if (articulo[i].fltprice == 0) {//SI EL PRECIO ES 0...
						printf("\n\t\t* precio neto: gratis");//EN VEZ DE IMPRIMIR EL PRECIO 0 SE IMPRIME "GRATIS"
					}
					else {//SI EL PRECIO ES MAYOR A 0...
						printf("\n\t\t* precio neto: $%f", articulo[i].ttlprice); printf("\n\t\t\t* precio bruto: $%f", articulo[i].fltprice); printf("\n\t\t\t* impuesto(16%%): $%f", articulo[i].tax);//SE IMPRIMEN LOS DATOS
					}
					if (i < 20) {//SI EL ARTICULO NO ES EL �LTIMO EN SER IMPRESO...
						printf("\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--\n");//SE IMPRIME UN SEPARADOR
					}
				}
				else {//SI EL ARTICULO...
					if (articulo[i].status == 2) {//TIENE UN ESTATUS DE DORMIDO (DADO DE BAJA)
						printf("\n\n\t//Art%cculo Dado de Baja//\n\n", 161);//SE IMPRIME QUE EL ARTICULO FUE DADO DE BAJA
						if (i < 20) {//SI EL ARTICULO NO ES EL �LTIMO EN SER IMPRESO...
							printf("\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--\n");//SE IMPRIME UN SEPARADOR
						}
					}
					else {//TIENE UN ESTATUS DE VACIO
						empty++;//SE VA ACUMULANDO EN LA VARIABLE EMPTY
					}
				}
			}
			else{//SI EL ARTICULO NO COINCIDE CON EL NOMBRE A FILTRAR...
				if (articulo[i].status == 1 || articulo[i].status == 2 || articulo[i].status == 0) {//SI TIENE UN ESTATUS DE ACTIVO O DORMIDO
					match++;//SE VA ACUMULANDO EN LA VARIABLE MATCH
				}
				if (articulo[i].status == 0) {//SI TIENE UN ESTATUS DE VACIO
					empty++;//SE VA ACUMULANDO EN LA VARIABLE EMPTY
				}
			}
		}//FIN DE CICLO IMPRESI�N
		if (empty == 21) {//SI LA VARIABLE EMPTY ACUMULA UN VALOR A 21, SIGNIFICA QUE TODOS LOS ARTICULOS ESTABAN VACIOS
			printf("\n\n\t//Error: No Hay Art%cculos Registrados//\n\n", 161);//SE IMPRIME UN MENSAJE INDICANDOLO
		}
		if (match == 21) {//SI LA VARIABLE MATCH ACUMULA UN VALOR A 21, SIGNIFICA QUE NINGUN ELEMENTO COINCIDE CON EL NOMBRE A FILTRAR
			printf("\n\n\t//Error: No Hay Art%cculos Que Coincidan con el Filtro//\n\n", 161);//SE IMPRIME UN MENSAJE INDICANDOLO
		}
		break;
	case 2:
		printf("\n\t* CLasificaciones por edad:\n\t1.eC (Infancia Temprana)\n\t2.E (P%cblico General)\n\t3.E 10+ (Arriba de 10)\n\t4.T (Adolecentes)\n\t5.M (Arriba de 17)\n\t6.A +18 (Adultos)\n\t7.RP (Clasificacion Pendiente)", 163);//IMPRESI�N DE MEN� DE OPCIONES
		valtemp = 0; ent = 0; v = 0;//LIMPIEZA DE VARIABLES PARA REUTILIZAR
		do {//INICIO DEL CICLO VALIDACI�N EDAD
			printf("\n\n\t* Ingrese la clasificaci%cn a filtrar (valor n%cmerico entero): ", 162, 163);//INSTRUCCI�N AL USUARIO
			scanf_s("%f", &valtemp);//LECTURA DE DATOS EN VARIABLE TEMPORAL
			v = modf(valtemp, &ent);//CALCULACI�N DE LA VALIDACI�N DONDE SE BUSCA SI ES UN NUMERO ENTERO(SI V=0, EL NUMERO ES ENTERO)
			if (v != 0) {//SI EL NUMERO ES FLOTANTE...
				printf("\n\t\t//Error: Falla de Captura (el n%cmero debe ser entero)//", 163);//SE IMPRIME UN MENSAJE DE ERROR POR SER FLOTANTE
			}
			else {//SI EL NUMERO ES ENTERO...
				if (valtemp <= 0 || valtemp > 7) {//SE REVISA SI CAE DENTRO DEL RANGO DE OPCIONES
					printf("\n\t\t//Error: Opci%cn No Existente//", 162);//SE IMPRIME UN MENSAJE INDICANDO QUE EL NUMERO EST� FUERA DE RANGO
				}
			}
		} while (valtemp < 1 || valtemp > 7 || valtemp <= 0 || v != 0);//FIN DE CICLO VALIDACI�N EDAD DONDE SE REPETIR� SI EL NUMERO NO PASO LAS VALIDACIONES
		filtronum = valtemp;//SE PASAN LOS DATOS DE LA VARIABLE TEMPORAL A LA VARIABLE AGECLS PARA SER GUARDADA EN EL ARREGLO
		for (int i = 0; i < 21; i++) {//INICIO DE CICLO IMPRECI�N
			if (filtronum == articulo[i].agecls) {//SI EL ARTICULO COINCIDE CON LA CLASIFICACI�N A FILTRAR...
				if (articulo[i].status == 1) {//SI EL ARTICULO TIENE EL ESTATUS DE ACTIVO...
					printf("\n\t\t* item#%i", articulo[i].numitem); printf("\n\t\t* t%ctulo: %s", 161, articulo[i].itemname); printf("\n\t\t* g%cnero: %s", 130, articulo[i].gnre); printf("\n\t\t* clasificaci%cn de edad: ", 162);//SE IMPRIME LA INFORMACI�N REGISTRADA
					if (articulo[i].agecls == 1) {//CADENA DE CONDICIONALES PARA IMPRIMIR LA OPCI�N QUE EL USUARIO ECOJI�
						printf("eC (Infancia Temprana)");
					}
					if (articulo[i].agecls == 2) {
						printf("E (P%cblico General)", 163);
					}
					if (articulo[i].agecls == 3) {
						printf("E 10+ (Arriba de 10)");
					}
					if (articulo[i].agecls == 4) {
						printf("T (Adolecentes)");
					}
					if (articulo[i].agecls == 5) {
						printf("M (Arriba de 17)");
					}
					if (articulo[i].agecls == 6) {
						printf("A +18 (Adultos)");
					}
					if (articulo[i].agecls == 7) {
						printf("RP (Clasificaci%cn Pendiente)", 162);
					}
					printf("\n\t\t* consola: %s", articulo[i].consl);//IMPRESI�N DE INFORMACI�N
					if (articulo[i].fltprice == 0) {//SI EL PRECIO ES 0...
						printf("\n\t\t* precio neto: gratis");//EN VEZ DE IMPRIMIR EL PRECIO 0 SE IMPRIME "GRATIS"
					}
					else {//SI EL PRECIO ES MAYOR A 0...
						printf("\n\t\t* precio neto: $%f", articulo[i].ttlprice); printf("\n\t\t\t* precio bruto: $%f", articulo[i].fltprice); printf("\n\t\t\t* impuesto(16%%): $%f", articulo[i].tax);//SE IMPRIMEN LOS DATOS
					}
					if (i < 20) {//SI EL ARTICULO NO ES EL �LTIMO EN SER IMPRESO...
						printf("\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--\n");//SE IMPRIME UN SEPARADOR
					}
				}
				else {//SI EL ARTICULO...
					if (articulo[i].status == 2) {//TIENE UN ESTATUS DE DORMIDO (DADO DE BAJA)
						printf("\n\n\t//Art%cculo Dado de Baja//\n\n", 161);//SE IMPRIME QUE EL ARTICULO FUE DADO DE BAJA
						if (i < 20) {//SI EL ARTICULO NO ES EL �LTIMO EN SER IMPRESO...
							printf("\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--\n");//SE IMPRIME UN SEPARADOR
						}
					}
					else {//TIENE UN ESTATUS DE VACIO
						empty++;//SE VA ACUMULANDO EN LA VARIABLE EMPTY
					}
				}
			}
			else {//SI EL ARTICULO NO COINCIDE CON LA CLASIFICACI�N A FILTRAR...
				if (articulo[i].status == 1 || articulo[i].status == 2 || articulo[i].status == 0) {//SI TIENE UN ESTATUS DE ACTIVO O DORMIDO
					match++;//SE VA ACUMULANDO EN LA VARIABLE MATCH
				}
				if (articulo[i].status == 0) {//SI TIENE UN ESTATUS DE VACIO
					empty++;//SE VA ACUMULANDO EN LA VARIABLE EMPTY
				}
			}
		}//FIN DE CICLO IMPRESI�N
		if (empty == 21) {//SI LA VARIABLE EMPTY ACUMULA UN VALOR A 21, SIGNIFICA QUE TODOS LOS ARTICULOS ESTABAN VACIOS
			printf("\n\n\t//Error: No Hay Art%cculos Registrados//\n\n", 161);//SE IMPRIME UN MENSAJE INDICANDOLO
		}
		if (match == 21) {//SI LA VARIABLE MATCH ACUMULA UN VALOR A 21, SIGNIFICA QUE NINGUN ELEMENTO COINCIDE CON LA CLASIFICACI�N A FILTRAR
			printf("\n\n\t//Error: No Hay Art%cculos Que Coincidan con el Filtro//\n\n", 161);//SE IMPRIME UN MENSAJE INDICANDOLO
		}
		break;
	case 3:
		printf("\n\t* Ingrese la consola a filtrar (texto): ", 161);//INSTRUCCI�N AL USUARIO
		cin.ignore();//IGNORAR EL ESPACIO DE LA ENTERIOR LECTURA YA QUE GETS NO IGNORA SEPARADORES
		gets_s(filtrochar);//LECTURA DE DATOS
		for (int i = 0; i < 21; i++) {//INICIO DE CICLO IMPRESI�N
			if (strcmp(filtrochar, articulo[i].consl) == 0) {//SI EL ARTICULO COINCIDE CON LA CONSOLA A FILTRAR...
				if (articulo[i].status == 1) {//SI EL ARTICULO TIENE EL ESTATUS DE ACTIVO...
					printf("\n\t\t* item#%i", articulo[i].numitem); printf("\n\t\t* t%ctulo: %s", 161, articulo[i].itemname); printf("\n\t\t* g%cnero: %s", 130, articulo[i].gnre); printf("\n\t\t* clasificaci%cn de edad: ", 162);//SE IMPRIME LA INFORMACI�N REGISTRADA
					if (articulo[i].agecls == 1) {//CADENA DE CONDICIONALES PARA IMPRIMIR LA OPCI�N QUE EL USUARIO ECOJI�
						printf("eC (Infancia Temprana)");
					}
					if (articulo[i].agecls == 2) {
						printf("E (P%cblico General)", 163);
					}
					if (articulo[i].agecls == 3) {
						printf("E 10+ (Arriba de 10)");
					}
					if (articulo[i].agecls == 4) {
						printf("T (Adolecentes)");
					}
					if (articulo[i].agecls == 5) {
						printf("M (Arriba de 17)");
					}
					if (articulo[i].agecls == 6) {
						printf("A +18 (Adultos)");
					}
					if (articulo[i].agecls == 7) {
						printf("RP (Clasificaci%cn Pendiente)", 162);
					}
					printf("\n\t\t* consola: %s", articulo[i].consl);//IMPRESI�N DE INFORMACI�N
					if (articulo[i].fltprice == 0) {//SI EL PRECIO ES 0...
						printf("\n\t\t* precio neto: gratis");//EN VEZ DE IMPRIMIR EL PRECIO 0 SE IMPRIME "GRATIS"
					}
					else {//SI EL PRECIO ES MAYOR A 0...
						printf("\n\t\t* precio neto: $%f", articulo[i].ttlprice); printf("\n\t\t\t* precio bruto: $%f", articulo[i].fltprice); printf("\n\t\t\t* impuesto(16%%): $%f", articulo[i].tax);//SE IMPRIMEN LOS DATOS
					}
					if (i < 20) {//SI EL ARTICULO NO ES EL �LTIMO EN SER IMPRESO...
						printf("\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--\n");//SE IMPRIME UN SEPARADOR
					}
				}
				else {//SI EL ARTICULO...
					if (articulo[i].status == 2) {//TIENE UN ESTATUS DE DORMIDO (DADO DE BAJA)
						printf("\n\n\t//Art%cculo Dado de Baja//\n\n", 161);//SE IMPRIME QUE EL ARTICULO FUE DADO DE BAJA
						if (i < 20) {//SI EL ARTICULO NO ES EL �LTIMO EN SER IMPRESO...
							printf("\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--\n");//SE IMPRIME UN SEPARADOR
						}
					}
					else {//TIENE UN ESTATUS DE VACIO
						empty++;//SE VA ACUMULANDO EN LA VARIABLE EMPTY
					}
				}
			}
			else {//SI EL ARTICULO NO COINCIDE CON LA CONSOLA A FILTRAR...
				if (articulo[i].status == 1 || articulo[i].status == 2 || articulo[i].status == 0) {//SI TIENE UN ESTATUS DE ACTIVO O DORMIDO
					match++;//SE VA ACUMULANDO EN LA VARIABLE MATCH
				}
				if (articulo[i].status == 0) {//SI TIENE UN ESTATUS DE VACIO
					empty++;//SE VA ACUMULANDO EN LA VARIABLE EMPTY
				}
			}
		}//FIN DE CICLO IMPRESI�N
		if (empty == 21) {//SI LA VARIABLE EMPTY ACUMULA UN VALOR A 21, SIGNIFICA QUE TODOS LOS ARTICULOS ESTABAN VACIOS
			printf("\n\n\t//Error: No Hay Art%cculos Registrados//\n\n", 161);//SE IMPRIME UN MENSAJE INDICANDOLO
		}
		if (match == 21) {//SI LA VARIABLE MATCH ACUMULA UN VALOR A 21, SIGNIFICA QUE NINGUN ELEMENTO COINCIDE CON EL NOMBRE A FILTRAR
			printf("\n\n\t//Error: No Hay Art%cculos Que Coincidan con el Filtro//\n\n", 161);//SE IMPRIME UN MENSAJE INDICANDOLO
		}
		break;
	case 4:
		for (int i = 0; i < 21; i++) {//INICIO DE CICLO IMPRESI�N DE 20 VUELTAS PARA REVISAR TODOS LOS ELEMENTOS DEL ARREGLO
			if (articulo[i].status == 1) {//SI EL ARTICULO TIENE EL ESTATUS DE ACTIVO...
				printf("\n\t\t* item#%i", articulo[i].numitem); printf("\n\t\t* t%ctulo: %s", 161, articulo[i].itemname); printf("\n\t\t* g%cnero: %s", 130, articulo[i].gnre); printf("\n\t\t* clasificaci%cn de edad: ", 162);//SE IMPRIME LA INFORMACI�N REGISTRADA
				if (articulo[i].agecls == 1) {//CADENA DE CONDICIONALES PARA IMPRIMIR LA OPCI�N QUE EL USUARIO ECOJI�
					printf("eC (Infancia Temprana)");
				}
				if (articulo[i].agecls == 2) {
					printf("E (P%cblico General)", 163);
				}
				if (articulo[i].agecls == 3) {
					printf("E 10+ (Arriba de 10)");
				}
				if (articulo[i].agecls == 4) {
					printf("T (Adolecentes)");
				}
				if (articulo[i].agecls == 5) {
					printf("M (Arriba de 17)");
				}
				if (articulo[i].agecls == 6) {
					printf("A +18 (Adultos)");
				}
				if (articulo[i].agecls == 7) {
					printf("RP (Clasificaci%cn Pendiente)", 162);
				}
				printf("\n\t\t* consola: %s", articulo[i].consl);//IMPRESI�N DE INFORMACI�N
				if (articulo[i].fltprice == 0) {//SI EL PRECIO ES 0...
					printf("\n\t\t* precio neto: gratis");//EN VEZ DE IMPRIMIR EL PRECIO 0 SE IMPRIME "GRATIS"
				}
				else {//SI EL PRECIO ES MAYOR A 0...
					printf("\n\t\t* precio neto: $%f", articulo[i].ttlprice); printf("\n\t\t\t* precio bruto: $%f", articulo[i].fltprice); printf("\n\t\t\t* impuesto(16%%): $%f", articulo[i].tax);//SE IMPRIMEN LOS DATOS
				}
				if (i < 20) {//SI EL ARTICULO NO ES EL �LTIMO EN SER IMPRESO...
					printf("\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--\n");//SE IMPRIME UN SEPARADOR
				}
			}
			else {//SI EL ARTICULO...
				if (articulo[i].status == 2) {//TIENE UN ESTATUS DE DORMIDO (DADO DE BAJA)
					printf("\n\n\t//Art%cculo Dado de Baja//\n\n", 161);//SE IMPRIME QUE EL ARTICULO FUE DADO DE BAJA
					if (i < 20) {//SI EL ARTICULO NO ES EL �LTIMO EN SER IMPRESO...
						printf("\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--\n");//SE IMPRIME UN SEPARADOR
					}
				}
				else {//TIENE UN ESTATUS DE VACIO
					empty++;//SE VA ACUMULANDO EN LA VARIABLE EMPTY
				}
			}
			if (empty == 21) {//SI LA VARIABLE EMPTY ACUMULA UN VALOR A 21, SIGNIFICA QUE TODOS LOS ARTICULOS ESTABAN VACIOS
				printf("\n\n\t//Error: No Hay Art%cculos Registrados//\n\n", 161);//SE IMPRIME UN MENSAJE INDICANDOLO
			}
		}//FIN DEL CICLO IMPRESI�N
		break;
	default:
		printf("\n\n\t//Error: Opci%cn No Existente//\n", 162);//MENSAJE DE ERROR POR INGRESAR UNA OPCI�N FUERA DEL MENU
		return(lista());
		break;
	}//FIN DE ESTRUCTURA DE SELECCI�N
}//FIN DE FUNCI�N LISTA

void salir() {//INICIO DE FUNCI�N SALIDA
	ofstream archivo;//DECLARACI�N DE LA VARIABLE ARCHIVO
	string datos;
	printf("\n\t*creando archivo*");//SE LE INDICA LA USUARIO QUE SE INICIO EL PROCESO
	archivo.open("Lista_de_Articulos.txt", ios::out);//SE CREA EL ARCHIVO/REMPLAZA
	if (archivo.fail()) {//SI HUBO UN PROBLEMA AL CREAR EL ARCHIVO...
		printf("\n\t\t//Error: Hubo Un Problema al Crear el Archivo//");//SE LE INDICA AL USUARIO
		main();//SE REGRESA AL MENU
	}
	archivo << "\n\titem#\tt�tulo\t\t\tg�nero\t\t\tclasificaci�n\t\t\tconsola\t\tprecio neto\t\tprecio bruto\t\timpuesto\t\tstatus\n", 161, 130, 162;
	archivo << "\n--~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~-- --~--\n";//SE IMPRIME UN SEPARADOR
	for (int i = 1; i < 21; i++) {//INICIO DE CICLO GUARDADO DE 20 VUELTAS PARA GUARDAR TODOS LOS ELEMENTOS DEL ARREGLO
		archivo << "\n\t"; archivo << i;
		if (articulo[i].itemname == 0) {
			archivo << "\t \t";
		}
		else {
			archivo << "\t"; archivo << articulo[i].itemname;
		}
		if (articulo[i].gnre == 0) {
			archivo << "\t\t ";
		}
		else {
			archivo << "\t\t"; archivo << articulo[i].gnre;
		}
		if (articulo[i].agecls == 0) {
			archivo << "\t\t \t\t\t";
		}
		if (articulo[i].agecls == 1) {
			archivo << "\t\teC (Infancia Temprana)\t";
		}
		if (articulo[i].agecls == 2) {
			archivo << "\t\tE (P�blico General)\t   ";
		}
		if (articulo[i].agecls == 3) {
			archivo << "\t\tE 10+ (Arriba de 10)\t  ";
		}
		if (articulo[i].agecls == 4) {
			archivo << "\t\tT (Adolecentes)\t       ";
		}
		if (articulo[i].agecls == 5) {
			archivo << "\t\tM (Arriba de 17)\t      ";
		}
		if (articulo[i].agecls == 6) {
			archivo << "\t\tA +18 (Adultos)\t       ";
		}
		if (articulo[i].agecls == 7) {
			archivo << "\t\tRP (Clasificaci�n Pendiente)  ";
		}
		if (articulo[i].consl == 0) {
			archivo << " \t";
		}
		else {
			archivo << articulo[i].consl;
		}
		if (articulo[i].ttlprice == 0) {
			archivo << "\t \t";
		}
		else {
			archivo << "\t$"; archivo << articulo[i].ttlprice;
		}
		if (articulo[i].fltprice == 0) {
			archivo << "\t \t";
		}
		else {
			archivo << "\t$"; archivo << articulo[i].fltprice;
		}
		if (articulo[i].tax == 0) {
			archivo << "\t \t";
		}
		else {
			archivo << "\t$"; archivo << articulo[i].tax;
		}
		if (articulo[i].status == 0) {
			archivo << "\tVACIO\n";
		}
		else {
			if (articulo[i].status == 2) {
				archivo << "\tINACTIVO\n";
			}
			else {
				archivo << "\tACTIVO\n";
			}
		}
		
	}//FIN DEL CICLO GUARDADO
	printf("\n\t*saliendo*");//CONFIRMACI�N QUE SE INICI� EL PROCESO
	exit(1);//SE SALE DEL PROGRAMA
}//FIN DE FUNCI�N SALIDA