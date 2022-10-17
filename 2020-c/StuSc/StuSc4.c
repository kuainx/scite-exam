//StuSc4.c
#include <stdio.h>
#define N 100
int sca(int num[], float score[])
{ //输入学生数，每位学生的学号、成绩
    int n;
    printf("请输入多个学生的学号及成绩，学号-1表示结束：\n");
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
{ //统计分析
    int i, ct1=0, ct2=0, x1=0, x2=0, k1=-1, k2=-1;
    float avg=0, r1=0, r2=0;
    for (i=0; i<n; i++)
    {
        avg += score[i];
        if (score[i]>=60) ct1++;    //合格数
        if (score[i]>=85) ct2++;    //优秀数
        if (score[i]>score[x1]) x1=i;   //最大值
        if (score[i]<score[x2]) x2=i;   //最小值
        if (score[i]<60 && (k1<0 || score[i]>score[k1])) k1=i;
        if (score[i]<85 && (k2<0 || score[i]>score[k2])) k2=i;
    }
    printf("学生数=%d\n", n );
    if (n>0)
    {
        avg /= n;
        r1 = 100.0*ct1/n;
        r2 = 100.0*ct2/n;
        printf("平均成绩=%.1f，", avg );
        printf("合格率=%.1f%%，优秀率=%.1f%%\n", r1, r2 );
        printf("班级最高分=%.1f(%d), 班级最低分=%.1f(%d)\n", 
                score[x1], num[x1], score[x2], num[x2] );
        if (k1>=0)
            printf("最接近合格=%.1f(%d)，", score[k1], num[k1] );
        else if (k2>=0)
            printf("所有学生合格或以上，");
        //
        if (k2>=0)
            printf("最接近优秀=%.1f(%d)\n", score[k2], num[k2] );
        else
            printf("所有学生均为优秀\n");
        //
    }
}
void sort(int num[], float score[], int n)
{ //成绩从高到低排序
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
    printf("成绩排名(%d)：\n", n);
    for (i=0; i<n; i++)
    {
        if (i==0 || score[i]!=score[i-1])
            j = i+1;
        printf("{%d} %d %.1f\n", j, num[i], score[i]);
    }
}
int main(void)
{ //主函数
    int num[N] = {0};
    float score[N] = {0};
    int n = 0;
    printf("[StuSc4]\n");
    n = sca(num, score);
    total(num, score, n);
    sort(num, score, n);
    return 0;
}
