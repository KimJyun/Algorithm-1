def solution(a, b):
    answer = 0
    if ( a == b ) : return a
    first = min(a,b)
    second = max(a,b)
    for num in range(first,second+1) :
        answer += num
    return answer
