#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 1000

bool is_prime(long long n) {
    if (n <= 1) {
        return false;
    }
    for (long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void find_primes(long long n, long long* p, long long* q) {
    for (long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0 && is_prime(i)) {
            *p = i;
            *q = n / i;
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        return 1;
    }

    char buffer[BUFFER_SIZE];
    if (fgets(buffer, BUFFER_SIZE, file) == NULL) {
	return 1;
    }

    long long n = atoll(buffer);
    long long p, q;

    find_primes(n, &p, &q);

    printf("%lld=%lld*%lld\n", n, q, p);

    fclose(file);
    return 0;
}
