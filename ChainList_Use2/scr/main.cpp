#include <iostream>
#define ElemType int
#define MAXSIZE 100

//����һ������������������ڵ㣬���ݡ�
class List {
public:
    ElemType data;
    List* next;
};

//������ĳ�ʼ��
List* InitList() {
    List *head = new List;
    head->data = NULL;
    head->next = nullptr;
    return head;
}

//β�巨��
void InsertTail(List* list,ElemType e) {
    List* new_list = new List;
    new_list->data = e;
    while (list->next != nullptr) {
        list = list->next;
    }
    new_list->next = list->next;
    list->next = new_list;
}

//����
void ListElem(List* list) {
    List *L = list;
    while (L->next != nullptr) {
        L = L->next;
        std::cout << L->data << "\t";
    }
    std::cout<<"\n";
}

//������Ҫ��������list{1,2,3,4,...n,n+1}����list2{1��n+1��2��n,}��ʽ���
//1:�ҵ�ԭ��������м�ڵ㣬���������Ϊ��������
//2:��������ת
//3:��ת�󽫺������нڵ㰴��˳����뵽ǰ������

//�ҵ��м�ڵ㣬���������Ϊ��������

List* FindMiddleNode(List* list) {
    List* slowNode = list;
    List* fastNode = list->next;

    while (fastNode != nullptr && fastNode->next != nullptr) {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
    }

    List* middleNode = slowNode->next;  // ��벿�ֵ����
    slowNode->next = nullptr;  // **�Ͽ�ǰ������**
    return middleNode;
}

//2:��ת����
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

//3:���뷴ת�����γ�������
void NewList(List* list) {
    List* middleNode = FindMiddleNode(list);
    List* tailList = InitList();
    tailList->next = middleNode;

    //(��Ҫ����ͷ�ڵ�)
    List* rollbackTail = RollbackList(tailList)->next;        //�������ķ�ת����RollbackTail
    List* headList = list->next;      //ǰ������Ϊheadlist

    List* newList = InitList();     //�½�һ���������洢�ϳɵ�����currΪ�������ͷָ��
    List* curr = newList;
    while (rollbackTail != nullptr && headList != nullptr) {    //����ĺϲ�
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