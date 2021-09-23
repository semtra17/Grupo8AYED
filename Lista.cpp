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
}

Node* newNode(int number){
	Node *node = new Node();
	node->number = number;
    node->nextNode = NULL;
	return node;
}

List* newList(){
	List *list = new List();
	list->head = NULL;
	return list;
}

void linkToNext(Node* currentNode, Node* nodeToAdd){
	if (currentNode->nextNode == NULL){
		currentNode->nextNode = nodeToAdd;
	}else{
	 	linkToNext(currentNode->nextNode, nodeToAdd);
	}
}

void addNodeToList(List* list, Node* nodeToAdd){
  if(list->head == NULL){
    list->head = nodeToAdd;
  }else{
    linkToNext(list->head, nodeToAdd);
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
  delete nodeToRemove;
}

void removeNumber(List* list, int numberToRemove){
  Node* nodeToRemove = findNumberByValue(list, numberToRemove);
//  cout << nodeToRemove->number << " ";
  removeNode(list, nodeToRemove);
}
