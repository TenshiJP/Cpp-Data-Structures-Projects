/*
    Tema:           Lista Simple Ejemplo
    Nombre:         Angel Roberto Jacinto Payes
    No.Carnet:      5990-20-1756
*/

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Funciones a utilizar.
 void crearNodoFinal();
 void crearNodoInico();
 void recorrido();
 void busqueda();

//Nodo que representará nuestra lista.
typedef struct nodo{
    int numValor;
    //string dato;
    struct nodo *pSig;
} stcNodo;

//Apuntadores a a la lista.
stcNodo *pInicio, *pRecorrido, *pNuevo;

int main()
{
    int opcion=0;

    while(opcion!=5){
        system("cls");
        cout << "\n\t********************LISTAS SIMPLES********************" << endl;
        cout << "\n\t1.   Ingresar datos a la Lista (Final de la lista)" << endl;
        cout << "\t2.   Ingresar datos a la Lista (Inicio de la lista)" << endl;
        cout << "\t3.   Mostrar valores de la Lista" << endl;
        cout << "\t4.   Buscar un valor de la Lista" << endl;
        cout << "\t5.   Salir" << endl;
        cout << "\t Digite su opcion: "; cin >> opcion;
        cout << "\n\t******************************************************" << endl;
        switch(opcion){
            case 1:
                crearNodoFinal(); getch();
                break;

            case 2:
                crearNodoInico(); getch();
                break;

            case 3:
                recorrido(); getch();
                break;

            case 4:
                busqueda(); getch();
                break;

            case 5:
                break;
            default:
                cout << "\tNo es una opcion valida." << endl;
                getch();
        }
    }

    return 0;
}

//Procedimiento para creación de un nodo simple para lista, con una inserción al final de la lista.
void crearNodoFinal(){
    int numValor;
    system("cls");

    //Se busca un espacio en memoria segun el tamaño del nodo prototipo.
    pNuevo = (stcNodo *)malloc(sizeof(stcNodo));

    //Si pNuevo es nulo, quiere decir que no hay espacio en memoria.
    if(pNuevo==NULL){
        cout << " No hay espacio en memoria disponible para crear mas nodos." << endl;
    }else{
        //Paso 1: Pedimos Valor e inicializamos Punteros.
        cout << "\n \t**********INGRESO DE DATOS**********" << endl;
        cout << " Ingrese un numero: "; cin >> numValor;
        pNuevo->numValor = numValor;
        pNuevo->pSig = NULL;

        /*Para el puntero Inicio, si llegara a ser igual a nil, hay dos opciones
        1.- Perdimos la lista (Pero escenario).
        2.- Esta vacia (no existe ningun nodo en la lista.)*/
        if(pInicio==NULL){
            //Es este caso seria primero y ultimo nodo de la lista.
            pInicio = pNuevo;
        }else{
            //Nos posicionaremos en el primer nodo de la lista hasta el ultimo nodo.
            pRecorrido = pInicio;
            //Ahora recorremos la lista hasta el ultimo nodo.
            while(pRecorrido->pSig != NULL)
                pRecorrido = pRecorrido->pSig;

            //Cuando el recorrido finaliza estamos seguros que pRecorrido se encuentra en el ultimo nodo de la lista.
            pRecorrido->pSig = pNuevo;
        }
    }
}   //Fin de la función para la creación de nodos al final.

//Procedimiento para creacion de un nodo simple para lista, con una insección al inicion de la lista.
void crearNodoInico(){
    int numValor;
    string dato;
    system("cls");

    //Se busca un espacio en memeoria segun el tamaño del nodo prototipo.
    pNuevo = (stcNodo *)malloc(sizeof(stcNodo));

    //Si pBuevo es nulo, quiere decir que no hay espcio en memoria.
    if(pNuevo==NULL){
        cout << " No hay espacio en memoria disponible para crear mas nodos." << endl;
    }else{
        //Paso 1: Pedimos Valor e inicializamos Punteros.
        cout << "\t **********INGRESO DE DATOS**********" << endl;
        cout << " Ingrese un numero: "; cin >> numValor; cin.ignore();
        //cout << " Ingrese un dato: "; getline(cin, dato);
        pNuevo->numValor = numValor;
        //pNuevo->dato = dato;
        pNuevo->pSig = NULL;

        /*Para el puntero Inicio, si llegara a ser igual a nil, hay dos opciones:
          1.-   Perdimos la lista (Peor escenario).
          2.-   Esta vacia (no existe ningun nodo en la lista).*/
        if(pInicio==NULL){
            //En este caso seria primero y ultimo nodo de la lista.
            pInicio = pNuevo;
        }else{
            /*Orden en pasos:
               1.-  El nuevo nodo apuntara a donde apunta pInicio.
               2.-  Luego pInicio apuntara al nuevo.*/
               pNuevo->pSig = pInicio;
               pInicio = pNuevo;
        }
    }
}   //Fin de la función para creacion de nodos al inicio.

//Función que muestra los valores de la lista.
void recorrido(){
    //Limpiamos pantalla
    system("cls");
    printf("%s\n","*********************************************\n");
    printf("%s\n","************RECORRIDO DE LA LISTA************\n");
    printf("%s\n","*                                           *\n");
    printf("%s","* ");

    //Nos posicionamos en el primer nodo de la lista, pInicio lo sabe.
    pRecorrido = pInicio;

    //Mientras no estemos en el ultimo nodo de nuestra lista, la seguiremos recorriendo.
    while(pRecorrido!=NULL){
        printf(" %d%s",pRecorrido->numValor," -->");
        pRecorrido = pRecorrido->pSig;
    }
    printf("%s\n"," Nill");
    printf("%s\n","*                                           *");
    printf("%s\n","*********************************************");
}   //Fin de la funcion de Recorrido.

//Función que busca un valor en la lista.
void busqueda(){
    //Variables utilizadas en el procedimiento.
    int numBusqueda, numEncontrado;

    //Buena practica inicializar variables.
    numBusqueda = 0;
    numEncontrado = 0;

    //Titulo en la pantalla
    system("cls");
    printf("%s\n","**************************************************");
    printf("%s\n","***************BUSQUEDA DE UN VALOR***************");
    printf("%s\n","*                                                *");
    printf("%s","* Ingrese valor a buscar: ");
    scanf("%d",&numBusqueda);

    //Nos posicionamos en el primer nodo de la lista, pInicio lo sabe.
    pRecorrido = pInicio;

    //Mientras no estemos en el ultimo nodo de nuestra lista, la seguiremos recorriendo.
    while(pRecorrido!=NULL){
        if(pRecorrido->numValor==numBusqueda){
            printf("%s%d%s\n","* ",pRecorrido->numValor," --> [Valor Encotrado!!!]");
            numEncontrado++;
        }else{}

        pRecorrido = pRecorrido->pSig;
    }

    //Si termino el recorrido y no encontro el valor, debemos informar que no fue encontrado.
    if(numEncontrado == 0){
        printf("%s%d%s\n","* ",numBusqueda," --> [Lo lamento, el valor NO fue encotrado!!!]");
    }else{}

    printf("%s\n","*                                                 *");
    printf("%s\n","***************************************************");
}   //Fin función de Recorrido.
