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
	for(int i = 0;i < n;i ++){    //�������֣���������
		s = new node;
		scanf("%s",s->name);
		if(head == NULL)head = s;
		else p->next = s;
		p = s;
	}
	int w,x;
	scanf("%d,%d",&w,&x);
	p->next = head;    //ѭ�������p���ڱ�β
	while(--w)
		p = p->next;               //�ӵ�w����ʼ��pͣ��w-1��
	for(int i = 0;i < n;i ++){
		for(int j = 0;j < x-1;j ++){    //����x-1Ҫע�⣡
			p = p->next;
		}
		printf("%s\n",p->next->name);
		p->next = p->next->next;        //ɾ���ڵ�
	}
	return 0;
}

//������Ҫ��ʵ��x=1��ʱ�����˳��ɾ����㣬����pָ���Ҫ����ǰһλ�����⿨��N�ã�WA��N�Σ�= =