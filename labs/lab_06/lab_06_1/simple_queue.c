//
// Created by Nandor on 2025. 03. 27..
//

#include "simple_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createQueue(int kapacitas, Simple_Queue_t *sor) {
    sor->kapacitas = kapacitas;
    sor->eleje = -1;
    sor->vege = -1;
    sor->elemek = (char**)malloc(kapacitas * sizeof(char*));
}

void destroyQueue(Simple_Queue_t *sor) {
    for (int i = 0; i < sor->kapacitas; i++) {
        free(sor->elemek[i]);
    }
    free(sor->elemek);
}

bool isFull(Simple_Queue_t sor) {
    return sor.vege == sor.kapacitas - 1;
}

bool isEmpty(Simple_Queue_t sor) {
    return sor.eleje == -1 || sor.eleje > sor.vege;
}

void enqueue(Simple_Queue_t *sor, const char *rendszam) {
    if (isFull(*sor)) {
        printf("A sor tele van, nem lehet tobb autot hozzaadni.\n");
        return;
    }

    if (isEmpty(*sor)) {
        sor->eleje = 0;
    }

    sor->vege++;
    sor->elemek[sor->vege] = strdup(rendszam);
    printf("Auto hozzaadva: %s\n", rendszam);
}

char* dequeue(Simple_Queue_t *sor) {
    if (isEmpty(*sor)) {
        printf("A sor ures, nem lehet autot kivenni.\n");
        return NULL;
    }

    char *rendszam = sor->elemek[sor->eleje];
    sor->eleje++;

    if (sor->eleje > sor->vege) {
        // Sor újra üres lett
        sor->eleje = sor->vege = -1;
    }

    printf("Auto kiszolgalva: %s\n", rendszam);
    return rendszam;
}

void display(Simple_Queue_t sor) {
    if (isEmpty(sor)) {
        printf("A sor ures.\n");
        return;
    }

    printf("Sorban allo autok:\n");
    for (int i = sor.eleje; i <= sor.vege; i++) {
        printf("%d. %s\n", i - sor.eleje + 1, sor.elemek[i]);
    }
}

char* peek(Simple_Queue_t sor) {
    if (isEmpty(sor)) {
        return NULL;
    }
    return sor.elemek[sor.eleje];
}
