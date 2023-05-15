#include <iostream>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// Función que selecciona el pivote y particiona el arreglo
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // Seleccionamos el último elemento como pivote
  int i = (low - 1);     // Índice del elemento más pequeño

  for (int j = low; j <= high - 1; j++) {
    // Si el elemento actual es más pequeño o igual que el pivote
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1],
       arr[high]); // Intercambiamos el pivote con el elemento en arr[i+1]
  return (i + 1);
}

void quicksort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Arreglo original: ";
  printArray(arr, n);

  quicksort(arr, 0, n - 1);
  cout << "Arreglo ordenado: ";
  printArray(arr, n);

  return 0;
}