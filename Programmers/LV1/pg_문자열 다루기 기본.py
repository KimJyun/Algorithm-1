def solution(s):
    answer = False
    try :
        checkNum = int(s)
        checkLen = len(s)
        if (checkLen == 4 or checkLen == 6) : answer = True
    except :
        answer = False
    return answer
