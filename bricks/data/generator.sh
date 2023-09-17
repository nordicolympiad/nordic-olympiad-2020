#!/usr/bin/env bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution joshua_full.cpp

compile gen.py
compile gen_danish.py

samplegroup
limits maxn=5
sample 1

group g1 30
limits maxn=5
tc 1
tc g1-1 gen mode=random n=5
tc g1-2 gen mode=random n=5
tc g1-3 gen mode=random n=5
tc g1-4 gen mode=random n=5
tc g1d-1 gen_danish n=2 maxscore=20
tc g1d-2 gen_danish n=3 maxscore=20
tc g1d-3 gen_danish n=4 maxscore=20
tc g1d-4 gen_danish n=5 maxscore=20
tc g1d-5 gen_danish n=1
tc g1d-6 gen_danish n=2
tc g1d-7 gen_danish n=3
tc g1d-8 gen_danish n=4
tc g1d-9 gen_danish n=5

group g2 70
limits maxn=300
include_group g1
tc g2-1 gen mode=random n=300
tc g2-2 gen mode=random n=300
tc g2-3 gen mode=random n=300
tc g2d-1 gen_danish n=9
tc g2d-2 gen_danish n=10
tc g2d-3 gen_danish n=49
tc g2d-4 gen_danish n=50
tc g2d-5 gen_danish n=99
tc g2d-6 gen_danish n=100
tc g2d-7 gen_danish n=199
tc g2d-8 gen_danish n=200
tc g2d-9 gen_danish n=249
tc g2d-10 gen_danish n=250
tc g2d-11 gen_danish n=289
tc g2d-12 gen_danish n=290
tc g2d-13 gen_danish n=299
tc g2d-14 gen_danish n=300

