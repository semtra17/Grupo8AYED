#include "ListaRegistroVino.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "Funciones.h"
#include "ListaVinos.h"
#include "Vino.h"
#include "ItemRankingPerVarietal.h"
using namespace std;

struct NodoRankingPerVarietal{
    ItemRankingPerVarietal* itemRankingPerVarietal;
    NodoRankingPerVarietal* siguienteNodo;
    NodoRankingPerVarietal* anteriorNodo;
};

struct ListaRankingPerVarietales
{
    int size;
	NodoRankingPerVarietal* primerNodo;
	NodoRankingPerVarietal* ultimoNodo;
};

ListaRankingPerVarietales* newListaRankingPerVarietales(){
    ListaRankingPerVarietales* list = new ListaRankingPerVarietales();
	list->primerNodo = NULL;
	list->ultimoNodo = NULL;
	list->size = 0;
	return list;
}

NodoRankingPerVarietal* newNodoRankingPerVarietal(Vino* vino){
	NodoRankingPerVarietal *node = new NodoRankingPerVarietal();
	ItemRankingPerVarietal * rv = crearItemRankingPerVarietal(vino->idVino, 1);
	node->itemRankingPerVarietal = rv;
    node->siguienteNodo = NULL;
    node->anteriorNodo = NULL;
	return node;
}
void linkToNext2(NodoRankingPerVarietal* currentNode, NodoRankingPerVarietal* nodeToAdd){
	if (currentNode->siguienteNodo == NULL){
		currentNode->siguienteNodo = nodeToAdd;
		nodeToAdd->anteriorNodo = currentNode;
	}else{
	 	linkToNext2(currentNode->siguienteNodo, nodeToAdd);
	}
}

void addNodeToList(ListaRankingPerVarietales* list, NodoRankingPerVarietal* nodeToAdd){
  if(list->primerNodo == NULL){
    list->primerNodo = nodeToAdd;
    list->ultimoNodo = nodeToAdd;
    list->size++;
  }else{
    linkToNext2(list->primerNodo, nodeToAdd);
    list->ultimoNodo = nodeToAdd;
    list->size++;
  }
}

void agregarItemRankingPerVarietal(ListaRankingPerVarietales* list, Vino* vino){
  NodoRankingPerVarietal* nuevoNodoRankingPerVarietal = newNodoRankingPerVarietal(vino);
  addNodeToList(list, nuevoNodoRankingPerVarietal);
}

NodoRankingPerVarietal* buscarRegistroVinoPorId(ListaRankingPerVarietales* list, string idVino){
    NodoRankingPerVarietal* n = list->primerNodo;
    NodoRankingPerVarietal* temp = NULL;
    while (n != NULL) {
      if(n->itemRankingPerVarietal->nombre == idVino){
        temp = n;
      }
      n = n->siguienteNodo;
    }
    return temp;
}

void contarVinoPerVarietal(ListaRankingPerVarietales* list, Vino* vino){
    NodoRankingPerVarietal* nodoItemRankingPerVarietal = buscarRegistroVinoPorId(list, vino->idVino);
    if(nodoItemRankingPerVarietal != NULL){
        nodoItemRankingPerVarietal->itemRankingPerVarietal->cantidad++;
    }else{
        agregarItemRankingPerVarietal(list, vino);
    }
}

void printNodoRankingPerVarietal(NodoRankingPerVarietal *nr){
   printItemRankingPerVarietal(nr->itemRankingPerVarietal);
}

void printListaRankingPerVarietales(ListaRankingPerVarietales* list){

   NodoRankingPerVarietal* sm = list->primerNodo;
    while (sm != NULL) {
        printNodoRankingPerVarietal(sm);
        sm = sm->siguienteNodo;
    }
}

void rankingVinosPerVarietal(ListaSelecciones* listaSelecciones, ListaVinos* listaVinos){
    ListaRankingPerVarietales* rankingVinosJovenes = newListaRankingPerVarietales();
    ListaRankingPerVarietales* rankingVinosMedianos = newListaRankingPerVarietales();
    ListaRankingPerVarietales* rankingVinosViejos = newListaRankingPerVarietales();


    NodoSeleccion* currentNode = listaSelecciones->primerSeleccion;
    while(currentNode != NULL){
        //tambien hay que recorrer el array de IDs
        for(int i = 0; i < 5; i++){
            Vino* vino = findVinoById(listaVinos, currentNode->elementoSeleccion->idsVinos[i]);
            //printVino(vino);
            int anioCosecha;
            stringstream ss;
            ss << vino->anioCosecha;
            ss >> anioCosecha;
            int edad = 2021 - anioCosecha;
            if(edad < 30){
                contarVinoPerVarietal(rankingVinosJovenes, vino);
                //cout << "chico" << endl;
            }
            if(edad >30 && edad < 50){
                contarVinoPerVarietal(rankingVinosMedianos, vino);
                cout << "mediano" << endl;
            }
            if(edad > 50){
                contarVinoPerVarietal(rankingVinosViejos, vino);
                cout << "grande" << endl;
            }
        }

        currentNode = currentNode->sigSeleccion;
        //recorrer la lista
        //busca el vino en el catalogo
        //checkear la edad
        //crear el nodo y ponerlo en la lista que corresponde
        //ordenar las tres listas
    }
    printListaRankingPerVarietales(rankingVinosJovenes);
    printListaRankingPerVarietales(rankingVinosMedianos);
    printListaRankingPerVarietales(rankingVinosViejos);
}
