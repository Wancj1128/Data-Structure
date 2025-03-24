#include <iostream>
#define ElemType int
#define MAXSIZE 100

//定义一个单链表，里面包含：节点，数据。
class List {
public:
    ElemType data;
    List* next;
};

//单链表的初始化
List* InitList() {
    List *head = new List;
    head->data = NULL;
    head->next = nullptr;
    return head;
}

//尾插法：
void InsertTail(List* list,ElemType e) {
    List* new_list = new List;
    new_list->data = e;
    while (list->next != nullptr) {
        list = list->next;
    }
    new_list->next = list->next;
    list->next = new_list;
}

//遍历
void ListElem(List* list) {
    List *L = list;
    while (L->next != nullptr) {
        L = L->next;
        std::cout << L->data << "\t";
    }
    std::cout<<"\n";
}

//需求：需要将单链表list{1,2,3,4,...n,n+1}，以list2{1，n+1，2，n,}格式输出
//1:找到原单链表的中间节点，并将链表分为两个链表
//2:将后链表反转
//3:反转后将后链表中节点按照顺序插入到前链表中

//找到中间节点，并将链表分为两个链表

List* FindMiddleNode(List* list) {
    List* slowNode = list;
    List* fastNode = list->next;

    while (fastNode != nullptr && fastNode->next != nullptr) {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
    }

    List* middleNode = slowNode->next;  // 后半部分的起点
    slowNode->next = nullptr;  // **断开前后链表**
    return middleNode;
}

//2:反转链表
List* RollbackList(List* list) {
    List* first = nullptr;
    List* second = list->next;
    List* third;
    while (second != nullptr) {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    List* reverse = InitList();
    reverse->next = first;
    return reverse;
}

//3:插入反转链表，形成新链表
void NewList(List* list) {
    List* middleNode = FindMiddleNode(list);
    List* tailList = InitList();
    tailList->next = middleNode;

    //(需要跳过头节点)
    List* rollbackTail = RollbackList(tailList)->next;        //后段链表的反转链表：RollbackTail
    List* headList = list->next;      //前段链表为headlist

    List* newList = InitList();     //新建一个链表来存储合成的链表，curr为新链表的头指针
    List* curr = newList;
    while (rollbackTail != nullptr && headList != nullptr) {    //链表的合并
        curr->next = headList;
        headList = headList->next;
        curr = curr->next;

        curr->next = rollbackTail;
        rollbackTail = rollbackTail->next;
        curr = curr->next;
    }
    if (headList != nullptr) {
        curr->next = headList;
    }
    ListElem(newList);
}

int main() {
    List* list1 = InitList();
    InsertTail(list1, 1);
    InsertTail(list1, 2);
    InsertTail(list1, 3);
    InsertTail(list1, 4);
    InsertTail(list1, 5);
    InsertTail(list1, 6);
    NewList(list1);
}