import math

def get_t(v1,v2,a,b,x,y):
    A = v1*v2
    B = a*v2 - b*v1 + y*v1 - x*v2
    C = x*b + y*a - a*b
    D = B*B - 4*A*C
    if D < 0:
        return -1
    else:
        rt = math.sqrt(D)
        root1 = (-B+rt)
        root2 = (-B-rt)
        if root1 < 0 and root2 < 0:
            return -1
        if root1 < 0:
            return root2
        if root2 < 0:
            return root1
        return min(root1,root2)
        return time

def solve():
    a,b,v1,v2 = map(int,input().split())
    points = []
    n = int(input())
    for i in range(n):
        x,y = map(int,input().split())
        points.append([x,y])

    dic = {}
    for i in range(n):
        dic[i+1] = get_t(v1,v2,a,b,points[i][0],points[i][1])

    ans = -1
    time = -1
    for i in range(n):
        if dic[i+1] != -1:
            if time == -1:
                time = dic[i+1]
                ans = i+1
            else:
                if time > dic[i+1]:
                    time = dic[i+1]
                    ans = i+1
    if ans != -1:
        x = -1
        fin = ans
        for i in range(n):
            if dic[i+1] == time:
                if x == -1:
                    fin = i+1
                    x = points[i][0]
                else:
                    if points[i][0] < x:
                        x = points[i][0]
                        fin = i+1
        return fin

    return ans

t = int(input())
for _ in range(t):
    print(solve())