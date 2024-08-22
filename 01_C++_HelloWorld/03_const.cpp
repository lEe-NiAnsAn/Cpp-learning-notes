#include<iostream>

using namespace std;

//宏常量，定义在main方法外
#define Day 7

int main3()
{
	//如果在这里写“Day = 14”则会报错，常量不可修改
	cout << "一周一共有" << Day << "天" << endl;
	
	//const修饰的变量,亦为常量,直接定义在main方法内
	const int month = 12;
	//不可修改 month = 24；
	cout << "一年一共有" << month << "个月" << endl;



	system("pause");

	return 0;
}