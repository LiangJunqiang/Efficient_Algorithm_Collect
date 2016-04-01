#include <stdio.h>
#include <sys/time.h>
#include <time.h>  
int main() {
	/******************* 精确到微秒 *********************/
	//所用头文件：sys/time.h 
    struct timeval start, end;
    gettimeofday( &start, NULL );
    sleep(3);
    gettimeofday( &end, NULL );
    int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;
    printf("时间差: %d us\n", timeuse);
    /******************* 精确到毫秒 *********************/
    //所用头文件：time.h  
	clock_t clockBegin, clockEnd;
    clockBegin = clock();
    sleep(3);
    clockEnd = clock();  
    printf("时间差：%d ms\n", clockEnd - clockBegin);
    return 0;
}
