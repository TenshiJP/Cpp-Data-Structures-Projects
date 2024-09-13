/*
                +------------------------------------------------------------------------+
                |                                                                        |
                |            Proyecto de Programación III / Estructura de datos          |
                |                                                                        |
                |                Datos:                                                  |
                |                Nombre:     Angel Roberto Jacinto Payes                 |
                |                No.Carnet:  5990-20-1756                                |
                |                                                                        |
                +------------------------------------------------------------------------+
*/
#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

//Estructura para el nodo.
typedef struct arbolBB{
    //Datos del puntero.
    int    codigo;
    char   nombre[65];
    int    edad;
    char   dpi[16];
    int    telefono;
    char   mail[60];
    char   direccion[70];
    struct arbolBB *pIzq;
    struct arbolBB *pDer;
    int    equilibrio;  //Varabile para calcular el factor de equilibrio del nodo.
} avl;

avl *pArbolAVL = NULL;//Puntero que será utilizado para generar el árbol AVL.

//Funciones a utilizar.
void nuevoNodo();                                      //Función para empezar el procedimiento de ingresar un nuevo nodo en el árbol AVL.
avl *insertarNodo(avl *pNodo, int codigo);             //Función para buscar la posición en el árbol AVL en se guardará el nuevo nodo.
bool comprobarCodigo(int codigo, bool encontrado);     //Función para verificar si ya existe un nodo con el código ingresado a la función en el árbol AVL.
avl *datosNodo(int codigo);                            //Función para terminar el procedimiento de un nuevo nodo al árbol AVL, que permite terminar de ingresar los datos solicitados.
int hMayor(int izq, int der);                          //Función para verificar el entero mayor de los dos ingresados a la función.
int fEquilibrio(avl *pNodo);                           //Funcion para devolver el factor de equilibrio de un nodo.
int balance(avl *pNodo);                               //Función para comprobar que se encuentre balanceado un nodo en el árbol AVL.
avl *RDD(avl *pNodo);                                  //Función para reestructurar los nodos desbalanceados en el árbol AVL.
avl *RII(avl *pNodo);                                  //Función para reestructurar los nodos desbalanceados en el árbol AVL.
avl *RDI(avl *pNodo);                                  //Función para reestructurar los nodos desbalanceados en el árbol AVL.
avl *RID(avl *pNodo);                                  //Función para reestructurar los nodos desbalanceados en el árbol AVL.
void buscarCodigo();                                   //Función para buscar un nodo en el árbol AVL por medio de un código.
void eliminar();                                       //Función que empiza el procedimiento de eliminar un nodo por medio de su código.
avl *eliminarNodo(avl *pAVL, int codigo);              //Función para eliminar un nodo del árbol AVL por medio de un código.
void imprimir();                                       //Función para comenzar el proceso de graficar el árbol AVL en la consola.
void graficarArbol(avl *pAVL, int ejeY);               //Función para graficar en la consola el diagrama del árbol AVL con el código de los nodos.
void parpadeo(string texto, int x, int y, int tiempo); //Función que perimite que una cadena cambie de color cada cierto momento dado.
void parpadeoTexto(int tiempo);                        //Función para aplicar el cambio de color a unas cadenas que serán mostradas al ejecutar y cerrar el programa.
void titulo();                                         //Función que imprime "ARBOL AVL" en 2D en pantalla.
void gotoxy(int x,int y);                              //Función para asignar una posición de pantalla con los ejes X, Y cuando se vaya a imprimir en pantalla.

//Variables a utiliazar.
int opcion=0, ejeX=0;

//Función principal.
int main(){
    parpadeoTexto(25);
    do{
        system("cls"); titulo(); system("color 07");
        cout << "\n\n\t\t +----------------------------------------------+" << endl;
        cout << "\t\t |                                              |" << endl;
        cout << "\t\t |         ***** MENU DE OPCIONES *****         |" << endl;
        cout << "\t\t |                                              |" << endl;
        cout << "\t\t +----------------------------------------------+" << endl;
        cout << "\t\t |    ||                                        |" << endl;
        cout << "\t\t | 1. ||       Agregar nodos al Arbol AVL       |" << endl;
        cout << "\t\t | 2. ||     Buscar un nodo en el Arbol AVL     |" << endl;
        cout << "\t\t | 3. ||     Eliminar un nodo del Arbol AVL     |" << endl;
        cout << "\t\t | 4. ||          Mostrar el Arbol AVL          |" << endl;
        cout << "\t\t | 5. ||                 Salir                  |" << endl;
        cout << "\t\t |    ||                                        |" << endl;
        cout << "\t\t +----------------------------------------------+\n" << endl;
        cout << "\t  Digite su opcion: "; cin >> opcion;
        switch(opcion){
            case 1:
                nuevoNodo(); getch();
                break;
            case 2:
                buscarCodigo(); getch();
                break;
            case 3:
                eliminar(); getch();
                break;
            case 4:
                imprimir(); getch();
                break;
            case 5:
                system("cls"); parpadeoTexto(15); titulo();
                system("color 0C"); cout << "\n\n\t\t\t\t S A L I E N D O . . . " << endl;
                break;
            default:
                system("color 04");
                cout << "\n\t No es una opcion valida" << endl; getch();
        }
    }while(opcion!=5);
    return 0;
}

//Función para empezar el procedimiento de ingresar un nuevo nodo en el árbol AVL.
void nuevoNodo(){
    system("cls"); system("color 01");
    int codigo=0;//Variable para ingresar el codigo que tendrá el nodo a ingresar en el árbol AVL.
    char l1[55] = "******************************************************";
    char l2[55] = "************* INGRESAR NODO AL ARBOL AVL *************";
    char l3[55] = "******************************************************";
    gotoxy(16,1);//Posición de la consola a imprimir el texto.
    for(int i=0;i<55;i++){//Ciclo for para recorrer la cadena. Linea 1.
        cout << l1[i];
        Sleep(8);//Tiempo de espera para continuar.
    }
    gotoxy(16,2);//Posición de la consola a imprimir el texto.
    for(int i=0;i<55;i++){//Ciclo for para recorrer la cadena. Linea 2.
        cout << l2[i];
        Sleep(8);//Tiempo de espera para continuar.
    }
    gotoxy(16,3);//Posición de la consola a imprimir el texto.
    for(int i=0;i<55;i++){//Ciclo for para recorrer la cadena. Linea 3.
        cout << l3[i];
        Sleep(8);//Tiempo de espera para continuar.
    }
    cout << "\n\n Ingrese codigo:           \t"; cin >> codigo; cin.ignore();
    if((comprobarCodigo(codigo, true) == true)){//Comprobar que no exista un nodo con un código igual en el árbol AVL.
        return;//Regresa al menú principal.
    }else{//De no estar en el árbol AVL, proceder a su ingreso.
        pArbolAVL = insertarNodo(pArbolAVL, codigo);//Llama a la función para su ingreso.
    }
}

//Función para buscar la posición en el árbol AVL en se guardará el nuevo nodo.
avl *insertarNodo(avl *pNodo, int codigo){
    int equilibrio=0;//Variable para actualizar el factor de equilibrio del nodo actual.
    //En la condicional si, es el primer ingreso será la raíz, de lo contrario será una nueva hoja dentro del árbol AVL.
    if(pNodo==NULL){//Condicional para saber si el puntero en el árbol AVL es NULL y agregar el nuevo nodo.
        //cout << "\t NULL" << endl;
        return datosNodo(codigo);//Función para ingresar el nodo en la posición actual, y terminar de registrar sus datos.
    }else{
        if(codigo < pNodo->codigo){//Condicional para verificar si el nodo a ingresar es menor, con el nodo que se esta comparando del árbol AVL.
            //cout << "\t BUSCAR LUEGAR EN LA IZQUIERDA" << endl;
            pNodo->pIzq = insertarNodo(pNodo->pIzq, codigo);//Volver a llamarse a si misma la función, pero ingresando a un nuevo puntero.
        }else if(codigo > pNodo->codigo){//Condicional para verificar si el nodo a ingresar es mayor, con el nodo que se esta comparando del árbol AVL.
            //cout << "\t BUSCAR LUGAR EN LA DERECHA" << endl;
            pNodo->pDer = insertarNodo(pNodo->pDer, codigo);//Volver a llamarse a si misma la función, pero ingresando a un nuevo puntero.
        }
    }
    pNodo->equilibrio = 1+hMayor(fEquilibrio(pNodo->pIzq), fEquilibrio(pNodo->pDer));//Actualizar el factor de equilibrio del nodo padre del nuevo.
    equilibrio = balance(pNodo);//Verificar si el árbol AVL se encuentra balanceado a partir del nodo padre, para proceder a re-estructurar de ser necesario.
    //Comparar el factor de equilibrio para modificar apuntadores, con posible casos de re-estructaración.
    switch(equilibrio){
    case 2://Caso en que el nodo tenga un 2 de factor de equilibrio.
        //Condicional para verificar que el nodo ingresado sea menor a su nodo padre.
        if(codigo < pNodo->pIzq->codigo){//Caso 1°: Re-estructuración Izquierda Izquierda
            cout << "\t Se ha aplicado la RII" << endl;
            return RII(pNodo);//Aplica RII para balancear el árbol AVL.
        //Condicional para verificar que el nodo ingresado sea mayor a su nodo padre.
        }else if(codigo > pNodo->pIzq->codigo){//Caso 2°: Re-estructuración Izquierda Derecha.
            cout << "\t Se ha aplicado la RID" << endl;
            return RID(pNodo);//Aplica RID para balancear el árbol AVL.
        }
        break;
    case -2://Caso en que el nodo tenga un -2 de factor de equilibrio.
        //Condicional para verificar que el nodo ingresado sea mayor a su nodo padre.
        if(codigo > pNodo->pDer->codigo){//Caso 3°: Re-estructuración Derecha Derecha.
            cout << "\t Se ha aplicado la RDD" << endl;
            return RDD(pNodo);//Aplica RDD para balancear el árbol AVL.
        //Condicional para verificar que el nodo ingresado sea menor a su nodo padre.
        }else if(codigo < pNodo->pDer->codigo){//Caso 4°: Re-estructuración Derecha Izquierda.
            cout << "\t Se ha aplicado la RDI" << endl;
            return RDI(pNodo);//Aplica RDI para balancear el árbol AVL.
        }
        break;
    }
    return pNodo;
}

//Función para verificar si ya existe un nodo con el código ingresado a la función en el árbol AVL.
bool comprobarCodigo(int codigo, bool encontrado){
    avl *pRecorrido = pArbolAVL;//Igualar para comenzar a recorrer el árbol AVL.
    while(pRecorrido != NULL){//Mientras no este en el ultimo nodo del árbol AVL.
        if(codigo == pRecorrido->codigo){//Condición para comparar lo del árbol AVL con el dato nuevo.
            if(encontrado == true){//Fue llamada por entrada de datos.
                system("color 04");
                cout << "\n\t Lo sentimos, el codigo: " << codigo <<". Esta existente, intente de nuevo." << endl;
            }else{//Fue llamada por eliminación de datos.
                system("color 0A");
                cout << "\n\t Registro encontrado en el arbol AVL!" << endl; Sleep(5);
                cout << " Codigo:           \t" << pRecorrido->codigo << "." << endl;
                cout << " Nombre:           \t" << pRecorrido->nombre << "." << endl;
                cout << " No.DPI:           \t" << pRecorrido->dpi << "." << endl;
                cout << " Edad:             \t" << pRecorrido->edad << "." << endl;
                cout << " No.Celular:       \t" << pRecorrido->telefono << "." << endl;
                cout << " e-Mail:           \t" << pRecorrido->mail << "." << endl;
                cout << " Direccion:        \t" << pRecorrido->direccion << "." << endl;
            }
            return true;//Codigo nuevo, ya fue ingresado antes.
        }else if(codigo < pRecorrido->codigo){//Condicional para indicar el siguiente puntero en el ciclo.
            pRecorrido = pRecorrido->pIzq;//Salto al sig. puntero para seguir recorrido de lado Izq. del árbol AVL.
        }else if(codigo > pRecorrido->codigo){//Condicional para indicar el siguiente puntero en el ciclo.
            pRecorrido = pRecorrido->pDer;//Salto al sig. puntero para seguir recorrido de lado Der. del árbol AVL.
        }
    }
    //LLamada por eliminación de datos.
    if(encontrado==false){//Condicional para verificar si, se encontró el nodo solicitado.
        system("color 04");
        cout << "\n El codigo que ingreso, ( " << codigo << " )." << endl;
        cout << " No pertenece a ningun nodo del arbol AVL." << endl;
    }
    return false;//Codigo nuevo, no esta en el árbol AVL.
}

//Función para terminar el procedimiento de un nuevo nodo al árbol AVL, que permite terminar de ingresar los datos solicitados.
avl *datosNodo(int codigo){
    avl *pNuevo = (avl *)malloc(sizeof(avl));//Buscar espacio en memoria con el nuevo puntero.
    if(pNuevo==NULL){//Si el nodo pNuevo esta NULL.
        cout << "\n\t No hay espacio en memoria disponible para crear mas nodos..." << endl;
    }else{
        //Ingreso el resto de datos al nodo e inicialización de sus punteros
        pNuevo->codigo = codigo;
        cout << " Ingrese nombre:            \t"; cin.getline(pNuevo->nombre, 65);
        cout << " Ingrese No.DPI:            \t"; cin.getline(pNuevo->dpi, 16);
        cout << " Ingrese edad:              \t"; cin >> pNuevo->edad; cin.ignore();
        cout << " Ingrese No.Celular:        \t"; cin >> pNuevo->telefono; cin.ignore();
        cout << " Ingrese correo electronico:\t"; cin.getline(pNuevo->mail, 60);
        cout << " Ingrese direccion:         \t"; cin.getline(pNuevo->direccion, 70);
        pNuevo->equilibrio = 1;
        pNuevo->pIzq   = NULL;
        pNuevo->pDer   = NULL;
        system("color 0A"); cout << "\n\t Registro Guardado." << endl; Sleep(5);
        cout << " Codigo:           \t" << pNuevo->codigo << "." << endl;
        cout << " Nombre:           \t" << pNuevo->nombre << "." << endl;
        cout << " No.DPI:           \t" << pNuevo->dpi << "." << endl;
        cout << " Edad:             \t" << pNuevo->edad << "." << endl;
        cout << " No.Celular:       \t" << pNuevo->telefono << "." << endl;
        cout << " e-Mail:           \t" << pNuevo->mail << "." << endl;
        cout << " Direccion:        \t" << pNuevo->direccion << "." << endl;
        return pNuevo;
    }
}

//Función para verificar el entero mayor de los dos ingresados a la función.
int hMayor(int izq, int der){
    if(izq > der)
        return izq;
    else
        return der;
}

//Funcion para devolver el factor de equilibrio de un nodo.
int fEquilibrio(avl *pNodo){
    if(pNodo!=NULL){
        return pNodo->equilibrio;
    }else{
        return 0;
    }
}

//Función para comprobar que se encuentre balanceado un nodo en el árbol AVL.
int balance(avl *pNodo){
    int h=0;
    if(pNodo!=NULL){
        h = fEquilibrio(pNodo->pIzq)-fEquilibrio(pNodo->pDer);
        return h;
    }else{
        return 0;
    }
}

//Función para reestructurar los nodos desbalanceados en el árbol AVL.
avl *RII(avl *pNodo){
    //      Entrada               Salida
    //  (80)                       (85)
    //       (85)       --->  (80)      (90)
    //            (90)
    //cout << "\t Re-estructuración Izquierda Izquierda" << endl;
    //Varaibles tipo punteros para re-estructurar el árbol AVL.
    avl *pTemp1, *pTemp2;//Punteros a utilizar.
    pTemp1 = pNodo->pIzq;//Apuntador igual al puntero de la izquierda del que entro a la función.
    pTemp2 = pTemp1->pDer;//Apuntador igual al puntero de la derecha, del puntero de la izquierda del que entro a la función.
    //Realizando la re-estructuración.
    pTemp1->pDer = pNodo;//Actualizar el nuevo valor del apuntador a la derecha, del puntero de la izquierda, del que entro a la función.
    pNodo->pIzq = pTemp2;//Actulizar el nuevo valor del apuntador a la izquierda, del que entro a la función.
    pNodo->equilibrio = 1+hMayor(fEquilibrio(pNodo->pIzq), fEquilibrio(pNodo->pDer));//Actualizar factor de equilibrio.
    pTemp1->equilibrio = 1+hMayor(fEquilibrio(pTemp1->pIzq), fEquilibrio(pTemp1->pDer));//Actualizar factor de equilibrio.
    return pTemp1;
}

//Función para reestructurar los nodos desbalanceados en el árbol AVL.
avl *RDD(avl *pNodo){
    //     Entrada                Salida
    //            (90)             (85)
    //       (85)       --->  (80)      (90)
    //  (80)
    //cout << "\t Re-estructuración Derecha Derecha" << endl;
    //Variables tipo punteros para re-estructurar el árbol AVL.
    avl *pTemp1, *pTemp2;//Punteros a utilizar.
    pTemp1 = pNodo->pDer;//Apuntador igual al puntero de la derecha del que entro a la función.
    pTemp2 = pTemp1->pIzq;//Apuntador igual al puntero de la izquierda, del puntero de la derecha del que entro a la función.
    //Re-estructurar los nodos afectados del árbol AVL.
    pTemp1->pIzq = pNodo;//Actualizar el nuevo valor del apuntador a la izquierda, del puntero de la derecha, del que entro a la función.
    pNodo->pDer = pTemp2;//Actulizar el nuevo valor del apuntador a la derecha, del que entro a la función.
    pNodo->equilibrio = 1+hMayor(fEquilibrio(pNodo->pIzq), fEquilibrio(pNodo->pDer));//Actualizar factor de equilibrio.
    pTemp1->equilibrio = 1+hMayor(fEquilibrio(pTemp1->pIzq), fEquilibrio(pTemp1->pDer));//Actualizar factor de equilibrio.
    return pTemp1;
}

//Función para reestructurar los nodos desbalanceados en el árbol AVL.
avl *RDI(avl *pNodo){
    //      Entrada                  Primera Re-estructuración       Salida - Segunda Re-estructuración
    //  (80)                            (80)                                         (85)
    //             (90)       --->                (85)           --->           (80)      (90)
    //       (85)                            (**)      (90)                (**)
    //cout << "\t Re-estructuración Derecha Izquierda" << endl;
    pNodo->pDer = RII(pNodo->pDer);//Primero al puntero de la derecha del nodo que entro en la función, aplicar la función RII con el puntero a la derecha.
    return RDD(pNodo);//Segundo aplicar RDD al nodo que entro en la función, como resultado se ha aplicado el RDI, regresa árbol AVL a estar balanceado.
}

//Función para reestructurar los nodos desbalanceados en el árbol AVL.
avl *RID(avl *pNodo){
    //      Entrada                 Primera Re-estructuración       Salida - Segunda Re-estructuración
    //             (90)                               (90)                     (85)
    //  (80)                 --->           (85)                --->      (80)      (90)
    //       (85)                      (80)      (**)                                    (**)
    //cout << "\t Re-estructuración Izquierda Derecha" << endl;
    pNodo->pIzq = RDD(pNodo->pIzq);//Primero al puntero de la izquierda del nodo que entro en la función, aplicar la función RDD con el puntero a la izquierda.
    return RII(pNodo);//Segundo aplicar RII al nodo que entro en la función, como resultado se ha aplicado el RDI, regresa árbol AVL a estar balanceado.
}

//Función para buscar un nodo en el árbol AVL por medio de un código.
void buscarCodigo(){
    //Variables a utilizar.
    int codigo=0;
    bool encontrado=false;
    char l1[55] = "******************************************************";
    char l2[55] = "************** BUSCAR NODO POR EL CODIGO *************";
    char l3[55] = "******************************************************";
    system("cls"); system("color 09");
    gotoxy(16,1);//Posición de la consola a imprimir el texto.
    for(int i=0;i<55;i++){//Ciclo for para recorrer la cadena. Linea 1.
        cout << l1[i];
        Sleep(8);//Tiempo de espera para continuar.
    }
    gotoxy(16,2);//Posición de la consola a imprimir el texto.
    for(int i=0;i<55;i++){//Ciclo for para recorrer la cadena. Linea 2.
        cout << l2[i];
        Sleep(8);//Tiempo de espera para continuar.
    }
    gotoxy(16,3);//Posición de la consola a imprimir el texto.
    for(int i=0;i<55;i++){//Ciclo for para recorrer la cadena. Linea 3.
        cout << l3[i];
        Sleep(8);//Tiempo de espera para continuar.
    }

    cout << "\n\n Digite el codigo del nodo a buscar:        \t" ; cin >> codigo; cin.ignore();
    avl *pRecorrido = pArbolAVL;//Igualar para comenzar a recorrer el árbol AVL.
    if(pArbolAVL != NULL){//Condicional para verificar si el árbol AVL tiene nodos.
        while(pRecorrido != NULL){//Mientras no este en el ultimo nodo del árbol AVL.
            if(codigo == pRecorrido->codigo){//Condición para comparar lo del árbol AVL con el dato ingresado.
                system("color 0A");
                cout << "\n\t Registro encontrado en el arbol AVL!" << endl;
                cout << " Codigo:           \t" << pRecorrido->codigo << "." << endl;
                cout << " Nombre:           \t" << pRecorrido->nombre << "." << endl;
                cout << " No.DPI:           \t" << pRecorrido->dpi << "." << endl;
                cout << " Edad:             \t" << pRecorrido->edad << "." << endl;
                cout << " No.Celular:       \t" << pRecorrido->telefono << "." << endl;
                cout << " e-Mail:           \t" << pRecorrido->mail << "." << endl;
                cout << " Direccion:        \t" << pRecorrido->direccion << "." << endl;
                encontrado = true;
                return; //Nodo econtrado, salir de la función.
            }else if(codigo < pRecorrido->codigo){//Condicional para indicar el siguiente puntero en el ciclo.
                pRecorrido = pRecorrido->pIzq;//Salto al sig. puntero para seguir recorrido de lado Izq. del árbol AVL.
            }else if(codigo > pRecorrido->codigo){//Condicional para indicar el siguiente puntero en el ciclo.
                pRecorrido = pRecorrido->pDer;//Salto al sig. puntero para seguir recorrido de lado Der. del árbol AVL.
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

//Función que empiza el procedimiento de eliminar un nodo por medio de su código.
void eliminar(){
    system("cls"); system("color 09");
    int codigo = 0;//Variable para solicitar el ingreso del codigo del nodo a eliminar.
    char l1[55] = "******************************************************";
    char l2[55] = "************* ELIMINAR NODO DEL ARBOL AVL ************";
    char l3[55] = "******************************************************";
    gotoxy(16,1);//Posición de la consola a imprimir el texto.
    for(int i=0;i<55;i++){//Ciclo for para recorrer la cadena. Linea 1.
        cout << l1[i];
        Sleep(8);//Tiempo de espera para continuar.
    }
    gotoxy(16,2);//Posición de la consola a imprimir el texto.
    for(int i=0;i<55;i++){//Ciclo for para recorrer la cadena. Linea 2.
        cout << l2[i];
        Sleep(8);//Tiempo de espera para continuar.
    }
    gotoxy(16,3);//Posición de la consola a imprimir el texto.
    for(int i=0;i<55;i++){//Ciclo for para recorrer la cadena. Linea 3.
        cout << l3[i];
        Sleep(8);//Tiempo de espera para continuar.
    }
    cout << "\n\n Digite el codigo del nodo a eliminar:        \t" ; cin >> codigo; cin.ignore();
    if((comprobarCodigo(codigo, false) == true)){//Comprobar que exista el nodo solicitado en el árbol AVL.
            pArbolAVL = eliminarNodo(pArbolAVL, codigo);//Llama a la función para su ingreso.
    }else{//De no estar en el árbol AVL, proceder a su ingreso.
        return;//Regresa al menú principal.
    }
}

//Función para terminar el proceso de eliminar un nodo del árbol AVL por medio de un código.
avl *eliminarNodo(avl *pAVL, int codigo){
    //Variables a utilizar.
    int equilibrio=0;//Variable para comprobar que el árbol AVL, aun se encuentre balanceado.
    int izq = 0, der = 0;//Variables para comprobar que los hijos del nodo valuado, se encuetren balanceados en el árbol AVL.
    avl *pTemp1, *pTemp2;//Apuntadores para modificar los nodos afectados en el árbol AVL.
    if(pAVL==NULL){//Condicional para si el árbol AVL tiene nodos.
        //cout << " \n\t El arbol AVL no existe aun." << endl;
        return pAVL;
    }
    if(codigo < pAVL->codigo){//Condicional para indicar el siguiente puntero en ser verificado. Si es menor irá al hijo de la izquierda.
        pAVL->pIzq = eliminarNodo(pAVL->pIzq, codigo);//Salto al sig. puntero para seguir recorrido de lado Izquierda del árbol AVL.
    }else if(codigo > pAVL->codigo){////Condicional para indicar el siguiente puntero en ser verificado. Si es menor irá al hijo de la izquierda.
        pAVL->pDer = eliminarNodo(pAVL->pDer, codigo);//Salto al sig. puntero para seguir recorrido de lado Derecho del árbol AVL.
    }else{//Si ninguna condicional es cierta, se esta en la posición del nodo a eliminar.
        //Hay tres posibles casos para eliminar un nodo de un árbol AVL.
        //1°er Caso: Que el nodo a eliminar sea hoja o terminal, simplemente suprimirlo.
        //2°do Caso: Si el nodo a eliminar tiene un solo descendiente, sustituir por ese descendiente.
        if((pAVL->pIzq==NULL) || (pAVL->pDer==NULL)){//Condicional para verficar si el nodo actual del recorrido es hoja, o tiene un solo descendiente.
            if(pAVL->pIzq!=NULL){//Condicional para verificar si el nodo actual del recorrido en su puntero a la izquierda es NULL.
                pTemp1 = pAVL->pIzq;//Asignar valor al puntero temporal.
            }else{//En el nodo actual del recorrido en su puntero a la izquierda es NULL, el de la derecha no es NULL.
                pTemp1 = pAVL->pDer;//Asignar valor al puntero temporal.
            }
            if(pTemp1==NULL){//Condicional para verificar si el apuntador es NULL. El nodo es una hoja o terminal.
                pTemp1 = pAVL;//Igualar nodos, para proceder a eliminar adelante.
                pAVL = NULL;//Igualar a NULL el nodo, para que su nodo padre apunte NULL a su posición.
            }else{//Nodo con un solo descendiente.
                *pAVL = *pTemp1;//Igualar posición en memoria de punteros, para eliminara adelante.
            }
            delete pTemp1;//Elimina el nodo solicitado.
            Sleep(120); system("color 0C");
            cout << "\n\t Registro eliminado del arbol AVL!" << endl;
            //pTemp1 = pRecorrido->pDer;
            //free (pAVL);
            //return pTemp1;
        }else{//3°er Caso: Si el nodo a eliminar tiene dos descendientes, sustituir por nodo +D del SI.
            //Buscar el nodo +D del SI para sustituir en la posición.
            pTemp2 = pAVL->pIzq;//Igualar el puntero al sub-árbol izquierdo, para poder realizar la búsqueda y empezar el recorrido.
            //Ciclo while para buscar el nodo más a la derecha.
            while(pTemp2->pDer != NULL){//El ciclo avanzará mientras el puntero a la derecha del valuado, sea diferente de NULL.
                pTemp2 = pTemp2->pDer;//Salto al siguiente nodo para valuar la condición del ciclo.
            }//El nodo +D del SI se guardará en pTemp2.
            pTemp1 = pTemp2;//Igualar punteros, para no perder los datos.
            pAVL->codigo = pTemp1->codigo;//Reemplazar el codigo del puntero por el del nodo +D del SI.
            //Se procede buscar una nueva eliminación, a partir del hijo a la izquierda del nodo actual.
            pAVL->pIzq = eliminarNodo(pAVL->pIzq, pTemp1->codigo);//Volver a llamar la función, para eliminar el nodo que se acaba de copiar a la nueva posición.
        }
    }
    if(pAVL==NULL)//Condicional para comprobar del nodo no sea NULL.
        return pAVL;
    pAVL->equilibrio = 1+hMayor(fEquilibrio(pAVL->pIzq), fEquilibrio(pAVL->pDer));//Actualizar el factor de equilibrio del nodo padre del siguiente a valuar.
    equilibrio = balance(pAVL);//Verificar si el árbol AVL se encuentra balanceado a partir del nodo padre del siguiente a valuar, para proceder a re-estructurar de ser necesario.
    //Comparar el factor de equilibrio para modificar apuntadores, con posible casos de re-estructaración.
    izq = balance(pAVL->pIzq);//Verificar si se encuntra desbalance en el hijo de la izquierda del nodo valuado.
    der = balance(pAVL->pDer);//Verificar si se encuntra desbalance en el hijo de la derecha del nodo valuado.
    if(equilibrio > 1){//Condicional para verificar, si hay desbalance en el nodo valuado y proceder a re-estructurar los nodos afectados.
        if(izq >= 0){//Caso 1°: Re-estructuración Izquierda Izquierda.
            cout << "\t Se ha aplicado la RII" << endl;
            return RII(pAVL);//Aplica RII para balancear el árbol AVL.
        }else if(izq < 0){//Caso 2°: Re-estructuración Izquierda Derecha.
            cout << "\t Se ha aplicado la RID" << endl;
            return RID(pAVL);//Aplica RID para balancear el árbol AVL.
        }
    }else if(equilibrio < -1){////Condicional para verificar, si hay desbalance en el nodo valuado y proceder a re-estructurar los nodos afectados.
        if(der <= 0){//Caso 3°: Re-estructuración Derecha Derecha.
            cout << "\t Se ha aplicado la RDD" << endl;
            return RDD(pAVL);//Aplica RDD para balancear el árbol AVL.
        }else if(der > 0){//Caso 4°: Re-estructuración Derecha Izquierda.
            cout << "\t Se ha aplicado la RDI" << endl;
            return RDI(pAVL);//Aplica RDI para balancear el árbol AVL.
        }
    }
    return pAVL;
}

//Función para comenzar el proceso de graficar el árbol AVL en la consola.
void imprimir(){
    system("cls");
    ejeX = 0; //Actualizar varaible a cero antes de ser utilizada
    //cout << "\n\t\t\t********** ARBOL AVL **********\n" << endl;
    titulo();
    graficarArbol(pArbolAVL, 0);
    parpadeo(" ",0,0,150); system("color 06");
}

//Función para graficar en la consola el diagrama del árbol AVL con el código de los nodos.
void graficarArbol(avl *pAVL, int ejeY){
    if(pAVL == NULL){ //Si el árbol AVL esta vació.
        return;//Salir de la función.
    }else{
        ejeX += 5; //Posición en el eje X de la consola.
        graficarArbol(pAVL->pIzq, ejeY+2); //Se pocisiona en la hoja más a la Izquierda del árbol AVL.
        parpadeo("  * ", 9+ejeX-ejeY, 11+ejeY-1, 12);//Llama la función para imprimir la cadena, y dar la posición a aparecer en pantalla.
        gotoxy(9+ejeX-ejeY, 11+ejeY);//Posición de la cadena a imprimir en pantalla.
        cout << "(" << pAVL->codigo <<  ")" << endl << endl;
        graficarArbol(pAVL->pDer, ejeY+2); //Se pocisiona en la hoja más a la Derecha del árbol AVL.
    }
}

//Función que perimite que una cadena cambie de color cada cierto momento dado.
void parpadeo(string texto, int x, int y, int t){
    int contador = 0;// Variable para contar el tiempo.
    do{
        if (contador = 5){
            //system("cls");//Limpia pantalla.
            system("color 04");//Color de Letra.
            gotoxy(x,y);//Posicion en que se imprimirá el siguiente texto en pantalla.
            cout << texto;
            Sleep(t);//Tiempo de espera para continuar los cambios.
            if (contador = 10){
                //system("cls");
                system("color 02");
                gotoxy(x,y);//Posicion en que se imprimirá el siguiente texto en pantalla.
                cout << texto;
                Sleep(t);//Tiempo de espera para continuar los cambios.
                if (contador = 15){
                    //system("cls");
                    system("color 01");
                    gotoxy(x,y);//Posicion en que se imprimirá el siguiente texto en pantalla.
                    cout << texto;
                    Sleep(t);//Tiempo de espera para continuar los cambios.
                    if (contador = 25){
                        //system("cls");
                        system("color 0C");
                        gotoxy(x,y);//Posicion en que se imprimirá el siguiente texto en pantalla.
                        cout << texto;
                        Sleep(t);//Tiempo de espera para continuar los cambios.
                        if (contador = 25){
                            //system("cls");
                            system("color 0A");
                            gotoxy(x,y);//Posicion en que se imprimirá el siguiente texto en pantalla.
                            cout << texto;
                            Sleep(t);//Tiempo de espera para continuar los cambios.
                            if (contador = 30){
                                //system("cls");
                                system("color 09");
                                gotoxy(x,y);//Posicion en que se imprimirá el siguiente texto en pantalla.
                                cout << texto;
                                Sleep(t);//Tiempo de espera para continuar los cambios.
                                cout << "\n" << endl;
                            }
                        }
                    }
                }
            }
        }
        contador++;//Aumento de la varieble entera.
    }while(contador<20);//Fin del Tiempo Puesto.
}

//Función para aplicar el cambio de color a unas cadenas que serán mostradas al ejecutar y cerrar el programa.
void parpadeoTexto(int t){
    parpadeo("  ___  ______ ______  _____  _            ___   _   _  _ \n", 31, 2, t);
    parpadeo(" / _ \\ | ___ \\| ___ \\|  _  || |          / _ \\ | | | || | \n", 31, 3, t);
    parpadeo("/ /_\\ \\| |_/ /| |_/ /| | | || |         / /_\\ \\| | | || | \n", 31, 4, t);
    parpadeo("|  _  ||    / | ___ \\| | | || |         |  _  || | | || |    \n", 31, 5, t);
    parpadeo("| | | || |\\ \\ | |_/ /\\ \\_/ /| |____     | | | |\\ \\_/ /| |____ \n", 31, 6, t);
    parpadeo("\\_| |_/\\_| \\_|\\____/  \\___/ \\_____/     \\_| |_/ \\___/ \\_____/ \n", 31, 7, t);

}

//Función que imprime "ARBOL AVL" en 2D en pantalla.
void titulo(){
    gotoxy(31,2);//Posición en que se imprimirá el siguiente texto en pantalla.
    cout << "  ___  ______ ______  _____  _            ___   _   _  _     " << endl;//Línea 1.
    gotoxy(31,3);//Posición en que se imprimirá el siguiente texto en pantalla.
    cout << " / _ \\ | ___ \\| ___ \\|  _  || |          / _ \\ | | | || |" << endl;//Línea 2.
    gotoxy(31,4);//Posición en que se imprimirá el siguiente texto en pantalla.
    cout << "/ /_\\ \\| |_/ /| |_/ /| | | || |         / /_\\ \\| | | || |" << endl;//Línea 3.
    gotoxy(31,5);//Posición en que se imprimirá el siguiente texto en pantalla.
    cout << "|  _  ||    / | ___ \\| | | || |         |  _  || | | || |   " << endl;//Línea 4.
    gotoxy(31,6);//Posición en que se imprimirá el siguiente texto en pantalla.
    cout << "| | | || |\\ \\ | |_/ /\\ \\_/ /| |____     | | | |\\ \\_/ /| |____" << endl;//Línea 5.
    gotoxy(31,7);//Posición en que se imprimirá el siguiente texto en pantalla.
    cout << "\\_| |_/\\_| \\_|\\____/  \\___/ \\_____/     \\_| |_/ \\___/ \\_____/" << endl;//Línea 6.
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
