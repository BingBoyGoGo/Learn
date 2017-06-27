/****约瑟夫问题，这是一个事关生命的问题。传说有一天，39个犹太人躲避战乱逃到了一个洞里，洞里还有约瑟夫和他的一个朋友。
		犹太人呢宁死不屈，为了不让敌人抓住，于是发明了一个死亡游戏。犹太人一致决定，41个人围成一个圈，从第一个人开始
		数数，当数到3的那个人呢那个人就刺自己一下，把自己给杀了。比如第1个人开始数数，第3个数到3就自杀，接着第4个开始
		数1，第6个数到3就自杀……以此类推，直到41个人都杀掉自己。约瑟夫和他的朋友想着不能就这么轻易的go die，但是犹太
		人这么多他们又不能傻BB地奋起反抗。那怎么办呢，聪明的约瑟夫想到，不管自杀的顺序是怎么的，最后总会有两个人剩下。
		约瑟夫先生略作思考，就把自己和朋友分别排到了第16个和第31个位置，最后39个犹太人呢全都自杀了，剩下了约瑟夫和他的
		朋友，所有人都达到了自己的目的，皆大欢喜（虽然有点血腥，但是约瑟夫凭借自己的智慧活了下来）。
	*以上就是约瑟夫问题。那约瑟夫问题和循环链表又能有什么联系呢？我们这么想，41个人手拉手围成了一个圈，最后一个人又拉着
		第一个人的手，这样就构成了一个循环，当某个人自杀之后，前一个人就越过了这个人牵了下一个人的手，如此循环往复。我们可以
		简单的归纳为一个算法问题，即一共有41个节点的循环链表，去掉一个节点，前一个节点就指向下一个节点，直到所有节点都被删除了为止。
	*比如，要删除第3个节点，那么第2个节点的next就指向第4个节点(p->next = p->next->next)，接着删除第三个节点(delete p->next)。
		思路明确，我们就开始我们的代码。
*****/
#include <iostream>
typedef struct Bing {
	int data;
	Bing *next;
}Bing;//节点的属性
Bing* creat(int count)
{
	if (count < 1)
		exit(0);//表至少得有一个节点

	Bing *head = new Bing;
	Bing *newNode = NULL;
	Bing *p = head;
	head->data = 1;//创建第一个节点
	
	int i = 1;
	while(i++<count)
	{
		newNode = new Bing;
		newNode->data = i;
		p->next = newNode;
		p = newNode;
	}
	p->next = head;//屁股指向头

	return head;
}
void kill(Bing *p, int num)
{
	Bing *del = NULL;
	while (p->next != p)					//判断是否只剩下一个节点
	{
		for (int i = 1; i < num - 1; i++)
			p = p->next;					//索引到删除节点的前一个节点
		std::cout << p->next->data << "->";
		del = p->next;						//要删除的节点
		p->next = p->next->next;
		delete del;
		p = p->next;
	}
	std::cout << p->data << std::endl;
	delete p;
}

int main()
{
	const int num = 3;

	Bing *head = creat(41);
	Bing *p = head;
	Bing *del=NULL;

	while (p->next != head)
	{
		std::cout << p->data;
		p = p->next;
	}
	std::cout << p->data << std::endl;

	p = head;
	kill(p, num);

	std::cin.get();
	return 0;
}