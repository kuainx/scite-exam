//eCost3.c
#include <stdio.h>
float ecost(float amount)
{   //���Ѽ��㺯�������ݵ���amount���㲢���ض�Ӧ�ĵ��
    float estd[] = {4, 0,0.6, 3000,0.1, 5000,0.2, 7000,0.3 }; //�շѱ�׼
    int i; float cost = 0;
    for (i=0; i<estd[0]; i++)
        if (amount>=estd[2*i+1])
            cost += (amount-estd[2*i+1]) * estd[2*i+2];
    return cost;
}
int main(void)
{   //��������������������ú��������Ѳ����
    float amount, cost; //���õ���������
    printf("\n\t[eCost3]\n");
    printf("\t���������õ������ȣ���");
    scanf("%f", &amount);
    cost = ecost(amount);
    printf("\t����Ϊ %.2f Ԫ\n\n", cost);
    return 0;
}
