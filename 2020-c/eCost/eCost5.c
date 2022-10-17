//eCost5.c，使用结构体与命令行-电费专题
#include <stdio.h>
#define M 10
#define N 60
struct indmonth
{ //年初及每期：电表读数、年电量、年电费、当期电费
    float indicator;    //电表读数
    float amount;       //年用电量
    float costy;        //本年累积电费
    float costm;        //当期应付电费
};
int readstd(float estd[], char *fnStd)
{ //读取电费标准文件
    FILE *fp;
    int i;
    fp = fopen(fnStd, "r");
    if (fp==NULL)
    {
        printf("电费标准文件打开失败：%s\n", fnStd);
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
{ //计算年电费
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
{ //读取电表读数
    FILE *fp;
    int i;
    fp = fopen(fnInd, "r");
    if (fp==NULL)
    {
        printf("电表读数文件打开失败：%s\n", fnInd);
        return -1;
    }
    for (i=0; i<N; i++)
    {
        indm[i].indicator = -1;
        fscanf(fp, "%f", &indm[i].indicator);
        if (indm[i].indicator < 0)
            break;  //文件结束、非数值或-1为结束标志
    }
    return i;
}
void ecostm(struct indmonth indm[], int indn, float estd[])
{ //计算每期电费
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
{ //输出每期电费至文件fp中
    FILE *fp;
    int i;
    if (fnLst==NULL)
        fp = stdout;
    else
    {
        fp = fopen(fnLst, "w");
        if (fp==NULL)
        {
            printf("电费输出文件创建失败：%s\n", fnLst);
            return;
        }
    }
    fprintf(fp, "期,电表读数,年用电量,当期费用,当年收费\n");
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
    float estd[2*M+2];        //假设最多10档
    struct indmonth indm[N];  //假设每年最多60期
    int stdn, indn;
    printf("[eCost5]\n");
    //读取电费标准文件，命令行参数1
    if (argc>1)
        fnStd = argv[1];
    else
        fnStd = "eCost5Std.txt";
    stdn = readstd(estd, fnStd);
    if (stdn<0) return -1;
    //读取电表读数文件，命令行参数2
    if (argc>2)
        fnInd = argv[2];
    else
        fnInd = "eCost5Ind.txt";
    indn = readind(indm, fnInd);
    if (indn<0) return -2;
    //计算每期电费
    ecostm(indm, indn, estd);
    //输出至电费输出文件，命令行参数3
    if (argc>3)
        fnLst = argv[3];
    else
        fnLst = "eCost5Lst.csv";
    prtcostm(indm, indn, fnLst);
    //输出至屏幕
    prtcostm(indm, indn, NULL);
    return 0;
}
