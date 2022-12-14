import tkinter
import math
root=tkinter.Tk()
root.geometry('600x600')
canvas=tkinter.Canvas(root,height=600,width=600)
canvas.create_line(300,0,300,600,fill="red")
canvas.create_line(0,300,600,300,fill='red')
canvas.pack()

wh=300
hh=300
t=0.0
def x(t):
    x=wh*((1+math.cos(5*t)+math.sin(3*t)**2)*math.sin(t))/4+300
    return x
def y(t):
    x=-hh*((1+math.cos(2*t)+math.sin(3*t)**2)*math.cos(t))/4+300
    return x
   
                       
while(t<=2*math.pi):
    canvas.create_line(x(t),y(t),x(t+0.01),y(t+0.01),fill='blue')
    t+=0.01

canvas.pack()
