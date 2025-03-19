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

//尾插法：
void InsertTail(List& list, ElemType e) {
    Node *new_node = new Node;
	new_node->data = e;
	Node *position = list.head;
	while (true) {
		position = position->next;
		if (position->next == NULL) {
			new_node->next = position->next;
			position->next = new_node;
			list.size++;
			return;
		}
	}
    // for (int i = 0; i < list.size; i++) {
	   //  position = position->next;
    // }
	new_node->next = NULL;
	position->next = new_node;
	list.size++;

}

//在指定位置插入数据：
void Insert(List& list, int position, ElemType e) {
	Node* new_node = new Node;
	new_node->data = e;
	Node* p = list.head;
	for (int i = 0; i < position - 1; i++) {
		p = p->next;
	}
	new_node->next = p->next;
	p->next =new_node;
	list.size++;
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
	InsertTail(*list,5);
	InsertTail(*list,6);
	Insert(*list, 1, 10);
	ListElem(*list);
}
