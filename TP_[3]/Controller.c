#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "PassengerData.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	FILE* pArchivo;
	pArchivo = fopen(path,"r");

	if((pArchivo = fopen(path, "r")) != NULL)
	{
		parser_PassengerFromText(pArchivo ,pArrayListPassenger);
		rtn = 1;
	}
    return rtn;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	FILE* pArchivo;

	pArchivo = fopen(path,"rb");
	if(pArchivo != NULL)
	{
		parser_PassengerFromBinary(pArchivo,pArrayListPassenger);
		rtn = 1;

		fclose(pArchivo);
	}

    return rtn;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;

	int orden = AltaPasajero(pArrayListPassenger);
	if( orden == 1)
	{
		rtn = 1;
	}

    return rtn;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int orden = EditarPasajero(pArrayListPassenger);
	if( orden == 1)
	{
		rtn = 1;
	}

	return rtn;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
		int orden = RemoverPasajero(pArrayListPassenger);
		if( orden == 1)
		{
			rtn = 1;
		}
		return rtn;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno =-1;
	Passenger* unPasajero;

	int cantidad = ll_len(pArrayListPassenger);

	if(cantidad > 0)
	{
		for(int i = 0; i < cantidad;i++)
		{
			unPasajero = (Passenger*) ll_get(pArrayListPassenger,i);
			Passenger_PrintOne(unPasajero);
		}
		retorno = 1;
	}

    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	int orden = OrdenarPasajeros(pArrayListPassenger);
	if( orden == 1)
	{
		rtn = 1;
	}

    return rtn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	Passenger* unPasajero;
	int rtn = -1;

	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[20];
	char codigoVuelo[20];
	char estadoVuelo[20];

	pArchivo = fopen(path,"w");

	 if(pArchivo != NULL && pArrayListPassenger != NULL)
	 {
		 for(int i=0; i<ll_len(pArrayListPassenger); i++)
		 {
			 unPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			 Passenger_getId(unPasajero,&id);
			 Passenger_getNombre(unPasajero,nombre);
			 Passenger_getApellido(unPasajero,apellido);
			 Passenger_getPrecio(unPasajero,&precio);
			 Passenger_getCodigoVuelo(unPasajero,codigoVuelo);
			 Passenger_getTipoPasajero(unPasajero,tipoPasajero);
			 Passenger_getEstadoVuelo(unPasajero,estadoVuelo);
			 fprintf(pArchivo,"%d,%s,%s,%f,%s,%s,%s\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
			 rtn = 1;
		 }
	 }
	 fclose(pArchivo);
	 return rtn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	Passenger* unPasajero;
	int rtn = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	 {
		pArchivo = fopen(path,"wb");

		 for(int i=0; i<ll_len(pArrayListPassenger); i++)
		 {
			 unPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			 fwrite(unPasajero,sizeof(Passenger),1,pArchivo);
		 }
		 fclose(pArchivo);
		 rtn = 1;
	 }

    return rtn;
}

