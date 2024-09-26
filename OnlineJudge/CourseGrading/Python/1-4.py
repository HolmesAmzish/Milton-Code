print("Find the sum by using 'for'")

sum = 0
sum_odd = 0
sum_even = 0

for i in range(1, 101):
    sum += i

for i in range(1, 101, 2):
    sum_odd += i

for i in range(2, 101, 2):
    sum_even += i

print('Sum:', sum, '\n', 'Sum of odd:', sum_odd, '\n', 'Sum of even:', sum_even)

print("Find the sum by using 'while'")

sum = 0
sum_odd = 0
sum_even = 0

i = 0
while(i <= 100):
    sum += i
    if i % 2 == 0:
        sum_even += i
    else:
        sum_odd += i
    i += 1

print('Sum:', sum, '\n', 'Sum of odd:', sum_odd, '\n', 'Sum of even:', sum_even)