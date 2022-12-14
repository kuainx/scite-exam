import math
import simple_math
n=int(input("n="))
s=0
def getsingle(n):
    return (-1)**(n-1) * (3*n+1)*(n+2)/(n+1)/(2*n+3)
for i in range(1,n+1):
    s+=getsingle(i)
s0=round(s,5)
print(s0)

print("分解算式：{}".format(simple_math.exno(s)))
