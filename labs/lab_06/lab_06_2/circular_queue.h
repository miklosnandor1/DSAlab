//
// Created by Nandor on 2025. 03. 27..
//

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>

typedef struct {
    int kapacitas;  // A sor maximális mérete
    int eleje;      // Az első elem indexe
    int vege;       // Az utolsó elem indexe
    int *elemek;    // A sorban tárolt egész számok
} CircularQueue_t;

// Létrehoz egy új körkörös sort
void createQueue(int kapacitas, CircularQueue_t *sor);

// Felszabadítja a sort
void destroyQueue(CircularQueue_t *sor);

// Ellenőrzi, hogy a sor tele van-e
bool isFull(CircularQueue_t sor);

// Ellenőrzi, hogy a sor üres-e
bool isEmpty(CircularQueue_t sor);

// Új elemet helyez a sor végére
void enqueue(CircularQueue_t *sor, int ertek);

// Kiveszi és visszaadja a sor elején lévő elemet
int dequeue(CircularQueue_t *sor);

// Kiírja a sor elemeit
void display(CircularQueue_t sor);

#endif