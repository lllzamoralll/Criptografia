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

const int LONGITUD_ALFABETO = 32;

int codificarCaracter(unsigned char c) {
    for (int i = 0; i < LONGITUD_ALFABETO; i++) {
        if (ALFABETO_MAY[i] == c || ALFABETO_MIN[i] == c) {
            return i;
        }
    }
    return -1;
}

unsigned char decodificarPosicion(int pos, int esMayuscula) {
    if (pos < 0 || pos >= LONGITUD_ALFABETO) return '?';
    return esMayuscula ? ALFABETO_MAY[pos] : ALFABETO_MIN[pos];
}

void cifrarVigenere(unsigned char texto[], unsigned char clave[], unsigned char resultado[]) {
    int i, j = 0, codificacion, claveCodificacion, nuevaPosicion;
    int claveLongitud = strlen((char*)clave);
    
    for (i = 0; texto[i] != '\0'; i++) {
        codificacion = codificarCaracter(texto[i]);
        claveCodificacion = codificarCaracter(clave[j % claveLongitud]);
        
        if (codificacion != -1 && claveCodificacion != -1) {
            nuevaPosicion = (codificacion + claveCodificacion) % LONGITUD_ALFABETO;
            resultado[i] = decodificarPosicion(nuevaPosicion, (texto[i] >= 'A' && texto[i] <= 'Z') || texto[i] == 165 || texto[i] == 181 || texto[i] == 144 || texto[i] == 214 || texto[i] == 224 || texto[i] == 233);
            j++;
        } else {
            resultado[i] = texto[i];
        }
    }
    resultado[i] = '\0';
}

void descifrarVigenere(unsigned char texto[], unsigned char clave[], unsigned char resultado[]) {
    int i, j = 0, codificacion, claveCodificacion, nuevaPosicion;
    int claveLongitud = strlen((char*)clave);
    
    for (i = 0; texto[i] != '\0'; i++) {
        codificacion = codificarCaracter(texto[i]);
        claveCodificacion = codificarCaracter(clave[j % claveLongitud]);
        
        if (codificacion != -1 && claveCodificacion != -1) {
            nuevaPosicion = (codificacion - claveCodificacion + LONGITUD_ALFABETO) % LONGITUD_ALFABETO;
            resultado[i] = decodificarPosicion(nuevaPosicion, (texto[i] >= 'A' && texto[i] <= 'Z') || texto[i] == 165 || texto[i] == 181 || texto[i] == 144 || texto[i] == 214 || texto[i] == 224 || texto[i] == 233);
            j++;
        } else {
            resultado[i] = texto[i];
        }
    }
    resultado[i] = '\0';
}

int main() {
    unsigned char texto[MAX_LENGTH];
    unsigned char clave[MAX_LENGTH];
    unsigned char resultado[MAX_LENGTH];
    int opcion;

    printf("=== Cifrado Vigenère con Ñ y acentos (ASCII extendido) ===\n");
    printf("1. Cifrar\n");
    printf("2. Descifrar\n");
    printf("Seleccione una opción (1 o 2): ");
    scanf("%d", &opcion);
    getchar(); 

    printf("Ingrese el texto: ");
    fgets((char*)texto, MAX_LENGTH, stdin);
    texto[strcspn((char*)texto, "\n")] = 0; 

    printf("Ingrese la clave (solo letras): ");
    fgets((char*)clave, MAX_LENGTH, stdin);
    clave[strcspn((char*)clave, "\n")] = 0;

    if (opcion == 1) {
        cifrarVigenere(texto, clave, resultado);
        printf("\nTexto cifrado: %s\n", resultado);
    } else if (opcion == 2) {
        descifrarVigenere(texto, clave, resultado);
        printf("\nTexto descifrado: %s\n", resultado);
    } else {
        printf("Opción inválida\n");
    }

    return 0;
}
