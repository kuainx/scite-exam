#coding=utf-8
print('*'*40)
print('欢迎某市车辆限行咨询平台！')
print('*'*40)
text=int(input("请输入车牌:"))
i=1
code=text[-i]
while not code.isdigit():
    i-=1
    code=text[-i]
t=int(code)
if t==1 or t==9:
    print("每周一禁行")
elif t==2 or t==8:
    print("每周二禁行")
elif t==3 or t==7:
    print("每周三禁行")
elif t==4 or t==6:
    print("每周四禁行")
else t==5 or t==0:
    print("每周五禁行")
