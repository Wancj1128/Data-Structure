//������Ҫ���һ���㷨������������data�ľ���ֵ��ȵĽڵ㣬
//��������һ�γ��ֵĽڵ��ɾ���������ֵ��ͬ�Ľڵ㡣
#include <iostream>
#define ElemType int
#define MAXSIZE 100

enum FlagLevel{
    no_appear = 0, appear
};

class List {
public:
    ElemType data;
    List* next;
};

List* InitList() {
    List *head = new List;
    head->data = NULL;
    head->next = NULL;
    return head;
}

//β�巨��
void InsertTail(List* list,ElemType e) {
    List* new_list = new List;
    new_list->data = e;
    while (list->next != NULL) {
        list = list->next;
    }
    new_list->next = list->next;
    list->next = new_list;
}

//����
void ListElem(List* list) {
    List *L = list;
    while (L->next != NULL) {
        L = L->next;
        std::cout << L->data << "\t";
    }
    std::cout<<"\n";
}

//ɾ������ڵ㣬������һ�γ��ֵĽڵ�
void SelectList(List *list, int length) {
    //����һ������������ͬ�����飬��ʼֵ��Ϊ0�����������������dataֵʱ��
    //�������Ӧ�±괦����Ӧ��ֵ�޸�Ϊ1������ڶ��γ���ʱ�����ԡ�
    List* p = list;
    //indexΪ������±�
    int index;
    int *position = new int[length + 1];
    //�������飬��ʼֵ��Ϊ0
    for (int i = 0; i < length+1; i++) {
        position[i+1] = 0;
    }
    while (p->next != NULL) {
        //���������±�
        index = abs(p->next->data);
        if (position[index] == no_appear) {
            position[index] = appear;
            p = p->next;
        }
        else {
            List* temp = p->next;
            p->next = temp->next;
            delete temp;
        }
    }
    delete[] position;
}

//��ת����
List* ReverseList(List &list) {
    List* first = NULL;
    List* second = list.next;
    List* third;
    while (second != NULL) {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    List *reverse = InitList();
    reverse->next = first;
    return reverse;
}

//ʹ�ÿ���ָ����ɾ����������м�һ���ڵ�
void DeleteCenterList(List *list) {
    //��ָ��ÿ����������ָ�����һ��
    List* fastNode = list->next;
    List *slowNode = list;
    while (fastNode->next != NULL ) {
        List* p = fastNode->next;
        fastNode = p->next;
        slowNode = slowNode->next;
    }
    List* centerNode = slowNode->next;
    slowNode->next = centerNode->next;
    delete centerNode;
}
int main() {
    List* list1 = InitList();
    InsertTail(list1, 21);
    InsertTail(list1, -15);
    InsertTail(list1, 15);
    InsertTail(list1, -7);
    InsertTail(list1, 15);

    DeleteCenterList(list1);
    ListElem(list1);
    // List* list2 = ReverseList(*list1);
    // ListElem(list2);
    // SelectList(list1,21);
    // ListElem(list1);

}