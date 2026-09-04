#include <iostream>
#include <cstdlib>
using namespace std;
// Constante global
const char* const mensaje_ro = "Hola, memoria de solo lectura";

int main() {
    // Variable local (stack)
    int a = 10;
    int b = 20;

    /**********************************************************
    EXPERIMENTO 2
    ***********************************************************/
    char* ptr = (char*)&mensaje_ro;
    cout << "Voy a modificar la memoria en la dirección: " << ptr << endl;
    *ptr = 0;
    /********************************************************/
    return 0;
} 

/* 
-¿Qué ocurre?
El programa intenta modificar la memoria donde está almacenada la constante global mensaje_ro. Al ejecutar "*ptr = 0;"
el programa puede detenersecon una violación de acceso, porque intenta escribir en una región de memoria que está protegida
como solo lectura.

- ¿Por qué?
mensaje_ro está declarado como "const char* const mensaje_ro = "Hola, memoria de solo lectura";" Eso significa que es una constante global, y su valor no puede ser modificado.
En este ejemplo se obtiene su direccíón como char* ptr = (char*)&mensaje_ro;. El cast elimina la protección de const, pero la memoria donde se almacena mensaje_ro sigue siendo de solo lectura.
Por lo tanto, al intentar escribir en esa dirección, el sistema operativo bloquea la operación y genera un error de violación de acceso.
Hacer cast puede permitir compilar el código, pero no garantiza que la operación sea segura o permitida en tiempo de ejecución.

*/