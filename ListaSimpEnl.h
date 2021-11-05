#ifndef LISTASIMPENL_H_INCLUDED
#define LISTASIMPENL_H_INCLUDED


/**
    Definición del Tipo de Dato para manejo de Nodo.
    Atributos:
    * index,
    * data,
    * nextNode,

    Axiomas:
    * index = int
    * data = void *
    * nextNode = struct Nodo
*/

/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/
/*--------------------------------*/

/* Tipo de Estructura del Nodo */
struct Nodo{
    int index;
    void * data;
    Nodo * nextNode;
};

/**
    Definición del Tipo de Dato para manejo de ListaSimpEnl.
    Atributos:
    * tam,
    * head,

    Axiomas:
    * tam = int
    * head = struct Nodo
*/

/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/
/*--------------------------------*/

/* Tipo de Estructura del ListaSimpEnl */



struct ListaSimpEnl{
    int tam;
    Nodo * head;

};


/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*-------CONSTRUCTOR-------*/

/*
  PRE : El Nodo no debe haber sido creado.
  POST: El Nodo queda creado y preparado para ser usado.
  El nextNodo queda setteado en NULL.
  El index queda setteado en 0;
*/
Nodo* newNode(void * data);
/*
  PRE : La ListaSimEnl no debe haber sido creada.
  POST: La ListaSimEnl queda creada y preparada para ser usada.
  El head queda setteado en NULL.
  El tam queda setteado en 0;
*/
ListaSimpEnl* newListSimpEnl();

/*
  PRE : El currentNode debe pertener a una ListSimEnl o obligatoriamente ya creado e instanciado con newNode().
  POST: Nodos correctamentes enlazados.
  El currentNode->nextNode queda setteado a nodeToAdd.
  El index queda setteado en nodeToAdd sera igual al currentNode->index + 1;
*/




/*-------ADDITION-------*/
void linkToNext(Nodo* currentNode, Nodo* nodeToAdd);
/*
  PRE : La ListaSimEnl debe haber sido creada e instanciada con newListSimpEnl(), y el nodeToAdd deberia estarlo tambien con newNode().
  POST: Se comenzara desde list->head hasta hallar el ultimo nodo perteneciente de la lista el cual su nodo->nextNode apunte a NULL.
  Allì se setteara el nodeToAdd. Dentro de esta funcionalidad se instancia de manera recursiva la funcion "linkToNext"
  El currentNode->nextNode queda setteado a nodeToAdd.
  El index queda setteado en nodeToAdd sera igual al currentNode->index + 1;
*/
void addNodeToList(ListaSimpEnl* list, Nodo* nodeToAdd);

/*
  PRE : La ListaSimEnl debe haber sido creada e instanciada con newListSimpEnl(), y el nodeToAdd deberia estarlo tambien con newNode().
  POST: Se comienza con la creacion de un Nodo* el cual sea cargado con data luego se recorrera la lista
   desde list->head hasta hallar el ultimo nodo perteneciente de la lista el cual su nodo->nextNode apunte a NULL.
  Allì se setteara el nodeToAdd. Dentro de esta funcionalidad se instancia de manera recursiva la funcion "linkToNext"
  El currentNode->nextNode queda setteado a nodeToAdd.
  El index queda setteado en nodeToAdd sera igual al currentNode->index + 1;
*/
void addDataToList(ListaSimpEnl* list, void* data);

/*
  PRE : Lista debe estar previamente creada con newListSimpEnl().
  POST: Si la lista esta creada y cargada, se comenzara desde list->head y secuencialmente se eliminara nodo por nodo.
    Si la lista esta creada pero esta vacia, la funcion no hara nada.
  Todo nodo sera eliminado de la lista
  lista->head apuntara a NULL
  lista->tam sera reducido a 0
*/
/*-------DESTRUCTOR-------*/
void vaciarListaSimpEnl(ListaSimpEnl * list);

/*
  PRE : La lista debe estar previamente creada e instanciada con newListSimpEnl(), index debe pertenecer a un valor de la lista.
  POST: Se devolvera un Nodo que contenga el mismo index que el requerido por parametro.
  Nodo * sera devuelto, caso contrario no devolvera nada;
*/

/*-------GET-------*/
Nodo* getIndex(ListaSimpEnl * lista, int index);




#endif // LISTASIMPENL_H_INCLUDED
