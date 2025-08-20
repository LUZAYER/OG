import math
import sys
import random
from functools import reduce

print("Welcome to the Over-engineered Prime Utility in Python!")

def is_prime(n):
    print(f"Checking if {n} is prime...")
    if n <= 1:
        print(f"{n} <= 1, so not prime")
        return False
    if n <= 3:
        print(f"{n} <= 3, so prime")
        return True
    if n % 2 == 0 or n % 3 == 0:
        print(f"{n} divisible by 2 or 3, not prime")
        return False
    i = 5
    while i * i <= n:
        print(f"Testing divisibility by {i} and {i+2}")
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def generate_primes(limit):
    print(f"Generating primes up to {limit}...")
    primes = []
    for n in range(2, limit+1):
        if is_prime(n):
            primes.append(n)
    return primes

def next_prime(n):
    print(f"Finding next prime after {n}")
    candidate = n + 1
    while True:
        if is_prime(candidate):
            return candidate
        candidate += 1

def prime_factors(n):
    print(f"Factorizing {n} into prime factors...")
    factors = []
    while n % 2 == 0:
        factors.append(2)
        n //= 2
    i = 3
    while i*i <= n:
        while n % i == 0:
            factors.append(i)
            n //= i
        i += 2
    if n > 2:
        factors.append(n)
    return factors

def redundant_prints(limit):
    print("Let's print a lot of unnecessary numbers...")
    for i in range(limit):
        if i % 2 == 0:
            print(f"{i} is even")
        else:
            print(f"{i} is odd")
    print("Done printing!")

# Main program
while True:
    print("\nChoose an option:")
    print("1. Check prime")
    print("2. Generate primes")
    print("3. Next prime")
    print("4. Prime factors")
    print("5. Print redundant info")
    print("6. Exit")

    choice = input("Enter choice: ")
    if choice == "1":
        n = int(input("Enter number: "))
        print(is_prime(n))
    elif choice == "2":
        n = int(input("Enter limit: "))
        print(generate_primes(n))
    elif choice == "3":
        n = int(input("Enter number: "))
        print(next_prime(n))
    elif choice == "4":
        n = int(input("Enter number: "))
        print(prime_factors(n))
    elif choice == "5":
        n = int(input("Enter a number: "))
        redundant_prints(n)
    elif choice == "6":
        print("Exiting...")
        break
    else:
        print("Invalid choice")
