/*
        *******   ÁRBOL BINARIO DE BÚSQUEDA   *******
        Nombre:         Angel Roberto Jacinto Payes
        No.Carnet:      5990-20-1756

*/
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

//Estructura para el nodo
typedef struct binario{
    int numero;
    struct binario *pIzq;
    struct binario *pDer;
} nodo;

//Nodos para la estructura.
nodo *pRaiz, *pFinal, *pRecorrido, *pNuevo, *pTemporal;

//Funciones a utlizar
void ingresarDatos();
void imprimir();
void inOrden(nodo *pArbol, int y);
void gotoxy(int x, int y);

//Variables a utilizar.
int ejeX=0, opcion=0;

int main()
{
    do{
        system("cls"); system("color 07");
        cout << "\n\t\t .-----------------------------------------." << endl;
        cout << "\t\t |                                         |" << endl;
        cout << "\t\t |     *  ARBOL BINARIO DE BUSQUEDA  *     |" << endl;
        cout << "\t\t |                                         |" << endl;
        cout << "\t\t :-----------------------------------------:" << endl;
        cout << "\t\t |    ||                                   |" << endl;
        cout << "\t\t | 1. ||       Ingresar nodo al ABB        |" << endl;
        cout << "\t\t | 2. ||     Mostrar diagrama del ABB      |" << endl;
        cout << "\t\t | 3. ||               Salir               |" << endl;
        cout << "\t\t |    ||                                   |" << endl;
        cout << "\t\t '-----------------------------------------'\n" << endl;
        cout << "\t  Digite su opcion: "; cin >> opcion;
        switch(opcion){
            case 1:
                ingresarDatos(); getch();
                break;
            case 2:
                imprimir(); getch();
                break;
            case 3:
                system("cls"); system("color 0C");
                cout << "\n\t\t Adios..." << endl;
                break;
            default:
                system("color 04");
                cout << "\n\t No es una opcion valida" << endl; getch();
        }
    }while(opcion!=3);
    return 0;
}

//Fución para ingresar datos a un nodo y agregarlo al ÁrbolBB.
void ingresarDatos(){
    system("cls"); system("color 01");
    pNuevo = (nodo *)malloc(sizeof(nodo));//Buscar espacio en memoria.

    if(pNuevo==NULL){//Si el nodo pNuevo esta NULL.
        cout << "\t No hay espacio en memoria disponible para crear mas nodos." << endl;
    }else{
        /*Ingreso de datos e inicialización de punteros*/
        cout << "\n \t**********INGRESO DE DATOS**********\n" << endl;
        cout << " Ingrese un numero: "; cin >> pNuevo->numero; cin.ignore();
        pNuevo->pIzq = NULL;
        pNuevo->pDer = NULL;
        /*Fin*/

        /* Para el puntero Raíz, si llegara a ser igual a NULL, hay dos opciones:
            1.-  Perdimos los punteros (Peor escenario).
            2.-  Arbol vacío.    */
        if(pRaiz==NULL){
            pRaiz   = pNuevo;//Sera la raíz y ultimo nodo en la lista.
            system("color 0A"); cout << "\n\t Registro Guardado." << endl;
            cout << " " << pNuevo->numero << "." << endl;
        }else{
            if(pNuevo->numero == pRaiz->numero){ //Condicional para valores iguales a la Raiz.
                system("color 04"); cout << "\tLo sentimos el valor de " << pNuevo->numero << " es igual que la Raiz" << endl;
                return;
            }else{}

            //Condicionales para ordenar los valores a ingresar en Árbol Binario de Busqueda.
            pFinal = NULL;  //Inicializar puntero.
            pRecorrido = pRaiz; //Igualar punteros para recorrer el Árbol Binario de Busqueda.
            while(pRecorrido != NULL){ //Mientras no este en el ultimo nodo.
                pFinal = pRecorrido; //Igualar punteros para realizar las condocionales.
                if(pNuevo->numero <= pRaiz->numero){ //Si el nuevo dato es <= al valor del nodo en que se encuentra.
                    pRecorrido = pRecorrido->pIzq;
                }else{//Caso contrario valor nuevo > a valor de Raíz.
                    pRecorrido = pRecorrido->pDer;
                }
            }
            if(pNuevo->numero <= pFinal->numero){ //Si el nuevo dato es <= al valor del nodo que se compara.
                pFinal->pIzq = pNuevo;
            }else{//Caso contrario valor nuevo > a valor de Raíz.
                pFinal->pDer = pNuevo;
            }
            system("color 0A"); cout << "\n\t Registro Guardado." << endl;
            cout << " " << pNuevo->numero << "." << endl;
        }

    }
}

//Función para imprimir el diagrama de arbol con los datos de los nodos por InOrden.
void inOrden(nodo *pArbol, int ejeY){
    if(pArbol == NULL){ //Si el ÁrbolBB esta vació.
        return;
    }else{
        ejeX += 5; //Posición en el eje X de la consola.
        inOrden(pArbol->pIzq, ejeY+2); //Se pocisiona en la hoja más a la Izquierda del ABB.
        gotoxy(10+ejeX-ejeY, 3+ejeY);//Posición de la cadena a imprimir en pantalla.
        cout << "(" << pArbol->numero <<  ")" << endl << endl;
        inOrden(pArbol->pDer, ejeY+2); //Se pocisiona en la hoja más a la Derecha del ABB.
    }
}

//Función para imprimir el ABB.
void imprimir(){
    system("cls"); system("color 0D");
    ejeX = 0; //Actualizar variable a cero antes de ser utilizada.
    cout << "\n\t\t********** ARBOL BINARIO DE BUSQUEDA **********\n" << endl;
    inOrden(pRaiz, 0);
}

//Función para asignar una posición de pantalla con los ejes X, Y cuando se vaya a imprimir en pantalla.
void gotoxy(int x,int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon,dwPos);
}
