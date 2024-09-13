/*
    Nombre:     Angel Roberto Jacinto Payes
    No.Carnet:  5990-20-1756
    Curso:      Programación III - Estructura de Datos
*/
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;
//Funciones a Utilizar.
void elevarAlCubo(int *);

int main()
{
    int numero=5;
    cout << "\n\t*** LLAMADAS POR REFERENCIA ***\n" << endl;
    cout << " El valor original del numero es: " << numero << endl;
    elevarAlCubo(&numero);
    cout << " El nuevo valor del cubo es: " << numero << endl;
    getch();
    return 0;
}

//Función para elevar un entero al cubo.
void elevarAlCubo(int *ptrNumero){
    *ptrNumero = *ptrNumero * *ptrNumero * *ptrNumero;
}
