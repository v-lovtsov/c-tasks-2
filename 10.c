#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

void fill_array(int * nums, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", (nums + i));
    }
}

int is_sym(int * arr, int start, int end) {
    if (start >= end)
        return 1;

    if (arr[start] == arr[end])
        return is_sym(arr, start + 1, end - 1);
    else
        return 0;
}

int main() {
    int size, start, end;
    int * arr;

    scanf("%d", &size);
    scanf("%d %d", &start, &end);

    arr = (int *)malloc(size * sizeof(int));
    
    fill_array(arr, size);
    
    printf("%d\n", is_sym(arr, start, end));

    return 0;
}