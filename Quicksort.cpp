#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int mitad(int a[], int pinicial, int pfinal);
void ordenar(int a[], int pinicial, int pfinal);


int main()
{
	int A[10] = { 123,-6,13,-33,-98,333,23,-5,0,-100 };
	ofstream archivo;
	string nombreA;
	cout << "Ingrese el nombre del archivo: ";
	getline(cin, nombreA);
	archivo.open(nombreA.c_str(), ios::out);

	cout << "Antes de ordenar: " << endl;
	archivo << "Antes de ordenar: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
		archivo << A[i] << " ";
	}

	ordenar(A, 0, 9);
	cout << endl;
	archivo << endl;
	cout << "Despues de ordenar: " << endl;
	archivo << "Despues de ordenar: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
		archivo << A[i] << " ";
	}
	archivo.close();


	return 0;
}

int mitad(int a[], int pinicial, int pfinal)
{
	return a[(pinicial + pfinal) / 2];

}

void ordenar(int a[], int pinicial, int pfinal)
{
	int i = pinicial;
	int j = pfinal;
	int temp;
	int piv = mitad(a, pinicial, pfinal);

	do
	{
		while (a[i] < piv)
		{
			i++;
		}

		while (a[j] > piv)
		{
			j--;
		}

		if (i <= j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);


	if (pinicial < j)
	{
		ordenar(a, pinicial, j);
	}

	if (i < pfinal)
	{
		ordenar(a, i, pfinal);
	}
}