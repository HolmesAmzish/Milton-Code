"""
problem: find prime number between 101 and 200
date: 2024-09-26
"""

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

count = 0
for i in range(101, 200):
    if is_prime(i):
        print(i, end=' ')
        count += 1
        if count % 10 == 0:
            print()