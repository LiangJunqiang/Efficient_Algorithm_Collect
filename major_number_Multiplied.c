#include<stdlib.h>
#include<conio.h>
#include<string.h> 
#include<stdio.h> 
#include<time.h>  
#define N 7200 //作 72xx 位的整数乘法 
int max(int,int,int);  
int initarray(int a[]);  
void write(int a[],int l);  
FILE *fp;
int main(int argc, char const *argv[])
{
//	int a[5000]={0},b[5000]={0},k[10001]={0}; //声明存放乘数、被乘数与积的数组 
	int k[10001]={0}, a[3] = {999,999,999}, b[] = {999,999,999};
	clock_t start, end; 					//声明用于计时的变量  
	unsigned long c,d,e; 					//声明作累加用的无符号长整数变量 
	int i,j,la,lb,ma,mi,p,q,t; 				//声明其它变量 
	srand((unsigned)time(NULL));			//初始化随机数
//	la=initarray(a); 						//产生被乘数，并返回其长度 
//	lb=initarray(b); 						//产生乘数，并返回其长度   
	la = 3;
	lb = 3;
	if(la<lb) 								//如果被乘数长度小于乘数，则交换被乘数与乘数 
	{  
		p=lb;   
		for (q=0;q<p;q++) 					//交换被乘数与乘数 
		t=a[q],a[q]=b[q],b[q]=t;   
		t=la,la=lb,lb=t; 					//交换被乘数的长度与乘数的长度 
	}   
	start = clock();						//开始计时  
	c=d=0; 									//清空累加变量，其中 C 用于累加斜线间的数，d 用作进位标志 
	for(i=la+lb-2;i>=0;i--) 				//累加斜线间的数，i为横纵坐标之和 
	{  
		c=d; 								//将前一位的进位标志存入累加变量 c 
		ma=max(0,i-la+1,i-lb+1);		 	//求累加的下限 
		mi=(i>la-1)?(la-1):i; 				//求累加的上限  
		for(j=ma;j<=mi;j++)					//计算出横纵坐标之和为i的单元内的数,并累加到 C 中 
			c+=(long)a[j]*b[i-j];
		d=c/1000; 							//求进位标志 
		if(c>999)  
			c%=1000; 						//取 c 的末三位 
		k[i]=c; 							//保存至表示乘积的数组 k[] 
	}
	printf("%ld", d);
	for(i = 0; i <= la+lb-2; i++)
		printf("%3d", k[i]);
	putchar('\n');
//	printf("%ld", e);
	e=k[0]+1000*d; 							//求出乘积的最高位 
	end = clock();							//停止计时  
	fp = fopen("result.txt", "w+"); 		//保存结果到 result.txt  
	printf("\nThe elapsed time was: %3.4f\n", (end - start) / CLK_TCK); //打印消耗的时间 
	fprintf(fp,"%d",a[0]); 					//打印被乘数最高位 
	write(a,la); 							//打印被乘数其他位 
	fprintf(fp,"%d",b[0]); 					//打印乘数最高位 
	write(b,lb); 							//打印乘数其他位 
	fprintf(fp,"%ld",e); 					//打印乘积最高位 
	write(k,la+lb-1); 						//打印乘积其他位 
	fclose(fp); 
	return 0;
}
int max(int a,int b,int c)
{  
	int d;  
	d=(a>b)?a:b;  
	return (d>c)?d:c;  
}    
int initarray(int a[])  
{  
	int q,p,i;   
	q=N+rand()%100;  
	if(q%3==0)  
		p=q/3;  
	else  
		p=q/3+1;    
	for(i=0;i<p;i++)  
		a[i]=rand()%1000;    
	if(q%3==0)   
		a[0]=100+rand()%900;  
	if(q%3==2)  
		a[0]=10+rand()%90;  
	if(q%3==1)  
		a[0]=1+rand()%9;    
	return p;  
}    
void write(int a[],int l)  
{  	
	int i;   
	char string[10];  
	for(i=1;i<l;i++) {   
		itoa(a[i],string,10);  
		if (strlen(string)==1)  
			fprintf(fp,"00");  
		if (strlen(string)==2)  
			fprintf(fp,"0");  
		fprintf(fp,"%s",string);  
		if((i+1)%25==0)  
			fprintf(fp,"\n");  
	}   
	fprintf(fp,"\n");  
	fprintf(fp,"\n");  
}