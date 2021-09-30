#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include "Usuario.h"
#include "Direccion.h"
#include <string>
using namespace std;

struct Usuario{
    std::string id_usuario;
    std::string nombreYapellido;
    int edad;
    std::string  direccion;
};


Usuario* crearUsuario(string nombreYapellido, int edad,string direccion);
Usuario* crearUsuario(string id_usuario, string nombreYapellido, int edad, string direccion);
string getIdUsuario(Usuario *usuario);
string getNombreYapellido(Usuario *usuario);
string getDireccion(Usuario *usuario);
int getEdad(Usuario *usuario);

void setDireccion(Usuario *usuario, string direccion);
void setIdUsuario(Usuario *usuario, string id_usuario);
void setNombreYapellido(Usuario * usuario, string nombreYapellido);
void setEdad(Usuario * usuario, int edad);

#endif // USUARIO_H_INCLUDED
