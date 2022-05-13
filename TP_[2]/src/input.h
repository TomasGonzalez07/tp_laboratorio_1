/*
 * input.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef INPUT_H_
#define INPUT_H_

int utn_getnumero(int* pResultado,char* mensaje, char* mensajeError,int minimo, int maximo);

///-----------------------------------------------------------------------------------------///

int esNumerico(char str[]);
int esNumericoFlotante(char str[]);

///-----------------------------------------------------------------------------------------///

int getInt(int*);

///-----------------------------------------------------------------------------------------///

void getString(char[], char*,char*);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para tomar un numero entero
/// @param mensaje para el ingreso
/// @param mensaje en caso de error
/// @param minimo
/// @param maximo
/// @return retorna el numero entero ingresado
int getNumberInt(char*,char*,int,int);

///-----------------------------------------------------------------------------------------///

///  @brief funcion para tomar un flotante
/// @param mensaje para el ingreso
/// @param mensaje en caso de rror
/// @param minimo
/// @param maximo
/// @return retorna numero flotante ingresado
float getNumberFloat(char* mensaje, char* mensajeError,int minimo, int maximo);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para tomar un caracter
/// @param
/// @param mensaje para el ingreso
/// @param mensaje en caso de error
/// @param minimo
/// @param maximo
/// @return retorna 0 en caso de ser valido el dato ingresado
int getCaracter(char* pResultado,char* mensaje, char* mensajeError,char minimo, char maximo);

///-----------------------------------------------------------------------------------------///

///  @brief funcion para cargar vector con enteros
/// @param numeros enteros recibidos en el vector
/// @param tamaño del vector
void CargarVectorEnteros(int numerosRecibidos[],int size);

///-----------------------------------------------------------------------------------------///

///  @brief funcion para cargar vector con flotantes
/// @param numeros flotantes recibidos
/// @param tamaño del vector
void CargarVectorFlotantes(float numerosRecibidos[],int size);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para recorrer y mostrar vector
/// @param numeros recibidos
/// @param tamaño del vector
void MostrarVector(int numerosRecibidos[],int size);

///-----------------------------------------------------------------------------------------///

/// @brief calcula el promedio entre dos numeros
/// @param numero uno
/// @param numero dos
/// @return retorna promedio final
float CalcularPromedio(int,int);

///-----------------------------------------------------------------------------------------///

///  @brief funcion para determinar paridad
/// @param numero recibido
/// @return retorna 0 en caso de ser impar y 1 en caso de ser par
int DeterminarParidad(int numeroRecibido);

///-----------------------------------------------------------------------------------------///

/// @brief determina si es positivo o negativo
/// @param numero a determinar
/// @param signo
/// @return retorna positivo o negativo
int DeterminarSigno(int,int);

///-----------------------------------------------------------------------------------------///

/// @brief mostrar bumero entero
/// @param mostrar el mensaje
/// @param el resultado entero
void MostrarResultadoEntero(char*,int);

///-----------------------------------------------------------------------------------------///

/// @brief mostrar numero flotante
/// @param mostrar el mensaje
/// @param el resultado flotante
void MostrarResultadoFlotante(char*,float);

///-----------------------------------------------------------------------------------------///

#endif /* INPUT_H_ */
