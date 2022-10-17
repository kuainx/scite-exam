#ifndef _MYBMP_H
#define _MYBMP_H

////�ṩ����3��ͼ���ļ�����Դ����

//bmpInitial��ʼ��ͼ����Ϣ��wΪͼ���ȣ�hΪͼ��߶�
//ʹ��ʱ�����ȵ���bmpInitialһ��
void bmpInitial(int w,int h);
//
//bmpSetPixel����i��j�еĺ������ֱ�Ϊr,g,b
//ʹ��ʱbmpSetPixel���ٵ���w��*h�дΣ�ÿ�ε�������һ������
//iȡֵ0��h-1��jȡֵ0��w-1��r/g/bȡֵ0��255
void bmpSetPixel(int i,int j,int r,int g,int b);
//
//bmpWriteToFile��ͼ������д�뵽ͼ���ļ�fn�У����سɹ�0��ʧ��-1
//ʹ��ʱbmpWriteToFile��������һ��
int bmpWriteToFile(char *fn);
//

////����Ϊ��Դ������ʵ�ִ��룬����ֱ����.h������һ��
#include <stdlib.h>

//����.BMP��ʽͼ���ļ���ͷ��Ϣ
struct BitmapHead
{   //.bmp�ļ�ͷ��ʽ��ÿ����24λʱ
    char bm[2];     //�ļ���ʶ������Ϊ"BM"
    long flen;      //�ļ����ȣ�=w*h*3+0x36
    long res1;      //������=0
    long offset;    //λͼ����λ�ã�=0x36
    long hlen;      //λͼ��Ϣ���ȣ�=0x28
    long width;     //ͼ���ȣ�=w
    long height;    //ͼ��߶ȣ�=h
    short planes;   //ͼ��λƽ������=1
    short bit;      //ÿ����λ����=24
    long res2;      //������=0
    long dlen;      //ͼ�����ݳ��ȣ�=w*h*3
    long res3[4];   //������=0
};

//��������ͼ���ļ���ȫ�ֱ���
unsigned char *gvp=NULL;    //ͼ�����ݴ洢λ�õ�ָ��
int gvw=0, gvh=0;           //ͼ�����ݵ�����������
//ͼ�����ݴ洢˳�򣺴ӵ�0����gvh-1�У�ÿ�дӵ�0��w-1��
//  ÿ���ذ������̡���˳��洢��ÿ����һ���ֽ�

//bmpInitial��ʼ��ͼ����Ϣ��wΪͼ���ȣ�hΪͼ��߶�
//ʹ��ʱ�����ȵ���bmpInitialһ��
void bmpInitial(int w,int h)
{
    gvw = w;
    gvh = h;
    if (gvp!=NULL)
        free(gvp);
    gvp = (unsigned char *)malloc(w*h*3);
}

//bmpSetPixel����i��j�еĺ������ֱ�Ϊr,g,b
//ʹ��ʱbmpSetPixel���ٵ���w��*h�дΣ�ÿ�ε�������һ������
//iȡֵ0��h-1��jȡֵ0��w-1��r/g/bȡֵ0��255
void bmpSetPixel(int i,int j,int r,int g,int b)
{
    if (gvp!=NULL)
    {
        gvp[3*(i*gvw+j)+0] = b;
        gvp[3*(i*gvw+j)+1] = g;
        gvp[3*(i*gvw+j)+2] = r;
    }
}

//bmpWriteToFile��ͼ������д�뵽ͼ���ļ�fn�У����سɹ�0��ʧ��-1
//ʹ��ʱbmpWriteToFile��������һ��
//�ļ�fn����չ��Ϊ.BMP
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
