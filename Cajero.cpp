#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int menu();
const int tamanio = 5;
typedef int tValores[tamanio];

int main()
{
	int op = -1, aux, i, j, impar = 0, par = 0;
	tValores dinero;
	cout << "*________Bienvenido________* " << endl;

	for (int i = 0; i < tamanio; i++)
	{
		cout << "ingrese el valor: ";
		cin >> dinero[i];
	}
	op = menu();
	while (op != 4)
	{
		switch (op)
		{
		case 1:
			for (i = 0; i < tamanio; i++)
			{
				for (j = i + 1; j < tamanio; j++)
				{
					if (dinero[j] < dinero[i])
					{
						aux = dinero[i];
						dinero[i] = dinero[j];
						dinero[j] = aux;
					}
				}

			}

			for (int i = 0; i < tamanio; i++)
			{
				cout << dinero[i];


			}
			cout << endl;
			break;
		case 2:
			for (i = 0; i < tamanio; i++)
			{
				for (j = i + 1; j < tamanio; j++)
				{
					if (dinero[j] > dinero[i])
					{
						aux = dinero[i];
						dinero[i] = dinero[j];
						dinero[j] = aux;
					}
				}

			}

			for (int i = 0; i < tamanio; i++)
			{
				cout << dinero[i];


			}
			cout << endl;
			break;
		case 3:
			for (int i = 0; i < tamanio; i++)
			{
				if (dinero[i] % 2 == 0)
				{
					par = par + dinero[i];
				}
				else if (dinero[i] % 2 != 0)
				{
					impar = impar + dinero[i];
				}
			}
			cout << "la suma de los pares es: " << par << endl;
			cout << "la suma de los impares es: " << impar << endl;

			break;
		}
		op = menu();
	}
	return 0;
}
int menu()
{
	int op = -1;
	while ((op < 0) || (op > 4))
	{
		cout << "1.- Mostrar los elementos ordenados de menor a mayor " << endl;
		cout << "2.- Mostrar los elementos ordenados de mayor a menor " << endl;
		cout << "3.- Mostar la suma de los elementos pares e impares del arreglo " << endl;
		cout << "4.- Salir " << endl;
		cout << "escoga opcion:";
		cin >> op;
		system("cls");
		if ((op < 0) && (op > 4))
		{
			cout << "Opcion no valida" << endl;
		}
	}
	return op;
}
