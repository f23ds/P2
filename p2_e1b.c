#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "stack_fDoble.h"
#include "types.h"
#include "point.h"

#define MIN_POINTS 0
#define MAX_POINTS 10
#define MAX_RAND 10

int main(int argc, char **argv)
{
    int n, i, j;
    double d;
    Stack *stack;
    Point *origen, *p[MAX_POINTS];

    /* Comprobamos la command line */
    if (argc < 2)
        return 1;

    n = atoi(argv[1]);

    /* Comprobamos que el número de puntos es correcto */
    if (n < MIN_POINTS || n > MAX_POINTS)
        return 1;

    /* Calcular la distancia euclídea de los puntos al origen de coordenadas */
    origen = point_new(0, 0, BARRIER);

    /* Imprimimos la distancia euclídea para cada uno de los puntos */
    for (i = 0; i < n; i++)
    {
        /* point with random coordinates */
        p[i] = point_new(rand() % MAX_RAND, rand() % MAX_RAND,
                         BARRIER);

        /* Liberamos los puntos anteriores  en el caso de que erre la función point_new */
        if (p[i] == NULL)
        {
            for (j = i - 1; j >= 0; j--)
            {
                point_free(p[j]);
            }
            return 1;
        }

        point_print(stdout, p[i]);
        point_euDistance(p[i], origen, &d);
        fprintf(stdout, " distance: %f\n", d);
    }

    /* Almacenar los puntos en una pila */
    stack = stack_init();

    if (!stack)
        return 1;

    // TODO: MIRAR SI LA PILA ESTÁ LLENA
    for (i = 0; i < n; i++) {
        stack_push(stack, p[i]);
    }

    // stack_print(stdout, stack);

    /* Ordenamos la pila de mayor a menor según la distancia euclídea entre los puntos */
}