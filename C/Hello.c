#include <stdio.h>

// Función principal
int main(void)
{
    char respuesta[100];

    printf("Cual es tu nombre? : ");

    if (fgets(respuesta, sizeof(respuesta), stdin) != NULL)
    {
        // Buscamos manualmente el salto de línea y lo reemplazamos por el terminador nulo. Así el nombre no se guardará como "Juan\n"(salto de linea del enter) sino solo "Juan".
        for (int i = 0; respuesta[i] != '\0'; i++)
        {
            if (respuesta[i] == '\n')
            {
                respuesta[i] = '\0';
                break;
            }
        }
    }

    printf("Hola, %s\n", respuesta);

    getchar(); // para que no me cierre el .exe inmediatamente

    return 0;
}

/*
 - Generar el .exe
    gcc ./C/Hello.c -o ./C/Hello

 - char respuesta[100];
    Arreglo para almacenar el nombre (hasta 99 caracteres)
    . 99 espacios quedan disponibles para las letras de lo que escribas (incluyendo espacios en blanco).
    . 1 espacio (el final) siempre se reserva para el '\0'.

 - fgets
    Función estándar de C (File Get String) diseñada para leer una línea o cadena de texto de un flujo de datos de forma segura.

 - respuesta
    Es el arreglo de caracteres (el buffer) que creamos antes.

 - sizeof
    Operador de C que calcula el tamaño total (en bytes) que ocupa una variable o tipo de dato en la memoria.

 - stdin
    Abreviatura de Standard Input (Entrada Estándar). Es un flujo predefinido que representa el teclado. Le indica a fgets de dónde debe leer los datos.

*/