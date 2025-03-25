#include <iostream>
#define ElemType int
#define MAXSIZE 100


//双向链表的定义
//（与单链表的区别是：单链表只有一个后继指针指向后一节点，双向链表既有前驱节点又有后继节点）
class Node {
public:
    Node *prev, *next;
    ElemType data;
};

//双链表的初始化操作
Node* InitList() {
    Node* head = new Node;
    head->data = NULL;
    head->prev = nullptr;
    head->next = nullptr;
    return head;
}

//双链表的头插法操作
void HeadInsert(Node* list, ElemType e) {
    Node* NewNode = new Node;   //创建一个新的节点，并将e传入data中
    NewNode->data = e;
    NewNode->prev = list->next;
    NewNode->next = list->next;
    list->next = NewNode;
}

//双链表的尾插法操作
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

//双链表的遍历操作
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