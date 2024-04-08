#include <stdio.h>
#include <string.h>

#define MAX_PALABRAS 5
#define MAX_LONGITUD 100

int main() {
    char palabras[MAX_PALABRAS][MAX_LONGITUD];
    int longitudes[MAX_PALABRAS];
    int max_longitud = 0;
    int max_indice = 0;

    // Solicitar al usuario que ingrese las palabras
    for (int i = 0; i < MAX_PALABRAS; i++) {
        printf("Ingresa la palabra %d: ", i + 1);
        fgets(palabras[i], MAX_LONGITUD, stdin);
        palabras[i][strcspn(palabras[i], "\n")] = '\0'; // Eliminar el salto de l�nea

        // Calcular la longitud de la palabra
        longitudes[i] = strlen(palabras[i]);

        // Actualizar la longitud m�xima y el �ndice correspondiente
        if (longitudes[i] > max_longitud) {
            max_longitud = longitudes[i];
            max_indice = i;
        }
    }

    // Imprimir la cadena m�s larga
    printf("La cadena m�s larga es: %s\n", palabras[max_indice]);

    return 0;
}

