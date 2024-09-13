/*
    Nombre:     Angel Roberto Jacinto Payes
    No.Carnet:  5990-20-1756
    Curso:      Programación III - Estructura de Datos
*/
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

//Función potencia a utilizar
int potencia(int x, int n){
    int aux;
    if(n==0){
        return 1;
    }else{
        aux = potencia(x, n/2);
        if(n%2==0){
            return aux * aux;
        }else{
            return x * aux * aux;
        }
    }
}

int main()
{
    int numero, potenciar = 0;
    cout << "\n\t *** RECURSIVIDAD CON POTENCIAS ***\n" << endl;
    cout << " Ingrese el numero que desea elevar: ";
    cin >> numero;
    cout << " Ingrese la potencia a la que lo elevara: ";
    cin >> potenciar;
    cout << "\n Resultado: " << numero << "^" << potenciar << " = " << potencia(numero, potenciar) << endl;
    getch();
    return 0;
}
