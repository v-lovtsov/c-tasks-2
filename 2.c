#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int NOD(int * nums, int size) {
    
}

int main() {
    int * nums;
    int n;
    scanf("%d", &n);

    nums = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", nums + i);   
    }

    printf("%d\n", NOD(nums, n));

    free(nums);

    return 0;
}