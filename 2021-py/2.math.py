import math
import scre
def single(n):
    return 1/n/n
while (True):
    n=int(input('n='))
    if(n==0):
        break
    sum=0.0
    for i in range(1,n):
        sum+=single(i)
    sum*=6
    sum=math.pow(sum,0.5)
    print(sum)
    print(scre.zna(sum))
