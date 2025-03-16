#include<iostream>
#include"Log.h"


class SeqList
{
public:
	//数据
	ElemType* data;
	//顺序表的长度
	int length;
};

//顺序表的初始化
//void initlist(SeqList& list)
//{
//	list.length = 0;
//	std::cout<< "初始化成功！" << "表长为："  << list.length << std::endl;
//}

void initlist(SeqList& list)
{
	//list->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	list.data = new ElemType[MAXSIZE];
	list.length = 0;
}

//顺序表的添加操作
int add(SeqList& L, ElemType e)
{
	//首先判断顺序表的空间是否满了
	if (L.length >= MAXSIZE)
	{
		std::cout << "此顺序表已满" << std::endl;
		return FALSE;
	}
	L.data[L.length] = e;
	L.length++;
	return TRUE;
}

//顺序表的遍历
void ListElem(SeqList& list)
{
	for (int i = 0; i < list.length; i++)
	{
		std::cout << list.data[i] << " ";
	}
	std::cout << "\n";
}

//顺序表的插入操作
int insert(SeqList& list, int position, ElemType e)
{
	if (list.length >= MAXSIZE)
	{
		std::cout << "此表已经满了！" << std::endl;
		return 0;
	}

	if (position < 1 || position > list.length)
	{
		std::cout << "插入位置错误！" << std::endl;
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

//顺序表的删除操作
int DeleteElem(SeqList& list, int position, ElemType& e)
{
	if (position < 1 || position >= list.length)
	{
		std::cout << "删除的位置不合法！" << std::endl;
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

//顺序表的查找
int FindElem(SeqList& list, ElemType e)
{
	if (list.length == 0)
	{
		std::cout << "此列表为空！" << std::endl;
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
	std::cout << "被删除的元素为：" << deleted_data << std::endl;
	ListElem(list);
	std::cin.get();
}