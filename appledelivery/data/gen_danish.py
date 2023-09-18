import random
from random import randint
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
n = int(cmdlinearg("n"))
minr = int(cmdlinearg("minr",0))
maxr = int(cmdlinearg("maxr"))

def printTest(numbers):
    print(len(numbers))
    print(" ".join(map(str, numbers)))

def genRnd(N, minR=0, maxR=300000):
    numbers = []

    for _ in range(N):
        number = random.randint(minR, maxR)
        numbers.append(number)

    printTest(numbers)        


genRnd(n, minr, maxr)
