#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char line[256];
    long long int n;

    if (argc < 2) {
        printf("Usage: factors <file>\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        n = strtoll(line, NULL, 10);

        for (long long int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                printf("%lld=%lld*%lld\n", n, n / i, i);
                break;
            }
        }
    }

    fclose(file);
    return 0;
}
