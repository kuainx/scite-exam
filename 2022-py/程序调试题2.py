#coding=utf-8
s='创新'
a= input("输入行数") ####
a=int(a)
for i in range(1,a+1):
    print(' ' * 2 * (a - i),end="") ####
    print(s * i)
for i in range(a,0,-1): ####
    print(' ' * 2 * (a - i),end="")
    print(s * i)
