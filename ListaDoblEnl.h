#ifndef LISTADOBLENL_H_INCLUDED
#define LISTADOBLENL_H_INCLUDED

/**
    Definición del Tipo de Dato para manejo de Nodo.
    Atributos:
    * index,
    * data,
    * nextNode,
    * previousNode,

    Axiomas:
    * index = int
    * data = void *
    * nextNode = struct Nodo
    * previousNode = struct Nodo
*/

/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/
/*--------------------------------*/

struct NodoDobl{
    int index;
    void * data;
    NodoDobl * nextNode;
    NodoDobl * previousNode;
};

/**
    Definición del Tipo de Dato para manejo de Nodo.
    Atributos:
    * index,
    * data,
    * nextNode,
   * previousNode,

    Axiomas:
    * index = int
    * data = void *
    * nextNode = struct Nodo
     * previousNode = struct Nodo
*/

/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/
/*--------------------------------*/
struct ListaDoblEnl{
    int tam;
    NodoDobl * head;
    NodoDobl * tail;

};

/*-------CONSTRUCTOR-------*/

/*
  PRE : El Nodo no debe haber sido creado.
  POST: El Nodo queda creado y preparado para ser usado.
  El nextNodo queda setteado en NULL.
  El previousNode queda setteado en NULL;
  La data queda setteado con la data entrante por parametro;
  El index queda setteado en 0;
*/
NodoDobl* newNodeDobl(void * data);

/*
  PRE : La ListaSimEnl no debe haber sido creada.
  POST: La ListaSimEnl queda creada y preparada para ser usada.
  El head queda setteado en NULL.
  El tail queda setteado en NULL.
  El tam queda setteado en 0;
*/

ListaDoblEnl* newListaDoblEnl();


/*
  PRE : El currentNode debe pertener a una ListSimEnl o obligatoriamente ya creado e instanciado con newNodeDobl().
  POST: Nodos correctamentes enlazados.
  El currentNode->nextNode queda setteado a nodeToAdd.
    El nodeToAdd->previous ahora apuntara al currentNode.
  El index queda setteado en nodeToAdd sera igual al currentNode->index + 1;
*/

void linkToNext(NodoDobl* currentNode, NodoDobl* nodeToAdd);
/*
  PRE : La ListaSimEnl debe haber sido creada e instanciada con newListaDoblEnl(), y el nodeToAdd deberia estarlo tambien con newNodeDobl().
  POST: Se comienza con la creacion de un Nodo* el cual sea cargado con data luego se recorrera la lista
   desde list->head hasta hallar el ultimo nodo perteneciente de la lista el cual su nodo->nextNode apunte a NULL.
  Allì se setteara el nodeToAdd. Dentro de esta funcionalidad se instancia de manera recursiva la funcion "linkToNext"
  El currentNode->nextNode queda setteado a nodeToAdd.
  El index queda setteado en nodeToAdd sera igual al currentNode->index + 1;
*/

void addNodeToListDoblEnl(ListaDoblEnl* list, NodoDobl* nodeToAdd);

/*
  PRE : La ListaSimEnl debe haber sido creada e instanciada con newListaDoblEnl(), y el nodeToAdd deberia estarlo tambien con newNode().
  POST: Se comienza con la creacion de un Nodo* el cual sea cargado con data luego se recorrera la lista
   desde list->head hasta hallar el ultimo nodo perteneciente de la lista el cual su nodo->nextNode apunte a NULL.
  Allì se setteara el nodeToAdd. Dentro de esta funcionalidad se instancia de manera recursiva la funcion "linkToNext"
  El currentNode->nextNode queda setteado a nodeToAdd.
  El index queda setteado en nodeToAdd sera igual al currentNode->index + 1;
*/
void addDataToListDoblEnl(ListaDoblEnl* list, void* data);
/*
  PRE : Lista debe estar previamente creada con newListaDoblEnl().
  POST: Si la lista esta creada y cargada, se comenzara desde list->head y secuencialmente se eliminara nodo por nodo.
    Si la lista esta creada pero esta vacia, la funcion no hara nada.
  Todo nodo sera eliminado de la lista
  lista->head apuntara a NULL
  lista->tail apuntara a NULL
  lista->tam sera reducido a 0
*/
void vaciarListaDobEnl(ListaDoblEnl * list);

/*
  PRE : La lista debe estar previamente creada e instanciada con newListSimpEnl(), index debe pertenecer a un valor de la lista.
  POST: Se devolvera un Nodo que contenga el mismo index que el requerido por parametro.
  Nodo * sera devuelto, caso contrario no devolvera nada;
*/

/*-------GET-------*/
NodoDobl* getIndex(ListaDoblEnl * lista, int index);
#endif // LISTADOBLENL_H_INCLUDED
