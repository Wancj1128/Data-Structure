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
	ElemType size;
};

List* InitList() {
	List *list = new List;
	list->size = 0;
	list->head = new Node;
	list->head->next = NULL;
	list->head->data = NULL;
	return list;
}

//Í·²å·¨£º
int insertHead(List& list,ElemType e)
{
	list.head->data
}

int main() {
	List* list = InitList();

}