with open('edges.txt', 'r') as file:
    lines = file.readlines()

sorted_lines = sorted(lines, key = lambda line: int(lines.split()[1]))

with open('sorted_edges.txt', 'w') as file:
    for line in sorted_lines:
        file.write(line)

print("Done.")