#ifndef LISTAREGISTROVINO_H_INCLUDED
#define LISTAREGISTROVINO_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <string>
#include "ListaSelecciones.h"
#include "RegistroVino.h"

using namespace std;
struct NodoRegistroVino{
    RegistroVino * registroVino;
    NodoRegistroVino* SiguienteNodoRegistroVino;
    NodoRegistroVino* AnteriorNodoRegistroVino;
};

struct ListaRegistroVino
{
    int tamanio;
	NodoRegistroVino* primerNodoRegistroVino;
	NodoRegistroVino* ultimoNodoRegistroVino;
};



ListaRegistroVino* newListaRegistroVino();
NodoRegistroVino* newNodoRegistroVino(string idVino);

NodoRegistroVino* buscarRegristoVinoPorId(ListaRegistroVino* list, string idVino);

void linkToNext(NodoRegistroVino* currentNode, NodoRegistroVino* nodeToAdd);
void addNodeToList(ListaRegistroVino* list, NodoRegistroVino* nodeToAdd);
void agregarNodoRegistro(ListaRegistroVino* list, string idVino);
void contarVino(ListaRegistroVino* list, string idVino);

void sortRankingVinos(ListaRegistroVino* list);



ListaRegistroVino * rankingVinosPerYearDes(ListaSelecciones* list, int year);
ListaRegistroVino * rankingVinosPerYearAsc(ListaSelecciones* list, int year);

void ordenarRegistrosAsc(ListaRegistroVino * lr);
void ordenarRegistrosDes(ListaRegistroVino * lr);



RegistroVino * obtenerUltimoRegistroVino(ListaRegistroVino * lr);
RegistroVino * obtenerPrimerRegistroVino(ListaRegistroVino * lr);

//PRINTS
void printNodoRegistroVino(NodoRegistroVino *nr);
void printRankingVinosPerYearDes(ListaRegistroVino* list);
void printRankingVinosPerYearAsc(ListaRegistroVino* list);

void printListaRegistrosVinos(ListaRegistroVino* list);
#endif // LISTAREGISTROVINO_H_INCLUDED
