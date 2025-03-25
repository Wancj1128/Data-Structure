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
int HeadInsert(Node* list, ElemType e) {
    Node* NewNode = new Node;   //创建一个新的节点，并将e传入data中
    NewNode->data = e;
    NewNode->prev = list;
    NewNode->next = list->next;
    if (list->next != nullptr) {
        list->next->prev = NewNode;
    }
    list->next = NewNode;
    return 1;
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

//在指定的位置插入数据
int Insert(Node* list, int position, ElemType e) {
    if (position < 1) {  // position 不能小于 1，因为 1 才是第 1 个数据元素
        std::cout << "非法的插入位置！\n";
        return 0;
    }

    Node* NewNode = new Node;
    NewNode->data = e;

    Node* l = list->next; // 从第 1 个数据节点开始遍历
    for (int i = 0; i < position-1 && l != nullptr; i++) {
        l = l->next;
    }

    if (l == nullptr) {
        std::cout << "插入位置超出范围！\n";
        return 0;
    }

    // 插入新节点
    NewNode->next = l;
    NewNode->prev = l->prev;

    if (l->prev != nullptr) {
        l->prev->next = NewNode;
    }

    l->prev = NewNode;

    return 1;
}

//删除节点
int DeleteNode(Node* list, int position) {
    if (position < 1) {
        std::cout << "删除位置不合法！";
        return 0;
    }
    Node* L = list->next;
    for (int i = 0; i < position-1; i++) {
        L = L->next;
    }
    if (L == nullptr) {
        std::cout << "删除位置超出范围";
        return 0;
    }

    if (L->next != nullptr) {
        L->next->prev = L->prev;  // 让后继节点的 prev 指向 L 的 prev
    }

    if (L->prev != nullptr) {
        L->prev->next = L->next;  // 让前驱节点的 next 指向 L 的 next
    }
    delete L;
    return 1;
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
    Insert(list, 2,10);
    Insert(list, 3,11);
    ListElem(list);
    DeleteNode(list, 2);
    ListElem(list);
    DeleteNode(list, 3);
    ListElem(list);
}