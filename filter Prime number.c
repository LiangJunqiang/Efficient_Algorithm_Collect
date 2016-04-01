//筛素数 在 MoreWindows( http://blog.csdn.net/morewindows/article/details/7347459 ) 的基础上进行改进 
//空间压缩者：梁骏强
#include <stdio.h>  
#include <memory.h>
#define	MAXN	100
char flag[MAXN / 8];
int primes[MAXN / 3], pi;
void GetPrime()
{	//小于MAXN的素数有pi个，都放在primes里面啦~！拿去用吧~ 
    int i, j;  
    pi = 0;  
    memset(flag, 0, sizeof(flag));  
    for (i = 2; i < MAXN; i++)  
    {  
        if (!(flag[i / 8] & (1 << (i % 8))))//i在flag上对应的一个二进制位等于 0，也就是说 i 为素数 
            primes[pi++] = i;
//        else printf("%d ", i);//按顺序筛选合数
        for (j = 0; (j < pi)  && (i * primes[j] < MAXN); j++)  
        {	//把现有各素数的 i 倍数 b 标记为合数，其中 b < MAXN 且 素数 primes[j] 不是 i 的因数
			//若 primes[j] 是 i 的因数也继续标记后面primes[j+k]素数的倍数，则合数会被多次重复标记
			//例如遇到 6 % 2 == 0，若不退出内层循环，则 6 * 3 == 9 * 2 会被重复标记 
            flag[i * primes[j] / 8] |= 1 << ((i * primes[j]) % 8);//把i * primes[j]在flag上对应的一个二进制位标记为 1（合数） 
//            printf("%d  ", i * primes[j]);//验证：循环输出合数，未发现重复
			if(i % primes[j] == 0)//这句保证每个非素数只被筛去一次  
                break;
        }
    }
}//GetPrime 
int main()  
{
	int i;
    GetPrime();
    return 0;
}