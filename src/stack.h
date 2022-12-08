/*
 * Author: Adam Ali
 * Date: 7/12/2022
 * Description: This is the header file for the implementation of stacks.
 */

#ifndef DSLIB_STACK_H
#define DSLIB_STACK_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct stack {
    int top;
    int capacity;
    void **array;
} stack;

stack *create_stack(int capacity);

int is_empty(stack *s);
int is_full(stack *s);

void push(stack *s, void *data);
void *pop(stack *s);
void *peek(stack *s);

#ifdef __cplusplus
}
#endif
#endif //DSLIB_STACK_H
