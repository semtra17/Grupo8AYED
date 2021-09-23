#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include "Usuario.h"
#include "Direccion.h"


struct Usuario{
    char id_usuario[6];
    char nombreYapellido[50];
    int edad;
    char direccion[40];
};


Usuario* crearUsuario(char nombreYapellido[50], int edad,char direccion[40]);
Usuario* crearUsuarioConId(int id_usuario, char nombreYapellido[50], int edad, char direccion[40]);
char *getIdUsuario(Usuario *usuario);
char *getNombreYapellido(Usuario *usuario);
char *getDireccion(Usuario *usuario);
int getEdad(Usuario *usuario);

void setDireccion(Usuario *usuario, char direccion[40]);
void setIdUsuario(Usuario *usuario, char id_usuario[6]);
void setNombreYapellido(Usuario * usuario, char nombreYapellido[50]);
void setEdad(Usuario * usuario, int edad);

#endif // USUARIO_H_INCLUDED
