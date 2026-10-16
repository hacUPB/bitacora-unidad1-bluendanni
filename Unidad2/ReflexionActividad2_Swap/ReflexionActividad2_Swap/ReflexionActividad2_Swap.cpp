#include <iostream>
using namespace std;

void swapPorValor(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapPorReferencia(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapPorPuntero(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10;
    int b = 20;

    cout << "Valores iniciales: a = " << a << ", b = " << b << endl;

    cout << "\nPaso por valor:" << endl;
    swapPorValor(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    cout << "\nPaso por referencia:" << endl;
    swapPorReferencia(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    a = 10;
    b = 20;

    cout << "\nPaso por puntero:" << endl;
    swapPorPuntero(&a, &b);
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}