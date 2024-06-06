"""
Contest: Codeforces Round 928 Div. 4
Problem: Vlad and the Best of Five
Date: 2024.06.04
Author: Nulla
"""

t = int(input())

results = []

for i in range(t):
    string = input()

    nA = nB = 0
    for char in string:
        if char == 'A':
            nA += 1
        else:
            nB += 1
    result = 'A' if nA > nB else 'B'
    results.append(result)

for result in results:
    print(result)

# solved