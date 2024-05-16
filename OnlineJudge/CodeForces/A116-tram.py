"""
Problem: A. Tram
Date: 2024.05.16
Author: Nulla
"""

n = int(input())

max_capcity = 0
current_capcity = 0

for i in range(n):
    (a, b) = map(int, input().split())
    current_capcity += b - a
    if current_capcity > max_capcity:
        max_capcity = current_capcity

print(max_capcity)