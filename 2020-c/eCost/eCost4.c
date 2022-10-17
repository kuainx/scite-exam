//eCost4.c，真实数据表计算-电费专题
#include <stdio.h>
int readstd(float estd[])
{ //读取电费标准文件
    char *fnStd = "eCost4Std.txt";
    FILE *fp;
    int i;
    fp = fopen(fnStd, "r");
    if (fp==NULL)
    {
        printf("电费标准文件打开失败：%s\n", fnStd);
        return -1;
    }
    fscanf(fp, "%f", &estd[0]);
    for (i=0; i<estd[0]; i++)
        fscanf(fp, "%f%f", &estd[2*i+1], &estd[2*i+2]);
    fclose(fp);
    return estd[0];
}
float ecost(float amount, float estd[])
{ //计算年电费
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
{ //读取电表读数
    char *fnInd = "eCost4Ind.txt";
    FILE *fp;
    int i;
    fp = fopen(fnInd, "r");
    if (fp==NULL)
    {
        printf("电表读数文件打开失败：%s\n", fnInd);
        return -1;
    }
    for (i=0; 1; i++)
    {
        indm[i] = -1;
        fscanf(fp, "%f", &indm[i]);
        if (indm[i] < 0)
            break;  //文件结束、非数值或-1为结束标志
    }
    fclose(fp);
    return i-1;
}
void prtcostm(float indm[], float estd[])
{ //计算并输出每月电费
    int i;
    float amount, cost, paym, sumpay=0;
    printf("期,电表读数,年用电量,当年费用,当期收费\n");
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
{ //主函数
    float estd[23], indm[60];
    printf("[eCost4]\n");
    if (readstd(estd)<0) return -1;
    if (readind(indm)<0) return -2;
    prtcostm(indm, estd);
    return 0;
}
