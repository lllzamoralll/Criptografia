# Cifrado César con Ñ y acentos (ASCII extendido)

Este programa implementa el Cifrado César en C, permitiendo el cifrado y descifrado de textos que incluyen la letra Ñ y vocales acentuadas en ASCII extendido.

## Requisitos

- Compilador de C (GCC recomendado)
- Sistema operativo con soporte para compilación en C (Windows, Linux o macOS)

## Compilación y Ejecución

### Compilar el código

Para compilar el código fuente, utiliza el siguiente comando en la terminal:

```sh
gcc cifradoCesar.c -o cifradoCesar
```

### Ejecutar el programa

Para ejecutar el programa, usa el siguiente comando:

```sh
./cifradoCesar
```

## Cómo usar el código

Al ejecutar el programa, se presentará un menú donde puedes elegir entre cifrar o descifrar un mensaje.

1. **Elige una opción:**
   - `1`: Cifrar un mensaje.
   - `2`: Descifrar un mensaje.
2. **Ingresa el texto:** Debe contener solo caracteres alfabéticos, incluidos `Ñ` y vocales acentuadas.
3. **Ingresa la llave:** Debe ser un número entre `1` y `31`. Este número define el desplazamiento en el cifrado César.
4. **Resultado:** El programa imprimirá el texto cifrado o descifrado según la opción seleccionada.

### **Probar cifrado**

1. Ejecutar el programa `./cifradoCesar`
2. Seleccionar la opción `1` (Cifrar)
3. Ingresar el texto, por ejemplo: `HOLA MUNDO`
4. Ingresar la llave, por ejemplo: `3`
5. Se mostrará el texto cifrado, por ejemplo: `KROD PXQGR`

### **Probar descifrado**

1. Ejecutar el programa `./cifradoCesar`
2. Seleccionar la opción `2` (Descifrar)
3. Ingresar el texto cifrado, por ejemplo: `KROD PXQGR`
4. Ingresar la misma llave usada en el cifrado, por ejemplo: `3`
5. Se mostrará el texto descifrado: `HOLA MUNDO`

## Notas

- Solo se cifran caracteres alfabéticos, incluyendo `Ñ` y vocales acentuadas.
- Los caracteres no alfabéticos permanecen sin cambios.
- La clave debe estar en el rango `1-31` para un correcto funcionamiento.
