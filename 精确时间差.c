#include <stdio.h>
#include <sys/time.h>
#include <time.h>  
int main() {
	/******************* ��ȷ��΢�� *********************/
	//����ͷ�ļ���sys/time.h 
    struct timeval start, end;
    gettimeofday( &start, NULL );
    sleep(3);
    gettimeofday( &end, NULL );
    int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;
    printf("ʱ���: %d us\n", timeuse);
    /******************* ��ȷ������ *********************/
    //����ͷ�ļ���time.h  
	clock_t clockBegin, clockEnd;
    clockBegin = clock();
    sleep(3);
    clockEnd = clock();  
    printf("ʱ��%d ms\n", clockEnd - clockBegin);
    return 0;
}
