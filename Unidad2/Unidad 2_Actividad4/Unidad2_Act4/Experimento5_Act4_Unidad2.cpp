#include <iostream>
#include <cstdlib>
using namespace std;
// Función de ejemplo que muestra la dirección de su variable local estática
void funcionConStatic() {
	static int var_estatica = 100;
	cout << "var_estatica: " << var_estatica << endl;
	var_estatica++;
}

void funcionSinStatic() {
	int var_no_estatica = 100;
	cout << "var_no_estatica: " << var_no_estatica << endl;
	var_no_estatica++;
}

int main() {    // Variable local (stack)
	int a = 10;
	int b = 20;
	/**********************************************************
	EXPERIMENTO 5
	***********************************************************/
	for (int i = 0; i < 5; i++) {
		cout << "Iteración " << i << endl;
		funcionSinStatic();
		funcionConStatic();
	}
	/********************************************************/
	return 0;
}


/* 
- Qué ocurre? ¿Por qué?
En cada for, ambas funciones se llaman, pero la variable local no estática se reinicia a 100 en cada llamada,
mientras que la variable local estática mantiene su valor entre llamadas y se incrementa en cada iteración.

var_no_estatica es una variable local normal, por lo que se crea y destruye cada vez que se entra y sale de
la función funcionSinStatic(). Por eso, en cada iteración del bucle, su valor vuelve a ser 100.

- Ves alguna diferencia entre las variables locales estáticas y no estáticas?
La variable local notmal existe solo mientras se ejecuta la función, mientras que la variable local estática existe
durante toda la ejecución del programa y conserva su valor entre llamadas a la función.

- ¿Qué pasa con las variables cada que entras y sales de la función?
La no estática se crea de nuevo cada vez que entras y desaparece al salir. La estática permanece en memoria y conserva su valor entre llamadas.

*/