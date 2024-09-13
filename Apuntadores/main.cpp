/*
    En punteros con * apunta lo que esta dentro de la posicion de memoria.
    sin * muestra la posición de memoria.
*/

#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{
    int num = 0;
    int *pNum=&num; //Guarda posición de memoria de la variable en el puntero.

    cout << "\n Ingrese su numero: "; cin >> num;
    if(*pNum%2==0){
        cout << "\n " << *pNum << " es un numero par." <<endl;
        cout << " Posicion de memoria: " << pNum;
    }else{
        cout << "\n " << *pNum << " es un numero impar." <<endl;
        cout << " Posicion de memoria: " << pNum;
    }

    getch();
    return 0;
}
