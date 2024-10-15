#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

void fill_array(int * nums, int size) {
    for (int i = 0; i < size; i++) {
        nums[i] = rand() % 10000;
    }
}

int getmax(int * arr, int size, int max, int index) {
    int bigger = arr[index] > max ? arr[index] : max;

    if (index >= size - 1) 
        return bigger;
    
    return getmax(arr, size, bigger, index + 1);
}

int main() {
    srand(time(NULL));

    int size;
    int * arr;

    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));
    
    fill_array(arr, size);
    
    printf("%d\n", getmax(arr, size, *arr, 1));

    for (int i = 0; i < size; i++) {
        int num = arr[i];
        printf("%d ", num);
    }

    return 0;
}