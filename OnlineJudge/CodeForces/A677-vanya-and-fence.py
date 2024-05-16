"""
Problem: A. Vanya and Fence
Date: 2024.05.16
Author: Nulla
"""

(n, h) = map(int, input().split())
width = 0
l = list(map(int, input().split()))
for p in l:
    if p > h:
        width += 2
    else:
        width += 1

print(width)