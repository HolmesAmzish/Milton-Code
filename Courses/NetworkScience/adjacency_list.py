import numpy as np

# Adjacency list representation
adj_list = {
    1: ['2', '3'],
    2: ['1', '3', '4', '5'],
    3: ['1', '2', '5', '7', '8'],
    4: ['2', '5'],
    5: ['2', '3', '4', '6'],
    6: ['5'],
    7: ['3', '8'],
    8: ['3', '7'],
    9: ['10'],
    10: ['9', '11'],
    11: ['10']
}

# Output the adjacency list format
print("Adjacency List:")
for node, neighbors in adj_list.items():
    print(f"{node} {neighbors}")


# Create a matrix and write the edge into it
n = 11
A = np.zeros((n, n), dtype=int)
for node, neighbors in adj_list.items():
    for neighbor in neighbors:
        A[node - 1][int(neighbor) - 1] = 1

def print_matrix(matrix, label):
    print(f"\n{label}:")
    for row in matrix:
        print('\t'.join(map(str, row)))

# Calculate and output powers of A from A^1 to A^10
for power in range(1, 11):
    A_power = np.linalg.matrix_power(A, power)
    print_matrix(A_power, f"A^{power}")