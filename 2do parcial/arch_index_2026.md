# Archivos indexados
- Clase 12/08/2026

# Visualización física
- área pprincipal, donde están los datos (Clave | Dato)
- área de indices, ordenada por clave de archivo (Clave|dirección)
- 

# Ambiente
``` 
	Accion lalal es
	Ambiente
		DATO = reg
			CLAVE: ...
			campos: ...
			...
		fin_reg
	
		Arch: Archivo de DATO INDEXADO por clave...
		reg: DATO
```

# Proceso
ABRIR E/S (variable)

Si el enunciado pide:
- "Modificación del archivo":  Entrada y Salida
- "Tomar datos del arch indexado":  Entrada

## Acceder a los registros
Consulta a indice, a dato del registro.
```
reg.CLAVE := valor

leer(Arch, reg)

si existe entonces
	[accion por éxito de búsqueda]
sino
	[accion por búsqueda fallida]
fin_si
```

**[ i ]** Primero se comprueba de que exista el registro.

## Acciones sobre el registro
- Eliminar(arch, reg): baja física. 
- Escribir(Arch, reg): Escribir
- Reescribir(Arch, reg): Escribir, modificaciones a campos