import sqlite3
dat={}
c = sqlite3.connect("sc/fangyi.db")
for row in c.execute('SELECT * FROM lianxi'):
    dat[row[1]]=[row[2],row[3]]
while(True):
    name=input("社区")
    if name=='0':
        break;
    print(dat[name])
