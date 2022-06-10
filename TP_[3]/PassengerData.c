/*
 * PassengerData.c
 *
 *  Created on: 6 jun 2022
 *      Author: User
 */
#include "Passenger.h"
#include "LinkedList.h"
#include "input.h"
#include "PassengerData.h"

static int idIncremental = 1000;
static int passenger_obtenerID();
static int passenger_obtenerID()
{
	return idIncremental++;
}

int AltaPasajero(LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;
	char idC [10];
	int id = passenger_obtenerID();
	char nombre[50];
	char apellido[50];
	char precioC[10];
	float precio;
	char tipoPasajero[20];
	char codigoVuelo[20];
	char estadoVuelo[10];

	sprintf(idC, "%d", id);
	getString(nombre, "Ingrese el nombre: ","Error\nReingrese nombre: ");
	getString(apellido, "Ingrese el  apellido: ","Error\nReingrese apellido: ");
	getNumberFloat(&precio,"Ingrese precio: ","Error\nReingrese precio: ",0, 1000000);
	gcvt(precio, 7, precioC);
	getStringAlf(codigoVuelo, "Ingrese codigo de vuelo: ","Error\nReingrese codigo de vuelo: ");
	getString(tipoPasajero, "Ingrese tipo de pasajero: ","Error\nReingrese tipo de pasajero: ");
	getString(estadoVuelo, "Ingrese estado de vuelo: ","Error\nReingrese estado de vuelo: ");

	unPasajero = Passenger_newParametros(idC,nombre,apellido,precioC,codigoVuelo,tipoPasajero,estadoVuelo);
	ll_add(pArrayListPassenger,unPasajero);

	return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int EditarPasajero(LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;
	int rtn = -1;
	int opciones;
	int respuesta;
	int idPasajero;
	char nombreN[50];
	char apellidoN[50];
	char precioCN[10];
	float precio;
	char tipoPasajeroN[20];
	char codigoVueloN[20];
	char estadoVueloN[10];

	getNumberInt(&idPasajero,"ingrese id del pasajero que desea modificar", "error id no valido",0, 10000);

	for(int i=0; i<ll_len(pArrayListPassenger); i++)
	{
		unPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
		if(unPasajero->id == idPasajero)
		{
		 do{
			respuesta = utn_getnumero(&opciones,"1.Modificar Nombre\n2.Modificar Apellido\n3.Modificar precio\n4.Modificar tipo de pasajero\n"
												"5.Modificar codigo de vuelo\n6.Modificar estado de vuelo\n7.Salir\n", "no es una opcion valida \n",0,8);
			if(respuesta == 0)
			{
				switch(opciones)
				{
				case 1:
					getString(nombreN, "Ingrese el nuevo nombre: ","Error\nReingrese nuevo nombre: ");
					Passenger_setNombre(unPasajero,nombreN);
					rtn = 1;
					break;
				case 2:
					getString(apellidoN, "Ingrese nuevo apellido: ","Error\nReingrese nuevo apellido: ");
					Passenger_setApellido(unPasajero,apellidoN);
					rtn = 1;
					break;
				case 3:
					getNumberFloat(&precio,"Ingrese nuevo precio: ","Error\nReingrese nuevo precio: ",0, 1000000);
					gcvt(precio, 7, precioCN);
					Passenger_setPrecio(unPasajero,atof(precioCN));
					rtn = 1;
					break;
				case 4:
					getString(tipoPasajeroN, "Ingrese tipo de pasajero: ","Error\nReingrese tipo de pasajero: ");
					Passenger_setTipoPasajero(unPasajero,tipoPasajeroN);
					rtn = 1;
					break;
				case 5:
					getString(codigoVueloN, "Ingrese nuevo codigo de vuelo: ","Error\nReingrese nuevo codigo de vuelo: ");
					Passenger_setCodigoVuelo(unPasajero,codigoVueloN);
					rtn = 1;
					break;
				case 6:
					getString(estadoVueloN, "Ingrese estado de vuelo: ","Error\nReingrese estado de vuelo: ");
					Passenger_setEstadoVuelo(unPasajero,estadoVueloN);
					rtn = 1;
					break;
				}
			}
		 }while(opciones != 7);
		}
	}



	return rtn;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int RemoverPasajero(LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;
	int rtn = -1;
	int idPasajero;

	getNumberInt(&idPasajero,"ingrese id del pasajero que desea remover", "error id no valido",0, sizeof(pArrayListPassenger+1));
	for(int i=0; i<ll_len(pArrayListPassenger); i++)
		{
			unPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			if(unPasajero->id == idPasajero)
			{
				 ll_remove(pArrayListPassenger, i);
				 rtn = 1;
			}
		}

	return rtn;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int OrdenarPasajeros(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int opciones;
	int respuesta;
	if(pArrayListPassenger != NULL)
	{
		do{
			respuesta = utn_getnumero(&opciones,"1.Ordenar por Nombre\n2.Ordenar por Apellido\n3.Ordenar por precio\n4.Ordenar por tipo de pasajero\n"
												"5.Ordenar por codigo de vuelo\n6.Ordenar por estado de vuelo\n7.Ordenar por id\n8.Salir\n", "no es una opcion valida \n",0,9);
			if(respuesta == 0)
			{
				switch(opciones)
				{
				case 1:
					ll_sort(pArrayListPassenger,Passenger_CompareByName,1);
					rtn = 1;
					break;
				case 2:
					ll_sort(pArrayListPassenger,Passenger_CompareBySurName,1);
					rtn = 1;
					break;
				case 3:
					ll_sort(pArrayListPassenger,Passenger_CompareByPrice,1);
					rtn = 1;
					break;
				case 4:
					ll_sort(pArrayListPassenger,Passenger_CompareByTypePassenger,1);
					rtn = 1;
					break;
				case 5:
					ll_sort(pArrayListPassenger,Passenger_CompareByFlyCode,1);
					rtn = 1;
					break;
				case 6:
					ll_sort(pArrayListPassenger,Passenger_CompareByStatusFlight,1);
					rtn = 1;
					break;
				case 7:
					ll_sort(pArrayListPassenger,Passenger_CompareById,1);
					rtn = 1;
					break;
				}
			}
		 }while(opciones != 8);
		}

	return rtn;
}
