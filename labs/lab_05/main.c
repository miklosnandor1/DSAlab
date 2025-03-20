#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// CMAKELIST jobb click load


int main() {
    IntArray array;
    createIntArray(10, &array);


    printf("Ures tomb: ");
    printArray(array);


    for (int i = 1; i <= array.capacity; i++) {
        insertLast(&array, i);
    }
    printf("Tomb feltoltve: ");
    printArray(array);


    int value = array.capacity + 1;
    while (!isFull(array)) {
        if (value % 2 == 0) {
            insertFirst(&array, value);
        } else {
            insertLast(&array, value);
        }
        value++;
    }
    printf("Tomb feltoltve paros/paratlan szaballyal: ");
    printArray(array);


    int searchItem;
    printf("Adj meg egy szamot a kereseshez: ");
    scanf("%d", &searchItem);
    int pos = search(array, searchItem);
    if (pos != -1) {
        printf("A keresett ertek a %d pozicion talalhato.\n", pos);
    } else {
        printf("A keresett ertek nem talalhato a tombben.\n");
    }


    if (pos != -1) {
        int newItem;
        printf("Adj meg egy uj erteket a frissiteshez: ");
        scanf("%d", &newItem);
        update(&array, pos, newItem);
        printf("Frissitett tomb: ");
        printArray(array);
    }



    srand(time(NULL));
    while (!isEmpty(array)) {
        int randomPos = rand() % array.size;
        printf("Torlendo pozicio: %d\n", randomPos);
        deleteItemAt(&array, randomPos);
        printf("Tomb a torles utan: ");
        printArray(array);
    }


    deallocateIntArray(&array);

    return 0;
}