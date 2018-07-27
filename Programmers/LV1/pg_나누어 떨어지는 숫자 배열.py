
def solution(arr, divisor):
    answer = []
    for eachNum in arr :
        if ( eachNum%divisor == 0) : answer.append(eachNum)
    if ( len(answer) == 0 ) : answer.append(-1)
    return sorted(answer)
