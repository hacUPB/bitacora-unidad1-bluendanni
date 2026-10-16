# Actividad 6: Hola Objeto: creación de un objeto en el stack

- 0A hexadecimal = 10 decimal
14 hexadecimal = 20 decimal
# **Reflexiona sobre las siguientes cuestiones**:

1. ¿Cuál es la diferencia entre un constructor y un destructor en C++?
2. ¿Cuál es la diferencia entre un objeto y una clase en C++?
3. ¿Qué diferencia notas entre el objeto Punto en C++ y C#?
4. ¿Qué es `p` en C++ y qué es `p` en C#? (en uno de ellos `p` es un objeto y en el otro es una referencia a un objeto).
5. ¿En qué parte de memoria se almacena `p` en C++ y en C#?
6. ¿Qué observaste con el depurador acerca de `p`? Según lo que observaste ¿Qué es un objeto en C++?

## RESPUESTAS:

1. Un constructor es un método especial que se llama automáticamente cuando se crea un objeto de una clase,
 y se utiliza para inicializar los atributos del objeto. Un destructor, por otro lado, es un método especial
 que se llama automáticamente cuando un objeto sale del alcance o se destruye, y se utiliza para liberar recursos
 o realizar limpieza antes de que el objeto sea eliminado.

 2. Una clase es una plantilla o un plano que define las propiedades y comportamientos de los objetos que se 
crean a partir de ella. Un objeto, por otro lado, es una instancia concreta de una clase, que tiene su propio estado y comportamiento.

3. En C++, el objeto Punto se crea en el stack y tiene un tiempo de vida limitado al alcance en el que se declara.
 En C#, el objeto Punto se crea en el heap y su tiempo de vida está gestionado por el recolector de basura, lo que 
 significa que puede vivir más allá del alcance en el que se declara.

 4. En C++, `p` es un objeto de la clase Punto, mientras que en C#, `p` es una referencia a un objeto de la clase Punto.

 5. En C++, `p` se almacena en el stack, mientras que en C#, `p` se almacena en el heap.
	
6. En el depurador, se puede observar que `p` en C++ tiene un tiempo de vida limitado al alcance en el que se declara,
 mientras que en C#, `p` puede vivir más allá del alcance en el que se declara debido a la gestión de memoria del recolector de basura.
 Esto indica que un objeto en C++ es una instancia concreta de una clase que se almacena en el stack y tiene un tiempo de vida limitado,
 mientras que en C#, un objeto es una instancia concreta de una clase que se almacena en el heap y su tiempo de vida está gestionado por el recolector de basura.





