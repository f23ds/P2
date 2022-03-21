/**
 * @file  stack_fDoble.h
 * @author Prog2
 * @date 8 Mar 2021
 * @version 1.0
 * @brief Stack library
 *
 * @details Stack interface
 *
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 */

#ifndef STACK_FDOBLE_H
#define STACK_FDOBLE_H

#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "stack_fDoble.h"

#define INIT_CAPACITY 2
#define FCT_CAPACITY 2

struct _Stack
{
    void **items;
    int top;
    int capacity;
};

typedef struct _Stack Stack;

typedef int (*P_stack_ele_print)(FILE *, const void *);

Stack *stack_init()
{
    Stack *s = NULL;
    int i;

    /* Creamos la stack */
    s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL)
        return NULL;

    /* Inicializamos la capacidad */
    s->capacity = INIT_CAPACITY;

    /* Reservamos memoria para el global pointer de items */
    s->items = (void **)calloc(INIT_CAPACITY, sizeof(void *));

    /* Inicializamos el top */
    s->top = -1;
    return s;
}

void stack_free(Stack *s)
{
    int i;

    if (s == NULL)
        return NULL;

    /* Liberamos el global pointer */
    free(s->items);
    /* Liberamos la stack */
    free(s);
}

Status stack_push(Stack *s, const void *ele);

void *stack_pop(Stack *s)
{
    void *e = NULL;

    if (s == NULL || stack_isEmpty(s))
        return NULL;

    e = s->items[s->top];
    s->items[s->top] = NULL;
    s->top--;

    return e;
}

void *stack_top(const Stack *s)
{
    if (s == NULL || stack_isEmpty(s))
        return NULL;

    return s->items[s->top];
}

Bool stack_isEmpty(const Stack *s)
{
    if (s == NULL)
        return TRUE;

    if (s->top == -1)
        return TRUE;

    return FALSE;
}

Bool _stack_isFull(const Stack *s)
{
    if (s == NULL)
        return TRUE;

    if (s->top == s->capacity - 1)
        return TRUE;

    return FALSE;
}
/**
 * @brief This function returns the size of the stack.
 *
 * Time complexity: O(1).
 * @param s A pointer to the stack.
 * @return the size
 */
size_t stack_size(const Stack *s);

/**
 * @brief  This function writes the elements of the stack to the stream.
 * @param fp A pointer to the stream
 * @param s A pointer to the element to the stack
 * @return Upon successful return, these function returns the number of characters writted.
 * The function returns a negative value if there was a problem writing to the file.
 *  */
int stack_print(FILE *fp, const Stack *s, P_stack_ele_print f);

#endif /* STACK_FDOBLE_H */
