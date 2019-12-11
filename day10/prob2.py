from math import sqrt, acos
import sys

def read_file(file_name):
    with open(file_name) as f:
        return [(x, y) for y, line in enumerate(f) for x, cell in enumerate(line) if cell == '#']

# calculate angle between two vectors
def angle(v1, v2):
    dot_product = v1[0] * v2[0] + v1[1] * v2[1]
    print(v2)
    return acos(dot_product / (length(v1) * length(v2)))

def length(v):
    return sqrt(v[0] * v[0] + v[1] * v[1])

if __name__ == "__main__":
    m = read_file(sys.argv[1])
    center = (22, 23)
    angles = [[point, angle((-1, 0), (point[0] - center[0], point[1] - center[1]))] for point in m]
    print(angles)
