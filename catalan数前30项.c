#include <stdio.h>
int main()
{
	int i, N;
	double catalan = 1;
//	scanf("%d", &N);
	N = 30;
	printf("1\n");
	for(i = 0; i < N; i++)
	{
		catalan = catalan * ((double)(4*i+2)/(i+2));
		printf("%lf ", catalan);
		printf("\n");
	}
	return 0;
}
