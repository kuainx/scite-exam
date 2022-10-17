//StuSc2.c
#include <stdio.h>
int main(void)
{
    int num;
    float score;
    printf("[StuSc2]\n");
    while (1)
    {
        printf("请输入学号和成绩：");
        num = -1; score = -1;
        scanf("%d%f", &num, &score);
        if (num<=0)
            printf("学号 %d 无效（必须为正数）\n", num);
        if (score<0 || score>100)
            printf("成绩 %g 无效（必须在0至100之间）\n", score);
        if (num>0 && score>=0 && score<=100)
            break;
    }
    printf("学号：%d，成绩：%.1f分，等级：", num, score );
    if (score>=85)
        printf("优秀\n");
    else if (score>=60)
        printf("合格\n");
    else
        printf("不合格\n");
    return 0;
}
