#解法1：将所有数据读入py处理
import sqlite3
con = sqlite3.connect('Edu_Base.db')
cur = con.cursor()
dat=[]
for row in cur.execute('SELECT * FROM baselist'):
    dat.append(row)

while True:
    name=input("基地名称：")
    place=input("地点：")
    ans=[]
    if name!="":
        cur.execute('INSERT INTO baselist("name","place","batch") VALUES ("{}","{}","第八批")'.format(name,place))
        con.commit()
        for row in cur.execute('SELECT * FROM baselist'):
            dat.append(row)
    if place=="0":
        break
    for row in dat:
        if row[2]==place:
            ans.append(row)
    print(ans)
        
        
    

