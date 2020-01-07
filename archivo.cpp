#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string contacto,nombre,apellido;
ofstream archivo;
int edad;

void ingresar_contactos();
void mostrar_contactos();
int menu();

int main()
{
	cout << "Ingrese el nombre del archivo(contactos.txt): " << endl;
	getline(cin, contacto);
	archivo.open(contacto.c_str(), ios::out);
	int opcion = menu();
	while (opcion != 0)
	{
		switch (opcion)
		{
		case 1:
		{
			ingresar_contactos();
			break;
		} 

		case 2:
		{
			mostrar_contactos();
			break;
		}

		}
		opcion = menu();
		cout << endl;
	}

}

void ingresar_contactos()
{
	string des;
	cin.ignore();
	do
	{
	cout << "Ingrese el nombre: " << endl;
	getline(cin, nombre);
	cout << "Ingrese el apellido: " << endl;
	getline(cin, apellido);
	cout << "Ingrese la edad: " << endl;
		cin >> edad;
		cout << endl;
		archivo << nombre << " " <<apellido << " " << edad << endl;
		cout << "Desea ingresar otro contacto (s/n): ";
		cin >> des;
		cin.ignore();
	} while (des == "s");
	archivo.close();
}


void mostrar_contactos()
{
	ifstream archivolec("contactos.txt");
	string texto;

	while (!archivolec.eof())
	{
		archivolec >> nombre >> apellido >> edad;
		if (!archivolec.eof())
		{
			getline(archivolec, texto);
			cout << "Nombre: " << nombre << endl;
			cout << "Apellido: " << apellido << endl;
			cout << "Edad: " << edad << endl;
			cout << endl;
		}
	}
	archivolec.close();
}

int menu()
{
	int op = -1;
	while (op < 0 || op > 2)
	{
		cout << "1.- Ingresar contactos" << endl;
		cout << "2.- Mostrar contactos" << endl;
		cout << "0.- Salir" << endl;
		cout << "Opcion: " << endl;
		cin >> op;
	}
	return op;
}