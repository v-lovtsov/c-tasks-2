#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

void fill_array(int * nums, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", (nums + i));
    }
}

int * add(int * n1, int * n2, int decimals) {
    int * res = (int *)malloc((decimals + 1) * sizeof(int));
    int mvdec = 0;

    for (int i = decimals - 1; i >= 0; i--) {
        int sum  = n1[i] + n2[i] + mvdec;
        int decimal = sum % 10;
        res[i + 1] = decimal;

        mvdec = sum / 10;
    }
    *res = mvdec;

    return res;
}

int main() {
    srand(time(NULL));

    int decimals;
    int * n1;
    int * n2;
    int * result;

    scanf("%d", &decimals);

    n1 = (int *)malloc(decimals * sizeof(int));
    n2 = (int *)malloc(decimals * sizeof(int));

    printf("\nNumber 1:\n");
    fill_array(n1, decimals);

    printf("\nNumber 2:\n");
    fill_array(n2, decimals);

    printf("\nResult:\n");
    result = add(n1, n2, decimals);

    for (int i = 0; i < decimals + 1; i++) {
        int num = result[i];
        printf("%d", num);
    }

    free(n1);
    free(n2);
    free(result);
    return 0;
}