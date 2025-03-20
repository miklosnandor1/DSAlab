//
// Created by Nandor on 2025. 03. 20..
//
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void createIntArray(int capacity, IntArray* pArray) {
    pArray->capacity = capacity;
    pArray->size = 0;
    pArray->elements = (int*)malloc(capacity * sizeof(int));
    if (pArray->elements == NULL) {
        printf("Memoria foglalasi hiba!\n");
        exit(1);
    }
}


void printArray(IntArray array) {
    for (int i = 0; i < array.size; i++) {
        printf("%d ", array.elements[i]);
    }
    printf("\n");
}


bool isFull(IntArray array) {
    return array.size == array.capacity;
}


bool isEmpty(IntArray array) {
    return array.size == 0;
}


int getItemAt(IntArray array, int position) {
    if (position >= 0 && position < array.size) {
        return array.elements[position];
    }
    return INT_MIN; // Érvénytelen pozíció esetén
}


void insertFirst(IntArray* pArray, int item) {
    if (isFull(*pArray)) {
        printf("A tomb tele, nem lehet beszurni.\n");
        return;
    }
    for (int i = pArray->size; i > 0; i--) {
        pArray->elements[i] = pArray->elements[i - 1];
    }
    pArray->elements[0] = item;
    pArray->size++;
}


void insertLast(IntArray* pArray, int item) {
    if (isFull(*pArray)) {
        printf("A tomb tele, nem lehet beszurni.\n");
        return;
    }
    pArray->elements[pArray->size] = item;
    pArray->size++;
}


void insertAt(IntArray* pArray, int position, int item) {
    if (isFull(*pArray)) {
        printf("A tomb tele, nem lehet beszurni.\n");
        return;
    }
    if (position < 0 || position > pArray->size) {
        printf("Ervenytelen pozicio.\n");
        return;
    }
    for (int i = pArray->size; i > position; i--) {
        pArray->elements[i] = pArray->elements[i - 1];
    }
    pArray->elements[position] = item;
    pArray->size++;
}


void deleteItemAt(IntArray* pArray, int position) {
    if (isEmpty(*pArray)) {
        printf("A tomb ures, nem lehet torolni.\n");
        return;
    }
    if (position < 0 || position >= pArray->size) {
        printf("Ervenytelen pozicio.\n");
        return;
    }
    for (int i = position; i < pArray->size - 1; i++) {
        pArray->elements[i] = pArray->elements[i + 1];
    }
    pArray->size--;
}


int search(IntArray array, int item) {
    for (int i = 0; i < array.size; i++) {
        if (array.elements[i] == item) {
            return i;
        }
    }
    return -1;
}


bool update(IntArray* pArray, int position, int newItem) {
    if (position < 0 || position >= pArray->size) {
        return false;
    }
    pArray->elements[position] = newItem;
    return true;
}


void deallocateIntArray(IntArray* pArray) {
    free(pArray->elements);
    pArray->elements = NULL;
    pArray->size = 0;
    pArray->capacity = 0;
}
