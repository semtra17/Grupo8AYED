#include "Funciones.h"
#include <cstring>
#include <iostream>
#include<string>



using namespace std;

string eliminarEspaciosDelComienzoYFinal(string cadena){
        int posComienzo = 0;
        int posFinal = 0;
        char letra;
        char auxCadena[40];
        char subCadena[40];
        char espacio = ' ';
        string palabra;
        for(int i = 0; i< cadena.length(); i++) {
            letra = cadena[i];
            if(letra != espacio){
                break;
            }
            posComienzo= i;
        }


        if(posComienzo!= 0){
            for(int i = 0; i< cadena.length(); i++) {
                auxCadena[i] = cadena[++posComienzo];
            }
        }
        for(int i = strlen(auxCadena) - 1; i > 0 ; i--) {

                letra = auxCadena[i];
                if(letra != espacio){
                    break;
                }

                posFinal= i;
        }

         if(posFinal != 0 ){
            for(int i = 0; i<strlen(auxCadena) - 1; i++) {
                subCadena[i] = auxCadena[--posFinal];
            }
        }
        palabra = subCadena;



    return palabra;
}
