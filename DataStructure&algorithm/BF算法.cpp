/*BF�㷨(Brute Force) C����ʵ��*/
/*�㷨������Ҫ����M*(N-M+1)�αȽϣ�ʱ�临�Ӷ�ΪO(M*N)*/

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

	//��ȡĿ�괮��ģʽ��
	printf("������Ŀ�괮\n");
	sour = gets_s(_buffers, BUFFER_SIZE);	
	fflush(stdin);
	printf("������ģʽ��\n");
	tar = gets_s(_buffert, BUFFER_SIZE);
	fflush(stdin);
	printf("Ŀ�괮Ϊ: %s\nģʽ��Ϊ: %s\n", sour, tar);

	BF(sour, tar);

	getchar();
	getchar();
	return 0;
}

void BF(char* sour, char* tar)
{
	int s, t;
	s = t = 0;		//����
	int sour_size = strlen(sour);
	int tar_size = strlen(tar);
	while (s >= 0 && s <= sour_size - tar_size )
	{
		if (sour[s+t] == tar[t])    
		{
			/*Ϊ�˷�����ʾƥ�䲽�裬�Ͳ���sour������ֵ���������Ĳ�������������������
			  �������ʾ���裬���Խ��ж�sour[s] == tar[t]����s��t�ֱ�����������ʱ
			  s = s - t + 1����
			*/

			{//ֱ����ʾƥ�����
				printf("%s\n", sour);
				for (int i = 0; i < s; i++)
				{
					printf(" ");
				}
				printf("%s\n", tar);
			}

			t++;		//����ֵ����1
			if (t >= tar_size)
			{
				printf("�ڵ�%d-%d��λ��ƥ��ɹ�\n", s+1, s + t);
				break;
			}
		}
		else
		{
			{//��ʾƥ�����
				printf("%s\n", sour);
				for (int i = 0; i < s; i++)
				{
					printf(" ");
				}
				printf("%s\n", tar);
			}
			//����
			s = s + 1;
			t = 0;
		}
	}
	//printf("ģʽ����Ŀ�괮�󣬲��ܱȽ�\n");
}

