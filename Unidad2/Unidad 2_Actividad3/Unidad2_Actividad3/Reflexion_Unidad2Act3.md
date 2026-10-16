# Mapa de memoria de ejemplo: 

+-------------------------------+
|	    Segmento de código      |
|   (instrucciones, funciones)  |
+-------------------------------+
| Variables globales y estáticas| <---- static (estáticas)
+-------------------------------+
|           Heap                | <--- Asignación dinámica (new/malloc)
|                               |
|                               |
+-------------------------------+
|           Stack               | <--- Variables locales
+-------------------------------+

##  Reflexión final para esta actividad:

Revisa de nuevo el programa anterior y construye tu propio mapa de memoria indicando
en qué parte del mapa se ubican las variables y constantes globales, locales, estáticas y
de la memoria dinámica y en qué parte del mapa se encuentran las funciones y el mensaje de solo lectura.

----
# Desarrollo de la actividad:

# Mapa de memoria

+---------------------------------------------+
|             Segmento de código              |
|         (instrucciones, funciones)          |
|                                             |
|  main()                                     |
|  suma()                                     |
|  crearArrayHeap()                           |
|  funcionConStatic()                         |
|                                             |
|  "Hola, memoria de solo lectura"            |
+---------------------------------------------+
|       Variables globales y estáticas        |
|                                             |
|  global_inicializada = 42                   |
|  global_no_inicializada                     |
|  var_estatica = 100              <--- static|
|  mensaje_ro                      <--- const  |
+---------------------------------------------+
|                   Heap                      |
|                                             |
|  new int[tam]       <--- memoria dinámica   |
|                                             |
|  arrayHeap[0]                               |
|  arrayHeap[1]                               |
|  ...                                        |
|  arrayHeap[9]                               |
|                                             |
+---------------------------------------------+
|                  Stack                      |
|                                             |
|  main():                                    |
|    a = 10                                   |
|    b = 20                                   |
|    c = 30                                   |
|    tamArray = 10                            |
|    arrayHeap        ---> apunta al Heap     |
|    i                                        |
|                                             |
|  suma():                                    |
|    a                                        |
|    b                                        |
|    c                                        |
|                                             |
|  crearArrayHeap():                          |
|    tam                                      |
|    arr              ---> apunta al Heap     |
|    i                                        |
+---------------------------------------------+