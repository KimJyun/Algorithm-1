def solution(s):
    str     = s.lower()
    p_num   = str.count('p')
    y_num   = str.count('y')
    rlt     = False
    if (p_num == y_num) : rlt = True
    return rlt
