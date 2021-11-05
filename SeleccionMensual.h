#ifndef SELECCIONMENSUAL_H_INCLUDED
#define SELECCIONMENSUAL_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <string>
#include "ListaSimpEnl.h"

using namespace std;

/**
    Definición del Tipo de Dato para manejo de Usuario.
    Atributos:
    * idSelecMen,
    * mes,
    * anio,
    * idsVinos,


    Axiomas:
    * idSelecMen = string,
    * mes= string,
    * idsVinos= string[],
    * anio = int,

*/

/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/
/*--------------------------------*/

struct SeleccionMensual{
    std::string idSelecMen;
    std::string mes;
    int anio;
    std::string idsVinos[6];
};
//------------------------------------------------------------
//CONSTUCTOR

//PRE: funcion asignada a un puntero de tipo de dato struct SeleccionMensual
//POST: idSelecMen, mes, anio, idsVinos[] seran asignados a cada atributo de SeleccionMensual

SeleccionMensual * crearSeleccionMensual(string idSelecMen, string mes, int anio, string idsVinos[6]);

//SOBRECARGA DE METODOS

//------------------------------------------------------------
//CONSTUCTOR

//PRE: funcion asignada a un puntero de tipo de dato struct SeleccionMensual
//POST: mes, anio, idsVinos[] seran asignados a cada atributo de SeleccionMensual
SeleccionMensual * crearSeleccionMensual( string mes, int anio, string idsVinos[6]);

//PRE: line debe entrar por parametro
//POST: puntero a void sera devuelto
//SeleccionMensual* sera cargado a partir de una linea de archivo de texto
// El mismo sera devuelto como un puntero a void
void* cargarSelMenConArchivo(string line);

//PRE: Lista previamente instanciada
//POST: Lista cargada a partir de archivo
//Lista cargada con nodos que contienen struct SeleccionMensual
void cargarListaSelDesdeArchivo(ListaSimpEnl* list);




//---------------------------------------------------------------------
//DESTRUCTOR

//PRE: SeleccionMensual *s debe tener espacio de memoria reservada previamente
//POST: se libera el espacio de memoria ocupado por SeleccionMensual *s

void borrarSeleccionMen(SeleccionMensual* s);


//PRE: Lista debe estar cargada y el idSelec debe existir en al lista
//POST Remueve SeleccionMensual* hallada en la lista
void removeSelMenByIdFromList(ListaSimpEnl* list, string idSelec);

//GETS

//PRE: "s" debe estar cargado con la funcion crearSeleccionMen
//POST devuelve el dato de "s" indicado en la respectiva funcion
//Funcion getIdSelecMen solo devolvera el dato id_usuario si fue inicializado con la funcion
//crear que requiere el id del mismo para ser cargado
string getIdSelecMen(SeleccionMensual * s);
int getAnioSelecMen(SeleccionMensual *s);
string getMesSelecMen(SeleccionMensual *s);
string *getIdsVinos(SeleccionMensual *s);


//SETS

//PRE: "s" inicializado vacio, solo se reservo espacio en memoria para el struct
//POST inicializa los valores dependiendo la funcion y el tipo de dato que ingrese en la misma

void setIdSelecMen(SeleccionMensual *s,string idSelecMen);
void setMesSelecMen(SeleccionMensual *s, string mes);
void setAnioSelecMen(SeleccionMensual *s,int anio);
void setIdsVinos(SeleccionMensual *s,string idsVinos[6]);


//------------------------------------------------------
//BUSCADOR

//PRE: Lista debe estar cargada y el idSelec debe existir en al lista
//POST Devuelve SeleccionMensual* hallada en la lista

SeleccionMensual * findSelecMenById(ListaSimpEnl* list, string idSelec);



//UTILIDADES

//PRE: "s" debe estar previamente cargado
//POST muestra por pantalla cada atributo del s

void printSelecMen(SeleccionMensual *s);

//PRE: "idsVinos" debe estar previamente cargado
//POST muestra por pantalla los ids alojados en el arreglo de string
void printIdsVinos(string idsVinos[6]);

//PRE: Lista cargada
//POST Imprime por pantalla datos pertenecientes a la lista
void printListaSelecMen(ListaSimpEnl* list);


#endif // SELECCIONMENSUAL_H_INCLUDED
