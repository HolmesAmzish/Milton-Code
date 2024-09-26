"""
problem: Operation of List
date: 2024-09-26
"""

input_numbers = input('Enter the list of number: ')
numbers = list(map(int, input_numbers.split()))

length = len(numbers)
max_value = max(numbers)
min_value = min(numbers)
sum_value = sum(numbers)
average_value = sum_value / length

print('Length =', length, '\n'
      'Max =', max_value, '\n'
      'Min =', min_value, '\n'
      'Sum =', sum_value, '\n'
      'Average =', average_value)