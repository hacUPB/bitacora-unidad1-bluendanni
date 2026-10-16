# Sesiones 5, 6 y 7

## Sesión 5. Traducción de ciclos entre C++ y ensamblador

### Actividad integrada: convertir un ciclo while en un ciclo for

#### Objetivo

Comprender la equivalencia entre los ciclos while y for y comparar sus representaciones en ensamblador Hack.

#### Hipótesis

Los dos programas deben producir el mismo resultado porque utilizan los mismos valores iniciales, la misma condición de repetición y el mismo incremento. Aunque su escritura en C++ cambia, ambos suman los números del 1 al 100.

#### ¿Por qué los programas son equivalentes?

En ambos casos, la suma comienza en cero y el contador comienza en uno. Mientras el contador sea menor o igual a 100, su valor se agrega al acumulador y después aumenta una unidad.

La diferencia principal está en la organización del código. En el while, la inicialización está antes del ciclo y el incremento está dentro del cuerpo. En el for, la inicialización, la condición y el incremento aparecen juntos en la cabecera.

También cambia el alcance del contador en los ejemplos: si se declara dentro del for, solo puede utilizarse dentro de ese ciclo; si se declara antes del while, continúa disponible después.

#### Predicción

La suma debe ser:

1 + 2 + 3 + ... + 100 = 5050.

Después de sumar el número 100, el contador aumenta a 101. Al comprobar nuevamente la condición, el programa debe salir del ciclo.

#### Análisis de la ejecución

| Momento | Contador | Suma acumulada |
|---|---:|---:|
| Inicialización | 1 | 0 |
| Después de la primera repetición | 2 | 1 |
| Después de la segunda repetición | 3 | 3 |
| Después de la tercera repetición | 4 | 6 |
| Después de procesar el número 100 | 101 | 5050 |

En ensamblador, la comparación puede realizarse restando 100 al contador. Si el resultado es mayor que cero, el contador superó el límite y se salta al final.

Si el contador vale 100, la resta da cero y todavía debe ejecutarse el cuerpo del ciclo. Esto permite incluir el último número.

#### Comparación de las versiones en ensamblador

Hack no tiene instrucciones específicas para while o for. Los dos se construyen mediante:

- Inicialización de variables.
- Una etiqueta que marca el comienzo.
- Una comparación.
- Un salto condicional para salir.
- Las operaciones del cuerpo.
- La actualización del contador.
- Un salto para repetir.

Por esta razón, sus traducciones pueden tener la misma estructura e incluso las mismas instrucciones. Las etiquetas y los nombres de las variables pueden cambiar sin modificar el comportamiento.

#### Evidencia de la simulación

<!-- Insertar captura del contador y de la suma final. -->

#### Conclusión

While y for permiten expresar la misma repetición. En ensamblador, su funcionamiento depende de la condición de salida y de los saltos, no del nombre de la estructura utilizada en C++.

---

## Sesión 6. Punteros, arreglos y direcciones de memoria

### Actividad integrada: escritura mediante un puntero

#### Objetivo

Comprender cómo se modifica una variable utilizando un puntero que almacena su dirección.

#### Hipótesis

Si p apunta a a, escribir 20 mediante *p debe cambiar el valor de a de 10 a 20. La dirección almacenada en p debe permanecer igual.

#### ¿Qué es un puntero?

Un puntero es una variable que almacena una dirección de memoria. Esa dirección permite acceder a otra variable para leer o modificar su contenido.

El puntero y la variable apuntada ocupan posiciones diferentes. Una posición guarda la dirección y la otra guarda el dato.

#### ¿Cómo se declara un puntero en C++?

La declaración int* p indica que p es un puntero a un entero.

Declarar el puntero no garantiza que contenga una dirección válida. Antes de acceder mediante él, es necesario inicializarlo con una dirección apropiada.

#### ¿Cómo se asigna una dirección al puntero?

El operador & obtiene la dirección de una variable. La expresión p = &a guarda la dirección de a en p.

En ensamblador Hack, se obtiene la dirección de a utilizando el valor del registro A después de seleccionar su símbolo. Después se guarda esa dirección en la posición correspondiente a p.

#### ¿Cómo se modifica la variable apuntada?

La expresión *p = 20 escribe 20 en la posición cuya dirección está almacenada en p.

En Hack, primero se selecciona p, después se carga en A la dirección almacenada en esa posición y finalmente se escribe el nuevo dato en la posición apuntada.

#### Diferencia entre p y *p

p representa la dirección almacenada en el puntero.

*p representa el contenido de la posición apuntada.

Cambiar p modifica la dirección a la que apunta. Cambiar *p modifica el dato que se encuentra en esa dirección.

#### Análisis paso a paso

| Etapa | Estado esperado |
|---|---|
| Inicializar a | a contiene 10. |
| Asignar la dirección de a a p | p contiene la dirección de a. |
| Escribir 20 mediante *p | a contiene 20. |
| Revisar p | Conserva la dirección de a. |

La escritura mediante el puntero no crea una segunda variable con valor 20: modifica directamente la variable a.

#### Evidencia de la simulación

<!-- Insertar captura de a y p después de la escritura. -->

#### Conclusión

Una variable puede modificarse mediante su nombre o mediante un puntero que almacene su dirección. Para comprender esta operación es necesario diferenciar la dirección de memoria del contenido almacenado en ella.

---

### Actividad integrada: lectura mediante un puntero

#### Objetivo

Comprender cómo se obtiene el valor de una variable mediante un puntero y cómo se copia a otra variable.

#### Hipótesis

Si a contiene 10 y p apunta a a, la asignación b = *p debe cambiar b de 5 a 10. La lectura no debe modificar a ni la dirección almacenada en p.

#### ¿Qué significa leer *p?

Significa acceder a la dirección almacenada en p y obtener el dato que se encuentra allí.

En Hack, esto requiere seleccionar el puntero, cargar la dirección apuntada en A y leer el contenido de esa posición.

#### ¿Qué recibe b?

b recibe el valor de a, que es 10. No recibe su dirección.

La asignación copia un entero. No establece una conexión permanente entre a y b: si a cambia posteriormente, b no cambia automáticamente.

#### Análisis paso a paso

| Etapa | a | b | p |
|---|---:|---:|---|
| Inicializar las variables | 10 | 5 | Todavía sin asignar |
| Asignar la dirección | 10 | 5 | Dirección de a |
| Copiar el contenido apuntado a b | 10 | 10 | Dirección de a |

#### Comparación entre lectura y escritura

En la escritura, el contenido apuntado recibe un nuevo valor.

En la lectura, el contenido apuntado se utiliza como un dato para otra operación.

Ambas operaciones requieren acceder a la dirección guardada en el puntero.

#### Evidencia de la simulación

<!-- Insertar captura de a, b y p después de la lectura. -->

#### Conclusión

El puntero permite acceder indirectamente a una variable. Leer mediante él obtiene el dato almacenado en la dirección apuntada y permite copiarlo sin modificar la variable original.

---

### Actividad integrada: experimentar con arreglos

#### Objetivo

Inicializar diez valores desde RAM[16], recorrerlos mediante un puntero y calcular su suma.

#### Datos del arreglo

33, 44, 55, 12, 34, 56, 78, 98, 76 y 54.

#### Hipótesis

Como los elementos se encuentran en posiciones consecutivas, aumentar una unidad el puntero permitirá avanzar al siguiente elemento. Después de procesar diez valores, la suma debe ser 540.

#### Organización de memoria

| Dirección | Elemento | Valor |
|---|---|---:|
| RAM[16] | arr[0] | 33 |
| RAM[17] | arr[1] | 44 |
| RAM[18] | arr[2] | 55 |
| RAM[19] | arr[3] | 12 |
| RAM[20] | arr[4] | 34 |
| RAM[21] | arr[5] | 56 |
| RAM[22] | arr[6] | 78 |
| RAM[23] | arr[7] | 98 |
| RAM[24] | arr[8] | 76 |
| RAM[25] | arr[9] | 54 |

Las variables auxiliares deben ubicarse fuera de estas posiciones para evitar sobrescribir los elementos.

#### ¿Cómo se accede a arr[j]?

La dirección se calcula sumando el índice a la dirección base:

Dirección de arr[j] = 16 + j.

Por ejemplo, arr[3] está en RAM[19] y contiene 12.

En este ejercicio, cada elemento ocupa una palabra de memoria Hack. En C++, el cálculo de direcciones también considera el tamaño del tipo de dato.

#### ¿Qué función cumple el puntero?

El puntero guarda la dirección del elemento actual. Comienza en 16 y aumenta una unidad después de procesar cada valor.

El contador indica cuántos elementos se han procesado. El acumulador conserva la suma parcial.

#### Prueba 1. Inicialización del arreglo

**Característica que se comprueba:** almacenamiento correcto de los diez valores.

**Predicción:** RAM[16] a RAM[25] deben contener los valores indicados en la tabla.

**Procedimiento:** ejecutar la inicialización y revisar cada posición antes de comenzar el recorrido.

**Criterio de aceptación:** las diez posiciones coinciden con los datos originales.

<!-- Insertar captura de RAM[16] a RAM[25]. -->

#### Prueba 2. Inicialización de variables auxiliares

**Característica que se comprueba:** estado inicial del recorrido.

**Predicción:** acumulador en cero, contador en cero y puntero en 16.

**Procedimiento:** detener la ejecución antes de la primera lectura y revisar las variables auxiliares.

**Criterio de aceptación:** el recorrido comienza en el primer elemento y no incluye valores de una ejecución anterior.

<!-- Insertar captura de las variables auxiliares. -->

#### Prueba 3. Primera lectura y acumulación

**Característica que se comprueba:** acceso indirecto al primer elemento.

**Predicción:** se lee 33 y la suma cambia de 0 a 33. Después del avance, el contador debe valer 1 y el puntero debe apuntar a 17.

**Procedimiento:** ejecutar una repetición y revisar el dato leído, la suma y las actualizaciones.

**Criterio de aceptación:** se procesa exactamente el primer elemento.

<!-- Insertar captura de la primera repetición. -->

#### Prueba 4. Recorrido y sumas parciales

**Característica que se comprueba:** avance correcto por el arreglo.

**Predicción:**

| Elementos procesados | Último dato agregado | Suma acumulada |
|---|---:|---:|
| 1 | 33 | 33 |
| 2 | 44 | 77 |
| 3 | 55 | 132 |
| 4 | 12 | 144 |
| 5 | 34 | 178 |
| 6 | 56 | 234 |
| 7 | 78 | 312 |
| 8 | 98 | 410 |
| 9 | 76 | 486 |
| 10 | 54 | 540 |

**Procedimiento:** revisar el acumulador al terminar distintas repeticiones y compararlo con la tabla.

**Criterio de aceptación:** cada suma parcial corresponde al número de elementos procesados.

<!-- Insertar capturas de sumas parciales. -->

#### Prueba 5. Condición de salida y resultado final

**Característica que se comprueba:** finalización después de diez elementos.

**Predicción:** el contador llega a 10 y la suma queda en 540. El programa no debe leer un undécimo elemento.

Si el puntero se incrementa después de cada lectura, termina en 26, una posición después del último elemento. Esto es correcto mientras no se lea esa posición como parte del arreglo.

**Procedimiento:** ejecutar hasta la salida del ciclo y revisar el acumulador, el contador y los datos originales.

**Criterio de aceptación:** suma de 540, diez elementos procesados y arreglo sin modificaciones.

<!-- Insertar captura del resultado final. -->

#### Conclusión

Un arreglo puede recorrerse mediante una dirección base y un índice, o mediante un puntero que avance entre posiciones consecutivas.

Separar las pruebas permite distinguir errores de inicialización, lectura, acumulación, avance y condición de salida. Una suma incorrecta puede investigarse comparando las sumas parciales hasta encontrar la primera diferencia.

---

## Sesión 7. Autoevaluación

### Parte 1. Recuperación de conocimiento

Las siguientes respuestas constituyen una guía de solución. La actividad original pide realizar primero el intento personal sin consultar material.

#### 1. Describe las fases Fetch-Decode-Execute. ¿Qué rol juega el PC?

Fetch consiste en obtener la instrucción de la memoria de instrucciones. El PC indica su dirección.

Decode consiste en interpretar la instrucción y determinar qué operación debe realizarse.

Execute consiste en realizar la operación, por ejemplo, calcular un resultado, escribir en memoria o efectuar un salto.

El PC normalmente avanza a la siguiente instrucción. Si se ejecuta un salto, toma la dirección de destino.

#### 2. ¿Cuál es la diferencia entre una instrucción A y una instrucción C? Da ejemplos.

Una instrucción A carga un valor en el registro A. Por ejemplo, @10 carga el número 10.

Una instrucción C realiza una operación y puede guardar su resultado o decidir un salto. Por ejemplo, D=A copia el contenido de A a D.

El valor cargado en A puede utilizarse como un dato, una dirección de RAM o un destino de salto, según la instrucción posterior.

#### 3. ¿Qué funciones cumplen D, A y la ALU?

D es un registro que permite guardar datos temporalmente para realizar cálculos.

A almacena un valor que también puede seleccionar una dirección de RAM o indicar el destino de un salto.

La ALU realiza operaciones aritméticas y lógicas. Sus resultados también permiten evaluar condiciones, como si un valor es cero o negativo.

#### 4. ¿Cómo se implementa un salto condicional?

Se carga la dirección de destino en A y se utiliza una instrucción C con una condición de salto.

Por ejemplo, después de seleccionar una etiqueta de destino, D;JGT salta si D es mayor que cero. Si la condición no se cumple, continúa la ejecución normal.

#### 5. ¿Cómo se implementa un ciclo?

Se utiliza una etiqueta de inicio, una comprobación de salida, un cuerpo de instrucciones y un salto que regresa al comienzo.

Para decrementar hasta cero, el programa puede comprobar si el contador llegó a cero; si no llegó, lo disminuye y vuelve a comprobar.

El contador debe actualizarse para que el ciclo pueda alcanzar su condición de salida.

#### 6. ¿Cuál es la diferencia entre D=M y M=D?

D=M lee el contenido de RAM en la dirección indicada por A y lo copia a D.

M=D escribe el contenido de D en RAM, también en la dirección indicada por A.

M representa RAM[A], no un registro independiente.

#### 7. ¿Qué se necesita para leer el teclado y pintar un píxel?

Para leer el teclado, se consulta la posición KBD, correspondiente a RAM[24576]. Su contenido representa la tecla presionada; si no hay una tecla presionada, contiene cero.

Para modificar la pantalla, se escribe en su mapa de memoria, que comienza en SCREEN, RAM[16384].

Cada palabra representa 16 píxeles. Un bit en uno representa un píxel negro y un bit en cero representa uno blanco. Para cambiar un píxel específico se debe modificar el bit correspondiente, conservando los demás si es necesario.

#### 8. ¿Cómo se representa y manipula un puntero en Hack?

Se utiliza una posición de RAM para almacenar la dirección de otra posición.

Para realizar el equivalente a p = &a, se obtiene la dirección de a y se guarda en p.

Para realizar el equivalente a *p = 20, se prepara el valor 20, se obtiene la dirección almacenada en p y se escribe allí.

La diferencia fundamental es que asignar al puntero modifica una dirección, mientras que escribir a través de él modifica el contenido apuntado.

#### 9. ¿Cómo se accede a arr[j]?

Se suma el índice j a la dirección base del arreglo y se accede a la posición resultante.

Si la base es 16 y j vale 3, se accede a RAM[19].

La base determina dónde comienza el arreglo y el índice indica cuántas posiciones hay que avanzar.

### Parte 2. Reflexión sobre el proceso

Estas son reflexiones modelo que deben ajustarse a la experiencia real de quien presenta la bitácora.

#### 1. ¿Cuál es el principal desafío conceptual de esta unidad?

Distinguir entre una dirección de memoria y el contenido almacenado en ella. Esta diferencia es esencial para comprender el registro A, la notación M, los punteros y los arreglos.

#### 2. ¿Cuándo resulta más útil predecir, ejecutar, observar y reflexionar?

Cuando una instrucción puede confundirse con otra, como D=A y D=M. Predecir el valor esperado y compararlo con el simulador permite identificar si se está leyendo una dirección o un contenido.

#### 3. ¿Qué comprensión conecta varios conceptos de la unidad?

Comprender que M representa RAM[A]. Esto explica por qué cambiar A modifica la posición a la que se accede y permite entender cómo funcionan los punteros.

#### 4. ¿Qué estrategia puede mejorar el estudio de la próxima unidad?

Dividir los programas en partes pequeñas, anotar los valores esperados y comprobar cada parte antes de continuar. También explicar el funcionamiento con palabras propias, sin limitarse a reconocer el código.

#### 5. ¿Qué hace difícil traducir punteros a ensamblador y cómo se puede abordar?

Una operación breve en C++ puede requerir varios pasos en ensamblador: localizar el puntero, obtener la dirección y acceder al contenido.

Un mapa de memoria ayuda a separar estas operaciones y a identificar qué se guarda en cada posición.

#### 6. ¿Cómo ayuda construir el programa de arreglos mediante pruebas?

Permite verificar por separado la inicialización, la lectura, la suma y la condición de salida. Si una etapa falla, se puede corregir antes de agregar más instrucciones.

#### 7. ¿Qué relación de bajo nivel se puede reconocer en C++?

Los ciclos dependen de condiciones y saltos; los punteros almacenan direcciones; los arreglos organizan elementos consecutivos. Estas relaciones permiten conectar las estructuras de C++ con operaciones concretas de memoria y control de flujo.

---

## Sesión 7. Coevaluación

La coevaluación requiere revisar la bitácora de un compañero y la verdad no la pude hacer en su momento jeje 