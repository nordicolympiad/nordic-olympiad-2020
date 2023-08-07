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



random.seed(int(sys.argv[-1]))
mode = cmdlinearg("mode")
n = int(cmdlinearg("n"))


if mode=="random":
    m = int(cmdlinearg("m", int(2e5)))
    print(n,m)
    edges = set()
    for i in range(m):
        while True:
            a,b=ra(1,n),ra(1,n)
            if a==b:
                continue
            if a > b:
                a,b=b,a
            if (a,b) in edges:
                continue
            edges.add((a,b))
            print(a,b)
            break
else:
    print("ERROR")