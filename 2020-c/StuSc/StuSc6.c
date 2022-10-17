//StuSc6.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define FileName "StuSc6.txt"
typedef struct student  //学生结构体
{
    int num;       //学号，正整数
    char name[20]; //姓名，长度≤19，姓名内不含空格TAB换行
    float score;   //成绩，范围0至100之间
} STUDENT; //学生类型
void prt(STUDENT *p)
{ //输出学生信息，学号、姓名、成绩、等级
    printf("%d %s %.1f ", p->num, p->name, p->score);
    if (p->score>=85)
        printf("优秀\n");
    else if (p->score>=60)
        printf("合格\n");
    else
        printf("不合格\n");
}
int find(STUDENT stu[], int n, int num)
{ //查找指定学号的学生，返回下标或-1
    int i;
    for (i=0; i<n; i++)
        if (stu[i].num == num)
            return i;
    return -1;
}
int insert(STUDENT stu[], int n, int num)
{ //空出插入点，指定学号的学生向后移动一个位置
    int i;
    for (i=n-1; i>=0; i--)
        if (stu[i].num > num)
            stu[i+1] = stu[i];
        else
            return i+1;
    return 0;
}
int cmdAdd(STUDENT stu[], int n, STUDENT x)
{ //处理Add命令：修改或插入学生
    int i;
    if (x.num<=0)
        printf("学号 %d 无效（必须为正数）\n", x.num);
    if (x.score<0 || x.score>100)
        printf("成绩 %g 无效（必须在0至100之间）\n", x.score);
    if (x.num>0 && x.score>=0 && x.score<=100)
    {
        i = find(stu, n, x.num);
        if (i>=0)
        {   //更改信息
            stu[i] = x;
            printf("更改学生，[%d] ", i);
            prt(&x);
        }
        else if (n<N)
        {
            i = insert(stu, n, x.num);
            stu[i] = x;
            printf("插入学生，[%d] ", i);
            prt(&x);
            n++;
        }
        else
            printf("班级学生数已达到上限(%d)，不能增加\n", N);
    }
    return n;
}
int cmdDel(STUDENT stu[], int n, int xn)
{ //处理Del命令：删除学生
    int i;
    i = find(stu, n, xn);
    if (i>=0)
    {
        printf("删除学生，[%d] ", i);
        prt(stu+i);
        for (; i<n; i++)
            stu[i] = stu[i+1];
        n--;
    }
    else
        printf("未找到学号 %d 的学生\n", xn);
    return n;
}
void cmdFind(STUDENT stu[], int n, int xn)
{ //处理Find命令：查找学生
    int i;
    i = find(stu, n, xn);
    if (i>=0)
    {
        printf("找到学生，[%d] ", i);
        prt(stu+i);
    }
    else
        printf("未找到学号 %d 的学生\n", xn);
}
void cmdList(STUDENT stu[], int n)
{ //处理List命令：学生信息列表
    int i;
    printf("学生列表(%d)：\n", n);
    for (i=0; i<n; i++)
    {
        printf("[%d] ", i);
        prt(stu+i);
    }
}
void cmdSort(STUDENT stu[], int n)
{ //处理Sort命令：按学号降序排序排名，但不改变stu数组
    STUDENT *p[N], *t;
    int i, j;
    for (i=0; i<n; i++)
        p[i] = &stu[i];
    for (i=0; i<n-1; i++)
        for (j=0; j<n-1-i; j++)
            if (p[j]->score < p[j+1]->score)
            {
                t = p[j];
                p[j] = p[j+1];
                p[j+1] = t;
            }
    printf("成绩排名(%d)：\n", n);
    for (i=0; i<n; i++)
    {
        if (i==0 || p[i]->score != p[i-1]->score)
            j = i+1;
        printf("{%d} ", j);
        prt(p[i]);
    }
}
void cmdTotal(STUDENT stu[], int n)
{ //处理Total命令：统计学生信息
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
        printf("班级最高分=%.1f(%d-%s), 班级最低分=%.1f(%d-%s)\n", 
                stu[x1].score, stu[x1].num, stu[x1].name,
                stu[x2].score, stu[x2].num, stu[x2].name );
        if (k1>=0)
            printf("最接近合格=%.1f(%d-%s)，", 
                stu[k1].score, stu[k1].num, stu[k1].name );
        else if (k2>=0)
            printf("所有学生合格或以上，");
        //
        if (k2>=0)
            printf("最接近优秀=%.1f(%d-%s)\n", 
                stu[k2].score, stu[k2].num, stu[k2].name );
        else
            printf("所有学生均为优秀\n");
        //
    }
}
void cmdWrite(STUDENT stu[], int n, char *fn)
{ //处理Write命令：保存数据到文件fn中
    FILE *fp;
    int i;
    if (fn==NULL || fn[0]=='\0')
        fn = FileName;
    fp = fopen(fn, "w");
    if (fp==NULL)
    {
        printf("写文件 %s 失败\n", fn);
        return;
    }
    fprintf(fp, "%d\n", n);
    for (i=0; i<n; i++)
        fprintf(fp, "%d %s %g\n", stu[i].num, stu[i].name, stu[i].score);
    fprintf(fp, "-1 NAME -1\n");
    fclose(fp);
    printf("保存 %d 个学生数据到文件 %s 中\n", n, fn);
}
int cmdRead(STUDENT stu[], int n, char *fn)
{ //处理Read命令：从文件fn中读取数据
    FILE *fp;
    STUDENT x;
    int i, m;
    if (fn==NULL || fn[0]=='\0')
        fn = FileName;
    fp = fopen(fn, "r");
    if (fp==NULL)
    {
        printf("读文件 %s 失败\n", fn);
        return n;
    }
    n = 0;
    fscanf(fp, "%d", &m);
    for (i=0; i<m; i++)
    {
        x.num = -1;
        fscanf(fp, "%d %s %f", &x.num, x.name, &x.score);
        if (x.num<0) break;     //学号为负数或无效时，结束读取
        n = cmdAdd(stu, n, x);
    }
    fclose(fp);
    printf("从文件 %s 中读取 %d 个学生数据\n", fn, n);
    return n;
}
void cmdHelp(void)
{ //处理Help命令：显示程序的帮助信息
    printf(
        "学生成绩管理程序V0.6，支持的命令有：\n"
        "  Add 学号 姓名 成绩 //修改学生或添加新学生\n"
        "  Del 学号           //删除指定学号的学生\n"
        "  Find 学号          //查找指定学号的学生\n"
        "  List               //学生列表\n"
        "  Sort               //成绩降序排名\n"
        "  Total              //显示成绩统计\n"
        "  Write [文件名]     //保存学生数据到文件\n"
        "  Read  [文件名]     //从文件中读取学生数据\n"
        "  Help 或 ?          //显示本帮助\n"
        "  Quit               //退出程序\n"
        );
}
void cmdQuit(void)
{ //处理Quit命令：显示再见并退出程序
    printf("再见！\n");
    exit(0);
}
#define cmdBAD      -1
#define cmdNONE     0
#define cmdQUIT     1
#define cmdHELP     2
#define cmdADD      3
#define cmdDEL      4
#define cmdLIST     5
#define cmdFIND     6
#define cmdSORT     7
#define cmdTOTAL    8
#define cmdWRITE    9
#define cmdREAD     10
struct cmdName
{
    int no;
    char *str;
} cmdNames[] = {
    {cmdQUIT,"QUIT"},   {cmdQUIT,"Q"},
    {cmdHELP,"HELP"},   {cmdHELP,"H"},  {cmdHELP,"?"}, 
    {cmdADD,"ADD"},     {cmdADD,"A"},
    {cmdDEL,"DEL"},     {cmdDEL,"D"},
    {cmdLIST,"LIST"},   {cmdLIST,"L"},
    {cmdFIND,"FIND"},   {cmdFIND,"F"},
    {cmdSORT,"SORT"},   {cmdSORT,"S"},
    {cmdTOTAL,"TOTAL"}, {cmdTOTAL,"T"},
    {cmdWRITE,"WRITE"}, {cmdWRITE,"W"},
    {cmdREAD,"READ"},   {cmdREAD,"R"},
    {cmdNONE,""} };
int cmdGet(char cmdWord[])
{ //解析命令词，并返回命令码
    int i, m;
    m = sizeof(cmdNames) / sizeof(struct cmdName);
    for (i=0; i<m; i++)
        if (stricmp(cmdWord,cmdNames[i].str)==0)
            return cmdNames[i].no;
    if (cmdWord[0]=='/')
        return cmdNONE;
    return cmdBAD;
}
int main(void)
{
    STUDENT stu[N], x;
    int n = 0, cmdNo;
    char cmdLine[80], cmdWord[50], fn[50];
    printf("[StuSc6]\n");
    while (1)
    {
        printf("ST6>");
        cmdLine[0] = cmdWord[0] = fn[0] = '\0';
        x.num=-1; x.name[0]='\0'; x.score=-1;
        gets(cmdLine);
        sscanf(cmdLine, "%s", cmdWord);
        cmdNo = cmdGet(cmdWord);
        switch (cmdNo)
        {
            case cmdADD:
                sscanf(cmdLine, "%s %d %s %f", cmdWord, &x.num, x.name, &x.score);
                            n = cmdAdd(stu,n,x);  break;
            case cmdDEL:
                sscanf(cmdLine, "%s %d", cmdWord, &x.num);
                            n = cmdDel(stu,n,x.num);  break;
            case cmdFIND:
                sscanf(cmdLine, "%s %d", cmdWord, &x.num);
                            cmdFind(stu,n,x.num);     break;
            case cmdLIST:   cmdList(stu,n);     break;
            case cmdSORT:   cmdSort(stu,n);     break;
            case cmdTOTAL:  cmdTotal(stu,n);    break;
            case cmdWRITE:
                            sscanf(cmdLine, "%s %s", cmdWord, fn);
                            cmdWrite(stu,n,fn);    break;
            case cmdREAD:
                            sscanf(cmdLine, "%s %s", cmdWord, fn);
                            n = cmdRead(stu,n,fn); break;
            case cmdHELP:   cmdHelp();          break;
            case cmdQUIT:   cmdQuit();          break;
            case cmdBAD:    printf("无效命令（%s）\n", cmdWord);
        }
    }
    return 0;
}
