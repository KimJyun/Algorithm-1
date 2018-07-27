import datetime

def solution(a, b):
    day         = ['MON','TUE','WED','THU','FRI','SAT','SUN']
    checkDate   = datetime.date(2016,a,b)
    answer      = day[checkDate.weekday()]
    return answer
