#ifndef LISTASIMPENL_H_INCLUDED
#define LISTASIMPENL_H_INCLUDED

struct Nodo{
    void * data;
    Nodo * nextNode;
};
struct ListaSimpEnl{
    int tam;
    Nodo * head;

};


Nodo* newNode(void * data);

ListaSimpEnl* newListSimpEnl();

void linkToNext(Nodo* currentNode, Nodo* nodeToAdd);

void addNodeToList(ListaSimpEnl* list, Nodo* nodeToAdd);

void addDataToList(ListaSimpEnl* list, void* data);

//Node* findNumberByValue(List* list, int numberToRemove);
//
//void removeNode(void* list, void* nodeToRemove);
//
//void removeData(void* list, void* data);







#endif // LISTASIMPENL_H_INCLUDED
