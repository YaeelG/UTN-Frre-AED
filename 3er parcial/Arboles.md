# Arboles

- vocabulario, partes del arbol


## Ordenes
### Pre orden - RID
``` 
Procedimiento PreOrden (p: puntero a nodo)
	Si p <> nil entonces
		Escribir(*p.dato)
		PreOrden(*p.izq)
		PreOrden(*p.der)
	fin_si
fin Procedimiento
``` 

### Post orden - IDR
``` 
Procedimiento PostOrden (p: puntero a nodo)
	Si p <> nil entonces
		PreOrden(*p.izq)
		PreOrden(*p.der)
		Escribir(*p.dato)
	fin_si
fin Procedimiento
``` 

### En orden - IRD
``` 
Procedimiento PostOrden (p: puntero a nodo)
	Si p <> nil entonces
		PreOrden(*p.izq)
		Escribir(*p.dato)
		PreOrden(*p.der)
	fin_si
fin Procedimiento
``` 

## Ejemplo contar nodos
``` 
Función Contar (p: puntero a nodo): entero
	Si p = nil entonces
		Contar := 0
	Sino
		Contar := 1 + Contar(*p.izq) + Contar(*p.der)
Fin_funcion
``` 



# Ejercicio 5.3.12

El recorrido en pre-orden de un determinado árbol binario es: GEAIBMCLDFKJH y en-orden IABEGLDCFMKHJ.

- Dibujar el árbol binario.
- Dar el recorrido en post-orden.
- Diseñar un algoritmo para recorrer el árbol en post-orden.

PreOrden RID
G EAIBMCLDFKJH

EnOrden IRD
IABE G LDCFMKHJ      

Raiz: G


Verif:   IABE=G=LDC=F==KHJ=

[ FOTO ]

