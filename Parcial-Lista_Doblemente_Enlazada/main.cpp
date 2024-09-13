/*
    *--------- SEGUNDO EXAMEN PARCIAL - PARTE PRACTICA ---------*
        Nombre:         Angel Roberto Jacinto Payes
        No.Carnet:      5990-20-1756
    *-----------------------------------------------------------*
*/
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

//Estructura doblemente enlazada. Se agregaron 2 datos más a los minimos esperados, por lo cual se cambió el orden en que ingresan de algunos.
typedef struct dobleenlazada{
    int codigo;
    char nombre [65];
    int edad;
    char dpi [16];
    int telefono;
    char mail [60];
    char direccion [80];
    struct dobleenlazada *pSig;
    struct dobleenlazada *pAnt;
} dobleEnlace;

//Nodos para la estructura.
dobleEnlace *pInicio, *pFinal, *pRecorrido, *pNuevo, *pTemporal;

//Funciones a utilizar.
void ingresarDatos();                   //Función para ingreasar datos al final de la lista doblemente enlazada.
bool comprobar(int cod);                //Función para evitar el ingreso de dos personas con el mismo código.
void ordenarLista(dobleEnlace *pLista); //Función para ordenar los nodos por el codigo de persona de manera ascedente.
void menuBusqueda();                    //Función para seleccionar una opcion del menu para realizar la busqueda.
void buscarCodigo();                    //Función para buscar en la lista por el codigo.
void buscarNombre();                    //Función para buscar en la lista por el nombre.
void buscarEdad();                      //Función para buscar en la lista por la edad.
void buscarDPI();                       //Función para buscar en la lista por el No.DPI.
void eliminarDatos();                   //Función para eliminar un nodo de la lista.
void inicioFin();                       //Función para el recorrido a la lista de inicio a fin.
void finInicio();                       //Función para el recorrido a la lista de fin a inicio.
void reporte();                         //Función para mostrar el recorrido de la lista, de las primeras 4 columnas.
void cantidadPersonas();                //Función para contar las personas de la lista y mostrar el total.

int main()
{
    int opcion=0;
    do{
        system("cls"); system("color 07");
        cout << "\n\t\t\t .-------------------------------------------------." << endl;
        cout << "\t\t\t |                                                 |" << endl;
        cout << "\t\t\t |            *** LISTA DE PERSONAS ***            |" << endl;
        cout << "\t\t\t |                                                 |" << endl;
        cout << "\t\t\t :-------------------------------------------------:" << endl;
        cout << "\t\t\t |    ||                                           |" << endl;
        cout << "\t\t\t | 1. ||        Ingresar persona a la lista        |" << endl;
        cout << "\t\t\t | 2. ||       Buscar una persona en la lista      |" << endl;
        cout << "\t\t\t | 3. ||     Eliminar una persona de la lista      |" << endl;
        cout << "\t\t\t | 4. ||       Mostrar lista de Inicio a Fin       |" << endl;
        cout << "\t\t\t | 5. ||       Mostrar lista de Fin a Inicio       |" << endl;
        cout << "\t\t\t | 6. ||            Reporte de personas            |" << endl;
        cout << "\t\t\t | 7. ||           Cantidad de personas            |" << endl;
        cout << "\t\t\t | 8. ||                   Salir                   |" << endl;
        cout << "\t\t\t |    ||                                           |" << endl;
        cout << "\t\t\t '-------------------------------------------------'\n" << endl;
        cout << "\t\t  Digite su opcion: "; cin >> opcion;
        switch(opcion){
            case 1:
                system("color 01");
                ingresarDatos(); getch();
                break;
            case 2:
                system("color 09");
                menuBusqueda();
                break;
            case 3:
                system("color 03");
                eliminarDatos(); getch();
                break;
            case 4:
                system("color 0B");
                inicioFin(); getch();
                break;
            case 5:
                system("color 0B");
                finInicio(); getch();
                break;
            case 6:
                system("color 0B");
                reporte(); getch();
                break;
            case 7:
                system("color 0D");
                cantidadPersonas(); getch();
                break;
            case 8:
                system("color 0F");
                system("cls"); cout << "\n\n\t\t Saliendo..." << endl;
                break;
            default:
                system("color 0C"); system("cls");
                cout << "\n\n\t\t No es una opcion valida" << endl; getch();
        }
    }while(opcion!=8);
    return 0;
}

//Función para ingreasar datos al final de la lista doblemente enlazada.
void ingresarDatos(){
    system("cls");
    pNuevo = (dobleEnlace *)malloc(sizeof(dobleEnlace));//Buscar espacio en memoria.

    if(pNuevo==NULL){
        system("cls"); system("color 04");
        cout << " No hay espacio en memoria disponible para crear mas nodos." << endl;
    }else{
        /*Ingreso de datos e inicialización de punteros*/
        cout << "\n \t********** INGRESO DE DATOS **********\n" << endl;
        cout << " Ingrese codigo de la persona: \t"; cin >> pNuevo->codigo; cin.ignore();
        if((comprobar(pNuevo->codigo) == true)){//Comprobar que no exista un código igual en la lista.
            return;//Regresa al menú principal.
        }else{}
        cout << " Ingrese nombre:               \t"; cin.getline(pNuevo->nombre, 65);
        cout << " Ingrese edad:                 \t"; cin >> pNuevo->edad; cin.ignore();
        cout << " Ingrese No. DPI o CUI         \t"; cin.getline(pNuevo->dpi, 16);
        cout << " Ingrese No. Celular:          \t"; cin >> pNuevo->telefono; cin.ignore();
        cout << " Ingrese email:                \t"; cin.getline(pNuevo->mail, 60);
        cout << " Ingrese direccion:            \t"; cin.getline(pNuevo->direccion, 80);
        pNuevo->pSig = NULL;
        pNuevo->pAnt = NULL;
        /*Fin*/

        /* Para el puntero Inicio, si llegara a ser igual a nill, hay dos opciones:
            1.-  Perdimos la lista (Peor escenario).
            2.-  Esta vacia.    */
        if(pInicio==NULL){
            system("color 0A");
            pInicio = pNuevo;//Sera el primero y ultimo nodo en la lista.
            pFinal  = pNuevo;
            cout << "\n\t Registro Guardado." << endl;//Imprime los datos guardados.
            cout << " Codigo:       \t" << pNuevo->codigo << endl;
            cout << " Nombre:       \t" << pNuevo->nombre << endl;
            cout << " Edad:         \t" << pNuevo->edad << endl;
            cout << " No. DPI/CUI:  \t" << pNuevo->dpi << endl;
            cout << " No. Celular:  \t" << pNuevo->telefono << endl;
            cout << " eMail:        \t" << pNuevo->mail << endl;
            cout << " Direccion:    \t" << pNuevo->direccion << endl;
        }else{
            system("color 0A");
            pNuevo->pAnt = pFinal;//Enlazar basado en el ultimo.
            pFinal->pSig = pNuevo;
            pFinal = pNuevo;
            pFinal->pSig = NULL;
            cout << "\n\t Registro Guardado." << endl;//Imprime los datos guardados.
            cout << " Codigo:       \t" << pNuevo->codigo << endl;
            cout << " Nombre:       \t" << pNuevo->nombre << endl;
            cout << " Edad:         \t" << pNuevo->edad << endl;
            cout << " No. DPI/CUI:  \t" << pNuevo->dpi << endl;
            cout << " No. Celular:  \t" << pNuevo->telefono << endl;
            cout << " eMail:        \t" << pNuevo->mail << endl;
            cout << " Direccion:    \t" << pNuevo->direccion << endl;
            ordenarLista(pInicio);//Llama a la función para ordenar en la lista el dato recien ingresado.
        }
    }
}

//Función para evitar el ingreso de dos personas con el mismo código.
bool comprobar(int cod){
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    while(pRecorrido!=NULL){//Mientras no este en el ultimo nodo de la lista.
        if(pRecorrido->codigo == cod){//Condición para comparar lo de la lista con el dato nuevo.
            system("color 04");
            cout << "\n\t Lo sentimos, el codigo: " << cod <<". Esta existente, intente de nuevo." << endl;
            return true;
        }else{}
        pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
    }
    return false;
}

//Función para ordenar los nodos por el codigo de persona de manera ascedente.
void ordenarLista(dobleEnlace *pLista){
    //Variables a utlizar
    dobleEnlace *pSiguiente; //Puntero para manipular y ordenar la lista doblemente enlazada.
    int codigo, edad, telefono, age, celular;//Variables para guardar los datos de las personas y no perderla.
    string nombre, dpi, mail, direccion, name, dpi1, email, direc;

    pRecorrido = pLista; //Igualar punteros, para iniciar el recorrido en el primer nodo.
    /*Inicio algoritmo burbuja para ordenar las personas por el codigo.*/
    while(pRecorrido->pSig!=NULL){//Mientras el puntero no apunte a null.
        pSiguiente = pRecorrido->pSig;//Igualar para iniciar en el primer nodo de la lista.
        while(pSiguiente != NULL){//Mientras no este en el ultimo nodo de la lista.
            if(pRecorrido->codigo > pSiguiente->codigo){//Condicional para ordenar los clientes en la lista de manera ascendente.
                codigo = pSiguiente->codigo;//Guarda codigo del puntero.
                nombre = pSiguiente->nombre;//Guarda codigo del puntero.
                edad = pSiguiente->edad;//Guarda codigo del puntero.
                dpi = pSiguiente->dpi;//Guarda No.DPI del puntero.
                telefono = pSiguiente->telefono;//Guarda telefono del puntero.
                mail = pSiguiente->mail;//Guarda mail del puntero.
                direccion = pSiguiente->direccion;//Guarda direccion del puntero.

                pSiguiente->codigo = pRecorrido->codigo;//Actualiza puntero pSiguiente.
                name = pRecorrido->nombre;//Copia el nombre del puntero.
                strcpy(pSiguiente->nombre, name.c_str());//Actualiza puntero pSiguiente.
                age = pRecorrido->edad;//Copia la edad del puntero.
                pSiguiente->edad = age;//Actualiza puntero pSiguiente.
                dpi1 = pRecorrido->dpi;//Copia el No.DPI del puntero.
                strcpy(pSiguiente->dpi, dpi1.c_str());//Actualiza puntero pSiguiente.
                celular = pRecorrido->telefono;//Copia el No.Telefono del puntero.
                pSiguiente->telefono = celular;//Actualiza puntero pSiguiente.
                email = pRecorrido->mail;//Copia el eMail del puntero.
                strcpy(pSiguiente->mail, email.c_str());//Actualiza puntero pSiguiente.
                direc = pRecorrido->direccion;//Copia la direccion del puntero.
                strcpy(pSiguiente->direccion, direc.c_str());//Actualiza puntero pSiguiente.

                pRecorrido->codigo = codigo;//Realizando el cambio para ordenar la lista.
                strcpy(pRecorrido->nombre, nombre.c_str());//Realizando el cambio para ordenar la lista.
                pRecorrido->edad = edad;//Realizando el cambio para ordenar la lista.
                strcpy(pRecorrido->dpi, dpi.c_str());//Realizando el cambio para ordenar la lista.
                pRecorrido->telefono = telefono;//Realizando el cambio para ordenar la lista.
                strcpy(pRecorrido->mail, mail.c_str());//Realizando el cambio para ordenar la lista.
                strcpy(pRecorrido->direccion, direccion.c_str());//Realizando el cambio para ordenar la lista.
            }else{}
            pSiguiente = pSiguiente->pSig;//Salto al siguiente nodo.
        }
        pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
        pSiguiente = pRecorrido->pSig;
    }/*Fin Algoritmo Burbuja*/
}

//Función para seleccionar opcion del menu para realizar la busqueda en la lista.
void menuBusqueda(){
    int opc = 0;
    do{
        system("cls"); system("color 09");
        cout << "\n\t ********** REALIZAR BUSQUEDA EN LA LISTA **********\n" << endl;
        cout << "\t .--------------------------------." << endl;
        cout << "\t | 1 | |    Busqueda por Codigo   |" << endl;
        cout << "\t | 2 | |    Busqueda por Nombre   |" << endl;
        cout << "\t | 3 | |     Busqueda por Edad    |" << endl;
        cout << "\t | 4 | |     Busqueda por DPI     |" << endl;
        cout << "\t | 5 | | Volver al Menu Principal |" << endl;
        cout << "\t '--------------------------------'\n" << endl;
        cout << " Digite su opcion: "; cin >> opc; cin.ignore();
        switch(opc){
            case 1:
                buscarCodigo(); getch();
                break;
            case 2:
                buscarNombre(); getch();
                break;
            case 3:
                buscarEdad(); getch();
                break;
            case 4:
                buscarDPI(); getch();
                break;
            case 5:
                break;
            default:
                cout << "\n\t No es una opcion valida" << endl; getch();
        }
    }while(opc!=5);
}

//Función para buscar en la lista por el codigo.
void buscarCodigo(){
    //Variables a utilizar.
    int codigo=0;
    bool encontrado=false;

    system("cls"); system("color 09");
    cout << "\n\t ************ BUSCAR PERSONA POR EL CODIGO ************\n" << endl;
    cout << " Digite el codigo a buscar:        \t" ; cin >> codigo; cin.ignore();
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    if(pInicio!=NULL){//Condicional para verificar si la lista tiene nodos.
        while(pRecorrido!=NULL){//Mientras no este en el ultimo nodo de la lista.
            if(pRecorrido->codigo == codigo){//Condicional para comparar el codigo ingresado, en la lista.
                system("color 0A");
                cout << "\n\t Registro encontrado!\n" << endl;
                cout << " Codigo:       \t" << pRecorrido->codigo << endl;
                cout << " Nombre:       \t" << pRecorrido->nombre << endl;
                cout << " Edad:         \t" << pRecorrido->edad << endl;
                cout << " No. DPI/CUI:  \t" << pRecorrido->dpi << endl;
                cout << " No. Celular:  \t" << pRecorrido->telefono << endl;
                cout << " eMail:        \t" << pRecorrido->mail << endl;
                cout << " Direccion:    \t" << pRecorrido->direccion << endl;
                encontrado=true;
            }else{}
            pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
        }
        if(encontrado==false){//Condicional por si no se encuentra el codigo ingresado.
            system("color 04");
            cout << "\n El codigo que ingreso, ( " << codigo << " )." << endl;
            cout << " No pertenece a ninguna persona de la lista." << endl;
        }else{}
    }else{
        system("color 04");
        cout << " \n\n\t\t La lista esta vacia." << endl;
    }
}

//Función para buscar en la lista por el nombre.
void buscarNombre(){
    //Variables a utilizar.
    char linea1 [] = "";
    char linea2 [] = "";
    char linea3 [] = "";
    char nombre [65];
    bool encontrado=false;

    system("cls");system("color 09");
//    for (int i;i<25;i++){//Linea 1.
//        cout << intro[i];
//        Sleep(35);
//    }
    cout << "******************************************************" << endl;
    cout << "************ BUSCAR PERSONA POR EL NOMBRE ************" << endl;
    cout << "******************************************************" << endl;
    cout << " Digite el nombre a buscar:        \t" ; cin.getline(nombre, 65);
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    if(pInicio!=NULL){//Condicional para verificar si la lista tiene nodos.
        while(pRecorrido!=NULL){//Mientras no este en el ultimo nodo de la lista.
            if(strcmp(pRecorrido->nombre, nombre)==0){//Condicional para comparar el nombre ingresado, en la lista.
                system("color 0A");
                cout << "\n\t Registro encontrado!\n" << endl;
                cout << " Codigo:       \t" << pRecorrido->codigo << endl;
                cout << " Nombre:       \t" << pRecorrido->nombre << endl;
                cout << " Edad:         \t" << pRecorrido->edad << endl;
                cout << " No. DPI/CUI:  \t" << pRecorrido->dpi << endl;
                cout << " No. Celular:  \t" << pRecorrido->telefono << endl;
                cout << " eMail:        \t" << pRecorrido->mail << endl;
                cout << " Direccion:    \t" << pRecorrido->direccion << endl;
                encontrado=true;
            }else{}
            pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
        }
        if(encontrado==false){//Condicional por si no se encuentra el codigo ingresado.
            system("color 04");
            cout << "\n El nombre que ingreso, ( " << nombre << " )." << endl;
            cout << " No pertenece a ninguna persona de la lista." << endl;
        }else{}
    }else{
        system("color 04");
        cout << " \n\n\t\t La lista esta vacia." << endl;
    }
}

//Función para buscar en la lista por la edad.
void buscarEdad(){
    //Variables a utilizar.
    int edad=0;
    bool encontrado=false;

    system("cls"); system("color 09");
    cout << "\n\t ************ BUSCAR PERSONA POR LA EDAD ************\n" << endl;
    cout << " Digite la edad a buscar:        \t" ; cin >> edad; cin.ignore();
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    if(pInicio!=NULL){//Condicional para verificar si la lista tiene nodos.
        while(pRecorrido!=NULL){//Mientras no este en el ultimo nodo de la lista.
            if(pRecorrido->edad == edad){//Condicional para comparar la edad ingresada, en la lista.
                system("color 0A");
                cout << "\n\t Registro encontrado!\n" << endl;
                cout << " Codigo:       \t" << pRecorrido->codigo << endl;
                cout << " Nombre:       \t" << pRecorrido->nombre << endl;
                cout << " Edad:         \t" << pRecorrido->edad << endl;
                cout << " No. DPI/CUI:  \t" << pRecorrido->dpi << endl;
                cout << " No. Celular:  \t" << pRecorrido->telefono << endl;
                cout << " eMail:        \t" << pRecorrido->mail << endl;
                cout << " Direccion:    \t" << pRecorrido->direccion << endl;
                encontrado=true;
            }else{}
            pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
        }
        if(encontrado==false){//Condicional por si no se encuentra el codigo ingresado.
            system("color 04");
            cout << "\n La edad que ingreso, ( " << edad << " )." << endl;
            cout << " No pertenece a ninguna persona de la lista." << endl;
        }else{}
    }else{
        system("color 04");
        cout << " \n\n\t\t La lista esta vacia." << endl;
    }
}

//Función para buscar en la lista por el No.DPI.
void buscarDPI(){
    //Variables a utilizar.
    char dpi[16];
    bool encontrado=false;

    system("cls"); system("color 09");
    cout << "\n\t ************ BUSCAR PERSONA POR EL NO.DPI ************\n" << endl;
    cout << " Digite el No.DPI a buscar:        \t" ; cin.getline(dpi, 16);
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    if(pInicio!=NULL){//Condicional para verificar si la lista tiene nodos.
        while(pRecorrido!=NULL){//Mientras no este en el ultimo nodo de la lista.
            if(strcmp(pRecorrido->dpi, dpi)==0){//Condicional para comparar el nombre ingresado, en la lista.
                system("color 0A");
                cout << "\n\t Registro encontrado!\n" << endl;
                cout << " Codigo:       \t" << pRecorrido->codigo << endl;
                cout << " Nombre:       \t" << pRecorrido->nombre << endl;
                cout << " Edad:         \t" << pRecorrido->edad << endl;
                cout << " No. DPI/CUI:  \t" << pRecorrido->dpi << endl;
                cout << " No. Celular:  \t" << pRecorrido->telefono << endl;
                cout << " eMail:        \t" << pRecorrido->mail << endl;
                cout << " Direccion:    \t" << pRecorrido->direccion << endl;
                encontrado=true;
            }else{}
            pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
        }
        if(encontrado==false){//Condicional por si no se encuentra el codigo ingresado.
            system("color 04");
            cout << "\n El No.DPI que ingreso, ( " << dpi << " )." << endl;
            cout << " No pertenece a ninguna persona de la lista." << endl;
        }else{}
    }else{
        system("color 04");
        cout << " \n\n\t\t La lista esta vacia." << endl;
    }
}

//Función para eliminar un nodo de la lista.
void eliminarDatos(){
    system("cls");
    //Variables a utilizar.
    pTemporal=NULL;//Puntero para guardar el nodo anterior al actual en los recorridos de los ciclos.
    int codigo=0;//Variable para ingresar codigo a buscar en la lista.
    bool encontrado=false;

    cout << "\n\t ************ ELIMINAR PERSONA DE LA LISTA ************\n" << endl;
    cout << " Digite el codigo de la perosna a eliminar:    \t"; cin >> codigo; cin.ignore();
    pRecorrido=pInicio;
    if(pInicio != NULL){//Condicional para verificar si la lista no esta vacía.
         while(pRecorrido != NULL){//Mientras no sea el ultimo nodo de la lista.
            if(pRecorrido->codigo==codigo){//Condicional para comparar el codigo ingresado, en la lista.
                encontrado=true;
                system("color 0A");
                cout << "\n\t Registro encontrado!\n" << endl;
                cout << " Codigo:       \t" << pRecorrido->codigo << endl;
                cout << " Nombre:       \t" << pRecorrido->nombre << endl;
                cout << " Edad:         \t" << pRecorrido->edad << endl;
                cout << " No. DPI/CUI:  \t" << pRecorrido->dpi << endl;
                cout << " No. Celular:  \t" << pRecorrido->telefono << endl;
                cout << " eMail:        \t" << pRecorrido->mail << endl;
                cout << " Direccion:    \t" << pRecorrido->direccion << endl;
                /*Inicio-Condicionales para Eliminar el nodo solictado y re-dirigir los punteros*/
                if(pRecorrido==pInicio){//Primer caso, que el nodo a eliminar sea el primero de la Lista.
                    pInicio = pInicio->pSig;//pInicio será ahora igual pInicio->pSig.
                    pInicio->pAnt = NULL;//El apuntador pAnt de pInicio ahora será NULL.
                }else if(pRecorrido==pFinal){//Segundo caso, que el nodo a eliminar sea el último de la lista.
                    pTemporal->pAnt = NULL;//El apuntador pAnt de pTemporal ahora será NULL.
                    pFinal = pTemporal;//pFinal ahora será igual pTemporal.
                }else{//Tercer caso, que el nodo a eliminar no se encuentre en el inicio o final de la lista.
                    pTemporal->pSig = pRecorrido->pSig;//pTemporal->pSig ahora apunta hacía pRecorrido->pSig;
                    pRecorrido->pSig->pAnt = pTemporal;//El nodo actual del ciclo en su puntero pSig, que ese * en su pAnt sea al temporal.
                }
                free(pRecorrido); //delete(pRecorrido); Elimina el nodo actual del recorrido de la lista.
                system("color 0C");
                cout << "\n\t Registro eliminado!" << endl;
                /*Fin*/
            }else{
                pTemporal = pRecorrido;//pTemporal igual al nodo actual del ciclo antes de que pase al siguiente nodo.
                pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
            }
         }
         if(encontrado==false){//Condicional por si no se encuentra el codigo ingresado.
            system("color 04");
            cout << "\n El codigo que ingreso, ( " << codigo << " )." << endl;
            cout << " No pertenece a ninguna persona de la lista." << endl;
        }else{}
    }else{
        system("color 04");
        cout << " \n\t\t\t La lista esta vacia." << endl;
    }
}

//Función para imprimir la lista en pantalla de Inicio a Fin.
void inicioFin(){
    system("cls");
    cout << "\n\t ********** MOSTRAR DE INICIO A FIN **********\n" << endl;
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    while(pRecorrido != NULL){//Mientras no este en el ultimo nodo de la lista.
        cout << " <--- " << endl;
        cout << " Codigo:       \t" << pRecorrido->codigo << endl;
        cout << " Nombre:       \t" << pRecorrido->nombre << endl;
        cout << " Edad:         \t" << pRecorrido->edad << endl;
        cout << " No. DPI/CUI:  \t" << pRecorrido->dpi << endl;
        cout << " No. Celular:  \t" << pRecorrido->telefono << endl;
        cout << " eMail:        \t" << pRecorrido->mail << endl;
        cout << " Direccion:    \t" << pRecorrido->direccion << endl;
        cout << " ---> " << endl;
        pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
    }
    cout << " NULL" << endl;
}

//Función para imprimir la lista en pantalla de Fin a Inicio.
void finInicio(){
    system("cls");
    cout << "\n\t ********** MOSTRAR DE FIN A INICIO **********\n" << endl;
    pRecorrido = pFinal;//Igualar punteros para empezar el recorrido desde el final de la lista.
    cout << " NULL" << endl;
    while(pRecorrido != NULL){//Mientras no este en el ultimo nodo de la lista.
        cout << " <--- " << endl;
        cout << " Codigo:       \t" << pRecorrido->codigo << endl;
        cout << " Nombre:       \t" << pRecorrido->nombre << endl;
        cout << " Edad:         \t" << pRecorrido->edad << endl;
        cout << " No. DPI/CUI:  \t" << pRecorrido->dpi << endl;
        cout << " No. Celular:  \t" << pRecorrido->telefono << endl;
        cout << " eMail:        \t" << pRecorrido->mail << endl;
        cout << " Direccion:    \t" << pRecorrido->direccion << endl;
        cout << " ---> " << endl;
        pRecorrido = pRecorrido->pAnt;//Salto al siguiente nodo.
    }
}

//Función para mostrar el recorrido de la lista, de las primeras 4 columnas.
void reporte(){
    system("cls");
    cout << "\n\t\t\t ********** REPORTE DE PERSONAS DE LA LISTA **********\n" << endl;
    cout << " \t| \tCodigo:\t\t|| \t\tNombre:\t\t|| \tEdad\t\t|| \tNo.DPI/CUI\t\t| " << endl;
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    while(pRecorrido != NULL){//Mientras no este en el ultimo nodo de la lista.
        cout << " \t| \t" << pRecorrido->codigo << "\t\t|| \t" << pRecorrido->nombre << "\t\t|| \t" << pRecorrido->edad << "\t\t|| \t" << pRecorrido->dpi << "\t\t|\n" << endl;
        pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
    }
}

//Función para contar las personas de la lista y mostrar el total.
void cantidadPersonas(){
    system("cls");
    cout << "\n\t\t ********** CANTIDAD DE PERSONAS EN LA LISTA **********\n" << endl;
    int personas = 0;//Varible para guaradar la cantidad de personas en la lista.
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el final de la lista.
    while(pRecorrido != NULL){//Mientras no este en el ultimo nodo de la lista.
        personas++;
        pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
    }
    cout << " Esta lista doblemente enlazada, tiene registrada " << personas << " persona(s)." << endl;
}
