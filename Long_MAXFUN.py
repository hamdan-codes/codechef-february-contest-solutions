# Author : Chaudhary Hamdan
# 100 Points
for _ in range(int(input())):
    
    n = int(input())
    a = [int(x) for x in input().split()]
    a = sorted(a)
    
    summ = (2 * ( a[-1] - a[0] ) )
    
    print(summ)
    