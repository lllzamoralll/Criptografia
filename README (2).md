# Cifrado Vigenère con Ñ y acentos (ASCII extendido)

Este programa implementa el **Cifrado Vigenère** en C, permitiendo el cifrado y descifrado de textos que incluyen la letra **Ñ** y vocales acentuadas en **ASCII extendido**.

## Requisitos

- **Compilador de C** (GCC recomendado)
- **Sistema operativo** con soporte para compilación en C (Windows, Linux o macOS)

## Compilación y Ejecución

### Compilar el código

Para compilar el código fuente, utiliza el siguiente comando en la terminal:

```sh
gcc cifradoVigenere.c -o cifradoVigenere
```

### Ejecutar el programa

Para ejecutar el programa, usa el siguiente comando:

```sh
./cifradoVigenere
```

## Cómo usar el programa

Al ejecutar el programa, se presentará un menú donde puedes elegir entre **cifrar o descifrar un mensaje**.

1. **Elige una opción:**
   - `1`: **Cifrar un mensaje**.
   - `2`: **Descifrar un mensaje**.
2. **Ingresa el texto:** El texto puede contener caracteres alfabéticos, incluyendo `Ñ` y vocales acentuadas.
3. **Ingresa la clave:** Debe ser una palabra o frase. La clave se repetirá cíclicamente sobre el texto para cifrarlo.
4. **Resultado:** El programa imprimirá el **texto cifrado o descifrado** según la opción seleccionada.

### **Ejemplo de cifrado**

1. Ejecutar el programa `./cifradoVigenere`
2. Seleccionar la opción `1` (**Cifrar**)
3. Ingresar el texto: `HOLA MUNDO`
4. Ingresar la clave: `SOL`
5. Se mostrará el texto cifrado, por ejemplo: `ZÓVS ÁAARZ`

### **Ejemplo de descifrado**

1. Ejecutar el programa `./cifradoVigenere`
2. Seleccionar la opción `2` (**Descifrar**)
3. Ingresar el texto cifrado: `ZÓVS ÁAARZ`
4. Ingresar la misma clave usada en el cifrado: `SOL`
5. Se mostrará el texto descifrado: `HOLA MUNDO`

## Notas

- **Solo se cifran caracteres alfabéticos**, incluyendo `Ñ` y vocales acentuadas.
- **Los caracteres no alfabéticos** permanecen sin cambios.
- **La clave debe ser una palabra o frase**, evitando números o caracteres especiales para un correcto funcionamiento.
- **El cifrado Vigenère es más seguro** que el César, ya que usa una clave variable en lugar de un desplazamiento fijo.
