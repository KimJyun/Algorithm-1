targetNum = int(input())
dpList = [-1,0,1,1]

for _ in range(4,targetNum+1) :
        dpList.append(9999)

for i in range(4,targetNum+1) :
        minOp = dpList[i-1]+1
        if( i%3 == 0) :
                minOp = min(dpList[int(i/3)]+1, minOp )
        if ( i%2 == 0):
                minOp = min(dpList[int(i/2)]+1, minOp)
        dpList[i] = minOp

print(dpList[targetNum])