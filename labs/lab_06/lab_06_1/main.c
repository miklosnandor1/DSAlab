#include "simple_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    Simple_Queue_t autoSor;
    createQueue(6, &autoSor);
    bool fut = true;
printf("simple");
    while (fut) {
        printf("\nValasszon a kovetkezo opciokbol:\n"
               "\t- Sor ures-e: 1\n"
               "\t- Sor tele van-e: 2\n"
               "\t- Uj auto hozzaadasa: 3\n"
               "\t- Auto kiszolgalasa: 4\n"
               "\t- Sor megjelenitese: 5\n"
               "\t- Kilepes: 0\n"
               "\nValasztas: ");

        int opcio;
        scanf("%d", &opcio);

        switch (opcio) {
            case 1:
                printf("A sor %s\n", isEmpty(autoSor) ? "ures" : "nem ures");
            break;
            case 2:
                printf("A sor %s\n", isFull(autoSor) ? "tele van" : "nincs tele");
            break;
            case 3: {
                char rendszam[20];
                printf("Adja meg az auto rendszamat: ");
                scanf("%s", rendszam);
                enqueue(&autoSor, rendszam);
                break;
            }
            case 4:
                dequeue(&autoSor);
            break;
            case 5:
                display(autoSor);
            break;
            case 0:
                fut = false;
            break;
            default:
                printf("Ervenytelen opcio!\n");
        }
    }

    destroyQueue(&autoSor);
    return 0;
}