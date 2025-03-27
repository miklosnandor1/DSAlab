#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int performOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0; // Hibás eset
    }
}

int evaluatePostfix(char *expression) {
    Stack stack;
    createStack(strlen(expression), &stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0'); // Karakterből szám
        } else if (isOperator(expression[i])) {
            int b = pop(&stack);
            int a = pop(&stack);
            int result = performOperation(a, b, expression[i]);
            push(&stack, result);
        }
    }

    int finalResult = pop(&stack);
    destroyStack(&stack);
    return finalResult;
}

int main() {
    char expression[] = "2 5 3 6 + * * 15 / 2 -";
    printf("Postfix kifejezes: %s\n", expression);
    int result = evaluatePostfix(expression);
    printf("Eredmeny: %d\n", result);

    return 0;
}