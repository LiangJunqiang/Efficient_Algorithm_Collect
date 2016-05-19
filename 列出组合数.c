/*
*  文件名：Combination.c
*  用途：组合算法
*  编程环境：WinXP SP2+CL 8.0
*  完成日期： 2006.2   Ver 0.01
*  作者： 88250
*  联系方式： E-mail: DL88250@gmail.com  QQ:845765
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
        comb[n] = i;        /* 选择当前的“头”元素 */
        if (n > 1){
            /* 进入下一次更小的组合问题 */
            combination(i - 1, n - 1);
        }else{
            /* 满了需要的组合数，输出 */
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
        printf("%s 组合下标 组合上标\n",argv[0]);
        return 0;
    }
    c1=atoi(argv[1]);
    if (c1<1||26<c1) {
        printf("1<=组合下标<=26\n");
        return 0;
    }
    c2=atoi(argv[2]);
    if (c2<1||c1<c2){
        printf("1<=组合上标<=组合下标\n");
        return 0;
    }
    comb[0]=c2;
    combination(c1, c2);        /* C(4, 2) */
    return 0;
}
