#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countingValleys function below.
def countingValleys(n:int, s:str) -> int:
    curr = 0
    valles = 0
    for ch in s :
        if ch.upper() == "D" : 
            if curr == 0 : valles += 1
            curr -= 1
        else : curr += 1
    return valles

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = countingValleys(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()
