//eCost5.c��ʹ�ýṹ����������-���ר��
#include <stdio.h>
#define M 10
#define N 60
struct indmonth
{ //�����ÿ�ڣ�������������������ѡ����ڵ��
    float indicator;    //������
    float amount;       //���õ���
    float costy;        //�����ۻ����
    float costm;        //����Ӧ�����
};
int readstd(float estd[], char *fnStd)
{ //��ȡ��ѱ�׼�ļ�
    FILE *fp;
    int i;
    fp = fopen(fnStd, "r");
    if (fp==NULL)
    {
        printf("��ѱ�׼�ļ���ʧ�ܣ�%s\n", fnStd);
        return -1;
    }
    fscanf(fp, "%f", &estd[0]);
    if (estd[0] < 0) estd[0] = 0;
    if (estd[0] > M) estd[0] = M;
    for (i=0; i<estd[0]; i++)
        fscanf(fp, "%f%f", &estd[2*i+1], &estd[2*i+2]);
    fclose(fp);
    return estd[0];
}
float ecost(float amount, float estd[])
{ //��������
    float cost = 0;
    int i;
    for (i=0; i<estd[0]; i++)
    {
        if (amount>estd[2*i+1])
            cost += (amount-estd[2*i+1])*estd[2*i+2];
    }
    return cost;
}
int readind(struct indmonth indm[], char *fnInd)
{ //��ȡ������
    FILE *fp;
    int i;
    fp = fopen(fnInd, "r");
    if (fp==NULL)
    {
        printf("�������ļ���ʧ�ܣ�%s\n", fnInd);
        return -1;
    }
    for (i=0; i<N; i++)
    {
        indm[i].indicator = -1;
        fscanf(fp, "%f", &indm[i].indicator);
        if (indm[i].indicator < 0)
            break;  //�ļ�����������ֵ��-1Ϊ������־
    }
    return i;
}
void ecostm(struct indmonth indm[], int indn, float estd[])
{ //����ÿ�ڵ��
    int i;
    indm[0].amount = indm[0].costy = indm[0].costm = 0;
    for (i=1; i<indn; i++)
    {
        indm[i].amount = indm[i].indicator - indm[0].indicator;
        indm[i].costy = ecost(indm[i].amount, estd);
        indm[i].costm = indm[i].costy - indm[i-1].costy;
    }
}
void prtcostm(struct indmonth indm[], int indn, char *fnLst)
{ //���ÿ�ڵ�����ļ�fp��
    FILE *fp;
    int i;
    if (fnLst==NULL)
        fp = stdout;
    else
    {
        fp = fopen(fnLst, "w");
        if (fp==NULL)
        {
            printf("�������ļ�����ʧ�ܣ�%s\n", fnLst);
            return;
        }
    }
    fprintf(fp, "��,������,���õ���,���ڷ���,�����շ�\n");
    fprintf(fp, " 0, %7.1f\n", indm[0].indicator);
    for (i=1; i<indn; i++)
    {
        fprintf(fp, "%2d, %7.1f, %7.1f, %7.2f, %7.2f\n", i,
            indm[i].indicator, indm[i].amount, indm[i].costm, indm[i].costy);
    }
	if (fnLst!=NULL) fclose(fp);
}
int main(int argc, char *argv[])
{
    char *fnStd, *fnInd, *fnLst;
    float estd[2*M+2];        //�������10��
    struct indmonth indm[N];  //����ÿ�����60��
    int stdn, indn;
    printf("[eCost5]\n");
    //��ȡ��ѱ�׼�ļ��������в���1
    if (argc>1)
        fnStd = argv[1];
    else
        fnStd = "eCost5Std.txt";
    stdn = readstd(estd, fnStd);
    if (stdn<0) return -1;
    //��ȡ�������ļ��������в���2
    if (argc>2)
        fnInd = argv[2];
    else
        fnInd = "eCost5Ind.txt";
    indn = readind(indm, fnInd);
    if (indn<0) return -2;
    //����ÿ�ڵ��
    ecostm(indm, indn, estd);
    //������������ļ��������в���3
    if (argc>3)
        fnLst = argv[3];
    else
        fnLst = "eCost5Lst.csv";
    prtcostm(indm, indn, fnLst);
    //�������Ļ
    prtcostm(indm, indn, NULL);
    return 0;
}
