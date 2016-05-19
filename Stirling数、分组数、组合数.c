#include <stdio.h>
#include <math.h>
typedef long long LL;
LL comb(int m, int n)
{	//统计组合数 
	LL sum = 1;
	int k;
	for(k = 1; k <= n; k++)
		sum = (sum * (m - n + k)) / k;
	return sum;
}
LL Stirling(int n, int k)
{	//第二类斯特林数 
	if(n == 0)
		return 1;
	else if(k == 1 || n == k)
		return 1;
	else if(k == 2)
		return ((LL)pow(2, n - 1) - 1);
	else if(n == (k + 1))
		return comb(n, 2);
	else if(n == (k + 2))
		return (comb(n, 3) + 3 * comb(n, 4));
	else if(k == 3)
		return (LL)((pow(3, n - 1) + 1) / 2 - pow(2, n - 1));
	else if(n == (k + 3))
		return (comb(n, 4) + 10 * comb(n, 5) + 15 * comb(n, 6));
	else return (Stirling(n - 1, k - 1) + k * Stirling(n - 1, k));
}
LL fatorial(int n)
{	//n的阶乘 
	int i;
	LL rs = 1;
	for(i = 1; i <= n; i++)
		rs = rs * i;
	return rs;
}
LL M(int n, int r)
{	//分组数 
	if(r == 1 || n == r || n == r + 1)
		return 1;
	else if(n < r)
		return 0;
	else if(r == 2)
		return n/2;
	else return (M(n - r, r) + M(n - 1, r - 1));
}
int main()
{
	int i;
	int m, n;
	LL d;
	n = 3;
	m = 1;
	scanf("%d%d", &n, &m);
	printf("%lld\n", M(n, m));
	return 0;
}
