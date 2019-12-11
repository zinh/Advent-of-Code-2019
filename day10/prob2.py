from math import sqrt, acos, pi
import sys

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


def read_file(file_name):
    with open(file_name) as f:
        return [(x, y) for y, line in enumerate(f) for x, cell in enumerate(line) if cell == '#']

# calculate angle between two vectors
def angle(v1, v2):
    delta = v1[0] * v2[1] - v1[1] * v2[0]
    #if v2 == (0, -3):
    #    import pdb; pdb.set_trace()
    if delta == 0:
        return 0
    dot_product = v1[0] * v2[0] + v1[1] * v2[1]
    if delta > 0:
        return acos(dot_product / (length(v1) * length(v2)))
    else:
        return 2*pi - acos(dot_product / (length(v1) * length(v2)))

def length(v):
    return sqrt(v[0] * v[0] + v[1] * v[1])

if __name__ == "__main__":
    m = read_file(sys.argv[1])
    center = (22, 23)
    angles = sorted([[point, angle((0, -1), (point[0] - center[0], point[1] - center[1]))] for point in m if  point != center], key=lambda x: x[1])
    #print(angles)
    order = 1
    while True:
        del_lst = []
        del_point = []
        if not angles:
            break
        for i in range(0, len(angles)):
            point, angle = angles[i]
            if is_visible(center, point, m):
                print(order, point)
                del_lst.append(i)
                del_point.append(point)
                order += 1
        for del_id in angles:
            del angles[i]
        for point in del_point:
            m.remove(point)
