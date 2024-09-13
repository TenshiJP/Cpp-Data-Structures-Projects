#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

long fnRecursiva (long number);

int main()
{
    cout << "\n\n\tPROGRAMA DE RECURSIVIDAD\n" << endl;

    //Código Original.
    int i;
    for(i=0;i<=40;i++){
        if(i==0)    //Condicional extra propia.
            cout<<"\tNumeros Factoriales"<<endl;
        if(i==14)
            cout<<"\n\tValores Aleatorios"<<endl;
        if(i==34)
            cout<<"\n\tValores con Cero"<<endl;
        printf(" Ejecucion %2d = %ld\n", i, fnRecursiva(i));
    }
    getch();
    return 0;
}

long fnRecursiva(long number){
    if(number <= 1)
        return 1;
    else
        return (number * fnRecursiva(number-1));
}
