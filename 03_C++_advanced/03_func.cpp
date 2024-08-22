#include<iostream>
using namespace std;

#pragma region 函数默认参数
//定义函数时可设置形参默认参数
//注意：	1、设置默认参数后，其后所有形参均需设置
//		2、当函数声明与实现分别编写时，声明中已设置默认参数，则实现中不可再次设置默认参数
int three_plus(int n1 = 0, int n2 = 0, int n3 = 0)
{
	return	n1 + n2 + n3;
}
#pragma endregion

#pragma region 函数占位参数
//设置占位参数后调用函数时则必须填补该位
//占位参数亦可设置默认值,此时便不必填补
//可用于函数的重载等
void show(int = 0)
{
	cout << "Hello World !!!\n\n";
}
#pragma endregion

#pragma region 函数重载
//使得函数名可以相同而参数不同(类型/数量/顺序)，以实现不同的功能
//注意：	1、需在同一作用域下
//		2、函数仅返回类型不同不可重载
void show(string a )
{
	cout << "Hello " << a << " !!!\n\n";
}
//引用作为函数重载条件注意事项：	1、引用与常量引用属于类型不同，传入常量即调用参数为常量引用的函数
//								2、若默认参数导致重载函数在实参传递形参时出现二义性，则无法正常调用函数
#pragma endregion


int main3()
{
	//一/二/三数相加函数
	cout << three_plus(1, 2) << "\n\n";
	//显示文本函数
	show();
	//重载显示文本函数
	show("C++");


	system("pause");

	return 0;
}