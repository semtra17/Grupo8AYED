#include "ListaSimpEnl.h"
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include <sstream>

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

void linkToNext(Nodo* currentNode, Nodo* nodeToAdd){
	if (currentNode->nextNode == NULL){
		currentNode->nextNode = nodeToAdd;
	}else{
	 	linkToNext(currentNode->nextNode, nodeToAdd);
	}
}

void addNodeToList(ListaSimpEnl* list, Nodo* nodeToAdd){
      if(list->head == NULL){
        list->head = nodeToAdd;
      }else{
        linkToNext(list->head, nodeToAdd);
      }
}

void addDataToList(ListaSimpEnl* list, void* data){
	Nodo* node = newNode(data);
    addNodeToList(list, node);
    list->tam++;
}
