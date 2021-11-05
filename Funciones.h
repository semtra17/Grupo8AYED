#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>
using namespace std;
/*
  PRE : cadena no debe estar vacia.
  POST: nuevo string es devuelto
  string es devuelto sin espacios(' '), sin tabulaciones('\t') o o guiones('-') del comienzo y el final.
*/
string eliminarEspaciosDelComienzo(string cadena);
/*
  PRE : cadena no debe estar vacia.
  POST: nuevo string es devuelto
  string es devuelto sin espacios(' '), sin tabulaciones('\t') o o guiones('-') del final.
*/
string eliminarEspaciosDelFinal(string cadena);


#endif // FUNCIONES_H_INCLUDED
