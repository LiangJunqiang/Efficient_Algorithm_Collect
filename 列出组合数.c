/*
*  �ļ�����Combination.c
*  ��;������㷨
*  ��̻�����WinXP SP2+CL 8.0
*  ������ڣ� 2006.2   Ver 0.01
*  ���ߣ� 88250
*  ��ϵ��ʽ�� E-mail: DL88250@gmail.com  QQ:845765
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 26
int comb[MAX_NUM];
int c1,c2;
void combination(int m, int n)
{
    int i, j;
    for (i = m; i >= n; i--){
        comb[n] = i;        /* ѡ��ǰ�ġ�ͷ��Ԫ�� */
        if (n > 1){
            /* ������һ�θ�С��������� */
            combination(i - 1, n - 1);
        }else{
            /* ������Ҫ������������ */
            for (j = comb[0]; j > 0; j--){
                printf("%c", 65+c1-comb[j]);
            }
            printf("\n");
        }
    }
    return;
}
int main(int argc, char *argv[])
{
    if (argc<3) {
        printf("%s ����±� ����ϱ�\n",argv[0]);
        return 0;
    }
    c1=atoi(argv[1]);
    if (c1<1||26<c1) {
        printf("1<=����±�<=26\n");
        return 0;
    }
    c2=atoi(argv[2]);
    if (c2<1||c1<c2){
        printf("1<=����ϱ�<=����±�\n");
        return 0;
    }
    comb[0]=c2;
    combination(c1, c2);        /* C(4, 2) */
    return 0;
}
