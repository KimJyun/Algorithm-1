
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

        # 1?????? vowel ???
        # 2?????? consonent ??? ?????????.


        curr_V_list = getComponents(V_list,1)
        curr_C_list = getComponents(C_list,2)
        numOfCheck -= 3


        # ???????????? ????????? ?????? ????????? ????????? ????????? ????????? ?????????.
        # ????????? ???????????? ?????? ?????? ??? ?????????.
        for each_V_list in curr_V_list :

                V_AlphaList = list()
                V_remainAlpha = list(alphaList)

                for each_V in each_V_list :
                        V_remainAlpha.remove(each_V)
                        V_AlphaList.append(each_V)

                for each_C_list in curr_C_list :
                        remainAlpha = list(V_remainAlpha)
                        rltAlphaList = list(V_AlphaList)

                        for each_C in each_C_list :
                                remainAlpha.remove(each_C)
                                rltAlphaList.append(each_C)

                        # ??? ????????? ??? ?????? ????????? ???????????? ????????? ???????????? ?????????.

                        if ( numOfCheck > 0 ) :
                                pickRemains = getComponents(remainAlpha,numOfCheck)
                                
                                for each_remainAlpha in pickRemains :
                                        each_rltAlphaList = list(rltAlphaList) + each_remainAlpha
                                        each_rltAlphaList = sorted(each_rltAlphaList)

                                        if( each_rltAlphaList not in rltList ) :
                                                rltList.append(each_rltAlphaList)
                        else :
                                rltAlphaList = sorted(rltAlphaList)
                                if( rltAlphaList not in rltList ) :
                                        rltList.append(rltAlphaList)
                                

        
        for eachList in sorted(rltList) :
                rlt = ""
                for alpha in eachList :
                        rlt += alpha
                print(rlt)



