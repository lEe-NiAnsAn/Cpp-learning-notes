#pragma once
#include <iostream>
using namespace std;
#include <string>


template<class T>
class cArr
{
private:
	T* pAddr;		//指向在堆区开辟的真实数组的指针
	int m_Capct;	//数组容量
	int m_Size;		//数组大小
public:
	//有参构造：数组容量
	cArr(int capct)
	{
		this->m_Capct = capct;
		this->m_Size = 0;
		this->pAddr = new T[this->m_Capct];	//在堆区创建一个类型为T、容量为capct的一个数组，并使用指针维护
		
	}
	//拷贝构造：防止浅拷贝
	cArr(const cArr& arr)
	{
		this->m_Capct = arr.m_Capct;
		this->m_Size = arr.m_Size;
		//深拷贝
		this->pAddr = new T[arr.m_Capct];	//在堆区新开辟内存防止指针重复释放
		//拷贝真实数组中的数据
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddr[i] = arr.pAddr[i];
		}
	}
	//重载赋值运算符“=”：防止浅拷贝
	cArr& operator=(const cArr& arr)
	{
		//释放原有堆区数据后进行拷贝
		if (this->pAddr != NULL)
		{
			delete[] this->pAddr;
			this->pAddr = NULL;
			this->m_Capct = 0;
			this->m_Size = 0;
		}
		this->m_Capct = arr.m_Capct;
		this->m_Size = arr.m_Size;
		this->pAddr = new T[arr.m_Capct];	
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddr[i] = arr.pAddr[i];
		}
		return *this;
	}
	//析构函数
	~cArr()
	{
		if (this->pAddr != NULL)
		{
			delete[] this->pAddr;
			this->pAddr = NULL;
		}
	}
	//尾插法增添数组数据
	void pushBk(const T& t)
	{
		//判断数组是否将会溢出
		if (this->m_Capct == this->m_Size)
		{
			cout << "扩大数组容量，否则继续填入数据将溢出！\n\n";
			return;
		}
		this->pAddr[this->m_Size] = t;
		this->m_Size++;
	}
	//尾删法减少数组数据
	void popBk()
	{
		//判断数组是否已经为空
		if (this->m_Size == 0)
		{
			cout << "数组已为空！\n\n";
			return;
		}
		//使得数组中最后以为数据无法通过接口访问
		this->m_Size--;
	}
	//重载“[]”运算符：提供通过下标访问数组元素接口
	T& operator[](int i)
	{
		return this->pAddr[i];
	}
	//提供返回数组容量接口
	int getCapct()
	{
		return this->m_Capct;
	}
	//提供返回数组大小接口
	int getSize()
	{
		return this->m_Size;
	}
};