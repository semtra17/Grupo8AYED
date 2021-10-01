#ifndef LISTAUSUARIO_H_INCLUDED
#define LISTAUSUARIO_H_INCLUDED
#include "Usuario.h"


struct NodoUsuario{
    NodoUsuario *anteriorUsuario;
    Usuario* elementoUsuario;
    NodoUsuario* siguienteUsuario;
};


struct ListaUsuario{

    NodoUsuario* primerUsuario;
    NodoUsuario* ultimoUsuario;
    int tamanioLista;
};

void printListaUsuario(ListaUsuario* list);

void cargarListaUsuarioDesdeArchivo(ListaUsuario* list);
NodoUsuario* cargarNodoConArchivo(string line);

NodoUsuario* nuevoNodoUsuario(Usuario* usuario);

ListaUsuario* nuevaListaUsuario();

void linkToNextNodoUsuario(NodoUsuario* currentNode, NodoUsuario* nodeToAdd);

void agregarNodoUsuario(ListaUsuario* list, NodoUsuario* nodeToAdd);

void agregarUsuario(ListaUsuario* list, Usuario * usuarioToAdd);

NodoUsuario* findUsuarioById(ListaUsuario* list, char idUsuario[6]);

void removeNode(ListaUsuario* list, NodoUsuario* nodeToRemove);

void removeUsuario(ListaUsuario* list, char idUsuario[6]);





#endif // LISTAUSUARIO_H_INCLUDED
