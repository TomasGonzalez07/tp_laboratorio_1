/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[30];
	char tipoPasajero[30];
	char estadoVuelo[30];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellido,char* precio,char* codigoVuelo,char* tipoPasajeroStr,char* estadoVuelo);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

int Passenger_CompareById(void* p1, void* p2);
int Passenger_CompareByName(void* p1, void* p2);
int Passenger_CompareBySurName(void* p1, void* p2);
int Passenger_CompareByFlyCode(void* p1, void* p2);
int Passenger_CompareByTypePassenger(void* p1, void* p2);
int Passenger_CompareByPrice(void* p1, void* p2);
int Passenger_CompareByStatusFlight(void* p1, void* p2);
void Passenger_PrintOne(Passenger*);

#endif /* PASSENGER_H_ */
