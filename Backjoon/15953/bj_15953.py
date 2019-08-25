def calcPrice(rank_2017, rank_2018) :
    price_2017 = [[1,500],[2,300],[3,200],[4,50],[5,30],[6,10]]
    price_2018 = [[1,512],[2,256],[4,128],[8,64],[16,32]]
    price_list = [price_2017,price_2018]
    my_price   = 0

    for no,year in enumerate(price_list) :
        current_rank = 0
        if no == 0  : my_rank = rank_2017
        else        : my_rank = rank_2018

        for rank in range(len(year)) :
            each_person = year[rank][0]

            for _ in range(each_person) :
                current_rank += 1
                if (current_rank == my_rank) :
                    my_price += year[rank][1]
                    break
                else : continue

    return my_price

    
if __name__ == "__main__" :
    numOfinput  = int(input())
    rltList     = list()

    for _ in range(numOfinput) :
        rank_2017, rank_2018 = input().split()
        rltList.append(calcPrice(int(rank_2017),int(rank_2018))*10000)

    for i in range(len(rltList)) :
        print(rltList[i])