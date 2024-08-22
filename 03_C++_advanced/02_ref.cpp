#include<iostream>
using namespace std;

//引用传递函数
void r_swap(int& n1, int& n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;

	return;
}

//引用错误返回
int& wrong_return()
{
	int a = 10;

	return a;
}

//通过静态变量返回引用
int& left_return()
{
	static int a = 10;		//静态变量位于全局区，异于栈区

	return a;
}

//常量引用修饰形参，防止误操作
void constshow(const int& num)
{
	//非法：num++;	//防止误操作
	cout << num << endl;

	return;
}

int main2()
{
	//引用即为变量定义“别名”
	//引用必须初始化
	int a = 1;
	int& r_a = a;
	cout << "r_a = a = " << r_a << "\n\n";
	//初始化后不可修改引用指向，但可重新赋值
	r_a = 2;
	cout << "修改r_a后，r_a = a = " << r_a << "\n\n";

	//引用的本质为C++内部实现的指针常量
	//int& r_a = a; ——>自动转化为 int* const r_a = &a;
	//r_a = 2; ——>内部识别r_a为引用，自动转化为 *r_a = 2;
	//此过程并不会开辟新的指针内存空间

	//以引用作为函数参数
	//使得形参可修饰实参
	int b = 0;
	cout << "交换前：\n" << a << "\t" << b << endl;
	r_swap(a, b);
	cout << "交换后：\n" << a << "\t" << b << "\n\n";

	//注意：请勿返回局部变量的引用
	int& wrong_ref = wrong_return();
	cout << wrong_ref << endl;		//编译器自动保留一次内存数据
	cout << wrong_ref << "\n\n";	//发生错误

	//函数调用可作为左值
	int& left_ref = left_return();
	cout << left_ref << endl;
	cout << left_ref << "\n\n";		//成功返回函数调用

	left_return() = 100;
	cout << "函数作为左值重新赋值后：\n" << left_ref << "\n\n";//通过函数返回值的引用更改left_ref

	//常量引用
	const int& c_r = 18;
	//非法：int& r = 18;		//引用不可直接指向无权限修改的常量等非法内存空间
	constshow(a);

	system("pause");

	return 0;
}