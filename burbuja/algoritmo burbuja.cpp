#include <iostream>
using namespace std;

void ingresar(int a[], int n);
void burbuja(int a[], int n);
void imprimir(int a[], int n);

int main()
{
 int arreglo[5];
 ingresar(arreglo, 5);
 burbuja(arreglo, 5);
 imprimir(arreglo, 5);

 return 0;
}
void ingresar(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "elemento " << i << ": ";
        cin >> a[i];
    }
}
void burbuja(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if(a[i] > a[j])
            {
                int aux = a[i];
                a[i = a[j]];
                a[j] = aux;
            }
        }
    }
}
void imprimir(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i];
    }
}
