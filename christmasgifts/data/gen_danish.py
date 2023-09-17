#!/usr/bin/python3

import random
from random import randint
import math
import sys
import string
ra = randint

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default



group = int(cmdlinearg("group"))
case = int(cmdlinearg("case"))

random.seed(int(sys.argv[-1]))

def printTest(n, edges):
    print(f"{n} {len(edges)}")

    for a, b in edges:
        assert a >= 1 and a <= n and b >= 1 and b <= n
        print(f"{a} {b}")

def genRnd(N, M):
    edges = set()

    for _ in range(M):
        while True:
            edge = (random.randint(1, N), random.randint(1, N))

            if not (edge[0] == edge[1] or edge in edges or (edge[1], edge[0]) in edges):
                break

        edges.add(edge)

    printTest(N, list(edges))       

def genEven(N, M):
    edges = set()
    
    while M - len(edges) >= 3:
        foundPath = False
        while not foundPath:
            foundPath = True
            path = random.sample(range(1, N+1), random.randint(3, min(M - len(edges), N, 100)))
            pathEdges = list(zip(path, path[1:] + path[0:1]))
            for a, b in pathEdges:
                if (a, b) in edges or (b, a) in edges:
                    foundPath = False
                    break
    
        edges.update(pathEdges)

    printTest(N, list(edges))

def genCycle(N):
    printTest(N, [(i, i+1) for i in range(1, N)] + [(N, 1)])


if group==1:
    # Group 1
    if case==0: genRnd(2, 1)
    if case==1: genRnd(3, 1)
    if case==2: genRnd(3, 2)
    if case==3: genRnd(3, 3)
    if case==4: genRnd(5, 10)
    if case==5: genRnd(6, 15)
    if case==6: genRnd(10, 15)
    if case==7: genRnd(9, 19)
    if case==8: genRnd(10, 20)
    if case==9: genRnd(10, 20)
    if case==10: genCycle(10)

elif group==2:
    # Group 2
    if case==0: genRnd(500, 10000)
    if case==1: genCycle(500)
    if case==2: genEven(500, 10000)
    if case==3: genRnd(499, 9999)
    if case==4: genRnd(498, 9000)
    if case==5: genRnd(423, 9786)
    if case==6: genRnd(489, 9777)



# Group 3

elif group==3:
    if case==0: genRnd(3, 3)
    if case==1: genRnd(5, 10)
    if case==2: genRnd(7, 21)
    if case==3: genCycle(10000)
    if case==4: genEven(10000, 5000)
    if case==5: genEven(999, 999)
    if case==6: genEven(100000, 200000)
    if case==7: genEven(100000, 200000)
    if case==8: genEven(10000, 100000)
    if case==9: genEven(3000, 199999)

elif group==4:
    if case==0: genRnd(100000, 200000)
    if case==1: genEven(10000, 5000)
    if case==2: genEven(100000, 200000)
    if case==3: genRnd(999, 199999)
    if case==4: genRnd(1000, 200000)
    if case==5: genRnd(90000, 123456)
    if case==6: genRnd(98765, 123456)
    if case==7: genRnd(99999, 199999)
    if case==8: genRnd(99999, 199999)

