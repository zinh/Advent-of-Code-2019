def read_file(file_name):
    with open(file_name) as f:
        return [(x, y) for y, line in enumerate(f) for x, cell in enumerate(line) if cell == '#']


def count_visible(origin, m):
    return sum([1 for point in m if is_visible(origin, point, m)])

def is_visible(p1, p2, m):
    if p1 == p2:
        return False
    for s in m:
        if s!= p1 and s!= p2 and m != p1 and m != p2 and is_between(p1, p2, s):
            return False
    #if p1 == (4, 0):
    #    print(p2)
    return True

def is_between(p1, p2, s):
    # sp1, sp2
    sp1 = (p1[0] - s[0], p1[1] - s[1])
    sp2 = (p2[0] - s[0], p2[1] - s[1])
    return (sp1[0] * sp2[1] == sp1[1] * sp2[0]) and (sp1[0] * sp2[0] < 0 or sp1[1] * sp2[1] < 0)

if __name__ == "__main__":
    m = read_file('01.input')
    max_c = 0
    max_p = (0, 0)
    for point in m:
        c = count_visible(point, m) 
        if c > max_c:
            max_c = c
            max_p = point
        if c == 260:
            print(point)
    print(point, max_c)

    #for point in m:
    #    c = count_visible(point, m) 
    #    print("point = ", point, "count = ", c)
