#include <iostream>
#define MAXSIZE 100
#define ELemType int

//ջ����ʽ�ṹʵ��(����ѡ�������ͷ�ڵ��Ӧ����һ���ڵ�Ϊջ����ѣ�
//����ʹ����ջ��ջ��ʱ�临�Ӷȶ�ΪO(1))
class Stack {
public:
    ELemType data;
    Stack *next;
};

//ջ�ĳ�ʼ��
Stack* InitStack() {
    Stack* stack = new Stack;
    stack->data = NULL;
    stack->next = nullptr;
    return stack;
}

//�ж�ջ�Ƿ�Ϊ��
bool IsItNull(Stack* stack) {
    if (stack->next == nullptr) {
        std::cout<<"ջΪ��";
        return true;
    }
    return false;
}

//��ջ(�����е�ͷ�巨����)
int Push(Stack* stack, ELemType e) {
        Stack *NewStack = new Stack;
        NewStack->data = e;
        NewStack->next = stack->next;
        stack->next = NewStack;
        return 1;
}

//��ջ
int Pop(Stack* stack, ELemType* e) {
    if (IsItNull(stack)) {
        std::cout<<"ջΪ�գ��޷���ջ��";
        return 0;
    }
    Stack* position = stack->next;
    *e = position->data;
    stack->next = position->next;
    delete position;
    return 1;
}

//��ȡջ��Ԫ��
int GetTop(Stack* stack, ELemType* e) {
    if (IsItNull(stack)) {
        std::cout<<"ջ����Ԫ��";
        return 0;
    }
    *e = stack->next->data;
    return 1;
}

int main() {

}