import tkinter
import math
root=tkinter.Tk()
root.geometry('500x500')
canvas=tkinter.Canvas(root,height=500,width=500)
canvas.create_line(250,0,250,500,fill="red")
canvas.create_line(0,250,500,250,fill='red')
canvas.pack()

wh=250
hh=250
t=0.0
def x(t):
    x=-wh*(math.cos(t)+0.5*math.cos(7*t)+1/3*math.sin(17*t))/2+wh
    return x
def y(t):
    x=hh*(math.sin(t)+0.5*math.sin(7*t)+1/3*math.cos(17*t))/2+hh
    return x
   
                       
while(t<=2*math.pi):
    canvas.create_line(x(t),y(t),x(t+0.01),y(t+0.01),fill='blue')
    t+=0.01

canvas.pack()
