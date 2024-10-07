#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"


int get_digits_sum(int num, int sum) {
    if (num / 10 == 0) return num + sum;
    
    return get_digits_sum(num / 10, sum + (num % 10));
}

int main() {
    int num;

    scanf("%d", &num);
    
    printf("%d\n", get_digits_sum(num, 0));

    return 0;
}