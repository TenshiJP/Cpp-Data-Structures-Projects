/*
    Nombre:     Angel Roberto Jacinto Payes
    No.Carnet:  5990-20-1756
    Curso:      Programación III - Estructura de Datos
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;
//Funciones utilizadas
void Agregar();
void Verificar();
void Atender();
void AgregarPrioridad();

//Declaración de Valores
int cola[12];   //Tamaño de la cola.
int frenteCola, finalCola, opcion=0, opc=0;

int main()
{
    frenteCola=-1; finalCola=-1;
    do{
        system("cls");
        cout << "\n\t\tBANCO GUATEMALTECO\n" << endl;
        cout << "\t | 1 |  INGRESO DE CLIENTES A LA COLA" << endl;
        cout << "\t | 2 |  ATENDER CLIENTE" << endl;
        cout << "\t | 3 |  SALIR" << endl;
        cout << "\t Nota: La cola es de 12 espacios.\n" <<endl;
        cout << "\t Proporcione su opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                do {
                    system("cls");cout << "\n\tINGRESO DE CLIENTES A LA COLA\n" << endl;
                    cout << " | 1 |  INGRESO A LA COLA (NORMAL)" << endl;
                    cout << " | 2 |  INGRESO A LA COLA CON PRIORIDAD" << endl;
                    cout << " | 3 |  REGRESAR AL MENU PRINCIPAL\n" << endl;
                    cout << " Proporcione su opcion: ";
                    cin >> opc;
                    switch(opc){
                        case 1:
                            Agregar();
                            break;
                        case 2:
                            AgregarPrioridad();
                            break;
                        case 3:
                            break;
                    default:
                        cout << "\tError: Opcion no disponible" << endl;getch();
                    }
                }while(opc!=3);
                break;

            case 2:
                Atender();
                break;
            case 3:
                system("cls");cout << "\tAdios..." << endl;
                break;
            default:
                cout << "\tError: Opcion no disponible" << endl;getch();
        }

    }while(opcion!=3);
    return 0;
}

/*Función para agregar personas a la cola.*/
void Agregar(){
    system("cls");cout << "\n\t INGRESANDO CLIENTE A LA COLA\n" << endl;
    if(finalCola==11){  //Condicional para verificar el estado de cola.
        cout << "\tLo sentimos, la cola esta llena." << endl;
    }else{
        if(frenteCola==-1)  //Condicional para crear cola cuando no exista.
            frenteCola++;
        finalCola++;
        cout << "Adelante, su posicion es " << finalCola+1 << endl;
        cola[finalCola]=finalCola+1;
    }
    getch();
}

/*Función para agregar clientes con prioridad*/
void AgregarPrioridad(){
    system("cls");cout << "\n\t INGRESANDO CLIENTE CON PRIORIDAD\n" << endl;
    if(finalCola==11){
            Verificar();
            cout << "\n Cola llena, espere unos segundos y sera atendido." << endl;
            for(int i=frenteCola+1;i<=finalCola;i++){    //Ciclo para eliminar(atender) el primero de la cola.
                    cola[i-1]=cola[i];
            }
            cola[finalCola]=0;
            cout << "\n Se ha atendido al cliente del principio. Su espacio esta disponible." <<endl;
            cola[0]=1;
            for(int i=1;i<=finalCola;i++){   //Ciclo para correr la cola atras del cliente con prioridad.
                cola[i]=i;
            }
            Verificar();
    }else{
        Verificar();
        cout << "\n Su espacio esta disponible al inicio de la cola." <<endl;
        cola[0]=1;
        finalCola++;
        for(int i=finalCola;i>=frenteCola+1;i--){   //Ciclo para correr la cola atras del cliente con prioridad.
            cola[i]=i;
        }
        Verificar();
    }
    getch();
}

/*Función para ver los elementos en cola.*/
void Verificar(){
    cout << " Clientes en cola:";
    if(finalCola==-1){  //Condicional para verificar el estado de la cola.
        cout << " La cola esta vacia." << endl;
    }else{
        for(int i=frenteCola;i<=finalCola;i++){ //Ciclo para mostrar todos los posiciones ocupadas en la cola.
            cout << " " << cola[i] << ",";
        }
    }
}

/*Función para atender un cliente.*/
void Atender(){
    system("cls");cout << "\t ATENDER CLIENTES\n" << endl;
    if(finalCola==-1){  //Condicional para verificar el estado de la cola.
        cout << " La cola esta vacia." << endl;
    }else{
        Verificar();
        for(int i=frenteCola+1;i<=finalCola;i++)    //Ciclo para eliminar(atender) el primero de la cola.
            cola[i-1]=cola[i];
        cola[finalCola]=0;
        finalCola--;
        cout << "\n\n Se ha atendido al cliente del principio." <<endl;
        for(int i=0;i<=finalCola;i++){   //Ciclo para correr la cola.
            cola[i]=i+1;
        }
        Verificar();
    }
    getch();
}
