#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

struct Node
{
	int number;
	Node *nextNode;
	Node *previousNode;
};

struct List
{
    int tamanio;
	Node *head;
	Node *tail;
};


void printList(List* list);
void showListBackToFront(List*list);

Node* newNode(int number);

List* newList();

void linkToNext(Node* currentNode, Node* nodeToAdd);

void addNodeToList(List* list, Node* nodeToAdd);

void addNumberToList(List* list, int numberToAdd);

Node* findNumberByValue(List* list, int numberToRemove);

void removeNode(List* list, Node* nodeToRemove);

void removeNumber(List* list, int numberToRemove);

void showFirstNode(List* list);
void showLastNode(List* list);

int bringFirstNumber (List* list);
int bringLastNumber (List* list);
void ordenarListaAsc(List * lista);
void ordenarListaDes(List * lista);




#endif // LISTA_H_INCLUDED
