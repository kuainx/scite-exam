//eCost3.c
#include <stdio.h>
float ecost(float amount)
{   //年电费计算函数，根据电量amount计算并返回对应的电费
    float estd[] = {4, 0,0.6, 3000,0.1, 5000,0.2, 7000,0.3 }; //收费标准
    int i; float cost = 0;
    for (i=0; i<estd[0]; i++)
        if (amount>=estd[2*i+1])
            cost += (amount-estd[2*i+1]) * estd[2*i+2];
    return cost;
}
int main(void)
{   //主函数，输入电量，调用函数计算电费并输出
    float amount, cost; //年用电量、年电费
    printf("\n\t[eCost3]\n");
    printf("\t请输入年用电量（度）：");
    scanf("%f", &amount);
    cost = ecost(amount);
    printf("\t年电费为 %.2f 元\n\n", cost);
    return 0;
}
