#!/usr/bin/env bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution joshua_full.cpp

compile gen.py
compile gen_danish.py

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
tc g1d-1 gen_danish n=10 minr=0 maxr=300
tc g1d-2 gen_danish n=10 minr=290 maxr=300
tc g1d-3 gen_danish n=10 minr=299 maxr=300
tc g1d-4 gen_danish n=10 minr=300 maxr=300
tc_manual ../manual_tests/manual_1.in
tc_manual ../manual_tests/manual_2.in
tc_manual ../manual_tests/manual_3.in
tc_manual ../manual_tests/manual_4.in
tc_manual ../manual_tests/manual_5.in
tc_manual ../manual_tests/manual_6.in
tc_manual ../manual_tests/manual_7.in
tc_manual ../manual_tests/manual_8.in
tc_manual ../manual_tests/manual_9.in
tc_manual ../manual_tests/manual_10.in
tc_manual ../manual_tests/manual_11.in
tc_manual ../manual_tests/manual_12.in

group g2 25
limits maxn=3000 maxr=1000
include_group g1
tc g2-1 gen mode="random" n=3000 r=1000
tc g2-2 gen mode="random" n=3000 r=1000
tc g2-3 gen mode="random" n=3000 r=1000
tc g2-4 gen mode="max" n=3000 r=1000 
tc g2d-1 gen_danish n=3000 minr=900 maxr=1000
tc g2d-2 gen_danish n=2989 minr=0   maxr=5
tc g2d-3 gen_danish n=2987 minr=0   maxr=100
tc g2d-4 gen_danish n=2999 minr=300 maxr=600
tc g2d-5 gen_danish n=2999 minr=990 maxr=1000
tc g2d-6 gen_danish n=2998 minr=999 maxr=1000
tc g2d-7 gen_danish n=3000 minr=997 maxr=1000


group g3 15
limits maxn=$MAXN maxr=10000
include_group g2
tc g3-1 gen mode="random" n=$MAXN r=10000
tc g3-2 gen mode="random" n=$MAXN r=10000
tc g3-3 gen mode="random" n=$MAXN r=10000
tc g3-4 gen mode="max" n=$MAXN r=10000 
tc g3d-1 gen_danish n=300000 minr=9990 maxr=10000
tc g3d-2 gen_danish n=300000 minr=9990 maxr=10000
tc g3d-3 gen_danish n=299999 minr=8000 maxr=10000
tc g3d-4 gen_danish n=299989 minr=0    maxr=10000
tc g3d-5 gen_danish n=299799 minr=0    maxr=20


group g4 45
limits maxn=$MAXN maxr=$MAXR
include_group g3
tc g4-1 gen mode="random" n=$MAXN r=$MAXR
tc g4-2 gen mode="random" n=$MAXN r=$MAXR
tc g4-3 gen mode="random" n=$MAXN r=$MAXR
tc g4-4 gen mode="max" n=$MAXN r=$MAXR
tc g4-5 gen mode="max" n=200000 r=$MAXR
tc g4-6 gen mode="max" n=100000 r=$MAXR
tc g4d-1 gen_danish n=300000 minr=299900 maxr=300000
tc g4d-2 gen_danish n=300000 minr=290000 maxr=300000
tc g4d-3 gen_danish n=222222 minr=100000 maxr=300000
tc g4d-4 gen_danish n=299999 minr=200000 maxr=300000
tc g4d-5 gen_danish n=299999 minr=0      maxr=300000
tc g4d-6 gen_danish n=299878 minr=290000 maxr=300000
