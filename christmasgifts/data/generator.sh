#!/usr/bin/env bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution joshua_full.cpp

compile gen.py
compile geneven.cpp

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


group g2 15
include_group g1
limits maxn=500 maxm=10000
tc g2-1 gen mode=random n=500 m=10000
tc g2-2 gen mode=random n=500 m=10000
tc g2-3 gen mode=random n=500 m=10000
tc g2-4 gen mode=random n=500 m=10000
tc g2-5 gen mode=random n=500 m=10000

group g3 20
limits maxn=100000 maxm=200000 evendeg=1
tc g3-1 geneven
tc g3-2 geneven
tc g3-3 geneven

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
