#include "ListaUsuario.h"
#include "Usuario.h"
#include <fstream>
#include<stdlib.h>
#include <iostream>
using namespace std;



void printListaUsuario(ListaUsuario* list){

    NodoUsuario* n = list->primerUsuario;
    while (n != NULL) {
        cout << "Id Usuario: " << n->elementoUsuario->id_usuario << endl;
        cout << n->elementoUsuario->nombreYapellido << "  Edad: " << n->elementoUsuario->edad << endl ;
        cout << "Direccion: " << n->elementoUsuario->direccion << endl ;
        cout << "=======================================" << endl;
        n = n->siguienteUsuario;
    }

}



//NodoUsuario* cargarNodoUsuarioConArchivo(char renglonArchivo[]){
//            fflush(stdin);
//            int tamanio = 0, i=0, j=0;
//            tamanio=strlen(renglonArchivo);
//            char id_usuario[6];
//            char auxEdad[6];
//            char nombreYapellido[40];
//            int edad;
//            char direccion[40];
//
//            int separadores[7];
//            int contSeparadores = 0;
////Encuentro cada separador en el archivo txt y guardo su posicion en separadores
////Tambien cuento los separadores
//        for (i=0;i<tamanio;i++){
//            if(renglonArchivo[i]=='/'){
//                separadores[contSeparadores] = i;
//                contSeparadores++;
//            }
//        }
//
//            contSeparadores++;
//            separadores[contSeparadores- 1] = tamanio;
//                            cout << "========================"<< endl;
//
//
//            for (i=0;i<contSeparadores;i++){
//                int posLetra = 0;
//
//                switch(i){
//                    case 0:
//                        for(j=0;j<separadores[i];j++){
//                            fflush(stdin);
//                            id_usuario[j] = renglonArchivo[j];
//                        }
//
//                    break;
//
//                    case 1:
//                        for(j=separadores[i - 1] + 1;j<separadores[i];j++){
//                            fflush(stdin);
//                            nombreYapellido[posLetra] = renglonArchivo[j];
//                            posLetra++;
//                        }
//                    break;
//
//                    case 2:
//                        for(j=separadores[i - 1]+1;j<separadores[i];j++){
//                            fflush(stdin);
//                            direccion[posLetra] = renglonArchivo[j];
//                            posLetra++;
//                        }
//                    break;
//
//                    case 3:
//
//                            for(j=separadores[i - 1]+1;j<separadores[i];j++){
//                                  fflush(stdin);
//                                auxEdad[posLetra] = renglonArchivo[j];
//                                posLetra++;
//                            }
//                            edad = atoi(auxEdad);
//                    break;
//
//
//
//                }
//
//            }
//        Usuario *usuario = crearUsuarioConId(id_usuario,nombreYapellido,edad,direccion);
//        NodoUsuario* n= new NodoUsuario();
//
//        n->elementoUsuario= usuario;
//        n->siguienteUsuario=NULL;
//
//    return n;
//}


//
//void cargarListaUsuarioDesdeArchivo(ListaUsuario* list){
//
//    char renglon[300]=" ";
//
//    NodoUsuario* ultimoNodo;
//    NodoUsuario* anteriorNodo;
//
//
//    ifstream archivo ("usuarios.txt");
//
//        while(!archivo.eof()){
//
//            archivo.getline(renglon,300);
//
//            ultimoNodo=cargarNodoUsuarioConArchivo(renglon);
//
//            if(list->tamanioLista==0){
//
//                list->primerUsuario=ultimoNodo;
//            }
//            else{
//
//                anteriorNodo->siguienteUsuario=ultimoNodo;
//            }
//
//            list->tamanioLista++;
//            anteriorNodo=ultimoNodo;
//
//        }
//
//    archivo.close();
//
//}

NodoUsuario* nuevoNodoUsuario(Usuario* usuario){
    NodoUsuario* nodoUsuario = new NodoUsuario();
    nodoUsuario->elementoUsuario = usuario;
    nodoUsuario->siguienteUsuario = NULL;
    return nodoUsuario;

}

ListaUsuario* nuevaListaUsuario(){
    ListaUsuario* lista = new ListaUsuario();
    lista->primerUsuario = NULL;
    lista->tamanioLista = 0 ;
    return lista;

}

void linkToNextNodoUsuario(NodoUsuario* currentNode, NodoUsuario* nodeToAdd){

    if (currentNode->siguienteUsuario == NULL){
		currentNode->siguienteUsuario = nodeToAdd;
	}else{
	 	linkToNextNodoUsuario(currentNode->siguienteUsuario, nodeToAdd);
	}
}

void agregarNodoUsuario(ListaUsuario* list, NodoUsuario* nodeToAdd){
    if(list->primerUsuario == NULL){
            list->primerUsuario = nodeToAdd;
            list->tamanioLista++;
     }else{
            linkToNextNodoUsuario(list->primerUsuario, nodeToAdd);
            list->tamanioLista++;
      }
}

void agregarUsuario(ListaUsuario* list, Usuario * usuarioToAdd){

    NodoUsuario* node = nuevoNodoUsuario(usuarioToAdd);
    agregarNodoUsuario(list, node);

}

NodoUsuario* findUsuarioById(ListaUsuario* list, char idUsuario[6]){
      NodoUsuario* n = list->primerUsuario;
      NodoUsuario* temp;
      while (n != NULL) {
        if(n->elementoUsuario->id_usuario == idUsuario){
          temp = n;
        }
        n = n->siguienteUsuario;
      }
      return temp;
}

void removeNode(ListaUsuario* list, NodoUsuario* nodeToRemove){
    NodoUsuario* tempUsuarioNode = nodeToRemove;
    NodoUsuario* tempPreviousNode = NULL;

    NodoUsuario* n = list->primerUsuario;

    while (n != NULL) {
        if(n->siguienteUsuario == nodeToRemove){
          tempPreviousNode = n;
        }
        n = n->siguienteUsuario;
    }
      tempPreviousNode->siguienteUsuario = tempUsuarioNode;
      delete nodeToRemove;



}

void removeUsuario(ListaUsuario* list, char idUsuario[6]){
    NodoUsuario* nodeToRemove = findUsuarioById(list, idUsuario);
    removeNode(list, nodeToRemove);


}
