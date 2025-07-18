#include <iostream>
using namespace std;

// Practica #3 Grupo #4 integrantes
// Axel Ulate Ulate
// Esteban Wu Zhen
// Alejandro Somogyi Murillo

struct nodo
{
    int valor;
    nodo *siguiente;

} *head, *tail;

void push()
{
    nodo *nuevo = new nodo();
    cout << "\n Digite el dato a ingresar: ";
    cin >> nuevo->valor;

    if (head == NULL)
    {
        head = nuevo;
        head->siguiente = NULL;
        tail = head;
    }
    else
    {
        tail->siguiente = nuevo;
        nuevo->siguiente = NULL;
        tail = nuevo;
    }
    cout << "Nodo insertado" << endl;
    // system("pause");
}

void pop()
{
    if (head == NULL)
    {
        cout << "No existen datos en la cola " << endl;
    }
    else
    {
        nodo *actual = head;
        cout << "Nodo Eliminado: " << actual->valor << endl;
        head = actual->siguiente;
        delete actual;
    }

    system("pause");
}

void mostrarNodo()
{
    if (head == NULL)
    {
        cout << "No existen datos en la cola " << endl;
    }
    else
    {
        nodo *actual = head;
        actual = head;
        int i = 0;

        while (actual != NULL)
        {
            cout << "Elemento No." << i << ": " << actual->valor << endl;
            actual = actual->siguiente;
            i++;
        }
    }
    system("pause");
}

void buscarNodo()
{
    int buscar;
    int i = 0;
    nodo *actual = head;

    cout << "Que valor desea buscar: ";
    cin >> buscar;

    if (actual == NULL)
    {
        cout << "No existen datos en la cola " << endl;
    }
    else
    {
        while (actual != NULL)
        {
            if (actual->valor == buscar)
            {
                cout << "\n Dato: " << actual->valor << " fue encontrado en la posicion No. " << i << " de la cola\n";
                system("pause");
                return;
            }
            actual = actual->siguiente;
            i++;
        }
        cout << "\n Lo sentimos, la cola no contiene datos: " << buscar << endl;
        system("pause");
    }
}

void modificarNodo()
{
    nodo *actual = head;
    int buscar, modificar;
    int i = 0;

    cout << "Que valor desea cambiar: ";
    cin >> buscar;
    cout << "Al valor " << buscar << " desea cambiar por: ";
    cin >> modificar;

    if (actual == NULL)
    {
        cout << "No existen datos en la cola " << endl;
    }
    else
    {
        while (actual != NULL)
        {
            if (actual->valor == buscar)
            {
                cout << "\n Dato: " << actual->valor << " fue cambiado por " << modificar << " de la cola\n";
                actual->valor = modificar;
                system("pause");
                return;
            }
            actual = actual->siguiente;
            i++;
        }
        cout << "\n Lo sentimos, la cola no contiene datos: " << buscar << endl;
        system("pause");
    }
}

void buscarNodoRepetidos()
{
    int buscar;
    int i = 0;
    nodo *actual = head;
    bool encontrado = false;
    cout << "Que valor desea buscar: ";
    cin >> buscar;

    if (actual == NULL)
    {
        cout << "No existen datos en la cola " << endl;
    }
    else
    {
        while (actual != NULL)
        {
            if (actual->valor == buscar)
            {
                cout << "\n Dato: " << actual->valor << " fue encontrado en la posicion No. " << i << " de la cola\n";
                encontrado = true;
            }
            actual = actual->siguiente;
            i++;
        }

        if (encontrado == false)
        {
            cout << "\n Lo sentimos, la cola no contiene datos: " << buscar << endl;
            system("pause");
        }
        else
        {
            system("pause");
        }
    }
}

void modificarNodoRepetidos()
{
    nodo *actual = head;
    int buscar, modificar;
    int i = 0;
    bool encontrado = false;

    cout << "Que valor desea cambiar: ";
    cin >> buscar;

    if (actual == NULL)
    {
        cout << "No existen datos en la cola " << endl;
    }
    else
    {
        while (actual != NULL)
        {
            if (actual->valor == buscar)
            {
                cout << "\n Dato: " << actual->valor << " fue encontrado en la posicion No. " << i << " de la cola\n";
                cout << "Al valor " << buscar << " desea cambiar por: ";
                cin >> modificar;
                cout << "\n Dato: " << actual->valor << " fue cambiado por " << modificar << " de la cola\n";
                actual->valor = modificar;
                encontrado = true;
            }
            actual = actual->siguiente;
            i++;
        }
        if (encontrado == false)
        {
            cout << "\n Lo sentimos, la cola no contiene datos: " << buscar << endl;
            system("pause");
        }
        else
        {
            system("pause");
        }
    }
}

void popRepetidos()
{
    int buscar;
    nodo *actual = head;
    nodo *anterior = NULL;
    bool encontrado = false;

    cout << "Que valor desea eliminar: ";
    cin >> buscar;

    if (actual == NULL)
    {
        cout << "No existen datos en la cola " << endl;
    }
    else
    {
        while (actual != NULL)
        {
            if (actual->valor == buscar)
            {
                encontrado = true;
                cout << "Nodo Eliminado: " << actual->valor << endl;

                // Eliminar nodo
                nodo *temp = actual;

                if (anterior == NULL)
                {
                    head = actual->siguiente;
                    actual = head;
                }
                else
                {
                    anterior->siguiente = actual->siguiente;
                    actual = anterior->siguiente;
                }

                delete temp;
            }
            else
            {
                anterior = actual;
                actual = actual->siguiente;
            }
        }

        if (!encontrado)
        {
            cout << "\nLo sentimos, la cola no contiene datos: " << buscar << endl;
        }

        system("pause");
    }
}

void ordernarAsecen()
{
    nodo *actual = head;
    nodo *anterior = NULL;
    int intercambio = 0;
    bool ordenado = false;

    if (actual == NULL)
    {
        cout << "No existen datos en la cola " << endl;
    }
    else
    {
        nodo *next = actual->siguiente;
        while (!ordenado)
        {
            intercambio = 0;
            actual = head;
            next = actual->siguiente;
            while (actual != NULL && next != NULL)
            {
                if (actual->valor > next->valor)
                {
                    int temp = actual->valor;
                    actual->valor = next->valor;
                    next->valor = temp;
                    intercambio++;
                }
                actual = actual->siguiente;
                next = next->siguiente;
            }
            if (intercambio == 0)
            {
                ordenado = true;
            }
        }
    }
}

void ordernarDescendente()
{
    nodo *actual = head;
    nodo *anterior = NULL;
    int intercambio = 0;
    bool ordenado = false;

    if (actual == NULL)
    {
        cout << "No existen datos en la cola " << endl;
    }
    else
    {
        nodo *next = actual->siguiente;
        while (!ordenado)
        {
            intercambio = 0;
            actual = head;
            next = actual->siguiente;
            while (actual != NULL && next != NULL)
            {
                if (actual->valor < next->valor)
                {
                    int temp = actual->valor;
                    actual->valor = next->valor;
                    next->valor = temp;
                    intercambio++;
                }
                actual = actual->siguiente;
                next = next->siguiente;
            }
            if (intercambio == 0)
            {
                ordenado = true;
            }
        }
    }
}

int main()
{
    int opc;
    system("color 4");
    do
    {
        cout << "\n *** MENU DE OPCIONES *** \n";
        cout << "1. Insertar elementos en la Cola \n";
        cout << "2. Mostrar elementos en la Cola \n";
        cout << "3. Buscar un elemento en la Cola \n";
        cout << "4. Modificar un elemento en la Cola \n";
        cout << "5. Eliminar un elemento en la Cola \n";
        cout << "6. Buscar elementos en la Cola // si se repiten debe mostrarlos junto a su posición \n";
        cout << "7. Modificar elementos en la Cola // si se repiten debe dar chance a modificar \n";
        cout << "8. Eliminar elementos en la Cola // si se repite debe ser eliminado y mostrar \n";
        cout << "9. Ordenar elementos de la Cola Ascendentemente por prioridad \n";
        cout << "10. Ordenar elementos de la Cola Descendentemente por prioridad \n";
        cout << "11. Salir \n";

        cout << "\n Opcion: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            push();
            system("cls");
            break;
        case 2:
            mostrarNodo();
            system("cls");
            break;
        case 3:
            mostrarNodo();
            buscarNodo();
            system("cls");
            break;
        case 4:
            mostrarNodo();
            modificarNodo();
            system("cls");
            break;
        case 5:
            pop();
            system("cls");
            break;
        case 6:
            mostrarNodo();
            buscarNodoRepetidos();
            system("cls");
            break;
        case 7:
            mostrarNodo();
            modificarNodoRepetidos();
            system("cls");
			break;
			
        case 8:
            popRepetidos();
            mostrarNodo();
            system("cls");
            break;

        case 9:
            mostrarNodo();
            ordernarAsecen();
            cout << "\n*** Cola Ordenada Ascendentemente ***\n";
            mostrarNodo();
            system("cls");
            break;

        case 10:
            mostrarNodo();
            ordernarDescendente();
            cout << "\n*** Cola Ordenada Desecendetemente ***\n";
            mostrarNodo();
            system("cls");
            break;

        case 11:
            break;
        default:
            cout << "Opcion Invalida";
            system("cls");
            break;
        }
    } while (opc != 0);
};
