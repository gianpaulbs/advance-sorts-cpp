class Sorts {
  private:
    void merge(Stack<Card> cards, int left, int middle, int right) {
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

  public:
    void mergesort(Stack<Card> cards, int left, int right) {
      if (left < right) {
        int middle = left + (right - left) / 2; // Calcular el punto medio

        // Ordenar recursivamente los subarreglos izquierdo y derecho
        mergesort(cards, left, middle);
        mergesort(cards, middle + 1, right);

      //   // Combinar los subarreglos ordenados
      //   merge(arr, left, middle, right);
      // }
    }
};