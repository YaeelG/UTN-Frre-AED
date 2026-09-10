	[ Clase 08/07/2026 ]

# Actualización Secuencial por Lotes
``` 
// Ciclo excluyente
	mientras arch1 y arch2
	
	si arch1 
	si arch2 
	
// Ciclo excluyente
	mientras (reg_mae.clave <> HV) o (reg_mae.clave <> HV)
		si
		si
``` 
	
## Actualizacion secuencial
- Archivos secuenciales solo puedo abrir en modo lectura, no puedo escribir.
	Arch entrada: maestro, movimientos
	arch ssalida: maestro actualizado
	Tipos movimientos: altas, bajas, modificaciones
	
## Tipos de act:
	 - Unitaria: 
	 - Por lotes: el arch de mae y de movimientos deben tener clave y estar ordenados.
				Varias modificaciones - una baja
				Alta - varias modificaciones
				Alta
				Siempre en ese orden, siempre las altas primeros.
				Baja una sola baja lógica o física(desaparece el registro, no lo escribo en el maestro actualizado)
				
				``` 
				R_mae = registro
					clave: 
						campo1
						campo2
						campo3
						marca_baja
				fin_reg
				``` 
				
				"fichero maestro" = "archivo maestro"
				
				"Maestro sin movimientos": avancé y resulta que el maestro no registra movimientos parar el maestro actual(sí para el siguiente).
				
				// PPT drive practica hay ejemplos de como trabajar con esto. Ejemplo de qué hacer cuando el maestro es menor que movimiento.
				
				
## Estructura
``` 
Accion Actualiación_Lotes es
	AMBIENTE
		...
	PROCESO
		Abrir_archivos()
		Leer_Maestro()
		Leer_Movimiento()

		Mientras (reg_mae.clave <> HV) o (reg_mov.clave <> HV) hacer
			Si (reg_mae.clave < reg_mov.clave) entonces
				reg_sal := reg_mae
				Escribir(mae_sal, reg_sal)
				Leer_Maestro()
			Sino
				Si (reg_mae.clave = reg_mov.clave) entonces
					aux := reg_mae

					Mientras (reg_mae.clave = reg_mov.clave) hacer
						Proceso_Movim()
						Leer_Movimiento()
					Fin_mientras

					reg_sal := aux

					Escribir(mae_sal, reg_sal)
					
					Leer_Maestro()

				Sino
					aux.clave := reg_mov.clave
					aux.campo1 := reg_mov.campo1
					aux.campo2 := reg_mov.campo2
					...
					aux.campoN := reg_mov.campoN
					aux.Marca_baja := ""

					Leer_Movimiento()

					Mientras (aux.clave = reg_mov.clave) hacer
						Proceso_Movim()
						Leer_Movimiento()
					Fin_Mientras

					reg_sal := aux

					Escribir(mae_sal, reg_sal)
				Fin_si
			fin_si
		Fin_mientras
		
		Cerrar(mae)
		Cerrar(mov)
		Cerrar(mae_sal)
Fin_accion
``` 


## Procedimientos
``` 
Procedimiento Proceso_modif_maestro es
	Si reg_mov.campo1 <> "" entonces 
		aux.campo1 := reg_mov.campo1
	Fin_si

	Si reg_mov.campo2 <> "" entonces 
		aux.campo2 := reg_mov.campo2
	Fin_si

	...

	Si reg_mov.campoN <> "" entonces 
		aux.campoN := reg_mov.campoN
	Fin_si
Fin_Procedeimiento
``` 

``` 
Procedimiento Marcar_registro es
	aux.marca_baja := "*"    //o podemos asignar una fecha o cualquier otro dato
Fin_Procedimiento
``` 
			
	
https://youtu.be/9guq11_WVkE?si=eisDF49GrxPApLV-
