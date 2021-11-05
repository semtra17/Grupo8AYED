#ifndef VINO_H_INCLUDED
#define VINO_H_INCLUDED
#include <string>
#include "ListaSimpEnl.h"
using namespace std;



/**
    Definición del Tipo de Dato para manejo de Vino.
    Atributos:
    * idVino,
    * etiqueta,
    * bodega,
    * segmentoDelVino,
    * varietal,
    * anioCosecha,
    * terroir,

    Axiomas:
    * idVino = identificador del Vino,
    * etiqueta= Etiqueta del vino,
    * bodega= Bodega del Vino,
    * segmentoDelVino = Segmento del vino,
    * varietal = tipo,
    * anioCosecha = año de cosecha,
    * terroir = Tipo de terroir,
*/

/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/
/*--------------------------------*/
struct Vino{

    std::string idVino;
    std::string etiqueta;
    std::string  bodega;
    std::string  segmentoDelVino;
    std::string varietal;
    std::string anioCosecha;
    std::string terroir;

};

//------------------------------------------------------------
//CONSTUCTOR

//PRE: funcion asignada a un puntero de tipo de dato struct Vino
//POST:idVino,etiqueta, bodega, segmentoDelVino, varietal, anioCosecha, terroir seran asignados a cada atributo de Vino
Vino *crearVino(string idVino, string etiqueta, string bodega, string segmentoDelVino, string varietal, string anioCosecha, string terroir);


//Sobrecarga de metodos

//------------------------------------------------------------
//CONSTUCTOR

//PRE: funcion asignada a un puntero de tipo de dato struct Vino
//POST:etiqueta, bodega, segmentoDelVino, varietal, anioCosecha, terroir seran asignados a cada atributo de Vino
Vino *crearVino(string etiqueta, string bodega, string segmentoDelVino, string varietal, string anioCosecha, string terroir);


//POST: puntero a void sera devuelto
//Vino* sera cargado a partir de una linea de archivo de texto
// El mismo sera devuelto como un puntero a void

void* cargarVinoConArchivo(string line);

//PRE: Lista previamente instanciada
//POST: Lista cargada a partir de archivo
//Lista cargada con nodos que contienen struct Vino
void cargarListaVinoDesdeArchivo(ListaSimpEnl* list);

//---------------------------------------------------------------------
//DESTRUCTOR

//PRE: Vino *v debe tener espacio de memoria reservada previamente
//POST: se libera el espacio de la memoria del Vino* v
void borrarVino(Vino *v);

//PRE: Lista debe estar cargada y el idVino debe existir en al lista
//POST Remueve Vino* hallada en la lista
void removeVinoByIdFromList(ListaSimpEnl* list, string idVino);



//------------------------------------------------------------
//GETS

//PRE: "v" debe estar cargado con la funcion crearVino
//POST devuelve el dato de "v" indicado en la respectiva funcion
//Funcion getIdVino solo devolvera el dato idVino si fue inicializado
//con la funcion crearVino que requiere el id del mismo para ser cargado

string getIdVino(Vino *v);
string getEtiqueta(Vino *v);
string getBodega(Vino * v);
string getSegmentoDelVino(Vino *v);
string getVarietal(Vino *v);
string getTerroir(Vino *v);
string getAnioCosecha(Vino *v);

//------------------------------------------------------------
//SETS

//PRE: "v" inicializado vacio, solo se reservo espacio en memoria para el struct
//POST inicializa los valores dependiendo la funcion y el tipo de dato que ingrese en la mis
void setEtiqueta(Vino *v, string etiqueta);
void setBodega(Vino *v, string bodega);
void setIdVino(Vino *v, string idVino);
void setSegmentoDelVino(Vino *v, string segmentoDelVino);
void setVarietal(Vino *v, string varietal);
void setAnioCosecha(Vino *v, string anioCosecha);
void setTerroir(Vino *v, string terroir);


//------------------------------------------------------
//BUSCADOR


//PRE: Lista debe estar cargada y el idVino debe existir en al lista
//POST Devuelve Vino* hallado en la lista
Vino * findVinoById(ListaSimpEnl* listaVino, string idVino);



//------------------------------------------------------------
//UTILIDADES

//PRE: "v" debe estar previamente cargado
//POST muestra por pantalla cada atributo del vino
void printVino(Vino *v);
void printListaVino(ListaSimpEnl* list);






#endif // VINO_H_INCLUDED
