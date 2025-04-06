#include <iostream>
#define MAXSIZE 100
#define ElemType int

//栈的顺序结构——栈的定义
class Stack {
public:
    ElemType data[MAXSIZE];
    int top;
};
//栈的初始化
void InitStack(Stack* stack) {
    stack->top = -1;
}

//判断栈是否为空
bool IsitNull(Stack* stack) {
    if (stack->top == -1) return true;

    return false;
}
//入栈
int Push(Stack* stack, ElemType e) {
    if (stack->top == MAXSIZE - 1) {
        std::cout<<"此栈已满";
        return 0;
    }

    stack->top++;
    stack->data[stack->top] = e;
    return 1;
}
//出栈
int Pop(Stack* stack, ElemType* e) {
    if (stack->top == -1) {         //判断是否为空
        std::cout<<"此栈为空！";
        return 0;
    }

    *e = stack->data[stack->top];
    stack->top--;
    return 1;
}

//获取栈顶元素
int GetTop(Stack* stack, ElemType* e) {
    if (stack->top == -1) {         //判断是否为空
        std::cout<<"此栈为空！";
        return 0;
    }
    *e = stack->data[stack->top];
    return 1;
}
int main() {
    return 0;
}