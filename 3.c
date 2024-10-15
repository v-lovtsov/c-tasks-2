#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"


int fill_array(int * nums, int size) {
    for (int i = 0; i < size; i++) {
        nums[i] = rand() % 10000;
    }
}

int main() {
    srand(time(NULL));

    int * nums;
    int n;

    scanf("%d", &n);

    nums = (int *)malloc(n * sizeof(int));
    fill_array(nums, n);

    for (int i = 0; i < n; i++) {
        printf("%d\n", nums[i]); 
    }

    free(nums);

    return 0;
}