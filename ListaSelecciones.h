#ifndef LISTASELECCIONES_H_INCLUDED
#define LISTASELECCIONES_H_INCLUDED

#include "SeleccionMensual.h"


struct NodoSeleccion{
    SeleccionMensual* elementoSeleccion;
    NodoSeleccion* sigSeleccion;
};


struct ListaSelecciones{

    NodoSeleccion* primerSeleccion;
    int tamanioLista;
};

void printListaSelecciones(ListaSelecciones* list);

void cargarListaSeleccionesDesdeArchivo(ListaSelecciones* list);

NodoSeleccion* cargarNodoSeleccionConArchivo(string line);

NodoSeleccion* nuevoNodoSeleccion(SeleccionMensual* s);

ListaSelecciones* nuevaListaSelecciones();

void linkToNextNodoSeleccion(NodoSeleccion* currentNode, NodoSeleccion* nodeToAdd);

void agregarNodoSeleccion(ListaSelecciones* list, NodoSeleccion* nodeToAdd);

void agregarSeleccion(ListaSelecciones* list, SeleccionMensual * seleccionToAdd);

NodoSeleccion* findSelcMenById(ListaSelecciones* list, string idSeleccion);

void removeNode(ListaSelecciones* list, NodoSeleccion* nodeToRemove);

void removeSelecMen(ListaSelecciones* list, SeleccionMensual *s);


#endif // LISTASELECCIONES_H_INCLUDED
