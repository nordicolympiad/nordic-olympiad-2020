#!/usr/bin/python3

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
mode = cmdlinearg("mode")
n = int(cmdlinearg("n"))

def getblock():
    while True:
        n,m=randint(1,6),randint(1,6)
        rows = []
        for i in range(n):
            rows.append(list(random.choice(('#','_')) for k in range(m)))
        

        while len(rows):
            alldash = True
            for i in range(len(rows[0])):
                if rows[0][i]=='#':
                    alldash=False
                    break
            if alldash:
                del rows[0]
            else:
                break

        while len(rows):
            alldash = True
            for i in range(len(rows[0])):
                if rows[-1][i]=='#':
                    alldash=False
                    break
            if alldash:
                del rows[-1]
            else:
                break


        while len(rows) and len(rows[0]):
            alldash = True
            for i in range(len(rows)):
                if rows[i][0]=='#':
                    alldash=False
                    break
            if alldash:
                for i in range(len(rows)):
                    del rows[i][0]
            else:
                break
            
        while len(rows) and len(rows[0]):
            alldash = True
            for i in range(len(rows)):
                if rows[i][-1]=='#':
                    alldash=False
                    break
            if alldash:
                for i in range(len(rows)):
                    del rows[i][-1]
            else:
                break

        if len(rows) and len(rows[0]):
            return ["".join(i) for i in rows]

print(n)
if mode=="random":
    for i in range(n):
        block = getblock()
        print(len(block[0]),len(block),randint(0, 10000))
        for j in range(len(block)):
            print(block[j])
else:
    print("ERROR")