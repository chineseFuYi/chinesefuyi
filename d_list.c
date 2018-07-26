//double_list

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bzero(a, b)             memset(a, 0, b)

//节点结构体，每个节点分别保存了一个指向前一个节点的指针和指向后一个节点的指针，以及保存数据的指针
struct _node {																//定义一个_node类型的结构体
	struct _node *prevNode;													//连接前一个节点的指针
	struct _node *nextNode;													//连接后一个节点的指针
	void *data;																//记录节点数据的指针
};


//链表结构体，记录了链表的首节点和尾节点指针，以及节点总个数
struct _list {																//定义一个_list类型的结构体
	struct _node *firstNode;												//记录链表的头节点
	struct _node *lastNode;													//记录链表的尾节点
	int len;																//记录链表长度
};


//头部添加节点
void hpush(struct _list *list, void *data)
{
	struct _node *node = (_node*)malloc(sizeof(struct _node));				//申请一个新节点
	memset(node, 0, sizeof(struct _node));									//初始化这个节点
	node->data = data;														//将数据放入新节点
	node->nextNode = list->firstNode;										//新节点的下一节点连接至链表的第一个节点
	if (list->firstNode != NULL)											//如果链表有头节点
	{
		list->firstNode->prevNode = node;									//当前链表的头节点的前一个节点等于当前节点（后面会变成一个普通节点）
	}
	list->firstNode = node;													//链表的头节点等于当前节点
	if (list->len == 0)														//如果链表长度为0，即当前没有别的节点
	{
		list->lastNode = node;												//链表尾节点就是当前节点
	}
	list->len++;															//链表长度加一
}

//尾部添加节点
void lpush(struct _list *list, void *data)
{
	struct _node *node = (_node*)malloc(sizeof(struct _node));				//申请一个节点
	memset(node, 0, sizeof(struct _node));									//初始化该节点
	node->data = data;														//将数据放入新节点
	node->prevNode = list->lastNode;										//新节点的上一节点连接到当前链表的尾节点
	if (list->lastNode != NULL)												//如果链表有尾节点
	{
		list->lastNode->nextNode = node;									//当前尾节点的下一节点连接到当前节点（他马上会变成一个普通节点）
	}
	list->lastNode = node;													//链表的尾节点设置为新节点
	if (list->len == 0)														//如果链表长度为0，即链表为空链表
	{
		list->firstNode = node;												//链表头节点就是当前新节点
	}
	list->len++;															//链表长度加一
}

//删除头节点
void hpop(struct _list *list)
{
	if (list->firstNode == NULL)											//如何没有头节点，直接跳出
	{
		return;																//直接跳出
	}
	if (list->firstNode->nextNode != NULL)									//如果头节点所指向的下一节点不为空
	{
		list->firstNode = list->firstNode->nextNode;						//将头节点设置成下一节点
		free(list->firstNode->prevNode);									//清空之前的头节点
		list->firstNode->prevNode = NULL;									//将当前头节点的前一节点设置成空
	}
	else																	//如果下一节点为空
	{
		free(list->firstNode);												//清空该节点
		list->firstNode = NULL;												//设置链表的头节点成空
	}
	list->len--;															//链表长度减一
	if (list->len == 0)														//如果链表长度为空
	{
		list->lastNode = NULL;												//设置链表的尾节点为空
	}
}

//删除尾节点
void lpop(struct _list *list)
{
	if (list->lastNode == NULL)												//如何没有尾节点，直接跳出
	{
		return;																//直接跳出
	}
	if (list->lastNode->prevNode != NULL)									//如果尾节点所指向的上一节点不为空
	{
		list->lastNode = list->lastNode->prevNode;							//将尾节点设置成上一节点
		free(list->lastNode->nextNode);										//清空之前的尾节点
		list->lastNode->nextNode = NULL;									//将当前尾节点的下一节点设置成空
	}
	else																	//如果上一节点为空
	{
		free(list->lastNode);												//清空该节点
		list->lastNode = NULL;												//设置链表的尾节点成空
	}
	list->len--;															//链表长度减一
	if (list->len == 0)														//如果链表长度为空
	{
		list->firstNode = NULL;												//设置链表的头节点为空
	}
}

//取出链表里第p个数值
void getval(struct _list *list, int p)
{
	if (p > list->len)														//如果p的长度大于链表长度
	{
		printf("NO.%d node is not exist\r\n", p);							//显示不存在该节点
		return;																//返回空值
	}
	if (p < 0)																//如果p小于零
	{
		printf("NO.%d node is not exist\r\n", p);							//显示不存在该节点
		return;																//返回空值
	}
	struct _node *curnode = list->firstNode;								//创建一个node类型节点叫curnode

	for (int i = 1; i < p; i++)												//建立循环，循环p次
	{
		curnode = curnode->nextNode;										//将节点往后挪一位
	}
	printf("NO.%d node's data is %s\r\n", p, (char*)curnode->data);				//返回第p个节点的数值
}

//打印链表
static void print(struct _list *list)
{
	printf("-----------print the list-------------\r\n");					//打印表头
	printf("This list's len is %d\r\n", list->len);							//声明链表有多长
	struct _node *node = list->firstNode;									//创建一节点为链表头节点
	int i = 1;																//声明一个i
	while (1)																//建立死循环
	{
		if (node == NULL)													//如果节点为空
		{
			printf("---------------end of this list----------------\r\n");
			printf("\r\n");
			break;															//跳出循环
		}
		printf("node%d is %s\r\n", i, (char*)node->data);							//打印节点信息
		node = node->nextNode;												//节点往后走一位
		i++;																//i自加
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
