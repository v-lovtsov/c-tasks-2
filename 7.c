#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"


int get_digits_sum(int num, int sum) {
    if (num / 10 == 0) return num + sum;
    
    return get_digits_sum(num / 10, sum + (num % 10));
}

int get_digital_root(int num) {
    if (num / 10 == 0) return num;

    return get_digital_root(get_digits_sum(num, 0));
}

int main() {
    int num;

    scanf("%d", &num);
    
    printf("%d\n", get_digital_root(num));

    return 0;
}