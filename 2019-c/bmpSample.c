    //图像生成范例程序bmpSample.c
#include <stdio.h>
#include <math.h>
#include "mybmp.h"      //包含图像生成资源库
//生成图像文件fn，w列h行，坐标左界x1，右界x2，下界y1，上界y2
void drawPicture(char *fn,int w,int h,double x1,double x2,double y1,double y2)
{
    double x, y, d;
    int i, j;
    printf("fn=%s, w=%d, h=%d\n", fn, w, h);
    printf("x1=%lg, x2=%lg, y1=%lg, y2=%lg\n", x1, x2, y1, y2);
    bmpInitial(w, h);           //调用资源函数，初始化信息
    for (i=0; i<h; i++)         //逐行循环，图像下边对应0行
    {
        y = y1 + i*(y2-y1)/h;       //计算第i行对应的y坐标
        for (j=0; j<w; j++)         //逐列循环，图像左边对应0列
        {
            x = x1 + j*(x2-x1)/w;       //计算第j列对应的x坐标
            d = sqrt(x*x + y*y);        //计算(x,y)与(0,0)的距离
            if (d>0.8)                      //半径0.8以外
                bmpSetPixel(i, j, 0, 255, 255);     //青色
                //调用资源函数，设置第i行第j列的颜色（着色）
            else if (x>=0 && y>=0)          //第一象限
                bmpSetPixel(i, j, 255, 0, 0);       //红色
            else if (x<0 && y>=0)           //第二象限
                bmpSetPixel(i, j, 0, 255, 0);       //绿色
            else if (x<0 && y<0)            //第三象限
                bmpSetPixel(i, j, 0, 0, 255);       //兰色
            else                            //第四象限
                bmpSetPixel(i, j, 255, 0, 255);     //紫色
        }
    }
    bmpWriteToFile(fn);         //调用资源函数，生成图像文件
}
int main(void)
{
    int w=160, h=120;
    double x1=-2.5, y1=-2, x2=1.5, y2=1;
    drawPicture("bmpSample.BMP", w, h, x1, x2, y1, y2);
    return 0;
}
/*运行输出：
fn=bmpSample.BMP, w=160, h=120
x1=-2.5, x2=1.5, y1=-2, y2=1
*/
