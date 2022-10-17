//eCost4.c����ʵ���ݱ����-���ר��
#include <stdio.h>
int readstd(float estd[])
{ //��ȡ��ѱ�׼�ļ�
    char *fnStd = "eCost4Std.txt";
    FILE *fp;
    int i;
    fp = fopen(fnStd, "r");
    if (fp==NULL)
    {
        printf("��ѱ�׼�ļ���ʧ�ܣ�%s\n", fnStd);
        return -1;
    }
    fscanf(fp, "%f", &estd[0]);
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
            cost += (amount-estd[2*i+1]) * estd[2*i+2];
    }
    return cost;
}
int readind(float indm[])
{ //��ȡ������
    char *fnInd = "eCost4Ind.txt";
    FILE *fp;
    int i;
    fp = fopen(fnInd, "r");
    if (fp==NULL)
    {
        printf("�������ļ���ʧ�ܣ�%s\n", fnInd);
        return -1;
    }
    for (i=0; 1; i++)
    {
        indm[i] = -1;
        fscanf(fp, "%f", &indm[i]);
        if (indm[i] < 0)
            break;  //�ļ�����������ֵ��-1Ϊ������־
    }
    fclose(fp);
    return i-1;
}
void prtcostm(float indm[], float estd[])
{ //���㲢���ÿ�µ��
    int i;
    float amount, cost, paym, sumpay=0;
    printf("��,������,���õ���,�������,�����շ�\n");
    printf("%2d, %7.1f, %7.1f\n", 0, indm[0], 0.0);
    for (i=1; indm[i]>=0; i++)
    {
        amount = indm[i] - indm[0];
        cost = ecost(amount, estd);
        paym = cost - sumpay;
        printf("%2d, %7.1f, %7.1f, %7.2f, %7.2f\n",
            i, indm[i], amount, cost, paym);
        sumpay += paym;
    }
}
int main(void)
{ //������
    float estd[23], indm[60];
    printf("[eCost4]\n");
    if (readstd(estd)<0) return -1;
    if (readind(indm)<0) return -2;
    prtcostm(indm, estd);
    return 0;
}
