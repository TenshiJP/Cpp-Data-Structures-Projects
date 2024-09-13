#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>

using namespace std;

ifstream lectura; ofstream escritura;//Variables para el manejo de archivos txt.
int fin=0, limite=10;

int main()
{
    fin=0;
    int numeros [10];//Vector
    lectura.open("prueba.txt",ios::in);  //Abre documento.txt en Lectura


    while(lectura.good()){ //Ciclo con condicinal, para calcular los saltos de linea del archivo txt.
        if(lectura.get()=='\n')
            fin++;    //Actualiza la varible
    }
    lectura.close();


    lectura.open("prueba.txt",ios::in);  //Abre documento.txt en Lectura
    for(int j=1; j<fin+1; j++){  //Condición para recorrer el archivo txt.
            lectura >> numeros[j-1];    //Copia y guarda lo del archivo txt en el vector.
    }
    lectura.close();// ***Fin carga de Datos.***

    cout << " \n\t Datos del vector." << endl;

    //IMPRIMIR VECTOR.
    for(int i=1;i<=fin;i++){
        cout << "Posicion: " << i << " |\t Dato: " << numeros[i-1] << endl;
    }

    return 0;
}
