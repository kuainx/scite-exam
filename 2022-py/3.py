#coding=utf-8
patient=[1,2,5,7]
contact={1:[2,3],2:[1,4],3:[1,4],4:[3,2,5],5:[4,6],6:[5],7:[ ]}
#1-7号为已存在于字典contact的键
x=int(input("请输入待筛查人员身份编号（1～7）：")) 
answer=[ ]	#此列表存放可能关联的所有确诊病人,即输出答案
searched=[ ] 				#此列表存放已经搜索过的人员

def trace(p):
    if p in searched:	#防止已搜索过的人员二次搜索
        return
    searched.append(p)
    for i in contact[p]:
        if i==x or i in answer:
            continue
        if i in patient:
            answer.append(i)        
        trace(i)
        
trace(x)
print("待筛查人员%d关联的确诊病人为："%x)
if answer==[ ]:
    print(0)
for i in answer:
    print(i,end=' ')
