#include <iostream>
#include <vector>
int main()
{
	std::vector<std::vector<std::vector<int> > > a(2);//创建2个vector<vector<int> >类型的数组
	for (int n = 0; n < 2; n++)
	{
		a[n].resize(4);
	}//要先对二维数组设定大小
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			a[i][j].resize(2);
		}//之后才能对三维数组设定大小，否则内存出错
	}

	int m = 1;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				a[i][j][k] = m++;
			}
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				std::cout << a[i][j][k] << std::endl;
			}
		}
	}
	std::cin.get();
	return 0;
}