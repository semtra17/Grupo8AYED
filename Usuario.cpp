#include "Usuario.h"
#include "ListaSimpEnl.h"
#include "Funciones.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;



//------------------------------------------------------
//CONSTRUCTOR

Usuario* crearUsuario(  string nombreYapellido, int edad, string direccion){
    Usuario *usuario = new Usuario();
    usuario->direccion= direccion;
    usuario->nombreYapellido = nombreYapellido;
    usuario->edad = edad;
    return usuario;
}

Usuario* crearUsuario(string id_usuario, string nombreYapellido, int edad, string direccion){
    Usuario *usuario = new Usuario();
    usuario->direccion= direccion;
    usuario->nombreYapellido = nombreYapellido;
    usuario->id_usuario = id_usuario;
    usuario->edad = edad;
    return usuario;
}

//------------------------------------------------------
//DESTRUCTORES

void borrarUsuario(Usuario* u){
    delete(u);
}


void removeUsuarioByIdFromList(ListaSimpEnl* list, string idUsuario){

        Nodo* tempPreviousNode = NULL;

      Nodo* n = list->head;
        Usuario * head = (Usuario *) list->head->data;
      while (n != NULL) {
        Usuario * u = (Usuario *)n->data;
        if(head->id_usuario == idUsuario){
            list->head = n->nextNode;
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            cout << "Usuario id: " << ((Usuario* )n->data )->id_usuario << " eliminado" << endl;
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            delete(n);
            n=NULL;
        }
        else if(u->id_usuario == idUsuario && head->id_usuario != idUsuario){
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            cout << "Usuario id: " << ((Usuario* )n->data )->id_usuario << " eliminado" << endl;
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            tempPreviousNode->nextNode = n->nextNode != NULL ? n->nextNode : NULL;
            delete(n);
            n=NULL;
        }
        if(n!=NULL){
            tempPreviousNode = n;
            n = n->nextNode;
        }
      }

}




//------------------------------------------------------
//LECTURA DE ARCHIVOS
void* cargarUsuarioConArchivo(string line){


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
        getline(ss, auxId_usuario, '-');
        id_usuario = eliminarEspaciosDelComienzo(auxId_usuario);
        getline(ss, auxNombrApellido, '-');
        nombrApellido = eliminarEspaciosDelComienzo(auxNombrApellido);
        getline(ss, auxDireccion, '-');
        direccion = eliminarEspaciosDelComienzo(auxDireccion);
        getline(ss, aux, '-');
        edad= stoi(aux);


        void * u = crearUsuario(id_usuario,nombrApellido,edad,direccion);


    return u;
}



void cargarListaUsuarioDesdeArchivo(ListaSimpEnl* list){




    ifstream archivo;
    string line = "";

    archivo.open("usuarios_test.txt",ios::in);//Abrimos el archivo en modo lectura

    while(!archivo.eof()){//mientras NO sea el final del archivo, recorrelo

        while(getline(archivo,line)){
            addDataToList(list,cargarUsuarioConArchivo(line));
        }
    }

    archivo.close();



}




//------------------------------------------------------
//GETS

string getIdUsuario(Usuario *usuario){
    return usuario->id_usuario;
}

string getNombreYapellido(Usuario *usuario){
    return usuario->direccion;
}

string getDireccion(Usuario *usuario){
    return usuario->nombreYapellido;
}

int getEdad(Usuario *usuario){
    return usuario->edad;
}

//------------------------------------------------------
//SETS


void setDireccion(Usuario *usuario, string direccion){
    usuario->direccion = direccion;

}

void setIdUsuario(Usuario *usuario, string id_usuario){
     usuario->id_usuario = id_usuario;
}

void setNombreYapellido(Usuario * usuario, string nombreYapellido){
    usuario->nombreYapellido = nombreYapellido;
}
void setEdad(Usuario * usuario, int edad){

    usuario->edad = edad;
}

//------------------------------------------------------
//BUSCADOR


Usuario * findUsuarioById(ListaSimpEnl* list, string idUsuario){
  Nodo* n = list->head;

  idUsuario = idUsuario + " ";
  while (n != NULL) {
    Usuario * u = (Usuario *)n->data;
    if(u->id_usuario == idUsuario){
        return u;
    }
    n = n->nextNode;
  }
    return 0;
}



//------------------------------------------------------
//UTILIDADES

void printUsuario(Usuario *u){
    if(u != NULL){
        cout << "======================" << endl;
        cout << "IdUsuario: " << u->id_usuario << endl;
        cout << "Nombre y Apellido: " << u->nombreYapellido << endl;
        cout << "Edad: " << u->edad << endl;
        cout << "Direccion: " << u->direccion<< endl;
    }else{
        cout << "Usuario vacio" << endl;
    }


}

void printListaUsuario(ListaSimpEnl* list){
if(list->head){
        cout << "Lista vacia" << endl;

    }else{
        Nodo* n = list->head;
        while (n != NULL) {
            printUsuario((Usuario*)n->data);
            n = n->nextNode;
        }
    }

}
