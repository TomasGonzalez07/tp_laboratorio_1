/*
 * validaciones.c
 *
 *  Created on: 3 jun 2022
 *      Author: User
 */

#include "validaciones.h"

int esEnteroValido(char cadena[])
{
    int longitud = strlen(cadena);
    int rtn = 1;
     int i;

    // Quitar espacios, saltos de l�nea, etc�tera
    while (longitud > 0 && isspace(cadena[longitud - 1]))
    {
    	 longitud--;
    }

    if (longitud <= 0)
    	{
    		rtn = 0;
    	}

    for (i = 0; i < longitud; ++i)
    {
        // En caso de que sea un gui�n, y que no est� al inicio, no es v�lido
        if (cadena[i] == '-' && i > 0)
        {
            rtn = 0;
        }
        // Si no es d�gito, tampoco es v�lido
        if (!isdigit(cadena[i]) && cadena[i] != '-')
        {
            rtn = 0;
        }
    }
    return rtn;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int esFlotanteValido(char *cadena)
{
    int longitud = strlen(cadena);
    int rtn = 1;
    int i;
    int haEncontradoElPunto = 0;
    // Quitar espacios, saltos de l�nea, etc�tera
    while (longitud > 0 && isspace(cadena[longitud - 1]))
    {
    	longitud--;
    }

    if (longitud <= 0)
    	{
    		rtn = 0;
    	}

    for (i = 0; i < longitud; ++i)
    {
        // En caso de que sea un gui�n, y que no est� al inicio, no es v�lido
        if (cadena[i] == '-' && i > 0)
        {
        	rtn = 0;
        }
        // El punto solo puede aparecer una vez
        if (cadena[i] == '.')
        {
            // Si ya lo ha encontrado antes, entonces no es v�lido
            if (haEncontradoElPunto)
            {
            	rtn = 0;
            }
            else
            {
                haEncontradoElPunto = 1;
            }
        }
        // Si no es d�gito, tampoco es v�lido
        if (!isdigit(cadena[i]) && cadena[i] != '-' && cadena[i] != '.')
        {
        	rtn = 0;
        }
    }
    return rtn;
}
