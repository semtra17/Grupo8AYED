#include "ListaSimpEnl.h"
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include <sstream>

/******************************************************************************/
/* Implementacion de Primitivas */
/* ===================== CONSTRUCTOR =====================*/
Nodo* newNode(void * data){

	Nodo *nodo = new Nodo();
	nodo->data = data;
    nodo->nextNode = NULL;
	return nodo;


}

ListaSimpEnl* newListSimpEnl(){
	ListaSimpEnl *list = new ListaSimpEnl();
	list->head = NULL;
	list->tam = 0;
	return list;
}



/* ===================== ADDITION =====================*/

void linkToNext(Nodo* currentNode, Nodo* nodeToAdd){
	if (currentNode->nextNode == NULL){
		currentNode->nextNode = nodeToAdd;
		nodeToAdd->index = nodeToAdd->index + 1;
	}else{
	 	linkToNext(currentNode->nextNode, nodeToAdd);
	}
}

void addNodeToList(ListaSimpEnl* list, Nodo* nodeToAdd){
      if(list->head == NULL){
        list->head = nodeToAdd;
        nodeToAdd->index = 0;
      }else{
        linkToNext(list->head, nodeToAdd);
      }
}

void addDataToList(ListaSimpEnl* list, void* data){
	Nodo* node = newNode(data);
    addNodeToList(list, node);
    list->tam++;
}

/* ===================== DESTRUCTOR =====================*/
void vaciarListaSimpEnl(ListaSimpEnl * list){
    Nodo * nodo = list->head;
    Nodo * nextNode = nodo->nextNode;
    while(nodo != NULL){
        delete(nodo);
        nodo = nextNode;
       if(nextNode != NULL){
        nextNode = nextNode->nextNode;

       }

    }
    delete(list->head);
    list->head = NULL;
}


/* ===================== GET =====================*/
Nodo* getIndex(ListaSimpEnl * lista, int index){
    Nodo* n = lista->head;
    Nodo* temp = NULL;
    while (n != NULL) {
        if(n->index == index){
            return n;
        }
        n = n->nextNode;
      }
        return temp;

}

