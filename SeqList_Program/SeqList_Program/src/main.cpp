#include<iostream>
#include"Log.h"


class SeqList
{
public:
	//����
	ElemType* data;
	//˳���ĳ���
	int length;
};

//˳���ĳ�ʼ��
//void initlist(SeqList& list)
//{
//	list.length = 0;
//	std::cout<< "��ʼ���ɹ���" << "��Ϊ��"  << list.length << std::endl;
//}

void initlist(SeqList& list)
{
	//list->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	list.data = new ElemType[MAXSIZE];
	list.length = 0;
}

//˳������Ӳ���
int add(SeqList& L, ElemType e)
{
	//�����ж�˳���Ŀռ��Ƿ�����
	if (L.length >= MAXSIZE)
	{
		std::cout << "��˳�������" << std::endl;
		return FALSE;
	}
	L.data[L.length] = e;
	L.length++;
	return TRUE;
}

//˳���ı���
void ListElem(SeqList& list)
{
	for (int i = 0; i < list.length; i++)
	{
		std::cout << list.data[i] << " ";
	}
	std::cout << "\n";
}

//˳���Ĳ������
int insert(SeqList& list, int position, ElemType e)
{
	if (list.length >= MAXSIZE)
	{
		std::cout << "�˱��Ѿ����ˣ�" << std::endl;
		return 0;
	}

	if (position < 1 || position > list.length)
	{
		std::cout << "����λ�ô���" << std::endl;
		return 0;
	}

	if (position <= list.length)
	{
		for (int i = list.length-1; i >= position -1; i--)
		{
			list.data[i + 1] = list.data[i];
		}
		list.data[position - 1] = e;
		list.length++;
	}
	return 1;
 }

//˳����ɾ������
int DeleteElem(SeqList& list, int position, ElemType& e)
{
	if (position < 1 || position >= list.length)
	{
		std::cout << "ɾ����λ�ò��Ϸ���" << std::endl;
		return 0;
	}
	e = list.data[position - 1];
	if (position < list.length)
	{
		for (int i = position; i < list.length; i++)
		{
			list.data[i - 1] = list.data[i];
		}
		list.length--;
	}
	return 1;
}

//˳���Ĳ���
int FindElem(SeqList& list, ElemType e)
{
	if (list.length == 0)
	{
		std::cout << "���б�Ϊ�գ�" << std::endl;
		return 0;
	}

	for (int i = 0; i < list.length; i++)
	{
		if (e == list.data[i - 1])
			return i + 1;
	}

	return 0;

}

int main() {
	SeqList list;
	initlist(list);
	//initlist(&list);

	add(list, 2);
	add(list, 5);
	ListElem(list);
	insert(list, 1, 10);
	std::cout << "-------------" << std::endl;
	ListElem(list);
	ElemType deleted_data;
	DeleteElem(list, 1, deleted_data);
	std::cout << "��ɾ����Ԫ��Ϊ��" << deleted_data << std::endl;
	ListElem(list);
	std::cin.get();
}