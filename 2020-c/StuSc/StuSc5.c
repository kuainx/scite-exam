//StuSc5.c
#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef struct student  //学生结构体
{
    int num;       //学号，正整数
    float score;   //成绩，范围0至100之间
} STUDENT; //学生类型
int cmdAdd(STUDENT stu[], int n)
{ //处理A命令：修改或添加学生
    STUDENT x = {-1, -1};
    int i;
    scanf("%d %f", &x.num, &x.score);
    if (x.num<=0)
        printf("学号 %d 无效（必须为正数）\n", x.num);
    if (x.score<0 || x.score>100)
        printf("成绩 %g 无效（必须在0至100之间）\n", x.score);
    if (x.num>0 && x.score>=0 && x.score<=100)
    {
        for (i=0; i<n; i++)
            if (stu[i].num==x.num)
            {   //更改信息
                stu[i] = x;
                printf("更改学生，[%d] %d %.1f\n", i, x.num, x.score );
                return n;
            }
        if (n<N)
        {
            stu[n] = x;
            printf("添加学生，[%d] %d %.1f\n", i, x.num, x.score );
            n++;
        }
        else
            printf("学生数已达到上限(%d)，不能添加\n", N);
    }
    return n;
}
int cmdDel(STUDENT stu[], int n)
{ //处理D命令：删除学生
    int i, xn=-1;
    scanf("%d", &xn);
    for (i=0; i<n; i++)
        if (stu[i].num==xn)
        {
            printf("删除学生，[%d] %d %.1f\n", i, stu[i].num, stu[i].score );
            for (; i<n; i++)
                stu[i] = stu[i+1];
            n--;
            return n;
        }
    printf("未找到学号 %d 的学生\n", xn);
    return n;
}
void cmdList(STUDENT stu[], int n)
{ //处理L命令：学生信息列表
    int i;
    printf("学生列表(%d)：\n", n);
    for (i=0; i<n; i++)
    {
        printf("[%d] %d %.1f ", i, stu[i].num, stu[i].score);
        if (stu[i].score>=85)
            printf("优秀\n");
        else if (stu[i].score>=60)
            printf("合格\n");
        else
            printf("不合格\n");
    }
}
void cmdSort(STUDENT stu[], int n)
{ //处理S命令：按学号降序排序排名，但不改变stu数组
    STUDENT *t, *p[N];
    int i, j;
    for (i=0; i<n; i++)
        p[i] = &stu[i];
    for (i=0; i<n-1; i++)
    {
        for (j=0; j<n-1-i; j++)
            if (p[j]->score<p[j+1]->score || 
                (p[j]->score==p[j+1]->score && p[j]->num>p[j+1]->num))
            {
                t = p[j];
                p[j] = p[j+1];
                p[j+1] = t;
            }
    }
    printf("成绩排名(%d)：\n", n);
    for (i=0; i<n; i++)
    {
        if (i==0 || p[i]->score!=p[i-1]->score)
            j = i+1;
        printf("{%d} %d %.1f\n", j, p[i]->num, p[i]->score);
    }
}
void cmdTotal(STUDENT stu[],int n)
{ //处理T命令：统计学生信息
    int i, ct1=0, ct2=0, x1=0, x2=0, k1=-1, k2=-1;
    float avg=0, r1=0, r2=0;
    for (i=0; i<n; i++)
    {
        avg += stu[i].score;
        if (stu[i].score>=60) ct1++;    //合格数
        if (stu[i].score>=85) ct2++;    //优秀数
        if (stu[i].score>stu[x1].score) x1=i;   //最大值
        if (stu[i].score<stu[x2].score) x2=i;   //最小值
        if (stu[i].score<60 && (k1<0 || stu[i].score>stu[k1].score)) k1=i;
        if (stu[i].score<85 && (k2<0 || stu[i].score>stu[k2].score)) k2=i;
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
                stu[x1].score, stu[x1].num,
                stu[x2].score, stu[x2].num );
        if (k1>=0)
            printf("最接近合格=%.1f(%d)，", 
                stu[k1].score, stu[k1].num );
        else if (k2>=0)
            printf("所有学生合格或以上，");
        //
        if (k2>=0)
            printf("最接近优秀=%.1f(%d)\n", 
                stu[k2].score, stu[k2].num );
        else
            printf("所有学生均为优秀\n");
        //
    }
}
void cmdHelp(void)
{ //处理H命令：显示程序的帮助信息
    printf(
        "学生成绩管理程序V0.5，支持的命令有：\n"
        "  A 学号 成绩  //修改学生或添加新学生\n"
        "  D 学号       //删除指定学号的学生\n"
        "  L            //学生列表\n"
        "  S            //成绩降序排名\n"
        "  T            //显示成绩统计\n"
        "  H            //显示本帮助\n"
        "  Q            //退出程序\n"
        );
}
void cmdQuit(void)
{ //处理Q命令：显示再见并退出程序
    printf("再见！\n");
    exit(0);
}
char cmdGet(void)
{ //显示提示符，读取命令符并转换成大写，返回命令符
    char cmd;
    printf("ST5>");
    do {
        cmd = getchar();
    } while (cmd==' ' || cmd=='\t');
    if (cmd>='a' && cmd<='z')
        cmd = cmd - 'a' + 'A';
    return cmd;
}
int main(void)
{ //主函数
    STUDENT stu[N];
    int n = 0;
    char cmd;
    printf("[StuSc5]\n");
    while (1)
    {
        cmd = cmdGet();
        switch (cmd)
        {
            case 'A': n = cmdAdd(stu,n); break;
            case 'D': n = cmdDel(stu,n); break;
            case 'L': cmdList(stu,n); break;
            case 'S': cmdSort(stu,n); break;
            case 'T': cmdTotal(stu,n); break;
            case 'H': cmdHelp(); break;
            case 'Q': cmdQuit(); break;
            case '/':          //注释命令
            case '\n': break;  //空白命令
            default:  printf("无效命令（%c）\n", cmd);
        }
        while (cmd!='\n') cmd=getchar();
    }
    return 0;
}
