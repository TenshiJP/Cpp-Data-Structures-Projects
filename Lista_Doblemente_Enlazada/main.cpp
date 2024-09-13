/*
       *** LISTA DE ALUMNOS DOBLEMENTE ENLAZADA ***
    Curso:      Progrmación III - Estructura de Datos.
    Nombre:     Angel Roberto Jacinto Payes.
    No.Carnet:  5990-20-1756.
*/

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

//Estructura para datos del carnet.
struct carnet{
    int codCarrera=0, anioIngreso=0, noCorrelativo=0;
};

//Estructura para datos de la fecha.
struct fecha{
    int dia=0, mes=0, anio=0;
};

//Estructura doblemente enlazada.
typedef struct dobleenlazada{
    struct carnet noCarnet;
    char nombre[70];
    int telefono;
    char direccion[90];
    struct fecha fNacimiento;
    struct dobleenlazada *pSig;
    struct dobleenlazada *pAnt;
} dobleEnlace;

//Nodos para la estructura.
dobleEnlace *pInicio, *pFinal, *pRecorrido, *pNuevo;

//Funciones a utlizar.
void ingresarDatos();   //Función para ingreasar datos al final de la lista doblemente enlazada.
void mostrarLista();    //Funcion para seleccionar las 2 formas de ver la lista.
void inicioFin();       //Recorrido a la lista de inicio a fin.
void finInicio();       //Recorrido a la lista de fin a inicio.
void busqueda();        //Función para buscar un alumno en la lista.
bool comprobar (int cod, int anio, int no);      //Función para evitar el ingreso de dos alumnos con el mismo no.carnet.

int main()
{
    int opcion=0;
    do{
        system("cls");
        cout << "\n\t\t .-----------------------------------------." << endl;
        cout << "\t\t |                                         |" << endl;
        cout << "\t\t |    LISTA DE ESTUDIANTES - CHINAUTLA     |" << endl;
        cout << "\t\t |                                         |" << endl;
        cout << "\t\t :-----------------------------------------:" << endl;
        cout << "\t\t |    ||                                   |" << endl;
        cout << "\t\t | 1. ||    Ingresar alumno a la Lista     |" << endl;
        cout << "\t\t | 2. ||    Mostrar alumnos de la Lista    |" << endl;
        cout << "\t\t | 3. ||   Buscar un alumno en la Lista    |" << endl;
        cout << "\t\t | 4. ||               Salir               |" << endl;
        cout << "\t\t |    ||                                   |" << endl;
        cout << "\t\t '-----------------------------------------'\n" << endl;
        cout << "\t  Digite su opcion: "; cin >> opcion;
        switch(opcion){
            case 1:
                ingresarDatos(); getch();
                break;
            case 2:
                mostrarLista();
                break;
            case 3:
                busqueda(); getch();
                break;
            case 4:
                system("cls"); cout << "\n\t Adios" << endl;
                break;
            default:
                cout << "\n\t No es una opcion valida" << endl; getch();
        }
    }while(opcion!=4);
    return 0;
}

//Función para ingreasar datos al final de la lista doblemente enlazada.
void ingresarDatos(){
    system("cls");
    pNuevo = (dobleEnlace *)malloc(sizeof(dobleEnlace));//Buscar espacio en memoria.

    if(pNuevo==NULL){
         cout << " No hay espacio en memoria disponible para crear mas nodos." << endl;
    }else{
        /*Ingreso de datos e inicialización de punteros*/
        cout << "\n \t**********INGRESO DE DATOS**********\n" << endl;
        cout << " Numero de carnet\n" << endl;
        cout << " Ingrese codigo de carrera:        "; cin >> pNuevo->noCarnet.codCarrera; cin.ignore();
        cout << " Ingrese anio de ingreso:          "; cin >> pNuevo->noCarnet.anioIngreso; cin.ignore();
        cout << " Ingrese No.Correlativo:           "; cin >> pNuevo->noCarnet.noCorrelativo; cin.ignore();
        cout << "\n Ingrese nombre completo:          "; cin.getline(pNuevo->nombre, 70);
        cout << " Ingrese No.Telefono:              "; cin >> pNuevo->telefono; cin.ignore();
        cout << " Ingrese direccion de domicilio:   "; cin.getline(pNuevo->direccion, 90);
        cout << "\n Fecha de Nacimiento" << endl;
        do{
            cout << " Ingrese dia:                      "; cin >> pNuevo->fNacimiento.dia; cin.ignore();
            if(pNuevo->fNacimiento.dia<1 || pNuevo->fNacimiento.dia>31)
               cout << "\t Error: No es un dia valido.\n" << endl;
        }while(pNuevo->fNacimiento.dia<1 || pNuevo->fNacimiento.dia>31);
        do{
            cout << " Ingrese mes:                      "; cin >> pNuevo->fNacimiento.mes; cin.ignore();
            if(pNuevo->fNacimiento.mes<1 || pNuevo->fNacimiento.mes>12)
                cout << "\t Error: El mes ingresado no existe.\n" << endl;
        }while(pNuevo->fNacimiento.mes<1 || pNuevo->fNacimiento.mes>12);
        cout << " Ingrese anio:                     "; cin >> pNuevo->fNacimiento.anio; cin.ignore();
        pNuevo->pSig = NULL;
        pNuevo->pAnt = NULL;
        /*Fin*/

        if((comprobar(pNuevo->noCarnet.codCarrera, pNuevo->noCarnet.anioIngreso, pNuevo->noCarnet.noCorrelativo)==true)){//Comprobar que no exista un No.Carnet igual en la lista.
            return;
        }else{}

        /* Para el puntero Inicio, si llegara a ser igual a nill, hay dos opciones:
            1.-  Perdimos la lista (Peor escenario).
            2.-  Esta vacia.    */
        if(pInicio==NULL){
            pInicio = pNuevo;//Sera el primero y ultimo nodo en la lista.
            pFinal  = pNuevo;
            cout << "\n\t Registro Guardado." << endl;
            cout << " No.Carnet:                " << pNuevo->noCarnet.codCarrera << "-" << pNuevo->noCarnet.anioIngreso << "-" << pNuevo->noCarnet.noCorrelativo << endl;
            cout << " Nombre:                   " << pNuevo->nombre << endl;
            cout << " Telefono:                 " << pNuevo->telefono << endl;
            cout << " Direccion de domicilio:   " << pNuevo->direccion << endl;
            cout << " Fecha de nacimiento:      " << pNuevo->fNacimiento.dia << "-" << pNuevo->fNacimiento.mes << "-" << pNuevo->fNacimiento.anio << endl;
        }else{
            pNuevo->pAnt = pFinal;//Enlazar basado en el ultimo.
            pFinal->pSig = pNuevo;
            pFinal = pNuevo;
            pFinal->pSig = NULL;
            cout << "\n\t Registro Guardado." << endl;
            cout << " No.Carnet:                " << pNuevo->noCarnet.codCarrera << "-" << pNuevo->noCarnet.anioIngreso << "-" << pNuevo->noCarnet.noCorrelativo << endl;
            cout << " Nombre:                   " << pNuevo->nombre << endl;
            cout << " Telefono:                 " << pNuevo->telefono << endl;
            cout << " Direccion de domicilio:   " << pNuevo->direccion << endl;
            cout << " Fecha de nacimiento:      " << pNuevo->fNacimiento.dia << "-" << pNuevo->fNacimiento.mes << "-" << pNuevo->fNacimiento.anio << endl;
        }
    }
}

//Funcion para seleccionar las 2 formas de ver la lista.
void mostrarLista(){
    int opc=0;
    do{
        system("cls");
        cout << "\n\t ********** VER LISTA DOBLEMENTE ENLAZADA **********\n" << endl;
        cout << "\t .---------------------------." << endl;
        cout << "\t | 1 | | Ver de inicio a fin |" << endl;
        cout << "\t | 2 | | Ver de fin a inicio |" << endl;
        cout << "\t | 3 | |    Volver al menu   |" << endl;
        cout << "\t '---------------------------'\n" << endl;
        cout << " Digite su opcion: "; cin >> opc; cin.ignore();
        switch(opc){
            case 1:
                inicioFin(); getch();
                break;
            case 2:
                finInicio(); getch();
                break;
            case 3:
                break;
            default:
                cout << "\n\t Opción no valida." << endl; getch();
        }
    }while(opc!=3);
}

//Recorrido a la lista de inicia a fin.
void inicioFin(){
    system("cls");
    cout << "\t ********** MOSTRAR DE INICIO A FIN **********\n" << endl;
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    while(pRecorrido != NULL){//Mientras no este en el ultimo nodo de la lista.
        cout << " <-- " << endl;
        cout << " No.Carnet:                " << pRecorrido->noCarnet.codCarrera << "-" << pRecorrido->noCarnet.anioIngreso << "-" << pRecorrido->noCarnet.noCorrelativo << endl;
        cout << " Nombre:                   " << pRecorrido->nombre << endl;
        cout << " Telefono:                 " << pRecorrido->telefono << endl;
        cout << " Direccion de domicilio:   " << pRecorrido->direccion << endl;
        cout << " Fecha de nacimiento:      " << pRecorrido->fNacimiento.dia << "-" << pRecorrido->fNacimiento.mes << "-" << pRecorrido->fNacimiento.anio << endl;
        cout << " --> " << endl;
        pRecorrido = pRecorrido->pSig;
    }
    cout << " Nill" << endl;
}

//Recorrido a la lista de fin a inicio.
void finInicio(){
    system("cls");
    cout << "\t ********** MOSTRAR DE FIN A INICIO **********\n" << endl;
    pRecorrido = pFinal;//Igualar punteros para empezar el recorrido desde el final de la lista.
    cout << " Nill" << endl;
    while(pRecorrido != NULL){//Mientras no este en el ultimo nodo de la lista.
        cout << " <-- " << endl;
        cout << " No.Carnet:                " << pRecorrido->noCarnet.codCarrera << "-" << pRecorrido->noCarnet.anioIngreso << "-" << pRecorrido->noCarnet.noCorrelativo << endl;
        cout << " Nombre:                   " << pRecorrido->nombre << endl;
        cout << " Telefono:                 " << pRecorrido->telefono << endl;
        cout << " Direccion de domicilio:   " << pRecorrido->direccion << endl;
        cout << " Fecha de nacimiento:      " << pRecorrido->fNacimiento.dia << "-" << pRecorrido->fNacimiento.mes << "-" << pRecorrido->fNacimiento.anio << endl;
        cout << " --> " << endl;
        pRecorrido = pRecorrido->pAnt;
    }
}

//Función para buscar un alumno en la lista.
void busqueda(){
    //Variables a utilizar.
    struct carnet noCarnet;
    int carnetFound=0;
    system("cls");
    cout << "\n\t ************ BUSCAR ALUMNO EN LA LISTA ************\n" << endl;
    cout << " Buscar por carnet" << endl;
    cout << " Digite codigo de carrera  : "; cin >> noCarnet.codCarrera; cin.ignore();
    cout << " Digite anio de ingreso    : "; cin >> noCarnet.anioIngreso; cin.ignore();
    cout << " Digite no.correlativo     : "; cin >> noCarnet.noCorrelativo; cin.ignore();

    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    if(pInicio!=NULL){//Condicional para verificar si la lista tiene nodos.
        while(pRecorrido!=NULL){//Mientras no este en el ultimo nodo de la lista.
            if(pRecorrido->noCarnet.codCarrera==noCarnet.codCarrera && pRecorrido->noCarnet.anioIngreso==noCarnet.anioIngreso && pRecorrido->noCarnet.noCorrelativo==noCarnet.noCorrelativo){
                cout << "\n\t Alumno encontrado!\n" << endl;
                cout << " No.Carnet:                " << pRecorrido->noCarnet.codCarrera << "-" << pRecorrido->noCarnet.anioIngreso << "-" << pRecorrido->noCarnet.noCorrelativo << endl;
                cout << " Nombre:                   " << pRecorrido->nombre << endl;
                cout << " Telefono:                 " << pRecorrido->telefono << endl;
                cout << " Direccion de domicilio:   " << pRecorrido->direccion << endl;
                cout << " Fecha de nacimiento:      " << pRecorrido->fNacimiento.dia << "-" << pRecorrido->fNacimiento.mes << "-" << pRecorrido->fNacimiento.anio << endl;
                carnetFound++;
            }else{}
            pRecorrido = pRecorrido->pSig;
        }
        if(carnetFound==0){//Condicional si no se encuentra el alumno en la lista.
            cout << "\n El no.carnet que ingreso: " << noCarnet.codCarrera << "-" << noCarnet.anioIngreso << "-" << noCarnet.noCorrelativo << "." << endl;
            cout << " No pertenece a ningun alumno de la lista." << endl;
        }else{}
    }else{
        cout << " \n\t La lista esta vacia." << endl;
    }
}

//Función para evitar el ingreso de dos alumnos con el mismo no.carnet.
bool comprobar(int cod, int anio, int no){
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    while(pRecorrido!=NULL){//Mientras no este en el ultimo nodo de la lista.
        if(pRecorrido->noCarnet.codCarrera==cod && pRecorrido->noCarnet.anioIngreso==anio && pRecorrido->noCarnet.noCorrelativo==no){
            cout << "\n\t Lo sentimos, el No.Carnet " << cod << "-" << anio << "-" << no <<" esta existente. Intente de nuevo." << endl;
            return true;
        }else{}
        pRecorrido = pRecorrido->pSig;
    }
    return false;
}
