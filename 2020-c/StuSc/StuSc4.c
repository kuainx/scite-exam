//StuSc4.c
#include <stdio.h>
#define N 100
int sca(int num[], float score[])
{ //����ѧ������ÿλѧ����ѧ�š��ɼ�
    int n;
    printf("��������ѧ����ѧ�ż��ɼ���ѧ��-1��ʾ������\n");
    for (n=0; 1; n++)
    {
        if (n>=N) break;
        num[n] = -1; score[n] = -1;
        scanf("%d%f", &num[n], &score[n]);
        if (num[n]<0) break;
    }
    return n;
}
void total(int num[], float score[], int n)
{ //ͳ�Ʒ���
    int i, ct1=0, ct2=0, x1=0, x2=0, k1=-1, k2=-1;
    float avg=0, r1=0, r2=0;
    for (i=0; i<n; i++)
    {
        avg += score[i];
        if (score[i]>=60) ct1++;    //�ϸ���
        if (score[i]>=85) ct2++;    //������
        if (score[i]>score[x1]) x1=i;   //���ֵ
        if (score[i]<score[x2]) x2=i;   //��Сֵ
        if (score[i]<60 && (k1<0 || score[i]>score[k1])) k1=i;
        if (score[i]<85 && (k2<0 || score[i]>score[k2])) k2=i;
    }
    printf("ѧ����=%d\n", n );
    if (n>0)
    {
        avg /= n;
        r1 = 100.0*ct1/n;
        r2 = 100.0*ct2/n;
        printf("ƽ���ɼ�=%.1f��", avg );
        printf("�ϸ���=%.1f%%��������=%.1f%%\n", r1, r2 );
        printf("�༶��߷�=%.1f(%d), �༶��ͷ�=%.1f(%d)\n", 
                score[x1], num[x1], score[x2], num[x2] );
        if (k1>=0)
            printf("��ӽ��ϸ�=%.1f(%d)��", score[k1], num[k1] );
        else if (k2>=0)
            printf("����ѧ���ϸ�����ϣ�");
        //
        if (k2>=0)
            printf("��ӽ�����=%.1f(%d)\n", score[k2], num[k2] );
        else
            printf("����ѧ����Ϊ����\n");
        //
    }
}
void sort(int num[], float score[], int n)
{ //�ɼ��Ӹߵ�������
    int i, j, tn;
    float ts;
    for (i=0; i<n-1; i++)
    {
        for (j=0; j<n-1-i; j++)
            if (score[j]<score[j+1] || (score[j]==score[j+1] && num[j]>num[j+1]))
            {
                tn = num[j];
                num[j] = num[j+1];
                num[j+1] = tn;
                ts = score[j];
                score[j] = score[j+1];
                score[j+1] = ts;
            }
    }
    printf("�ɼ�����(%d)��\n", n);
    for (i=0; i<n; i++)
    {
        if (i==0 || score[i]!=score[i-1])
            j = i+1;
        printf("{%d} %d %.1f\n", j, num[i], score[i]);
    }
}
int main(void)
{ //������
    int num[N] = {0};
    float score[N] = {0};
    int n = 0;
    printf("[StuSc4]\n");
    n = sca(num, score);
    total(num, score, n);
    sort(num, score, n);
    return 0;
}
