/*
 * Author: Adam Ali
 * Date: 7/12/2022
 * Description: This is the implementation of stacks.
 */

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/*
 * Function: create_stack
 * ----------------------
 * Creates a stack with the given capacity.
 *
 * capacity: the capacity of the stack
 *
 * returns: a pointer to the stack
 */
stack *create_stack(int capacity) {
    stack *s = malloc(sizeof(stack));
    s->top = -1;
    s->capacity = capacity;
    s->array = malloc(capacity * sizeof(void *));
    return s;
}

/*
 * Function: is_empty
 * ------------------
 * Checks if the stack is empty.
 *
 * s: the stack to check
 *
 * returns: 1 if the stack is empty, 0 otherwise
 */
int is_empty(stack *s) {
    return s->top == -1;
}

/*
 * Function: is_full
 * -----------------
 *
 * Checks if the stack is full.
 *
 * s: the stack to check
 *
 * returns: 1 if the stack is full, 0 otherwise
 */
int is_full(stack *s) {
    return s->top == s->capacity - 1;
}

/*
 * Function: push
 * --------------
 * Pushes the given data onto the stack.
 *
 * s: the stack to push to
 * data: the data to push
 */
void push(stack *s, void *data) {
    if (is_full(s)) {
        printf("Stack is full. Cannot push data.\n");
        return;
    }
    s->array[++s->top] = data;
}

/*
 * Function: pop
 * -------------
 * Pops the top element off the stack.
 *
 * s: the stack to pop from
 *
 * returns: the data that was popped
 */
void *pop(stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty. Cannot pop data.\n");
        return NULL;
    }
    return s->array[s->top--];
}

/*
 * Function: peek
 * --------------
 * Peeks at the top element of the stack.
 *
 * s: the stack to peek at
 *
 * returns: the data at the top of the stack
 */
void *peek(stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty. Cannot peek data.\n");
        return NULL;
    }
    return s->array[s->top];
}