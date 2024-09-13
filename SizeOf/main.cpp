/*
    Nombre:     Angel Roberto Jacinto Payes
    No.Carnet:  5990-20-1756
    Curso:      Programación III - Estructura de Datos
*/
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{
    float arreglo[20];
    cout << "\n El numero de bytes en el Arreglo es " << sizeof(arreglo) <<endl;
    printf("\n Char        :    %d\n",sizeof(char));
    printf(" short       :    %d\n",sizeof(short));
    printf(" int         :    %d\n",sizeof(int));
    printf(" long        :    %d\n",sizeof(long));
    printf(" float       :    %d\n",sizeof(float));
    printf(" double      :    %d\n",sizeof(double));
    printf(" long double :    %d\n",sizeof(long double));
    getch();

    return 0;
}
