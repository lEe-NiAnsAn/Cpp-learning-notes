#include<iostream>
using namespace std;

//以解引用的指针为形参进行地址传递
void swap(int* p1,int* p2) 
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;

	return;
}

//冒泡排序函数
void bublle(int* arr, int len)		//参数一：数组首地址		参数二：数组长度
{
	for (int j = 0; j < len - 1; j++) {
		for (int i = 0; i < len - 1 - j; i++) {
			if (arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}

	return;
}


//打印数组函数
void printArr(int* arr, int len)
{
	cout << "数组为：\n";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << "\t";
	}
	cout << "\n\n";

	return;
}

int main10()
{
#pragma region 定义指针
	int a = 10;
	//定义关于变量a的指针
	int* p_a = &a;
	//此时指针并非为int十进制，而为十六进制
	cout << "变量a的地址为" << &a << "\n" << "指针p_a的值为" << p_a << endl;
	
	cout << endl;
#pragma endregion

#pragma region 使用指针
	//使用解引用方式(* )查找指针指向的内存地址
	* p_a = 1000;
	cout << "变量a的值为" << a << "\n" << "解引用指针(* p_a)为" << * p_a << endl;
	
	cout << endl;
#pragma endregion

#pragma region 指针所占内存空间
	//不同操作系统下指针所占内存空间不同
	//32位为四字节	64位为八字节
	cout << "int指针所占内存空间为" << sizeof(int* ) << "\n";
	cout << "short指针所占内存空间为" << sizeof(short* ) << "\n";
	cout << "double指针所占内存空间为" << sizeof(double* ) << "\n\n";

#pragma endregion

#pragma region 空指针与野指针
	//空指针 指向内存编号为0的空间
	//用于初始化指针，不可访问其指向的内存
	//错误初始化：int* p = 100；	//0~255内存编号为系统占用，不可访问
	int* p0 = NULL;
	//错误访问：cout << *p0 << endl;

	//野指针 指向非法内存空间
	//例如：int* p_error = (int* )0x1100;
	//野指针操作十分危险！！！不可访问！

#pragma endregion

#pragma region const修饰指针
	a = 1;
	int b = 1;
	int c = 2;
	int d = 3;
	//const修饰指针：常量指针
	const int* p1 = &a;
	p1 = &b;	//非法：*p1 = 4;
	//指针指向可修改，而指向的值不可修改


	//const修饰常量：指针常量
	int* const p2 = &c;
	cout << "修改前解引用值为" << *p2 << "\n";
	*p2 = 5;	//非法：p2 = &a;
	cout << "修改后解引用值为" << *p2 << "\n\n";
	//指针指向不可修改，而指向的值可修改

	
	//const既修饰指针，又修饰常量
	const int* const p3 = &d;
	//指针指向与指向的值均不可修改

#pragma endregion

#pragma region 指针与数组
	int arr1[5] = { 1,2,3,4,5 };
	int l = sizeof(arr1) / sizeof(arr1[0]);
	int* p_arr1 = arr1;//arr1数组名的首地址即为首个元素的首地址
	cout << "利用指针访问数组" << endl;
	for (int i = 0; i < l; i++) {
		cout << "第" << i + 1 << "个元素是" << *p_arr1 << endl;
		p_arr1++;//使指针向后偏移一内存单位（四字节）
	}

	cout << endl;
#pragma endregion

#pragma region 指针与函数
	//地址传递：调用函数不仅改变形参，也改变实参
	cout << "函数运行前实参的值：\n" << c << "\t" << d << endl;
	swap(&c, &d);//传入实参地址
	cout << "函数运行后实参的值：\n" << c << "\t" << d << endl;

	cout << endl;
#pragma endregion

#pragma region 冒泡排序函数
	int arr2[9] = { 3,1,4,1,5,9,2,6 };
	int len_arr2 = sizeof(arr2) / sizeof(arr2[0]);
	bublle(arr2, len_arr2);		//数组名arr2即为数组首地址
	printArr(arr2, len_arr2);

#pragma endregion


	system("pause");

	return 0;
}