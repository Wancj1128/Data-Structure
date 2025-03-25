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
int HeadInsert(Node* list, ElemType e) {
    Node* NewNode = new Node;   //����һ���µĽڵ㣬����e����data��
    NewNode->data = e;
    NewNode->prev = list;
    NewNode->next = list->next;
    if (list->next != nullptr) {
        list->next->prev = NewNode;
    }
    list->next = NewNode;
    return 1;
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

//��ָ����λ�ò�������
int Insert(Node* list, int position, ElemType e) {
    if (position < 1) {  // position ����С�� 1����Ϊ 1 ���ǵ� 1 ������Ԫ��
        std::cout << "�Ƿ��Ĳ���λ�ã�\n";
        return 0;
    }

    Node* NewNode = new Node;
    NewNode->data = e;

    Node* l = list->next; // �ӵ� 1 �����ݽڵ㿪ʼ����
    for (int i = 0; i < position-1 && l != nullptr; i++) {
        l = l->next;
    }

    if (l == nullptr) {
        std::cout << "����λ�ó�����Χ��\n";
        return 0;
    }

    // �����½ڵ�
    NewNode->next = l;
    NewNode->prev = l->prev;

    if (l->prev != nullptr) {
        l->prev->next = NewNode;
    }

    l->prev = NewNode;

    return 1;
}

//ɾ���ڵ�
int DeleteNode(Node* list, int position) {
    if (position < 1) {
        std::cout << "ɾ��λ�ò��Ϸ���";
        return 0;
    }
    Node* L = list->next;
    for (int i = 0; i < position-1; i++) {
        L = L->next;
    }
    if (L == nullptr) {
        std::cout << "ɾ��λ�ó�����Χ";
        return 0;
    }

    if (L->next != nullptr) {
        L->next->prev = L->prev;  // �ú�̽ڵ�� prev ָ�� L �� prev
    }

    if (L->prev != nullptr) {
        L->prev->next = L->next;  // ��ǰ���ڵ�� next ָ�� L �� next
    }
    delete L;
    return 1;
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
    Insert(list, 2,10);
    Insert(list, 3,11);
    ListElem(list);
    DeleteNode(list, 2);
    ListElem(list);
    DeleteNode(list, 3);
    ListElem(list);
}