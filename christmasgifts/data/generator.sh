#!/usr/bin/env bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_full.cpp

compile gen.py
compile geneven.cpp
compile gen_danish.py

samplegroup
limits maxn=5 maxm=5
sample 1

group g1 15
limits maxn=10 maxm=20
tc 1
tc g1-1 gen mode=random n=10 m=20
tc g1-2 gen mode=random n=10 m=20
tc g1-3 gen mode=random n=10 m=20
tc g1-4 gen mode=random n=10 m=20
tc g1d-1 gen_danish group=1 case=0
tc g1d-2 gen_danish group=1 case=1
tc g1d-3 gen_danish group=1 case=2
tc g1d-4 gen_danish group=1 case=3
tc g1d-5 gen_danish group=1 case=4
tc g1d-6 gen_danish group=1 case=5
tc g1d-7 gen_danish group=1 case=6
tc g1d-8 gen_danish group=1 case=7
tc g1d-9 gen_danish group=1 case=8
tc g1d-10 gen_danish group=1 case=9
tc g1d-11 gen_danish group=1 case=10


group g2 15
include_group g1
limits maxn=500 maxm=10000
tc g2-1 gen mode=random n=500 m=10000
tc g2-2 gen mode=random n=500 m=10000
tc g2-3 gen mode=random n=500 m=10000
tc g2-4 gen mode=random n=500 m=10000
tc g2-5 gen mode=random n=500 m=10000
tc g2d-1 gen_danish group=2 case=0
tc g2d-2 gen_danish group=2 case=1
tc g2d-3 gen_danish group=2 case=2
tc g2d-4 gen_danish group=2 case=3
tc g2d-5 gen_danish group=2 case=4
tc g2d-6 gen_danish group=2 case=5
tc g2d-7 gen_danish group=2 case=6


group g3 20
limits maxn=100000 maxm=200000 evendeg=1
tc g3-1 geneven
tc g3-2 geneven
tc g3-3 geneven
tc g3d-1 gen_danish group=3 case=0
tc g3d-2 gen_danish group=3 case=1
tc g3d-3 gen_danish group=3 case=2
tc g3d-4 gen_danish group=3 case=3
tc g3d-5 gen_danish group=3 case=4
tc g3d-6 gen_danish group=3 case=5
tc g3d-7 gen_danish group=3 case=6
tc g3d-9 gen_danish group=3 case=7
tc g3d-8 gen_danish group=3 case=8
tc g3d-10 gen_danish group=3 case=9


# Potential cheese that can slip through
# Do a dfs until you find a cycle, then return. repeat
# Can be quadratic if a long path leads to an area with many cycles
# Pain in the ass to order edges such that all found cycles are short and we actually get quadratic
group g4 50
include_group g2
include_group g3
limits maxn=100000 maxm=200000
tc g4-1 gen mode=random n=100000 m=200000
tc g4-2 gen mode=random n=100000 m=200000
tc g4-3 gen mode=random n=100000 m=200000
tc g4d-1 gen_danish group=4 case=0
tc g4d-2 gen_danish group=4 case=1
tc g4d-3 gen_danish group=4 case=2
tc g4d-4 gen_danish group=4 case=3
tc g4d-5 gen_danish group=4 case=4
tc g4d-6 gen_danish group=4 case=5
tc g4d-7 gen_danish group=4 case=6
tc g4d-8 gen_danish group=4 case=7
tc g4d-9 gen_danish group=4 case=8

