#ifndef LISTABODEGA_H_INCLUDED
#define LISTABODEGA_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <string>
#include "ListaSelecciones.h"
#include "ListaVinos.h"


using namespace std;
struct NodoBodega{

    string nombreBodega;
    NodoBodega* SiguienteNodoBodega;
    NodoBodega* AnteriorNodoBodega;
};

struct ListaBodega
{
    int tamanio;
	NodoBodega* primerNodoBodega;
	NodoBodega* ultimoNodoBodega;
};



ListaBodega* newListaBodega();
NodoBodega* newNodoBodega(string nombreBodega);

NodoBodega* buscarBodegaPorNombre(ListaBodega* list, string idBodega);

void linkToNext(NodoBodega* currentNode, NodoBodega* nodeToAdd);
void addNodeToList(ListaBodega* list, NodoBodega* nodeToAdd);
void agregarNodoRegistro(ListaBodega* list, string nombreBodega);


void printRankingBodegasPerYearDes(ListaSelecciones* list,ListaVinos * listVinos, int year);
void printRankingBodegasPerYearAsc(ListaSelecciones* list,ListaVinos * listVinos, int year);





NodoBodega * obtenerUltimoRegistroBodega(ListaBodega * lb);
NodoBodega * obtenerPrimerRegistroBodega(ListaBodega * lb);

//PRINTS

void printListaBodegaAsc(ListaBodega* list);
void printListaBodegaDes(ListaBodega* list);
void printNodoBodega(NodoBodega *nb);
void printListaBodega(ListaBodega* list);

#endif // LISTABODEGA_H_INCLUDED
