/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include "Passenger.h"
#include "input.h"

Passenger* Passenger_new()
{
	Passenger* p;
	p = (Passenger*) malloc(sizeof(Passenger));
	return p;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellido,char* precio,char* codigoVuelo,char* tipoPasajeroStr,char* estadoVuelo)
{
	Passenger* unPasajero;
	unPasajero = Passenger_new();

	Passenger_setId(unPasajero,atoi(idStr));
	Passenger_setNombre(unPasajero,nombreStr);
	Passenger_setApellido(unPasajero,apellido);
	Passenger_setPrecio(unPasajero,atof(precio));
	Passenger_setCodigoVuelo(unPasajero,codigoVuelo);
	Passenger_setTipoPasajero(unPasajero,tipoPasajeroStr);
	Passenger_setEstadoVuelo(unPasajero,estadoVuelo);

	return unPasajero;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void Passenger_PrintOne(Passenger* unPasajero)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[20];
	char codigoVuelo[20];
	char estadoVuelo[20];
	Passenger_getId(unPasajero,&id);
	Passenger_getNombre(unPasajero,nombre);
	Passenger_getApellido(unPasajero,apellido);
	Passenger_getPrecio(unPasajero,&precio);
	Passenger_getCodigoVuelo(unPasajero,codigoVuelo);
	Passenger_getTipoPasajero(unPasajero,tipoPasajero);
	Passenger_getEstadoVuelo(unPasajero,estadoVuelo);

	printf("%4d %15s %15s %5f %15s %15s %15s \n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////

int Passenger_setId(Passenger* this,int id)
{
	int isOk = 0;
	if(this!=NULL && id>0)
	{
		this -> id = id;
		isOk = 1;
	}
	return isOk;
}


int Passenger_getId(Passenger* this,int* id)
{
	int isOk = 0;
	if(this!=NULL && id!=NULL)
	{
		*id = this -> id;
		isOk = 1;
	}
	return isOk;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int isOk = 0;
	if(this!=NULL)
		{
			strcpy(this->nombre,nombre);
			isOk = 1;
		}
	return isOk;
}


int Passenger_getNombre(Passenger* this,char* nombre)
{
	int isOk = 0;
	if(this!=NULL && nombre!=NULL)
		{
			strcpy(nombre,this->nombre);
			isOk = 1;
		}
		return isOk;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int isOk = 0;
	if(this!=NULL)
		{
			strcpy(this->apellido,apellido);
			isOk = 1;
		}
	return isOk;
}


int Passenger_getApellido(Passenger* this,char* apellido)
{
	int isOk = 0;
	if(this!=NULL && apellido!=NULL)
		{
			strcpy(apellido,this->apellido);
			isOk = 1;
		}
		return isOk;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int isOk = 0;
	if(this!=NULL)
		{
			strcpy(this->codigoVuelo,codigoVuelo);
			isOk = 1;
		}
	return isOk;
}


int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int isOk = 0;
	if(this!=NULL && codigoVuelo!=NULL)
		{
			strcpy(codigoVuelo,this->codigoVuelo);
			isOk = 1;
		}
		return isOk;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int isOk = 0;
	if(this!=NULL)
		{
			strcpy(this->tipoPasajero,tipoPasajero);
			isOk = 1;
		}
	return isOk;
}


int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int isOk = 0;
	if(this!=NULL && tipoPasajero!=NULL)
		{
			strcpy(tipoPasajero,this->tipoPasajero);
			isOk = 1;
		}
		return isOk;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int Passenger_setPrecio(Passenger* this,float precio)
{
	int isOk = 0;
	if(this!=NULL && precio>0)
	{
		this -> precio = precio;
		isOk = 1;
	}
	return isOk;
}


int Passenger_getPrecio(Passenger* this,float* precio)
{
	int isOk = 0;
	if(this!=NULL && precio!=NULL)
	{
		*precio = this -> precio;
		isOk = 1;
	}
	return isOk;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int isOk = 0;
	if(this!=NULL)
		{
			strcpy(this->estadoVuelo,estadoVuelo);
			isOk = 1;
		}
	return isOk;
}


int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int isOk = 0;
	if(this!=NULL && estadoVuelo!=NULL)
		{
			strcpy(estadoVuelo,this->estadoVuelo);
			isOk = 1;
		}
		return isOk;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int Passenger_CompareById(void* p1, void* p2)
{
	int comparison = 0;
	int idOne;
	int idTwo;

	Passenger* passengerOne;
	Passenger* passengerTwo;

	passengerOne = (Passenger*) p1;
	passengerTwo = (Passenger*) p2;

	Passenger_getId(passengerOne, &idOne);
	Passenger_getId(passengerTwo, &idTwo);

	if(idOne<idTwo)
	{
		comparison = -1;
	}
	else
	{
		if(idOne>idTwo)
		{
			comparison = 1;
		}
	}
	return comparison;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////


int Passenger_CompareByName(void* p1, void* p2)
{
	int comparison;
	char nameOne[30];
	char nameTwo[30];

	Passenger* passengerOne;
	Passenger* passengerTwo;

	passengerOne = (Passenger*) p1;
	passengerTwo = (Passenger*) p2;

	Passenger_getNombre(passengerOne, nameOne);
	Passenger_getNombre(passengerTwo, nameTwo);

	comparison = strcmp(nameOne,nameTwo);

	if(comparison<0)
	{
		comparison = -1;
	}
	else
	{
		if(comparison>0)
		{
			comparison = 1;
		}
		else
		{
			comparison = 0;
		}
	}
	return comparison;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int Passenger_CompareBySurName(void* p1, void* p2)
{
	int comparison;
	char SurNameOne[30];
	char SurNameTwo[30];

	Passenger* passengerOne;
	Passenger* passengerTwo;

	passengerOne = (Passenger*) p1;
	passengerTwo = (Passenger*) p2;

	Passenger_getApellido(passengerOne, SurNameOne);
	Passenger_getApellido(passengerTwo, SurNameTwo);

	comparison = strcmp(SurNameOne,SurNameTwo);

	if(comparison<0)
	{
		comparison = -1;
	}
	else
	{
		if(comparison>0)
		{
			comparison = 1;
		}
		else
		{
			comparison = 0;
		}
	}
	return comparison;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int Passenger_CompareByFlyCode(void* p1, void* p2)
{
	int comparison;
	char FlyCodeOne[30];
	char FlyCodeTwo[30];

	Passenger* passengerOne;
	Passenger* passengerTwo;

	passengerOne = (Passenger*) p1;
	passengerTwo = (Passenger*) p2;

	Passenger_getCodigoVuelo(passengerOne, FlyCodeOne);
	Passenger_getCodigoVuelo(passengerTwo, FlyCodeTwo);

	comparison = strcmp(FlyCodeOne,FlyCodeTwo);

	if(comparison<0)
	{
		comparison = -1;
	}
	else
	{
		if(comparison>0)
		{
			comparison = 1;
		}
		else
		{
			comparison = 0;
		}
	}
	return comparison;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int Passenger_CompareByTypePassenger(void* p1, void* p2)
{
	int comparison;
	char TypePassengerOne[30];
	char TypePassengerTwo[30];

	Passenger* passengerOne;
	Passenger* passengerTwo;

	passengerOne = (Passenger*) p1;
	passengerTwo = (Passenger*) p2;

	Passenger_getTipoPasajero(passengerOne, TypePassengerOne);
	Passenger_getTipoPasajero(passengerTwo, TypePassengerTwo);

	comparison = strcmp(TypePassengerOne,TypePassengerTwo);

	if(comparison<0)
	{
		comparison = -1;
	}
	else
	{
		if(comparison>0)
		{
			comparison = 1;
		}
		else
		{
			comparison = 0;
		}
	}
	return comparison;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int Passenger_CompareByPrice(void* p1, void* p2)
{
	int comparison = 0;
	float priceOne;
	float priceTwo;

	Passenger* passengerOne;
	Passenger* passengerTwo;

	passengerOne = (Passenger*) p1;
	passengerTwo = (Passenger*) p2;

	Passenger_getPrecio(passengerOne, &priceOne);
	Passenger_getPrecio(passengerTwo, &priceTwo);

	if(priceOne<priceTwo)
	{
		comparison = -1;
	}
	else
	{
		if(priceOne>priceTwo)
		{
			comparison = 1;
		}
	}
	return comparison;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int Passenger_CompareByStatusFlight(void* p1, void* p2)
{
	int comparison;
	char StatusFlightOne[30];
	char StatusFlightTwo[30];

	Passenger* passengerOne;
	Passenger* passengerTwo;

	passengerOne = (Passenger*) p1;
	passengerTwo = (Passenger*) p2;

	Passenger_getEstadoVuelo(passengerOne, StatusFlightOne);
	Passenger_getEstadoVuelo(passengerTwo, StatusFlightTwo);

	comparison = strcmp(StatusFlightOne,StatusFlightTwo);

	if(comparison<0)
	{
		comparison = -1;
	}
	else
	{
		if(comparison>0)
		{
			comparison = 1;
		}
		else
		{
			comparison = 0;
		}
	}
	return comparison;
}
