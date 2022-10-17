//StuSc6.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define FileName "StuSc6.txt"
typedef struct student  //ѧ���ṹ��
{
    int num;       //ѧ�ţ�������
    char name[20]; //���������ȡ�19�������ڲ����ո�TAB����
    float score;   //�ɼ�����Χ0��100֮��
} STUDENT; //ѧ������
void prt(STUDENT *p)
{ //���ѧ����Ϣ��ѧ�š��������ɼ����ȼ�
    printf("%d %s %.1f ", p->num, p->name, p->score);
    if (p->score>=85)
        printf("����\n");
    else if (p->score>=60)
        printf("�ϸ�\n");
    else
        printf("���ϸ�\n");
}
int find(STUDENT stu[], int n, int num)
{ //����ָ��ѧ�ŵ�ѧ���������±��-1
    int i;
    for (i=0; i<n; i++)
        if (stu[i].num == num)
            return i;
    return -1;
}
int insert(STUDENT stu[], int n, int num)
{ //�ճ�����㣬ָ��ѧ�ŵ�ѧ������ƶ�һ��λ��
    int i;
    for (i=n-1; i>=0; i--)
        if (stu[i].num > num)
            stu[i+1] = stu[i];
        else
            return i+1;
    return 0;
}
int cmdAdd(STUDENT stu[], int n, STUDENT x)
{ //����Add����޸Ļ����ѧ��
    int i;
    if (x.num<=0)
        printf("ѧ�� %d ��Ч������Ϊ������\n", x.num);
    if (x.score<0 || x.score>100)
        printf("�ɼ� %g ��Ч��������0��100֮�䣩\n", x.score);
    if (x.num>0 && x.score>=0 && x.score<=100)
    {
        i = find(stu, n, x.num);
        if (i>=0)
        {   //������Ϣ
            stu[i] = x;
            printf("����ѧ����[%d] ", i);
            prt(&x);
        }
        else if (n<N)
        {
            i = insert(stu, n, x.num);
            stu[i] = x;
            printf("����ѧ����[%d] ", i);
            prt(&x);
            n++;
        }
        else
            printf("�༶ѧ�����Ѵﵽ����(%d)����������\n", N);
    }
    return n;
}
int cmdDel(STUDENT stu[], int n, int xn)
{ //����Del���ɾ��ѧ��
    int i;
    i = find(stu, n, xn);
    if (i>=0)
    {
        printf("ɾ��ѧ����[%d] ", i);
        prt(stu+i);
        for (; i<n; i++)
            stu[i] = stu[i+1];
        n--;
    }
    else
        printf("δ�ҵ�ѧ�� %d ��ѧ��\n", xn);
    return n;
}
void cmdFind(STUDENT stu[], int n, int xn)
{ //����Find�������ѧ��
    int i;
    i = find(stu, n, xn);
    if (i>=0)
    {
        printf("�ҵ�ѧ����[%d] ", i);
        prt(stu+i);
    }
    else
        printf("δ�ҵ�ѧ�� %d ��ѧ��\n", xn);
}
void cmdList(STUDENT stu[], int n)
{ //����List���ѧ����Ϣ�б�
    int i;
    printf("ѧ���б�(%d)��\n", n);
    for (i=0; i<n; i++)
    {
        printf("[%d] ", i);
        prt(stu+i);
    }
}
void cmdSort(STUDENT stu[], int n)
{ //����Sort�����ѧ�Ž������������������ı�stu����
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
    printf("�ɼ�����(%d)��\n", n);
    for (i=0; i<n; i++)
    {
        if (i==0 || p[i]->score != p[i-1]->score)
            j = i+1;
        printf("{%d} ", j);
        prt(p[i]);
    }
}
void cmdTotal(STUDENT stu[], int n)
{ //����Total���ͳ��ѧ����Ϣ
    int i, ct1=0, ct2=0, x1=0, x2=0, k1=-1, k2=-1;
    float avg=0, r1=0, r2=0;
    for (i=0; i<n; i++)
    {
        avg += stu[i].score;
        if (stu[i].score>=60) ct1++;    //�ϸ���
        if (stu[i].score>=85) ct2++;    //������
        if (stu[i].score>stu[x1].score) x1=i;   //���ֵ
        if (stu[i].score<stu[x2].score) x2=i;   //��Сֵ
        if (stu[i].score<60 && (k1<0 || stu[i].score>stu[k1].score)) k1=i;
        if (stu[i].score<85 && (k2<0 || stu[i].score>stu[k2].score)) k2=i;
    }
    printf("ѧ����=%d\n", n );
    if (n>0)
    {
        avg /= n;
        r1 = 100.0*ct1/n;
        r2 = 100.0*ct2/n;
        printf("ƽ���ɼ�=%.1f��", avg );
        printf("�ϸ���=%.1f%%��������=%.1f%%\n", r1, r2 );
        printf("�༶��߷�=%.1f(%d-%s), �༶��ͷ�=%.1f(%d-%s)\n", 
                stu[x1].score, stu[x1].num, stu[x1].name,
                stu[x2].score, stu[x2].num, stu[x2].name );
        if (k1>=0)
            printf("��ӽ��ϸ�=%.1f(%d-%s)��", 
                stu[k1].score, stu[k1].num, stu[k1].name );
        else if (k2>=0)
            printf("����ѧ���ϸ�����ϣ�");
        //
        if (k2>=0)
            printf("��ӽ�����=%.1f(%d-%s)\n", 
                stu[k2].score, stu[k2].num, stu[k2].name );
        else
            printf("����ѧ����Ϊ����\n");
        //
    }
}
void cmdWrite(STUDENT stu[], int n, char *fn)
{ //����Write����������ݵ��ļ�fn��
    FILE *fp;
    int i;
    if (fn==NULL || fn[0]=='\0')
        fn = FileName;
    fp = fopen(fn, "w");
    if (fp==NULL)
    {
        printf("д�ļ� %s ʧ��\n", fn);
        return;
    }
    fprintf(fp, "%d\n", n);
    for (i=0; i<n; i++)
        fprintf(fp, "%d %s %g\n", stu[i].num, stu[i].name, stu[i].score);
    fprintf(fp, "-1 NAME -1\n");
    fclose(fp);
    printf("���� %d ��ѧ�����ݵ��ļ� %s ��\n", n, fn);
}
int cmdRead(STUDENT stu[], int n, char *fn)
{ //����Read������ļ�fn�ж�ȡ����
    FILE *fp;
    STUDENT x;
    int i, m;
    if (fn==NULL || fn[0]=='\0')
        fn = FileName;
    fp = fopen(fn, "r");
    if (fp==NULL)
    {
        printf("���ļ� %s ʧ��\n", fn);
        return n;
    }
    n = 0;
    fscanf(fp, "%d", &m);
    for (i=0; i<m; i++)
    {
        x.num = -1;
        fscanf(fp, "%d %s %f", &x.num, x.name, &x.score);
        if (x.num<0) break;     //ѧ��Ϊ��������Чʱ��������ȡ
        n = cmdAdd(stu, n, x);
    }
    fclose(fp);
    printf("���ļ� %s �ж�ȡ %d ��ѧ������\n", fn, n);
    return n;
}
void cmdHelp(void)
{ //����Help�����ʾ����İ�����Ϣ
    printf(
        "ѧ���ɼ��������V0.6��֧�ֵ������У�\n"
        "  Add ѧ�� ���� �ɼ� //�޸�ѧ���������ѧ��\n"
        "  Del ѧ��           //ɾ��ָ��ѧ�ŵ�ѧ��\n"
        "  Find ѧ��          //����ָ��ѧ�ŵ�ѧ��\n"
        "  List               //ѧ���б�\n"
        "  Sort               //�ɼ���������\n"
        "  Total              //��ʾ�ɼ�ͳ��\n"
        "  Write [�ļ���]     //����ѧ�����ݵ��ļ�\n"
        "  Read  [�ļ���]     //���ļ��ж�ȡѧ������\n"
        "  Help �� ?          //��ʾ������\n"
        "  Quit               //�˳�����\n"
        );
}
void cmdQuit(void)
{ //����Quit�����ʾ�ټ����˳�����
    printf("�ټ���\n");
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
{ //��������ʣ�������������
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
            case cmdBAD:    printf("��Ч���%s��\n", cmdWord);
        }
    }
    return 0;
}
