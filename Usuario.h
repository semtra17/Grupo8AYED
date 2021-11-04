#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <string>
#include "ListaSimpEnl.h"
using namespace std;

struct Usuario{
    std::string id_usuario;
    std::string nombreYapellido;
    int edad;
    std::string  direccion;
};

//------------------------------------------------------------
//CONSTUCTOR

//PRE: funcion asignada a un puntero de tipo de dato struct Usuario
//POST: nombre, apellido, edad y direccion seran asignados a cada atributo de Usuario
Usuario* crearUsuario(string nombreYapellido, int edad,string direccion);

//Sobrecarga de metodos

//------------------------------------------------------------
//CONSTUCTOR

//PRE: funcion asignada a un puntero de tipo de dato struct Usuario
//POST:id_usuario, nombre, apellido, edad y direccion seran asignados a cada atributo de Usuario
Usuario* crearUsuario(string id_usuario, string nombreYapellido, int edad, string direccion);


void* cargarUsuarioConArchivo(string line);
void cargarListaUsuarioDesdeArchivo(ListaSimpEnl* list);


//---------------------------------------------------------------------
//DESTRUCTOR

//PRE: Usuario* u debe estar cargado con la funcion crearUsuario
//POST: se libera el epacio de la memoria del Usuario* u
void removeUsuarioByIdFromList(ListaSimpEnl* list, string idUsuario);
void borrarUsuario(Usuario* u);

//GETS

//PRE: "usuario" debe estar cargado con la funcion crearUsuario
//POST devuelve el dato de "usuario" indicado en la respectiva funcion
//Funcion getIdUsuario solo devolvera el dato id_usuario si fue inicializado con la funcion crearUsuario que requiere el id del mismo para ser cargado
string getIdUsuario(Usuario *usuario);
string getNombreYapellido(Usuario *usuario);
string getDireccion(Usuario *usuario);
int getEdad(Usuario *usuario);

//SETS

//PRE: "usuario" inicializado vacio, solo se reservo espacio en memoria para el struct
//POST inicializa los valores dependiendo la funcion y el tipo de dato que ingrese en la misma

void setDireccion(Usuario *usuario, string direccion);
void setIdUsuario(Usuario *usuario, string id_usuario);
void setNombreYapellido(Usuario * usuario, string nombreYapellido);
void setEdad(Usuario * usuario, int edad);


//BUSCADOR

//PRE: "usuario" debe estar previamente cargado
//POST muestra por pantalla cada atributo del usuario

Usuario * findUsuarioById(ListaSimpEnl* list, string idUsuario);

//UTILIDADES

//PRE: "usuario" debe estar previamente cargado
//POST muestra por pantalla cada atributo del usuario

void printUsuario(Usuario *u);
void printListaUsuario(ListaSimpEnl* list);

#endif // USUARIO_H_INCLUDED
