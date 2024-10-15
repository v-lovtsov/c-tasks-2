#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int NOD(int n1, int n2) {
    while (n2 != 0) {
        int temp = n2;
        n2 = n1 % n2;
        n1 = temp;
    }
    return n1;
}

int NODA(int * arr, int size) {
    int temp = NOD(arr[0], arr[1]);
    for (int i = 2; i < size; i++) {
        temp = NOD(temp, arr[i]);
    }
    return temp;
}

int main() {
    int * nums;
    int n;

    scanf("%d", &n);

    if (n < 3)
        n = 3;

    nums = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", nums + i);   
    }

    printf("%d\n", NODA(nums, n));

    free(nums);

    return 0;
}