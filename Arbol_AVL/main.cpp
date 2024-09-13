#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

//Estructura para el nodo.
typedef struct arbolBB{
    int    codigo;
    struct arbolBB *pPadre;
    struct arbolBB *pIzq;
    struct arbolBB *pDer;
    int    equilibrio;  //Varabile para calcular el factor de equilibrio del nodo.
} avl;

//Nodos para la estructura.
avl *pRaiz, *pNuevo, *pRecorrido, *pPadre, *pActual, *pTemp, *pTemp1, *pTemp2, *pTemp3, *pTemp4, *pTemp5, *pTemp6;

//Funciones a utilizar.
void insertarNodo();                                        //Funci�n
bool comprobarDato(int cod);                                //Funci�n
int hMayor(int izq, int der);                               //Funci�n
int factorEqui(avl *pNodo);                                 //Funci�n
int comprobarBalance(avl *pNodo);                           //Funci�n
void equilibrarIn(avl *pNodo, int rama);                    //Funci�n

void re_sDer(avl *pNodo);                                   //Funci�n
void re_sIzq(avl *pNodo);                                   //Funci�n

void RII(avl *pNodo);                                       //Funci�n
void RDD(avl *pNodo);                                       //Funci�n
void RDI(avl *pNodo);                                       //Funci�n
void RID(avl *pNodo);                                       //Funci�n
void menuBusqueda();                                        //Funci�n
void buscarCodigo();                                        //Funci�n
void buscarNombre();                                        //Funci�n
void elimininarNodo();                                      //Funci�n
void equilibrarFree(avl *pNodo, int rama);                  //Funci�n
void imprimir();                                            //Funci�n
void graficarArbol(avl *pAVL, int ejeY);                    //Funci�n
void gotoxy(int x, int y);                                  //Funci�n

//Variables a utilizar.
int opcion=0, opc=0, ejeX=0, derecha=0, izquierda=1;

int main()
{
    do{
        system("cls"); system("color 07");
        cout << "\n\t\t :----------------------------------------------:" << endl;
        cout << "\t\t |    ||                                        |" << endl;
        cout << "\t\t | 1. ||       Agregar nodos al Arbol AVL       |" << endl;
        cout << "\t\t | 2. ||     Buscar un valor en el Arbol AVL    |" << endl;
        cout << "\t\t | 3. ||     Eliminar un valor del Arbol AVL    |" << endl;
        cout << "\t\t | 4. ||          Mostrar el Arbol AVL          |" << endl;
        cout << "\t\t | 5. ||                 Salir                  |" << endl;
        cout << "\t\t |    ||                                        |" << endl;
        cout << "\t\t '----------------------------------------------'\n" << endl;
        cout << "\t  Digite su opcion: "; cin >> opcion;
        switch(opcion){
            case 1:
                insertarNodo(); getch();
                break;
            case 2:
                menuBusqueda(); getch();
                break;
            case 3:
                elimininarNodo(); getch();
                break;
            case 4:
                imprimir(); getch();
                break;
            case 5:
                system("cls"); system("color 0C");
                cout << "\n\t\t Adios..." << endl;
                break;
            default:
                system("color 04");
                cout << "\n\t No es una opcion valida" << endl; getch();
        }
    }while(opcion!=5);
    return 0;
}

///****Comentarios****
//Funci�n
void insertarNodo(){
    system("cls"); system("color 01");
    //Varaibles a utilizar.
    pNuevo = (avl *)malloc(sizeof(avl));//Buscar espacio en memoria.
    int equilibrio=0, h=0;

    if(pNuevo==NULL){//Si el nodo pNuevo esta NULL.
        cout << "\n\t No hay espacio en memoria disponible para crear mas nodos..." << endl;
    }else{
        /*Ingreso de datos al nodo e inicializaci�n de sus punteros*/
        cout << "\n \t**********INGRESO DE DATOS**********\n" << endl;
        cout << " Ingrese codigo: "; cin >> pNuevo->codigo; cin.ignore();

        if((comprobarDato(pNuevo->codigo) == true)){//Comprobar que no exista un c�digo igual en el �rbol AVL.
            return;//Regresa al men� principal.
        }else{}
        pNuevo->pPadre = NULL;
        pNuevo->pIzq   = NULL;
        pNuevo->pDer   = NULL;
        /*Fin*/
        pRecorrido = pRaiz;//Igualar para comenzar a recorrer el �rbol AVL.
        //Ciclo While para guardar el puntero Padre. Mientras no este en un nodo NULL y el codigo ingresar sea diferente del mismo.
        while(pRecorrido!=NULL && pNuevo->codigo!=pRecorrido->codigo){
            pPadre = pRecorrido;//Guarda en pPadre el puntero actual de recorrido.
            if(pNuevo->codigo < pRecorrido->codigo)//Condicional para indicar el siguiente puntero en el ciclo.
                pRecorrido = pRecorrido->pIzq;//Salto al sig. puntero para seguir recorrido de lado Izq. del �rbol AVL.
            else
                pRecorrido = pRecorrido->pDer;//Salto al sig. puntero para seguir recorrido de lado Der. del �rbol AVL.
        }

        if(pPadre == NULL){//Condicional para saber si pPadre es NULL, el �rbol AVL esta vac�o, el nodo ingresado ser� la raiz.
            pRaiz = pNuevo;//Ser� la ra�z.
            system("color 0A"); cout << "\n\t Registro Guardado." << endl;
            cout << " Codigo:           \t" << pNuevo->codigo << "." << endl;
            //return;
        }else if(pNuevo->codigo < pPadre->codigo){//Codigo menor, que al de su nodo padre.
            //pNuevo->equilibrio=pNuevo->equilibrio+1;
            pPadre->pIzq = pNuevo;//Guarda el nodo ingresado en puntero pIzq del nodo padre.
            pPadre->pIzq->pPadre = pPadre;//
            //pActual = pPadre->pIzq;//
            //La sig. funci�n a llamar necesita: El nodo y la rama de sus padre en que fue agregado el nodo.
            equilibrarIn(pPadre, izquierda);


            system("color 0A"); cout << "\n\t Registro Guardado." << endl;
            cout << " Codigo:           \t" << pNuevo->codigo << "." << endl;

        }else if(pNuevo->codigo > pPadre->codigo){//Codigo mayor, que al de su nodo padre.
            //pNuevo->equilibrio=pNuevo->equilibrio+1;
            pPadre->pDer = pNuevo;//Guarda el nodo ingresado en puntero pDer del nodo padre.
            pPadre->pDer->pPadre = pPadre;//
            //pActual = pPadre->pDer;//
            //La sig. funci�n a llamar necesita: El nodo y la rama de su padre en que fue agregado el nodo.
            equilibrarIn(pPadre, derecha);


            system("color 0A"); cout << "\n\t Registro Guardado." << endl;
            cout << " Codigo:           \t" << pNuevo->codigo << "." << endl;
        }
    }
}

//Funci�n para evitar el ingreso de dos nodos con el mismo c�digo.
bool comprobarDato(int cod){
    pRecorrido = pRaiz;//Igualar para comenzar a recorrer el �rbol AVL.
    while(pRecorrido != NULL){//Mientras no este en el ultimo nodo del �rbol AVL.
        if(cod == pRecorrido->codigo){//Condici�n para comparar lo del �rbol AVL con el dato nuevo.
            system("color 04");
            cout << "\n\t Lo sentimos, el codigo: " << cod <<". Esta existente, intente de nuevo." << endl;
            return true;//Codigo nuevo, ya fue ingresado antes.
        }else if(cod < pRecorrido->codigo){//Condicional para indicar el siguiente puntero en el ciclo.
            pRecorrido = pRecorrido->pIzq;//Salto al sig. puntero para seguir recorrido de lado Izq. del �rbol AVL.
        }else if(cod > pRecorrido->codigo){//Condicional para indicar el siguiente puntero en el ciclo.
            pRecorrido = pRecorrido->pDer;//Salto al sig. puntero para seguir recorrido de lado Der. del �rbol AVL.
        }
    }
    return false;//Codigo nuevo, no esta en el �rbol AVL.
}

//Funci�n
int hMayor(int izq, int der){
    if(izq > der){
        return izq;
    }else{
        return der;
    }
}

//Funci�n
int factorEqui(avl *pNodo){
    if(pNodo==NULL){
        return 0;
    }else{}
    return pNodo->equilibrio;
}

//Funci�n
int comprobarBalance(avl *pNodo){
    if(pNodo==NULL){
        return 0;
    }else{
        //cout << "\t Nodo NULL" << endl;
        return factorEqui(pNodo->pIzq) - factorEqui(pNodo->pDer);;
    }
}



//Funci�n
void re_sDer(avl *pNodo){
    //Nodos para ayudar a re-estructurar.
    avl *pTemp1, *pTemp2;
    pTemp1 = pNodo->pIzq;
    pTemp2 = pTemp1->pDer;

    //Realizar re-estructuraci�n.
    pTemp1->pDer = pNodo;
    pNodo->pIzq = pTemp2;

    //Actualizar factores de equilibrio.
    pNodo->equilibrio = hMayor(factorEqui(pNodo->pIzq), factorEqui(pNodo->pDer))+1;
    pTemp1->equilibrio = hMayor(factorEqui(pTemp1->pIzq), factorEqui(pTemp1->pDer))+1;
}

//Funci�n
void re_sIzq(avl *pNodo){
    //Nodos para ayudar a re-estructurar.
    avl *pTemp1, *pTemp2;
    pTemp1 = pNodo->pDer;
    pTemp2 = pTemp1->pIzq;

    //Realizar re-estructuraci�n.
    pTemp1->pIzq = pNodo;
    pNodo->pDer = pTemp2;

    //Actualizar factores de equilibrio.
    pNodo->equilibrio = hMayor(factorEqui(pNodo->pIzq), factorEqui(pNodo->pDer))+1;
    pTemp1->equilibrio = hMayor(factorEqui(pTemp1->pIzq), factorEqui(pTemp1->pDer))+1;
}

///Seguir intentando, que aun no funciona.
//Funci�n
void equilibrarIn(avl *pNodo, int rama){
    int equilibrado=1;//Varible para detener ciclo con codicionales.
    //cout << pNodo->pPadre->codigo << endl;
    //cout << pNodo->codigo << endl;
    //Ciclo While, para recorrer el �rbol e ir comparando el factor de equilibrio del nodo en cada recorrido, para verificar si se necesita re-estructuraci�n.
    while(pNodo!=NULL && equilibrado==1){//Cumplir el ciclo mientras el nodo actual del ciclo no sea NULL, y equilibrado = 1.
        //cout << " \t Inicio..." << endl;
        //Paso 1�: Asignar valor a los factores de equilibrio de cada nodo.
        if(rama==derecha){//Condicional para saber en que rama de su nodo padre, se encuentra el nodo actual del ciclo.
            //cout << " \t 1.1 Aumenta derecha" << endl;
            pNodo->equilibrio++;//Aumenta en 1 en 1 el factor de equilibrio del nodo actual del ciclo.
        }else{
            //scout << " \t 1.2 Aumenta izquierda" << endl;
            pNodo->equilibrio--;//Disminuye en 1 en 1 el factor de equilibrio del nodo actual del ciclo.
        }
        //cout << " \nNODO ACTUAL" << endl;
        //cout << " Codigo:                 \t" << pNodo->codigo << "." << endl;
        //cout << " Factor de equilibrio:   \t" << pNodo->equilibrio << "." << endl;
        //Paso 2�: Comparar los factores de equilibrio para modificar apuntadores,con posible casos de re-estructaraci�n.
        if(pNodo->equilibrio==0){//1. Caso: Concicional para verifcar si el factor de equilibrio no ha variado, por lo cual el �rbol AVL esta balanceado.
            //cout << " \t Balanceado." << endl;
            equilibrado=2;//Rompe el ciclo, sale de la funci�n.
        }else if(pNodo->equilibrio==-2){//2. Caso: Codicional para comparar el factor de equilibrio y verificar si el desbalance se encuentra de lado izquierdo.
            //cout << " \t 2.1 Entro" << endl;
            if(pNodo->pIzq->equilibrio==1){//Condicional para verificar si se necesita Re-estructuraci�n .
                //cout << " \t RID" << endl;
                RID(pNodo);
            }else{//Se necesita Re-estructuraci�n II.
                //cout << " \t RDD" << endl;
                RII(pNodo);
            }
            equilibrado=3;//Rompe el ciclo, sale de la funci�n.
        }else if(pNodo->equilibrio==2){//2. Caso: Codicional para comparar el factor de equilibrio y verificar si el desbalance se encuentra de lado derecho.
            //cout << " \t 2.2 Entro" << endl;
            if(pNodo->pDer->equilibrio==-1){//Condicional para verificar si se necesita Re-estructuraci�n .
                //cout << " \t RDI" << endl;
                RDI(pNodo);
            }else{//Se necesita re-estructuraci�n R-estructuraci�n DD.
                //cout << " \t RII" << endl;
                RDD(pNodo);
            }
            equilibrado=4;//Rompe el ciclo, sale de la funci�n.
        }
        //Paso 3�: Asignar el siguiente nodo, en el recorrido del ciclo.
        if(pNodo->pPadre!=NULL){//Condicional para verificar si el padre del nodo actual del recorrido no es NULL.
            //cout << " \t Comparando.." << endl;
            if(pNodo->pPadre->pDer==pNodo){//Condicional para verificar en que rama de su nodo padre, se encuentra el nodo actual del recorrido.
                //cout << " \t 3.1 Derecha" << endl;
                rama=derecha;
            }else{
                //cout << " \t 3.2 Izquierda" << endl;
                rama=izquierda;
            }
        }else{
            //cout << "\n\t Rompe el ciclo..." << endl;
        }
        pNodo = pNodo->pPadre;//Siguiente nodo en el recorrido.
        //cout << " \t Fin...\n\n" << endl;
    }
}

//Funci�n
void equilibrarFree(avl *pNodo, int rama){
    int equilibrado=1;//Varible para detener ciclo con codicionales.
    //Ciclo While, para recorrer el �rbol e ir comparando el factor de equilibrio del nodo en cada recorrido, para verificar si se necesita re-estructuraci�n.
    while(pNodo!=NULL && equilibrado==1){//Cumplir el ciclo mientras el nodo actual del ciclo no sea NULL, y equilibrado = 1.
        //Paso 1�: Asignar valor a los factores de equilibrio de cada nodo.
        if(rama==izquierda){//Condicional para saber en que rama de su nodo padre, se encuentra el nodo actual del ciclo.
            pNodo->equilibrio++;//Aumenta en 1 en 1 el factor de equilibrio del nodo actual del ciclo.
        }else{
            pNodo->equilibrio--;//Disminuye en 1 en 1 el factor de equilibrio del nodo actual del ciclo.
        }
        //Paso 2�: Comparar los factores de equilibrio para modificar apuntadores,con posible casos de re-estructaraci�n.
        if(pNodo->equilibrio==0){//1. Caso: Concicional para verifcar si el factor de equilibrio no ha variado, por lo cual el �rbol AVL esta balanceado.
            //cout << " \t Balanceado." << endl;
            equilibrado=2;//Rompe el ciclo, sale de la funci�n.
        }else if(pNodo->equilibrio==-2){//2. Caso: Codicional para comparar el factor de equilibrio y verificar si el desbalance se encuentra de lado izquierdo.
            if(pNodo->pIzq->equilibrio==1){//Condicional para verificar si se necesita Re-estructuraci�n .
                RID(pNodo);
            }else{//Se necesita Re-estructuraci�n II.
                RII(pNodo);
            }
            equilibrado=3;//Rompe el ciclo, sale de la funci�n.
        }else if(pNodo->equilibrio==2){//2. Caso: Codicional para comparar el factor de equilibrio y verificar si el desbalance se encuentra de lado derecho.
            if(pNodo->pDer->equilibrio==-1){//Condicional para verificar si se necesita Re-estructuraci�n DI.
                RDI(pNodo);
            }else{//Se necesita re-estructuraci�n R-estructuraci�n DD.
                RDD(pNodo);
            }
            equilibrado=4;//Rompe el ciclo, sale de la funci�n.
        }
        //Paso 3�: Asignar el siguiente nodo, en el recorrido del ciclo.
        if(pNodo->pPadre!=NULL){//Condicional para verificar si el padre del nodo actual del recorrido no es NULL.
            if(pNodo->pPadre->pDer==pNodo){//Condicional para verificar en que rama de su nodo padre, se encuentra el nodo actual del recorrido.
                rama=derecha;
            }else{
                rama=izquierda;
            }
        }else{}
        pNodo = pNodo->pPadre;//Siguiente nodo en el recorrido.
    }
}

//Funci�n
void RII(avl *pNodo){
    cout << "\t Re-estructuracion Izquierda Izquierda" << endl;
    //Asignaci�n de valor a los punteros.
    pTemp = pNodo;//Igualar con el nodo que entro a la funci�n.
    pTemp1 = pNodo->pPadre;//Guardar� el nodo padre del que entr� a la funci�n.
    pTemp2 = pTemp->pIzq;//Guardar� el nodo de la Izquierda, del que entr� a la funci�n.
    pTemp3 = pTemp2->pDer;//Guardar� el nodo de la Derecha, del de la izquierda que entr� a la funci�n.
    if(pTemp1!=NULL){//Condicional para saber si el nodo padre esta vaci�.
        if(pTemp1->pDer==pTemp){//Condicional para verificar si el padre del nodo, tiene un hijo Izquierdo o Derecho.
            pTemp1->pDer=pTemp2;//Hijo derecho del nodo padre, se actualiza.
        }else{
            pTemp1->pIzq=pTemp2;//Hijo izquierdo del nodo padre, se actualiza.
        }
    }else{
        pRaiz=pTemp2;//Se actualiza la nueva ra�z del �rbol AVL.
    }
    //Re-estructurar nodos afectados del �rbol AVL.
    pTemp->pIzq=pTemp3;//Actualizar el nuevo valor al nodo descendiente a la izquierda, del que ocasiono el desbalance.
    pTemp2->pDer=pTemp;//Actualizar el nuevo valor al nodo.
    //Asignar nuevos padres a los nodos.
    pTemp->pPadre=pTemp2;//Asignar nuevo padre al nodo que ocasiono el desbalance.
    if(pTemp3!=NULL){//Condicional para saber si el nodo valuado esta vaci�.
        pTemp3->pPadre=pTemp;//Nuevo nodo padre para el nodo que ocasiono el desbalance.
    }else{}
    pTemp2->pPadre=pTemp1;//Nuevo nodo padre al puntero.
    pTemp->equilibrio=0;//Asignar nuevo valor al factor de equilibrio.
    pTemp2->equilibrio=0;//Asignar nuevo valor al factor de equilibrio.
}

//Funci�n
void RDD(avl *pNodo){
    cout << "\t Re-estructuracion Derecha Derecha" << endl;
    //Asignaci�n de valor a los punteros.
    pTemp = pNodo;//Igualar con el nodo que entro a la funci�n.
    pTemp1 = pNodo->pPadre;//Guardar� el nodo padre del que entr� a la funci�n.
    pTemp2 = pTemp->pDer;//Guardar� el nodo de la derecha, del que entr� a la funci�n.
    pTemp3 = pTemp2->pIzq;//Guardar� el nodo de la izquierda, del la derecha que entro a la funci�n.
    if(pTemp1!=NULL){//Condicional para saber si el nodo padre esta vaci�.
        if(pTemp1->pDer==pTemp){//Condicional para verificar si el padre del nodo, tiene un hijo Izquierdo o Derecho.
            pTemp1->pDer=pTemp2;//Hijo derecho del nodo padre, se actualiza.
        }else{
            pTemp1->pIzq=pTemp2;//Hijo izquierdo del nodo padre, se actualiza.
        }
    }else{
        pRaiz=pTemp2;//Se actualiza la nueva ra�z del �rbol AVL.
    }
    //Re-estructurar nodos afectados del �rbol AVL.
    pTemp->pDer=pTemp3;//Actualizar el uevo valor al nodo descendiente a la derecha, del que ocasiono el desbalance.
    pTemp2->pIzq=pTemp;//Actualizar el nuevo valor al nodo.
    //Asignar nuevos padres a los nodos.
    pTemp->pPadre=pTemp2;//Asignar nuevo padre al nodo que ocasiono el desbalance.
    if(pTemp3!=NULL){//Condicional para saber si el nodo valuado esta vaci�.
        pTemp->pPadre=pTemp;//Nuevo nodo padre para el nodo que ocasiono el desbalance.
    }else{}
    pTemp2->pPadre=pTemp1;//Nuevo nodo padre al puntero.
    pTemp->equilibrio=0;//Asignar nuevo valor al factor de equilibrio.
    pTemp2->equilibrio=0;//Asignar nuevo valor al factor de equilibrio.
}

//Funci�n
void RDI(avl *pNodo){
    cout << "\t Re-estructuracion Derecha Izquierda" << endl;
    //Asignaci�n de valor a los punteros.
    pTemp = pNodo;//Igualar con el nodo que entro a la funci�n.
    pTemp1 = pNodo->pPadre;//Guardar� el nodo padre del que entr� a la funci�n.
    pTemp2 = pTemp->pDer;//Guardar� el nodo de la derecha, del que entr� a la funci�n.
    pTemp3 = pTemp2->pIzq;//Guardar� el nodo de la izquierda, del de la derecha que entro a la funci�n.
    pTemp4 = pTemp3->pIzq;//Guardar� el nodo de la izuierda, del de la izquierda, del de la derecha que entro a la funci�n.
    pTemp5 = pTemp3->pDer;//Guardar� el nodo de la derecha, del de la izquierda, del de la derecha que entro a la funci�n.
    if(pTemp1!=NULL){//Condicional para saber si el nodo padre esta vaci�.
        if(pTemp1->pDer==pNodo){//Condicional para verificar si el padre del nodo, tiene un hijo Izquierdo o Derecho.
            pTemp1->pDer=pTemp3;//Hijo derecho del nodo padre, se actualiza.
        }else{
            pTemp1->pIzq=pTemp3;//Hijo izquierdo del nodo padre, se actualiza.
        }
    }else{
        pRaiz=pTemp3;//Se actualiza la nueva ra�z del �rbol AVL.
    }
    //Re-estructurar nodos afectados del �rbol AVL.
    pTemp->pDer=pTemp4;//Actualizar el nuevo valor al nodo descendiente a la derecha, del que ocasiono el desbalance.
    pTemp2->pIzq=pTemp5;//Actualizar el nuevo valor al nodo, en su descendiente izquierdo.
    pTemp3->pIzq=pTemp;//Actualizar el nuevo valor al nodo, en su descendiente izquierdo.
    pTemp3->pDer=pTemp2;//Actualizar el nuevo valor al nodo, en su descendiente derecho.
    //Asignar nuevos padres a los nodos.
    pTemp3->pPadre=pTemp1;//Asignar nuevo padre al nodo.
    pTemp->pPadre=pTemp3;//Asignar nuevo padre al nodo que ocasiono el desbalance.
    pTemp2->pPadre=pTemp3;//Asignar nuevo padre al nodo.
    if(pTemp4!=NULL){//Condicional para saber si el nodo valuado esta vaci�.
        pTemp4->pPadre=pTemp;//Asignar nuevo padre al nodo, que ser� el que ocasiono el desbalance.
    }else{}
    if(pTemp5!=NULL){//Condicional para saber si el nodo valuado esta vaci�.
        pTemp5->pPadre=pTemp2;//Asignar nuevo padre al nodo.
    }else{}
    //Codicionales para actualizar los factores de equilibrio de los nodos afectados en la re-estructuraci�n.
    if(pTemp3->codigo==0){//Condicional para verificar si el factor de equilibrio es 0.
        pTemp->equilibrio=0;//Asignar nuevo valor al factor de equilibrio.
        pTemp2->equilibrio=0;//Asignar nuevo valor al factor de equilibrio.
    }else if(pTemp3->codigo==-1){//Condicional para verificar si el factor de equilibrio es -1.
        pTemp->equilibrio=0;//Asignar nuevo valor al factor de equilibrio.
        pTemp2->equilibrio=1;//Asignar nuevo valor al factor de equilibrio.
    }else if(pTemp3->codigo==1){//Condicional para verificar si el factor de equilibrio es 1.
        pTemp->equilibrio=-1;//Asignar nuevo valor al factor de equilibrio.
        pTemp2->equilibrio=0;//Asignar nuevo valor al factor de equilibrio.
    }
    pTemp3->equilibrio=0;//Asignar nuevo valor al factor de equilibrio.
}

//Funci�n
void RID(avl *pNodo){
    cout << "\t Re-estructuracion Izquierda Derecha" << endl;
    //Asignaci�n de valor a los punteros.
    pTemp = pNodo;//Igualar con el nodo que entro a la funci�n.
    pTemp1 = pNodo->pPadre;//Guardar� el nodo padre del que entr� a la funci�n.
    pTemp2 = pTemp->pIzq;//Guardar� el nodo de la izquierda, del que entr� a la funci�n.
    pTemp3 = pTemp2->pDer;//Guardar� el nodo de la derecha, del de la izquierda que entro a la funci�n.
    pTemp4 = pTemp3->pIzq;//Guardar� el nodo de la izuierda, del de la izquierda, del de la derecha que entro a la funci�n.
    pTemp5 = pTemp3->pDer;//Guardar� el nodo de la derecha, del de la izquierda, del de la derecha que entro a la funci�n.
    if(pTemp1!=NULL){//Condicional para saber si el nodo padre esta vaci�.
        if(pTemp1->pDer==pNodo){//Condicional para verificar si el padre del nodo, tiene un hijo Izquierdo o Derecho.
            pTemp1->pDer=pTemp3;//Hijo derecho del nodo padre, se actualiza.
        }else{
            pTemp1->pIzq=pTemp3;//Hijo izquierdo del nodo padre, se actualiza.
        }
    }else{
        pRaiz=pTemp3;//Se actualiza la nueva ra�z del �rbol AVL.
    }
    //Re-estructurar nodos afectados del �rbol AVL.
    pTemp2->pDer=pTemp4;//Actualizar el nuevo valor al nodo, en su descendiente derecho.
    pTemp->pIzq=pTemp5;//Nuevo valor al nodo descendiente a la izquierda, del que ocasiono el desbalance.
    pTemp3->pIzq=pTemp2;//Actualizar el nuevo valor al nodo, en su descendiente izquierdo.
    pTemp3->pDer=pTemp;//Actualizar el nuevo valor al nodo, en su descendiente derecho.
    //Asignar nuevos padres a los nodos.
    pTemp3->pPadre=pTemp1;//Asignar nuevo padre al nodo.
    pTemp->pPadre=pTemp3;//Asignar nuevo padre al nodo que ocasiono el desbalance.
    pTemp2->pPadre=pTemp3;//Asignar nuevo padre al nodo.
    if(pTemp4!=NULL){//Condicional para saber si el nodo valuado esta vaci�.
        pTemp4->pPadre=pTemp2;//Asignar nuevo padre al nodo.
    }else{}
    if(pTemp5!=NULL){//Condicional para saber si el nodo valuado esta vaci�.
        pTemp5->pPadre=pTemp;//Asignar nuevo padre al nodo.
    }else{}
    //Codicionales para actualizar los factores de equilibrio de los nodos afectados en la re-estructuraci�n.
    if(pTemp3->codigo==0){//Condicional para verificar si el factor de equilibrio es 0.
        pTemp2->equilibrio=0;//Asignar nuevo valor al factor de equilibrio.
        pTemp->equilibrio=0;//Asignar nuevo valor al factor de equilibrio.
    }else if(pTemp3->codigo==-1){//Condicional para verificar si el factor de equilibrio es -1.
        pTemp2->equilibrio=0;//Asignar nuevo valor al factor de equilibrio.
        pTemp->equilibrio=1;//Asignar nuevo valor al factor de equilibrio.
    }else if(pTemp3->codigo==1){//Condicional para verificar si el factor de equilibrio es 1.
        pTemp2->equilibrio=-1;//Asignar nuevo valor al factor de equilibrio.
        pTemp->equilibrio=0;//Asignar nuevo valor al factor de equilibrio.
    }
    pTemp3->equilibrio=0;//Asignar nuevo valor al factor de equilibrio.
}

//Funci�n
void menuBusqueda(){
     do{
        system("cls"); system("color 09");
        cout << "\n\t ********** REALIZAR BUSQUEDA EN EL ARBOL AVL **********\n" << endl;
        cout << "\t .--------------------------------." << endl;
        cout << "\t | 1 ||    Busqueda por Codigo    |" << endl;
        cout << "\t | 2 ||    Busqueda por Nombre    |" << endl;
        cout << "\t | 3 || Volver al Menu Principal  |" << endl;
        cout << "\t '--------------------------------'\n" << endl;
        cout << " Digite su opcion: "; cin >> opc; cin.ignore();
        switch(opc){
            case 1:
                buscarCodigo(); getch();
                break;
            case 2:
                //buscarNombre(); getch();
                break;
            case 3:
                break;
            default:
                cout << "\n\t No es una opcion valida" << endl; getch();
        }
    }while(opc!=3);
}

//Funci�n
void buscarCodigo(){
    //Variables a utilizar.
    int codigo=0;
    bool encontrado=false;

    system("cls"); system("color 09");
    cout << "\n\t ************ BUSCAR NODO POR EL CODIGO ************\n" << endl;
    cout << " Digite el codigo a buscar:        \t" ; cin >> codigo; cin.ignore();
    pRecorrido = pRaiz;//Igualar para comenzar a recorrer el �rbol AVL.
    if(pRaiz != NULL){//Condicional para verificar si el �rbol AVL tiene nodos.
        while(pRecorrido != NULL){//Mientras no este en el ultimo nodo del �rbol AVL.
            if(codigo == pRecorrido->codigo){//Condici�n para comparar lo del �rbol AVL con el dato nuevo.
                system("color 0A");
                cout << "\n\t Registro encontrado!" << endl;
                cout << " Codigo:           \t" << pRecorrido->codigo << "." << endl;
                cout << " Factor de Equilibrio: \t" << pRecorrido->equilibrio << "." << endl;
                encontrado = true;
                return; //Nodo econtrado, salir de la funci�n.
            }else if(codigo < pRecorrido->codigo){//Condicional para indicar el siguiente puntero en el ciclo.
                pRecorrido = pRecorrido->pIzq;//Salto al sig. puntero para seguir recorrido de lado Izq. del �rbol AVL.
            }else if(codigo > pRecorrido->codigo){//Condicional para indicar el siguiente puntero en el ciclo.
                pRecorrido = pRecorrido->pDer;//Salto al sig. puntero para seguir recorrido de lado Der. del �rbol AVL.
            }
        }
        if(encontrado==false){//Condicional por si no se encuentra el codigo ingresado.
            system("color 04");
            cout << "\n El codigo que ingreso, ( " << codigo << " )." << endl;
            cout << " No pertenece a ningun nodo del arbol AVL." << endl;
        }else{}
    }else{
        system("color 04");
        cout << " \n\t El arbol AVL no existe aun." << endl;
    }
}

//Funci�n
void buscarNombre(){

}

///Aun no me funciona bien, se debe mejorar bastante.
//Funci�n
void elimininarNodo(){
    //Variables a utilizar.
    int codigo=0, cod=0;
    bool encontrado=false;
    pPadre=NULL;//Igualar puntero a NULL, para empezar a guardar nodos en el recorrido.

    system("cls"); system("color 09");
    cout << "\n\t ************ ELIMINAR NODO POR EL CODIGO ************\n" << endl;
    cout << " Digite el codigo a eliminar:        \t" ; cin >> codigo; cin.ignore();
    pRecorrido = pRaiz;//Igualar para comenzar a recorrer el �rbol AVL.
    if(pRaiz != NULL){//Condicional para verificar si el �rbol AVL tiene nodos.
        while(pRecorrido != NULL){//Mientras no este en el ultimo nodo del �rbol AVL.
            if(codigo == pRecorrido->codigo){//Condici�n para comparar lo del �rbol AVL con el dato nuevo.
                system("color 0A");
                cout << "\n\t Registro encontrado!" << endl;
                cout << " Codigo:           \t" << pRecorrido->codigo << "." << endl;
                //cout << " Factor de Equilibrio: \t" << pRecorrido->equilibrio << "." << endl;
                encontrado = true;

                //Hay tres posibles casos para eliminar dentro de un �rbol AVL.
                //1�er Caso: Que el nodo a eliminar sea hoja o terminal, simplemente suprimirlo.
                if(pRecorrido->pIzq==NULL && pRecorrido->pDer==NULL){//Si los apuntadores de la izq. y der. del nodo actual son null, el nodo es hoja.
                    if(pPadre!=NULL){//Condicional, para verificar si el nodo padre es la ra�z del �rbol.
                        if(pPadre->pDer==pRecorrido){//Condicional para verficar si el nodo actual del ciclo es hijo izq. o der. de su padre.
                            pPadre->pDer=NULL;//La referencia del nodo padre a su a eliminar, ahora ser� NULL.
                            //pPadre->equilibrio=pPadre->equilibrio-1;//Actualizar el factor de equilibrio del nodo padre.
                        }else{
                            pPadre->pIzq=NULL;//La referencia del nodo padre a su a eliminar, ahora ser� NULL.
                            //pPadre->equilibrio=pPadre->equilibrio+1;
                        }
                    }else{}
                    //cout << "\n\t   " << pPadre->equilibrio <<endl;
                    delete pRecorrido;//Eliminar el nodo solicitado.
                    pRecorrido=NULL;//Igualar a NUll, para utilizarlo en la siguiente codicional.

/*                    if(pPadre->pDer!=NULL){
                        equilibrarIn(pPadre, derecha);
                        //pPadre->equilibrio=0;
                    }else{
                        equilibrarIn(pPadre, izquierda);
                        //pPadre->equilibrio=0;
                    }   */

///******** AUNN FALTA MODIFICAR
                    //Condicional para actualizar el nuevo factor de equilibrio del nodo padre.
                    if((pPadre->pDer==NULL && pPadre->equilibrio==1) || (pPadre->pIzq==NULL && pPadre->equilibrio==-1)){
                        pPadre->equilibrio=0;//Nuevo factor de equilibrio, para el nodo padre.
                        pRecorrido=pPadre;//Igualar apuntadores.
                        pPadre=pRecorrido->pPadre;//Actualizar los valores del nodo padre, para proceder a re-estructurar de ser necesario.
                    }else{}


                    if(pPadre!=NULL){//Condicional, para verificar si el nodo padre es la ra�z del �rbol.
                        if(pPadre->pDer==pRecorrido){//Condicional para verificar si el nodo, es hijo izquierdo o derecho.
                            //Hijo de la derecha.
                            equilibrarFree(pPadre, derecha);//Funci�n para equilibrar de ser necesario.
                        }else{
                            //Hijo de la izquierda.
                            equilibrarFree(pPadre, izquierda);//Funci�n para equilibrar de ser necesario.
                        }
                    }else{}


                    system("color 0C");
                    cout << "\n\t El nodo fue eliminado del arbol AVL\n" << endl;
                    return; //Nodo econtrado y eliminado, salir de la funci�n.
                }else{//No es hoja el nodo a eliminar.
                    /*
                    pPadre=pRecorrido;

                    ///**** No s� como funciona a�n del todo esta parte del algoritmo.
                    //2�do Caso: Si el nodo a eliminar tiene un solo descendiente, sustituir por ese descendiente.
                    if(pRecorrido->pDer!=NULL){
                        pTemp6 = pRecorrido->pDer;//Guarda lo apuntado a la derecha, del nodo actual del recorrido.
                        while(pRecorrido->pIzq!=NULL){//Mientras lo que tenga apuntado a la izquierda no sea NULL.
                            pPadre = pTemp6;//Actualizar nuevo nodo padre.
                            pRecorrido = pRecorrido->pIzq;//Siguiente nodo en el ciclo.
                        }

                    }else{//3�er Caso: Si el nodo a eliminar tiene dos descendientes, sustituir por nodo +D del SI.
                        pTemp6 = pRecorrido->pIzq;//Guarda lo apuntado a la izquierda, del nodo actual del recorrido.
                        while(pRecorrido->pDer!=NULL){//Mientras lo que tenga apuntado a la derecha no sea NULL.
                            pPadre = pTemp6;//Actualizar nuevo nodo padre.
                            pRecorrido = pRecorrido->pDer;//Siguiente nodo en el ciclo.
                        }
                    }
                    //Realizando cambios a los nodos afectados.
                    cod = pRecorrido->codigo;
                    pRecorrido->codigo = pTemp6->codigo;
                    pTemp6->codigo =cod;
                    pRecorrido = pTemp6;
                    */
                }
            }else{
                pPadre=pRecorrido;//Guardar el nodo actual, ya que ser� el padre del siguiente en entrar al ciclo.
                if(codigo < pRecorrido->codigo){//Condicional para indicar el siguiente puntero en el ciclo.
                    pRecorrido = pRecorrido->pIzq;//Salto al sig. puntero para seguir recorrido de lado Izq. del �rbol AVL.
                }else if(codigo > pRecorrido->codigo){//Condicional para indicar el siguiente puntero en el ciclo.
                    pRecorrido = pRecorrido->pDer;//Salto al sig. puntero para seguir recorrido de lado Der. del �rbol AVL.
                }
            }
        }
        if(encontrado==false){//Condicional por si no se encuentra el codigo ingresado.
            system("color 04");
            cout << "\n El codigo que ingreso, ( " << codigo << " )." << endl;
            cout << " No pertenece a ningun nodo del arbol AVL." << endl;
        }else{}
    }else{
        system("color 04");
        cout << " \n\t El arbol AVL no existe aun." << endl;
    }
}

//Funci�n para imprimir el �rbol AVL.
void imprimir(){
    system("cls"); system("color 0D");
    ejeX = 0; //Actualizar varaible a cero antes de ser utilizada
    cout << "\n\t\t\t********** ARBOL AVL **********\n" << endl;
    graficarArbol(pRaiz, 0);
}

///Se puede mejorar.
//Funci�n  para graficar en la consola el diagrama del �rbol AVL con los datos de los nodos.
void graficarArbol(avl *pAVL, int ejeY){
    if(pAVL == NULL){ //Si el �rbol AVL esta vaci�.
        return;//Salir de la funci�n.
    }else{
        ejeX += 5; //Posici�n en el eje X de la consola.
        graficarArbol(pAVL->pIzq, ejeY+2); //Se pocisiona en la hoja m�s a la Izquierda del �rbol AVL.
        gotoxy(6+ejeX-ejeY, 3+ejeY-1);//Posici�n de la cadena a imprimir en pantalla.
        cout << "  * " << endl << endl;
        gotoxy(6+ejeX-ejeY, 3+ejeY);//Posici�n de la cadena a imprimir en pantalla.
        cout << "(" << pAVL->codigo <<  ")" << endl << endl;
        graficarArbol(pAVL->pDer, ejeY+2); //Se pocisiona en la hoja m�s a la Derecha del �rbol AVL.
    }
}

///Buscar informaci�n
//Funci�n para asignar una posici�n de pantalla con los ejes X, Y cuando se vaya a imprimir en pantalla.
void gotoxy(int x,int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon,dwPos);
}
