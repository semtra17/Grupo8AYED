#include "Usuario.h"





Usuario* crearUsuario( char nombreYapellido[50], int edad, char direccion[40]){
    Usuario *usuario = new Usuario();
    strcpy(usuario->direccion,direccion);
    fflush(stdin);
    strcpy(usuario->nombreYapellido,nombreYapellido);
    fflush(stdin);
    usuario->edad = edad;
    return usuario;
}

Usuario* crearUsuarioConId(char id_usuario[6], char nombreYapellido[50], int edad, char direccion[40]){
    Usuario *usuario = new Usuario();
    fflush(stdin);
    strcpy(usuario->direccion,direccion);
    fflush(stdin);
    strcpy(usuario->id_usuario,id_usuario);
    strcpy(usuario->nombreYapellido,nombreYapellido);
    fflush(stdin);
    usuario->edad = edad;
    return usuario;
}
char *getIdUsuario(Usuario *usuario){
    return usuario->id_usuario;
}

char * getDireccion(Usuario *usuario){
    return usuario->direccion;
}

char *getNombreYapellido(Usuario *usuario){
    return usuario->nombreYapellido;
}

int getEdad(Usuario *usuario){
    return usuario->edad;
}

void setDireccion(Usuario *usuario, char direccion[40]){
       strcpy(usuario->direccion,direccion);
}

void setIdUsuario(Usuario *usuario, char id_usuario[6]){
    strcpy(usuario->id_usuario,id_usuario);
}

void setNombreYapellido(Usuario * usuario, char nombreYapellido[50]){
    strcpy(usuario->nombreYapellido,nombreYapellido);
}
void setEdad(Usuario * usuario, int edad){

    usuario->edad = edad;
}

