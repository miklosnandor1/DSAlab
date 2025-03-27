//
// Created by Nandor on 2025. 03. 27..
//

#include "circular_queue.h"
#include <stdio.h>
#include <stdlib.h>

void createQueue(int kapacitas, CircularQueue_t *sor) {
    sor->kapacitas = kapacitas;
    sor->eleje = -1;
    sor->vege = -1;
    sor->elemek = (int*)malloc(kapacitas * sizeof(int));
}

void destroyQueue(CircularQueue_t *sor) {
    free(sor->elemek);
}

bool isFull(CircularQueue_t sor) {
    return (sor.vege + 1) % sor.kapacitas == sor.eleje;
}

bool isEmpty(CircularQueue_t sor) {
    return sor.eleje == -1;
}

void enqueue(CircularQueue_t *sor, int ertek) {
    if (isFull(*sor)) {
        printf("A sor tele van.\n");
        return;
    }

    if (isEmpty(*sor)) {
        sor->eleje = 0;
    }

    sor->vege = (sor->vege + 1) % sor->kapacitas;
    sor->elemek[sor->vege] = ertek;
    printf("%d hozzaadva a sorhoz.\n", ertek);
}

int dequeue(CircularQueue_t *sor) {
    if (isEmpty(*sor)) {
        printf("A sor ures.\n");
        return -1;
    }

    int ertek = sor->elemek[sor->eleje];

    if (sor->eleje == sor->vege) {
        // Utolsó elem kivétele
        sor->eleje = sor->vege = -1;
    } else {
        sor->eleje = (sor->eleje + 1) % sor->kapacitas;
    }

    printf("%d kiszolgalva a sorból.\n", ertek);
    return ertek;
}

void display(CircularQueue_t sor) {
    if (isEmpty(sor)) {
        printf("A sor ures.\n");
        return;
    }

    printf("Sor elemei: ");
    int i = sor.eleje;
    while (1) {
        printf("%d ", sor.elemek[i]);
        if (i == sor.vege) break;
        i = (i + 1) % sor.kapacitas;
    }
    printf("\n");
}
