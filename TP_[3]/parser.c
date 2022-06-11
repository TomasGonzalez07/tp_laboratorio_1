#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	char id[20];
	char nombre[20];
	char apellido[20];
	char precio[20];
	char codigoVuelo[30];
	char tipo[30];
	char estadoVuelo[30];
	int datosLeidos;

	Passenger* unPasajero;


	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombre,apellido,precio,codigoVuelo,tipo,estadoVuelo);
	while(!feof(pFile))
	{
		datosLeidos =fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",id,nombre,apellido,precio,codigoVuelo,tipo,estadoVuelo);

		if(datosLeidos == 7)
		{
			unPasajero = Passenger_newParametros(id,nombre,apellido,precio,codigoVuelo,tipo,estadoVuelo);
			ll_add(pArrayListPassenger,unPasajero);
		}
		else
		{
			if(datosLeidos != 7 && unPasajero != NULL)
			{
				if(!feof(pFile))
				{
					printf("error al leer datos\n");
				}
				else
				{
					printf("se leyo todo el archivo completo\n");
				}
			}
		}
	}
	fclose(pFile);

    return 1;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;
	int datosLeidos;

	while(!feof(pFile))
	{

		unPasajero = Passenger_new();
		datosLeidos = fread(&unPasajero,sizeof(Passenger*),1,pFile);
		if(datosLeidos == 1 && unPasajero != NULL)
		{
			ll_add(pArrayListPassenger,unPasajero);
		}
		else
		{
			if(datosLeidos != 1)
			{
				if(!feof(pFile))
				{
					printf("error al leer datos\n");
					break;
				}
				else
				{
					printf("se leyo todo el archivo completo\n");
				}
			}
		}
	}
	fclose(pFile);

    return 1;
}
