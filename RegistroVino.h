#ifndef REGISTROVINO_H_INCLUDED
#define REGISTROVINO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "ListaDoblEnl.h"
#include "ListaSimpEnl.h"


/**
    Definición del Tipo de Dato para manejo de Usuario.
    Atributos:
    * idRegistroVino,
    * cantidadSeleccionado,



    Axiomas:
    * idRegistroVino = identificador de la idRegistroVino ,
    * cantidadSeleccionado = Cantidad de veces que fue seleccionado el vino,

*/

/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/
/*--------------------------------*/

using namespace std;
struct RegistroVino{

    string idRegistroVino;
    int cantidadSeleccionado;
};

/**
    Definición del Tipo de Dato para manejo de Usuario.
    Atributos:
    * bodega,



    Axiomas:
    * bodega = nombre de la bodega,

*/

/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/
/*--------------------------------*/

struct RegistroBodega {
    string bodega;
};




//------------------------------------------------------------
//CONSTUCTOR

//PRE: funcion asignada a un puntero de tipo de dato struct RegistroVino
//POST: idVino, cantidadSeleccionado seran asignados a cada atributo de RegistroVino

RegistroVino * crearRegistroVino(string idVino, int cantidadSeleccionado);


//PRE: ListaVinos previamente instanciada
//POST: Lista cargada a partir de popularidad
//Lista cargada con nodos que contienen struct RegistroVino
ListaDoblEnl * rankingVinosPerYear(ListaSimpEnl* listaVinos, int year);


//GETS

//PRE: "RegistroVino" debe estar cargado con la funcion crearRegistroVino()
//POST devuelve el dato de "usuario" indicado en la respectiva funcion

string getIdRegistroVino(RegistroVino* rv);
int getCantidadRegistroVino(RegistroVino* rv);

//SETS

//PRE: "RegistroVino" inicializado vacio, solo se reservo espacio en memoria para el struct RegistroVino
//POST inicializa los valores dependiendo la funcion y el tipo de dato que ingrese en la misma
void setIdRegistroVino(RegistroVino *rv, string idRegistroVino);
void setIdRegistroVino(RegistroVino *rv, int cantidadSeleccionado);


//---------------------------------------------------------------------
//DESTRUCTOR

//PRE: Lista debe estar cargada y el RegistroVino debe existir en al lista
//POST Remueve RegistroVino* hallado en la lista
void eliminarRegistroVino(RegistroVino *rv);


//---------------------------------------------------------------------
//ORDENAMIENTO
//PRE: ListaDoblEnl Debe estar creada y cargada con structs RegistroVinos
//POST Lista ordenada de acuerdo a popularidad de menor a mayor

void ordenarRegistrosAsc(ListaDoblEnl * lr);
//ORDENAMIENTO
//PRE: ListaDoblEnl Debe estar creada y cargada con structs RegistroVinos
//POST Lista ordenada de acuerdo a popularidad de mayor a menor

void ordenarRegistrosDes(ListaDoblEnl * lr);


//UTILIDADES

//PRE: "RegistroVino" debe estar previamente cargado
//POST muestra por pantalla cada atributo del RegistroVino

void printRegistroVino(RegistroVino *rv);


//PRE: "RegistroVino" debe estar previamente cargado
//POST muestra por pantalla cada atributo del RegistroVino ordenado por popularidad de mayor a menor
void printRankingVinosPerYearDes(ListaDoblEnl* listaRegistros);

//PRE: "ListaDoblEnl" debe estar previamente cargado
//POST muestra por pantalla cada atributo del RegistroVino ordenado por popularidad de menor a mayor
void printRankingVinosPerYearAsc(ListaDoblEnl* listaRegistros);

//PRE: "ListaDoblEnl" debe estar previamente cargado
//POST muestra por pantalla cada atributo del RegistroVino de cada nodo perteneciente a la lista
void printListaRegistrosVinos(ListaDoblEnl* listaRegistros);

//PRE: "NodoDobl" debe estar previamente cargado con alguna Struct RegistroVino
//POST muestra por pantalla cada atributo del RegistroVino
void printNodoRegistroVino(NodoDobl *rv);



//PRE: "ListaSimpEnl" y listVinos  debe estar previamente cargado
//POST muestra por pantalla cada atributo del Bodega ordenado por popularidad de menor a mayor de un año especifico
void printRankingBodegasPerYearAsc(ListaSimpEnl* listaSelecciones, ListaSimpEnl * listVinos, int year);

//PRE: "ListaSimpEnl" y listVinos  debe estar previamente cargado
//POST muestra por pantalla cada atributo del Bodega ordenado por popularidad de mayor a menor de un año especifico
void printRankingBodegasPerYearDes(ListaSimpEnl* listaSelecciones, ListaSimpEnl * listVinos, int year);

void printListaBodegaAsc(ListaDoblEnl* list);
void printListaBodegaDes(ListaDoblEnl* list);

#endif // REGISTROVINO_H_INCLUDED
