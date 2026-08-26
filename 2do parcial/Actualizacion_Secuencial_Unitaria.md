# Actualizacion Secuencial Unitaria 
https://youtu.be/e9MB-YY6JBc?list=PLizIqQiDw5tc2nKPdIy7kJvdys_OZnVX5&t=3019

[Corte de control era un PROCESO INDIVIDUAL, tenemos 1 archivo de entrada]


## Procesos Múltiples
- Existen 2 o más archivos de entrada.
- 1 o más archivos de salida.

### Mezcla
- Directa
- Indirecta

### Actualización
Archivo Maestro y Archivo Movimientos (Altas, Bajas, Modificaciones)
- Unitaria / 
- Por lotes / 

## Ciclos de Apareo  (Procesos Múltiples)

### Excluyente
Ideal para 2 archivos, pero si tengo 3 o más significa que tengo varios ciclo, se me alarga demasiado el código.

``` 
Mientras NFDA (Arch1) y NFDA(Arch2) hacer
    PRoceso de registros comunes
Fin_mientras

Mientras NFDA(Arch1) hacer       //Este ciclo para un arch de entrada
    Proceso de Registros del Arch1
Fin_mientras

Mientras NFDA(Arch2) hacer      //Este ciclo para el otro arch de entrada
    Proceso de registros del Arch2
Fin_mientras
``` 
Conector: YYYYYY

### Incluyente
Definimos procedimientos para leer archivos.
Asignamos al campo clave un valor muy alto(HV), los registros se encuentran en RAM/Mem interna así que puedo utilizarlos como si fueran variables.

Vamos comparando las claves, al llegar al fin de Archivo me quedo sin clave y salgo del bbucle principal.


``` 
Procedimiento Leer_Arch1 es
    Leer(Arch1, Reg1)

    Si FDA(Arch1) entonces
        Reg1.Clave1 := HV
    Fin_si 
Fin_procedimiento
``` 

``` 
Mientras (Clave1 <> HV) o (Clave2 <> HV) o ... (ClaveN <> HV) hacer
    Proceso
F_mientras

``` 

Conector: OOOOOO  


``` 
// si Clave1 ya se le asignó HV entonces el siguiente, Clave2 en este momento puede seguir siendo su valor original que es distinto de HV.

Mientras (Clave1 <> HV) o (Clave2 <> HV) o ... (ClaveN <> HV) hacer
    Proceso
F_mientras
``` 


#### Actualización Unitaria (Ciclo Incluyente)

``` 
Accion Actualización_Unitaria es
AMBIENTE
    ...

    Procedimiento LeerMAE es
        ...
    Fin_procedimiento

    Procedimiento LeerMOV es
        ...
    Fin_procedimiento

PROCESO
    // Abrir archivos
    Abrir(ArchMAE)
    Abrir(ArchMOV) 

    // Leerlos
    LeerMAE  //Maestro
    LeerMOV() // Movimiento

    Mientras (Clave_MAE <> HV) o (Clave_MOV <> HV) hacer
        Si (Clave_MAE < Clave_MOV) entonces
            Reg_sal := Reg_MAE

            Escribir(Arch_sal, Reg_sal)
            LeerMAE()

        Sino
            Si (Clave_MAE = Clave_MOV) entonces 
                // Procesos iguales
            Sino
                // Procesos distintos
            Fin_si
        Fin_si
    Fin_mientras

    Cerrar(ArchMAE)
    Cerrar(ArchMOV) 
Fin_Accion
``` 

- Procesos iguales
``` 
Procedimiento Proceso_Iguales es
    Si Reg_MOV.Cod_MOV = 'ALTA' entonces           // Alta
        ESCRIBIR('Error: No se puede hacer alta')

        Reg_sal := Reg_mae
        ESCRIBIR(Arch_sal, Reg_sal)
    Sino
        Si (Reg_mov.Cod_mov = 'MODIF') entonces    // Modificación
            Proceso_Mod_Maestro()

            Reg_sal := Reg_MAE

            ESCRIBIR(Arch_sal, Reg_sal)
        Sino                                       // Baja, Eliminación lógica
            Reg_sal := Reg_MAE
            Marcar_Registro()

            ESCRIBIR(Arch_sal, Reg_sal)

            // Si fuera Eliminación Física simplemente no lo copio a la salida, este sino no se colocarias
        Fin_si
    Fin_si

    Leer_Maestro
    Leer_Movimiento
Fin_Procedimiento
``` 

- Procesos distintos
``` 
Procedimiento Proceso_Iguales es
    Si Reg_MOV.Cod_MOV = 'BAJA' entonces           // Baja
        ESCRIBIR('Error: No se puede dar de baja')
    Sino
        Si (Reg_mov.Cod_mov = 'MODIF') entonces    // Modificación
            ESCRIBIR('Error, no se puede modificar')

        Sino                                       // Alta
            // Asigna campo por campo. Reg_sal y Reg_MOV tienen distinto formato, distinta estructura, distintos campos.
            Reg_sal.Clave := Reg_MOV.Clave
            Reg_sal.campo1 := Reg_MOV.campo1
            Reg_sal.campo2 := Reg_MOV.campo2
            ...
            Reg_sal.campoN := Reg_MOV.campoN
            Reg_sal.Marca_baja := ''

            ESCRIBIR(Arch_sal, Reg_sal)
        Fin_si
    Fin_si

    Leer_Movimiento   // porque es la que tiene la clave menor
Fin_Procedimiento
``` 


