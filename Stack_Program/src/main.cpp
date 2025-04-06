#include <iostream>
#define MAXSIZE 100
#define ElemType int

//ջ��˳��ṹ����ջ�Ķ���
class Stack {
public:
    ElemType data[MAXSIZE];
    int top;
};
//ջ�ĳ�ʼ��
void InitStack(Stack* stack) {
    stack->top = -1;
}

//�ж�ջ�Ƿ�Ϊ��
bool IsitNull(Stack* stack) {
    if (stack->top == -1) return true;

    return false;
}
//��ջ
int Push(Stack* stack, ElemType e) {
    if (stack->top == MAXSIZE - 1) {
        std::cout<<"��ջ����";
        return 0;
    }

    stack->top++;
    stack->data[stack->top] = e;
    return 1;
}
//��ջ
int Pop(Stack* stack, ElemType* e) {
    if (stack->top == -1) {         //�ж��Ƿ�Ϊ��
        std::cout<<"��ջΪ�գ�";
        return 0;
    }

    *e = stack->data[stack->top];
    stack->top--;
    return 1;
}

//��ȡջ��Ԫ��
int GetTop(Stack* stack, ElemType* e) {
    if (stack->top == -1) {         //�ж��Ƿ�Ϊ��
        std::cout<<"��ջΪ�գ�";
        return 0;
    }
    *e = stack->data[stack->top];
    return 1;
}
int main() {
    return 0;
}