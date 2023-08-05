#!/usr/bin/env bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution joshua_precompute.cpp

compile gen.py

samplegroup
limits maxn=10 maxr=100
sample 1

MAXN=300000
MAXR=300000

group g1 15
limits maxn=10 maxr=300
tc 1
tc g1-1 gen mode="random" n=10 r=300 
tc g1-2 gen mode="random" n=10 r=300 
tc g1-3 gen mode="random" n=10 r=300 
tc g1-4 gen mode="max" n=10 r=300 


group g2 25
limits maxn=3000 maxr=1000
include_group g1
tc g2-1 gen mode="random" n=3000 r=1000
tc g2-2 gen mode="random" n=3000 r=1000
tc g2-3 gen mode="random" n=3000 r=1000
tc g2-4 gen mode="max" n=3000 r=1000 


group g3 15
limits maxn=$MAXN maxr=10000
include_group g2
tc g3-1 gen mode="random" n=$MAXN r=10000
tc g3-2 gen mode="random" n=$MAXN r=10000
tc g3-3 gen mode="random" n=$MAXN r=10000
tc g3-4 gen mode="max" n=$MAXN r=10000 

group g4 45
limits maxn=$MAXN maxr=$MAXR
include_group g3
tc g4-1 gen mode="random" n=$MAXN r=$MAXR
tc g4-2 gen mode="random" n=$MAXN r=$MAXR
tc g4-3 gen mode="random" n=$MAXN r=$MAXR
tc g4-4 gen mode="max" n=$MAXN r=$MAXR
tc g4-5 gen mode="max" n=200000 r=$MAXR
tc g4-6 gen mode="max" n=100000 r=$MAXR
