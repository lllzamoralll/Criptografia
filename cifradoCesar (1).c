#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

// Definir el alfabeto con valores ASCII extendidos manualmente
const unsigned char ALFABETO_MAY[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 165, 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 181, 144, 214, 224, 233
};
const unsigned char ALFABETO_MIN[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 164, 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 160, 130, 161, 162, 163
};

// Definir el tamaño correcto del alfabeto (27 + 5 vocales acentuadas = 32)
const int LONGITUD_ALFABETO = 32;

// Función para encontrar la posición en el alfabeto
int codificarCaracter(unsigned char c) {
    for (int i = 0; i < LONGITUD_ALFABETO; i++) {
        if (ALFABETO_MAY[i] == c || ALFABETO_MIN[i] == c) {
            return i; // Retorna el índice correcto de la letra en el alfabeto
        }
    }
    return -1; // Carácter no encontrado
}

// Función para obtener la letra desde una posición
unsigned char decodificarPosicion(int pos, int esMayuscula) {
    if (pos < 0 || pos >= LONGITUD_ALFABETO) return '?'; // Evitar errores en índices inválidos
    return esMayuscula ? ALFABETO_MAY[pos] : ALFABETO_MIN[pos];
}

// Función para cifrar con César
void cifrarCesar(unsigned char texto[], int llave, unsigned char resultado[]) {
    int i, codificacion, nuevaPosicion;

    for (i = 0; texto[i] != '\0'; i++) {
        codificacion = codificarCaracter(texto[i]);
        if (codificacion != -1) {
            nuevaPosicion = (codificacion + llave) % LONGITUD_ALFABETO;
            resultado[i] = decodificarPosicion(nuevaPosicion, (texto[i] >= 'A' && texto[i] <= 'Z') || texto[i] == 165 || texto[i] == 181 || texto[i] == 144 || texto[i] == 214 || texto[i] == 224 || texto[i] == 233);
        } else {
            resultado[i] = texto[i]; // Mantener caracteres no alfabéticos
        }
    }
    resultado[i] = '\0';
}

// Función para descifrar con César
void descifrarCesar(unsigned char texto[], int llave, unsigned char resultado[]) {
    int i, codificacion, nuevaPosicion;

    for (i = 0; texto[i] != '\0'; i++) {
        codificacion = codificarCaracter(texto[i]);
        if (codificacion != -1) {
            nuevaPosicion = (codificacion - llave + LONGITUD_ALFABETO) % LONGITUD_ALFABETO;
            resultado[i] = decodificarPosicion(nuevaPosicion, (texto[i] >= 'A' && texto[i] <= 'Z') || texto[i] == 165 || texto[i] == 181 || texto[i] == 144 || texto[i] == 214 || texto[i] == 224 || texto[i] == 233);
        } else {
            resultado[i] = texto[i]; // Mantener caracteres no alfabéticos
        }
    }
    resultado[i] = '\0';
}

// Función principal
int main() {
    unsigned char texto[MAX_LENGTH];
    unsigned char resultado[MAX_LENGTH];
    int llave;
    int opcion;

    printf("=== Cifrado César con Ñ y acentos (ASCII extendido) ===\n");
    printf("1. Cifrar\n");
    printf("2. Descifrar\n");
    printf("Seleccione una opción (1 o 2): ");
    scanf("%d", &opcion);
    getchar(); // Consumir el salto de línea residual

    printf("Ingrese el texto: ");
    fgets((char*)texto, MAX_LENGTH, stdin);
    texto[strcspn((char*)texto, "\n")] = 0; // Eliminar el salto de línea

    // Validar la llave para que esté en el rango correcto
    do {
        printf("Ingrese la llave (1-31): ");
        scanf("%d", &llave);

        if (llave < 1 || llave > 31) {
            printf("Error: La llave debe estar entre 1 y 31.\n");
        }
    } while (llave < 1 || llave > 31); // Bucle hasta que la llave sea válida

    if (opcion == 1) {
        cifrarCesar(texto, llave, resultado);
        printf("\nTexto cifrado: %s\n", resultado);
    } else if (opcion == 2) {
        descifrarCesar(texto, llave, resultado);
        printf("\nTexto descifrado: %s\n", resultado);
    } else {
        printf("Opción inválida\n");
    }

    return 0;
}
