//eCost2.c
#include <stdio.h>
#define PRICE (0.6)     //_
int main(void)          //_
{
    int x;  float y;    //_
printf("\n\t");
    scanf("%d",&x);
    if (x<=3000)
        y = x*PRICE;
    else if (x<=5000)
        y = 3000*PRICE+(x-3000)*(PRICE+0.1);
    else
        y = 3000*PRICE+(5000-3000)*(PRICE+0.1)+(x-5000)*(PRICE+0.3);    //_
printf("\t%.0f\n\n",y);     //_
    return 0;
}
