#!/usr/bin/python3

# This is a Python script that factors large RSA numbers

import sys
import time
from math import sqrt, ceil

# Define a function to check if a number is prime
def is_prime(n):
    """Check if a number is prime."""
    if n < 2:
        return (False)
    for i in range(2, int(sqrt(n)) + 1):
        if n % i == 0:
            return (False)
        return (True)

def factor_rsa_number(n):
    """Factor a single RSA number using trial division."""
    factors = []

    # Check if 2 is a factor of n
    while n % 2 == 0:
        factors.append(2)
        n //= 2

    # Check for odd prime factors up to sqrt(n)
    i = 3
    while i <= sqrt(n):
        if n % i == 0:
            factors.append(i)
            n //= i
        else:
            i += 2

    # If n is still greater than 2, it must be prime
    if n > 2:
        factors.append(n)

    # If only one factor is found, return it as p and n//p as q
    if len(factors) == 1:
        p = factors[0]
        q = n // p
        return (p, q)
    else:
        pq = []
        for factor in factors:
            if is_prime(factor):
                pq.append(factor)
            else:
                p, q = factor_rsa_number(factor)
                pq.append(p)
                pq.append(q)
            return (tuple(pq))

    if __name__ == "__main__":
        if len(sys.argv) != 2:
            print("Usage: python rsa.py <input_file>")
            sys.exit(1)

        input_file = sys.argv[1]

        try:
            with open(input_file, 'r') as f:
                rsa_numbers = [int(line.strip()) for line in f.readlines()]
        except FileNotFoundError:
            print("File not found")
            sys.exit(1)

        start_time = time.time()

        # Factor each RSA number in the file
        for n in rsa_numbers:
            p, q = factor_rsa_number(n)
            print(f"{n}={q}*{p}")

        end_time = time.time()
        exec_time = end_time - start_time

        # Print the execution time in seconds
        print("Total execution time: {:.6f} seconds".format(exec_time))
