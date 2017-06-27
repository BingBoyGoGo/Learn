#include <iostream>
#include <string>
#include <stdlib.h>

typedef struct LinkList {
	int data;
	LinkList *next;
}LinkLIst;

bool deleteNode(int count,int position, LinkList *p);
bool insertNode(int count,int position, LinkList *p);
LinkList* creatLinkList(int count);
bool delLinkList(LinkList *p, int count);
LinkList* seekLinkList(int count,int position,LinkList *p);

/*************************************************/
LinkList* seekLinkList(int count,int position, LinkList *headNode)
{
	LinkList *prev = NULL;
	
	if (position > count || position <= 0)
	{
		std::cout << "seek position error\n";//判断查找的位置是否异常
	}
	else
	{
		prev = headNode;
		int i = 0;
		while(i++<position-1)
		{
			prev = prev->next;
		}//prev指向第position节点的前一个节点
	}
	
	return prev;
}//返回第position个节点的前一个节点的地址

/*************************************************/
bool deleteNode(int count,int position,LinkList *headNode)
{
	bool ok = true;
	LinkList *prev = seekLinkList(count,position,headNode);

	if (prev == NULL || prev->next == NULL)
	{
		std::cout << "delete error\n";
		ok = false;
		return ok;
	}
	
	LinkList *delNode = prev->next;//要删除的节点
	prev->next = prev->next->next;//越过要删除的节点指向下一个节点
	delete delNode;//删除节点
	
	return ok;
}

/*************************************************/
bool insertNode(int count,int position,LinkList *headNode)
{
	bool ok = true;
	LinkList *newNode = new LinkList;
	LinkList *prev = NULL;
	
	if (!(headNode->next == NULL) && position != 0 && position < count)
	{
		prev = seekLinkList(count,position,headNode);
		newNode->next = prev->next;
		prev->next = newNode;
	}
	else
	{
		ok = false;
	}
	if ( prev->next == NULL )
		ok = false;
	
	return ok;
}

/*************************************************/
LinkList* creatLinkList(int count)
{
	bool c_error = false;
	int i = 1;

	LinkList *newNode = new LinkList;
	LinkList *headNode = newNode;
	headNode->next = NULL;
	LinkList *prevNode = newNode;

	while (i++ < count)
	{
		newNode = new LinkList;
		prevNode->next = newNode;
		prevNode = newNode;
	}
	prevNode->next = NULL;

	//以下语句判断是否创建失败
	if (headNode->next == NULL)
		c_error = true;

	if (c_error)
	{	
		delete headNode;
		std::cout << "creat error\n";
	}
	else
		return headNode;
}

/*******************************************/
bool delLinkList(LinkList *headNode,int count)
{
	bool ok = true;
	if (headNode == NULL)
	{
		ok = false;
		return ok;
	}
	LinkList *curNode = headNode;
	LinkList *nextNode = curNode->next;
	while (curNode->next != NULL)
	{
		delete curNode;
		curNode = nextNode;
		nextNode = curNode->next;
	}
	delete curNode;

	return ok;
}

int main()
{
	const int count = 8;
	LinkList *headNode =  creatLinkList(count);
	LinkList *curNode = headNode;
	int i = 1;

	while (curNode->next != NULL)
	{
		curNode->data = i++;
		curNode = curNode->next;
	}

	curNode = headNode;
	std::cout << "own data      next data\n";
	while (curNode->next != NULL)
	{
		std::cout << curNode->data << "                 " << curNode->next->data << std::endl;
		curNode = curNode->next;
	}
	
	if (insertNode(count, 4, headNode))
	{
		std::cout << "Insert a Node after the 3rd node.\n";
		curNode = headNode;
		for (int i = 0; i < 3; i++)
		{
			curNode = curNode->next;
		}
		curNode->data = 100;
		curNode = headNode;
		while (curNode->next != NULL )
		{
			std::cout << curNode->data << "                 " << curNode->next->data << std::endl;
			curNode = curNode->next;
		}
	}

	if (deleteNode(count, 4, headNode))
	{
		curNode = headNode;
		std::cout << "after delete the Node.\n";
		while(curNode->next != NULL)
		{
			std::cout << curNode->data << "                 " << curNode->next->data << std::endl;
			curNode = curNode->next;
		}
	}
	
	std::cin.get();
	delLinkList(headNode, count);
	return 0;
}