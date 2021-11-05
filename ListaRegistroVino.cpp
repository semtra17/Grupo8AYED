#include "ListaRegistroVino.h"
#include "SeleccionMensual.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "Funciones.h"
#include "RegistroVino.h"
using namespace std;

ListaRegistroVino* newListaRegistroVino(){
	ListaRegistroVino *list = new ListaRegistroVino();
	list->primerNodoRegistroVino = NULL;
	list->ultimoNodoRegistroVino = NULL;
	list->tamanio = 0;
	return list;
}

NodoRegistroVino* newNodoRegistroVino(string idVino){
	NodoRegistroVino *node = new NodoRegistroVino();
	RegistroVino * rv = crearRegistroVino(idVino, 1);
	node->registroVino = rv;
    node->SiguienteNodoRegistroVino = NULL;
    node->AnteriorNodoRegistroVino = NULL;
	return node;
}


void linkToNext(NodoRegistroVino* currentNode, NodoRegistroVino* nodeToAdd){
	if (currentNode->SiguienteNodoRegistroVino == NULL){
		currentNode->SiguienteNodoRegistroVino = nodeToAdd;
		nodeToAdd->AnteriorNodoRegistroVino = currentNode;
	}else{
	 	linkToNext(currentNode->SiguienteNodoRegistroVino, nodeToAdd);
	}
}

void addNodeToList(ListaRegistroVino* list, NodoRegistroVino* nodeToAdd){
  if(list->primerNodoRegistroVino == NULL){
    list->primerNodoRegistroVino = nodeToAdd;
    list->ultimoNodoRegistroVino = nodeToAdd;
    list->tamanio++;
  }else{
    linkToNext(list->primerNodoRegistroVino, nodeToAdd);
    list->ultimoNodoRegistroVino = nodeToAdd;
    list->tamanio++;
  }
}

void agregarNodoRegistro(ListaRegistroVino* list, string idVino){
  NodoRegistroVino* nuevoNodoRegistroVinoNdo = newNodoRegistroVino(idVino);
  addNodeToList(list, nuevoNodoRegistroVinoNdo);
}


NodoRegistroVino* buscarRegistroVinoPorId(ListaRegistroVino* list, string idVino){
    NodoRegistroVino* n = list->primerNodoRegistroVino;
    NodoRegistroVino* temp = NULL;
    while (n != NULL) {
      if(getIdRegistroVino(n->registroVino) == idVino){
        temp = n;
      }
      n = n->SiguienteNodoRegistroVino;
    }
    return temp;
}

void contarVino(ListaRegistroVino* list, string idVino){
  NodoRegistroVino* nodoRegistroVino = buscarRegistroVinoPorId(list, idVino);
  if(nodoRegistroVino != NULL){
    nodoRegistroVino->registroVino->cantidadSeleccionado++;
  }else{
    agregarNodoRegistro(list, idVino);
  }
}

ListaRegistroVino * rankingVinosPerYearDes(ListaSelecciones* list, int year){
 ListaRegistroVino* listaRegistroVino = newListaRegistroVino();
  NodoSeleccion* node = list->primerSeleccion;

  while(node != NULL){
    SeleccionMensual* seleccionMensual = node->elementoSeleccion;
    if(seleccionMensual->anio == year){
      for(int i = 0; i < 5; i++){
        contarVino(listaRegistroVino, seleccionMensual->idsVinos[i]);
      }
    }
    node = node->sigSeleccion;
  }
    ordenarRegistrosAsc(listaRegistroVino);
    return listaRegistroVino;

}

ListaRegistroVino * rankingVinosPerYearAsc(ListaSelecciones* list, int year){

  ListaRegistroVino* listaRegistroVino = newListaRegistroVino();
  NodoSeleccion* node = list->primerSeleccion;

  while(node != NULL){
    SeleccionMensual* seleccionMensual = node->elementoSeleccion;
    if(seleccionMensual->anio == year){
      for(int i = 0; i <= 5; i++){
        contarVino(listaRegistroVino, seleccionMensual->idsVinos[i]);
      }
    }
    node = node->sigSeleccion;
  }

    ordenarRegistrosDes(listaRegistroVino);
    return listaRegistroVino;

}






void ordenarRegistrosAsc(ListaRegistroVino * lr){
    NodoRegistroVino * nr = lr->primerNodoRegistroVino;


    while(nr != NULL){
       NodoRegistroVino * nrs = nr->SiguienteNodoRegistroVino;
        while(nrs != NULL){
            if(nr->registroVino->cantidadSeleccionado < nrs->registroVino->cantidadSeleccionado){
                RegistroVino * auxRegVino = nrs->registroVino;
                nrs->registroVino = nr->registroVino;
                nr->registroVino = auxRegVino;
            }
            nrs = nrs->SiguienteNodoRegistroVino;
        }
        nr = nr->SiguienteNodoRegistroVino;
    }


}
void ordenarRegistrosDes(ListaRegistroVino * lr){

    NodoRegistroVino * nr = lr->primerNodoRegistroVino;
    while(nr != NULL){
    NodoRegistroVino * nrs = nr->SiguienteNodoRegistroVino;

        while(nrs != NULL){
            if(nr->registroVino->cantidadSeleccionado > nrs->registroVino->cantidadSeleccionado){
                RegistroVino * auxRegVino = nrs->registroVino;
                nrs->registroVino = nr->registroVino;
                nr->registroVino = auxRegVino;
            }
            nrs = nrs->SiguienteNodoRegistroVino;
        }
        nr = nr->SiguienteNodoRegistroVino;
    }

}


RegistroVino *obtenerUltimoRegistroVino(ListaRegistroVino * lr){
    return lr->ultimoNodoRegistroVino->registroVino;
}

RegistroVino * obtenerPrimerRegistroVino(ListaRegistroVino * lr){
    return lr->primerNodoRegistroVino->registroVino;
}

void printRankingVinosPerYearAsc(ListaRegistroVino* list){
          cout << "==========================" << endl;
    cout << "Ranking de Vinos Ascendente" << endl;

    NodoRegistroVino* sm = list->primerNodoRegistroVino;
    int i = 1;
    while (sm != NULL) {
        printNodoRegistroVino(sm);
        cout <<  "Puesto: " << i++ << endl;
        sm = sm->SiguienteNodoRegistroVino;
    }
}
void printRankingVinosPerYearDes(ListaRegistroVino* list){

    cout << "==========================" << endl;
    cout << "Ranking de Vinos Descendente" << endl;
    NodoRegistroVino* sm = list->primerNodoRegistroVino;
    int i =  list->tamanio;
    while (sm != NULL) {

        printNodoRegistroVino(sm);
        cout <<  "Puesto: " << i-- << endl;
        sm = sm->SiguienteNodoRegistroVino;
    }
}
void printListaRegistrosVinos(ListaRegistroVino* list){

   NodoRegistroVino* sm = list->primerNodoRegistroVino;
    while (sm != NULL) {
        printNodoRegistroVino(sm);
        sm = sm->SiguienteNodoRegistroVino;
    }
}


void printNodoRegistroVino(NodoRegistroVino *nr){
   printRegistroVino(nr->registroVino);
}



