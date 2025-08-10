# Color Sort (LIFO) — Data Structures

Educational implementation of the **Color Sort** puzzle using **stacks (LIFO)** in C.  
Each tube is a fixed-capacity stack; the goal is to end with tubes containing balls of a single color.

## Demo
```
make run
```
The program generates a random board and prints it with ANSI colors.

## Project Structure
```
include/        # headers (stack.h, datatypes.h)
src/            # C sources (colorsort.c, stack.c, datatypes.c)
tests/          # sample input or future unit tests
docs/           # diagrams, screenshots, notes
.github/workflows/ci.yml  # CI pipeline (build + lint)
Makefile        # build commands
```

## Build & Run
Requirements: GCC/Clang and make (Linux/macOS/WSL).
```bash
make            # build
make run        # build and run
make clean      # remove artifacts
make test       # placeholder test target
```

## How it Works
- **Stack ADT** in `stack.[ch]` manages push/pop/peek with capacity checks.
- **Ball and color types** in `datatypes.[ch]`.
- **colorsort.c** initializes N stacks, shuffles 6×4 balls, and prints the board with ANSI colors.
- Complexity per move: `push/pop = O(1)`; validation/display are `O(n_stacks * capacity)`.


## License
MIT © 2025 Daniel Hernández
