#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int sonAnagramas(char *cadena1, char *cadena2) {
    int frecuencias[26] = {0};
    int i;

    // Convertir las cadenas a minúsculas
    for (i = 0; cadena1[i]; i++) {
        if (cadena1[i] >= 'A' && cadena1[i] <= 'Z') {
            cadena1[i] += 'a' - 'A';
        }
    }
    for (i = 0; cadena2[i]; i++) {
        if (cadena2[i] >= 'A' && cadena2[i] <= 'Z') {
            cadena2[i] += 'a' - 'A';
        }
    }

    // Eliminar los espacios en blanco y caracteres no alfabéticos
    int j = 0;
    for (i = 0; cadena1[i]; i++) {
        if ((cadena1[i] >= 'a' && cadena1[i] <= 'z')) {
            cadena1[j++] = cadena1[i];
        }
    }
    cadena1[j] = '\0';

    j = 0;
    for (i = 0; cadena2[i]; i++) {
        if ((cadena2[i] >= 'a' && cadena2[i] <= 'z')) {
            cadena2[j++] = cadena2[i];
        }
    }
    cadena2[j] = '\0';

    // Contar las frecuencias de caracteres en cadena1
    for (i = 0; cadena1[i]; i++) {
        frecuencias[cadena1[i] - 'a']++;
    }

    // Verificar si las frecuencias de caracteres en cadena2 coinciden
    for (i = 0; cadena2[i]; i++) {
        frecuencias[cadena2[i] - 'a']--;
    }

    // Si todas las frecuencias son cero, son anagramas
    for (i = 0; i < 26; i++) {
        if (frecuencias[i] != 0) {
            return 0; // No son anagramas
        }
    }

    return 1; // Son anagramas
}

int main() {
    char cadena1[MAX_LENGTH];
    char cadena2[MAX_LENGTH];

    printf("Ingresa la primera cadena de caracteres: ");
    fgets(cadena1, sizeof(cadena1), stdin);
    cadena1[strcspn(cadena1, "\n")] = '\0'; // Eliminar el salto de línea

    printf("Ingresa la segunda cadena de caracteres: ");
    fgets(cadena2, sizeof(cadena2), stdin);
    cadena2[strcspn(cadena2, "\n")] = '\0'; // Eliminar el salto de línea

    if (sonAnagramas(cadena1, cadena2)) {
        printf("Las cadenas '%s' y '%s' son anagramas.\n", cadena1, cadena2);
    } else {
        printf("Las cadenas '%s' y '%s' no son anagramas.\n", cadena1, cadena2);
    }

    return 0;
}

