#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"


void fill_array(int * nums, int size) {
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

    int maxlen = 0;
    int curlen = 0;

    for (int i = 0; i < n; i++) {
        int num = nums[i];

        if (num % 2 != 0)
            curlen++;
        else {
            maxlen = curlen > maxlen ? curlen : maxlen;
            curlen = 0; 
        }
    }

    for (int i = 0; i < n; i++) {
        int num = nums[i];
        
        printf("%d ", num);
    }

    printf("\n%d\n", maxlen);

    free(nums);

    return 0;
}