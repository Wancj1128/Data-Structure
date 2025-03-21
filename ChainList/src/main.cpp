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

//ͷ�巨��
int insertHead(List& list, ElemType e)
{
	Node* new_node = new Node;
	new_node->data = e;
	new_node->next = list.head->next;
	list.head->next = new_node;
	list.size++;
	return 1;
}

//β�巨��
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

//��ָ��λ�ò������ݣ�
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

//�����ɾ��������
void DeleteList(List& list, int position) {
	Node* p = list.head;
	if (position <= 0 || p->next == NULL) {
		std::cout<<"Ҫɾ����λ�ô���";
	}

	for (int i = 0; i < position - 1; i++) {
		p = p->next;
	}
	Node* q = p->next;
	p->next = q->next;
	//�ͷ�Ҫɾ���ڵ�Ŀռ�
	delete q;
	list.size--;
}

//����ı���
void ListElem(List& list) {
	if (list.size == 0) {
		std::cout << "��������û�����ݣ�" << std::endl;
		return;
	}
	Node *position = list.head->next;
	while (position != NULL) {
		std::cout << position->data << "\t";
		position = position->next;
	}
	std::cout << "\n";
}

//�ͷ�����
void FreeList(List* list) {
	Node* p = list->head->next;
	Node* q;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
		list->size--;
	}
	list->head->next = NULL;
}

//�������Ӧ�ã�
//1): ʹ�ÿ���ָ����ҵ�������n���ڵ�����Ӧ������
Node* FindNodeFS(List& list, int k) {
	Node* FastNode = list.head->next;
	for (int i = 0; i < k; i++) {
		FastNode = FastNode->next;
	}
	Node* SlowNode = list.head->next;
	while (FastNode != NULL) {
		FastNode = FastNode->next;
		SlowNode = SlowNode->next;
	}
	return SlowNode;
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
	DeleteList(*list, 2);
	ListElem(*list);
	ListElem(*list);
	Node* position = FindNodeFS(*list, 3);
	std::cout << "�����������ڵ��ֵΪ��" << position->data;
	FreeList(list);
}
