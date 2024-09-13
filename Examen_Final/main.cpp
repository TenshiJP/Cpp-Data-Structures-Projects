/*
    *-------------- EXAMEN FINAL - PARTE PRACTICA --------------*
        Nombre:         Angel Roberto Jacinto Payes
        No.Carnet:      5990-20-1756
    *-----------------------------------------------------------*



    Preámbulo:
    Pensando en algún problema que alguien en mi alrededor posea sobre el manejo de datos, recordé a un amigo que tiene un negocio de venta
    de videojuegos por las redes sociales.

    ¿Cuál es el problema? El problema es que él no tiene un control formal o automatizado sobre sus productos, todo lo tiene apuntado en un
    cuaderno, que muchas ocasiones no tiene actualizado su contenido.

    La solución que desarrollé en este software, fue un programa con memoria dinámica lineal (lista doblemente enlazada), para que el lleve
    un control mas eficaz ahora sobre sus productos.

    ¿Por qué se utilizó memoria dinámica? Decidí utilizar memoria dinámica debido a que el nunca tiene un numero exacto de videojuegos
    diferentes, hay ocasiones donde el tiene alrededor de 100 productos diferentes, pero en otras tiene menos o más productos, como lo seria
    55 o 321. Por lo cual utilicé una lista doblemente enlazada, esto debido que no maneja una cantidad de datos que sobrepasen las centenas.
    Por lo cual para evitar estar consumiendo memoria innecesaria de la máquina fue tomada de mi parte esa decisión. Además, se carga los
    registros de un archivo txt a la lista dinámica, y se descarga de la lista dinámica a un archivo txt.

*/

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <String.h>
#include <windows.h>
#include <fstream>  //Librería para el manejo de archivos txt.

using namespace std;

//Estructura de los nodos para lista doblemente enlazada.
typedef struct dobleenlazada{
    int     codigo;
    char    nombre[50];
    char    consola[20];
    char    genero[20];
    char    clasificacion[5];
    char    desarrolladores[30];
    char    estado[12];
    char    idioma[10];
    int     cantidad;
    float   precio;
    struct  dobleenlazada *pSig;
    struct  dobleenlazada *pAnt;
} doble;

//Nodos a utilizar.
doble *pInicio, *pFinal, *pRecorrido, *pNuevo, *pSiguiente, *pTemporal;

//Estrucutura con variables, para ingresar y modificar datos de los nodos.
struct videogame{
    int     codigo, cantidad, precio;
    string  nombre, consola, genero, clasificacion, desarrolladores, estado, idioma;
};

//Funciones a utilizar.
void cargarLista(ifstream &lectura);            //Función para cargar los datos de los videojuegos del fichero a la memoria de la máquina.
void ingresarGame();                            //Función para insertar los datos de un nuevo videojuego en la lista.
bool comprobar(int cod);                        //Función para evitar que no exista, dos registros con el mismo codigo en la lista.
void ordenarLista(doble *pLista);               //Función para ordenar los registros de la lista, mediante el codigo de manera ascedente.
void descargarLista(ofstream &escritura);       //Función para descargar los datos de los videojuegos de  la memoria de la máquina al fichero.
void menuBusqueda();                            //Función que imprime un menu con las opcines de búsqueda en la lista disponibles.
void buscarCodigo();                            //Función para buscar un videojuego en la lista, mediante el dato del código.
void buscarNombre();                            //Función para buscar un videojuego en la lista, mediante el nombre del mismo.
void buscarConsola();                           //Función para buscar un videojuego en la lista, mediante el nombre de la consola.
void editarCantidad();                          //Función para actualizar la cantidad que se tiene registrada del videojuego solitado por medio de su código.
void reporte();                                 //Función para imprimir en pantalla todos los registros de la lista, en un tabla con columnas(titulos) y filas(datos del videojuego).
void gotoxy(int x,int y);                       //Función para asignar una posición de pantalla con los ejes X, Y cuando se vaya a imprimir en pantalla.

//Varaibles a utilizar.
ifstream lectura; ofstream escritura;//Variables para el manejo de archivos txt.
videogame game, game1;
int opcion=0, opc=0;

int main()//Función principal.
{
    cargarLista(lectura);//Carga los datos que se encuentren en el archivo.txt a la memoria del pc, de forma dinamica lineal.
    do{
        system("cls"); system("color 07");
        cout << "\n\t\t\t +--------------------------------------------------------+" << endl;
        cout << "\t\t\t |                                                        |" << endl;
        cout << "\t\t\t |            *****   SOLO VIDEOJUEGOS   *****            |" << endl;
        cout << "\t\t\t |                                                        |" << endl;
        cout << "\t\t\t +--------------------------------------------------------+" << endl;
        cout << "\t\t\t |    ||                                                  |" << endl;
        cout << "\t\t\t | 1. ||         Ingresar videojuego a la lista           |" << endl;
        cout << "\t\t\t | 2. ||          Buscar videojuego en la lista           |" << endl;
        cout << "\t\t\t | 3. || Actualizar cantidad de un videojuego en la lista |" << endl;
        cout << "\t\t\t | 4. ||              Reporte de videojuegos              |" << endl;
        cout << "\t\t\t | 5. ||                       Salir                      |" << endl;
        cout << "\t\t\t |    ||                                                  |" << endl;
        cout << "\t\t\t +--------------------------------------------------------+\n" << endl;
        cout << "\t\t  Digite su opcion: "; cin >> opcion;
        switch(opcion){
            case 1:
                ingresarGame(); getch();
                break;
            case 2:
                menuBusqueda(); getch();
                break;
            case 3:
                editarCantidad(); getch();
                break;
            case 4:
                reporte(); getch();
                break;
            case 5:
                system("color 0F"); system("cls");
                system("cls"); cout << "\n\t\t Saliendo . . ." << endl;
                break;
            default:
                system("color 0C");
                cout << "\n\n\t\t No es una opcion valida" << endl; getch();
        }
    }while(opcion!=5);
    return 0;
}

//Función para cargar los datos de los videojuegos del fichero a la memoria de la máquina.
void cargarLista(ifstream &lectura){
    doble juego;
    lectura.open("videogames.txt",ios::in);//Abre el archivo.txt
    if(lectura.fail()){   //Condicional por si falla al abrir el archivo.
            system("cls");system("color 0C");cout << "\n\t No existe archivo, para cargar lista a memoria.\n\t Presione una tecla para continuar..." <<endl;
            getch(); return;
    }
    lectura >> juego.codigo;//Cragar información.
    while(!lectura.eof()){//Mientras no sea el final.
        //Cargar la información del txt a memoria.
        lectura >> juego.nombre;
        lectura >> juego.consola;
        lectura >> juego.genero;
        lectura >> juego.clasificacion;
        lectura >> juego.desarrolladores;
        lectura >> juego.estado;
        lectura >> juego.idioma;
        lectura >> juego.cantidad;
        lectura >> juego.precio;
        //cout << "\n" << juego.codigo << " " <<juego.nombre <<" " <<juego.consola << " " <<juego.genero <<" " <<juego.clasificacion <<" " <<juego.desarrolladores <<" " <<juego.estado <<" " <<juego.idioma <<" " <<juego.cantidad <<" " <<juego.precio;
        if(!lectura.eof()){
            pNuevo = (doble *)malloc(sizeof(doble));//Buscar espacio en memoria.
            if(pNuevo==NULL){//Condicional para saber si el puntero pNuevo es NULL.
                system("cls"); system("color 04");
                cout << " No hay espacio en memoria disponible para crear mas nodos." << endl;
            }else{
                //Agregar los datos cargados e inicialización de punteros
                pNuevo->codigo = juego.codigo;
                strcpy(pNuevo->nombre, juego.nombre);
                strcpy(pNuevo->consola, juego.consola);
                strcpy(pNuevo->genero, juego.genero);
                strcpy(pNuevo->clasificacion, juego.clasificacion);
                strcpy(pNuevo->desarrolladores, juego.desarrolladores);
                strcpy(pNuevo->estado, juego.estado);
                strcpy(pNuevo->idioma, juego.idioma);
                pNuevo->cantidad = juego.cantidad;
                pNuevo->precio = juego.precio;
                pNuevo->pSig = NULL;
                pNuevo->pAnt = NULL;
                // Para el puntero Inicio, si llegara a ser igual a nill, hay dos opciones:
                //      1.-  Perdimos la lista (Peor escenario).
                //      2.-  Esta vacia.
                if(pInicio==NULL){
                    pInicio = pNuevo;//Sera el primero y ultimo nodo en la lista.
                    pFinal  = pInicio;
                }else{
                    pNuevo->pAnt = pFinal;//Enlazar basado en el ultimo.
                    pFinal->pSig = pNuevo;
                    pFinal = pNuevo;
                    pFinal->pSig = NULL;
                    ordenarLista(pInicio);//Llama a la función para ordenar en la lista el dato recien ingresado.
                }
            }
        }
        lectura >> juego.codigo;//Salto al siguiente.
    }
    lectura.close();//Cierra archivo.txt
    descargarLista(escritura);//Actualiza de manera ordenada la lista del txt, en caso se encontrará desordenada.
}

//Función para insertar los datos de un nuevo videojuego en la lista.
void ingresarGame(){
    system("cls");
    char c = ' '; string reemplazo = "_";   //Varibles para modificar los " " por "_".
    pNuevo = (doble *)malloc(sizeof(doble));//Buscar espacio en memoria.
    if(pNuevo==NULL){//Condicional para saber si el puntero pNuevo es NULL.
        system("cls"); system("color 04");
        cout << " No hay espacio en memoria disponible para crear mas nodos." << endl;
    }else{
        //Ingreso de datos e inicialización de punteros
        cout << "\n\t******************************************************" << endl;
        cout << "\t*********** INGRESO DE DATOS DEL VIDEOJUEGO **********" << endl;
        cout << "\t******************************************************\n" << endl;
        cout << " Ingrese Codigo:           \t"; cin>>game.codigo; cin.ignore();
        if((comprobar(game.codigo) == true)){//Comprobar que no exista un código igual en la lista.
            return;//Regresa al menú principal.
        }else{}
        cout << " Ingrese Nombre:           \t"; getline(cin, game.nombre);
        cout << " Ingrese Consola:          \t"; getline(cin, game.consola);
        cout << " Ingrese Genero:           \t"; getline(cin, game.genero);
        cout << " Ingrese Clasificacion:    \t"; getline(cin, game.clasificacion);
        cout << " Ingrese Desarrolladores:  \t"; getline(cin, game.desarrolladores);
        cout << " Ingrese Estado:           \t"; getline(cin, game.estado);
        cout << " Ingrese Idioma:           \t"; getline(cin, game.idioma);
        cout << " Ingrese Cantidad:         \t"; cin>>game.cantidad; cin.ignore();
        cout << " Ingrese Precio:           \t"; cin>>game.precio; cin.ignore();
        for(int i = 0; i < (int)(game.nombre).length(); ++i){//Iniciando el cambio de caracteres para guardar...
            if(game.nombre[i]==c)//Condicional para solicitar el cambio de caracteres donde sea necesario.
                game.nombre.replace(i,1,reemplazo);//Cambio de caracteres.
        }//Fin del cambio.
        for(int i = 0; i < (int)(game.consola).length(); ++i){//Iniciando el cambio de caracteres para guardar...
            if(game.consola[i]==c)//Condicional para solicitar el cambio de caracteres donde sea necesario.
                game.consola.replace(i,1,reemplazo);//Cambio de caracteres.
        }//Fin del cambio.
        for(int i = 0; i < (int)(game.genero).length(); ++i){//Iniciando el cambio de caracteres para guardar...
            if(game.genero[i]==c)//Condicional para solicitar el cambio de caracteres donde sea necesario.
                game.genero.replace(i,1,reemplazo);//Cambio de caracteres.
        }//Fin del cambio.
        for(int i = 0; i < (int)(game.desarrolladores).length(); ++i){//Iniciando el cambio de caracteres para guardar...
            if(game.desarrolladores[i]==c)//Condicional para solicitar el cambio de caracteres donde sea necesario.
                game.desarrolladores.replace(i,1,reemplazo);//Cambio de caracteres.
        }//Fin del cambio.
        for(int i = 0; i < (int)(game.estado).length(); ++i){//Iniciando el cambio de caracteres para guardar...
            if(game.estado[i]==c)//Condicional para solicitar el cambio de caracteres donde sea necesario.
                game.estado.replace(i,1,reemplazo);//Cambio de caracteres.
        }//Fin del cambio.
        pNuevo->codigo = game.codigo;
        strcpy(pNuevo->nombre, game.nombre.c_str());
        strcpy(pNuevo->consola, game.consola.c_str());
        strcpy(pNuevo->genero, game.genero.c_str());
        strcpy(pNuevo->clasificacion, game.clasificacion.c_str());
        strcpy(pNuevo->desarrolladores, game.desarrolladores.c_str());
        strcpy(pNuevo->estado, game.estado.c_str());
        strcpy(pNuevo->idioma, game.idioma.c_str());
        pNuevo->cantidad = game.cantidad;
        pNuevo->precio = game.precio;
        pNuevo->pSig = NULL;
        pNuevo->pAnt = NULL;//Fin
        // Para el puntero Inicio, si llegara a ser igual a nill, hay dos opciones:
        //      1.-  Perdimos la lista (Peor escenario).
        //      2.-  Esta vacia.
        if(pInicio==NULL){
            pInicio = pNuevo;//Sera el primero y ultimo nodo en la lista.
            pFinal  = pInicio;
            system("color 0A"); cout << "\n\t Registro Guardado." << endl;//Imprime los datos guardados.
            cout << " Codigo:           \t" << pNuevo->codigo << endl;
            cout << " Juego:            \t" << pNuevo->nombre << endl;
            cout << " Consola:          \t" << pNuevo->consola << endl;
            cout << " Genero:           \t" << pNuevo->genero << endl;
            cout << " Clasificación:    \t" << pNuevo->clasificacion << endl;
            cout << " Desarrolladores:  \t" << pNuevo->desarrolladores << endl;
            cout << " Estado:           \t" << pNuevo->estado << endl;
            cout << " Idioma:           \t" << pNuevo->idioma << endl;
            cout << " Cantidad:         \t" << pNuevo->cantidad << endl;
            cout << " Precio:           \t" << pNuevo->precio << endl;
            descargarLista(escritura);//Guarda el nuevo resgistro en el txt.
        }else{
            pNuevo->pAnt = pFinal;//Enlazar basado en el ultimo.
            pFinal->pSig = pNuevo;
            pFinal = pNuevo;
            pFinal->pSig = NULL;
            system("color 0A"); cout << "\n\t Registro Guardado." << endl;//Imprime los datos guardados.
            cout << " Codigo:           \t" << pNuevo->codigo << endl;
            cout << " Juego:            \t" << pNuevo->nombre << endl;
            cout << " Consola:          \t" << pNuevo->consola << endl;
            cout << " Genero:           \t" << pNuevo->genero << endl;
            cout << " Clasificación:    \t" << pNuevo->clasificacion << endl;
            cout << " Desarrolladores:  \t" << pNuevo->desarrolladores << endl;
            cout << " Estado:           \t" << pNuevo->estado << endl;
            cout << " Idioma:           \t" << pNuevo->idioma << endl;
            cout << " Cantidad:         \t" << pNuevo->cantidad << endl;
            cout << " Precio:           \t" << pNuevo->precio << endl;
            ordenarLista(pInicio);//Llama a la función para ordenar en la lista el dato recien ingresado.
            descargarLista(escritura);//Guarda el nuevo resgistro, con la lista ordenada en el txt.
        }
    }
}

//Función para evitar que no exista, dos registros con el mismo codigo en la lista.
bool comprobar(int cod){
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    while(pRecorrido!=NULL){//Mientras no este en el ultimo nodo de la lista.
        if(pRecorrido->codigo == cod){//Condición para comparar lo de la lista con el dato nuevo.
            system("color 04");
            cout << "\n\t Lo sentimos, el codigo: " << cod <<". Esta existente en la lista, intente de nuevo." << endl;
            return true;
        }else{}
        pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
    }
    return false;
}

//Función para ordenar los registros de la lista, mediante el codigo de manera ascedente.
void ordenarLista(doble *pLista){
    pRecorrido = pLista; //Igualar punteros, para iniciar el recorrido en el primer nodo.
    //Inicio algoritmo burbuja para ordenar los juegos por el codigo.
    while(pRecorrido->pSig!=NULL){//Mientras el puntero no apunte a null.
        pSiguiente = pRecorrido->pSig;//Igualar para iniciar en el primer nodo de la lista.
        while(pSiguiente != NULL){//Mientras no este en el ultimo nodo de la lista.
            if(pRecorrido->codigo > pSiguiente->codigo){//Condicional para ordenar los clientes en la lista de manera ascendente.
                game.codigo = pSiguiente->codigo;//Guarda codigo.
                game.nombre = pSiguiente->nombre;//Guarda nombre.
                game.consola = pSiguiente->consola;//Guarda consola.
                game.genero = pSiguiente->genero;//Guarda genero.
                game.clasificacion = pSiguiente->clasificacion;//Guarda clasificación.
                game.desarrolladores = pSiguiente->desarrolladores;//Guarda desarrolladores.
                game.estado = pSiguiente->estado;//Guarda estado.
                game.idioma = pSiguiente->idioma;//Guarda idioma.
                game.cantidad = pSiguiente->cantidad;//Guarda cantidad.
                game.precio = pSiguiente->precio;//Guarda precio.

                pSiguiente->codigo = pRecorrido->codigo;//Actualiza puntero pSiguiente.
                game1.nombre = pRecorrido->nombre;//Copia el nombre.
                strcpy(pSiguiente->nombre, game1.nombre.c_str());//Actualiza puntero pSiguiente.
                game1.consola = pRecorrido->consola;//Copia consola.
                strcpy(pSiguiente->consola, game1.consola.c_str());//Actualiza puntero pSiguiente.
                game1.genero = pRecorrido->genero;//Copia genero.
                strcpy(pSiguiente->genero, game1.genero.c_str());//Actualiza puntero pSiguiente.
                game1.clasificacion = pRecorrido->clasificacion;//Copia clasificación.
                strcpy(pSiguiente->clasificacion, game1.clasificacion.c_str());//Actualiza puntero pSiguiente.
                game1.desarrolladores = pRecorrido->desarrolladores;//Copia desarrolladores.
                strcpy(pSiguiente->desarrolladores, game1.desarrolladores.c_str());//Actualiza puntero pSiguiente.
                game1.estado = pRecorrido->estado;//Copia estado.
                strcpy(pSiguiente->estado, game1.estado.c_str());//Actualiza puntero pSiguiente.
                game1.idioma = pRecorrido->idioma;//Copia idioma.
                strcpy(pSiguiente->idioma, game1.idioma.c_str());//Actualiza puntero pSiguiente.
                game1.cantidad = pRecorrido->cantidad;//Copia cantidad.
                pSiguiente->cantidad = game1.cantidad;//Actualiza puntero pSiguiente.
                game1.precio = pRecorrido->precio;//Copia precio.
                pSiguiente->precio = game1.precio;//Actualiza puntero pSiguiente.

                pRecorrido->codigo = game.codigo;//Realizando el cambio para ordenar la lista.
                strcpy(pRecorrido->nombre, game.nombre.c_str());//Realizando el cambio para ordenar la lista.
                strcpy(pRecorrido->consola, game.consola.c_str());//Realizando el cambio para ordenar la lista.
                strcpy(pRecorrido->genero, game.genero.c_str());//Realizando el cambio para ordenar la lista.
                strcpy(pRecorrido->clasificacion, game.clasificacion.c_str());//Realizando el cambio para ordenar la lista.
                strcpy(pRecorrido->desarrolladores, game.desarrolladores.c_str());//Realizando el cambio para ordenar la lista.
                strcpy(pRecorrido->estado, game.estado.c_str());//Realizando el cambio para ordenar la lista.
                strcpy(pRecorrido->idioma, game.idioma.c_str());//Realizando el cambio para ordenar la lista.
                pRecorrido->cantidad = game.cantidad;//Realizando el cambio para ordenar la lista.
                pRecorrido->precio = game.precio;//Realizando el cambio para ordenar la lista.
            }else{}
            pSiguiente = pSiguiente->pSig;//Salto al siguiente nodo.
        }
        pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
        pSiguiente = pRecorrido->pSig;
    }/*Fin Algoritmo Burbuja*/
}

//Función para descargar los datos de los videojuegos de  la memoria de la máquina al fichero.
void descargarLista(ofstream &escritura){
    escritura.open("videojuegos.txt",ios::out | ios::app);//Abre el archivo.txt (si no existe lo crea y luego abre).
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    while(pRecorrido != NULL){//Mientras no este en el ultimo nodo de la lista.
        escritura << pRecorrido->codigo << " " << pRecorrido->nombre << " " << pRecorrido->consola << " " << pRecorrido->genero << " " << pRecorrido->clasificacion << " " << pRecorrido->desarrolladores << " " << pRecorrido->estado << " " << pRecorrido->idioma << " " << pRecorrido->cantidad << " " << pRecorrido->precio << "\n";//Escribe en el archivo txt.
        pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
    }
    escritura.close();
    remove("videogames.txt");//Elimina el archivo txt.
    rename("videojuegos.txt","videogames.txt");//Renombra el archivo txt.
}

//Función que imprime un menu con las opcines de búsqueda en la lista disponibles.
void menuBusqueda(){
    do{
        system("cls"); system("color 05");
        cout << "\n\t\t\t*******************************************************" << endl;
        cout << "\t\t\t************ REALIZAR BUSQUEDA EN LA LISTA ************" << endl;
        cout << "\t\t\t*******************************************************\n" << endl;
        cout << "\t +---------------------------------------------+" << endl;
        cout << "\t |   | |                                       |" << endl;
        cout << "\t | 1 | |     Busqueda por Codigo del Juego     |" << endl;
        cout << "\t | 2 | |     Busqueda por Nombre del Juego     |" << endl;
        cout << "\t | 3 | |   Busqueda por Nommbre de la Consola  |" << endl;
        cout << "\t | 4 | |        Volver al Menu Principal       |" << endl;
        cout << "\t |   | |                                       |" << endl;
        cout << "\t +---------------------------------------------+\n" << endl;
        cout << " Digite su opcion: "; cin >> opc; cin.ignore();
        switch(opc){
            case 1:
                buscarCodigo(); getch();
                break;
            case 2:
                buscarNombre(); getch();
                break;
            case 3:
                buscarConsola(); getch();
                break;
            case 4:
                break;
            default:
                system("color 0C");
                cout << "\n\t No es una opcion valida" << endl; getch();
        }
    }while(opc!=4);
}

//Función para buscar un videojuego en la lista, mediante el dato del código.
void buscarCodigo(){
    //Variables a utilizar.
    int codigo=0;
    bool encontrado=false;
    system("cls"); system("color 01");
    cout << "\n\t*******************************************************" << endl;
    cout << "\t*********** BUSCAR VIDEOJUEGO POR EL CODIGO ***********" << endl;
    cout << "\t*******************************************************\n" << endl;
    cout << " Digite el codigo del videojuego a buscar:        \t" ; cin >> codigo; cin.ignore();
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    if(pInicio!=NULL){//Condicional para verificar si la lista tiene nodos.
        while(pRecorrido!=NULL){//Mientras no este en el ultimo nodo de la lista.
            if(pRecorrido->codigo == codigo){//Condicional para comparar el codigo ingresado, en la lista.
                system("color 0A");
                cout << "\n\t Registro encontrado!\n" << endl;
                cout << " Codigo:           \t" << pRecorrido->codigo << endl;
                cout << " Juego:            \t" << pRecorrido->nombre << endl;
                cout << " Consola:          \t" << pRecorrido->consola << endl;
                cout << " Genero:           \t" << pRecorrido->genero << endl;
                cout << " Clasificación:    \t" << pRecorrido->clasificacion << endl;
                cout << " Desarrolladores:  \t" << pRecorrido->desarrolladores << endl;
                cout << " Estado:           \t" << pRecorrido->estado << endl;
                cout << " Idioma:           \t" << pRecorrido->idioma << endl;
                cout << " Cantidad:         \t" << pRecorrido->cantidad << endl;
                cout << " Precio:           \t" << pRecorrido->precio << endl;
                encontrado=true;
            }else{}
            pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
        }
        if(encontrado==false){//Condicional por si no se encuentra el codigo ingresado.
            system("color 04");
            cout << "\n El codigo que ingreso, ( " << codigo << " )." << endl;
            cout << " No pertenece a ningun videojuego de la lista." << endl;
        }else{}
    }else{
        system("color 04");
        cout << " \n\n\t\t La lista esta vacia." << endl;
    }
}

//Función para buscar un videojuego en la lista, mediante el nombre del mismo.
void buscarNombre(){
    system("cls");system("color 01");
    char c1=' ';string r = "_", nombre;//Varibles para modificar los "_" por " ".
    char name[50];
    bool encontrado=false;
    cout << "\n\t*******************************************************" << endl;
    cout << "\t*********** BUSCAR VIDEOJUEGO POR EL NOMBRE ***********" << endl;
    cout << "\t*******************************************************\n" << endl;
    cout << " Digite el nombre del videojuego a buscar:        \t" ; getline(cin, nombre);
    for(int i = 0; i < (int)nombre.length(); ++i){//Iniciando el cambio de caracteres Entrada...
        if(nombre[i]==c1)    //Condicional para cambio de caracter.
            nombre.replace(i,1,r);   //Cambio de caracater.
    }//Fin del cambio
    strcpy(name,nombre.c_str());
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    if(pInicio!=NULL){//Condicional para verificar si la lista tiene nodos.
        while(pRecorrido!=NULL){//Mientras no este en el ultimo nodo de la lista.
            if(strcmp(pRecorrido->nombre, name)==0){//Condicional para comparar el nombre ingresado, en la lista.
                system("color 0A");
                cout << "\n\t Registro encontrado!\n" << endl;
                cout << " Juego:            \t" << pRecorrido->nombre << endl;
                cout << " Codigo:           \t" << pRecorrido->codigo << endl;
                cout << " Consola:          \t" << pRecorrido->consola << endl;
                cout << " Genero:           \t" << pRecorrido->genero << endl;
                cout << " Clasificación:    \t" << pRecorrido->clasificacion << endl;
                cout << " Desarrolladores:  \t" << pRecorrido->desarrolladores << endl;
                cout << " Estado:           \t" << pRecorrido->estado << endl;
                cout << " Idioma:           \t" << pRecorrido->idioma << endl;
                cout << " Cantidad:         \t" << pRecorrido->cantidad << endl;
                cout << " Precio:           \t" << pRecorrido->precio << endl;
                encontrado=true;
            }else{}
            pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
        }
        if(encontrado==false){//Condicional por si no se encuentra el codigo ingresado.
            system("color 04");
            cout << "\n El nombre que ingreso, ( " << nombre << " )." << endl;
            cout << " No pertenece a ningun videojuego de la lista." << endl;
        }else{}
    }else{
        system("color 04");
        cout << " \n\n\t\t La lista esta vacia." << endl;
    }
}

//Función para buscar un videojuego en la lista, mediante el nombre de la consola.
void buscarConsola(){
    system("cls");system("color 01");
    char c1=' ';string r = "_", nombre;//Varibles para modificar los "_" por " ".
    char name[50];
    bool encontrado=false;
    cout << "\n\t*******************************************************" << endl;
    cout << "\t******* BUSCAR VIDEOJUEGO POR NOMBRE DE CONSOLA *******" << endl;
    cout << "\t*******************************************************\n" << endl;
    cout << " Digite el nombre de la consola a buscar:        \t" ; getline(cin, nombre);
    for(int i = 0; i < (int)nombre.length(); ++i){//Iniciando el cambio de caracteres Entrada...
        if(nombre[i]==c1)    //Condicional para cambio de caracter.
            nombre.replace(i,1,r);   //Cambio de caracater.
    }//Fin del cambio
    strcpy(name,nombre.c_str());
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    if(pInicio!=NULL){//Condicional para verificar si la lista tiene nodos.
        while(pRecorrido!=NULL){//Mientras no este en el ultimo nodo de la lista.
            if(strcmp(pRecorrido->consola, name)==0){//Condicional para comparar el nombre ingresado, en la lista.
                system("color 0A");
                cout << "\n\t Registro encontrado!\n" << endl;
                cout << " Consola:          \t" << pRecorrido->consola << endl;
                cout << " Codigo:           \t" << pRecorrido->codigo << endl;
                cout << " Juego:            \t" << pRecorrido->nombre << endl;
                cout << " Genero:           \t" << pRecorrido->genero << endl;
                cout << " Clasificación:    \t" << pRecorrido->clasificacion << endl;
                cout << " Desarrolladores:  \t" << pRecorrido->desarrolladores << endl;
                cout << " Estado:           \t" << pRecorrido->estado << endl;
                cout << " Idioma:           \t" << pRecorrido->idioma << endl;
                cout << " Cantidad:         \t" << pRecorrido->cantidad << endl;
                cout << " Precio:           \t" << pRecorrido->precio << endl;
                encontrado=true;
            }else{}
            pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
        }
        if(encontrado==false){//Condicional por si no se encuentra el codigo ingresado.
            system("color 04");
            cout << "\n El nombre que ingreso, ( " << nombre << " )." << endl;
            cout << " No pertenece a ningun videojuego de la lista." << endl;
        }else{}
    }else{
        system("color 04");
        cout << " \n\n\t\t La lista esta vacia." << endl;
    }
}

//Función para actualizar la cantidad que se tiene registrada del videojuego solitado por medio de su código.
void editarCantidad(){
    //Variables a utilizar.
    int codigo=0;
    bool encontrado=false;
    system("cls"); system("color 01");
    cout << "\n\t*******************************************************" << endl;
    cout << "\t************* EDITAR CANTIDAD DEL VIDEJUEGO ***********" << endl;
    cout << "\t*******************************************************\n" << endl;
    cout << " Digite el codigo del videojuego a buscar:        \t" ; cin >> codigo; cin.ignore();
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    if(pInicio!=NULL){//Condicional para verificar si la lista tiene nodos.
        while(pRecorrido!=NULL){//Mientras no este en el ultimo nodo de la lista.
            if(pRecorrido->codigo == codigo){//Condicional para comparar el codigo ingresado, en la lista.
                system("color 0A"); cout << "\n\t Registro encontrado!\n" << endl;
                cout << " Codigo:           \t" << pRecorrido->codigo << endl;
                cout << " Juego:            \t" << pRecorrido->nombre << endl;
                cout << " Consola:          \t" << pRecorrido->consola << endl;
                cout << " Cantidad:         \t" << pRecorrido->cantidad << endl;
                cout << " Precio:           \t" << pRecorrido->precio << endl;
                system("color 01"); cout << "\n\n\t Modificar cantidad de " << pRecorrido->nombre << "." << endl;
                cout << " Ingrese nueva cantidad:       \t"; cin >> pRecorrido->cantidad; cin.ignore();//Editar la nueva cantidad del videojuego.
                system("color 0A"); cout << "\n\t Modificación Realizada!\n" << endl;
                cout << " Codigo:           \t" << pRecorrido->codigo << endl;
                cout << " Juego:            \t" << pRecorrido->nombre << endl;
                cout << " Consola:          \t" << pRecorrido->consola << endl;
                cout << " Cantidad:         \t" << pRecorrido->cantidad << endl;
                cout << " Precio:           \t" << pRecorrido->precio << endl;
                encontrado=true;
            }else{}
            pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
        }
        if(encontrado==false){//Condicional por si no se encuentra el codigo ingresado.
            system("color 04");
            cout << "\n El codigo que ingreso, ( " << codigo << " )." << endl;
            cout << " No pertenece a ningun videojuego de la lista." << endl;
        }else{
            descargarLista(escritura);//Guarda la nueva lista, con el registro modificado incluido en el txt.
        }
    }else{
        system("color 04");
        cout << " \n\n\t\t La lista esta vacia." << endl;
    }
}

//Función para imprimir en pantalla todos los registros de la lista, en un tabla con columnas(titulos) y filas(datos del videojuego).
void reporte(){
    system("cls"); system("color 06");
    int i=5;
    gotoxy(2,2); cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+";
    gotoxy(2,3); cout << "| CODIGO ";
    gotoxy(11,3); cout << "||\t\t     JUEGO ";
    gotoxy(51,3); cout << "||\t  CONSOLA  ";
    gotoxy(69,3); cout << "||\t    GENERO";
    gotoxy(87,3); cout << "||  CLASIFICACION ";
    gotoxy(107,3); cout << "|| DESARROLLADORES";
    gotoxy(127,3); cout << "||   ESTADO  ";
    gotoxy(141,3); cout << "||  IDIOMA ";
    gotoxy(153,3); cout << "|| CANTIDAD ";
    gotoxy(165,3); cout << "|| PRECIO |";
    gotoxy(2,4); cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+";
    pRecorrido = pInicio;//Igualar punteros para empezar el recorrido desde el inico de la lista.
    while(pRecorrido != NULL){//Mientras no este en el ultimo nodo de la lista.
        gotoxy(2,i); cout << "|   " << pRecorrido->codigo;
        gotoxy(11,i); cout << "|| " << pRecorrido->nombre;
        gotoxy(51,i); cout << "|| " << pRecorrido->consola;
        gotoxy(69,i); cout << "|| " << pRecorrido->genero;
        gotoxy(87,i); cout << "||        " << pRecorrido->clasificacion;
        gotoxy(107,i); cout << "|| " << pRecorrido->desarrolladores;
        gotoxy(127,i); cout << "|| " << pRecorrido->estado;
        gotoxy(141,i); cout << "|| " << pRecorrido->idioma;
        gotoxy(153,i); cout << "||    " << pRecorrido->cantidad;
        gotoxy(165,i); cout << "|| Q." << pRecorrido->precio;
        gotoxy(175,i); cout << "|";
        i++;
        pRecorrido = pRecorrido->pSig;//Salto al siguiente nodo.
    }
    cout << "\n  +----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    //cout << " NULL" << endl;
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
