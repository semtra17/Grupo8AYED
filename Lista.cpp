#include "Lista.h"
#include <iostream>
using namespace std;




void printList(List* list)
{
    Node* n = list->head;
    while (n != NULL) {
      cout << n->number << " ";
      n = n->nextNode;
    }
    cout << endl;
}

void showLastNode(List *list){
    cout << list->tail->number << endl;
}

int  bringFirstNumber(List *list ){

    return list->head->number;
}
int  bringLastNumber(List *list ){

    return list->tail->number;
}

Node* newNode(int number){
	Node *node = new Node();
	node->number = number;
    node->nextNode = NULL;
	return node;
}

List* newList(){
	List *list = new List();
	list->tail = NULL;
	list->head = NULL;
	list->tamanio = 0;
	return list;
}

void linkToNext(Node* currentNode, Node* nodeToAdd){
	if (currentNode->nextNode == NULL){
		currentNode->nextNode = nodeToAdd;
		nodeToAdd->previousNode = currentNode;
	}else{
	 	linkToNext(currentNode->nextNode, nodeToAdd);
	}
}

void addNodeToList(List* list, Node* nodeToAdd){
  if(list->head == NULL){
    list->head = nodeToAdd;
    list->tail = nodeToAdd;
    list->tamanio++;
  }else{
    linkToNext(list->head, nodeToAdd);
    list->tail = nodeToAdd;
    list->tamanio++;
  }
}

void addNumberToList(List* list, int numberToAdd){
	Node* node = newNode(numberToAdd);
    addNodeToList(list, node);
}

Node* findNumberByValue(List* list, int numberToRemove){
  Node* n = list->head;
  Node* temp;
  while (n != NULL) {
    if(n->number == numberToRemove){
      temp = n;
    }
    n = n->nextNode;
  }
  return temp;
}

void removeNode(List* list, Node* nodeToRemove){
  Node* tempNextNode = nodeToRemove->nextNode;

  Node* tempPreviousNode = NULL;

  Node* n = list->head;
  while (n != NULL) {
    if(n->nextNode == nodeToRemove){
      tempPreviousNode = n;
    }
    n = n->nextNode;
  }
  tempPreviousNode->nextNode = tempNextNode;
  list->tamanio--;
  delete nodeToRemove;
}

void removeNumber(List* list, int numberToRemove){
  Node* nodeToRemove = findNumberByValue(list, numberToRemove);
  removeNode(list, nodeToRemove);
}

void showListBackToFront(List*list){

    Node* n = list->tail;
        while (n != NULL) {
          cout << n->number << " ";
          n = n->previousNode;
        }
    cout << endl;

};
void ordenarListaAsc(List * lista){

    Node * n = lista->head;
    int number = 0;

    while(n != NULL){
          Node * ns = n->nextNode;
        while(ns != NULL){
            if(n->number < ns->number){
                number = ns->number;
                ns->number = n->number;
                n->number = number;
            }
            ns = ns->nextNode;
        }
        n = n->nextNode;
    }

}





void ordenarListaDes(List * lista){

    Node * n = lista->head;
    int number = 0;

    while(n != NULL){
          Node * ns = n->nextNode;
        while(ns != NULL){
            if(n->number > ns->number){
                number = ns->number;
                ns->number = n->number;
                n->number = number;
            }
            ns = ns->nextNode;
        }
        n = n->nextNode;
    }
}

