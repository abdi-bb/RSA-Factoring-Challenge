#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

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

void main(int argc, char* argv[]) {
    if (argc != 2) {
        exit(EXIT_FAILURE);
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    /*if (fgets(buffer, BUFFER_SIZE, file) == NULL) {
	return 1;
    }

    long long n = strtoll(buffer, NULL, 10);
    long long p, q;

    find_primes(n, &p, &q);

    printf("%lld=%lld*%lld\n", n, q, p);
    */
    while (fgets(buffer, BUFFER_SIZE, file))
    {
	    long long n = strtoll(buffer, NULL, 10);
	    long long p, q;

	    find_primes(n, &p, &q);
	    if (n)
		    printf("%lld=%lld*%lld\n", n, q, p);
    }

    fclose(file);
}
