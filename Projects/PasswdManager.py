"""
Program: PasswordManager.py
Date: 2024.05.16
Last update: 2024.05.16
Author: Nulla
"""

import os

with open('password.csv', 'r') as file:
    first_line = True
    for line in file:
        for word in line.split(','):
            print(word, end = '\t')

        if first_line:
            print('=' * 32)
            first_line = False
os.system("pause")