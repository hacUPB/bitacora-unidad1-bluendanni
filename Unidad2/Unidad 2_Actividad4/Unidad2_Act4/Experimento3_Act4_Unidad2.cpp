#include <iostream>
#include <cstdlib>
using namespace std;
// Variables globales
int global_inicializada = 42;
int global_no_inicializada;

int main() {    // Variable local (stack)
    int a = 10;
    int b = 20;

    /**********************************************************
    EXPERIMENTO 3
    ***********************************************************/
    cout << "global_inicializada: " << global_inicializada << endl;
    cout << "global_no_inicializada: " << global_no_inicializada << endl;

    global_inicializada = 69;
    global_no_inicializada = 666;
    cout << "global_inicializada: " << global_inicializada << endl;
    cout << "global_no_inicializada: " << global_no_inicializada << endl;
    /********************************************************/
    return 0;
}
/*
- ¿Qué ocurre?
El programa imprime los valores de las variables globales, tanto la inicializada como la no inicializada.
Luego, modifica sus valores y vuelve a imprimirlos.

- ¿Por qué?
Porque global_inicializada y global_no_inicializada son variables globales, se almacenan en el segmento
de datos del programa. A diferencia de las variables locales, las variables globales tienen un tiempo de 
vida que abarca toda la ejecución del programa y pueden ser modificadas en cualquier parte del código.

*/