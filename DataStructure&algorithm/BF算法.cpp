/*BF算法(Brute Force) C语言实现*/
/*算法最坏情况下要进行M*(N-M+1)次比较，时间复杂度为O(M*N)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void BF(char *sour, char* tar);  

int main()
{
	char* sour;
	char* tar;
	char _buffers[BUFFER_SIZE];
	char _buffert[BUFFER_SIZE];

	//获取目标串和模式串
	printf("请输入目标串\n");
	sour = gets_s(_buffers, BUFFER_SIZE);	
	fflush(stdin);
	printf("请输入模式串\n");
	tar = gets_s(_buffert, BUFFER_SIZE);
	fflush(stdin);
	printf("目标串为: %s\n模式串为: %s\n", sour, tar);

	BF(sour, tar);

	getchar();
	getchar();
	return 0;
}

void BF(char* sour, char* tar)
{
	int s, t;
	s = t = 0;		//索引
	int sour_size = strlen(sour);
	int tar_size = strlen(tar);
	while (s >= 0 && s <= sour_size - tar_size )
	{
		if (sour[s+t] == tar[t])    
		{
			/*为了方便显示匹配步骤，就不对sour的索引值进行自增的操作，而改用算术方法
			  如果不显示步骤，可以将判断sour[s] == tar[t]，将s与t分别自增，回溯时
			  s = s - t + 1即可
			*/

			{//直观显示匹配情况
				printf("%s\n", sour);
				for (int i = 0; i < s; i++)
				{
					printf(" ");
				}
				printf("%s\n", tar);
			}

			t++;		//索引值自增1
			if (t >= tar_size)
			{
				printf("在第%d-%d个位置匹配成功\n", s+1, s + t);
				break;
			}
		}
		else
		{
			{//显示匹配情况
				printf("%s\n", sour);
				for (int i = 0; i < s; i++)
				{
					printf(" ");
				}
				printf("%s\n", tar);
			}
			//回溯
			s = s + 1;
			t = 0;
		}
	}
	//printf("模式串比目标串大，不能比较\n");
}

