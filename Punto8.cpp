#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void convertirMayusculas(char *str);
void convertirMinusculas(char *str);
void alternarMayusculasMinusculas(char *str);
void capitalizarPalabras(char *str);

int main() {
    char oracion[MAX_LENGTH];
    int opcion;

    printf("Ingresa una oracion: ");
    fgets(oracion, MAX_LENGTH, stdin);
    oracion[strcspn(oracion, "\n")] = '\0'; // Eliminar el salto de línea

    printf("\nSelecciona una opción:\n");
    printf("a) Mostrar la oración toda en mayuscula\n");
    printf("b) Mostrar la oración toda en minuscula\n");
    printf("c) Mostrar la oración alternando una mayuscula y una minuscula\n");
    printf("d) Mostrar la oración comenzando todas las palabras con mayuscula\n");
    printf("Opcion: ");
    scanf(" %c", &opcion);

    switch (opcion) {
        case 'a':
            convertirMayusculas(oracion);
            printf("Oracion en mayusculas: %s\n", oracion);
            break;
        case 'b':
            convertirMinusculas(oracion);
            printf("Oracion en minusculas: %s\n", oracion);
            break;
        case 'c':
            alternarMayusculasMinusculas(oracion);
            printf("Oracion alternando mayusculas y minusculas: %s\n", oracion);
            break;
        case 'd':
            capitalizarPalabras(oracion);
            printf("Oracion con todas las palabras capitalizadas: %s\n", oracion);
            break;
        default:
            printf("Opcion invalida.\n");
    }

    return 0;
}

void convertirMayusculas(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

void convertirMinusculas(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

void alternarMayusculasMinusculas(char *str) {
    int alternador = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (alternador % 2 == 0) ? str[i] - 32 : str[i];
            alternador++;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (alternador % 2 == 0) ? str[i] : str[i] + 32;
            alternador++;
        }
    }
}

void capitalizarPalabras(char *str) {
    int esNuevaPalabra = 1;
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (esNuevaPalabra) ? str[i] - 32 : str[i];
            esNuevaPalabra = 0;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (esNuevaPalabra) ? str[i] : str[i] + 32;
            esNuevaPalabra = 0;
        } else {
            esNuevaPalabra = 1;
        }
    }
}
