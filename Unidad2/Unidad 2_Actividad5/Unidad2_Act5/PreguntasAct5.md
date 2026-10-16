## Reflexión final para esta actividad
---
1. Explica qué ocurre al copiar un objeto en C++ y en C#. ¿Qué diferencias encuentras?
En C++, cuando se copia un objeto, se crea una copia independiente del objeto original.
Esto significa que cualquier cambio realizado en la copia no afectará al objeto original
y viceversa. En cambio, el puntero Punto* p = &original; si apunta directamente al objeto original,
por lo que cualquier cambio realizado a través del puntero afectará al objeto original.

----
2. ¿Qué es `copia` en C++ y en C#? ¿Es una copia independiente de `original`?
En C++, una copia es un objeto separado que contiene los mismos valores que el
objeto original. Cualquier cambio realizado en la copia no afectará al objeto original
y viceversa. En C#, cuando se copia un objeto, se crea una nueva referencia al mismo 
objeto en la memoria, por lo que cualquier cambio realizado a través de la referencia 
afectará al objeto original.
---
# En pocas palabras, en C++ Punto copia = original crea un objeto independiente.

# En C#, Punto copia = original hace que ambas variablas hagan referencia al mismo objeto en memoria.
---