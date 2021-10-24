#include "Funciones.h"
#include <cstring>
#include <sstream>
#include <iostream>
#include<string>



using namespace std;

string eliminarEspaciosDelComienzo(string cadena){

    int posComienzo = -1, auxPosComienzo = 0;
    int posFinal = 0, auxPosFinal = 0;
    char espacio = ' ';

    char tab = '\t';
    char auxCadena[50] = " ";
    char auxCadena2[50] = " ";
    string palabra = " ";
    int i=0;
    while(i < cadena.length()){

         if((cadena[i] == espacio) || cadena[i] == tab){
            posComienzo++;

        }else if( cadena[i] != espacio){
            i = cadena.length() + 1;
        }
        i++;
    }


    auxPosComienzo = posComienzo;
    if(posComienzo >= 0){
         for(int i = 0; i< cadena.length() - (auxPosComienzo + 1);i++){
            fflush(stdin);
            auxCadena[i] = cadena[++posComienzo];
        }

        fflush(stdin);
        palabra.clear();
        palabra = auxCadena;
    }else{

       palabra = cadena;
    }


    palabra = eliminarEspaciosDelFinal(palabra);


    return palabra;



}


string eliminarEspaciosDelFinal(string cadena){
    int posFinal = cadena.length(), auxPosFinal = 0;
    char espacio = ' ';
    char tab = '\t';
     char puntoComa = ';';
    char auxCadena[50] = " ";
    string palabra = " ";
//    cout<< "largoAntes: "<< cadena.length() << endl;
    int i = cadena.length() - 1;
       while(i >= 0){
         if((cadena[i] == espacio) || cadena[i] == tab || cadena[i] == puntoComa){

            posFinal--;

        }else if( cadena[i] != espacio || cadena[i] != tab){

            i -= cadena.length();
        }
        i--;
    }

    auxPosFinal = posFinal;
    if(posFinal < cadena.length() - 1){
         for(int j = 0; j< posFinal;j++){
            fflush(stdin);
            auxCadena[j] = cadena[j];
        }

        fflush(stdin);
        palabra.clear();
        palabra = auxCadena;
    }else{

       palabra = cadena;
    }
//    cout<< "largoDespues: "<< palabra.length() << endl;
    return palabra;



}

string stringToNumber(string cadena){
  std::istringstream iss(cadena);
  std::string s;
  iss >> s;
  return s;
}
