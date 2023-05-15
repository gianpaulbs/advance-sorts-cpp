#include <iostream>
using namespace std;

// Función para combinar dos subarreglos ordenados en un solo arreglo ordenado
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1; // Tamaño del subarreglo izquierdo
    int n2 = right - middle; // Tamaño del subarreglo derecho

    // Crear arreglos temporales
    int * L = new int[n1];
    int * R = new int[n2];

    // Copiar los datos a los arreglos temporales
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Combinar los subarreglos ordenados en el arreglo original
    int i = 0; // Índice inicial del subarreglo izquierdo
    int j = 0; // Índice inicial del subarreglo derecho
    int k = left; // Índice inicial del arreglo original

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes del subarreglo izquierdo, si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes del subarreglo derecho, si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función principal de Mergesort
void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2; // Calcular el punto medio

        // Ordenar recursivamente los subarreglos izquierdo y derecho
        mergesort(arr, left, middle);
        mergesort(arr, middle + 1, right);

        // Combinar los subarreglos ordenados
        merge(arr, left, middle, right);
    }
}

// Función para imprimir un arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Arreglo original: ";
    printArray(arr, n);
    
    mergesort(arr, 0, n - 1);
    cout << "Arreglo ordenado: ";
    printArray(arr, n);
    
    return 0;
}