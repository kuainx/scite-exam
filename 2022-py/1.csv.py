import csv
max_play=0;
max_play_arr=[]
title=0;

with open('pyt.csv', newline='') as csvfile:
     spamreader = csv.reader(csvfile, delimiter=',', quotechar=',')
     for row in spamreader:
         if title == 0:
             title=1;
         elif max_play < float(row[3]):
             max_play=float(row[3])
             max_play_arr=row
     print("播放量最高的标题：")
     print(max_play_arr[1])
     print("播放量为{:.2f}万次".format(float(max_play_arr[3])))
