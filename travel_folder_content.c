#include "stdio.h"
#include "io.h"
int main()
{
	struct _finddata_t	files;//存放文件信息的结构体，结构体定义：http://baike.baidu.com/link?url=2Y9xlAXHF9xryb0Ur8VknegsVVzr7Njy4IVZ2ir0KRoyDnUmpWEpjLqByQ8v_iZ3rbfPW6XgvoKmG_zvtXW71a
	int			File_Handle;
	int			i = 0;
	File_Handle = _findfirst( "C:/Users/admin/Desktop/bjcsv/*.csv", &files );//搜索与指定的文件名称匹配的第一个实例，若成功则返回第一个实例的句柄，否则返回-1L。一个句柄是指使用的一个唯一的整数值，即一个4字节(64位程序中为8字节)长的数值，来标识应用程序中的不同对象和同类中的不同的实例
	//*.csv表示遍历后缀名为.csv的文件
	if ( File_Handle == -1 )
	{
		printf( "error\n" );
		return(0);
	}
	do
	{
		
		i++;
	}
	while ( 0 == _findnext( File_Handle, &files ) );//搜索下一个实例
	_findclose( File_Handle );
	printf( "Find %d files\n", i );
	return(0);
}
