//eCost6.c，促进节能-分时兼容-电费专题
#include <stdio.h>
#define M 10        //最多10档电费
#define N 60        //最多60期
struct eCostStd     //电费标准结构体
{
    int level;                  //分档级别
    float lowlimit, uplimit;    //该档界限
    float price;                //不分时价格
    float prpeak,  prvalley;    //电费价格：峰、谷
    float prpeak1, prvalley1;   //刚进入该档时价格
};
int readstd(struct eCostStd estd[], char *fnStd)
{ //读取电费标准文件，保存在estd[]，返回档级数
    FILE *fp;
    int n=-1, i;
    fp = fopen(fnStd, "r");
    if (fp==NULL)
    {
        printf("电费标准文件打开失败：%s\n", fnStd);
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
    printf("读取电费标准，共 %d 档\n", n);
    return n;
}
struct indmonth     //电表读数及电价结构体
{ //年初及每期：电表读数、年电量、应付电费
    float indpeak, indvalley;   //电表读数
    float amount;               //年用电量
    int level;                  //分档级别
    float amount1,amount2;      //当期电量：峰时谷时
    float price1, price2;       //当期电价：峰时谷时
    float costm, costy;         //电费：当期、年积
};
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
        indm[i].indpeak = indm[i].indvalley = -1;
        fscanf(fp, "%f%f", &indm[i].indpeak, &indm[i].indvalley);
        if (indm[i].indpeak < 0)
            break;  //文件结束、非数值或-1为结束标志
    }
    printf("读取居民电量，共 %d 期\n", i);
    return i;
}
void ecostm(struct indmonth indm[], int indn, struct eCostStd estd[], int stdn)
{ //计算每期电费
    int i, j;
    //年初数据初始化
    if (indm[0].indvalley<0)
        indm[0].amount = indm[0].indpeak;   //未分时
    else
        indm[0].amount = indm[0].indpeak + indm[0].indvalley;
    indm[0].level = indm[0].costy = indm[0].costm = 0;
    for (i=1; i<indn; i++)
    {
        //计算当期累计年用电量
        indm[i].amount = indm[i].indpeak - indm[0].indpeak;
        if (indm[0].indvalley>=0)
            indm[i].amount += indm[i].indvalley - indm[0].indvalley;
        //判断当期用电档级
        for (j=0; j<stdn-1; j++)
            if (indm[i].amount>estd[j].lowlimit && indm[i].amount<=estd[j].uplimit)
                break;
        indm[i].level = estd[j].level;
        //
        if (indm[0].indvalley>=0)
        {   //分时情况下电费计算
            indm[i].amount1 = indm[i].indpeak - indm[i-1].indpeak;      //峰时用电量
            indm[i].amount2 = indm[i].indvalley - indm[i-1].indvalley;  //谷时用电量
            if (j==0 || indm[i].level==indm[i-1].level
                     || indm[i-1].amount==estd[j].lowlimit)
            {       //第一档、不是第一次本档、当期全部新档
                indm[i].price1 = estd[j].prpeak;    //峰时价格
                indm[i].price2 = estd[j].prvalley;  //谷时价格
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
        {   //不分时情况电费计算
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
    if (indm[0].indvalley>=0)
    {   //分时情况
        fprintf(fp, "期,峰时读数,谷时读数,年用电量,档,用电1,用电2,单价1,单价2,当期费用,年积费用\n");
        fprintf(fp, " 0, %7.1f, %7.1f\n", indm[0].indpeak, indm[0].indvalley );
        for (i=1; i<indn; i++)
        {
            fprintf(fp, "%2d, %7.1f, %7.1f, %7.2f,%2d,%5.1f,%5.1f,%5.3f,%5.3f,%8.2f,%8.2f\n",
                i,                                   //当期序号
                indm[i].indpeak, indm[i].indvalley, //当期电表读数：峰谷
                indm[i].amount, indm[i].level,      //年用电量, 档级
                indm[i].amount1, indm[i].amount2,   //当期电量：峰谷
                indm[i].price1, indm[i].price2,     //当期电价：峰谷
                indm[i].costm, indm[i].costy);      //电费：当期、累积
        }
    }
    else
    {   //不分时情况
        fprintf(fp, "期,不分时读数,年用电量,档,用电量,单价,当期费用,年积费用\n");
        fprintf(fp, " 0, %7.1f\n", indm[0].indpeak );
        for (i=1; i<indn; i++)
        {
            fprintf(fp, "%2d, %7.1f, %7.2f,%2d,%5.1f,%5.3f,%8.2f,%8.2f\n",
                i,                                  //当期序号
                indm[i].indpeak,                    //当期电表读数
                indm[i].amount, indm[i].level,      //年用电量, 档级
                indm[i].amount1,                    //当期电量
                indm[i].price1,                     //当期电价
                indm[i].costm, indm[i].costy);      //电费：当期、累积
        }
    }
	if (fnLst!=NULL) fclose(fp);
}
int main(int argc, char *argv[])
{
    char *fnStd, *fnInd, *fnLst;
    struct eCostStd estd[M+1];    //假设最多10档
    struct indmonth indm[N+1];    //假设每年最多60期
    int stdn, indn;
    printf("[eCost6]\n");
    //读取电费标准文件，命令行参数1
    if (argc>1)
        fnStd = argv[1];
    else
        fnStd = "eCost6Std.txt";
    stdn = readstd(estd, fnStd);
    if (stdn<0) return -1;
    //读取电表读数文件，命令行参数2
    if (argc>2)
        fnInd = argv[2];
    else
        fnInd = "eCost6Ind.txt";
    indn = readind(indm, fnInd);
    if (indn<0) return -2;
    //计算每期电费
    ecostm(indm, indn, estd, stdn);
    //输出至电费输出文件，命令行参数3
    if (argc>3)
        fnLst = argv[3];
    else
        fnLst = "eCost6Lst.csv";
    prtcostm(indm, indn, fnLst);
    //输出至屏幕
    prtcostm(indm, indn, NULL);
    return 0;
}
