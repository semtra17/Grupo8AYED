#ifndef LISTADOBLENL_H_INCLUDED
#define LISTADOBLENL_H_INCLUDED

struct NodoDobl{
    void * data;
    NodoDobl * nextNode;
    NodoDobl * previousNode;
};
struct ListaDoblEnl{
    int tam;
    NodoDobl * head;
    NodoDobl * tail;

};


NodoDobl* newNodeDobl(void * data);

ListaDoblEnl* newListaDoblEnl();

void linkToNext(NodoDobl* currentNode, NodoDobl* nodeToAdd);

void addNodeToListDoblEnl(ListaDoblEnl* list, NodoDobl* nodeToAdd);

void addDataToListDoblEnl(ListaDoblEnl* list, void* data);

#endif // LISTADOBLENL_H_INCLUDED
