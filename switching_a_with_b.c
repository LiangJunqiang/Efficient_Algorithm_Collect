int main()
{
	int a = 12, b = 34, temp;
	a = a + b - (b = a);
	//以下是最简单最快的方法
	temp = a;
	a = b;
	b = temp;
	return 0;	
}
