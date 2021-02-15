# Author : Chaudhary Hamdan
# 10 Points

import operator as op
from functools import reduce

ncrs = {}
def ncr(n, r):
    if n < r:
        return 0
    keyr = str(n)+'_'+str(r)
    keynr = str(n)+'_'+str(n-r)
    if keyr in ncrs.keys():
        return ncrs[keyr]
    
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    
    returned = numer // denom
    
    ncrs[keyr] = ncrs[keynr] = returned
    
    return returned

n = int(input())
a = [int(x) for x in input().split()]
q = int(input())
mod = 998244353


one, zero = [], []

for i in range(31):
    set1 = 0
    set0 = 0
    bit = 1 << i
    for j in range(n):
        if bit & a[j]:
            set1 += 1
        else:
            set0 += 1
    one.append(set1)
    zero.append(set0)
    
dp = [0, sum(a)]

for i in range(2,n):
    ans = 0
    for k in range(31):
        pro = 0
        for j in range(1,i+1,2):
            if one[k] >= j and zero[k] >= (i-j):
                ones = ncr(one[k],j)
                zeros = ncr(zero[k],i-j)
                pro += ones * zeros
        ans += pro * (1 << k)
    dp.append(dp[-1] + ans)

ORS = 0
for i in range(n):
    ORS = ORS | a[i]

ORS *= 2 ** (n-1)

dp.append(ORS)
    
for _ in range(q):
    m = int(input())
    print(dp[m] % mod)
        
