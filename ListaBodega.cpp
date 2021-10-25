#include "ListaBodega.h"
#include "ListaSelecciones.h"
#include "ListaVinos.h"
#include "ListaRegistroVino.h"
using namespace std;



ListaBodega* newListaBodega(){
	ListaBodega *list = new ListaBodega();
	list->primerNodoBodega = NULL;
	list->ultimoNodoBodega = NULL;
	list->tamanio = 0;
	return list;
}

NodoBodega* newNodoBodega(string nombreBodega){
	NodoBodega *node = new NodoBodega();
	node->nombreBodega = nombreBodega;
    node->SiguienteNodoBodega = NULL;
    node->AnteriorNodoBodega = NULL;
	return node;
}


void linkToNext(NodoBodega* currentNode, NodoBodega* nodeToAdd){
	if (currentNode->SiguienteNodoBodega == NULL){
		currentNode->SiguienteNodoBodega = nodeToAdd;
		nodeToAdd->AnteriorNodoBodega = currentNode;
	}else{
	 	linkToNext(currentNode->SiguienteNodoBodega, nodeToAdd);
	}
}

void addNodeToList(ListaBodega* list, NodoBodega* nodeToAdd){
  if(list->primerNodoBodega == NULL){
    list->primerNodoBodega = nodeToAdd;
    list->ultimoNodoBodega = nodeToAdd;
    list->tamanio++;
  }else{
    linkToNext(list->primerNodoBodega, nodeToAdd);
    list->ultimoNodoBodega = nodeToAdd;
    list->tamanio++;
  }
}

void agregarNodoBodega(ListaBodega* list, string nombreBodega){
  NodoBodega* nuevoNodoBodegaNdo = newNodoBodega(nombreBodega);
  addNodeToList(list, nuevoNodoBodegaNdo);
}


NodoBodega* buscarBodegaPorNombre(ListaBodega* list, string nombreBodega){
    NodoBodega* n = list->primerNodoBodega;
    NodoBodega* temp = NULL;
    while (n != NULL) {
      if(n->nombreBodega == nombreBodega){
        temp = n;
      }
      n = n->SiguienteNodoBodega;
    }
    return temp;
}




void printRankingBodegasPerYearAsc(ListaSelecciones* list,ListaVinos * listVinos, int year){
  ListaRegistroVino * lrv = rankingVinosPerYearAsc(list,year);
  ListaBodega* listaBodega = newListaBodega();
  NodoRegistroVino* node = lrv->primerNodoRegistroVino;

  while(node != NULL){
    Vino * v = findVinoById(listVinos,node->registroVino->idRegistroVino);
    agregarNodoBodega(listaBodega, v->bodega);

    node = node->SiguienteNodoRegistroVino;
  }
    cout << "==========================" << endl;
    cout << "Ranking de Bodegas Ascendente" << endl;
    printListaBodegaAsc(listaBodega);
}



void printRankingBodegasPerYearDes(ListaSelecciones* list,ListaVinos * listVinos, int year){
   ListaRegistroVino * lrv = rankingVinosPerYearDes(list,year);
  ListaBodega* listaBodega = newListaBodega();
  NodoRegistroVino* node = lrv->primerNodoRegistroVino;

  while(node != NULL){
    Vino * v = findVinoById(listVinos,node->registroVino->idRegistroVino);
    agregarNodoBodega(listaBodega, v->bodega);

    node = node->SiguienteNodoRegistroVino;
  }
    cout << "==========================" << endl;
    cout << "Ranking de Bodegas Descendente" << endl;
    printListaBodegaDes(listaBodega);
}




NodoBodega* obtenerUltimaBodega(ListaBodega * lr){
    return lr->ultimoNodoBodega;
}

NodoBodega * obtenerPrimerBodega(ListaBodega * lr){
    return lr->primerNodoBodega;
}
void printListaBodegaAsc(ListaBodega* list){
    NodoBodega* sm = list->primerNodoBodega;
     int i = 1;
    while (sm != NULL) {
        cout << "Puesto: " << i++ << endl;
        printNodoBodega(sm);
        sm = sm->SiguienteNodoBodega;
         cout << "---------------------------" << endl;
    }
}
void printListaBodegaDes(ListaBodega* list){
    NodoBodega* sm = list->primerNodoBodega;
    int i = list->tamanio;
    while (sm != NULL) {
        cout << "Puesto: " << i-- << endl;
        printNodoBodega(sm);
        sm = sm->SiguienteNodoBodega;
        cout << "---------------------------" << endl;
    }
}

void printListaBodega(ListaBodega* list){
    NodoBodega* sm = list->primerNodoBodega;
    while (sm != NULL) {
        printNodoBodega(sm);
        sm = sm->SiguienteNodoBodega;
    }
}

void printNodoBodega(NodoBodega *nr){
   cout << "Bodega: " << nr->nombreBodega << endl;
}



