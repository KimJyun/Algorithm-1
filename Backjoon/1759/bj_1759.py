
def checkVowel(alphaList) :
        vowelList = ["a","e","i","o","u"]
        V_list = list()
        C_list = list()
        for each in alphaList :
                if ( each in vowelList ) :
                        V_list.append(each)
                else :
                        C_list.append(each)
        return (sorted(V_list), sorted(C_list))

def getComponents(targetList,numOfElemnets) :

        rltList         = list()
        cursorList      = list()
        exitList        = list()
        for i in range(numOfElemnets) :
                cursorList.append(i)
                exitList.append(len(targetList)-i-1)
        exitList = sorted(exitList)
        
        
        while(True) :
                eachList = list()
                for i in range(len(cursorList)) :
                        eachList.append(targetList[cursorList[i]])
                rltList.append(eachList)
                
                for i in range(-1, -numOfElemnets, -1) :

                        if ( cursorList[i] == exitList[i] ) :
                                cursorList[i-1] += 1
                                cursorList[i] = cursorList[i-1] + 1
                                if ( i != -1 ):
                                        cursorList[i+1] = cursorList[i]+1
                                
                                eachList = list()
                                for i in range(len(cursorList)) :
                                        eachList.append(targetList[cursorList[i]])
                                rltList.append(eachList)
                
                if ( cursorList == exitList ) : break
                cursorList[-1] = cursorList[-1] + 1
        return rltList
                


        


if ( __name__ == "__main__" ) :

        numOfPW,numOfAlpha      = input().strip().split()
        numOfPW                 = int(numOfPW)
        numOfAlpha              = int(numOfAlpha)
        alphaList               = input().strip().split()
        V_list,C_list           = checkVowel(alphaList)

        rltList = list()
        numOfCheck = numOfPW

        # 1개의 vowel 와
        # 2개의 consonent 를 뽑는다.

        curr_V_list = getComponents(V_list,1)
        curr_C_list = getComponents(C_list,2)
        numOfCheck -= 3


        # 각각에서 하나씩 뽑고 그것을 제외한 나머지 배열을 만든다.
        # 나머지 배열에서 남은 수만 큼 뽑는다.
        for each_V_list in curr_V_list :
                remainAlpha = alphaList
                for each_V in each_V_list :
                        remainAlpha.remove(each_V)
                for each_C_list in curr_C_list :
                        for each_C in each_C_list :
                                remainAlpha.remove(each_C)
                
                




        # 나머지 배열에서 나머지 알파벳을 뽑는다.












 

        

        rltList = list()








        

        



