//StuSc3.c
#include <stdio.h>
#include <stdlib.h>
void cmdA(void)
{ //����A������
    int num = -1;
    float score = -1;
    scanf("%d%f", &num, &score);
    if (num<=0)
        printf("ѧ�� %d ��Ч������Ϊ������\n", num);
    if (score<0 || score>100)
        printf("�ɼ� %g ��Ч��������0��100֮�䣩\n", score);
    if (num>0 && score>=0 && score<=100)
    {
        printf("ѧ�ţ�%d���ɼ���%.1f�֣��ȼ���", num, score );
        if (score>=85)
            printf("����\n");
        else if (score>=60)
            printf("�ϸ�\n");
        else
            printf("���ϸ�\n");
    }
}
void cmdH(void)
{ //����H������
    printf(
        "ѧ���ɼ��������V0.3��֧�ֵ������У�\n"
        "  A ѧ�� �ɼ�  //ѧ���ɼ��ȼ�\n"
        "  H            //��ʾ������\n"
        "  Q            //�˳�����\n"
        );
}
void cmdQ(void)
{ //����Q������
    printf("�ټ���\n");
    exit(0);
}
char cmdGet(void)
{ //�������ȡ+ת��д����
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
{ //������
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
            default:  printf("��Ч���%c��\n", cmd);
        }
        while (cmd!='\n') cmd=getchar();
    }
    return 0;
}
