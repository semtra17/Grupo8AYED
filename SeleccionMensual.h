#ifndef SELECCIONMENSUAL_H_INCLUDED
#define SELECCIONMENSUAL_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

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


//---------------------------------------------------------------------
//DESTRUCTOR

//PRE: SeleccionMensual *s debe tener espacio de memoria reservada previamente
//POST: se libera el espacio de memoria ocupado por SeleccionMensual *s

void borrarSeleccionMen(SeleccionMensual* s);

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

//UTILIDADES

//PRE: "s" debe estar previamente cargado
//POST muestra por pantalla cada atributo del s

void printSelecMen(SeleccionMensual *s);

//PRE: "idsVinos" debe estar previamente cargado
//POST muestra por pantalla los ids alojados en el arreglo de string
void printIdsVinos(string idsVinos[6]);


#endif // SELECCIONMENSUAL_H_INCLUDED
