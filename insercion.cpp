#include <iostream>
using namespace std;

const int MAX = 100;
void ingresar(int a[], int n);
void ordenar(int a[], int n);
void imprimir(int a[], int n);

int main() {
	int arreglo[MAX];
	int m;
	cout << "Ingreses el tamano del arreglo: ";
	cin >> m;
	ingresar(arreglo, m);
	ordenar(arreglo, m);
	imprimir(arreglo, m);
	return 0;
}
void ingresar(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Ingrese el elemento " << i + 1 << endl;;
		cin >> a[i];
	}
}
void ordenar(int a[], int n) {
	int i, pos, aux;
	for (int i = 0; i < n; i++) {
		pos = i;
		aux = a[i];
		while ((pos > 0) && (a[pos - 1] > aux)) {
			a[pos] = a[pos - 1];
			pos--;
		}
		a[pos] = aux;
	}
}
void imprimir(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " " << a[i] << " ";
	}
}
