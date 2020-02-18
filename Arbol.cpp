#include <iostream>
using namespace std;

//PLANTILLA DEL NODO
struct Nodo
{
    int dato;
    Nodo *derecho;  //punteo derecho
    Nodo *izquierdo;    //puntero izquierdo
};

//NODOS LISTOS PARA SER INSERTADOS EN EL ARBOL
Nodo *crearNodoPadresHijos (int n);

//ARBOL LISTO PARA SER USADO
Nodo *arbolBinario = NULL;

void insertarNodosEnArbolBinario(Nodo *&arbolBinario, int n);   //funcion para insertar los nodos en el arbol

void mostrarArbolBinario(Nodo *arbolBinario, int separador);

//RECORRIDO PREORDEN  //R-I-D
void preOrden(Nodo*&arbolBinario);
//RECORRIDO INORDEN  //I-R-D
void inOrden(Nodo*&arbolBinario);
//RECORRIDO POSORDEN  //I-D-R
void posOrden(Nodo*&arbolBinario);

int main()
{
    int n;
     cout << "INSERTAR NODOS"<<endl;
    for (int i = 0; i < 9; i++)
    {
        cout<<i+1<<") ";
        cin >> n;
        insertarNodosEnArbolBinario(arbolBinario, n);
    }
    cout<<endl<<"ARBOL:"<<endl;
    mostrarArbolBinario(arbolBinario, 0);
    cout<<"RECORRIDO PREORDEN:"<<endl;
    preOrden(arbolBinario);
    cout<<endl;
    cout<<"RECORRIDO INORDEN:"<<endl;
    inOrden(arbolBinario);
    cout<<endl;
    cout<<"RECORRIDO POSORDEN:"<<endl;
    posOrden(arbolBinario);
    cout<<endl;
    return 0;
}

Nodo *crearNodoPadresHijos (int n)  //funcion de tipo nodo, porque retorna un nodo "nuevo"
{
    //INICIALIZAR EL ARBOL CON LOS NODOS
    Nodo *nuevo = new Nodo();   //PLANTILLA BAUTIZADA COMO "nuevo"
    //ASIGNAR LOS VALORES AL NODO CREADO (
    nuevo -> dato = n;
    nuevo -> derecho = NULL;
    nuevo -> izquierdo = NULL;

    return nuevo;
}

void insertarNodosEnArbolBinario(Nodo *&arbolBinario, int n)
{
    if(arbolBinario == NULL)
    {
        Nodo *nuevo = crearNodoPadresHijos(n);
        arbolBinario = nuevo;
    }
    else
    {
        //INSERTAR NODO RAIZ
        int datoRaiz = arbolBinario -> dato;
        if(n < datoRaiz)
        {
            //INSERTA EL SIGUIENTE NODO EN EL SUB-IZQUIERDO
            insertarNodosEnArbolBinario(arbolBinario -> izquierdo, n);
        }
        else
        {
            //INSERTA EL SIGUIENTE NODO EN EL SUB-DERECHO
            insertarNodosEnArbolBinario(arbolBinario -> derecho, n);
        }
    }
}

void mostrarArbolBinario(Nodo *arbolBinario, int separador)
{
    if(arbolBinario == NULL)  //si el arbol esta vacio, no hara nada
    {
        return;
    }
    else
    {
        mostrarArbolBinario(arbolBinario -> derecho, separador + 1);
        for (int i = 0; i < separador; i++)
        {
            cout << " ";
        }
        cout << arbolBinario -> dato << endl;
        mostrarArbolBinario(arbolBinario -> izquierdo,separador + 1);
    }
}

void preOrden(Nodo*&arbolBinario)
{
    if(arbolBinario==NULL)
    {
        return;
    }
    else
    {
            //R
            cout<<arbolBinario->dato<<" ";
            //I
            preOrden(arbolBinario->izquierdo);
            //D
            preOrden(arbolBinario->derecho);
    }
}

void inOrden(Nodo*&arbolBinario)
{
    if(arbolBinario==NULL)
    {
        return;
    }
    else
    {
            //I
            inOrden(arbolBinario->izquierdo);
            //R
            cout<<arbolBinario->dato<<" ";
            //D
            inOrden(arbolBinario->derecho);

    }
}

void posOrden(Nodo*&arbolBinario)
{
    if(arbolBinario==NULL)
    {
        return;
    }
    else
    {
            //I
            posOrden(arbolBinario->izquierdo);
            //D
            posOrden(arbolBinario->derecho);
            //R
            cout<<arbolBinario->dato<<" ";
    }
}


