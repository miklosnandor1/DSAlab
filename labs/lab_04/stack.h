//
// Created by Nandor on 2025. 03. 20..
//

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct {
    int capacity;  // A verem maximális kapacitása
    int top;       // A verem tetejének pozíciója
    int *elements; // A verem elemeit tároló tömb
} Stack;

// Hibakódok és üzenetek
#define MEMORY_ALLOCATION_ERROR_CODE 1
#define MEMORY_ALLOCATION_ERROR_MESSAGE "Error when allocating memory"

#define STACK_FULL_ERROR_CODE 3
#define STACK_FULL_ERROR_MESSAGE "Stack is full"

#define STACK_EMPTY_ERROR_CODE 4
#define STACK_EMPTY_ERROR_MESSAGE "Stack is empty"

// Függvények deklarációi
void createStack(int capacity, Stack *stack);
void destroyStack(Stack *stack);
bool isFull(Stack stack);
bool isEmpty(Stack stack);
void push(Stack *stack, int item);
int pop(Stack *stack);
int peek(Stack stack);
int size(Stack stack);

#endif // STACK_H