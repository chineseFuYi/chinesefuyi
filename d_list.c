//double_list

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bzero(a, b)             memset(a, 0, b)

//�ڵ�ṹ�壬ÿ���ڵ�ֱ𱣴���һ��ָ��ǰһ���ڵ��ָ���ָ���һ���ڵ��ָ�룬�Լ��������ݵ�ָ��
struct _node {																//����һ��_node���͵Ľṹ��
	struct _node *prevNode;													//����ǰһ���ڵ��ָ��
	struct _node *nextNode;													//���Ӻ�һ���ڵ��ָ��
	void *data;																//��¼�ڵ����ݵ�ָ��
};


//����ṹ�壬��¼��������׽ڵ��β�ڵ�ָ�룬�Լ��ڵ��ܸ���
struct _list {																//����һ��_list���͵Ľṹ��
	struct _node *firstNode;												//��¼�����ͷ�ڵ�
	struct _node *lastNode;													//��¼�����β�ڵ�
	int len;																//��¼������
};


//ͷ����ӽڵ�
void hpush(struct _list *list, void *data)
{
	struct _node *node = (_node*)malloc(sizeof(struct _node));				//����һ���½ڵ�
	memset(node, 0, sizeof(struct _node));									//��ʼ������ڵ�
	node->data = data;														//�����ݷ����½ڵ�
	node->nextNode = list->firstNode;										//�½ڵ����һ�ڵ�����������ĵ�һ���ڵ�
	if (list->firstNode != NULL)											//���������ͷ�ڵ�
	{
		list->firstNode->prevNode = node;									//��ǰ�����ͷ�ڵ��ǰһ���ڵ���ڵ�ǰ�ڵ㣨�������һ����ͨ�ڵ㣩
	}
	list->firstNode = node;													//�����ͷ�ڵ���ڵ�ǰ�ڵ�
	if (list->len == 0)														//���������Ϊ0������ǰû�б�Ľڵ�
	{
		list->lastNode = node;												//����β�ڵ���ǵ�ǰ�ڵ�
	}
	list->len++;															//�����ȼ�һ
}

//β����ӽڵ�
void lpush(struct _list *list, void *data)
{
	struct _node *node = (_node*)malloc(sizeof(struct _node));				//����һ���ڵ�
	memset(node, 0, sizeof(struct _node));									//��ʼ���ýڵ�
	node->data = data;														//�����ݷ����½ڵ�
	node->prevNode = list->lastNode;										//�½ڵ����һ�ڵ����ӵ���ǰ�����β�ڵ�
	if (list->lastNode != NULL)												//���������β�ڵ�
	{
		list->lastNode->nextNode = node;									//��ǰβ�ڵ����һ�ڵ����ӵ���ǰ�ڵ㣨�����ϻ���һ����ͨ�ڵ㣩
	}
	list->lastNode = node;													//�����β�ڵ�����Ϊ�½ڵ�
	if (list->len == 0)														//���������Ϊ0��������Ϊ������
	{
		list->firstNode = node;												//����ͷ�ڵ���ǵ�ǰ�½ڵ�
	}
	list->len++;															//�����ȼ�һ
}

//ɾ��ͷ�ڵ�
void hpop(struct _list *list)
{
	if (list->firstNode == NULL)											//���û��ͷ�ڵ㣬ֱ������
	{
		return;																//ֱ������
	}
	if (list->firstNode->nextNode != NULL)									//���ͷ�ڵ���ָ�����һ�ڵ㲻Ϊ��
	{
		list->firstNode = list->firstNode->nextNode;						//��ͷ�ڵ����ó���һ�ڵ�
		free(list->firstNode->prevNode);									//���֮ǰ��ͷ�ڵ�
		list->firstNode->prevNode = NULL;									//����ǰͷ�ڵ��ǰһ�ڵ����óɿ�
	}
	else																	//�����һ�ڵ�Ϊ��
	{
		free(list->firstNode);												//��ոýڵ�
		list->firstNode = NULL;												//���������ͷ�ڵ�ɿ�
	}
	list->len--;															//�����ȼ�һ
	if (list->len == 0)														//���������Ϊ��
	{
		list->lastNode = NULL;												//���������β�ڵ�Ϊ��
	}
}

//ɾ��β�ڵ�
void lpop(struct _list *list)
{
	if (list->lastNode == NULL)												//���û��β�ڵ㣬ֱ������
	{
		return;																//ֱ������
	}
	if (list->lastNode->prevNode != NULL)									//���β�ڵ���ָ�����һ�ڵ㲻Ϊ��
	{
		list->lastNode = list->lastNode->prevNode;							//��β�ڵ����ó���һ�ڵ�
		free(list->lastNode->nextNode);										//���֮ǰ��β�ڵ�
		list->lastNode->nextNode = NULL;									//����ǰβ�ڵ����һ�ڵ����óɿ�
	}
	else																	//�����һ�ڵ�Ϊ��
	{
		free(list->lastNode);												//��ոýڵ�
		list->lastNode = NULL;												//���������β�ڵ�ɿ�
	}
	list->len--;															//�����ȼ�һ
	if (list->len == 0)														//���������Ϊ��
	{
		list->firstNode = NULL;												//���������ͷ�ڵ�Ϊ��
	}
}

//ȡ���������p����ֵ
void getval(struct _list *list, int p)
{
	if (p > list->len)														//���p�ĳ��ȴ���������
	{
		printf("NO.%d node is not exist\r\n", p);							//��ʾ�����ڸýڵ�
		return;																//���ؿ�ֵ
	}
	if (p < 0)																//���pС����
	{
		printf("NO.%d node is not exist\r\n", p);							//��ʾ�����ڸýڵ�
		return;																//���ؿ�ֵ
	}
	struct _node *curnode = list->firstNode;								//����һ��node���ͽڵ��curnode

	for (int i = 1; i < p; i++)												//����ѭ����ѭ��p��
	{
		curnode = curnode->nextNode;										//���ڵ�����Ųһλ
	}
	printf("NO.%d node's data is %s\r\n", p, (char*)curnode->data);				//���ص�p���ڵ����ֵ
}

//��ӡ����
static void print(struct _list *list)
{
	printf("-----------print the list-------------\r\n");					//��ӡ��ͷ
	printf("This list's len is %d\r\n", list->len);							//���������ж೤
	struct _node *node = list->firstNode;									//����һ�ڵ�Ϊ����ͷ�ڵ�
	int i = 1;																//����һ��i
	while (1)																//������ѭ��
	{
		if (node == NULL)													//����ڵ�Ϊ��
		{
			printf("---------------end of this list----------------\r\n");
			printf("\r\n");
			break;															//����ѭ��
		}
		printf("node%d is %s\r\n", i, (char*)node->data);							//��ӡ�ڵ���Ϣ
		node = node->nextNode;												//�ڵ�������һλ
		i++;																//i�Լ�
	}																		//
}

int main()
{
	printf("please input a point\r\n");
	int point = 0;
	scanf_s("%d", &point);
	struct _list list = { NULL, NULL, 0 };

	hpush(&list, "node 0");
	hpush(&list, "node 1");
	hpush(&list, "node 2");
	lpush(&list, "node 3");
	lpush(&list, "node 4");
	print(&list);
	getval(&list, point);

	hpop(&list);
	hpop(&list);
	lpop(&list);
	print(&list);
	getval(&list, point);

	hpush(&list, "hello node");
	print(&list);

	system("pause");
}
