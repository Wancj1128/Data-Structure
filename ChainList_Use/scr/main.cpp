//需求：需要设计一个算法，对于链表中data的绝对值相等的节点，
//仅保留第一次出现的节点而删除其余绝对值相同的节点。
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

//尾插法：
void InsertTail(List* list,ElemType e) {
    List* new_list = new List;
    new_list->data = e;
    while (list->next != NULL) {
        list = list->next;
    }
    new_list->next = list->next;
    list->next = new_list;
}

//遍历
void ListElem(List* list) {
    List *L = list;
    while (L->next != NULL) {
        L = L->next;
        std::cout << L->data << "\t";
    }
    std::cout<<"\n";
}

//删除其余节点，保留第一次出现的节点
void SelectList(List *list, int length) {
    //创立一个和链表长度相同的数组，初始值都为0，当链表遍历访问其data值时，
    //将数组对应下标处所对应的值修改为1，当其第二次出现时，忽略。
    List* p = list;
    //index为数组的下标
    int index;
    int *position = new int[length + 1];
    //遍历数组，初始值设为0
    for (int i = 0; i < length+1; i++) {
        position[i+1] = 0;
    }
    while (p->next != NULL) {
        //传入数组下标
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

//反转链表
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

//使用快慢指针来删除单链表的中间一个节点
void DeleteCenterList(List *list) {
    //快指针每走两步，慢指针才走一步
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