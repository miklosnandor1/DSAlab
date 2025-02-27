#include <stdio.h>

int main() {
    int num;
    int Prim = 1;

    printf("Adjon meg egy szamot: ");
    scanf("%d", &num);

    if (num <= 1) {
        Prim = 0;
    } else {

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                Prim = 0;
                break;
            }
        }
    }

    if (Prim) {
        printf("%d egy primszam.\n", num);
    } else {
        printf("%d nem primszam.\n", num);
    }

    return 0;
}
