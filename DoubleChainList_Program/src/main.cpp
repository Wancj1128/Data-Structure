#include <iostream>
#define ElemType int
#define MAXSIZE 100


//˫������Ķ���
//���뵥����������ǣ�������ֻ��һ�����ָ��ָ���һ�ڵ㣬˫���������ǰ���ڵ����к�̽ڵ㣩
class Node {
public:
    Node *prev, *next;
    ElemType data;
};

//˫����ĳ�ʼ������
Node* InitList() {
    Node* head = new Node;
    head->data = NULL;
    head->prev = nullptr;
    head->next = nullptr;
    return head;
}

//˫�����ͷ�巨����
void HeadInsert(Node* list, ElemType e) {
    Node* NewNode = new Node;   //����һ���µĽڵ㣬����e����data��
    NewNode->data = e;
    NewNode->prev = list->next;
    NewNode->next = list->next;
    list->next = NewNode;
}

//˫�����β�巨����
void TailInsert(Node* list, ElemType e) {
    Node* NewNode = new Node;
    NewNode->data = e;
    Node* position = list;
    while (position->next != nullptr) {
        position = position->next;
    }
    NewNode->next = position->next;
    NewNode->prev = position;
    position->next = NewNode;
}

//˫����ı�������
void ListElem(Node* list) {
    Node* position = list->next;
    while (position != nullptr) {
        std::cout << position->data << "\t";
        position = position->next;
    }
    std::cout << "\n" << std::endl;
}

int main() {
    Node* list = InitList();
    HeadInsert(list,1);
    HeadInsert(list,2);
    HeadInsert(list,3);
    HeadInsert(list,4);
    HeadInsert(list,5);
    HeadInsert(list,6);
    TailInsert(list,7);
    TailInsert(list,8);
    ListElem(list);
}