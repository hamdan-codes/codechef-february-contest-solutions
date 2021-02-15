# Author : Chaudhary Hamdan
# 100 Points

def unique(a,b):
    l = len(set(a+b))
    return l


for _ in range(int(input())):
    n = int(input())
    a = input().split()
    
    data = {}
    for i in a:
        rem = i[1:]
        if rem in data:
            data[rem].append(i[0])
        else:
            data[rem] = [i[0]]
    unq_key = list(data.keys())
    ans = 0
    l = len(data)
    for i in range(l-1):
        for j in range(i+1,l):
            dis = unique(data[unq_key[i]],data[unq_key[j]])
            add = (dis - len(data[unq_key[i]])) * (dis - len(data[unq_key[j]]))
            ans += add
    print(2*ans)
