#include <iostream>
#include <vector>
int main()
{
	std::vector<std::vector<std::vector<int> > > a(2);//����2��vector<vector<int> >���͵�����
	for (int n = 0; n < 2; n++)
	{
		a[n].resize(4);
	}//Ҫ�ȶԶ�ά�����趨��С
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			a[i][j].resize(2);
		}//֮����ܶ���ά�����趨��С�������ڴ����
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