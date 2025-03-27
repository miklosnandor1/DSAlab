#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// Verem létrehozása
void createStack(int capacity, Stack *stack) {
    stack->capacity = capacity;
    stack->top = -1; // Kezdetben a verem üres
    stack->elements = (int *)malloc(capacity * sizeof(int));
    if (stack->elements == NULL) {
        printf("%s\n", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

// Verem megsemmisítése (memória felszabadítása)
void destroyStack(Stack *stack) {
    free(stack->elements);
    stack->elements = NULL;
    stack->top = -1;
    stack->capacity = 0;
}

// Ellenőrzi, hogy a verem tele van-e
bool isFull(Stack stack) {
    return stack.top == stack.capacity - 1;
}

// Ellenőrzi, hogy a verem üres-e
bool isEmpty(Stack stack) {
    return stack.top == -1;
}

// Elem hozzáadása a veremhez (push)
void push(Stack *stack, int item) {
    if (isFull(*stack)) {
        printf("%s\n", STACK_FULL_ERROR_MESSAGE);
        return;
    }
    stack->elements[++stack->top] = item;
}

// Elem eltávolítása a veremből (pop)
int pop(Stack *stack) {
    if (isEmpty(*stack)) {
        printf("%s\n", STACK_EMPTY_ERROR_MESSAGE);
        return -1; // Hibás eset
    }
    return stack->elements[stack->top--];
}

// A verem tetején lévő elem lekérése (peek)
int peek(Stack stack) {
    if (isEmpty(stack)) {
        printf("%s\n", STACK_EMPTY_ERROR_MESSAGE);
        return -1; // Hibás eset
    }
    return stack.elements[stack.top];
}

// A verem méretének lekérése
int size(Stack stack) {
    return stack.top + 1;
}