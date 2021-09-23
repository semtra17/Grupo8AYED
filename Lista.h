#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

struct Node
{
	int number;
	Node *nextNode;
};

struct List
{
	Node *head;
};


void printList(List* list);

Node* newNode(int number);

List* newList();

void linkToNext(Node* currentNode, Node* nodeToAdd);

void addNodeToList(List* list, Node* nodeToAdd);

void addNumberToList(List* list, int numberToAdd);

Node* findNumberByValue(List* list, int numberToRemove);

void removeNode(List* list, Node* nodeToRemove);

void removeNumber(List* list, int numberToRemove);





#endif // LISTA_H_INCLUDED
