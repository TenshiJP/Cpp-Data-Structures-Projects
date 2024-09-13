#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{
    int numeros[]=  {1,2,3,4,5};
    int *pNumeros=numeros;  //Pasar direccion solo funcina en arrays.

    for (int i=0;i<5;i++)
    {
        //cout << " Elemento del vector " << i << " es: " << *pNumeros++<< endl;//Opción para mostrar con punteros los items de un array.
        cout << " Posicion de memoria " << i << " es: " << pNumeros++<< endl;//Opción para mostra con punteros la direccion de los items de un array.
    }
    getch();
    return 0;
}
