#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "input.h"
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

	int opcionesGenerales;
	int respuestaGen;
    int retorno = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do
    {
    	respuestaGen = utn_getnumero(&opcionesGenerales,"1.Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)."
														"\n2.Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)."
														"\n3.Alta de pasajero\n4.Modificar datos de pasajero\n"
    													"5.Baja de pasajero\n6.Listar pasajeros\n7.Ordenar pasajeros"
    													"\n8.Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
    													"9.Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
    													"10.Salir\n"
    													"Elija una opcion: ","no es una opcion valida \n",0,11);
    	if(respuestaGen == 0)
    	{
			switch(opcionesGenerales)
			{
				case 1:
					retorno = controller_loadFromText("data.csv",listaPasajeros);
					switch(retorno)
					{
					case -1:
						printf("\nno se encontro el archivo\n\n");
						break;
					default:
						printf("\ncarga exitosa\n\n");
						break;
					}
					break;
				case 2:
					retorno = controller_loadFromBinary("bin.dat",listaPasajeros);
					switch(retorno)
					{
					case -1:
						printf("\nno se encontro el archivo\n\n");
						break;
					default:
						printf("\ncarga exitosa\n\n");
						break;
					}
					break;
				case 3:
					retorno = controller_addPassenger(listaPasajeros);
					switch(retorno)
					{
					case -1:
						printf("\nno hay datos cargados\n\n");
						break;
					default:
						printf("\nalta exitosa\n\n");
						break;
					}
					break;
				case 4:
					retorno = controller_editPassenger(listaPasajeros);
					switch(retorno)
					{
					case -1:
						printf("\nno hay datos cargados\n\n");
						break;
					default:
						printf("\nmodificacion exitosa\n\n");
						break;
					}
					break;
				case 5:
					retorno = controller_removePassenger(listaPasajeros);
					switch(retorno)
					{
					case -1:
						printf("\nno hay datos cargados\n\n");
						break;
					default:
						printf("\nbaja exitosa\n\n");
						break;
					}
					break;
				case 6:
					retorno = controller_ListPassenger(listaPasajeros);
					switch(retorno)
					{
					case -1:
						printf("\nno hay datos cargados\n\n");
						break;
					default:
						printf("\nlistado exitoso\n\n");
						break;
					}
					break;
				case 7:
					retorno = controller_sortPassenger(listaPasajeros);
					switch(retorno)
					{
					case -1:
						printf("\nno hay datos cargados\n\n");
						break;
					default:
						printf("\nlistado exitoso\n\n");
						break;
					}
					break;
				case 8:
					retorno = controller_saveAsText( "data.csv",listaPasajeros);
					switch(retorno)
					{
					case -1:
						printf("\nno hay datos cargados\n\n");
						break;
					default:
						printf("\nguardado exitoso\n\n");
						break;
					}
					break;
				case 9:
					retorno = controller_saveAsBinary("bin.dat",listaPasajeros);
					switch(retorno)
					{
					case -1:
						printf("\nno hay datos cargados\n\n");
						break;
					default:
						printf("\nguardado exitoso\n\n");
						break;
					}
					break;
			}

        }
    }while(opcionesGenerales != 10);

    return EXIT_SUCCESS;
}

