#include <iostream>
#include <vector>

using namespace std;

// vector<int>& v    (este es el apuntador o puntero que se dirige al vector principal)
void LlenarVector(vector<int>& v)
{
	int cant;
	cout << "\n Digite la cantidad de datos a ingresar al vector: ";
	cin >> cant;
	v.resize(cant);   // función nombrevector.resize cambiar el tamaño del vector v
	cout << "\n  *** Digite los datos a almacenar en el vector *** \n";
	for ( int i = 0; i < cant; i++ )
	{
		cout << "\n Dato No " << i + 1 << ": ";
		cin >> v[i];
	}
}

void MostrarVector(vector<int>& v)
{
	if (v.empty())
	{
		cout << "\n *** El vector principal esta vacio - Utilice la opcion No.1 del Menu *** \n";
	}
	else
	{
		cout << "\n  *** Datos almacenados en el vector *** \n";
		for ( int i = 0; i < v.size(); i++ )    // función nombrevector.size devolver el tamaño del vector v 
		{
			cout << "Dato No " << i + 1 << ": " << v[i] << endl;
		}
	}
}


void SumarVector(vector<int>& v)
{
	int suma = 0;
	if (v.empty())
	{
		cout << "\n *** El vector principal esta vacio - Utilice la opcion No.1 del Menu *** \n";
	}
	else
	{
		cout << "\n  *** Datos almacenados en el vector *** \n";
		for ( int i = 0; i < v.size(); i++ )    // función nombrevector.size devolver el tamaño del vector v 
		{
			cout << "Dato No " << i + 1 << ": " << v[i] << endl;
			suma = suma + v[i];
		}
		cout << "\n La suma de los datos del vector es igual a: " << suma << endl;
	}
	
}

void MayorMenor(vector<int>& v)
{
	if (v.empty())
	{
		cout << "\n *** El vector principal esta vacio - Utilice la opcion No.1 del Menu *** \n";
	}
	else
	{
		int mayor = v[0];    //  50   80    27     9         mayor = 80      menor = 9
		int menor = v[0];
		cout << "\n  *** Datos almacenados en el vector *** \n";
		for ( int i = 0; i < v.size(); i++ )    // función nombrevector.size devolver el tamaño del vector v 
		{
			cout << "Dato No " << i + 1 << ": " << v[i] << endl;
			if (v[i] > mayor )
			{
				mayor = v[i];
			}
			if (v[i] < menor)
			{
				menor = v[i];
			}
		}
		cout << "\n El dato mayor del vector es: " << mayor << endl;
		cout << " El dato menor del vector es: " << menor << endl;
	}
		
}




int main()
{
	int opcion;
	vector<int> vectorPrincipal;  // declaración de un vector con datos tipo integer
	
	do
	{
		cout << "\n *** MENU DE OPCIONES A EJECUTAR *** \n";
		cout << "         1.  Llenado de datos \n";
		cout << "         2.  Mostrar datos \n";
		cout << "         3.  Suma datos del vector  \n";
		cout << "         4.  Mayor y menor de los datos del vector  \n";
		cout << "         5.  Salir  \n";
		cout << "      Ingrese la opcion: ";
		cin >> opcion;
		
		switch (opcion)
		{
			case 1:
				system("cls");
				LlenarVector(vectorPrincipal);
				system("pause");
				break;
			case 2:
				MostrarVector(vectorPrincipal);
				system("pause");
				break;	
			case 3:
				SumarVector(vectorPrincipal);
				system("pause");
				break;	
			case 4:
				MayorMenor(vectorPrincipal);
				system("pause");
				break;		
			case 5:
				exit(EXIT_SUCCESS);
			default:
				cout << "\n Opcion Invalida \n";
				system("pause");	
				opcion = 1;
		}
		
		system("cls");
		
	}while(opcion < 5);
	
}


























