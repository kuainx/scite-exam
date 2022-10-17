    //ͼ�����ɷ�������bmpSample.c
#include <stdio.h>
#include <math.h>
#include "mybmp.h"      //����ͼ��������Դ��
//����ͼ���ļ�fn��w��h�У��������x1���ҽ�x2���½�y1���Ͻ�y2
void drawPicture(char *fn,int w,int h,double x1,double x2,double y1,double y2)
{
    double x, y, d;
    int i, j;
    printf("fn=%s, w=%d, h=%d\n", fn, w, h);
    printf("x1=%lg, x2=%lg, y1=%lg, y2=%lg\n", x1, x2, y1, y2);
    bmpInitial(w, h);           //������Դ��������ʼ����Ϣ
    for (i=0; i<h; i++)         //����ѭ����ͼ���±߶�Ӧ0��
    {
        y = y1 + i*(y2-y1)/h;       //�����i�ж�Ӧ��y����
        for (j=0; j<w; j++)         //����ѭ����ͼ����߶�Ӧ0��
        {
            x = x1 + j*(x2-x1)/w;       //�����j�ж�Ӧ��x����
            d = sqrt(x*x + y*y);        //����(x,y)��(0,0)�ľ���
            if (d>0.8)                      //�뾶0.8����
                bmpSetPixel(i, j, 0, 255, 255);     //��ɫ
                //������Դ���������õ�i�е�j�е���ɫ����ɫ��
            else if (x>=0 && y>=0)          //��һ����
                bmpSetPixel(i, j, 255, 0, 0);       //��ɫ
            else if (x<0 && y>=0)           //�ڶ�����
                bmpSetPixel(i, j, 0, 255, 0);       //��ɫ
            else if (x<0 && y<0)            //��������
                bmpSetPixel(i, j, 0, 0, 255);       //��ɫ
            else                            //��������
                bmpSetPixel(i, j, 255, 0, 255);     //��ɫ
        }
    }
    bmpWriteToFile(fn);         //������Դ����������ͼ���ļ�
}
int main(void)
{
    int w=160, h=120;
    double x1=-2.5, y1=-2, x2=1.5, y2=1;
    drawPicture("bmpSample.BMP", w, h, x1, x2, y1, y2);
    return 0;
}
/*���������
fn=bmpSample.BMP, w=160, h=120
x1=-2.5, x2=1.5, y1=-2, y2=1
*/
