#ifndef LISTAVINOS_H_INCLUDED
#define LISTAVINOS_H_INCLUDED
#include "Vino.h"
struct NodoVino{
    Vino* elementoVino;
    NodoVino* siguienteVIno;
};


struct ListaVino{

    NodoVino *primerVino;
    int tamanioLista;
};

void printListaVinos(ListaVino* list);
void cargarListaVinoDesdeArchivo(ListaVino* list);

NodoVino* nuevoNodoVino(Vino* vino);

ListaVino* nuevaListaVino();

void linkToNextNodoVino(NodoVino* currentNode, NodoVino* nodeToAdd);

void agregarNodoVino(ListaVino* list, NodoVino* nodeToAdd);

void agregarVino(ListaVino* list, Vino * usuarioToAdd);

NodoVino* findVinoById(ListaVino* list, int idVino);

void removeNodeVino(ListaVino* list, NodoVino* nodeToRemove);

void removeVino(ListaVino* list, int idVino);




#endif // LISTAVINOS_H_INCLUDED
