#include "ListaUsuario.h"
#include "Funciones.h"
#include "Usuario.h"
#include <fstream>
#include<stdlib.h>
#include <iostream>
#include <sstream>
using std::cout; using std::cin;
using std::endl; using std::string;



void printListaUsuario(ListaUsuario* list){

    NodoUsuario* n = list->primerUsuario;
    while (n != NULL) {
        cout << "Id Usuario: " << n->elementoUsuario->id_usuario << endl;
        cout << "Nombre y apellido: " << n->elementoUsuario->nombreYapellido << endl << "Edad: " << n->elementoUsuario->edad << endl ;
        cout << "Direccion: " << n->elementoUsuario->direccion << endl ;
        cout << "=======================================" << endl;
        n = n->siguienteUsuario;
    }

}



NodoUsuario* cargarNodoUsuarioConArchivo(string line){


//        cout << "===============================" << endl;
//        cout <<"Informacion obtenida de archivo : "<<  line << endl;
        string auxNombrApellido;
        string auxId_usuario;
        string auxDireccion;
        string nombrApellido;
        string id_usuario;
        string direccion;
        string aux;
        string palabra;
        int edad = 0;



        stringstream ss(line);
        getline(ss, id_usuario, '-');
        getline(ss, auxNombrApellido, '-');
        nombrApellido = eliminarEspaciosDelComienzoYFinal(auxNombrApellido);
        getline(ss, auxDireccion, '-');
        direccion = eliminarEspaciosDelComienzoYFinal(auxDireccion);
        getline(ss, aux, '-');
        edad= stoi(aux);


        Usuario *u = crearUsuarioConId(id_usuario,nombrApellido,edad,direccion);


        NodoUsuario* n = new NodoUsuario();
        n->elementoUsuario = u;
        n->siguienteUsuario = NULL;




    return n;
}



void cargarListaUsuarioDesdeArchivo(ListaUsuario* list){


    NodoUsuario* ultimoNodo;
    NodoUsuario* anteriorNodo;


       ifstream archivo;
    string line = "";

    archivo.open("usuarios_test.txt",ios::in);//Abrimos el archivo en modo lectura

    while(!archivo.eof()){//mientras NO sea el final del archivo, recorrelo

        while(getline(archivo,line)){


            ultimoNodo=cargarNodoUsuarioConArchivo(line) ;

            if(list->tamanioLista==0){

                list->primerUsuario=ultimoNodo;
            }
            else{

                anteriorNodo->siguienteUsuario=ultimoNodo;
            }

                list->tamanioLista++;
                anteriorNodo=ultimoNodo;
            }


    }

    archivo.close();



}

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
