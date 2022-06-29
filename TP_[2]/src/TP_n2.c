/*
 ============================================================================
 Name        : TP_n2.c
 Author      : Tomas Gonzalez
 Description : Trabajo Practico n2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "ArrayPassenger.h"

int main(void) {

	setbuf(stdout, NULL);

	int opcionesGenerales;
	int respuestaGen;
	int retorno = 0;
	int len = 2000;
	struct Passenger listPassenger[len];
	initPassengers(listPassenger, len);
	do
	{
		respuestaGen = utn_getnumero(&opcionesGenerales,"1.Ingresar pasajero\n2.Modificar Pasajero\n3.Eliminar Pasajero\n4.Informe\n"
													    "5.Carga forzada\n6.Salir\nElija una opcion: ","no es una opcion valida \n",1,6);
		if(respuestaGen == 0)
		{
			switch(opcionesGenerales)
			{
				case 1:
					retorno = addPassenger(listPassenger,len);
					switch(retorno)
					{
					case -1:
						printf("\nNo hay mas espacio\n\n");
					break;
					default:
						printf("\nEl pasajero se cargo de manera correcta\n\n");
					break;
					}
				break;
				case 2:
					if(passenger_findOcSpace(listPassenger,len)!= -1)
					{
						retorno =  modificarPasajero(listPassenger,len,listPassenger->id);
						switch(retorno)
						{
						case -1:
							printf("\nno se encontro el id\n\n");
						break;
						default:
							printf("\nPasajero modificado\n\n");
						break;
						}
					}
				break;
				case 3:
					if(passenger_findOcSpace(listPassenger,len)!= -1)
					{
						retorno = removePassenger(listPassenger,len,listPassenger->id);
						switch(retorno)
						{
						case -1:
							printf("\nno se encontro el pasajero\n\n");
						break;
						default:
							printf("\nPasajero eliminado\n\n");
						break;
						}
					}
				break;
				case 4:
					if(passenger_findOcSpace(listPassenger,len)!= -1)
					{
						retorno = informeDatos(listPassenger,len);
						switch(retorno)
						{
						case -1:
							printf("\nFalta de datos\n\n");
						break;
						default:
							printf("\nInforme exitoso\n\n");
						break;
						}
					}
				break;
				case 5:
					cargaForzadaDatos(listPassenger);
				break;
			}
		 }
		}while(opcionesGenerales!=6);

	return EXIT_SUCCESS;
}
