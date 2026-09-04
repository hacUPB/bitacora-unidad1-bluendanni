
## **Tu Tarea**:

**A. Predicción (sin ejecutar el código):**

1. ¿Cuál será la salida final en la consola de este programa?
2. Escribe la salida completa que esperas.
3. Dibuja un mapa de memoria conceptual de este programa justo antes de que `main` finalice.
Debes indicar en qué segmento de memoria (Stack, Heap, Datos Globales/Estáticos, Código) se encontraría cada una de las siguientes variables: `contador_global`, `contador_estatico`, `val_A`, `val_B`, `val_C` (dentro de main), el parámetro a de la función `sumaPorValor`, la función main misma.
**B. Verificación y análisis (usando el depurador):**
Ejecuta el programa paso a paso (F10) con un `breakpoint` al inicio de `main`.
4. Compara la salida real con tu predicción. Si hubo diferencias, explica por qué ocurrieron.
Evidencia clave: capturas de pantalla antes y después de los puntos de interés (¿Cuáles son esos puntos? -> tu tarea analizarlo).
5. Describe qué demuestran estas capturas sobre la diferencia entre los diferentes tipos de paso por parámetros analizados.
6. Explica con tus propias palabras el comportamiento de contador_estatico. ¿Por qué “recuerda” su valor entre llamadas a la función ejecutarContador? ¿En qué se diferencia de una variable local normal?


## RESPUESTAS Y EVIDENCIAS:

1. La salida final de la consola será: val_A:20, val_B:30, val_C:30.
El contador_estatico imprime 1, 2 y 3.
El contador_global sigue siendo 100.
----
2. La salida completa que espero es:
--- Experimento con paso de parámetros ---
Valor inicial de val_A: 20
 -> Dentro de sumaPorValor, 'a' ahora es: 30
Valor final de val_A: 20

Valor inicial de val_B: 20
 -> Dentro de sumaPorReferencia, 'a' ahora es: 30
Valor final de val_B: 30

Valor inicial de val_C: 20
 -> Dentro de sumaPorPuntero, '*a' ahora es: 30
Valor final de val_C: 30

--- Experimento con variables estáticas ---
 -> Llamada a ejecutarContador. Valor de contador_estatico: 1
 -> Llamada a ejecutarContador. Valor de contador_estatico: 2
 -> Llamada a ejecutarContador. Valor de contador_estatico: 3

 **Esto por las llamadas que hace main**
 ----
 3.
 +---------------------------------------------+
|             Segmento de código              |
|         (instrucciones, funciones)          |
|                                             |
|  main()                                     |
|  ejecutarContador()                         |
|  sumaPorValor()                             |
|  sumaPorReferencia()                        |
|  sumaPorPuntero()                           |
+---------------------------------------------+
|       Variables globales y estáticas        |
|                                             |
|  contador_global = 100                      |
|  contador_estatico = 3       <--- static    |
+---------------------------------------------+
|                   Heap                      |
|                                             |
|  No se utiliza                              |
|                                             |
+---------------------------------------------+
|                  Stack                      |
|                                             |
|  main():                                    |
|    val_A = 20                               |
|    val_B = 30                               |
|    val_C = 30                               |
|                                             |
+---------------------------------------------+

**a** se encuentra en el Stack mientras sumaPorValor() está ejecutándose. 
Pero justo antes de que main() finalice, esa función ya terminó,
así que ese parámetro ya no existe como variable activa.

----
## B. Verificación y análisis (usando el depurador):

