#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

int is_prime_step(int init, int cur, int count) {
    if (cur <= 2) 
        return init % 2 == 0 ? count + 1 : count;

    return is_prime_step(init, cur - 1, count + 1);
}

int is_prime(int init) {
    int delcount = is_prime_step(init, init / 2, 0);
    printf("%d\n", delcount);
    return 0;
}

int main() {
    int num;

    scanf("%d", &num);
    
    printf("%d\n", is_prime(num));

    return 0;
}