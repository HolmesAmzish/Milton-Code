n = int(input("Enter the number to: "))

def fibo(n):
    if n <= 0:
        return 0
    elif n == 1 or n == 2:
        return 1
    else:
        return fibo(n - 1) + fibo(n - 2)

for i in range(1, n + 1):
    print(f"The no. {i} of fibonacci array is {fibo(i)}")