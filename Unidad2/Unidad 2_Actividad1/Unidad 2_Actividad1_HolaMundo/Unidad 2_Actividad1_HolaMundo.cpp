#include <iostream>
int sum(int a, int b) {
	return a + b;
}

int main() {
	int a = 5;
	int b = 7;
	std::cout << "La suma de " << a << " y " << b << " es " << sum(a, b) << "\n";
}

/*/
¿Para qué sirven los Breakpoints?
Sirven para detener temporalmente la ejecución del programa en una línea específica,
para poder revisar qué está pasando en ese momento y continuar ejecutando el código paso a paso.

¿Para qué se usa la ventana de depuración Autos?
Se usa para observar las variables relevantes durante la ejecución del programa, incluyendo sus valores.
/*/