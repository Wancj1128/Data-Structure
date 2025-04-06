#include <iostream>
#define MAXSIZE 100
#define ELemType int

//栈的链式结构实现(其中选用链表的头节点对应的下一个节点为栈顶最佳，
//可以使得入栈出栈的时间复杂度都为O(1))
class Stack {
public:
    ELemType data;
    Stack *next;
};

//栈的初始化
Stack* InitStack() {
    Stack* stack = new Stack;
    stack->data = NULL;
    stack->next = nullptr;
    return stack;
}

//判断栈是否为空
bool IsItNull(Stack* stack) {
    if (stack->next == nullptr) {
        std::cout<<"栈为空";
        return true;
    }
    return false;
}

//进栈(链表中的头插法操作)
int Push(Stack* stack, ELemType e) {
        Stack *NewStack = new Stack;
        NewStack->data = e;
        NewStack->next = stack->next;
        stack->next = NewStack;
        return 1;
}

//出栈
int Pop(Stack* stack, ELemType* e) {
    if (IsItNull(stack)) {
        std::cout<<"栈为空，无法出栈！";
        return 0;
    }
    Stack* position = stack->next;
    *e = position->data;
    stack->next = position->next;
    delete position;
    return 1;
}

//获取栈顶元素
int GetTop(Stack* stack, ELemType* e) {
    if (IsItNull(stack)) {
        std::cout<<"栈顶无元素";
        return 0;
    }
    *e = stack->next->data;
    return 1;
}

int main() {

}