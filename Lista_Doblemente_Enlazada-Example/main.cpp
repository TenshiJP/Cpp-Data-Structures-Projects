#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Estructura doblemente enlazada
typedef struct dobleenlazada{
    int num;
    struct dobleenlazada *pSig;
    struct dobleenlazada *pAnt;
} doble_enlace;

//Nodos para estructura
doble_enlace *pInicio, *pFinal, *pRecorrido, *pNuevo;

//Funciones a utlizar
void ingresardoble();   //Procedimiento para creación de nodo doble.
void mostrar();         //Función que muestra los valores de la lista doble.

//Menú principal.
int main()
{
    int opcion = 0;
    while(opcion != 3){
        system("cls");
        printf("%s\n","\n\t**********LISTA DOBLEMENTE ENLAZADA**********\n");
        printf("%s\n"," 1.  Ingresar datos");
        printf("%s\n"," 2.  Mostrar Lista Doblemente Enlazada");
        printf("%s\n"," 3.  Salir");
        printf("%s\n"," Selccione una opcion: ");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                ingresardoble();getch();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                system("cls"); printf("%s\n","\n\tAdios");
                break;
            default:
                printf("%s\n","No es una opcion correcta.");
                getch();
                break;
        }
    }
    return 0;
}//Fin de la función.

//Procedimiento para creación de nodo doble.
void ingresardoble(){
    system("cls");
    int numValor=0;

    //Se busca un espacio en memoria
    pNuevo = (doble_enlace *)malloc(sizeof(doble_enlace));

    //Si pNuevo es nulo, quiere decir que no hay espacio en la memoria.
    if(pNuevo == NULL){
        printf("%s","NO HAY ESPACIO EN MEMORIA PARA CREAR MAS NODOS");
    }else{
        //Paso 1:   Pedimos valor e inicializamos punteros.
        printf("%s","\t************INGRESO DE DATOS************\n");
        printf("%s","\n Ingrese un numero:\n");
        scanf("%d",&numValor);
        pNuevo->num = numValor;
        pNuevo->pSig = NULL;
        pNuevo->pAnt = NULL;

        /* Para el puntero Inicio, si llegara a ser igual a nill, hay dos opciones:
            1.-  Perdimos la lista (Peor escenario).
            2.-  Esta vacia.
        */
        if(pInicio == NULL){
            //En este caso seria primero y ultimo nodo en la lista.
            pInicio = pNuevo;
            pFinal  = pNuevo;
        }else{
            //En este caso seria solo de enlazar basado en el ultimo.
            pNuevo->pAnt = pFinal;
            pFinal->pSig = pNuevo;
            pFinal = pNuevo;
            pFinal->pSig = NULL;
        }
    }
}//Fin de la función.

//Función que muestra los valores de la lista doble.
void mostrar(){
    system("cls");
    printf("%s\n"," *********************************************");
    printf("%s\n"," **********LISTA DOBLEMENTE ENLAZADA**********");
    printf("%s\n"," *                                           *");
    printf("%s\n"," ***********MOSTRAR DE INICIO A FIN***********");
    printf("%s\n"," *                                           * ");
    pRecorrido = pInicio;
    while(pRecorrido != NULL){
        printf("%d\n ",pRecorrido->num);
        pRecorrido = pRecorrido->pSig;
    }
    printf("%s\n"," *                                           *");
    printf("%s\n"," ***********MOSTRAR DE FIN A INICIO***********");
    printf("%s\n"," *                                           * ");
    pRecorrido = pFinal;
    while(pRecorrido != NULL){
        printf("%d\n ",pRecorrido->num);
        pRecorrido = pRecorrido->pAnt;
    }
    printf("%s\n"," *********************************************");
    getch();
}//Fin de la función.
