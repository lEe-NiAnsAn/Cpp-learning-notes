#include <iostream>
using namespace std;
#include "cArr.hpp"


void test1()
{
	cArr<int> arr1(5);		//有参构造
	cArr<int> arr2(arr1);	//拷贝构造
	cArr<int> arr3(1);		
	arr2 = arr3;			//= 号重载
	for (int i = 1; i < 6; i++)
	{
		arr1.pushBk(i);		//尾插法
	}
	arr1.popBk();			//尾删法
	for (int i = 0; i < 5; i++)
	{
		cout << arr1[i] << endl;		//[]号重载
	}
	cout << arr1.getCapct() << "  ";	//返回数组容量
	cout << arr1.getSize() << endl;		//返回数组大小
}
class cPerson
{
public:
	cPerson()
	{
		this->m_name = "name";
		this->m_age = 18;
	}
	cPerson(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
	void pshow()
	{
		cout << "name：" << this->m_name << "  age：" << this->m_age << endl;
	}
};
void test2()
{
	cArr<cPerson> arr1(5);		//有参构造
	cArr<cPerson> arr2(arr1);	//拷贝构造
	cArr<cPerson> arr3(1);
	arr2 = arr3;				//= 号重载
	for (int i = 1; i < 6; i++)
	{
		cPerson pi("N", i);
		arr1.pushBk(pi);		//尾插法
	}
	arr1.popBk();				//尾删法
	for (int i = 0; i < arr1.getSize(); i++)
	{
		arr1[i].pshow();			//[]号重载
	}
	cout << arr1.getCapct() << "  ";	//返回数组容量
	cout << arr1.getSize() << endl;		//返回数组大小
}
int main2()
{
	test1();
	test2();


	system("pause");


	return 0;
}