#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

int is_prime_step(int n, int i) {
    if (i == 1) {
        return 1;
    } else {
        if (n % i == 0) {
            return 0;
        } else {
            return is_prime_step(n, i - 1);
        }
    }
}


int is_prime(int init) {
    int isprime = is_prime_step(init, init - 1);
    return isprime;
}

int main() {
    int num;

    scanf("%d", &num);
    
    printf("%d\n", is_prime(num));

    return 0;
}