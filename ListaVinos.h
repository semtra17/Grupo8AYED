#ifndef LISTAVINOS_H_INCLUDED
#define LISTAVINOS_H_INCLUDED
#include "Vino.h"


struct NodoVino{
    Vino* elementoVino;
    NodoVino* sigVino;
};


struct ListaVinos{

    NodoVino* primerVino;
    int tamanioLista;
};

void printListaVinos(ListaVinos* list);

void cargarListaVinosDesdeArchivo(ListaVinos* list);

NodoVino* cargarNodoVinoConArchivo(string line);

NodoVino* nuevoNodoVino(Vino* v);

ListaVinos* nuevaListaVinos();

void linkToNextNodoVino(NodoVino* currentNode, NodoVino* nodeToAdd);

void agregarNodoVino(ListaVinos* list, NodoVino* nodeToAdd);

void agregarVino(ListaVinos* list, Vino * vinoToAdd);

NodoVino* findNodoVinoById(ListaVinos* list, string idVIno);
Vino* findVinoById(ListaVinos* list, string idVIno);

void removeNode(ListaVinos* list, NodoVino* nodeToRemove);

void removeVino(ListaVinos* list, Vino *v);



#endif // LISTAVINOS_H_INCLUDED
