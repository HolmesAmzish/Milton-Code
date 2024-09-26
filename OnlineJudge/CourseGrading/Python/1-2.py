"""
problem: Harmonic numbers
date: 2024-09-26
"""

def harmonic_number(n):
    return round(sum(1 / i for i in range(1, n + 1)), 1)

n = int(input("Enter an integer: "))
harmonic_numbers = [harmonic_number(i) for i in range(1, n + 1)]

print("The list of Harmonic numbers: ", harmonic_numbers)
print("The sum of the list: ", sum(harmonic_numbers))