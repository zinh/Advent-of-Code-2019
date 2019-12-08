def read_file(file_name):
    d = dict()
    with open(file_name) as f:
        for line in f:
            src, dest = line.strip().split(')')
            d[dest] = src
    return d

def find_path(node_name, h):
    path = []
    current_node = node_name
    while current_node in h:
        path.append(h[current_node])
        current_node = h[current_node]
    return path

# return first intersection
def intersection(set1, set2):
    for s1 in set1:
        for s2 in set2:
            if s1 == s2:
                return s1
    return None

if __name__ == "__main__":
    d = read_file('01.input')
    you_path = find_path("YOU", d)
    san_path = find_path("SAN", d)
    joint = intersection(you_path, san_path)
    print(you_path.index(joint) + san_path.index(joint))
