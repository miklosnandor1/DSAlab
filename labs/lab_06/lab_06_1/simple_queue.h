//
// Created by Nandor on 2025. 03. 27..
//
#ifndef SIMPLE_QUEUE_H
#define SIMPLE_QUEUE_H

#include <stdbool.h>

typedef struct {
    int kapacitas;    // A sor maximális mérete
    int eleje;       // Az első elem indexe
    int vege;        // Az utolsó elem indexe
    char **elemek;   // A sorban tárolt karakterláncok (rendszámok)
} Simple_Queue_t;

// Létrehoz egy új sort a megadott kapacitással
void createQueue(int kapacitas, Simple_Queue_t *sor);

// Felszabadítja a sor által lefoglalt memóriát
void destroyQueue(Simple_Queue_t *sor);

// Ellenőrzi, hogy a sor tele van-e
bool isFull(Simple_Queue_t sor);

// Ellenőrzi, hogy a sor üres-e
bool isEmpty(Simple_Queue_t sor);

// Új elemet (rendszámot) helyez a sor végére
void enqueue(Simple_Queue_t *sor, const char *rendszam);

// Kiveszi és visszaadja a sor elején lévő elemet (rendszámot)
char* dequeue(Simple_Queue_t *sor);

// Kiírja a sorban várakozó autók rendszámait
void display(Simple_Queue_t sor);

// Visszaadja a sor elején lévő elemet anélkül, hogy kivenné
char* peek(Simple_Queue_t sor);

#endif