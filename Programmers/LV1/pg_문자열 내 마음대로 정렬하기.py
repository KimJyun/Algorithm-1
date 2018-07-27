def solution(strings, n):
    rlt = sorted ( strings, key = lambda x : (x[n],x.lower()) )
    return rlt
