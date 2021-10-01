#include "Usuario.h"
#include <iostream>

using namespace std;


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
void printUsuario(Usuario *u){
    cout << "======================" << endl;
    cout << "IdUsuario: " << u->id_usuario << endl;
    cout << "Nombre y Apellido: " << u->nombreYapellido << endl;
    cout << "Edad: " << u->edad << endl;
    cout << "Direccion: " << u->direccion<< endl;

}
