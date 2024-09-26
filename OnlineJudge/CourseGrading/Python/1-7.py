"""
problem: Find the area of the triangle
date: 2024-09-26
"""

def caculate_triangle_area(a, b, c):
    h = (a + b + c) / 2
    return (h * (h - a) * (h - b) * (h - c)) ** 0.5

def get_triangle_sides():
    while True:
        try:
            a = int(input('Enter a side:'))
            b = int(input('Enter b side:'))
            c = int(input('Enter c side:'))
            if a < 0 and b < 0 and c < 0 and a + b < c and a + c < b and b + c < a:
                print('Invalid sides, pls retry.')
                continue
            return a, b, c

        except ValueError:
            print('Input value invalid!')

a, b, c = get_triangle_sides()
area = caculate_triangle_area(a, b, c)

print('The are of the triangle is:', round(area, 2))