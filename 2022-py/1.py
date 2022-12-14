#coding=utf-8
work={"1001":[4,1,1,0],
"1002":[3,0,2,1],
"1003":[0,3,0,3],
"1004":[6,0,0,0],
"1005":[5,0,1,0]
}
max_score=0   #初始化最高分为0分
print('学号\t特色分\t扣分点1\t扣分点2\t扣分点3\t分数')
for k in work:
    total=15+work[k][0]-work[k][1]*0.5-work[k][2]*0.5-work[k][3]
    if max_score<total:
        max_score = total
    work[k]. append (total) 
    print("{}\t{}\t{}\t{}\t{}\t{}".format(k,work[k][0],work[k][1], work[k][2],work[k][3],work[k][4]))
    
print("\n最高分同学成绩为：")
for k in work:
    if work[k][4] == max_score: 
        print("{}\t{}\t{}\t{}\t{}\t{}".format(k,work[k][0],work[k][1], work[k][2],work[k][3],work[k][4]))
