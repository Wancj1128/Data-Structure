#include <complex.h>
#include <iostream>
#define MAXSIZE 100
#define ElemType int

//���еĶ��壺
class Queue {
public:
    ElemType data[MAXSIZE];
    int front;
    int rear;
};

//���еĳ�ʼ��
void InitQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = 0;
}

//�ж϶����Ƿ�Ϊ��(���ж϶��е�front��rear�Ƿ���ȣ��������˵������Ϊ��)
bool IsitEmpty(Queue* queue) {
    if (queue->front == queue->rear) {
        return true;
    }
    return false;
}

//���Ӳ���
ElemType DeQueue(Queue* queue) {
    if (IsitEmpty(queue)) {
        std::cout<<"�˶���Ϊ��";
        return 0;
    }
    ElemType e = queue->data[queue->front];
    queue->front++;
    return e;
}

//��β���ˣ�����λ��
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
        std::cout<<"�������";
        return 0;
    }
}

//��ȡ��ͷ����
int GetHead(Queue* queue, ElemType *e) {
    if (IsitEmpty(queue)) {
        std::cout<<"����Ϊ�գ�";
        return 0;
    }
    *e = queue->data[queue->front];
    return 1;
}

//��Ӳ���
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