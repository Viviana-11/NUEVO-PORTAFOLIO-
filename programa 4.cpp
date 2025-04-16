#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int a[n], b[n];
    int suma[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cin >> b[i];
    }

    int ProductoEsc = 0;

    for (int i = 0; i < n; i++) {
        suma[i] = a[i] + b[i];
        ProductoEsc += a[i] * b[i];
        cout << suma[i] << endl;
    }

    cout << ProductoEsc << endl;

    return 0;
}