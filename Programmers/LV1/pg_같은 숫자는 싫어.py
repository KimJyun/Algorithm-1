def solution(arr):
    checker = None
    rlt     = list()

    rlt.append(arr[0])
    checker = arr[0]

    for num in arr[1:] :
        if ( num != checker ):
            rlt.append(num)
            checker = num

    return rlt
