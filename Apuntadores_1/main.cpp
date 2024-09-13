#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{
    int num=0, contador=0;
    int *pNum=&num;

    cout << "\tDEMOSTRAR NUMEROS PRIMOS\n\n Ingrese su numero: "; cin >> num;

    for(int i=1;i<*pNum+1;i++){
        if(*pNum%i==0)
            contador++;
    }
    if(contador==2){
        cout << "\n " << *pNum << " es un numero primo." << endl;
        cout << " La posicion de memoria: " << pNum << endl;
    }else{
        cout << "\n " << *pNum << " no es un numero primo." << endl;
        cout << " La posicion de memoria: " << pNum << endl;
    }
    contador=0;
    return 0;
}
