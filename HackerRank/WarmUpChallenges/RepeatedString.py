#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the repeatedString function below.
def repeatedString(s:str, n:int) -> int:
    rlt = 0
    block = s.count('a')
    rlt += int(n/len(s)) * block
    remain = n%len(s)

    if remain is not 0 :
        rlt += s[:remain].count('a')
    
    return rlt

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    n = int(input())

    result = repeatedString(s, n)

    fptr.write(str(result) + '\n')

    fptr.close()
