# Notas Lab C

## Archivos .c vs .h

.c es el "proceso" del algoritmo, es el código ejecutable.
Asignan espacio en la memoria cuando se compilan y generan el código máquina.

.h es una **cabecera**, declaración de funciones, qué parámetros reciben y qué devuelven(prototipos).
No reservan espacio en memoria.
Se incluyen al principio de otros archivos mediante la directiva del preprocesador #include "archivo.h".



## Estructura

### Main.c

Llama a las funciones/cabeceras.
Hasta ahora no hay menú, solo llama a la función e imprime el resultado.

### SRC

#### artemis.c

**Utiliza** ../include/artemis.h

**Calcula**:

* Velocidad orbital. Double
* pto a) Imprime por pantalla la demostración analítica. Void
* Calculamos el periodo orbital con la velocidad orbital que ya calculamos. Double

**Void**: ausencia de tipo de valor. Para retorno de funciones o como puntero genérico.
**Double**: tipo de dato de punto flotante.

#### validaciones.c

**%d**: Para mostrar números enteros con signo (decimales). Representa un número entero en base 10. scanf("%d", &valor);
**%s**: Indica que el dato con el que se va a trabajar es una cadena de caracteres. printf("%s", mensaje);
**%f**: Es un especificador de formato que se utiliza para trabajar con números de punto flotante (números decimales o reales), como las variables de tipo float. scanf("%f", &valor);
**%.2f.**: para mostrar solo 2 decimales
**&variable**: Cuando pasas solo el nombre de una variable, le estás dando a la función una copia de lo que hay dentro de ella. Si scanf recibiera una copia de la variable, guardaría el número que escribas en la copia, y al terminar la función, ese número se destruiría y tu variable original seguiría vacía.

**do { ... }**: Garantiza que el bloque de instrucciones dentro de las llaves se ejecute al menos una vez antes de evaluar ninguna condición.
**if (resultado != 1)**: Evalúa una condición intermedia durante la ejecución del bloque. Si resultado es distinto de 1, ejecuta ciertas instrucciones (por ejemplo, reintentar una operación, mostrar un error o usar continue).
**while (1)**: Crea un bucle infinito. La única manera de salir de este ciclo es que dentro del bloque se ejecute una instrucción break. Si no hay un break, el programa se quedará atrapado repitiéndose indefinidamente.


### include

#### Artemis.h

Definición de variables y constantes para el pto a).

**Directivas del preprocesador** (. Esto significa que el preprocesador las evalúa y actúa sobre ellas antes de que el código sea compilado.):

* \#define: Se usa para crear macros o constantes simbólicas. Le indica al preprocesador que sustituya un identificador por un valor o fragmento de código en todo el programa. #define PI 3.14159265359
* \#ifndef: (If Not Defined), if pero sintaxis de cabecera.
* \#endif: fin del if

