# Author : Chaudhary Hamdan
# 20 Points

class Node:
    def __init__(self, data):   
        self.val = data
        self.child = []    

def insert(root, parent, node): 
    if root is None: 
        root = node                
    else: 
        if root.val == parent: 
            root.child.append(node)     
        else:
            l = len(root.child) 
            for i in range(l): 
                if root.child[i].val == parent: 
                    insert(root.child[i], parent, node) 
                else: 
                    insert(root.child[i], parent, node) 


def solve(root, w):
    global kk
    k = len(root.child)
    if k == 0:
        return kk + w
    
    if w % k == 0:
        a = 0
        for i in range(k):
            a += solve(root.child[i], w // k)
        return kk + a
    else:
        return kk


n = int(input())
p = [int(x) for x in input().split()]
q = int(input())
root = Node(1)

data = {}
data[1] = root
kk = 0
for i in range(n-1):
    new_Node = Node(i+2)
    data[i+2] = new_Node
    insert(root,p[i],new_Node)

for i in range(q):
    v, w = [int(x) for x in input().split()]
    ans = solve(data[v], w) 
    print(w - ans)


