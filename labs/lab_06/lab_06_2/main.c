#include "circular_queue.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    CircularQueue_t intSor;
    createQueue(6, &intSor);
    bool fut = true;

    while (fut) {
        printf("\nValasszon a kovetkezo opciokbol:\n"
               "\t- Sor ures-e: 1\n"
               "\t- Sor tele van-e: 2\n"
               "\t- Uj elem hozzaadasa: 3\n"
               "\t- Elem kiszolgalasa: 4\n"
               "\t- Sor megjelenitese: 5\n"
               "\t- Kilepes: 0\n"
               "\nValasztas: ");

        int opcio;
        scanf("%d", &opcio);

        switch (opcio) {
            case 1:
                printf("A sor %s\n", isEmpty(intSor) ? "ures" : "nem ures");
            break;
            case 2:
                printf("A sor %s\n", isFull(intSor) ? "tele van" : "nincs tele");
            break;
            case 3: {
                int ertek;
                printf("Adja meg az egesz szamot: ");
                scanf("%d", &ertek);
                enqueue(&intSor, ertek);
                break;
            }
            case 4:
                dequeue(&intSor);
            break;
            case 5:
                display(intSor);
            break;
            case 0:
                fut = false;
            break;
            default:
                printf("Ervenytelen opcio!\n");
        }
    }

    destroyQueue(&intSor);
    return 0;
}