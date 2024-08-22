#include<iostream>
using namespace std;


//C++中内存大致分为四区域：
//1、代码区：存放函数体二进制代码，由操作系统进行管理
//2、全局区（包括常量区）：存放全局变量、静态变量及常量（代码中数字、字符、const全局变量等常量）
//3、栈区：存放函数参数值、局部变量等，由编译器自动分配释放（const修饰的局部变量位于栈区）
//4、堆区：主动分配和释放，若不主动释放，则在程序结束时由系统回收
//不同区域存放不同数据，赋予不同生命周期

//全局变量
int g_a = 11;
int g_b = 12;

//const修饰的全局变量
const int c_g_a = 20;
const int c_g_b = 21;

int* wrong_func()
{
	int l_a = 1;	//局部变量
	return &l_a;	//返回局部变量地址
}

int* func()
{
	//利用new关键字将数据开辟至堆区
	int* p = new int(10);	//new的返回值为数据地址
	//p仍为局部变量，但其指向的地址为堆区数据
	return p;
}

void arr_func(int i)
{
	int* arr = new int[i];		//返回一个含有i个元素的数组的首地址
	//初始化数组
	for (int j = 0; j < i; j++) {
		arr[j] = j;
	}
	//遍历数组
	for (int j = 0; j < i; j++) {
		cout << arr[j] << "\t";
	}
	cout << "\n\n";

	delete[] arr;		//释放内存(注意[]）
	return;
}


int main1()
{
//程序运行前：
#pragma  region 代码区
	cout<< "\t代码区\n"
		<< "代码区于.exe等可执行程序运行前分配\n"
		<< "存放CPU执行的机器指令\n"
		<< "共享：频繁执行的程序共享内存中的一份代码\n"
		<< "只读：避免程序意外修改指令\n\n";
#pragma endregion

#pragma region 全局区
	cout << "\t全局区\n"
		<< "全局区亦于程序运行前分配\n"
		<< "存放全局变量、静态变量\n"
		<< "包含常量区，存放字符串常量和其他常量\n"
		<< "该区数据于程序结束后由操作系统释放\n"
		<< "共享、只读\n\n";

	//局部变量
	//不位于全局区
	int a = 10;
	int b = 9;

	//静态变量
	static int s_a = 8;
	static int s_b = 7;

	//常量
	//字符串常量，如"hello"
	//const修饰的变量
	//1、const修饰的全局变量
	//2、const修饰的局部变量
	const int c_a = 22;
	const int c_b = 23;

	cout << "\t局部变量a的地址为" << (int)&a << "\n"
		<< "\t局部变量b的地址为" << (int)&b << "\n"
		<< "\tconst局部变量c_a的地址为" << (int)&c_a << "\n"
		<< "\tconst局部变量c_b的地址为" << (int)&c_b << "\n\n"

		<< "\t静态变量s_a的地址为" << (int)&s_a << "\n"
		<< "\t静态变量s_b的地址为" << (int)&s_b << "\n"
		<< "\t全局变量g_a的地址为" << (int)&g_a << "\n"
		<< "\t全局变量g_b的地址为" << (int)&g_b << "\n"
		<< "\tconst全局变量c_g_a的地址为" << (int)&c_g_a << "\n"
		<< "\tconst全局变量c_g_b的地址为" << (int)&c_g_b << "\n"
		<< "\t字符串常量\"hello\"地址为" << (int)"hello" << "\n\n";
#pragma endregion

//程序运行后：
#pragma region 栈区
	cout << "\t栈区\n"
		<< "程序运行后分配\n"
		<< "由编译器自动分配释放，内存较小\n"
		<< "存放函数参数值、局部变量等\n\n"
		<< "注意事项：请勿返回局部变量地址，栈区开辟的数据应由编译器自动释放\n";

	int* p = wrong_func();	//接受局部变量地址返回值
	cout << *p << endl;		//运行函数后局部变量即被自动收回，但编译器为防止错误将保留一次
														//（视操作系统等不同或有其他次数)
	cout << *p << "\n\n";	//出现错误

#pragma endregion

#pragma region 堆区
	cout << "\t堆区\n"
		<< "程序运行后分配,结束未释放的内存系统自动释放\n"
		<< "人为主动分配，内存较大\n"
		<< "C++中主要利用new在堆区开辟内存\n\n";

	//堆区开辟内存
	int* p2 = func();
	cout << "解引用地址p的值为" << *p2 << "\n\n";

	//delete关键字在堆区释放内存
	delete p2;
	//非法：cout << *p2 << endl;

	//使用new在堆中创建数组并释放内存
	cout << "创建的数组为：\n";
	arr_func(3);

#pragma endregion

	system("pause");

	return 0;
}