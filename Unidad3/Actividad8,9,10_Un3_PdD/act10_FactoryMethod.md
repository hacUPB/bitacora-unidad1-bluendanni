## Actividad 10: Investiga el patrón Factory Method

### 1. Explica con tus propias palabras el propósito de Factory Method o Simple Factory. ¿Qué problema aborda?

Una fábrica reúne en un solo lugar la creación y configuración de objetos. Así no hay que repetir esas instrucciones en diferentes partes del programa.
Acá, ParticleFactory crea una Particle y ajusta sus propiedades según el tipo solicitado

---

### 2. ¿Qué ventajas aporta ParticleFactory en ofApp::setup?

Hace que setup sea más corto y fácil de entender: solicita las partículas y la fábrica se encarga de configurarlas.
También facilita cambiar sus propiedades o agregar nuevas configuraciones sin repetir instrucciones por todo el programa. Cada parte tiene una responsabilidad más clara

---

### 3. ¿Cómo añadirías una partícula black_hole? ¿Tendrías que modificar setup?

Agregaría una opción black_hole en createParticle y le asignaría un tamaño grande, color negro y una velocidad inicial muy baja.
Sí tendría que modificar setup si quiero que aparezca desde el inicio, porque allí se solicitan las partículas que se van a crear.
La velocidad inicial baja podría cambiar después al activar otros estados

---

### 4. ¿Qué ventajas y desventajas tiene que createParticle sea estático?

La ventaja es que puedo llamar al método directamente mediante ParticleFactory sin crear un objeto fábrica. Es sencillo para este ejemplo.
La desventaja es que no permite tener distintas fábricas con su propia configuración ni reemplazar el método mediante polimorfismo. Una fábrica de instancia daría más flexibilidad si el programa necesitara ser
más grande
