#include<iostream>
using namespace std;

int main5()
{
	//从键盘上获取数据
	int i = 0;
	cout << "请输入一个整数" << endl;
	cin >> i;
	cout << "你输入的整数是" << i << endl;

	cout << endl;

	char s[] = "默认字符串";
	cout << "请输入一串字符串" << endl;
	cin >> s;
	cout << "你输入的字符串是" << s << endl;
	
	cout << endl;

	bool flag = false;
	cout << "请为一个布尔值输入一个值" << endl;
	cin >> flag;
	cout << "你输入的数据的布尔值是" << flag << endl;

	cout << endl;


	system("pause");

	return 0;
}