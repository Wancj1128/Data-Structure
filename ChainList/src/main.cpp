#include<iostream>
#include"Log.h"

class Node
{
public:
	ElemType data;
	Node* next;
};

class List
{
public:
	Node* head;
	int size;
};

List* InitList() {
	List *list = new List;
	list->size = 0;
	list->head = new Node;
	list->head->next = NULL;
	list->head->data = NULL;
	return list;
}

//头插法：
int insertHead(List& list, ElemType e)
{
	Node* new_node = new Node;
	new_node->data = e;
	new_node->next = list.head->next;
	list.head->next = new_node;
	list.size++;
	return 1;
}

//链表的遍历
void ListElem(List& list) {
	if (list.size == 0) {
		std::cout << "此链表中没有数据！" << std::endl;
		return;
	}
	Node *position = list.head->next;
	while (position != NULL) {
		std::cout << position->data << "\t";
		position = position->next;
	}
}

int main() {
	List* list = InitList();
	insertHead(*list, 1);
	insertHead(*list, 2);
	insertHead(*list, 3);
	insertHead(*list, 4);
	ListElem(*list);
}