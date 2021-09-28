#include "Funciones.h"
#include <cstring>
#include <iostream>
#include<string>



using namespace std;

string eliminarEspaciosDelComienzoYFinal(string cadena){
//        cout <<"Palabra a la cual se eliminaran los espacios : "<<  cadena << endl;
        int posComienzo = 0;
        int posFinal = 0;
        char letra;
        char auxCadena[40];
        char subCadena[40];
        char espacio = ' ';
        int i = 0, tamanio = 0, j= 0;

        string palabra;
//Elimino los espacios al principio de la cadena
        while(i < cadena.length()){

          if(cadena[i] != espacio){
                i = cadena.length() +  1;
            }
           posComienzo++;
        }

         for(int i = 0; i< cadena.length(); i++) {
            fflush(stdin);
            auxCadena[i] = cadena[posComienzo++];
        }



//Elimino los espacios al final de la cadena
        tamanio = strlen(auxCadena) -1 ;
        while(j == 0){
          if(auxCadena[tamanio] != espacio){
                posFinal = tamanio;
                j = 1;
            }
           tamanio--;
        }

//        cout << "Palabra: "<< auxCadena[posFinal-5] << endl;
        cout << "Palabra: "<< auxCadena[posFinal] << endl;
        for(int i = 0; i<=posFinal; i++) {
            subCadena[i] = auxCadena[i];
        }


        palabra = subCadena;




    return palabra;
}
