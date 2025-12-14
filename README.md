# Proyecto Final de Compiladores: Compilador para ANSI C

## Descripción del Proyecto

Este proyecto es un compilador completo para el lenguaje de programación ANSI C. El compilador toma como entrada código fuente en C y genera código ensamblador x86 como salida. Está implementado utilizando herramientas de análisis léxico y sintáctico como Flex (para el analizador léxico) y Bison (para el analizador sintáctico), junto con código en C++ para la gestión de la tabla de símbolos, generación de código intermedio y producción de código ensamblador.

El compilador soporta un subconjunto significativo de ANSI C, incluyendo variables, funciones, estructuras de control (if, for, while, etc.), expresiones aritméticas, lógicas y de asignación, así como manejo de tipos básicos como int, float, char, etc.

## Requisitos del Sistema

Para compilar y ejecutar este compilador, necesitas los siguientes programas instalados en tu sistema:

- **Compilador C++**: g++ (parte de GCC). Se recomienda tener instalado GCC versión 4.8 o superior.
- **Flex**: Generador de analizadores léxicos. Versión 2.5 o superior.
- **Bison**: Generador de analizadores sintácticos. Versión 3.0 o superior.
- **Sistema operativo**: Linux (probado en distribuciones basadas en Debian/Ubuntu), aunque debería funcionar en otros sistemas Unix-like con las herramientas mencionadas.

### Instalación de Dependencias en Ubuntu/Debian

```bash
sudo apt update
sudo apt install g++ flex bison
```

### Instalación de Dependencias en CentOS/RHEL/Fedora

```bash
sudo yum install gcc-c++ flex bison  # Para CentOS/RHEL
sudo dnf install gcc-c++ flex bison  # Para Fedora
```

## Cómo Compilar el Proyecto

1. **Clona o descarga el proyecto**: Asegúrate de tener todos los archivos del proyecto en un directorio.

2. **Navega al directorio del proyecto**:
   ```bash
   cd /ruta/al/proyecto/Proyecto-Final-Compiladoores
   ```

3. **Compila el compilador**:
   ```bash
   make
   ```
   Este comando ejecutará las siguientes acciones:
   - Generará el analizador sintáctico (`ansic.tab.c` y `ansic.tab.h`) a partir de `ansic.y` usando Bison.
   - Generará el analizador léxico (`lex.yy.c`) a partir de `ansic.l` usando Flex.
   - Compilará el ejecutable `compiler` usando g++.

4. **Verificación**: Después de la compilación, deberías ver el archivo ejecutable `compiler` en el directorio.

## Cómo Usar el Compilador

Una vez compilado, puedes usar el compilador de la siguiente manera:

```bash
./compiler archivo_entrada.c
```

Esto generará un archivo `archivo_entrada.asm` con el código ensamblador correspondiente.

### Ejemplo de Uso

```bash
./compiler codigo.c
```

Esto procesará `codigo.c` y generará `codigo.asm`.

### Ejecutar Pruebas

El Makefile incluye un objetivo `test` que compila varios archivos de prueba:

```bash
make test
```

Esto ejecutará el compilador en `codigo.c`, `codigo2.c`, `codigo3.c`, `codigo4.c` y `codigo5.c`, generando los correspondientes archivos `.asm`.

## Limpieza

Para limpiar los archivos generados durante la compilación:

```bash
make clean
```

Esto eliminará `ansic.tab.c`, `ansic.tab.h`, `lex.yy.c` y el ejecutable `compiler`.

## Arquitectura del Compilador

El compilador está dividido en varias partes principales, cada una responsable de una fase específica del proceso de compilación:

### 1. Analizador Léxico (`ansic.l`)

**Archivo**: `ansic.l`  
**Herramienta**: Flex  
**Función**: 
- Tokeniza el código fuente de entrada.
- Reconoce palabras clave de C (como `int`, `if`, `while`, etc.).
- Identifica identificadores, constantes numéricas, literales de cadena y caracteres.
- Maneja comentarios (`/* */`) y directivas de preprocesador simples.
- Cuenta líneas y columnas para reportes de errores.
- Maneja estados para literales de cadena y carácter (usando estados Flex `INSTRING` e `INCHAR`).

**Salida**: Tokens que son pasados al analizador sintáctico.

### 2. Analizador Sintáctico (`ansic.y`)

**Archivo**: `ansic.y`  
**Herramienta**: Bison  
**Función**:
- Define la gramática completa de ANSI C.
- Realiza análisis sintáctico descendente (LR parsing).
- Construye el árbol de sintaxis abstracta (AST) implícitamente a través de acciones semánticas.
- Gestiona la tabla de símbolos para declaraciones de variables y funciones.
- Genera código intermedio en forma de cuádruplas (quads).
- Maneja scopes (ámbitos) de variables usando una pila de tablas de símbolos.
- Soporta estructuras de control: if-else, for, while, do-while, switch-case.
- Maneja expresiones aritméticas, lógicas, de asignación y relacionales.
- Gestiona llamadas a funciones y definición de funciones.
- Produce código ensamblador x86 como salida final.

**Características implementadas**:
- Tipos de datos: void, char, short, int, long, float, double, con modificadores signed/unsigned.
- Declaraciones: variables simples, arrays, punteros, structs, unions, enums.
- Funciones: definición, declaración, llamadas, parámetros.
- Expresiones: aritméticas (+, -, *, /, %), lógicas (&&, ||, !), relacionales (<, >, <=, >=, ==, !=), bitwise (&, |, ^, <<, >>, ~).
- Operadores de asignación: =, +=, -=, *=, /=, %=, <<=, >>=, &=, ^=, |=.
- Estructuras de control: if, else, for, while, do-while, switch, case, default, break, continue, goto.
- Preprocesador básico: sizeof.

### 3. Tabla de Símbolos (`symdefs.h`, `symfuncs.h`)

**Archivos**: `symdefs.h`, `symfuncs.h`  
**Función**:
- Gestiona la información de todos los símbolos (variables, funciones, tipos) en el programa.
- Soporta múltiples scopes (global, función, bloque) usando una pila de tablas de símbolos.
- Almacena información como nombre, tipo, tamaño, offset en memoria, inicialización.
- Para funciones: almacena tipo de retorno, tabla de símbolos local.
- Para arrays: lista de dimensiones.
- Proporciona funciones para insertar, buscar y gestionar símbolos.
- Calcula offsets de memoria para variables locales y globales.
- Maneja tipos complejos como punteros, arrays y structs.

**Estructuras principales**:
- `symrec`: Registro de símbolo individual.
- `symboltable`: Lista de símbolos por scope.
- `scopes`: Pila de scopes.

### 4. Generación de Código (`genlib.h`)

**Archivo**: `genlib.h`  
**Función**:
- Define el conjunto de operaciones de código intermedio (representación intermedia).
- Genera cuádruplas (quads) para representar operaciones.
- Soporta operaciones aritméticas, lógicas, de memoria, control de flujo.
- Gestiona etiquetas para saltos condicionales e incondicionales.
- Proporciona funciones para generar código intermedio (`gencode`).
- Almacena el código intermedio en un arreglo global `code`.

**Operaciones soportadas**:
- Asignación: STORE_IR, STOREA_IR, LOADA_IR
- Aritméticas: ADD_IR, SUB_IR, MULT_IR, DIV_IR, MOD_IR, MINUS_IR
- Lógicas: AND_IR, OR_IR, XOR_IR, NOT_IR
- Bitwise: LSHIFT_IR, RSHIFT_IR, TWOCOMP_IR
- Memoria: ADDRESS_IR, DEREF_IR
- Control: IF_EQ_IR, IF_NE_IR, etc., GOTO_IR
- Funciones: PROC_IR, ENDPROC_IR, CALL_IR, PARAM_IR, RET_IR
- Conversiones: INT_IR, FLOAT_IR, CHAR_IR

### 5. Generación de Código Ensamblador

**Integrado en el analizador sintáctico**  
**Función**:
- Traduce el código intermedio a código ensamblador x86.
- Genera directivas de segmento (.data, .text, .const).
- Maneja variables globales y locales.
- Produce código para expresiones, asignaciones y control de flujo.
- Gestiona la pila para variables locales y parámetros de función.
- Soporta llamadas a funciones y retorno.
- Incluye prólogo y epílogo de funciones.

**Características**:
- Modelo de memoria: flat (32-bit).
- Convenciones de llamada: estándar C (cdecl).
- Manejo de punto flotante usando instrucciones FPU.
- Generación de constantes en segmento .const.

## Archivos del Proyecto

- `ansic.l`: Definición del analizador léxico.
- `ansic.y`: Definición del analizador sintáctico y generador de código.
- `symdefs.h`: Definiciones de estructuras para la tabla de símbolos.
- `symfuncs.h`: Funciones para gestión de la tabla de símbolos.
- `genlib.h`: Biblioteca para generación de código intermedio.
- `ansic.tab.c`, `ansic.tab.h`: Archivos generados por Bison.
- `lex.yy.c`: Archivo generado por Flex.
- `Makefile`: Script de compilación.
- `codigo.c` a `codigo5.c`: Archivos de prueba en C.
- `codigo.asm` a `codigo5.asm`: Salidas ensamblador correspondientes.
- `fail.c`: Archivo de prueba que puede fallar.
- `compiler`: Ejecutable del compilador (generado).
- `micc`, `parse`, `rep`: Posiblemente ejecutables auxiliares o de depuración.

## Limitaciones

- No implementa todas las características de ANSI C completo (por ejemplo, algunos aspectos avanzados de preprocesador, uniones complejas).
- La generación de código está optimizada para claridad educativa, no para rendimiento máximo.
- Manejo limitado de errores en tiempo de compilación.
- No incluye un enlazador; el código ensamblador debe ser ensamblado y enlazado por separado con un ensamblador como MASM o NASM.

## Futuras Mejoras

- Implementar más optimizaciones de código.
- Agregar más verificaciones semánticas.
- Soporte para más características de C (como preprocesador completo).
- Generación de código para otras arquitecturas.
- Integración con un ensamblador y enlazador automático.

## Contribución

Este proyecto fue desarrollado como parte de un curso de compiladores. Para modificaciones o mejoras, edita los archivos fuente y recompila usando `make`.

## Licencia

Este proyecto es de código abierto y puede ser usado con fines educativos.

Este texto fue generado de manera automatica por lo que puede contener errores que se corregiran mas adelante.
