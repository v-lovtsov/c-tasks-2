#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
//-
void fill_array(int * nums, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", (nums + i));
    }
}

int max(int * arr, int size) {
    int m = *arr;
    int res = 0;

    for (int i = 0; i < size; i++) {
        if (*(arr + i) > m) {
            res = i;
            m = *(arr + i);
        }
    }

    return res;
}

int * add(int * n1, int * n2, int decimals) {
    int * res = (int *)malloc((decimals + 1) * sizeof(int));
    int mvdec = 0;
    for (int i = decimals - 1; i >= 0; i--) {
        int sum  = *(n1 + i) + *(n2 + i) + mvdec;
        int decimal = sum % 10;
        *(res + i + 1) = decimal;

        mvdec = sum / 10;
    }
    *res = mvdec;

    return res;
}

int * multiple(int * n1, int * n2, int decimals1, int decimals2) {
    int ** steps = (int **)malloc((decimals2) * sizeof(int *));
    int * sizes = (int *)malloc((decimals2) * sizeof(int));
    

    int mvdec = 0;
    for (int i = decimals2 - 1; i >= 0; i--) {
        int size = 1;
        int step = 1;
        *(steps + i) = (int *)malloc(size * sizeof(int));


        while (step != 0) {
            int mult = ((*n1) * (*n2)) + mvdec;
            *(*(steps + i) + step) = mult % 10;
            mvdec = mult / 10;

            if (mvdec != 0) {
                *(steps + i) = (int *)realloc(*(steps + i), (size + 1) * sizeof(int));
                size++;
                step++;
            }
            step--;
        }
        *(sizes + i) = size;
    }

    for (int i = 0; i < decimals2; i++) {
        int size = *(sizes + i);
        for (int j = 0; j < size; j++) {
            printf("%d\n", steps[i][j]);
        }
        
    }

    int maxsize = max(sizes, decimals2);

    for (int i = 0; i < decimals2; i++) {
        *(steps + i) = (int *)realloc(*(steps + i), maxsize);
    }

    int * res = *steps;

    for (int i = 1; i < decimals2; i++) {
        res = add(res, *(steps + i), maxsize);
    }

    free(sizes);

    free(steps);


    return res;
}

// int * factorial(int * nstep, int * res, int decimals) {
//     if 
// }

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
    // result = factorial(n1, decimals);
    result = multiple(n1, n2, decimals, decimals);

    for (int i = 0; i < decimals + 1; i++) {
        int num = *(result + i);
        printf("%d", num);
    }

    free(n1);
    free(n2);
    free(result);
    return 0;
}