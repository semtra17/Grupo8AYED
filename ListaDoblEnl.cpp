#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include <sstream>
#include "ListaDoblEnl.h"


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

void linkToNext(NodoDobl* currentNode, NodoDobl* nodeToAdd){
	if (currentNode->nextNode == NULL){
		currentNode->nextNode = nodeToAdd;
		nodeToAdd->previousNode = currentNode;
	}else{
	 	linkToNext(currentNode->nextNode, nodeToAdd);
	}
}

void addNodeToListDoblEnl(ListaDoblEnl* list, NodoDobl* nodeToAdd){
      if(list->head == NULL){
        list->head = nodeToAdd;
        list->tail = nodeToAdd;
      }else{
        linkToNext(list->head, nodeToAdd);
      }
}

void addDataToListDoblEnl(ListaDoblEnl* list, void* data){
	NodoDobl* node = newNodeDobl(data);
    addNodeToListDoblEnl(list, node);
    list->tam++;
}
