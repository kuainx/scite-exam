//StuSc5.c
#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef struct student  //ѧ���ṹ��
{
    int num;       //ѧ�ţ�������
    float score;   //�ɼ�����Χ0��100֮��
} STUDENT; //ѧ������
int cmdAdd(STUDENT stu[], int n)
{ //����A����޸Ļ����ѧ��
    STUDENT x = {-1, -1};
    int i;
    scanf("%d %f", &x.num, &x.score);
    if (x.num<=0)
        printf("ѧ�� %d ��Ч������Ϊ������\n", x.num);
    if (x.score<0 || x.score>100)
        printf("�ɼ� %g ��Ч��������0��100֮�䣩\n", x.score);
    if (x.num>0 && x.score>=0 && x.score<=100)
    {
        for (i=0; i<n; i++)
            if (stu[i].num==x.num)
            {   //������Ϣ
                stu[i] = x;
                printf("����ѧ����[%d] %d %.1f\n", i, x.num, x.score );
                return n;
            }
        if (n<N)
        {
            stu[n] = x;
            printf("���ѧ����[%d] %d %.1f\n", i, x.num, x.score );
            n++;
        }
        else
            printf("ѧ�����Ѵﵽ����(%d)���������\n", N);
    }
    return n;
}
int cmdDel(STUDENT stu[], int n)
{ //����D���ɾ��ѧ��
    int i, xn=-1;
    scanf("%d", &xn);
    for (i=0; i<n; i++)
        if (stu[i].num==xn)
        {
            printf("ɾ��ѧ����[%d] %d %.1f\n", i, stu[i].num, stu[i].score );
            for (; i<n; i++)
                stu[i] = stu[i+1];
            n--;
            return n;
        }
    printf("δ�ҵ�ѧ�� %d ��ѧ��\n", xn);
    return n;
}
void cmdList(STUDENT stu[], int n)
{ //����L���ѧ����Ϣ�б�
    int i;
    printf("ѧ���б�(%d)��\n", n);
    for (i=0; i<n; i++)
    {
        printf("[%d] %d %.1f ", i, stu[i].num, stu[i].score);
        if (stu[i].score>=85)
            printf("����\n");
        else if (stu[i].score>=60)
            printf("�ϸ�\n");
        else
            printf("���ϸ�\n");
    }
}
void cmdSort(STUDENT stu[], int n)
{ //����S�����ѧ�Ž������������������ı�stu����
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
    printf("�ɼ�����(%d)��\n", n);
    for (i=0; i<n; i++)
    {
        if (i==0 || p[i]->score!=p[i-1]->score)
            j = i+1;
        printf("{%d} %d %.1f\n", j, p[i]->num, p[i]->score);
    }
}
void cmdTotal(STUDENT stu[],int n)
{ //����T���ͳ��ѧ����Ϣ
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
        printf("�༶��߷�=%.1f(%d), �༶��ͷ�=%.1f(%d)\n", 
                stu[x1].score, stu[x1].num,
                stu[x2].score, stu[x2].num );
        if (k1>=0)
            printf("��ӽ��ϸ�=%.1f(%d)��", 
                stu[k1].score, stu[k1].num );
        else if (k2>=0)
            printf("����ѧ���ϸ�����ϣ�");
        //
        if (k2>=0)
            printf("��ӽ�����=%.1f(%d)\n", 
                stu[k2].score, stu[k2].num );
        else
            printf("����ѧ����Ϊ����\n");
        //
    }
}
void cmdHelp(void)
{ //����H�����ʾ����İ�����Ϣ
    printf(
        "ѧ���ɼ��������V0.5��֧�ֵ������У�\n"
        "  A ѧ�� �ɼ�  //�޸�ѧ���������ѧ��\n"
        "  D ѧ��       //ɾ��ָ��ѧ�ŵ�ѧ��\n"
        "  L            //ѧ���б�\n"
        "  S            //�ɼ���������\n"
        "  T            //��ʾ�ɼ�ͳ��\n"
        "  H            //��ʾ������\n"
        "  Q            //�˳�����\n"
        );
}
void cmdQuit(void)
{ //����Q�����ʾ�ټ����˳�����
    printf("�ټ���\n");
    exit(0);
}
char cmdGet(void)
{ //��ʾ��ʾ������ȡ�������ת���ɴ�д�����������
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
{ //������
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
            case '/':          //ע������
            case '\n': break;  //�հ�����
            default:  printf("��Ч���%c��\n", cmd);
        }
        while (cmd!='\n') cmd=getchar();
    }
    return 0;
}
