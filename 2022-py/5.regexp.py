import re
import csv

with open('h1.txt', 'r', encoding="utf-8") as file:
    dat=file.read()
    result=re.findall('<li class=\"name_list\"><a href=\"(.*)\" target=\"_blank\">(.*)</a></li>',dat)
    #注意！双引号要转义，将需要提取的部分用(.*)替代
with open('mem.csv', 'w', newline='') as csvfile:
    spamwriter = csv.writer(csvfile)
    for row in result:
        spamwriter.writerow(["https://"+row[0],row[1]])

    
