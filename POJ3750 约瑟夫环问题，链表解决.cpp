#include <stdio.h>
struct node
{
	char name[20];
	node* next;
};
int main()
{
	int n;
	node *s,*p,*head=NULL;
	scanf("%d",&n);
	for(int i = 0;i < n;i ++){    //输入名字，建立链表
		s = new node;
		scanf("%s",s->name);
		if(head == NULL)head = s;
		else p->next = s;
		p = s;
	}
	int w,x;
	scanf("%d,%d",&w,&x);
	p->next = head;    //循环单向表，p留在表尾
	while(--w)
		p = p->next;               //从第w个开始，p停在w-1上
	for(int i = 0;i < n;i ++){
		for(int j = 0;j < x-1;j ++){    //这里x-1要注意！
			p = p->next;
		}
		printf("%s\n",p->next->name);
		p->next = p->next->next;        //删除节点
	}
	return 0;
}

//本题主要是实现x=1的时候可以顺利删除结点，这样p指针就要留在前一位。在这卡了N久，WA了N次！= =