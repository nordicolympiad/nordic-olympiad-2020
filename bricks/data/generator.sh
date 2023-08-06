#!/usr/bin/env bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

use_solution joshua_full.cpp

compile gen.py

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


group g2 70
limits maxn=300
include_group g1
tc g2-1 gen mode=random n=300
tc g2-2 gen mode=random n=300
tc g2-3 gen mode=random n=300

