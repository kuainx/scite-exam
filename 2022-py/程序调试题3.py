#coding=utf-8
def change(money): ####
    tmp=['总金额：'+str(money)+'元']
    cate=(100,50,20,10,5,2,1,0.5,0.2,0.1)
    sy=int(money*10)
    while True:
        if sy==0:
            break ####
        else:
            for row in cate:
                tmpStr=""
                jine=int(row*10)
                if sy>=jine:
                    m=sy//jine
                    sy=sy%jine
                    if jine>=10:
                        tmpStr=str(jine//10)+"元"+str(m)+'张'
                    else:
                        tmpStr=str(jine)+"角"+str(m)+'张' ####
                    tmp.append(tmpStr)
    return tmp
money=float(input("请输入金额："))
a=change(money)
for x in a:
    print(x)
