## **Reflexiona sobre lo siguiente**:

1. Explicación de la diferencia entre objetos creados en el stack y en el heap.
2. `pStack` ¿Es un objeto o una referencia a un objeto?
3. `pHeap` ¿Es un objeto o una referencia a un objeto? Si es una referencia, 
¿A qué objeto hace referencia?
4. Observa en Memory1 (Debug->Windows->Memory->Memory1) el contenido de la dirección de memoria de `pHeap`, recuerda escribir en la entrada de texto de Memory1 la dirección de memoria de `&pHeap` y presionar Enter. Compara el contenido de memoria con el contenido de `pHeap` en la pestaña de Locals (Debug->Windows->Locals).
¿Qué observas? ¿Qué significa esto?


## RESPUESTAS

1. La diferencia entre objetos creados en el stack y en el heap radica principalmente en su gestión de memoria y tiempo de vida. Los objetos en el stack se crean y destruyen automáticamente cuando entran y salen del alcance de la función, lo que significa que su tiempo de vida es limitado al bloque de código donde se declaran. Por otro lado, los objetos en el heap se crean dinámicamente y permanecen en memoria hasta que se liberan explícitamente mediante una llamada a `delete` (en C++) o cuando el recolector de basura los elimina (en lenguajes con gestión automática de memoria como Java o C#). Esto permite que los objetos en el heap tengan un tiempo de vida más flexible, pero también requiere una gestión más cuidadosa para evitar fugas de memoria.

2. `pStack` es una referencia a un objeto. En este caso, `pStack` apunta a un objeto que se encuentra en el stack, y su valor es la dirección de memoria de ese objeto.

3. `pHeap` es una referencia a un objeto. Hace referencia a un objeto que se encuentra en el heap, y su valor es la dirección de memoria de ese objeto. Esto significa que `pHeap` no contiene el objeto en sí, sino la ubicación en memoria donde se almacena el objeto en el heap.

4. Al observar el contenido de la dirección de memoria de `pHeap` en Memory1 y compararlo con el contenido de `pHeap` en la pestaña de Locals, se puede notar que ambos muestran la misma dirección de memoria. Esto significa que `pHeap` contiene la dirección del objeto en el heap, y al inspeccionar esa dirección en Memory1, se puede ver el contenido real del objeto al que `pHeap` hace referencia. Esto confirma que `pHeap` es efectivamente una referencia a un objeto en el heap, y no el objeto mismo.








