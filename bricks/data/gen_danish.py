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
maxscore = int(cmdlinearg("maxscore", 10000))

WIDTH = 6


def printTest(formations):
    print(len(formations))
    for rows, s in formations:
        print(f"{len(rows[0])} {len(rows)} {s}")
        for row in rows:
            print(row)

def genRnd(N, minScore=0, maxScore=10000):
    formations = []

    for _ in range(N):
        w = random.randint(1, WIDTH)
        h = random.randint(1, WIDTH)
        s = random.randint(minScore, maxScore)

        grid = ["".join("#" if (i in [0, h-1] and j in [0, w - 1]) or random.randint(0, 1) else "_" for j in range(w)) for i in range(h)]
        
        formations.append((grid, s))

    printTest(formations)        

genRnd(n,maxscore)
