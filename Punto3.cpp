#include <stdio.h>
#include <string.h>
int esPalindromo(char *cadena) {
    int longitud = strlen(cadena);
    int i, j;

    // Convertir la cadena a minúsculas
    for (i = 0; cadena[i]; i++) {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            cadena[i] += 'a' - 'A';
        }
    }

    // Eliminar los espacios en blanco y caracteres no alfanuméricos
    j = 0;
    for (i = 0; cadena[i]; i++) {
        if ((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= '0' && cadena[i] <= '9')) {
            cadena[j++] = cadena[i];
        }
    }
    cadena[j] = '\0'; // Agregar el carácter nulo al final

    // Verificar si es palíndromo
    for (i = 0, j = strlen(cadena) - 1; i < j; i++, j--) {
        if (cadena[i] != cadena[j]) {
            return 0; // No es palíndromo
        }
    }

    return 1; // Es palíndromo
}

int main() {
    char cadena[100];
    printf("Ingresa una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin); // Leer la cadena

    if (esPalindromo(cadena)) {
        printf("La cadena '%s' es un palindromo.\n", cadena);
    } else {
        printf("La cadena '%s' no es un palindromo.\n", cadena);
    }
    return 0;
}

