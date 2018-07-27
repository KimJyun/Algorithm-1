import math
def solution(s):
    index = math.floor(len(s)/2)
    answer = None
    if (len(s)%2)       : answer = s[index]
    else                : answer = s[index-1:(index+1)]
    return answer
