#include <iostream>
using namespace std;

void LlenarVector(int numeros[],int cant)
{
	cout << "\n  *** Digite los datos a almacenar en el vector *** \n";
	for ( int i = 0; i < cant; i++ )
	{
		cout << "\n Dato No " << i + 1 << ": ";
		cin >> numeros[i];
	}
}

void MostrarVector(int numeros[],int cant)
{
	cout << "\n  *** Datos almacenados en el vector *** \n";
	for ( int i = 0; i < cant; i++ )
	{
		cout << "Dato No " << i + 1 << ": " << numeros[i] << endl;
	}
}

void SumarVector(int numeros[],int cant)
{
	int suma = 0;
	cout << "\n  *** Datos almacenados en el vector *** \n";
	for ( int i = 0; i < cant; i++ )
	{
		cout << "Dato No " << i + 1 << ": " << numeros[i] << endl;
		suma = suma + numeros[i];
	}
	cout << "\n La suma de los datos del vector es igual a: " << suma << endl;
}

void MayorMenor(int numeros[],int cant)
{
	int mayor = numeros[0];    //  50   80    27     9         mayor = 80      menor = 9
	int menor = numeros[0];
	cout << "\n  *** Datos almacenados en el vector *** \n";
	for ( int i = 0; i < cant; i++ )
	{
		if (numeros[i] > mayor )
		{
			mayor = numeros[i];
		}
		if (numeros[i] < menor)
		{
			menor = numeros[i];
		}
		cout << "Dato No " << i + 1 << ": " << numeros[i] << endl;
	}
	cout << "\n El dato mayor del vector es: " << mayor << endl;
	cout << " El dato menor del vector es: " << menor << endl;
}

int main()
{
	int opcion, cant;
	int numeros[4];
	
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
				cout << "\n Digite la cantidad de datos a ingresar al vector: ";
				cin >> cant;
				LlenarVector(numeros,cant);
				system("pause");
				break;
			case 2:
				MostrarVector(numeros,cant);
				system("pause");
				break;	
			case 3:
				SumarVector(numeros,cant);
				system("pause");
				break;	
			case 4:
				MayorMenor(numeros,cant);
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
