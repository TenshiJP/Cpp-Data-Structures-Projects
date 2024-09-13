#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
    int numeros[10];
    int *pNumeros=numeros;
    cout << "" << endl;
    for(int i=0;i<sizeof numeros/4;i++){
        cout << " Ingrese un numero [" << i << "]: "; cin >> numeros[i];
    }

    cout << "\n Numeros Pares del Array\n" << endl;

    for(int i=0;i<sizeof numeros/4;i++){
        if(*pNumeros%2==0)
            cout << " " << *pNumeros << " es par. Posicion de memoria: " << pNumeros << endl;
        pNumeros++;
    }
    getch();
    return 0;
}
