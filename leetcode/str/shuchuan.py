#!/usr/bin/python3

'''
设有n个正整数，将他们连接成一排，组成一个最大的多位整数。
如:n=3时，3个整数13,312,343,连成的最大整数为34331213。
如:n=4时,4个整数7,13,4,246连接成的最大整数为7424613。
'''
import sys 
from functools import cmp_to_key

def mycmp(x,y):
    if x+y>y+x:
        return 1
    elif x==y:
        return 0
    else:
        return -1

for i,v in enumerate(sys.stdin.readlines()):
    if i%2==1:
        v=v.strip().split()
        v.sort(key=cmp_to_key(mycmp),reverse=True)
        print("".join(v).lstrip("0") or "0")
