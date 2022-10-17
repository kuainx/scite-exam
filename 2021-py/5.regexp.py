import re
import csv
regdat=[]
with open('sc/h.txt') as f:
    dat = f.read()
    m = re.findall('<a href="(http.*?)" mon="ct=1&amp;a=2&amp;c=top&pn=\w+" target="_blank">(.*?)</a>',dat)
    for d in m:
        regdat.append(d)
with open('news.csv', 'w', newline='') as csvfile:
    spamwriter = csv.writer(csvfile, delimiter=',')
    for d in regdat:
        spamwriter.writerow(d)
