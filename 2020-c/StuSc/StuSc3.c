//StuSc3.c
#include <stdio.h>
#include <stdlib.h>
void cmdA(void)
{ //命令A处理函数
    int num = -1;
    float score = -1;
    scanf("%d%f", &num, &score);
    if (num<=0)
        printf("学号 %d 无效（必须为正数）\n", num);
    if (score<0 || score>100)
        printf("成绩 %g 无效（必须在0至100之间）\n", score);
    if (num>0 && score>=0 && score<=100)
    {
        printf("学号：%d，成绩：%.1f分，等级：", num, score );
        if (score>=85)
            printf("优秀\n");
        else if (score>=60)
            printf("合格\n");
        else
            printf("不合格\n");
    }
}
void cmdH(void)
{ //命令H处理函数
    printf(
        "学生成绩管理程序V0.3，支持的命令有：\n"
        "  A 学号 成绩  //学生成绩等级\n"
        "  H            //显示本帮助\n"
        "  Q            //退出程序\n"
        );
}
void cmdQ(void)
{ //命令Q处理函数
    printf("再见！\n");
    exit(0);
}
char cmdGet(void)
{ //命令符读取+转大写函数
    char cmd;
    printf("ST3>");
    do {
        cmd = getchar();
    } while (cmd==' ' || cmd=='\t');
    if (cmd>='a' && cmd<='z')
        cmd = cmd - 'a' + 'A';
    return cmd;
}
int main(void)
{ //主函数
    char cmd;
    printf("[StuSc3]\n");
    while (1)
    {
        cmd = cmdGet();
        switch (cmd)
        {
            case 'A': cmdA(); break;
            case 'H': cmdH(); break;
            case 'Q': cmdQ(); break;
            case '\n': break;
            default:  printf("无效命令（%c）\n", cmd);
        }
        while (cmd!='\n') cmd=getchar();
    }
    return 0;
}
