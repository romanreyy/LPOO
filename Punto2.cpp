#include <stdio.h>
#include <string.h>

int contarVocales(char *cadena) {
    int contador = 0;
    int i;

    for (i = 0; cadena[i] != '\0'; i++) {
        char c = cadena[i];
        if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A'; // Convertir a minúscula
        }
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }

    return contador;
}

int main() {
    char cadena[100];

    printf("Ingresa una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin); // Leer la cadena

    int numVocales = contarVocales(cadena);

    printf("La cadena '%s' tiene %d vocales.\n", cadena, numVocales);

    return 0;
}

