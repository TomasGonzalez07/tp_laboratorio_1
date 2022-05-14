/*
 * passenger.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "ArrayPassenger.h"

static int idIncremental = 1;
static int passenger_obtenerID();
static int passenger_obtenerID()
{
	return idIncremental++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int initPassengers(struct Passenger listPassenger[],int len)
{
	int rtn = -1;
	int i;

	if(listPassenger != NULL)
	{
		if(len >= 0)
		{
			for(i = 0; i<len; i++)
			{
				listPassenger[i].isEmpty = LIBRE;
			}
			rtn = 0;
		}
	}
	return rtn;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int addPassenger(struct Passenger listPassenger[],int len)
{
	int rtn = -1;
	int index;
	struct Passenger auxiliar;

	if(listPassenger != NULL)
	{
		if(len >= 0)
		{
			index = passenger_findEmptySpace(listPassenger,len);
			if(index >= 0)
			{
				auxiliar = Passenger_cargarUno();
				auxiliar.id = passenger_obtenerID();
				auxiliar.isEmpty = OCUPADO;

				listPassenger[index] = auxiliar;
				rtn = 0;
			}
		}
	}
	return rtn;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int findPassengerById(struct Passenger listPassenger[],int len,int id)
{
	int rtn = -1;
	int index;

	for(index = 0; index <len; index++)
	{
		if(listPassenger[index].isEmpty == OCUPADO && listPassenger[index].id == id)
		{
			rtn = id;
		}
	}

	return rtn;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int removePassenger(struct Passenger listPassenger[],int len,int id)
{
	int rtn = -1;

	printf("ingrese id del pasajero que esta buscando: ");
	scanf("%d", &id);
	findPassengerById(listPassenger,len,id);

	for(int i=0; i<len; i++)
	{
		if(listPassenger[i].isEmpty == OCUPADO && listPassenger[i].id == id)
		{
			listPassenger[i].isEmpty = LIBRE;
			rtn = 0;
			break;
		}
	}

	return rtn;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int sortPassengersByName(struct Passenger listPassenger[], int len,int order)
{
	int rtn = -1;
	struct Passenger auxiliarPassenger;

	if(order == 0)
	{
		rtn = 0;
		for(int i = 0; i < len-1; i++)
		{
			for(int j = i+1; j<len; j++)
			{
				if(strcmp(listPassenger[i].lastName,listPassenger[j].lastName)<0)
				{
					auxiliarPassenger = listPassenger[i];
					listPassenger[i] = listPassenger[j];
					listPassenger[j] = auxiliarPassenger;
				}
			}
		}
	}

	else
	{
		rtn = 0;
		for(int i = 0; i < len-1; i++)
		{
			for(int j = i+1; j<len; j++)
			{
				if(strcmp(listPassenger[i].lastName,listPassenger[j].lastName)>0)
				{
					auxiliarPassenger = listPassenger[i];
					listPassenger[i] = listPassenger[j];
					listPassenger[j] = auxiliarPassenger;

				}
			}
		}
	}

	return rtn;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int printPassengers(struct Passenger listPassenger[],int len)
{

	int rtn = -1;
	int i;

	int anchoColumnaid = -5;
    int anchoColumnaNombres = -20;
    int anchoColumnaApellidos = -20;
    int anchoColumnaPrecios = -20;
    int anchoColumnaCodigos = -20;
    int anchoColumnaTipo = -20;
    int anchoColumnaEstadoVuelo = -20;

    printf("+-----+--------------------+--------------------+--------------------+--------------------+--------------------+--------------------+\n");
 	printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n", anchoColumnaid, "ID",
 												anchoColumnaNombres,"NOMBRE",
 												anchoColumnaApellidos,"APELLIDO",
 												anchoColumnaPrecios,"PRECIO",
 												anchoColumnaCodigos,"CODIGO DE VUELO",
 												anchoColumnaTipo,"TIPO PASAJERO",
 												anchoColumnaEstadoVuelo,"ESTADO DEL VUELO");
    printf("+-----+--------------------+--------------------+--------------------+--------------------+--------------------+--------------------+\n");

	if(listPassenger != NULL)
	{
		if(len >= 0)
		{
			for(i = 0; i<len; i++)
			{
				if(listPassenger[i].isEmpty == OCUPADO)
				{
					informarPasajero(listPassenger[i]);
				}
			}
			rtn = 0;
		}
	}
	return rtn;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int sortPassengerByFlyCode(struct Passenger listPassenger[],int len,int order)
{
	int rtn = -1;
	struct Passenger auxiliarPassenger;

	if(order == 0)
	{
		rtn = 0;
		for(int i = 0; i < len-1; i++)
		{
			for(int j = i+1; j<len; j++)
			{
				if(strcmp(listPassenger[i].flycode,listPassenger[j].flycode)<0)
				{
					auxiliarPassenger = listPassenger[i];
					listPassenger[i] = listPassenger[j];
					listPassenger[j] = auxiliarPassenger;
				}
			}
		}
	}
	else
	{
		rtn = 0;
		for(int i = 0; i < len-1; i++)
		{
			for(int j = i+1; j<len; j++)
			{
				if(strcmp(listPassenger[i].flycode,listPassenger[j].flycode)>0)
				{
					auxiliarPassenger = listPassenger[i];
					listPassenger[i] = listPassenger[j];
					listPassenger[j] = auxiliarPassenger;
				}
			}
		}
	}

	return rtn;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

struct Passenger Passenger_cargarUno()
{
	struct Passenger aPassenger;

	getString(aPassenger.name, "Ingrese el nombre: ","Error\nReingrese nombre: ");

	getString(aPassenger.lastName, "Ingrese el  apellido: ","Error\nReingrese apellido: ");

	aPassenger.price = getNumberFloat("Ingrese precio: ","Error\nReingrese precio: " ,0, 1000000);

	getString(aPassenger.flycode, "Ingrese codigo de vuelo: ","Error\nReingrese codigo de vuelo: ");

	aPassenger.typePassenger = getNumberInt("Ingrese tipo de pasajero(0(PRIMERA CLASE)1(SEGUNDA CLASE)2(ECONOMICO): ",
										    "Error\nReingrese tipo de pasajero (0(PRIMERA CLASE)1(SEGUNDA CLASE)2(ECONOMICO): ",0, 1);

	aPassenger.statusFlight = getNumberInt("Ingrese estado de vuelo(0(INACTIVO)1(ACTIVO)2(DEMORADO)): ",
			                               "Error\nReingrese estado de vuelo(0(INACTIVO)1(ACTIVO)2(DEMORADO)): ",0,1);

	return aPassenger;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int sortPassengersByTypePassenger(struct Passenger listPassenger[],int len,int order)
{
	struct Passenger auxiliarPassenger;
	int rtn = -1;
	if(order == 0)
	{
		rtn = 0;
		for(int i = 0; i < len-1; i++)
		{
			for(int j = i+1; j<len; j++)
			{
				if(listPassenger[i].typePassenger > listPassenger[j].typePassenger)
				{
					auxiliarPassenger = listPassenger[i];
					listPassenger[i] = listPassenger[j];
					listPassenger[j] = auxiliarPassenger;
				}
				else
				{
					if((listPassenger[i].typePassenger == listPassenger[j].typePassenger)>0)
					{
						auxiliarPassenger = listPassenger[i];
						listPassenger[i] = listPassenger[j];
						listPassenger[j] = auxiliarPassenger;
					}
				}
			}
		}
	}
	else
	{
		rtn = 0;
		for(int i = 0; i < len-1; i++)
		{
			for(int j = i+1; j<len; j++)
			{
				if(listPassenger[i].typePassenger < listPassenger[j].typePassenger)
				{
					auxiliarPassenger = listPassenger[i];
					listPassenger[i] = listPassenger[j];
					listPassenger[j] = auxiliarPassenger;
				}
				else
				{
					if((listPassenger[i].typePassenger == listPassenger[j].typePassenger)>0)
					{
						auxiliarPassenger = listPassenger[i];
						listPassenger[i] = listPassenger[j];
						listPassenger[j] = auxiliarPassenger;
					}
				}
			}
		}
	}

	return rtn;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int sortPassengerByStatusFlight(struct Passenger listPassenger[],int len)
{
	struct Passenger auxiliarPassenger;
	int rtn = -1;

		for(int i = 0; i < len-1; i++)
	    {
			for(int j = i+1; j<len; j++)
			{
				if(listPassenger[i].statusFlight > listPassenger[j].statusFlight)
				{
					auxiliarPassenger = listPassenger[i];
					listPassenger[i] = listPassenger[j];
					listPassenger[j] = auxiliarPassenger;
					rtn = 0;
				}
				else
				{
					if((listPassenger[i].statusFlight == listPassenger[j].statusFlight)>0)
					{
						auxiliarPassenger = listPassenger[i];
						listPassenger[i] = listPassenger[j];
						listPassenger[j] = auxiliarPassenger;
						rtn = 0;
					}
				}
		     }
	      }
	return rtn;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int passenger_findEmptySpace(struct Passenger listPassenger[],int len)
{
	int rtn = -1;
	int index;

	if(listPassenger != NULL)
	{
		if(len >= 0)
		{
			for(index = 0; index <len; index++)
			{
				if(listPassenger[index].isEmpty == LIBRE)
				{
					rtn = index;
					break;
				}
			}
		}
	}

	return rtn;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int passenger_findOcSpace(struct Passenger listPassenger[],int len)
{
	int rtn = -1;
	int index;

	if(listPassenger != NULL)
	{
		if(len >= 0)
		{
			for(index = 0; index <1; index++)
			{
				if(listPassenger[index].isEmpty == OCUPADO)
				{
					rtn = index;
					break;
				}
			}
		}
	}

	return rtn;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int modificarPasajero(struct Passenger listPassenger[],int len,int id)
{
	int rtn;
	int opciones;
	int respuesta;

	printf("ingrese id del pasajero que esta buscando: ");
	scanf("%d", &id);

	findPassengerById(listPassenger,len,id);

	for(int i=0; i<len; i++)
	{
		if(listPassenger[i].id == id)
		{

			 do{
				respuesta = utn_getnumero(&opciones,"1.Modificar Nombre\n2.Modificar Apellido\n3.Modificar precio\n4.Modificar tipo de pasajero\n"
													"5.Modificar codigo de vuelo\n6.Modificar estado de vuelo\n7.Salir\n", "no es una opcion valida \n",0, 7);
				if(respuesta == 0)
				{
					switch(opciones)
					{
					case 1:
						getString(listPassenger[i].name, "Ingrese el nuevo nombre: ","Error\nReingrese nuevo nombre: ");
						rtn = 1;
						break;
					case 2:
						getString(listPassenger[i].lastName, "Ingrese nuevo apellido: ","Error\nReingrese nuevo apellido: ");
						rtn = 1;
						break;
					case 3:
						listPassenger[i].price = getNumberFloat("Ingrese nuevo precio: ","Error\nReingrese nuevo precio: " ,0, 1000000);
						rtn = 1;
						break;
					case 4:
						listPassenger[i].typePassenger = getNumberInt("Ingrese tipo de pasajero(0(PRIMERA CLASE)1(SEGUNDA CLASE)2(ECONOMICO)): ",
																	 "Error\nReingrese tipo de pasajero(0(PRIMERA CLASE)1(SEGUNDA CLASE)2(ECONOMICO): ",0,2);
						rtn = 1;
						break;
					case 5:
						getString(listPassenger[i].flycode, "Ingrese nuevo codigo de vuelo: ","Error\nReingrese nuevo codigo de vuelo: ");
						rtn = 1;
						break;
					case 6:
						listPassenger[i].statusFlight = getNumberInt("Ingrese estado de vuelo(0(INACTIVO)1(ACTIVO)2(DEMORADO)): ",
																	 "Error\nReingrese estado de vuelo(0(INACTIVO)1(ACTIVO)2(DEMORADO): ",0,1);
					break;
					}
				}
			 }while(opciones != 7);

			break;
		}
		else
		{
			rtn = -1;
		}
	}
	return rtn;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void cargaForzadaDatos(struct Passenger listPassenger[])
{
	struct Passenger auxiliar[10]= {{1,"Pedro","Aveiro",800.5,"hodoha",1,0,OCUPADO},
									{2,"Giselle","Perez",300.5,"zodada",0,1,OCUPADO},
									{3,"Cristiano","Santos",800.5,"codapña",1,1,OCUPADO},
									{4,"Ariel","Gomez",300.5,"codaoua",2,1,OCUPADO},
									{5,"Salvador","Ramirez",300.5,"godaha",2,0,OCUPADO},
									{6,"Maite","Gonzalez",800.5,"codqhl",0,1,OCUPADO},
									{7,"Leonidas","Elstner",800.5,"codqhlg",1,1,OCUPADO},
									{8,"Constantino","Giovagnonni",300.5,"codghg",2,1,OCUPADO},
									{9,"Matias","Coppola",800.5,"zodfil",1,0,OCUPADO},
									{10,"Cesar","Libermann",300.5,"codqnl",2,0,OCUPADO}};

		for(int i = 0 ; i<10 ;i++)
		{

			listPassenger[i]=auxiliar[i];
		}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void informarPasajero(struct Passenger aPassenger)
{
	  int anchoColumnaid = -5;
	  int anchoColumnaNombres = -20;
	  int anchoColumnaApellidos = -20;
	  int anchoColumnaPrecios = -20;
	  int anchoColumnaCodigos = -20;
	  int anchoColumnaTipo = -20;
	  int anchoColumnaEstadoVuelo = -20;

	  char tipoPasajero[15];
	  switch(aPassenger.typePassenger)
	  	  {
	  	  	  case 0:
	  		  strcpy( tipoPasajero,"PRIMERA CLASE");
	  		  break;
	  		  case 1:
	  		  strcpy( tipoPasajero,"SEGUNDA CLASE");
	  		  break;
	  		  case 2:
	  		  strcpy( tipoPasajero,"ECONOMICO");
	  		  break;
	  	  }
	  char estadoVuelo[15];
	  switch(aPassenger.statusFlight)
	  {
	  	  case 0:
		  strcpy(estadoVuelo,"INACTIVO");
		  break;
		  case 1:
		  strcpy(estadoVuelo,"ACTIVO");
		  break;
		  case 2:
		  strcpy(estadoVuelo,"DEMORADO");
		  break;
	  }

	printf("|%*d|%*s|%*s|%*.2f|%*s|%*s|%*s|\n", anchoColumnaid, aPassenger.id,
													anchoColumnaNombres,aPassenger.name,
													anchoColumnaApellidos,aPassenger.lastName,
													anchoColumnaPrecios,aPassenger.price,
													anchoColumnaCodigos,aPassenger.flycode,
													anchoColumnaTipo,tipoPasajero,
													anchoColumnaEstadoVuelo,estadoVuelo);
	  printf("+-----+--------------------+--------------------+--------------------+--------------------+--------------------+--------------------+\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void printTotalPromedioPrecios(struct Passenger listPassenger[],int len)
{
	float acumuladorPrecios = 0;
	int contador = 0;
	int contadorsupPromedio = 0;
	float promedio;

		for(int x = 0; x<len; x++)
		{
			if(listPassenger[x].isEmpty == OCUPADO)
			{
				contador++;
				acumuladorPrecios = acumuladorPrecios + listPassenger[x].price;
		    }
		}
	promedio = acumuladorPrecios/contador;
	for(int x = 0; x<len; x++)
	{
		if(listPassenger[x].isEmpty == OCUPADO)
		{
			if(listPassenger[x].price > promedio)
			{
				contadorsupPromedio++;
			}
		}
	}
	printf("El total de los precios ingresados es de %.2f.\nEl promedio de los mismos es de %.2f.\n"
			"Superan el promedio %d pasajeros.\n\n",
			acumuladorPrecios,promedio,contadorsupPromedio);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int informeDatos(struct Passenger listPassenger[],int len)
{
	int rtn =-1;
	int opciones;
	int respuesta;

	for(int i=0; i<len; i++)
	{
		 do{
			respuesta = utn_getnumero(&opciones,"1.Listado por apellido y tipo de pasajero\n2.Informe total de precios con promedio y cantidad de pasajeros que superan el mismo\n"
												"3.Listado de pasajeros por código de vuelo y estado de vuelo ‘ACTIVO’\n4..Salir\n", "no es una opcion valida \n",0, 4);
			if(respuesta == 0)
			{
				switch(opciones)
				{
				case 1:
					sortPassengersByName(listPassenger,len,0);
					sortPassengersByTypePassenger(listPassenger,len,0);
					printPassengers(listPassenger,len);
					rtn = 1;
					break;
				case 2:
					printTotalPromedioPrecios(listPassenger,len);
					rtn = 1;
					break;
				case 3:
					sortPassengerByFlyCode(listPassenger,len,0);
					sortPassengerByStatusFlight(listPassenger,len);
					printPassengers(listPassenger,len);
					rtn = 1;
					break;
				}
			}
		 }while(opciones != 4);

		break;
	}

	return rtn;
}
