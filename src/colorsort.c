// Daniel Hernandez
// Jose Garcia

// librerias para el programa
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// importamos la libreria de stack
#include "stack.h"

// constantes a utilizar en el programa
#define NUM_COLORS 6
#define BALLS_PER_COLOR 4
#define STACK_CAPACITY 4

// Colores ANSI para imprimir en la consola
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

// Estructura para representar una bola con su color
typedef struct
{
    char color;
} Ball;

// Función para inicializar los stacks con bolas aleatorias
void inicializarStacks(STACK stacks[])
{
    // array con los colores de las bolas
    char colors[NUM_COLORS] = {'R', 'G', 'Y', 'B', 'M', 'C'};
    // variables para las iteraciones
    int stack_index;

    // inicializar el generador de números con el tiempo actual
    srand(time(NULL));

    // iterar sobre los colores
    for (int i = 0; i < NUM_COLORS; i++)
    {
        // iterar para generar las 4 bolas de cada color
        for (int j = 0; j < BALLS_PER_COLOR; j++)
        {
            // crear una nueva bola
            Ball *ball = malloc(sizeof(Ball));
            // asignarle el color
            ball->color = colors[i];
            // generar un indice de stack aleatorio en el que insertar la bola
            stack_index = rand() % 6; // Generar un índice entre 0 y 5
            // mientras el stack este lleno, generar un nuevo indice
            while (stacks[stack_index].size == STACK_CAPACITY)
            {
                stack_index = rand() % 6; // Generar un nuevo índice si el actual está lleno
            }
            // insertar la bola en el stack
            stack_push(&stacks[stack_index], (TYPE *)ball);
        }
    }
}

// Función para imprimir el contenido de los stacks
void imprimirStacks(STACK stacks[])
{
    // Imprimir encabezados de los stacks
    printf(" 0\t 1\t 2\t 3\t 4\t 5\t 6\t 7\n\n");

    // Iterar sobre las filas de las bolas en los stacks
    for (int i = STACK_CAPACITY - 1; i >= 0; i--)
    {
        // Iterar sobre cada stack
        for (int j = 0; j < 8; j++)
        {
            // Verificar si el stack tiene bolas en la fila actual
            if (stacks[j].size > i)
            {
                // Encontrar la bola en la posición correspondiente
                struct STRSNODE *current = stacks[j].top;
                for (int k = 0; k < stacks[j].size - i - 1; k++)
                {
                    current = current->prev;
                }
                // Obtener el color de la bola
                Ball *ball = current->elem;
                // Imprimir la bola con el color correspondiente
                switch (ball->color)
                {
                case 'R':
                    printf("|" ANSI_COLOR_RED "R" ANSI_COLOR_RESET "|\t");
                    break;
                case 'G':
                    printf("|" ANSI_COLOR_GREEN "G" ANSI_COLOR_RESET "|\t");
                    break;
                case 'Y':
                    printf("|" ANSI_COLOR_YELLOW "Y" ANSI_COLOR_RESET "|\t");
                    break;
                case 'B':
                    printf("|" ANSI_COLOR_BLUE "B" ANSI_COLOR_RESET "|\t");
                    break;
                case 'M':
                    printf("|" ANSI_COLOR_MAGENTA "M" ANSI_COLOR_RESET "|\t");
                    break;
                case 'C':
                    printf("|" ANSI_COLOR_CYAN "C" ANSI_COLOR_RESET "|\t");
                    break;
                }
            }
            else
            {
                // Imprimir un espacio si el stack está vacío en la fila actual
                printf("| |\t");
            }
        }
        // Imprimir separadores entre filas
        printf("\n");
    }
    // Imprimir línea de separación entre stacks y bolas
    printf("---\t---\t---\t---\t---\t---\t---\t---\n");
}

void moverBola(STACK stacks[])
{
    int origen, destino;

    // Pedir al usuario los números de los stacks de origen y destino
    printf("De: ");
    scanf("%d", &origen);
    printf("A: ");
    scanf("%d", &destino);

    // Verificar si los números de stack son válidos
    if (origen < 0 || origen > 7 || destino < 0 || destino > 7)
    {
        printf("Números de stack inválidos.\n");
        return;
    }

    // Verificar si el stack de origen está vacío
    if (stack_empty(&stacks[origen]))
    {
        printf("El stack de origen está vacío.\n");
        return;
    }

    // Verificar si el stack de destino está lleno
    if (stacks[destino].size == 4)
    {
        printf("El stack de destino está lleno.\n\n");
        return;
    }

    // Obtener la bola del tope del stack de origen
    Ball *bola_origen = stack_peek(&stacks[origen]);
    // Obtener la bola del tope del stack de destino
    Ball *bola_destino = stack_peek(&stacks[destino]);

    // Verificar si el stack de destino está vacío o si la bola es del mismo color que la bola en la cima del stack de destino
    if (stack_empty(&stacks[destino]) || bola_destino->color == bola_origen->color)
    {
        // Mover la bola al stack de destino
        stack_push(&stacks[destino], bola_origen);
        // Eliminar la bola del stack de origen
        stack_pop(&stacks[origen]);
        // restarle 1 al tamanio del stack de origen
        stacks[origen].size--;
    }
    else
    {
        printf("No se puede mover la bola a este stack.\n");
    }
}

int juegoTerminado(STACK stacks[])
{
    int stacksLlenos = 0;  // Contador para los stacks llenos con bolas del mismo color
    int bolas_mismo_color; // Bandera para verificar si las siguientes bolas en el stack son del mismo color
    // Iteramos sobre cada stack
    for (int i = 0; i < 8; i++)
    {
        // Verificamos si el stack está lleno
        if (stacks[i].size == STACK_CAPACITY)
        {
            // Obtener la bola en el tope del stack
            Ball *bola_top = stack_peek(&stacks[i]);

            // Verificar las siguientes bolas en el stack
            bolas_mismo_color = 1; // Inicialmente asumimos que la primera bola cumple con la condición
            struct STRSNODE *current = stacks[i].top;

            // Recorremos las siguientes bolas en el stack para verificar si son del mismo color
            for (int j = 0; j < STACK_CAPACITY - 1; j++)
            {
                current = current->prev;
                Ball *bola_actual = current->elem;

                // Si la bola actual no es del mismo color que la del tope, marcamos la condición como falsa
                if (bola_actual->color != bola_top->color)
                {
                    bolas_mismo_color = 0;
                    break;
                }
            }

            // Si todas las bolas en el stack son del mismo color, incrementamos el contador de stacks
            if (bolas_mismo_color)
            {
                stacksLlenos++;
            }
        }
    }

    // Si hay al menos 6 stacks con bolas del mismo color, el juego ha terminado
    if (stacksLlenos >= 6)
    {
        return 1; // El juego ha terminado
    }
    else
    {
        return 0; // El juego aún está en progreso
    }
}

int main()
{
    STACK stacks[8]; // 8 stacks en total

    // crear los stacks
    for (int i = 0; i < 8; i++)
        stacks[i] = *stack_new();
    // inicializamos los stacks
    inicializarStacks(stacks);

    while (TRUE)
    {
        printf("Estado actual:\n");
        imprimirStacks(stacks);
        moverBola(stacks);
        if (juegoTerminado(stacks) == 1)
            break;
    }
    imprimirStacks(stacks);
    printf("Juego terminado!");

    return 0;
}