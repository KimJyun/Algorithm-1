#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c):
    strategy = list()
    for _ in c : strategy.append(sys.maxsize)
    strategy[0] = 0
    for i,step in enumerate(c) :
        if step is not 1 :
            if i+1<len(strategy) and c[i+1] != 1:
                strategy[i+1] = update(strategy,i+1,strategy[i]+1)
            if i+2<len(strategy) and c[i+2] != 1:
                strategy[i+2] = update(strategy,i+2,strategy[i]+1)
    return strategy[-1]

def update(strategy,targetIdx,jump) :
    return min(strategy[targetIdx],jump)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c)

    fptr.write(str(result) + '\n')

    fptr.close()
