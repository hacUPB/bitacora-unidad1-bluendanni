#include <iostream>
using namespace std;
int main() {    // Tamaño del arreglo dinámico
    int tam = 5;
    // Asignar memoria en el Heap para un arreglo de enteros
    int* arrayHeap = new int[tam];
    // Inicializar y mostrar los valores y direcciones de memoria
    for (int i = 0; i < tam; i++) {
        arrayHeap[i] = (i + 1) * 10;
        cout << "arrayHeap[" << i << "] = " << arrayHeap[i] << " en dirección " << (arrayHeap + i) << endl;
    }
    // Liberar la memoria asignada en el Heap
    delete[] arrayHeap;
    /**********************************************************
    EXPERIMENTO 6
    ***********************************************************/
    cout << arrayHeap[0] << endl;

    /********************************************************/
    return 0;
}

/*
- ¿Qué ocurre? ¿Por qué?
El programa crea un arreglo dinámico de enteros en el Heap, lo inicializa y muestra sus valores
y direcciones de memoria. Luego, libera la memoria asignada con delete[] y finalmente intenta acceder
al primer elemento del arreglo después de haberlo liberado.
El problema es que el puntero arrayHeap queda apuntando a una región de memoria que ya no es válida.
Acceder a esa memoria después de liberarla es un comportamiento indefinido.
 Porque después de delete[], el puntero queda apuntando a una zona de memoria wue ya no pertenece. Queda un dangling pointer.
Como es indefinido, puede causar errores, resultados inesperados o incluso que el programa se bloquee.

- Comenta la línea de genera el error y analiza las siguientes preguntas:
La línea que genera el error es: cout << arrayHeap[0] << endl; porque intenta acceder a memoria liberada.

    - ¿Qué diferencias notas entre el comportamiento y la gestión del `Heap` en comparación con el `Stack`?
	En Stack, la memoria de las variables locales se gestiona automáticamente: se asigna al entrar en un bloque
    y se libera al salir. En Heap, la memoria debe ser gestionada manualmente: se asigna con `new` y se libera
    con `delete`. 

    - ¿Qué consecuencias tendría no liberar la memoria reservada con `new`?
	Fugas de memoria. La memoria asignada con `new` permanecería ocupada hasta que el programa termine,
    lo que puede llevar a un consumo excesivo de memoria y eventualmente agotar los recursos del sistema.

    - ¿Por qué es importante usar `delete[]` al liberar memoria asignada para un arreglo?
	Porque `delete[]` asegura que se llame al destructor de cada elemento del arreglo (si es un tipo de objeto)
    y libera correctamente toda la memoria asignada para el arreglo. Usar `delete` en lugar de `delete[]` puede causar un
    comportamiento indefinido y posibles fugas de memoria.

*/