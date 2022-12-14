#coding=utf-8
def sell(n):
    days = 0
    while n>0:
        sold=n//2+2
        n-=sold         #假设每天剩余桃子数一定为偶数
        days+=1
    return days

num= int(input("请输入桃子个数："))
result= sell(num)
print("{}天能够卖完{}个桃子".format (result,num))
