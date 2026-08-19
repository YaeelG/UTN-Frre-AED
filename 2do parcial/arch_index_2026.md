# Archivos indexados
- Clase 12/08/2026

# Visualización física
- área condetenidos
- área de indices
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
	
		Arch: Archivo de DATO *indexado* por clave...
		reg: DATO
```

# Proceso
ABRIR E/S (variable)

## Acceder a los registros
Consulta a indice, a dato del registro.
```
reg.CLAVE := valor

leer(Arch, reg)

si existe entonces
 [accion por exito de busqueda]
sino
	[accion]
fin_si
```

## Acciones sobre el registro
- Eliminar(arch, reg): baja física
- Escribir(Arch, reg): Escribir
- Reescribir(Arch, reg): Escribir