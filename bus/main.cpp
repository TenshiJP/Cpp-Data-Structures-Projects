/*
    ******************DATOS******************
    - Nombre: Angel Roberto Jacinto Payes
    - Carnet: 5990-20-1756
    - Curso:  Programación III
    - IDE:    CodeBlocks
    *****************************************
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
///Funciones utilizadas
int Menu();
void Reservar(int sillones []);
void Liberar(int sillones []);
void Verificar(int sillones []);
void BusVista();

int main()
{
    ///Declaracion de varibles
    int opcion, sillones[24];
    /*Número 1 lo identifica como sillon "libre" y número cero como sillon "ocupado"*/
    for (int i=1; i<25; i++){   //Ciclo for para colocar libres los sillones con un no. par y colocar ocupados los sillones con no. impar.
        if(i%2==0) //Condicional para verificar los sillones ocupados por protocolos de salud.
            sillones[i]=1; //Sillones libres.
        else
            sillones[i]=0; //Sillones ocupados.
    }

    ///Menu de opciones
    do {    //Menú con ciclo Do-While para realizar toda las opciones que deseemos las veces que queramos.
        system("cls");system("color 0A");/*color de fondo y fuente*/BusVista();
        cout << "\n\t.---------------------------." << endl;
        cout << "\t|      Buses El Quetzal     |" << endl;
        cout << "\t.---------------------------." << endl;
        cout << "\t| 1. | | Reservar  Asientos |" << endl;
        cout << "\t| 2. | |  Liberar Asientos  |" << endl;
        cout << "\t| 3. | | Verificar Asientos |" << endl;
        cout << "\t| 4. | |       Salir        |" << endl;
        cout << "\t.---------------------------.\n" << endl;
        cout << "\tIngrese una opcion: ";
        cin >> opcion;cin.ignore();
        switch (opcion) { //Switch para seleccionar la opcion que se desea ingresar.
            case 1:
                Reservar(sillones);system("pause>nul");//Pausa
                break;
            case 2:
                Liberar(sillones);system("pause>nul");//Pausa
                break;
            case 3:
                Verificar(sillones);system("pause>nul");//Pausa
                break;
            case 4:
                system("cls");system("color 4F");system("color 2F");system("color 01");system("color 0F");/*color de fondo y fuente*/cout << "\n\t Adios..." << endl;
                break;
        }
    } while (opcion!=4);
    return 0;
}

void BusVista(){        //Función que Imprime una ilustracion del diseño del bus con signos.
    cout << "\n\n\tILUSTRACION DEL BUS\n\tLinea -->  01  02  03  04  05  06  07  08  09  10  11  12  " << endl;
    cout << "\t.-------  .-----------------------------------------------." << endl;
    cout << "\t|         |02||  ||06||  ||10||  ||14||  ||18||  ||22||  ||" << endl;
    cout << "\t|Entrada  |01||  ||05||  ||09||  ||13||  ||17||  ||21||  ||" << endl;
    cout << "\t|                             Pasillo                     |" << endl;
    cout << "\t|-----  -.|03||  ||07||  ||11||  ||15||  ||19||  ||23||  ||" << endl;
    cout << "\t| Piloto ||04||  ||08||  ||12||  ||16||  ||20||  ||24||  ||" << endl;
    cout << "\t.------------------------------------------------ --------.\n" << endl;
}

void Reservar(int sillones []){     //Función para reservar asientos del bus.
    int sillon;
    do {    //Ciclo Do-While Para buscar el no. de sillon que desea reservar y verificar si esta disponible aún.
        system("cls");system("color 09");/*color de fondo y fuente*/cout << "\n\tRESERVAR ASIENTO\n" << endl;
        cout << " Ingrese el numero de sillon que desea reservar: ";
        cin >> sillon;cin.ignore();
        if(sillon%2!=0 && sillon>0 && sillon <25) //Condicional para sillones ocupados por protocolos de salud.
        {
            system("color CF");system("color 0C");/*color de fondo y fuente*/cout << "No se puede reservar el sillon " << sillon << " por protocolos de salud." << endl;system("pause>nul");
        }
    }while(sillon<1 || sillon%2!=0 || sillon>=25); //Condicion del ciclo.

    if(sillones[sillon] == 1){ //Condicional para reservar los sillones y mostrar el mensaje.
        sillones[sillon] = 0;
        if(sillon>0 && sillon<=4){
            cout << "\tLinea 1, sillon "<< sillon << " reservado." << endl;
        }else if(sillon>4 && sillon<=8){
            cout << "\tLinea 3, sillon "<< sillon << " reservado." << endl;
        }else if(sillon>8 && sillon<=12){
            cout << "\tLinea 5, sillon "<< sillon << " reservado." << endl;
        }else if(sillon>12 && sillon<=16){
            cout << "\tLinea 7, sillon "<< sillon << " reservado." << endl;
        }else if(sillon>16 && sillon<=20){
            cout << "\tLinea 9, sillon "<< sillon << " reservado." << endl;
        }else if(sillon>20 && sillon<=24){
            cout << "\tLinea 11, Sillon "<< sillon << " reservado." << endl;
        }//cout << "\tSillon "<< sillon << " reservado." << endl;
    }else{
        system("color CF");system("color 0C");/*color de fondo y fuente*/cout << "\tLo sentimos el sillon " << sillon << " esta ocupado." <<endl;
    }
}

void Liberar(int sillones []){      //Función para liberar asientos del bus.
    int sillon;
    do {     //Ciclo Do-While para buscar el sillon que se desea liberar.
        system("cls");system("color 0D");/*color de fondo y fuente*/cout << "\n\tLIBERAR ASIENTO\n" << endl;
        cout << " Ingrese el numero de sillon que desea liberar: ";
        cin >> sillon;cin.ignore();
        if(sillon%2!=0 && sillon>0 && sillon <25) //Condicional para sillones ocupados por protocolos de salud.
        {
            system("color CF");system("color 0C");/*color de fondo y fuente*/cout << "No se puede liberar el sillon " << sillon << " por protocolos de salud." << endl;system("pause>nul");
        }
    }while(sillon<1 || sillon%2!=0 || sillon>=25); //Condicion del ciclo.

    if(sillones[sillon] == 0){ //Condicional para liberar el sillon encontrado y mostrar mensaje.
        sillones[sillon] = 1;
        if(sillon>0 && sillon<=4){
            cout << "\tLinea 1 sillon "<< sillon << " libre." << endl;
        }else if(sillon>4 && sillon<=8){
            cout << "\tLinea 3 sillon "<< sillon << " libre." << endl;
        }else if(sillon>8 && sillon<=12){
            cout << "\tLinea 5 sillon "<< sillon << " libre." << endl;
        }else if(sillon>12 && sillon<=16){
            cout << "\tLinea 7 sillon "<< sillon << " libre." << endl;
        }else if(sillon>16 && sillon<=20){
            cout << "\tLinea 9 sillon "<< sillon << " libre." << endl;
        }else if(sillon>20 && sillon<=24){
            cout << "\tLinea 11 Sillon "<< sillon << " libre." << endl;
        }//cout << "\tSillon "<< sillon << " libre." << endl;
    }else{
        system("color DF");system("color 0D");/*color de fondo y fuente*/cout << "\tEl sillon " << sillon << " ya se encuentra libre." <<endl;
    }
}

void Verificar(int sillones []){        //Funnción para verificar asientos del bus.
    system("cls");system("color 0E");/*color de fondo y fuente*/cout << "\tVERIFICAR ASIENTO\n" << endl;
    int sLibre=0, total=0;  //Variables
    for (int i=1; i<5; i++){    //Ciclo for para fila 1.
        if (sillones[i] == 1){
            cout <<" "<<i;
            sLibre++;total++;
        }
    }
    cout << "\nLinea 1, disponible " << sLibre << " sillon(es).\n" <<endl;sLibre=0;//Mensaje y reset a 0 de variable sLibre.

    for (int i=5; i<9; i++){    //Ciclo for para fila 3.
        if (sillones[i] == 1){  //Condicional para contar sillones libres.
            cout <<" "<<i;
            sLibre++;total++;
        }
    }
    cout << "\nLinea 3, disponible " << sLibre << " sillon(es).\n" <<endl;sLibre=0;//Mensaje y reset a 0 de variable sLibre.

    for (int i=9; i<13; i++){    //Ciclo for para fila 5.
        if (sillones[i] == 1){   //Condicional para contar sillones libres.
            cout <<" "<<i;
            sLibre++;total++;
        }
    }
    cout << "\nLinea 5, disponible " << sLibre << " sillon(es).\n" <<endl;sLibre=0;//Mensaje y reset a 0 de variable sLibre.

    for (int i=13; i<17; i++){    //Ciclo for para fila 7.
        if (sillones[i] == 1){    //Condicional para contar sillones libres.
            cout <<" "<<i;
            sLibre++;total++;
        }
    }
    cout << "\nLinea 7, disponible " << sLibre << " sillon(es).\n" <<endl;sLibre=0;//Mensaje y reset a 0 de variable sLibre.

    for (int i=17; i<21; i++){    //Ciclo for para fila 9.
        if (sillones[i] == 1){    //Condicional para contar sillones libres.
            cout <<" "<<i;
            sLibre++;total++;
        }
    }
    cout << "\nLinea 9, disponible " << sLibre << " sillon(es).\n" <<endl;sLibre=0;//Mensaje y reset a 0 de variable sLibre.

    for (int i=21; i<25; i++){    //Ciclo for para fila 11.
        if (sillones[i] == 1){    //Condicional para contar sillones libres.
            cout <<" "<<i;
            sLibre++;total++;
        }
    }
    cout << "\nLinea 11, disponible " << sLibre << " sillon(es).\n" <<endl;sLibre=0;//Mensaje y reset a 0 de variable sLibre.
    system("color EF");system("color 0E");/*color de fondo y fuente*/cout << "\tSe encuentran " << total << " sillones libres en todo el bus.";//Mensaje
}
