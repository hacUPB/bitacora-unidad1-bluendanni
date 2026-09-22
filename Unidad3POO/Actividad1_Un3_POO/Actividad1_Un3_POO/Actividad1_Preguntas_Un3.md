
# Unidad 3 - POO. 
## Actividad 1: diagnóstico inicial



 1.**¿Qué es el encapsulamiento para ti? Describe una situación en la que te haya sido útil o donde hayas visto su importancia.**
```
Para mí, el encapsulamiento consiste en proteger los datos internos de un objeto y controlar la manera en que otros pueden accederlos o modificarlos.
Por ejemplo, si tengo una clase CuentaBancaria, no sería buena idea permitir que cualquier parte del programa cambie directamente el saldo.
Sería mejor mantenerlo privado y modificarlo mediante métodos como Depositar() o Retirar(), donde se pueden comprobar las condiciones antes de cambiar el valor.
```

2. **¿Qué es la herencia? ¿Por qué un programador decidiría usarla? Da un ejemplo simple.**
```
La herencia hace que pueda crear una clase nueva a partir de otra, por lo que la nueva contiene características de la original, pero igual agregar los propios.
Un programador podría usarla para no tener que repetir código cuando varias clases contienen las mismas características.
```

3. **¿Qué es el polimorfismo? Describe con tus palabras qué significa que un código sea “polimórfico”.**
```
Significa que puedo tratar diferentes objetos como si fueran de un mismo tipo, pero al mismo tiempo, cada objeto puede comportarse de manera diferente.
Como el ejemplo de la variable Animal, donde el objeto es un Perro, por lo cual HacerSonido() ejecutaría el que le corresponde específicamente al Perro.
```

---
----
Ahora, preguntas sobre el código en el .cpp:

## **Encapsulamiento:**

- **Señala una línea de código que sea un ejemplo claro de encapsulamiento y explica por qué lo es.**

```
                private string nombre;

Es encapsulamiento porque nombre está declarado como private, por lo que solo lo puede acceder la clase Figura. 
```
- **¿Por qué crees que el campo nombre es private pero la propiedad Nombre es public? ¿Qué problema se evita con esto?** 
```
Hace que el valor interno quede protegido. Evita que pueda llamarse o modificarse por cualquier cosa. 
```
----

## **Herencia:**

- **¿Cómo se evidencia la herencia en la clase Circulo?**
```
                public class Circulo : Figura
                
Los dos puntos indican que Circulo hereda de Figura.
```
- **Un objeto de tipo Circulo, además de Radio, ¿Qué otros datos almacena en su interior gracias a la herencia?**
```
Contiene nombre, que es heredado de Figura, Radio que se define en Circulo. 
```

---
## **Polimorfismo:**

- **Observa el bucle `foreach`. La variable `fig` es de tipo Figura, pero a veces contiene un Circulo y otras un Rectangulo. Cuando se llama a `fig.Dibujar()`, el programa ejecuta la versión correcta.**
**En tu opinión, ¿Cómo crees que funciona esto “por debajo”? No necesitas saber la respuesta correcta, solo quiero que intentes razonar cómo podría ser.**
```
Puede ser que cada objeto tiene información de su tipo real mientras el programa se ejecuta. Porque Figura puede tener referencia a un Circulo o a un Rectángulo. Cuando se ejecuta fig.Dibujar(), el sistema revisa el tipo real del objeto y automáticamente selecciona la implementación que está sobrescrita que le corresponde. O sea cada uno ejecuta Circulo.Dibujar() o Rectangulo.Dibuja() sin usar condiciones.
```

---
### **Parte 3: hipótesis sobre la implementación**

Esta es la parte más importante. Imagina que eres un diseñador de lenguajes de programación. Tienes que decidir cómo implementar estos conceptos en la memoria y en el procesador.
No hay respuestas incorrectas, solo ideas. Dibuja si te ayuda.

1. **Memoria y herencia**: cuando creas un objeto `Rectangulo`, este tiene Base, Altura y también Nombre.
¿Cómo te imaginas que se organizan esos tres datos en la memoria del computador para formar un solo objeto?
```
Que Rectangulo ocupa solo un bloque de memoria en el que se encuentra primero la información que le corresponde a Figura, incluyendo nombre, después los datos ya del Rectangulo: Base y Altura. También debe existir información interna que diferencie que el objeto real es un rectángulo. 
```

2. **El mecanismo del polimorfismo:** pensemos de nuevo en la llamada `fig.Dibujar()`. El compilador solo sabe que fig es una Figura.
¿Cómo decide el programa, mientras se está ejecutando, si debe llamar al Dibujar del Circulo o al del Rectangulo? Lanza algunas ideas o hipótesis.
```
Es que cada objeto guarda info sobre su tipo real y los métodos que le corresponden. El prgorama consulta esa info en tiempo de ejecución, si el objeto es Círculo, busca el Dibujar() que es de Circulo. Lo mismo con Rectangulo. 
```

3. **La barrera del encapsulamiento:** ¿Cómo crees que el compilador logra que no puedas acceder a un miembro private desde fuera de la clase?
¿Es algo que se revisa cuando escribes el código, o es una protección que existe mientras el programa se ejecuta? ¿Por qué piensas eso?			
```
Pues debe ser que el compilador revise los modificadores de aceeso antes de generar todo. O sea, el encapsulamiento al final es protección o restricción que se verifica en la compilación, no como un cifrado de memoria. 
```		


















