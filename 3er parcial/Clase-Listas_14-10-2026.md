	[ Clase 08/07/2026 ]


- Preguntamos por P <> NIL
``` 
*P.prox <> NIL

``` 
  
# Cronograma - Última etapa
- Octubre:
  	- [07/10] Listas simples, carga apilada, encolada, ordenada
  	- [14/10] Listas circulares
  	- [21/10] Listas dobles
  	- [28/10] Recursividad
  
- Noviembre:
  	- [04/10] Recursividad - Arboles
  	- [11/11] Arboles - Repaso
  	- [18/11] 3er Parcial 
  	- [25/11] Repaso
  
- Diciembre:
  	- [02/12] Recuperatorio 2do Parcial
  	- [05/12] Fin 2do cuatrimetre


# Listas Simples - Eliminación
4 casos
- Único nodo
- 1er nodo
- En el medio
- Último nodo 

## Buscar el valor
``` 
Leer(valor)

P := Prim
Ant := NIL

Mientras (P <> NIL) Y (*P.Dato <> valor) hacer
	Ant := P
	P := *P.prox
Fin_mientras
``` 

## 1. Único nodo
``` 
// CONDICIÓN P = prim y *P.prox = NIL 
Prim := NIL
Disponer(P)
``` 

## 2. Primer Nodo
``` 
// CONDICIÓN P = prim 
Prim := *P.prox
DISPPONER(P)
``` 

## 3. En el medio
``` 
// CONDICIÓN *P.Dato = valor (con Ant<>NIL, P<>Último)
*Ant.prox := *P.prox
DISPPONER(P)
``` 

## 4. Último Nodo
``` 
// CONDICIÓN *P.prox = NIL
*Ant.prox := NIL
DISPONER(P)
``` 

## ALGORITMO ELIMINACIÓN completo
``` 
Leer(valor)
P := Prim
Ant := NIL

Mientras (P <> NIL) y (*P.Dato <> valor)    //BUSCAR
	Ant := P
	P := *P.prox
Fin_mientras


Si (P = NIL) entonces
	Escribir("Error el valor no existe")
	
Sino
	Si (Ant = NIL) entonces
		Prim := *P.prox            //Casos 1 o 2
	Sino	
		*Ant.prox := *P.prox       //Casos 3 o 4
	Fin_si

	DISPONER(P)             
Fin_si
``` 