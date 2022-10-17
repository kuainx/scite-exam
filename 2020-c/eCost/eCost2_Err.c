//待调试的源程序
#include <stdio.h>
#define PRICE = 0.6
int mian(void)
{
    int x, y;
    scanf("%d",&x);
    if (x<=3000)
        y = x*PRICE;
    else if (x<=5000)
        y = 3000*PRICE+(x-3000)*(PRICE+0.1);
    else
        y = 3000*PRICE+(5000-3000)*(PRICE+0.1)+(x-5000)*(PRICE+0.2);
    printf("%d\n",y);
    return 0;
}
