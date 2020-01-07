 #include <iostream>
 #include <fstream>

using namespace std;

const int tamano = 100;

void ingreso_datos(int a[], int b);
void buscar_elemento(int a[], int b);


int dato,n;

int main()
{
    setlocale(LC_CTYPE,"Spanish");

    int arreglo[tamano];

    cout << "ingrese el tamaño: " << endl;
    cin >> n;
    cout << "ingrese el elemento a buscar: " << endl;
    cin >> dato;

    ingreso_datos(arreglo,n);
    cout << endl;
    buscar_elemento(arreglo,n);
    cout << endl;
    return 0;
}
void ingreso_datos(int a[], int b)
{

    for(int i = 0; i < b; i++)
    {
    cout << "ingrese el elemento" << endl;
    cin >> a[i];
    }
    for(int i = 0; i < b; i++)
    {
    cout << a[i] << " ";
    }
}

void buscar_elemento(int a[], int b)
{
    bool c = false;
    ofstream archivo;
    string nombre;
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombre;
    getline(cin,nombre);
    archivo.open(nombre.c_str(), ios::out);
    for (int i = 0; i < b; i++)
    {
        if(a[i] == dato)
        {
            cout << "Elemento encontrado"<< endl;
            cout << "posicion:" << i + 1 ;
            archivo << "Elemento encontrado" << endl;
            archivo << "posicion: " << i + 1 << endl;
            c = true;
        }
    }
    if(c == false)
    {
        cout <<"error";
        archivo << "error" << endl;
    }

     archivo << "Los elementos del arreglo son: ";
for (int i = 0; i < n; i++)
    {
        cout << " " << a[i] << " ";
     archivo<<" " << a[i] << " ";
    }
}

