//eCost6.c���ٽ�����-��ʱ����-���ר��
#include <stdio.h>
#define M 10        //���10�����
#define N 60        //���60��
struct eCostStd     //��ѱ�׼�ṹ��
{
    int level;                  //�ֵ�����
    float lowlimit, uplimit;    //�õ�����
    float price;                //����ʱ�۸�
    float prpeak,  prvalley;    //��Ѽ۸񣺷塢��
    float prpeak1, prvalley1;   //�ս���õ�ʱ�۸�
};
int readstd(struct eCostStd estd[], char *fnStd)
{ //��ȡ��ѱ�׼�ļ���������estd[]�����ص�����
    FILE *fp;
    int n=-1, i;
    fp = fopen(fnStd, "r");
    if (fp==NULL)
    {
        printf("��ѱ�׼�ļ���ʧ�ܣ�%s\n", fnStd);
        return -1;
    }
    fscanf(fp, "%d", &n);
    if (n < 0) n = 0;
    if (n > M) n = M;
    for (i=0; i<n; i++)
        fscanf(fp, "%d%f%f%f%f%f%f%f", 
            &estd[i].level, 
            &estd[i].lowlimit, &estd[i].uplimit,
            &estd[i].price,
            &estd[i].prpeak, &estd[i].prvalley,
            &estd[i].prpeak1,&estd[i].prvalley1 );
    fclose(fp);
    estd[n].level = -1;
    printf("��ȡ��ѱ�׼���� %d ��\n", n);
    return n;
}
struct indmonth     //����������۽ṹ��
{ //�����ÿ�ڣ����������������Ӧ�����
    float indpeak, indvalley;   //������
    float amount;               //���õ���
    int level;                  //�ֵ�����
    float amount1,amount2;      //���ڵ�������ʱ��ʱ
    float price1, price2;       //���ڵ�ۣ���ʱ��ʱ
    float costm, costy;         //��ѣ����ڡ����
};
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
        indm[i].indpeak = indm[i].indvalley = -1;
        fscanf(fp, "%f%f", &indm[i].indpeak, &indm[i].indvalley);
        if (indm[i].indpeak < 0)
            break;  //�ļ�����������ֵ��-1Ϊ������־
    }
    printf("��ȡ����������� %d ��\n", i);
    return i;
}
void ecostm(struct indmonth indm[], int indn, struct eCostStd estd[], int stdn)
{ //����ÿ�ڵ��
    int i, j;
    //������ݳ�ʼ��
    if (indm[0].indvalley<0)
        indm[0].amount = indm[0].indpeak;   //δ��ʱ
    else
        indm[0].amount = indm[0].indpeak + indm[0].indvalley;
    indm[0].level = indm[0].costy = indm[0].costm = 0;
    for (i=1; i<indn; i++)
    {
        //���㵱���ۼ����õ���
        indm[i].amount = indm[i].indpeak - indm[0].indpeak;
        if (indm[0].indvalley>=0)
            indm[i].amount += indm[i].indvalley - indm[0].indvalley;
        //�жϵ����õ絵��
        for (j=0; j<stdn-1; j++)
            if (indm[i].amount>estd[j].lowlimit && indm[i].amount<=estd[j].uplimit)
                break;
        indm[i].level = estd[j].level;
        //
        if (indm[0].indvalley>=0)
        {   //��ʱ����µ�Ѽ���
            indm[i].amount1 = indm[i].indpeak - indm[i-1].indpeak;      //��ʱ�õ���
            indm[i].amount2 = indm[i].indvalley - indm[i-1].indvalley;  //��ʱ�õ���
            if (j==0 || indm[i].level==indm[i-1].level
                     || indm[i-1].amount==estd[j].lowlimit)
            {       //��һ�������ǵ�һ�α���������ȫ���µ�
                indm[i].price1 = estd[j].prpeak;    //��ʱ�۸�
                indm[i].price2 = estd[j].prvalley;  //��ʱ�۸�
            }
            else
            {
                indm[i].price1 = estd[j].prpeak1;
                indm[i].price2 = estd[j].prvalley1;
            }
            indm[i].costm = indm[i].amount1 * indm[i].price1 + 
                            indm[i].amount2 * indm[i].price2;
            indm[i].costy = indm[i].costm + indm[i-1].costy;
        }
        else
        {   //����ʱ�����Ѽ���
            indm[i].costy = 0;
            indm[i].amount1 = indm[i].indpeak - indm[i-1].indpeak;
            for (j=0; j<stdn; j++)
            {
                if (indm[i].amount>estd[j].lowlimit && (j==stdn-1 || indm[i].amount<=estd[j].uplimit))
                    indm[i].costy += (indm[i].amount-estd[j].lowlimit) * estd[j].price;
                else if (indm[i].amount>=estd[j].uplimit && estd[j].uplimit>0)
                    indm[i].costy += (estd[j].uplimit-estd[j].lowlimit) * estd[j].price;
                if (indm[i].amount>estd[j].lowlimit)
                    indm[i].price1 = estd[j].price;
            }
            indm[i].costm = indm[i].costy - indm[i-1].costy;
        }
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
    if (indm[0].indvalley>=0)
    {   //��ʱ���
        fprintf(fp, "��,��ʱ����,��ʱ����,���õ���,��,�õ�1,�õ�2,����1,����2,���ڷ���,�������\n");
        fprintf(fp, " 0, %7.1f, %7.1f\n", indm[0].indpeak, indm[0].indvalley );
        for (i=1; i<indn; i++)
        {
            fprintf(fp, "%2d, %7.1f, %7.1f, %7.2f,%2d,%5.1f,%5.1f,%5.3f,%5.3f,%8.2f,%8.2f\n",
                i,                                   //�������
                indm[i].indpeak, indm[i].indvalley, //���ڵ����������
                indm[i].amount, indm[i].level,      //���õ���, ����
                indm[i].amount1, indm[i].amount2,   //���ڵ��������
                indm[i].price1, indm[i].price2,     //���ڵ�ۣ����
                indm[i].costm, indm[i].costy);      //��ѣ����ڡ��ۻ�
        }
    }
    else
    {   //����ʱ���
        fprintf(fp, "��,����ʱ����,���õ���,��,�õ���,����,���ڷ���,�������\n");
        fprintf(fp, " 0, %7.1f\n", indm[0].indpeak );
        for (i=1; i<indn; i++)
        {
            fprintf(fp, "%2d, %7.1f, %7.2f,%2d,%5.1f,%5.3f,%8.2f,%8.2f\n",
                i,                                  //�������
                indm[i].indpeak,                    //���ڵ�����
                indm[i].amount, indm[i].level,      //���õ���, ����
                indm[i].amount1,                    //���ڵ���
                indm[i].price1,                     //���ڵ��
                indm[i].costm, indm[i].costy);      //��ѣ����ڡ��ۻ�
        }
    }
	if (fnLst!=NULL) fclose(fp);
}
int main(int argc, char *argv[])
{
    char *fnStd, *fnInd, *fnLst;
    struct eCostStd estd[M+1];    //�������10��
    struct indmonth indm[N+1];    //����ÿ�����60��
    int stdn, indn;
    printf("[eCost6]\n");
    //��ȡ��ѱ�׼�ļ��������в���1
    if (argc>1)
        fnStd = argv[1];
    else
        fnStd = "eCost6Std.txt";
    stdn = readstd(estd, fnStd);
    if (stdn<0) return -1;
    //��ȡ�������ļ��������в���2
    if (argc>2)
        fnInd = argv[2];
    else
        fnInd = "eCost6Ind.txt";
    indn = readind(indm, fnInd);
    if (indn<0) return -2;
    //����ÿ�ڵ��
    ecostm(indm, indn, estd, stdn);
    //������������ļ��������в���3
    if (argc>3)
        fnLst = argv[3];
    else
        fnLst = "eCost6Lst.csv";
    prtcostm(indm, indn, fnLst);
    //�������Ļ
    prtcostm(indm, indn, NULL);
    return 0;
}
