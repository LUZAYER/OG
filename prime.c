#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(long n) {
    printf("Checking %ld for primality...\n", n);
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    long i = 5;
    while (i * i <= n) {
        printf("Testing %ld and %ld\n", i, i+2);
        if (n % i == 0 || n % (i+2) == 0) return false;
        i += 6;
    }
    return true;
}

void generate_primes(long limit) {
    printf("Generating primes up to %ld\n", limit);
    for (long i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%ld ", i);
        }
    }
    printf("\n");
}

long next_prime(long n) {
    printf("Finding next prime after %ld\n", n);
    long candidate = n + 1;
    while (!is_prime(candidate)) {
        candidate++;
    }
    return candidate;
}

void prime_factors(long n) {
    printf("Prime factors of %ld: ", n);
    while (n % 2 == 0) {
        printf("2 ");
        n /= 2;
    }
    long i = 3;
    while (i * i <= n) {
        while (n % i == 0) {
            printf("%ld ", i);
            n /= i;
        }
        i += 2;
    }
    if (n > 2) printf("%ld", n);
    printf("\n");
}

int main() {
    int choice;
    long n;
    while (1) {
        printf("\n1. Check prime\n2. Generate primes\n3. Next prime\n4. Prime factors\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter number: ");
                scanf("%ld", &n);
                printf("%ld is %sprime\n", n, is_prime(n) ? "" : "not ");
                break;
            case 2:
                printf("Enter limit: ");
                scanf("%ld", &n);
                generate_primes(n);
                break;
            case 3:
                printf("Enter number: ");
                scanf("%ld", &n);
                printf("Next prime: %ld\n", next_prime(n));
                break;
            case 4:
                printf("Enter number: ");
                scanf("%ld", &n);
                prime_factors(n);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
