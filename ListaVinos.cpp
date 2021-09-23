#include "ListaVinos.h"
#include "Vino.h"
#include "iostream"
using namespace std;

void printListaVinos(ListaVino* list);

void cargarListaVinoDesdeArchivo(ListaVino* list);

NodoVino* nuevoNodoVino(Vino* vino);

ListaVino* nuevaListaVino();

void linkToNextNodoVino(NodoVino* currentNode, NodoVino* nodeToAdd);

void agregarNodoVino(ListaVino* list, NodoVino* nodeToAdd);

void agregarVino(ListaVino* list, Vino * usuarioToAdd);

NodoVino* findVinoById(ListaVino* list, int idVino);

void removeNodeVino(ListaVino* list, NodoVino* nodeToRemove);

void removeVino(ListaVino* list, int idVino);
