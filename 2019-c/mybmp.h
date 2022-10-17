#ifndef _MYBMP_H
#define _MYBMP_H

////提供以下3个图像文件的资源函数

//bmpInitial初始化图像信息，w为图像宽度，h为图像高度
//使用时必须先调用bmpInitial一次
void bmpInitial(int w,int h);
//
//bmpSetPixel设置i行j列的红绿兰分别为r,g,b
//使用时bmpSetPixel至少调用w列*h行次，每次调用设置一个像素
//i取值0至h-1，j取值0至w-1，r/g/b取值0至255
void bmpSetPixel(int i,int j,int r,int g,int b);
//
//bmpWriteToFile将图像数据写入到图像文件fn中，返回成功0或失败-1
//使用时bmpWriteToFile在最后调用一次
int bmpWriteToFile(char *fn);
//

////以下为资源函数的实现代码，这里直接与.h整合在一起
#include <stdlib.h>

//以下.BMP格式图像文件的头信息
struct BitmapHead
{   //.bmp文件头格式，每像素24位时
    char bm[2];     //文件标识，必须为"BM"
    long flen;      //文件长度，=w*h*3+0x36
    long res1;      //保留，=0
    long offset;    //位图数据位置，=0x36
    long hlen;      //位图信息长度，=0x28
    long width;     //图像宽度，=w
    long height;    //图像高度，=h
    short planes;   //图像位平面数，=1
    short bit;      //每像素位数，=24
    long res2;      //其他，=0
    long dlen;      //图像数据长度，=w*h*3
    long res3[4];   //其他，=0
};

//用于生成图像文件的全局变量
unsigned char *gvp=NULL;    //图像数据存储位置的指针
int gvw=0, gvh=0;           //图像数据的列数、行数
//图像数据存储顺序：从第0至第gvh-1行，每行从第0至w-1列
//  每像素按兰、绿、红顺序存储，每分量一个字节

//bmpInitial初始化图像信息，w为图像宽度，h为图像高度
//使用时必须先调用bmpInitial一次
void bmpInitial(int w,int h)
{
    gvw = w;
    gvh = h;
    if (gvp!=NULL)
        free(gvp);
    gvp = (unsigned char *)malloc(w*h*3);
}

//bmpSetPixel设置i行j列的红绿兰分别为r,g,b
//使用时bmpSetPixel至少调用w列*h行次，每次调用设置一个像素
//i取值0至h-1，j取值0至w-1，r/g/b取值0至255
void bmpSetPixel(int i,int j,int r,int g,int b)
{
    if (gvp!=NULL)
    {
        gvp[3*(i*gvw+j)+0] = b;
        gvp[3*(i*gvw+j)+1] = g;
        gvp[3*(i*gvw+j)+2] = r;
    }
}

//bmpWriteToFile将图像数据写入到图像文件fn中，返回成功0或失败-1
//使用时bmpWriteToFile在最后调用一次
//文件fn的扩展名为.BMP
int bmpWriteToFile(char *fn)
{
    int w=gvw, h=gvh;
    struct BitmapHead bh = {{'B','M'},0x36+w*h*3,0,0x36,0x28,w,h,1,24,0,w*h*3,{0,0,0,0}};
    FILE *fp;
    if (gvp==NULL) return -1;
    fp = fopen(fn,"wb");
    if (fp==NULL) return -1;
    fwrite(&bh,0x2,1,fp);
    fwrite(&bh.flen,0x34,1,fp);
    fwrite(gvp,1,w*h*3,fp);
    fclose(fp);
    free(gvp);
    gvp = NULL;
    return 0;
}

#endif
