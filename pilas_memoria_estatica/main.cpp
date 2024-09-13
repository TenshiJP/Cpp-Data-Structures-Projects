#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;
//Funciones utlizadas.
void Push();
void Pop();
void Recorrer();
void gotoxy(int x, int y);

//Declaracion de valores.
int Pila[6];
int Inicio, Final, Tope, opcion=0;

//Función del menú principal.
int main()
{
    Tope=6;     //Cantidad máxima que se trabajará.
    Final=0;    //El vector iniciará en la posición 1, no se manejará el 0.
    do{
        system("cls");//clrscr();
        gotoxy(30,2); cout<<"*** Programa para Control de Pila ***"<<endl;
        cout << "\n\n 1. Ingresar Valores a la Pila (Push) " << endl;
        cout << " 2. Mostrar Datos de la Pila (Recorrido)" << endl;
        cout << " 3. Eliminar Valores de la Pila (Pop)" << endl;
        cout << " 4. Salir\n" << endl;
        cout << "\t Que opcion Desea Realizar: "; cin>>opcion;
        switch(opcion){
        case 1:
            Push();break;
        case 2:
            Recorrer();break;
        case 3:
            Pop();break;
        case 4:
            system("cls");break;
        default: "\n No es una opcion valida";
        }
        getch();
    }while(opcion!=4);
    return 0;
}

//Funcion para ingresar a la pila.
void Push(){
    system("cls");//clrsrc();
    if(Tope==Final)
    {
        cout<<" La pila se encuentra llena, ocasionara Desbordamiento" <<endl;
    }else{
        cout<<" Valor a ingresar a la pila: ";
        Final++;
        cin>>Inicio; //Pila[Final];
        Pila[Final] = Inicio;
        cout<<" Valor agregado en la pila en la posicion: "<< Final <<endl;
    }
}

//Función para sacar datos de la pila.
void Pop(){
    system("cls");//clrscr();
    if(Final==0){
        cout<<" La pila se encuentra vacia, no procede"<<endl;
    }else{
        cout<<" Eliminando de la pila el valor: "<<Pila[Final]<<". De la posicion en la pila: "<<Final  <<endl;
        Pila[Final]=0;
        Final--;
    }
}

//Funcion que recorre la pila y muestra en pantalla.
void Recorrer(){
    system("cls");//clrscr();
    if(Final==0){
        cout<<" La pila se encuentra vacia, no procede"<<endl;
    }else{
        for(int r=1; r<=Final; r++){
            cout<<" Posicion en la pila: "<<r<<", valor en posicion "<<Pila[r]<<endl;
        }
    }
    getch();
}

//Función gotoxy para desplazamiento de texto en una posicion de la consola.
void gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}
