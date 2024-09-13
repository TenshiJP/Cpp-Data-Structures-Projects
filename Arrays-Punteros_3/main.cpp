#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
    int numeros[5], menor, j;
    int *pNumeros=numeros;

    cout << "\n\tLlenar el Array\n" << endl;
    for(int i=0; i< sizeof numeros/4; i++){
        cout << " Digite un numero: "; cin >> numeros[i];
    }
    menor=numeros[0];
    //Determinar el elemento menor de un array.
    for(int i=0; i<sizeof numeros/4; i++){
        if(menor>numeros[i]){
            menor=numeros[i];
            j=i;
        }
    }
    cout << "\n El numero menor en el array es: " << menor << endl;
    cout << " Posicion de meoria: " << pNumeros+(j) << endl;
    return 0;
}
