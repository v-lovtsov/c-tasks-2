#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int is_int_sqrt(int num) {
    double nsqrt = sqrt(num);
    if (nsqrt == floor(nsqrt))
        return 1;
    else 
        return 0;
}

int main() {
    int * nums;
    int n;
    int count = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (is_int_sqrt(num))
            count++;
    }

    printf("%d\n", count);

    return 0;
}