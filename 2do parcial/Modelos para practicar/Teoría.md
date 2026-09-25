# Clasificaciones importante - TEORÍA

## Procesos (sobre Archivos)
- Individuales
- Múltiples

## Procesos MÚLTIPLES
Existe: 
- 2 o más **ficheros de entrada** y
- 1 o más **ficheros de Salida**

### Mezcla (o apareo)
- Directa: Mismo formato ambos regs, 
- Indirecta: distintos regs, 

### Actualización Secuencial
- Unitaria
- Por lotes   //"multiples novedades para un mismo número de equipos/id" 



## Procesos INDIVIDUALES
Existe:
- un unico **fichero de entrada** y
- 1 o ningún **fichero de salida**

### Genérico (Proceso de carga o generación)
Lectura secuencial simple y procesamiento/filtrado registro a registro.
Tiene como objetivo crear un archivo consistente y de ser posible, **congruente grueso**.

### Emisión
Su objetivo es la salida impresa de datos.
Generación e impresión de listados o padrones.

- Listadores: Se emite listados sin títulos.
- Padrones: Los datos ingresasdos están ordenados y se emiten totales finales 

### Estadístico
Recorrido del archivo para acumular/contabilizar datos en memoria interna (usando un arreglo/matriz) e imprimir en pantalla al final un cuadro de resumen.

[Procesos Estadísticos]

### Corte de control
Procesamiento de archivos ordenados por clave que agrupa registros y emite totales parciales y generales.

- Padrones, pero que poseen totales parciales. 
- El archivo de entrada debe estar ordenado por clave compleja

## Otras definiciones
### Consistencia: 
Un archivo es consistente cuando cada valor almacenado en un campo es válido de manera aislada según la definición de dicho campo.

Clasificación de la consistencia:
- **Consistencia automática:** La impone el propio sistema según el tipo de dato (por ejemplo, evitar que un campo definido como entero guarde texto).
- **Consistencia por rango o conjunto:** Validaciones adicionales definidas por el programador (por ejemplo, verificar que la edad esté entre 0 y 120, o el mes entre 1 y 12).

### Congruencia
Un archivo es congruente cuando los datos son coherentes entre sí. 
A diferencia de la consistencia, es una propiedad relacional que requiere comparar dos o más datos.

Clasificación de la congruencia:
- **Congruencia gruesa:** Coherencia entre datos del **mismo registro** (por ejemplo, la fecha 31/02/1990 no es congruente porque febrero no tiene 31 días).
- **Congruencia fina:** Coherencia entre datos de **distintos archivos** (por ejemplo, un DNI registrado en el archivo ALUMNOS que no exista en el archivo PADRÓN ELECTORAL).

### Reglas de relación entre CONGRUENCIA Y CONSISTENCIA

1. Si un dato **NO es consistente**, tampoco puede ser congruente.
2. Que un dato **sea consistente NO garantiza** que sea congruente (el día 31 es consistente en el rango 1-31, pero no es congruente con el mes de febrero).



# BÚSQUEDA Y ORDENAMIENTO

## ORDENAMIENTO

### Burbuja 
- es el método más simple de entender e implementar.
- Compara pares de elementos adyacentes.

Version mejorada, con bandera:
``` 
i := 1;
hubo_cambio := VERDADERO;
MIENTRAS (i<=n-1) Y (hubo_cambio) HACER
	hubo_cambio := FALSO;
	PARA j:=1 HASTA n-i HACER
		SI v[j] > v[j+1] ENTONCES
			aux := v[j];
			v[j] := v[j+1];
			v[j+1] := aux;
			hubo_cambio := VERDADERO;
		FIN_SI;
	FIN_PARA;
i := i+1;
FIN_MIENTRAS;
``` 


### Selección
- Busca el mínimo y lo coloca en la posición final, con un único intercambio.
- o podemos buscar el máximo utilizando la misma lógica.

``` 
Acion SELECCION (v: arreglo [1..n] de entero) ES;
	Ambiente
		i, j, pos_min, aux: entero;

	Proceso
		PARA i:=1 HASTA n-1 HACER
			pos_min := i;

			PARA j:=i+1 HASTA n HACER
				SI v[j] < v[pos_min] ENTONCES
					pos_min := j;
				FIN_SI;
			FIN_PARA;

			SI pos_min <> i ENTONCES
				aux := v[i];
				v[i] := v[pos_min];
				v[pos_min] := aux;
			FIN_SI;
		FIN_PARA;
FinAccion
``` 

### Inserción
- Construye el arreglo ordenado de a poco
- toma cada elemento y lo inserta en su posición correcta dentro de la porción ya ordenada, desplazando los mayores a la derecha.

``` 
Accion INSERCION (v: arreglo [1..n] de entero) ES;
	Ambiente
		i, j, aux: entero;

	Proceso
		PARA i:=2 HASTA n HACER
			aux := v[i];
			j := i-1;

			MIENTRAS (j>=1) Y (v[j]>aux) HACER
				v[j+1] := v[j];
				j := j-1;
			FIN_MIENTRAS;

			v[j+1] := aux;
		FIN_PARA;
FinAccion.
``` 

## BÚSQUEDA

### Secuencial
- Recorre el arreglo desde el principio, comparando cada elemento con el valor buscado, hasta encontrarlo o llegar al final. 
- No requiere que el arreglo esté ordenado.

Accion BUSCAR_SECUENCIAL (v: arreglo [1..n] de entero) ES;
	Ambiente
	buscado, i: entero;
	Proceso
	LEER(buscado);
	PARA i := 1 HASTA n HACER
	SI v[i] = buscado ENTONCES
	Escribir("Encontrado en la posición: ", i);
	FIN_SI;
	FIN_PARA;
FinAccion.