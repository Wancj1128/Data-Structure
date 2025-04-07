#include <complex.h>
#include <iostream>
#define MAXSIZE 100
#define ElemType int

//队列的定义：
class Queue {
public:
    ElemType data[MAXSIZE];
    int front;
    int rear;
};

//队列的初始化
void InitQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = 0;
}

//判断队列是否为空(需判断队列的front和rear是否相等，若相等则说明队列为空)
bool IsitEmpty(Queue* queue) {
    if (queue->front == queue->rear) {
        return true;
    }
    return false;
}

//出队操作
ElemType DeQueue(Queue* queue) {
    if (IsitEmpty(queue)) {
        std::cout<<"此队列为空";
        return 0;
    }
    ElemType e = queue->data[queue->front];
    queue->front++;
    return e;
}

//队尾满了，调整位置
int QueueFull(Queue* queue) {
    if (queue->front > 0) {
        int step = queue->front;
        for (int i = queue->front; i < queue->rear; ++i) {
            queue->data[i - step] = queue->data[i];
        }
        queue->front = 0;
        queue->rear = queue->rear - step;
        return 1;
    }
    else {
        std::cout<<"真的满了";
        return 0;
    }
}

//获取队头数据
int GetHead(Queue* queue, ElemType *e) {
    if (IsitEmpty(queue)) {
        std::cout<<"队列为空！";
        return 0;
    }
    *e = queue->data[queue->front];
    return 1;
}

//入队操作
int Equeue(Queue* queue, ElemType e) {
    if (queue->rear >= MAXSIZE) {
        if (!QueueFull(queue)) {
            return 0;
        }
    }
    queue->data[queue->rear] = e;
    queue->rear++;
    return 1;
}
int main() {
    ElemType E;
    Queue *queue = new Queue;
    InitQueue(queue);

    Equeue(queue, 1);
    Equeue(queue, 2);
    Equeue(queue, 3);
    Equeue(queue, 4);
    
    std::cout << DeQueue(queue) << "\n";
    std::cout << DeQueue(queue) << "\n";

    GetHead(queue, &E);
    std::cout << E << std::endl;
    std::cin.get();
    return 0;
}