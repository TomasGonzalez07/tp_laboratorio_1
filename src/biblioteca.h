/*
 * biblioteca.h
 * Author: Tomas Gonzalez
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/// @brief Funcion que permite establecer un menu.
/// @param Int* guarda el numero ingresado por el usuario.
/// @param Char* mensaje que muestra las opciones del menu.
/// @param Char* mensaje de error en caso de haber introducido un numero invalido.
/// @param Int numero minimo que se puede ingresar.
/// @param Int numero maximo que se puede ingresar.
/// @return Retorna 0 en caso de que el numero ingresado sea valido y -1 en caso de que sea invalido.
int utn_getnumero(int*,char*,char*,int,int);

//==============================================================================================================================

/// @brief Funcion que permite recibir la cantidad de kilometros.
/// @param Char* mensaje que indica que dato ingresar.
/// @param Char* mensaje en caso de que se ingrese un numero negativo.
/// @return Retorna los kilometros ingresados.
int RecibirKm(char*,char*);

//==============================================================================================================================

/// @brief Funcion que permite recibir el precio de los vuelos.
/// @param Char* mensaje que indica que dato ingresar.
/// @param Char* mensaje en caso de que se ingrese un numero negativo.
/// @return Retorna el precio ingresado.
int RecibirPrecioVuelos(char*,char*);

//==============================================================================================================================

/// @brief Funcion que permite calcular el precio del vuelo con tarjeta de debito(descuento del %10).
/// @param Int precio del vuelo a calcular.
/// @return Retorna el precio ingresado con el descuento agregado.
float CalcularTarjetaDebito(int);

//==============================================================================================================================

/// @brief Funcion que permite calcular el precio del vuelo con tarjeta de credito(interes del %25).
/// @param Int precio del vuelo a calcular.
/// @return Retorna el precio ingresado con el interes agregado.
float CalcularTarjetaCredito(int);

//==============================================================================================================================

/// @brief Funcion que permite calcular el precio del vuelo en bitcoin.
/// @param int precio del vuelo a calcular.
/// @return Retorna el precio ingresado en bitcoin.
float CalcularBitcoin(int);

//==============================================================================================================================

/// @brief Funcion que permite calcular el precio del viaje por kilometro.
/// @param Int precio del vuelo a calcular.
/// @param Int cantidad de kilometros a calcular.
/// @return Retorna el precio del viaje por kilometro.
float CalcularPrecioUnitario(int,int);

//==============================================================================================================================

/// @brief Funcion que permite calcular la diferencia de precios entre ambas aerolineas.
/// @param Int precio de la primera aerolinea a calcular.
/// @param Int precio de la segunda aerolinea a calcular.
/// @return Retorna la diferencia de precios.
float CalcularDiferenciaPreciosIngresados(int,int);

//==============================================================================================================================

/// @brief Funcion que permite mostrar los resultados enteros.
/// @param Char* mensaje para especificar que dato se muestra.
/// @param Int valor del dato que se va a mostrar junto con el mensaje.
void MostrarResultadoEntero(char*,int);

//==============================================================================================================================

/// @brief Funcion que permite mostrar los resultados flotantes.
/// @param Char* mensaje para especificar que dato se muestra.
/// @param Float valor del dato que se va a mostrar junto con el mensaje.
void MostrarResultadoFlotante(char*,float);

//==============================================================================================================================

#endif /* BIBLIOTECA_H_ */
