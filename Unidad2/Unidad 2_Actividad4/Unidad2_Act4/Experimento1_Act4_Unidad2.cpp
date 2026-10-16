#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    // Variable local (stack)
    int a = 10;
    int b = 20;
    /**********************************************************
    EXPERIMENTO 1
    ***********************************************************/
    void* ptr = reinterpret_cast<void*>(&main);
    cout << "Voy a modificar la memoria en la dirección: " << ptr << endl;
    *reinterpret_cast<int*>(ptr) = 0;
    /********************************************************/
    return 0;
}
/*
-¿Qué ocurre?
El programa alcanza a mostrar la dirección de memoria de main(), pero al intentar ejecutar: "*reinterpret_cast<int*>(ptr) = 0;"
se produce una violación de acceso y el programa se detiene.

- ¿Por qué?
ptr contiene la dirección de la función main(), que se encuentra en el segmento de código o segmento de texto. Ese segmento contiene las instrucciones compiladas del programa y normalmente está protegido como solo lectura, por lo que no se permite escribir directamente sobre él.

La instrucción intenta escribir 0 sobre la memoria donde están almacenadas las instrucciones de main(). Como esa región no tiene permiso de escritura, el sistema bloquea la operación y genera el error.

*/