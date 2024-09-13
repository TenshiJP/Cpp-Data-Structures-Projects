/*
    Nombre:     Angel Roberto Jacinto Payes
    No.Carnet:  5990-20-1756
*/
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

//Nodo que representará la lista.
typedef struct nodo{
    int codigo;         //El código del cliente serán unicamente numeros enteros.
    char nombres[75];
    char apellidos[75];
    struct nodo *pSig;
}stcNodo;

//Funciones a utilizar.
void crearNodo();//Función que crea un nodo simple con una insección descendente.
void recorrido();//Funcion para imprimir a pantalla los clientes de la lista.
bool comprobar(int numBusqueda);//Función para realizar la busqueda del codigo de un cliente en la lista.
void ordenarLista(stcNodo *pLista);//Función para ordenar de manera descendentes los clientes por su codigo.
void busqueda();//Función para realizar una busqueda en lista por medio de un codigo de cliente ingresado.
void eliminarNodo();//Funcion para eliminar un nodo de la lista.

//Apuntadores a la lista.
stcNodo *pCrear, *pRecorrido, *pNuevo;

int main()
{
    int opcion=0;
    do{
        system("cls");
        cout << "\n\t\t .-----------------------------------------." << endl;
        cout << "\t\t |                                         |" << endl;
        cout << "\t\t |            LISTA DE CLIENTES            |" << endl;
        cout << "\t\t |                                         |" << endl;
        cout << "\t\t .-----------------------------------------." << endl;
        cout << "\t\t |    ||                                   |" << endl;
        cout << "\t\t | 1. || Ingresar cliente nuevo a la Lista |" << endl;
        cout << "\t\t | 2. ||    Mostrar clientes de la Lista   |" << endl;
        cout << "\t\t | 3. ||  Eliminar un cliente de la Lista  |" << endl;
        cout << "\t\t | 4. ||   Buscar un cliente en la Lista   |" << endl;
        cout << "\t\t | 5. ||               Salir               |" << endl;
        cout << "\t\t |    ||                                   |" << endl;
        cout << "\t\t .-----------------------------------------.\n" << endl;
        cout << "\t  Digite su opcion: "; cin >> opcion;
        switch(opcion){
            case 1:
                crearNodo(); getch();
                break;
            case 2:
                recorrido(); getch();
                break;
            case 3:
                eliminarNodo(); getch();
                break;
            case 4:
                busqueda(); getch();
                break;
            case 5:
                break;
            default:
                cout << "\tNo es una opcion valida." << endl; getch();
        }
    }while(opcion!=5);
    return 0;
}

//Función para crear un nodo simple con una inserción descendentemente.
void crearNodo(){
    system("cls");
    //Variables a utilizar
    //string nombres, apellidos;
    int codigo=0;
    pNuevo = (stcNodo *)malloc(sizeof(stcNodo));//Se busca un espacio en memoria segun el tamaño del nodo prototipo.

    if(pNuevo==NULL){
        cout << " No hay espacio en memoria disponible para crear mas nodos." << endl;
    }else{
        /*Ingreso de datos e inicialización de punteros*/
        cout << "\n \t**********INGRESO DE DATOS**********\n" << endl;
        do{
            cout << " Ingrese codigo del cliente      : "; cin >> codigo;
            if(codigo <= 0)
                cout << "\n\t No se permite ingresar clientes con codigos menores o iguales a 0.\n" << endl;
        }while(codigo < 1); cin.ignore();//Mientras que codigo no sea > 0, no avanzará la ejecución.
        cout << " Ingrese nombres del cliente     : "; cin.getline(pNuevo->nombres,80);// getline(cin, nombres);
        cout << " Ingrese apellidos del cliente   : "; cin.getline(pNuevo->apellidos,80);// getline(cin, apellidos);
        pNuevo->codigo = codigo;
        //pNuevo->nombres = nombres;
        //pNuevo->apellidos = apellidos;
        pNuevo->pSig = NULL;
        /*Fin*/

        if((comprobar(codigo)== true)){//Comprobar que no exista un código igual en la lista.
            return;
        }else{}

        /*Para el pCrear, si llegara a ser igual a nil, hay dos opciones
        1.- Perdimos la lista (Pero escenario).
        2.- Esta vacia (no existe ningun nodo en la lista.)*/
        if(pCrear==NULL){
            pCrear = pNuevo;//Será el primero y ultimo nodo de la lista.
            cout << "\n\t Registro Guardado." << endl;
            cout << " Codigo: " << codigo << ".\tCliente: " << pNuevo->nombres << " " << pNuevo->apellidos << "." << endl;
        }else{
            //pNuevo->pSig = pCrear;//pNuevo apunta al nodo creado.
            //pCrear = pNuevo;//pCrear apunta pNuevo.
            pRecorrido = pCrear;//Igular punteros para empezar recorrido desde el inicio de la lista.
            while(pRecorrido->pSig != NULL)//Mientras el puntero no apunte a null.
                pRecorrido = pRecorrido->pSig;
            pRecorrido->pSig = pNuevo;//Agrega a lista.
            cout << "\n\t Registro Guardado." << endl;
            cout << " Codigo: " << codigo << ".\tCliente: " << pNuevo->nombres << " " << pNuevo->apellidos << "." << endl;
            ordenarLista(pCrear);//Llama a la función para ordenar en la lista el dato recien ingresado.
        }
    }
}

//Funcion para imprimir a pantalla los clientes de la lista.
void recorrido(){
    system("cls"); int i=1;
    cout << "\n\t ************LISTA DE LOS CLIENTES************\n" << endl;

    pRecorrido = pCrear;//Igualamos para posicionarse en el primer nodo de la lista.
    while(pRecorrido!=NULL){//Mientras no estemos en el ultimo nodo de nuestra lista
        cout << " | " << i << " |  Codigo: " << pRecorrido->codigo << "\tCliente: " << pRecorrido->nombres << " " << pRecorrido->apellidos << " --> " << endl;
        pRecorrido = pRecorrido->pSig;
        i++;
    }
    cout << " Nill" << endl;
}

//Función para realizar una busqueda en la lista por medio del código del cliente.
void busqueda(){
    //Variables a utilizar.
    int codBusqueda=0, codFound=0;
    system("cls");
    cout << "\n\t ************BUSCAR CLIENTE************\n" << endl;
    cout << " Digite el codigo del cliente a buscar: "; cin >> codBusqueda; cin.ignore();
    pRecorrido = pCrear;//Igualar punteros para empezar el recorrido desde el inico de la lista.

    if(pCrear != NULL)//Condicional para verificar si la lista tiene nodos.
    {
        while(pRecorrido!=NULL){//Mientras no este en el ultimo nodo de la lista.
            if(pRecorrido->codigo==codBusqueda){
                cout << "\n\t Cliente encontrado!\n" << endl;
                cout << " Codigo: " << pRecorrido->codigo << ". \t Cliente: " << pRecorrido->nombres << " " << pRecorrido->apellidos << endl;
                codFound++;
            }else{}
            pRecorrido = pRecorrido->pSig;
        }
        if(codFound == 0){//Condicional si no se encuentra el cliente en la lista.
            cout << "\n El codigo que ingreso: " << codBusqueda << ".\n No pertenece a ningun cliente de la lista." << endl;
        }else{}
    }else{
        cout << " \n\t La lista esta vacia." << endl;
    }

}

//Función para realizar la busqueda del codigo de un cliente en la lista.
bool comprobar(int numBusqueda){

    pRecorrido = pCrear;//Iniciar en el primer nodo de la lista.
    while(pRecorrido!=NULL){//Mientras no este en el ultimo nodo de nuestra lista
        if(pRecorrido->codigo==numBusqueda){
            cout << "\n\t Lo sentimos, el codigo " << numBusqueda << " esta existente. Intente de nuevo." << endl;
            return true;
        }else{}
        pRecorrido = pRecorrido->pSig;
    }
    return false;
}

//Función para ordenar de manera descendentes los clientes por su codigo.
void ordenarLista(stcNodo *pLista){
    //Variables a utlizar
    stcNodo *pSiguiente; //Puntero para manipular y ordenar la lista de cleintes.
    int codigo;//Varible para guardar los codigos de los clientes.
    string nombres, apellidos, name, lastName; //Variables para guardar los datos de los clientes y no perderla.
    pRecorrido = pLista; //Igualar punteros, para iniciar el recorrido en el primer nodo.

    /*Inicio algoritmo burbuja para ordenar los clientes.*/
    while(pRecorrido->pSig!=NULL){//Mientras el puntero no apunte a null.
        pSiguiente = pRecorrido->pSig;//Igualar para inicair en el primer nodo de la lista.

        while(pSiguiente != NULL){//Mientras no este en el ultimo nodo de la lista.
            if(pRecorrido->codigo < pSiguiente->codigo){//Condicional para ordenar los clientes en la lista de manera descendente.
                codigo = pSiguiente->codigo;//Guarda codigo del puntero.
                nombres = pSiguiente->nombres;//Guarda nombres del puntero.
                apellidos = pSiguiente->apellidos;//Guarda apellidos del puntero.

                pSiguiente->codigo = pRecorrido->codigo;//Actualiza puntero pSiguiente.
                //pSiguiente->nombres = pRecorrido->nombres;
                name = pRecorrido->nombres;//Copia los nombres del puntero.
                strcpy(pSiguiente->nombres, name.c_str());//Actualiza puntero pSiguiente.
                //pSiguiente->apellidos = pRecorrido->apellidos;
                lastName = pRecorrido->apellidos;//Copia los apellidos del puntero.
                strcpy(pSiguiente->apellidos, lastName.c_str());//Actualiza puntero pSiguiente.

                pRecorrido->codigo = codigo;//Realizando el cambio para ordenar la lista.
                //pRecorrido->nombres = names;
                strcpy(pRecorrido->nombres, nombres.c_str());//Realizando el cambio para ordenar la lista.
                //pRecorrido->apellidos = lastNames;
                strcpy(pRecorrido->apellidos, apellidos.c_str());//Realizando el cambio para ordenar la lista.
            }else{}
            pSiguiente = pSiguiente->pSig;
        }
        pRecorrido = pRecorrido->pSig;
        pSiguiente = pRecorrido->pSig;//pSiguiente apunta hacia pRecorrido.
    }/*Fin algoritmo burbuja*/
}

//Funcion para eliminar un nodo de la lista.
void eliminarNodo(){
    system("cls");
    //Variables a utilizar.
    stcNodo *pAnterior;//Puntero para manipular los clientes.
    int codigo=0;//Variable para ingrsar codigo a buscar en la lista.

    cout << "\n\t ************ELIMINAR CLIENTE************\n" << endl;
    cout << " Digite el codigo del cliente a eliminar: "; cin >> codigo; cin.ignore();
    pRecorrido = pCrear;//Igular punteros, para iniciar recorrido desde el primer nodo.
    pAnterior=NULL;

    if(pCrear != NULL){//Condicional si la lista no esta vacía.
        while(pRecorrido != NULL){//Mientras no sea el ultimo nodo de la lista.
            if(pRecorrido->codigo == codigo){//Si el codigo actual del puntero es igual codigo ingresado.
                cout << "\n\t Cliente encontrado: " << endl;
                cout << " Codigo: " << pRecorrido->codigo << ".\t Cliente: " << pRecorrido->nombres << " " << pRecorrido->apellidos << ". " << endl;
                if(pRecorrido==pCrear)
                    pCrear = pCrear->pSig;
                else
                    pAnterior->pSig = pRecorrido->pSig;

                free(pRecorrido); //delete(pRecorrido); Elimina el nodo de la lista.
                cout << "\n\t Cliente eliminado!" << endl;
                return;
            }else{
                //cout << "\n\t Cliente no encontrado." << endl;
                pAnterior = pRecorrido;
                pRecorrido = pRecorrido->pSig;
            }
        }
        if(pRecorrido == NULL){//Condicional si no se encuentra el código ingresado en la lista.
            cout << "\n\t Cliente no encontrado! " << endl;
        }else{}
    }else{
        cout << " \n\t La lista esta vacia." << endl;
    }
}
