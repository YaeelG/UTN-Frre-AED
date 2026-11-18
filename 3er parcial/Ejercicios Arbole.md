Clase 18/11/2026 (zoom)

# Ejercicios de arboles
(No entran en el parcial practica)

##  Ej8
Escribir una función recurasiva que encuentre la altura de un arbol binario (p: directo de la raiz(??))

Solución 1
```
Función altura (p: puntero a nodo): entero es
Ambiente
    Aizq, Ader: entero;
Proceso
    Si p <> NILL entonces
        Si (*P.izq = NILL) y (*P.der = NILL) entonces
            Altura := 1;
        Sino
            Aizq := Altura (*P.izq);
            Ader := Altura (*P.der);
            Si (Aizq > Ader) entonces
                Altura := Aizq + 1;
            sino
                Altura := Ader + 1
            Fin si;
        Fin si;
    sino
        Altura := 0
    Fin si;
Facción.
```

Solución 2
```
Función altura (p: puntero a nodo): entero es
Proceso
    Si (P <> NILL) entonces
        Si (*P.izq = NILL) y (*P.der = NILL) entonces
            Altura := 1
        Sino
            Si Altura(*P.izq) > Altura(*P.der) entonces
                Altura := Altura(*P.izq) + 1
            sino
                Altura := Altura(*P.der) + 1
            Fin si;
        Fin si;
    sino
        Altura := 0
    Fin si;
Fin acción
```