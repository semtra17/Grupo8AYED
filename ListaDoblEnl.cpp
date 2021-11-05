#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include <sstream>
#include "ListaDoblEnl.h"
/******************************************************************************/
/* Implementacion de Primitivas */
/* ===================== CONSTRUCTOR =====================*/

NodoDobl* newNodeDobl(void * data){

	NodoDobl *nodoDobl = new NodoDobl();
	nodoDobl->data = data;
    nodoDobl->nextNode = NULL;
    nodoDobl->previousNode = NULL;
	return nodoDobl;


}

ListaDoblEnl* newListaDoblEnl(){
	ListaDoblEnl *list = new ListaDoblEnl();
	list->head = NULL;
	list->tail = NULL;
	list->tam = 0;
	return list;
}

/* ===================== ADDITION =====================*/
void linkToNext(NodoDobl* currentNode, NodoDobl* nodeToAdd){
	if (currentNode->nextNode == NULL){
		currentNode->nextNode = nodeToAdd;
		nodeToAdd->previousNode = currentNode;
		nodeToAdd->index = currentNode->index + 1;

	}else{
	 	linkToNext(currentNode->nextNode, nodeToAdd);
	}
}

void addNodeToListDoblEnl(ListaDoblEnl* list, NodoDobl* nodeToAdd){
      if(list->head == NULL){
        list->head = nodeToAdd;
        list->tail = nodeToAdd;
        nodeToAdd->index = 0;
      }else{
        linkToNext(list->head, nodeToAdd);
        list->tail = nodeToAdd;
      }
}

void addDataToListDoblEnl(ListaDoblEnl* list, void* data){
	NodoDobl* node = newNodeDobl(data);
    addNodeToListDoblEnl(list, node);
    list->tam++;
}

/* ===================== DESTRUCTOR =====================*/
void vaciarListaDobEnl(ListaDoblEnl * list){
    NodoDobl * nodo = list->head;
    NodoDobl * nextNode = nodo->nextNode;
    while(nodo != NULL){
        nodo->previousNode = NULL;
        delete(nodo);
        nodo = nextNode;
       if(nextNode != NULL){
        nextNode = nextNode->nextNode;

       }

    }
    delete(list->head);
    delete(list->tail);
    list->head = NULL;
    list->tail = NULL;

}
/* ===================== GET =====================*/
NodoDobl* getIndex(ListaDoblEnl * lista, int index){
    NodoDobl* n = lista->head;
    NodoDobl* temp = NULL;
    while (n != NULL) {
        if(n->index == index){
            return n;
        }
        n = n->nextNode;
      }
        return temp;

}
