#!/bin/python3

import math
import os
import random
import re
import sys
from typing import List

# Complete the sockMerchant function below.
def sockMerchant(n:int, ar:List[int]) -> int :
    socks = set(ar)
    rlt = 0
    for each in socks :
        print(each,ar.count(each))
        rlt += int( ar.count(each)/2)
    return rlt

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()