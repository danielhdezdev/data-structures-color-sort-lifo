# Color Sort (LIFO) — Estructuras de Datos

Implementación educativa del puzzle **Color Sort** usando **pilas (LIFO)** en C.  
Cada tubo es una pila con capacidad fija; el objetivo es terminar con tubos formados por un solo color.

## Demo
```
make run
```
El programa genera un tablero aleatorio y lo imprime con colores ANSI.

## Estructura
```
include/        # headers (stack.h, datatypes.h)
src/            # fuentes C (colorsort.c, stack.c, datatypes.c)
tests/          # entrada de prueba o futuros unit tests
docs/           # diagramas, capturas, notas
.github/workflows/ci.yml  # pipeline (build + lint)
Makefile        # comandos de build
```

## Compilar y Ejecutar
Requisitos: GCC/Clang y make (Linux/macOS/WSL).
```bash
make            # compila
make run        # compila y corre
make clean      # limpia artefactos
make test       # objetivo de prueba
```

## Cómo funciona
- **TAD Pila** en `stack.[ch]` maneja push/pop/peek con verificación de capacidad.
- **Tipos Ball y color** en `datatypes.[ch]`.
- **colorsort.c** inicializa N pilas, mezcla 6×4 bolas y muestra el tablero con colores ANSI.
- Complejidad por operación: `push/pop = O(1)`; validación/impresión `O(n_pilas * capacidad)`.


## Licencia
MIT © 2025 Daniel Hernández
