#include<iostream>
using namespace std;


//函数的分文件编写

//1、创建.h头文件
//2、创建.cpp源文件
//3、在头文件中声明函数
//4、在源文件中定义函数
//示例：完全平方函数squre

#include "squre.h"
//使用包含squre函数的头文件


//函数的定义
//n1,n2称为形参
//也可定义无参函数
int max(int n1,int n2)
{
	int temp;
	if (n1 >= n2) {
		temp = n1;
	}
	else
	{
		temp = n2;
	}
	
	return temp;
}

//无返回值函数
void swap(int n1, int n2)
{
	cout << "形参交换前：\n";
	cout << n1 <<"\t" << n2 << endl;
	int temp = n1;
	n1 = n2;
	n2 = temp;
	cout << "形参交换后：\n";
	cout << n1 << "\t" << n2 << endl;
	
	//无返回值函数可不需要return语句
	return;
}

//函数的声明
int min(int n1, int n2);
//函数定义即可置于main函数后
//函数声明可有数次，函数定义仅能存在一次

int main9()
{
	//函数的调用
	int a = 2;
	int b = 4;
	int m = max(a, b);
	//a,b称为实参
	cout << m << "\n\n";
	
	//值传递
	//实参将值传递给形参，形参发生改变不影响原实参
	swap(a, b);
	cout << "函数运行后实参的值：\n";
	cout << a << "\t" << b << endl;
	cout << "\n";

	//使用squre函数
	int sn = squre(a, b);
	cout << sn << "\n\n";


	system("pause");

	return 0;
}

int min(int n1, int n2)
{
	int temp;
	if (n1 <= n2) {
		temp = n1;
	}
	else
	{
		temp = n1;
	}

	return temp;
}