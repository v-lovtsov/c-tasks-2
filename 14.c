#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

void fill_array(int ** nums, int n, int * dirr, int * dirc, int idxr, int idxc, int count) {
    nums[idxc][idxr] = count;

    int idxr2 = idxr;
    int idxc2 = idxc;

    if (*dirr == 1) {
        idxr2++;
    } else if (*dirr == n) {
        idxr2--;
    }

    if (*dirc == 1) {
        idxc2++;
    } else if (*dirc == n) {
        idxc2--;
    }

    if (*dirr == 1 && (idxr2 == n - 1 || nums[idxc2][idxr2 + 1] != 0)) {
        *dirr = 0;
        *dirc = 1;
    } else if (*dirr == n && (idxr2 == 0 || nums[idxc2][idxr2 - 1] != 0)) {
        *dirr = 0;
        *dirc = n;
    } else if (*dirc == 1 && (idxc2 == n - 1 || nums[idxc2 + 1][idxr2] != 0)) {
        *dirc = 0;
        *dirr = n;
    } else if (*dirc == n && (idxc2 == 0 || nums[idxc2 - 1][idxr2] != 0)) {
        *dirc = 0;
        *dirr = 1;
    }

    if (count < n*n) {
        fill_array(nums, n, dirr, dirc, idxr2, idxc2, count + 1);
    }
}

int main() {
    srand(time(NULL));

    int n;
    int ** arr;
    int directionr = 1; // 1 - right, n - left, 0 - none
    int directionc = 0; // 1 - down, n - up, 0 - none

    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    fill_array(arr, n, &directionr, &directionc, 0, 0, 1);
    printf("\nResult:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    } 


    free(arr);
    return 0;
}