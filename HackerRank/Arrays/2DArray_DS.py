#!/bin/python3

import math
import os
import random
import re
import sys
from typing import List

# Complete the hourglassSum function below.
# Complete the hourglassSum function below.
def hourglassSum(arr:List[int]) -> int:
    rlt = sys.maxsize * -1
    I_filter = [[1,1,1],[0,1,0],[1,1,1]]
    for i in range(len(arr)) :
        if i+2 >= len(arr) : continue
        for j in range(len(arr[i])) :
            if j+2 >= len(arr) : continue
            row1 = [arr[i][j],   arr[i][j+1],     arr[i][j+2]]
            row2 = [arr[i+1][j], arr[i+1][j+1],   arr[i+1][j+2]]
            row3 = [arr[i+2][j], arr[i+2][j+1],   arr[i+2][j+2]]

            rlt = max(rlt,\
                mul_three_maxtrix(I_filter[0],row1) +\
                mul_three_maxtrix(I_filter[1],row2) +\
                mul_three_maxtrix(I_filter[2],row3) )
    return rlt


def mul_three_maxtrix(arr1, arr2) :
    rlt = 0
    for i in range(3) :
        rlt += arr1[i]*arr2[i]
    return rlt

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
