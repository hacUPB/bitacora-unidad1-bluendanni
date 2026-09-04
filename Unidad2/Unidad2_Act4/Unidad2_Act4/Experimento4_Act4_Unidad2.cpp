
/* Experimento 4: modificar la variable local estática de una función por fuera de ella: */

#include <iostream>
#include <cstdlib>
using namespace std;
// Función de ejemplo que muestra la dirección de su variable local estática
void funcionConStatic() {
    static int var_estatica = 100;
    cout << "Dirección de var_estatica (static): " << &var_estatica << endl;
}

int main() {    // Variable local (stack)
    int a = 10;
    int b = 20;
    /**********************************************************
    EXPERIMENTO 4
    ***********************************************************/
    var_estatica = 42;
    cout << "var_estatica: " << var_estatica << endl;
    /********************************************************/
    return 0;
}
/* 
- ¿Qué ocurre?
El programa no compila porque la variable local estática var_estatica está definida dentro de la función funcionConStatic()
y no es accesible desde main(). Intentar acceder a ella directamente desde main() genera un error de compilación.
Aunque sea static , su alcance sigue siendo local a la función donde fue declarada, por lo que no se puede modificar desde fuera de esa función.

- ¿Por qué?
Porque static cambia el tiempo de vida de la variable, pero no su alcance. La variable var_estatica
tiene un tiempo de vida que dura toda la ejecución del programa, pero su alcance sigue siendo limitado 
a la función funcionConStatic(). Por lo tanto, no se puede acceder ni modificar desde main() u otras funciones.

- ¿Qué pasa con las variables cada que entras y sales de la función?
Las variables locales normales se crean y destruyen cada vez que se entra y sale de la función, mientras que las
variables locales estáticas se crean una sola vez y conservan su valor entre llamadas a la función. 

- ¿Qué pasa con las variables locales estáticas?
No se destruyen al salir de la función, y su valor se mantiene entre llamadas a la función.


*/