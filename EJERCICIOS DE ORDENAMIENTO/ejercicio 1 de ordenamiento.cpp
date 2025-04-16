#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, int &comparaciones) { 
    for (int i = 0; i < n - 1; i++) { 
        int minIdx = i;
        for (int j = i + 1; j < n; j++) { 
            comparaciones++;
            if (arr[j] < arr[minIdx]) 
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
} 

int main() { 
    int arr[] = {580, 320, 760, 435, 520};
    int n = sizeof(arr) / sizeof(arr[0]); 
    int comparaciones = 0;

    selectionSort(arr, n, comparaciones);

    cout << "Ordenado de forma ascendete: ";
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;

    cout << "Numero de comparaciones: " << comparaciones << endl;

    return 0;
}