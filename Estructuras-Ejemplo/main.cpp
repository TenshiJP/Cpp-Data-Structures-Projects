/*
    Nombre:     Angel Roberto Jacinto Payes
    No.Carnet:  5990-20-1756
    Curso:      Programación III - Estructura de Datos
*/
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

//Estructura de tarjeta
struct tarjeta{
    char *cara;
    char *pie;
};

int main()
{
    struct tarjeta estrucutura;
    struct tarjeta *pEstructura;
    estrucutura.cara = "Redonda";
    estrucutura.pie = "Ancho";
    pEstructura = &estrucutura;

    printf("\n %s%s%s\n %s%s%s\n %s%s%s\n",
           estrucutura.cara, " y ", estrucutura.pie,
           pEstructura->cara, " y ", pEstructura->pie,
           (*pEstructura).cara, " y ", (*pEstructura).pie);
    getch();
    return 0;
}
