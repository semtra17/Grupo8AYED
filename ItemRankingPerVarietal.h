#ifndef ITEMRANKINGPERVARIETAL_H_INCLUDED
#define ITEMRANKINGPERVARIETAL_H_INCLUDED


#include "ItemRankingPerVarietal.h"
#include "ListaSimpEnl.h"
#include "ListaDoblEnl.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
/**
    Definición del Tipo de Dato para manejo de Usuario.
    Atributos:
    * nombre,
    * cantidad,



    Axiomas:
    * nombre = string idVino,
    * cantidad = cantidad de veces elegido,

*/

/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/
/*--------------------------------*/

struct ItemRankingPerVarietal{
   string nombre;
   int cantidad;
};


//------------------------------------------------------------
//CONSTUCTOR
//PRE: funcion asignada a un puntero de tipo de dato struct ItemRankingPerVarietal
//POST: nombre, cantidad seran asignados a cada atributo de ItemRankingPerVarietal
ItemRankingPerVarietal* crearItemRankingPerVarietal(string nombre, int cantidad);


//------------------------------------------------------------
//GETS

//PRE: "RegistroVino" debe estar cargado con la funcion crearItemRankingPerVarietal()
//POST devuelve el dato de "getNameItemRankingPerVarietal" indicado en la respectiva funcion
string getNameItemRankingPerVarietal(ItemRankingPerVarietal* i);
//GETS

//PRE: "RegistroVino" debe estar cargado con la funcion crearItemRankingPerVarietal()
//POST devuelve el dato de "getCantidadItemRankingPerVarietal" indicado en la respectiva funcion
int getCantidadItemRankingPerVarietal(ItemRankingPerVarietal* i);
//------------------------------------------------------------
//SETS
//PRE: "ItemRankingPerVarietal" inicializado vacio, solo se reservo espacio en memoria para el struct ItemRankingPerVarietal
//POST inicializa los valores dependiendo la funcion y el tipo de dato que ingrese en la misma
void setNameItemRankingPerVarietal(ItemRankingPerVarietal* i, string name);

//PRE: "ItemRankingPerVarietal" inicializado vacio, solo se reservo espacio en memoria para el struct ItemRankingPerVarietal
//POST inicializa los valores dependiendo la funcion y el tipo de dato que ingrese en la misma
void setCantidadItemRankingPerVarietal(ItemRankingPerVarietal* i, int cantidad);
//------------------------------------------------------------
//DESTRUCTOR

//PRE: Lista debe estar cargada y el ItemRankingPerVarietal debe existir en al lista
//POST Remueve ItemRankingPerVarietal* hallado en la lista
void eliminarItemRankingPerVarietal(ItemRankingPerVarietal *i);

//------------------------------------------------------------
//MAIN FUNCTIONS
//PRE: "listSelecciones" y listVinos debe estar previamente cargado
//POST muestra por pantalla los vinos ordenados por varietales de todas las edades de acuerdo a su popularidad
void rankingVinosTodasLasEdadesPerVarietal(ListaSimpEnl* listSelecciones, ListaSimpEnl* listVinos );
//PRE: "listSelecciones" y listVinos debe estar previamente cargado
//POST muestra por pantalla los vinos ordenados por varietales de edad Antigua de acuerdo a su popularidad
void rankingVinosAntiguosPerVarietal(ListaSimpEnl* listSelecciones, ListaSimpEnl* listVinos );
//PRE: "listSelecciones" y listVinos debe estar previamente cargado
//POST muestra por pantalla los vinos ordenados por varietales de edad Joven de acuerdo a su popularidad
void rankingVinosJovenesPerVarietal(ListaSimpEnl* listSelecciones, ListaSimpEnl* listVinos );
//PRE: "listSelecciones" y listVinos debe estar previamente cargado
//POST muestra por pantalla los vinos ordenados por varietales de edad Mediana de acuerdo a su popularidad
void rankingVinosMedianosPerVarietal(ListaSimpEnl* listSelecciones, ListaSimpEnl* listVinos );



//------------------------------------------------------------
//UTILIDADES
void printNodoRankingPerVarietal(NodoDobl *nr);
void printListaRankingPerVarietales(ListaDoblEnl* list);
void printItemRankingPerVarietal(ItemRankingPerVarietal *i);
#endif // ITEMRANKINGPERVARIETAL_H_INCLUDED
