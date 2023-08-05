#!/usr/bin/python3

import random
import math
import sys
import string

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
r = int(cmdlinearg("r"))

print(n)
if mode=="random":
    print(" ".join(str(random.randint(0, r)) for i in range(n)))
elif mode=="max":
    nums = []
    i = r
    while len(nums)<n and i>=0:
        nums.append(i)
        i-=1
    while len(nums)<n:
        nums.append(random.randint(0,r))
    print(" ".join(str(i) for i in nums))
else:
    print("ERROR")