#include <stdio.h>

int main() {
    char nombre[100]; // Declarar un arreglo para almacenar el nombre

    printf("Ingresa tu nombre: ");
    scanf("%s", nombre); // Leer el nombre ingresado por el usuario

    printf("Hola, %s\n", nombre); // Imprimir el nombre

    return 0;
}

