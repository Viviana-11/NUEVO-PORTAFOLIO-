#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int &intercambios) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // Comparación para ordenar en forma ascendente
                swap(arr[j], arr[j + 1]);
                intercambios++; // Incrementa el contador solo cuando hay un intercambio
            }
        }
    }
}

int main() {
    int arr[] = {125, 90, 150, 105, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    int intercambios = 0;

    bubbleSort(arr, n, intercambios);

    cout << "Arreglo ordenado de forma ascendente: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Numero de intercambios: " << intercambios << endl;

    return 0;
}