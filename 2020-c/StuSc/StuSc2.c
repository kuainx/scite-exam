//StuSc2.c
#include <stdio.h>
int main(void)
{
    int num;
    float score;
    printf("[StuSc2]\n");
    while (1)
    {
        printf("������ѧ�źͳɼ���");
        num = -1; score = -1;
        scanf("%d%f", &num, &score);
        if (num<=0)
            printf("ѧ�� %d ��Ч������Ϊ������\n", num);
        if (score<0 || score>100)
            printf("�ɼ� %g ��Ч��������0��100֮�䣩\n", score);
        if (num>0 && score>=0 && score<=100)
            break;
    }
    printf("ѧ�ţ�%d���ɼ���%.1f�֣��ȼ���", num, score );
    if (score>=85)
        printf("����\n");
    else if (score>=60)
        printf("�ϸ�\n");
    else
        printf("���ϸ�\n");
    return 0;
}
