/*
    Nombre:     Angel Roberto Jacinto Payes
    No.Carnet:  5990-20-1756
    Curso:      Programación III - Estructura de Datos
*/
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
    int variable;
    int *pVariable;
    variable = 7;
    pVariable = &variable;

    cout << "\n La direccion de la variable es " << &variable <<
    "\n El valor de la direccion del apuntador pVariable es " << *pVariable << endl;
    cout << "\n\n El valor de la variable es " << variable <<
    "\n El valor del apuntador es " << *pVariable << "\n\n" << endl;
    cout << " Probando que * y & son complementos uno de otro.\n &*pVariable = " << &*pVariable <<
    "\n *&pVariable = " << *&pVariable << endl;

    getch();
    return 0;
}
