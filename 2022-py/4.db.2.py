#解法2：通过sql语句处理
import sqlite3
con = sqlite3.connect('Edu_Base.db')
cur = con.cursor()
dat=[]
while True:
    name=input("基地名称：")
    place=input("地点：")
    ans=[]
    if name!="":
        cur.execute('INSERT INTO baselist("name","place","batch") VALUES ("{}","{}","第八批")'.format(name,place))
        con.commit()
    for row in cur.execute('SELECT * FROM baselist WHERE place="{}"'.format(place)):
        dat.append(row)
    print(dat)
        
        
    

