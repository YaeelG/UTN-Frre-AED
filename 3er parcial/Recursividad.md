	[ Clase 28/10/2026 ]

# Recursividad
	- Caso base
	- Caso recursivo

	- No usamos ciclos(mientras, para, repetir), porque eso ya nos saca de recursividad y lo vuelve iterativo.

## Ejemplo Factorial

### Iterativo
``` 
ACCION factorial es
	leer(n)
	fact:= 1

	Para i := 1 es
	 ...
``` 

### Recursivo
```
Accion Factorial(n: entero): entero es
	si n=0 ent
	 factorial := 1
	contrario
		factorial := n * factorial(n-1)
	Fin_si
Fin_acción
``` 

factorial(4)
4 * fatorial(3)
3 * factorial(2)
2 * factorial(1)
1 * factorial(0)
y entonces comienzan a desapilarse las llamadas recursivas


## Ejemplo ppt - longitud de una lista
``` 
Funcion longlista (r: punt a nodo): Entero es
	Si r = Nil entonces
		LongLista := 0
	Sino
		r := *r.prox
		LongLista := 1 + LongLista(r)
	Fin_si
Fin_funcion
``` 

## Ejemplo ppt - sumatoria de los números que van de x a y, incluidos los extremos
``` 
Funcion Sumatoria (x, y: entero): entero es
	Si x = y entonces
		sumatoria := x 
	Sino
		Si x > y entonces
			sumatoria := 0
		Sino
			Sumatoria := x + Sumatoria(x+1, y)
		Fin_si
	Fin_si
Fin_funcion
``` 

## Ejemplo - Determinar si los dígitos de un num n dado son todos pares

Casos bases:
- falso: n mod 2 <> 0
- verdadero: n mod 2 = 0  y  n < 10

Caso Recursivo:
- todospares(n div 10)  n mod 2 = 0  y  n >= 10

``` 
Funcion todoDigitospares(n: entero): lógico es
	Si n mod 2 <> 0 entonces
		todoDigitospares := falso
	Sino	
		Si n < 10 entonces
			todoDigitospares := verdadero
		Sino
			todoDigitospares := todoDigitospares(n div 10)
		Fin_si
	Fin_si
Fin_funcion
``` 

