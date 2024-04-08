#include <stdio.h>
#include <string.h>

void reemplazarCaracter(char *cadena, char caracterBuscar, char caracterReemplazar) {
    int i;
    for (i = 0; cadena[i]; i++) {
        if (cadena[i] == caracterBuscar) {
            cadena[i] = caracterReemplazar;
        }
    }
}

int main() {
    char cadena[100];
    char caracterBuscar, caracterReemplazar;

    printf("Ingresa una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin); // Leer la cadena

    printf("Ingresa el car�cter a buscar: ");
    scanf(" %c", &caracterBuscar); // Leer el car�cter a buscar

    printf("Ingresa el car�cter de reemplazo: ");
    scanf(" %c", &caracterReemplazar); // Leer el car�cter de reemplazo

    reemplazarCaracter(cadena, caracterBuscar, caracterReemplazar);

    printf("La cadena resultante es: %s\n", cadena);

    return 0;
}

