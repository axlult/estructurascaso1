#include <iostream>
#include <cstdlib> 
using namespace std;


// Caso de estudio #1 Grupo #4 integrantes
// Axel Ulate Ulate
// Esteban Wu Zhen
//

const int MAX = 100; // Tamaño máximo del vector


void LlenarVector(int numeros[], int &cant);
void MostrarVector(int numeros[], int cant);
void Ord_Num_Asc(int numeros[], int cant);
void Ord_Num_Des(int numeros[], int cant);
void Primos(int numeros[], int cant);
void SumarPromAumentar(int numeros[], int cant);
void MostrarMayor(int numeros[], int cant);
void MostrarMenor(int numeros[], int cant);
void FusionarVectores(int numeros[], int &cant);

int main() {
    int opcion;
    int cant = 0; // Cantidad actual de elementos
    int numeros[MAX]; // Vector principal
    
    do {
        cout << "\n *** MENU DE OPCIONES A REALIZAR *** \n";
        cout << "         1. Llenar el Vector Principal \n";
        cout << "         2. Mostrar datos Vector Principal \n";
        cout << "         3. Ordenar Números Ascendentemente \n";
        cout << "         4. Ordenar Números Descendentemente \n";
        cout << "         5. Obtener Primos \n";
        cout << "         6. Sumar, promedio y aumentar \n";
        cout << "         7. Mostrar Dato Mayor \n";
        cout << "         8. Mostrar Dato Menor \n";
        cout << "         9. Fusión de Vectores \n";
        cout << "         10. Salir \n";
        cout << "      Ingrese la opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                LlenarVector(numeros, cant);
                break;
            case 2:
                MostrarVector(numeros, cant);
                break;
            case 3:
                Ord_Num_Asc(numeros, cant);
                break;
            case 4:
                Ord_Num_Des(numeros, cant);
                break;
            case 5:
                Primos(numeros, cant);
                break;
            case 6:
                SumarPromAumentar(numeros, cant);
                break;
            case 7:
                MostrarMayor(numeros, cant);
                break;
            case 8:
                MostrarMenor(numeros, cant);
                break;
            case 9:
                FusionarVectores(numeros, cant);
                break;
            case 10:
                cout << "\nSaliendo del programa...\n";
                exit(0);
            default:
                cout << "\nOpción Inválida!\n";
        }
        
        system("pause");
        system("cls");
        
    } while (opcion != 10);
    
    return 0;
}

void LlenarVector(int numeros[], int &cant) {
    cout << "\nCuantos numeros desea ingresar? (max " << MAX << "): ";
    cin >> cant;
    
    if (cant <= 0 || cant > MAX) {
        cout << "Cantidad invalida!\n";
        cant = 0;
        return;
    }
    
    cout << "\n*** Digite los datos ***\n";
    for (int i = 0; i < cant; i++) {
        cout << "Dato No " << i + 1 << ": ";
        cin >> numeros[i];
    }
    cout << "Vector llenado correctamente!\n";
}

void MostrarVector(int numeros[], int cant) {
    if (cant == 0) {
        cout << "El vector esta vacio! Use la opcion 1 primero.\n";
        return;
    }
    
    cout << "\n*** Datos del Vector Principal ***\n";
    for (int i = 0; i < cant; i++) {
        cout << numeros[i] << "  ";
    }
    cout << "\n";
}

void Ord_Num_Asc(int numeros[], int cant) {
    if (cant == 0) {
        cout << "El vector esta vacio! Use la opcion 1 primero.\n";
        return;
    }
    
    // Hacer copia para no modificar el original
    int copia[MAX];
    for (int i = 0; i < cant; i++) {
        copia[i] = numeros[i];
    }
    
    // Ordenamiento burbuja ascendente
    for (int i = 0; i < cant - 1; i++) {
        for (int j = 0; j < cant - i - 1; j++) {
            if (copia[j] > copia[j + 1]) {
                swap(copia[j], copia[j + 1]);
            }
        }
    }
    
    cout << "\n*** Datos Ordenados Ascendentemente ***\n";
    for (int i = 0; i < cant; i++) {
        cout << copia[i] << "  ";
    }
    cout << "\n";
}

void Ord_Num_Des(int numeros[], int cant) {
    if (cant == 0) {
        cout << "El vector esta vacio! Use la opcion 1 primero.\n";
        return;
    }
    
    // Hacer copia para no modificar el original
    int copia[MAX];
    for (int i = 0; i < cant; i++) {
        copia[i] = numeros[i];
    }
    
    // Ordenamiento burbuja descendente
    for (int i = 0; i < cant - 1; i++) {
        for (int j = 0; j < cant - i - 1; j++) {
            if (copia[j] < copia[j + 1]) {
                swap(copia[j], copia[j + 1]);
            }
        }
    }
    
    cout << "\n*** Datos Ordenados Descendentemente ***\n";
    for (int i = 0; i < cant; i++) {
        cout << copia[i] << "  ";
    }
    cout << "\n";
}

void Primos(int numeros[], int cant) {
    if (cant == 0) {
        cout << "El vector esta vacio! Use la opcion 1 primero.\n";
        return;
    }
    
    cout << "\n*** Verificacion de Numeros Primos ***\n";
    for (int i = 0; i < cant; i++) {
        bool esPrimo = true;
        
        if (numeros[i] <= 1) {
            esPrimo = false;
        } else {
            for (int j = 2; j * j <= numeros[i]; j++) {
                if (numeros[i] % j == 0) {
                    esPrimo = false;
                    break;
                }
            }
        }
        
        if (esPrimo) {
            cout << "El numero " << numeros[i] << " es primo\n";
        } else {
            cout << "El numero " << numeros[i] << " no es primo\n";
        }
    }
}

void SumarPromAumentar(int numeros[], int cant) {
    if (cant == 0) {
        cout << "El vector esta vacio! Use la opcion 1 primero.\n";
        return;
    }
    
    int suma = 0;
    for (int i = 0; i < cant; i++) {
        suma += numeros[i];
    }
    
    double promedio = static_cast<double>(suma) / cant;
    double sumaAumentada = suma * 1.7; // Suma + 70%
    
    cout << "\n*** Resultados de Calculos ***\n";
    cout << "Suma total: " << suma << "\n";
    cout << "Suma aumentada en 70%: " << sumaAumentada << "\n";
    cout << "Promedio: " << promedio << "\n";
}

void MostrarMayor(int numeros[], int cant) {
    if (cant == 0) {
        cout << "El vector esta vacio! Use la opcion 1 primero.\n";
        return;
    }
    
    int mayor = numeros[0];
    for (int i = 1; i < cant; i++) {
        if (numeros[i] > mayor) {
            mayor = numeros[i];
        }
    }
    
    cout << "\n*** Dato Mayor del Vector ***\n";
    cout << "El dato mayor es: " << mayor << "\n";
}

void MostrarMenor(int numeros[], int cant) {
    if (cant == 0) {
        cout << "El vector esta vacio! Use la opcion 1 primero.\n";
        return;
    }
    
    int menor = numeros[0];
    for (int i = 1; i < cant; i++) {
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }
    
    cout << "\n*** Dato Menor del Vector ***\n";
    cout << "El dato menor es: " << menor << "\n";
}

void FusionarVectores(int numeros[], int &cant) {
    if (cant == 0) {
        cout << "El vector principal esta vacio! Use la opcion 1 primero.\n";
        return;
    }
    
    int cant2;
    cout << "\nCuantos numeros desea ingresar al segundo vector? (max " << MAX - cant << "): ";
    cin >> cant2;
    
    if (cant2 <= 0 || (cant + cant2) > MAX) {
        cout << "Cantidad invalida o excede capacidad maxima!\n";
        return;
    }
    
    int vectorSecundario[MAX];
    cout << "\n*** Ingrese datos del segundo vector ***\n";
    for (int i = 0; i < cant2; i++) {
        cout << "Dato No " << i + 1 << ": ";
        cin >> vectorSecundario[i];
    }
    
    // Crear vector fusionado
    int vectorFusionado[MAX];
    int total = cant + cant2;
    
    // Copiar vector principal
    for (int i = 0; i < cant; i++) {
        vectorFusionado[i] = numeros[i];
    }
    
    // Copiar vector secundario
    for (int i = 0; i < cant2; i++) {
        vectorFusionado[cant + i] = vectorSecundario[i];
    }
    
    // Mostrar resultados
    cout << "\n*** Vector Principal ***\n";
    for (int i = 0; i < cant; i++) {
        cout << numeros[i] << "  ";
    }
    
    cout << "\n\n*** Vector Secundario ***\n";
    for (int i = 0; i < cant2; i++) {
        cout << vectorSecundario[i] << "  ";
    }
    
    cout << "\n\n*** Vector Fusionado ***\n";
    for (int i = 0; i < total; i++) {
        cout << vectorFusionado[i] << "  ";
    }
    cout << "\n";
}