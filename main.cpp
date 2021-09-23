#include <iostream>
#include <fstream>
#include<stdlib.h>
#include "Lista.h"
#include "ListaUsuario.h"
#include "Usuario.h"

using namespace std;



int main()
{
   /* ListaUsuario* LISTA_USUARIOS = nuevaListaUsuario();

    Usuario* usuario = crearUsuario("Assefh Luciano", 24,crearDireccion("Santiago del Estero", "Capital","Belgrano", 312));
    Usuario* usuario1 = crearUsuario("Gomez Raquel", 24,crearDireccion("Buenos Aires", "Temperley","Eva Peron", 510));
    agregarUsuario(LISTA_USUARIOS, usuario);
    agregarUsuario(LISTA_USUARIOS, usuario1);

    printListaUsuario(LISTA_USUARIOS);*/



    char renglon[100]= "";


    ifstream archivo ("usuarios_test.txt");

        while(!archivo.eof()){

            fflush(stdin);
            archivo.getline(renglon,200);
            cout << "===============================" << endl;
            cout <<"Informacion obtenida de archivo : "<<  renglon << endl;

            int tamanio = 0, i=0, j=0;
            fflush(stdin);
            tamanio=   strlen(renglon);
              cout << tamanio << endl;
            char id_usuario[6];
            char auxEdad[6];
            char nombreYapellido[40];
            int edad;
            char direccion[40];


            int numero;

            int separadores[4];
            int contSeparadores = 0;
    //Encuentro cada separador en el archivo txt y guardo su posicion en separadores
    //Tambien cuento los separadores
            for (i=0;i<tamanio;i++){
                if(renglon[i]=='-'){
                    separadores[contSeparadores] = i;
                    contSeparadores++;
                }
                 if(renglon[i]==';'){
//                    cout << "separador de ;: "<<  i<< endl;
                    separadores[contSeparadores] = i;
                    contSeparadores++;
                }

            }
//             cout << "separador: "<<  renglon[separadores[contSeparadores - 1]]<< endl;
            //Agrego el tamaño total del renglon a la ultima pos de separadores
//            contSeparadores++;
//            separadores[contSeparadores- 1] = tamanio;
//            cout << "========================"<< endl;
//            cout << "separador: "<<  renglon[contSeparadores]<< endl;
//            cout << contSeparadores<< endl;

            for (i=0;i<contSeparadores;i++){
                int posLetra = 0;

                switch(i){
                    case 0:
                        for(j=0;j<separadores[i];j++){
                            cout<< renglon[j];
                            id_usuario[j] = renglon[j];


                        }
                    break;

                    case 1:
                        for(j=separadores[i - 1] + 1;j<separadores[i];j++){
                            fflush(stdin);
                            nombreYapellido[posLetra] = renglon[j];
                            posLetra++;
                        }
                    break;

                    case 2:
                        for(j=separadores[i - 1]+1;j<separadores[i];j++){
                            fflush(stdin);
                            direccion[posLetra] = renglon[j];
                            posLetra++;
                        }
                    break;

                    case 3:
                        for(j=separadores[i - 1]+1;j<separadores[i];j++){
                            fflush(stdin);                            auxEdad[posLetra] = renglon[j];
                            posLetra++;
                        }
                        edad = atoi(auxEdad);

                    break;

                }

            }

//            cout <<"Direccion : " <<  direccion << endl;
//            cout <<"id Usuario : " <<  id_usuario << endl;


    }

    archivo.close();
}

