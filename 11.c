#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

void fill_array(int * nums, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", (nums + i));
    }
}

void mvelsl(int * arr, int size, int from) {
    int cfrom = from;

    if (cfrom < 1)
        cfrom = 1;

    for (int i = cfrom; i < size; i++) {
        *(arr + i - 1) = *(arr + i);
    }
}

int * delel(int * arr, int * size, int idx) {
    int dsize = *size;
    if (idx != dsize - 1)
        mvelsl(arr, dsize, idx + 1);

    int * copy = (int *)malloc(sizeof(int) * (dsize - 1));
    for (int i = 0; i < dsize - 1; i++) {
        *(copy + i) = *(arr + i);
    }

    free(arr);

    *size = dsize - 1;

    return copy;
}

int * delete_copies(int * arr, int * size, int start) {
    if (start >= (*size) - 1) {
        return arr;
    }

    int el = *(arr + start);
    int * copy = arr;

    int i = start + 1;

    while (i < *size) {
        if (*(copy + i) == el) {
            copy = delel(copy, size, i);
            i--;
        }
        i++;
    }
    
    return delete_copies(copy, size, start + 1);
}

int main() {
    srand(time(NULL));

    int size;
    int * arr;

    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));
    fill_array(arr, size);

    for (int i = 0; i < size; i++) {
        int num = *(arr + i);
        printf("%d ", num);
    }

    printf("\n");

    arr = delete_copies(arr, &size, 0);
    
    for (int i = 0; i < size; i++) {
        int num = *(arr + i);
        printf("%d ", num);
    }

    free(arr);
    return 0;
}