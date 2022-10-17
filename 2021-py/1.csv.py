import csv
from datetime import date
import time
dat=[]
maxN=0
maxD=''
with open('sc/covid19mousheng.txt', newline='') as f:
    reader = csv.reader(f)
    for row in reader:
        dat.append([row[0],row[4]])
    for i in range(len(dat)):
        if i<=1:
            continue
        d=int(dat[i][1])-int(dat[i-1][1])
        if d>=maxN:
            maxN=d
            maxD=dat[i][0]
    print(maxD,maxN)
    print(time.strftime('%Y年%m月%d日',time.strptime(maxD,"%m/%d/%Y")))
