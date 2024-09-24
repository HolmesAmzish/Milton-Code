import random
def do_trials(n):
    hits = [0] * 10
    for i in range(n):
        a = random.randint(0, 9)
        hits[a] += 1
    for i in range(10):
        fss = '{}: {}\t {:.3}'
        print(fss.format(i, hits[i], hits[i] / (n / 10)))

n = int(input('Enter the number: '))
do_trials(n)