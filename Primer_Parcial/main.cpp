/*
                    PRIMER PARCIAL
    Curso       : Programación III / Estructura de Datos
    Nombre      : Angel Roberto Jacinto Payes
    No. Carnet  : 5990-20-1756
*/
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>  //Librería para el manejo de archivos txt.

using namespace std;
///Funciones a utilizar.
void opcionesMenu();//Funcion para imprimir el menú principal.
void pushProducto(ifstream &lectura, ofstream &escritura);//Función para agregar datos al vector y luego al archivo txt.
void actualizarProducto(ifstream &lectura, ofstream &escritura);//Funcioón para actualizar la cantidad de un producto.
void popProducto(ifstream &lectura, ofstream &escritura);//
void mostrarInventario(ifstream &lectura);//Función para ver el inventario de la despensa en casa.

//Estructura para el manejo de datos de los articulos de la despensa.
struct producto{
    string nombreProducto;
    int cantidad;
};

//Declaración de variables.
producto viveres[15];//Vectores para guardar los productos disponibles en el hogar.
producto higiene[15];
ifstream lectura; ofstream escritura;//Variables para el manejo de archivos txt.
int Tope=15, Final=0, opc1;

int main()
{
    do{
        system("color 0F");system("cls");opcionesMenu();
        cout << "\tDigite su opcion: "; cin >> opc1; cin.ignore();
        switch(opc1){
        case 1:
            system("cls");
            pushProducto(lectura, escritura);
            break;

        case 2:
            system("cls");
            actualizarProducto(lectura, escritura);
            break;

        case 3:
            system("cls");
            popProducto(lectura, escritura);
            break;

        case 4:
            system("cls");
            mostrarInventario(lectura);
            break;

        case 5:
            system("cls");
            break;
        default:
            cout << "\tOpcion no dispinible." << endl;
        }
        getch();
    }while(opc1!=5);

    cout << " " << endl;
    return 0;
}

void pushProducto(ifstream &lectura, ofstream &escritura){  //Función para agregar datos al vector y luego al archivo txt.
    char *archivo;  //Variable para el nombre del archivo.txt
    char c = ' '; string reemplazo = "_";   //Varibles para modificar los " " por "_".
    int tipo=0;
    Final=0; //Actualizar varible para evitar problemas.
    cout << "\n\t *.*.*.*.*.* INGRESAR ARTICULOS *.*.*.*.*\n"<< endl;
    //Ciclo Do-While con condicional para seleccionar el archivo txt a ingresar.
    do{
        cout << " | 1 |     Viveres" << endl;
        cout << " | 2 |     Articulos de limpieza" << endl;
        cout << " Digite su opcion: "; cin >> tipo; cin.ignore();
        switch (tipo){
        case 1:
            archivo="viveres.txt";  //Nombre del archivo txt a utilizar.
            lectura.open(archivo,ios::in);  //Abre el archivo
            while(lectura.good()){ //Ciclo con condicinal, para calcular los saltos de linea del archivo txt.
                if(lectura.get()=='\n')
                    Final++;    //Actualiza la varible
            }
            break;
        case 2:
            archivo="higiene.txt";  //Nombre del archivo txt a utilizar.
            lectura.open(archivo,ios::in);  //Abre el archivo
            while(lectura.good()){ //Ciclo con condicinal, para calcular los saltos de linea del archivo txt.
                if(lectura.get()=='\n')
                    Final++;    //Actualiza la varible
            }
            break;
        }
    }while(tipo<1 || tipo>2); //cout << " Final: " << Final << endl;
    lectura.close();    //Cierra el archivo txt.
    //cout << " \t Final: " << Final <<endl;

    if(Tope==Final){
            system("cls"); system("color F4"); cout<<" Nota: Lo sentimos no se puede agregar, ocasionara Desbordamiento" <<endl;
    }else{
        escritura.open(archivo,ios::out | ios::app);//Abre el archivo.txt (si no existe lo crea y luego abre).
        if(escritura.fail()){   //Condicional por si falla al abrir el archivo.
            system("cls");system("color F4");cout << "\n Error: No se pudo abrir el archivo" <<endl;
            exit(1);
        }
        if(tipo==1){
            cout << "\n Ingrese nombre del articulo: "; getline(cin,viveres[Final].nombreProducto);
            //cout << viveres[Final].nombreProducto;
            cout << " Ingrese la cantidad de " << viveres[Final].nombreProducto << ": "; cin >> viveres[Final].cantidad;
            system("color 09"); //cout << viveres[Final].cantidad;
            cout << "\n Registro Guardado \n "<< " Articulo: " << viveres[Final].nombreProducto <<
             ".\t Cantidad: " << viveres[Final].cantidad <<endl;

            for (int i = 0; i < (int)(viveres[Final].nombreProducto).length(); ++i){//Iniciando el cambio de caracteres para guardar...
                if(viveres[Final].nombreProducto[i]==c)    //Condicional para cambio de caracter.
                viveres[Final].nombreProducto.replace(i,1,reemplazo);   //Cambio de caracteres.
            }//Fin del cambio.
            escritura << viveres[Final].nombreProducto << " " << viveres[Final].cantidad << "\n";   //Escribe en documento de texto.
        }else{
            cout << "\n Ingrese nombre del articulo: "; getline(cin,higiene[Final].nombreProducto);
            cout << " Ingrese cantidad de " << higiene[Final].nombreProducto << ": "; cin >> higiene[Final].cantidad;
             system("color 09"); cout << "\n Registro Guardado \n "<< " Articulo: " << higiene[Final].nombreProducto <<
             ".\t Cantidad: " << higiene[Final].cantidad <<endl;

            for (int i = 0; i < (int)(higiene[Final].nombreProducto).length(); ++i){//Iniciando el cambio de caracteres...
                if(higiene[Final].nombreProducto[i]==c)    //Condicional para cambio de caracter.
                higiene[Final].nombreProducto.replace(i,1,reemplazo);   //Cambio de caracteres.
            }//Fin del cambio.
            escritura << higiene[Final].nombreProducto << " " << higiene[Final].cantidad << "\n";   //Escribe en documento de texto.
        }
        Final++;
    }
    escritura.close();  //Cierra el archivo.txt
}

void actualizarProducto(ifstream &lectura, ofstream &escritura){  //Funcioón para actualizar la cantidad de un producto.
    char *archivo;  //Variable para el nombre del archivo.txt
    char c = '_', c1=' ';string reemplazo = " ", r = "_", extra;    //Varibles para modificar los "_" por " ".
    bool encontrado = false;    //Variable para verificar el dato a buscar.
    producto articulo, articulo1, articulo2; //Variables para realizar los cambios.
    int tipo=0,j=1;
    Final=0; //Actualizar varible para evitar problemas.

    //Ciclo Do-While con condicional para seleccionar el archivo txt a leer.
    cout << "\n\t *.*.*.*.*.* ACTUALIZAR ARTICULO *.*.*.*.*\n"<< endl;
    do{
        cout << " | 1 |     Viveres" << endl;
        cout << " | 2 |     Articulos de limpieza" << endl;
        cout << " Digite su opcion: "; cin >> tipo; cin.ignore();
        switch (tipo){
        case 1:
            archivo="viveres.txt";  //Nombre del archivo txt a utilizar.
            cout << "\n\t VIVERES EN LA DESPENSA\n" << endl;
            break;
        case 2:
            archivo="higiene.txt";  //Nombre del archivo txt a utilizar.
            cout << "\n\t ARTICULOS DE LIMPIEZA EN LA DESPENSA\n " << endl;
            break;
        }
    }while(tipo<1 || tipo>2);

    lectura.open(archivo,ios::in); escritura.open("temporal.txt",ios::out); //Abre archivos txt.
    if(lectura.is_open()){     //Condicinal si no abre el txt.
        cout << " Producto a modificar cantidad " << "\n Ingrese el nombre completo : ";    //Articulo a modificar su cantidad.
        getline(cin,extra);cout<<endl;
        for (int i = 0; i < (int)extra.length(); ++i)//Iniciando el cambio de caracteres Entrada...
        {
            if(extra[i]==c1)    //Condicional para cambio de caracter.
                extra.replace(i,1,r);   //Cambio de caracater.
        }//Fin del cambio
        lectura >> articulo.nombreProducto;
        while(!lectura.eof()){  //Mientras no sea el final.
            lectura >> articulo.cantidad;
            if(articulo.nombreProducto==extra){    //Condicion para comparar con todos los datos del archivo txt y editar el solicitado.
                articulo1.cantidad=articulo.cantidad;   //Igualar para cambiar caracteres en la salida.
                articulo1.nombreProducto=articulo.nombreProducto;
                for (int i = 0; i < (int)articulo1.nombreProducto.length(); ++i)//Iniciando el cambio de caracteres Salida...
                {
                    if(articulo1.nombreProducto[i]==c)    //Condicional para cambio de caracter.
                        articulo1.nombreProducto.replace(i,1,reemplazo);    //Cambio de caracteres.
                }//Fin del cambio.
                system("color 0A");cout <<  "\n Buscando Registros en el archivo..." <<endl; getch(); cout << " Registro Encontrado \n" <<endl;
                cout << " Articulo: " << articulo1.nombreProducto << ".\t Cantidad: " << articulo1.cantidad << endl;
                encontrado=true;system("color 0F");
                cout <<  "\n A continuacion se empezara a editar..." <<endl;
                articulo2.nombreProducto = extra;
                cout << "Digite nuevo cantidad: "; cin >> articulo2.cantidad;  system("color 09");
                cout <<  "\n Realizando los Cambios..." <<endl; getch(); cout << " Registro Modificado" <<endl;
                cout << " Articulo: " << articulo1.nombreProducto << ".\t Cantidad: " << articulo2.cantidad << endl;
                escritura << articulo2.nombreProducto << " " << articulo2.cantidad << "\n";     //Escribe los datos nuevos en nuevo archivo txt.
            }else{
                escritura << articulo.nombreProducto << " " << articulo.cantidad << "\n";     //Escribe los datos en nuevo archivo txt.
            }
            lectura >> articulo.nombreProducto;
        }
        lectura.close(); escritura.close(); //Cierra archivos txt.
        remove(archivo);   //Elimina el archivo txt.
        rename("temporal.txt",archivo);//Renombra el archivo txt.
    }else{
        system("cls"); system("color F4");cout << "\n\n\t Error: No se pudo abrir el archivo txt" << endl;
    }
    if(!encontrado)//Mensaje al no encontrar Dato en el archivo txt.
    {
        system("cls"); system("color 04");
        cout  << "\n\n***** " << extra << " ***** no encontrado...\n Es posible que halla escrito mal el nombre intente de nuevo." <<endl;
        cout << "Recuerde que debe ingresar el nombre completo para realizar la busqueda." <<endl;
    }
}

void popProducto(ifstream &lectura, ofstream &escritura){   //Función para eliminar datos en la pila.
    char *archivo;  //Variable para el nombre del archivo.txt
    char c = '_', c1=' ';string reemplazo = " ", r = "_", extra;   //Varibles para modificar los " " por "_" y viceversa.
    bool encontrado = false;    //Variable para verificar el dato a buscar.
    producto articulo, articulo1; //Variables para el proceso de eliminar.
    int tipo=0, opcion=0, j=1;
    Final=0;    //Actualizar variable para evitar errores.

    //Ciclo Do-While con condicional para seleccionar el archivo txt a leer.
    cout << "\n\t *.*.*.*.*.* ELIMINAR ARTICULO *.*.*.*.*\n"<< endl;
    do{
        cout << " | 1 |     Viveres" << endl;
        cout << " | 2 |     Articulos de limpieza" << endl;
        cout << " Digite su opcion: "; cin >> tipo; cin.ignore();
        switch (tipo){
        case 1:
            archivo="viveres.txt";  //Nombre del archivo txt a utilizar.
            cout << "\n\t VIVERES EN LA DESPENSA\n" << endl;
            lectura.open(archivo,ios::in);//Abre documento.txt en Lectura
            while(lectura.good()){ //Ciclo con condicinal, para calcular los saltos de linea del archivo txt.
                if(lectura.get()=='\n')
                    Final++;    //Actualiza la varible
            }
            break;
        case 2:
            archivo="higiene.txt";  //Nombre del archivo txt a utilizar.
            cout << "\n\t ARTICULOS DE LIMPIEZA EN LA DESPENSA\n " << endl;
            lectura.open(archivo,ios::in);//Abre documento.txt en Lectura
            while(lectura.good()){ //Ciclo con condicinal, para calcular los saltos de linea del archivo txt.
                if(lectura.get()=='\n')
                    Final++;    //Actualiza la varible
            }
            break;
        }
    }while(tipo<1 || tipo>2);//cout << " Final: " << Final << endl;
    lectura.close();    //Cierra el archivo txt.;

    do{
        cout << " | 1 | Eliminar el ultimo de la pila." << endl;
        cout << " | 2 | Eliminar por busqueda " << endl;
        cout << " Digite su opcion: "; cin >> opcion; cin.ignore();
        switch(opcion){
        case 1: //Eliinar el ultimo de la pila.
            encontrado=true;
            if(Final==0){
                 system("color F4"); cout<<"\t La pila se encuentra vacia, no hay articulos para eliminar..."<<endl;
            }else{
                // ***Inicio de carga de Datos.***
                lectura.open(archivo,ios::in);  //Abre documento.txt en Lectura
                if(lectura.fail())  //Condicional de error al no encontrar el archivo
                {
                    system("cls");system("color F4");cout << "\n\nError: No se pudo abrir el archivo" << endl;exit(1);
                }

                for(int j=1;j<=Final;j++){  //Condición para recorrer el archivo txt.
                    if(tipo==1){
                        lectura >> viveres[j-1].nombreProducto;
                        lectura >> viveres[j-1].cantidad; //Copia y guarda lo del archivo txt en el vector.
                         //cout << " Articulo: " << viveres[j-1].nombreProducto << ".\t Cantidad: " << viveres[j-1].cantidad <<endl;
                    }else{
                        lectura >> higiene[j-1].nombreProducto;
                        lectura >> higiene[j-1].cantidad;  //Copia y guarda lo del archivo txt en el vector.
                    }
                }
                lectura.close();// ***Fin carga de Datos.***

                //Eliminar el utlimo en la pila
                if(tipo==1){
                    system("color 04");
                    cout<<"\n Eliminando de la pila el articulo: "<<viveres[Final-1].nombreProducto<<".\t Cantidad: "<< viveres[Final-1].cantidad <<endl;
                    viveres[Final-1].nombreProducto=""; viveres[Final-1].cantidad=0; Final--; //Elimina articulo de la pila

                    //Guardando datos actuales a archivo txt.
                    escritura.open("temporal.txt",ios::out); //Abre archivos txt.
                    if(escritura.is_open()) {     //Condiconal si no abre el archivo txt.
                        for(int j=0; j<=Final-1; j++){  //Ciclo para recorrer el vector e ir guardando en el txt.
                            escritura << viveres[j].nombreProducto << " " << viveres[j].cantidad << "\n";   //Guarda datos en el archivo txt.
                        }
                    }else{
                        system("cls");system("color F4");cout << "\n\n\t Error: No se pudo abrir el archivo txt" << endl;
                    }   //Fin del Guardado.
                }else{
                    system("color 04");
                    cout<<"\n Eliminando de la pila el articulo: "<<higiene[Final-1].nombreProducto<<".\t Cantidad: "<< higiene[Final-1].cantidad <<endl;
                    higiene[Final-1].nombreProducto=""; higiene[Final-1].cantidad=0; Final--; //Elimina articulo de la pila

                    //Guardando datos actuales a archivo txt.
                    escritura.open("temporal.txt",ios::out); //Abre archivos txt.
                    if(escritura.is_open()) {     //Condiconal si no abre el archivo txt.
                        for(int j=0; j<=Final-1; j++){  //Ciclo para reccorrer el vector e ir guardando en en txt.
                            escritura <<higiene[j].nombreProducto << " " << higiene[j].cantidad << "\n";    //Escribe el archivo txt.
                        }
                    }else{
                        system("cls");system("color F4");cout << "\n\n\t Error: No se pudo abrir el archivo txt" << endl;
                    }   //Fin de
                }//cout << "\t TXT: " << archivo << endl;
                escritura.close(); //Cierra archivo txt.
                remove(archivo);   //Elimina el archivo txt.
                rename("temporal.txt",archivo);//Renombra el archivo txt.
                //cout << "\t Final: " << Final << endl;
            }
            break;

        case 2: //Eliminar por busqueda.
            lectura.open(archivo,ios::in);escritura.open("temporal.txt",ios::out);  //Abrir archivos txt, si no existe lo crea.
            if (lectura.is_open()){ //Condicional si no abre el archivo txt.
                cout << "\n Producto a Eliminar " << "\n Ingrese el nombre completo : ";    //Articulo a modificar su cantidad.
                getline(cin,extra);cout<<endl;
                for (int i = 0; i < (int)extra.length(); ++i)//Iniciando el cambio de caracteres Entrada...
                {
                    if(extra[i]==c1)    //Condicion de cambio de caracteres.
                        extra.replace(i,1,r);   //Cambio de caracteres.
                }//Fin del cambio
                lectura >> articulo.nombreProducto;
                while(!lectura.eof()){  //Mientras no sea el final.
                    lectura >> articulo.cantidad;
                    if(articulo.nombreProducto==extra){  //Condición para recorrer y comparar todo el archivo txt para eliminar el solicitado.
                        articulo1.cantidad=articulo.cantidad;   //Igualar para cambiar caracteres en la salida.
                        articulo1.nombreProducto=articulo.nombreProducto;
                        for(int i = 0; i < (int)articulo1.nombreProducto.length(); ++i)//Iniciando el cambio de caracteres Salida...
                        {
                            if(articulo1.nombreProducto[i]==c)    //Condicion de cambio de caracteres.
                                articulo1.nombreProducto.replace(i,1,reemplazo);   //Cambio de caracteres.
                        }//Fin del cambio.
                        system("color 0A");cout <<  "\n Buscando Registros en el archivo..." <<endl; getch(); cout << " Registro Encontrado \n" <<endl;
                        cout << " Articulo: " << articulo1.nombreProducto << ".\t Cantidad: " << articulo1.cantidad << endl;
                        encontrado=true; system("color 04");
                        cout <<  "\n\t Eliminando..." <<endl; getch(); cout << " Articulo Eliminado" <<endl;
                    }else{
                        escritura << articulo.nombreProducto << " " << articulo.cantidad << "\n";   //Escribe los datos en el archivo txt.
                    }
                    lectura >> articulo.nombreProducto;
                }
                lectura.close(); escritura.close();     //Cierra los archivos txt.
                remove(archivo);    //Elimina archivo txt.
                rename("temporal.txt", archivo);    //Renombrar el archivo txt.
            }else{
                system("cls");system("color F4");cout << "\n\n Error: No se pudo abrir el archivo" << endl;
            }
            if(!encontrado){    //Mensaje al no encontrar dato ingresado.
                system("cls");system("color F4");
                cout  << "\n\n***** " << extra << " ***** no encontrado...\n Es posible que halla escrito mal el nombre intente de nuevo." <<endl;
                cout << " Recuerde que debe ingresar el nombre completo para realizar la busqueda." <<endl;
            }
            break;
        }
    }while(opcion<1 || opcion >2);
}

void mostrarInventario(ifstream &lectura){  //Función para ver el inventario de la despensa en casa.
    char *archivo;  //Variable para el nombre del archivo.txt
    char c = '_'; string reemplazo = " ", extra;//Varibles para modificar los "_" por " ".
    int tipo=0;
    Final=0; //Actualizar varible para evitar errores en el vector.
    //Ciclo Do-While con condicional para seleccionar el archivo txt a leer.
    cout << "\n\t *.*.*.*.*.* VER INVENTARIOS *.*.*.*.*\n"<< endl;
    do{
        cout << " | 1 |     Viveres" << endl;
        cout << " | 2 |     Articulos de limpieza" << endl;
        cout << " Digite su opcion: "; cin >> tipo; cin.ignore();
        switch (tipo){
        case 1:
            archivo="viveres.txt";  //Nombre del archivo txt a utilizar.
            cout << "\n\t VIVERES EN LA DESPENSA\n" << endl;
            lectura.open(archivo,ios::in);//Abre documento.txt en Lectura
            while(lectura.good()){ //Ciclo con condicinal, para calcular los saltos de linea del archivo txt.
                if(lectura.get()=='\n')
                    Final++;    //Actualiza la varible
            }
            break;
        case 2:
            archivo="higiene.txt";  //Nombre del archivo txt a utilizar.
            cout << "\n\t ARTICULOS DE LIMPIEZA EN LA DESPENSA\n " << endl;
            lectura.open(archivo,ios::in);//Abre documento.txt en Lectura
            while(lectura.good()){ //Ciclo con condicinal, para calcular los saltos de linea del archivo txt.
                if(lectura.get()=='\n')
                    Final++;    //Actualiza la varible
            }
            break;
        }
    }while(tipo<1 || tipo>2); //cout << " \tFinal: " << Final << endl;
    lectura.close();    //Cierra el archivo txt.;

    if(Final==0){   //Condicional para verificar si la pila esta vacía.
         system("color 04"); cout<<"\t La pila se encuentra vacia, no hay articulos para mmostrar..."<<endl;
    }else{
        lectura.open(archivo,ios::in);  //Abre documento.txt en Lectura
        if(lectura.fail())  //Condicional de error al no encontrar el archivo
        {
            system("cls");system("color F4");cout << "\n\nError: No se pudo abrir el archivo" << endl;exit(1);
        }
        // *** Carga los datos del txt, a los vectores. ***
        //while(j<Final+1/* !lectura.eof() lectura.good()*/){  //Condición para recorrer el archivo txt e imprimirlo en pantalla.
        for(int j=1;j<=Final;j++){  //Recorre todo el archivo txt.
            if(tipo==1){
                lectura >> extra;
                for(int i = 0; i < (int)extra.length(); ++i)//Iniciando el cambio de caracteres Salida...
                {
                    if(extra[i]==c) //Condicional de cambio de caracteres.
                        extra.replace(i,1,reemplazo);   //Cambio de caracteres.
                }//Fin del cambio
                viveres[j-1].nombreProducto=extra;
                lectura >> viveres[j-1].cantidad; //Copia y guarda lo del archivo txt en el vector.
                 system("color 05");
                cout << " Articulo: " << viveres[j-1].nombreProducto << ".\t Cantidad: " << viveres[j-1].cantidad <<endl;
            }else{
                lectura >> extra;
                for(int i = 0; i < (int)extra.length(); ++i)//Iniciando el cambio de caracteres Salida...
                {
                    if(extra[i]==c) //Condicional de cambio de caracteres.
                        extra.replace(i,1,reemplazo);   //Cambio de caracteres.
                }//Fin del cambio
                higiene[j-1].nombreProducto=extra;
                lectura >> higiene[j-1].cantidad;  //Copia y guarda lo del archivo txt en el vector.
                system("color 05");
                cout << " Articulo: " << higiene[j-1].nombreProducto << ".\t Cantidad: " << higiene[j-1].cantidad <<endl;
            }
            //j++; cout << "\tJ: " << j << endl;
        }
    }
    lectura.close(); //Cierra el archivo txt.
}

void opcionesMenu(){    //Funcion para imprimir el menú principal.
    cout << "\n\t._____________________________. " << endl;
    cout << "\t|                              |" << endl;
    cout << "\t|      DESPENSA DEL HOGAR      |" << endl;
    cout << "\t|______________________________|" << endl;
    cout << "\t|    ||                        |" << endl;
    cout << "\t| 1. || AGREGAR PRODUCTOS      |" << endl;
    cout << "\t|____||________________________|" << endl;
    cout << "\t|    ||                        |" << endl;
    cout << "\t| 2. || ACTUALIZAR PRODUCTOS   |" << endl;
    cout << "\t|____||________________________|" << endl;
    cout << "\t|    ||                        |" << endl;
    cout << "\t| 3. || ELIMINAR PRODUCTOS     |" << endl;
    cout << "\t|____||________________________|" << endl;
    cout << "\t|    ||                        |" << endl;
    cout << "\t| 4. || MOSTRAR INVENTARIO     |" << endl;
    cout << "\t|____||________________________|" << endl;
    cout << "\t|    ||                        |" << endl;
    cout << "\t| 5. || SALIR                  |" << endl;
    cout << "\t|____||________________________|\n" << endl;
}
