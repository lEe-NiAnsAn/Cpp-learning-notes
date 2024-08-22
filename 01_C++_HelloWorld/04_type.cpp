#include<iostream>
using namespace std;
#include<string>

int main4()
{
	
	//使用“#pragma region 标识符 ...... #pragma endregion”折叠代码块时，“标识符”有所限制
	#pragma region 整形：
	//1、short（短整形 -2^15 至 2^15减一) 两字节
	short num1 = 10;
	cout << num1 << endl;
	//2、int（整形 -2^31 至 2^31减一）四字节
	int num2 = 20;
	cout << num2 << endl;
	//3、long（长整形 2^31 至 2^31减一）Windows中为四字节，Linux中为四字节(32位操作系统)、八字节(64位操作系统)
	long num3 = 30;
	cout << num3 << endl;
	//4、long long（长长整形 -2^63 至 2^63减一）八字节
	long long num4 = 40;
	cout << num4 << endl;

	cout << endl;
	#pragma endregion


	#pragma region 实型（浮点型）
	// 1、单精度float（7位有效数字）四字节（小数后缀“f”）
	float f1 = 3.14f;
	cout << "三位有效数字的圆周率是" << f1 << endl;
	// 2、双精度double（15至16位有效数字）八字节（小数无后缀默认为双精度小数）
	double d1 = 3.1415926;
	cout << "九位有效数字的圆周率是" << d1 << endl;
	//默认输出只显示六位有效数字

	//科学计数法
	float f2 = 3e-3;//3 * 10 ^ -3
	float f3 = 2e2;//2 * 10 ^ 2
	cout << "f2=" << f2 << ", f3=" << f3 << endl;

	cout << endl;
	#pragma endregion


	#pragma region 字符型
	//用于显示单个字符（一字节）
	//只能用单引号
	//存储字符的ASCII码而不是字符本身
	char ch1 = 'a';
	cout << "英语字母表的第一个字母是" << ch1 << endl;
	//查看字符的ASCII码
	cout << "a的ASCII码是" << (int)ch1 << endl;
	char ch2 = 'A';
	cout << "A的ASCII码是" << (int)ch2 << endl;
	//ASCII表上 0 - 31 分配给了控制字符，32 - 126 分配给可查看的字符，127为DEL

	cout << endl;
	#pragma endregion


	#pragma region 转义字符
	/*
	"\a" 警报			"\b" 退格			"\f" 换页			"\n" 换行			"\r" 回车	
	"\t" 水平制表		"\v" 垂直制表		"\\" 反斜杠			"\'" 单引号			"\"" 双引号
	"\?" 问号			"\0" 空字符（NULL）		
	"\dddd" 1到3位八进制数所代表的任意字符
	"\xhh"  1到2位十六进制所代表的任意字符
	*/
	cout << "aaaa\taaaa\taaaa\taaaa\naaa\taaa\taaa\naa\taa\na\n";

	cout << endl;
	#pragma endregion


	#pragma region 字符串型
	//1、C风格
	char str1[] = "Lee";
	cout << "姓氏为" << str1 << endl;
	//2、C++风格(需要头文件 #include<string> )（不过现在好像也不一定要。。。
	string str2 = "Niansan";
	cout << "名字为" << str2 << endl;
	//3、字符串拼接
	str2 += str2[0];
	cout << str2 << endl;

	cout << endl;
	#pragma endregion

	
	#pragma region 布尔类型（一字节）
	bool flag1 = true;
	bool flag0 = false;
	cout << flag1 << endl;//(输出1)
	cout << flag0 << endl;//(输出0)
	//非0即为真，是0即为假
	//非数字亦为假

	cout << endl;
	#pragma endregion

	
	#pragma region 统计数据类型所占内存大小 sizeof()
	cout << "short类型所占用的内存大小为" << sizeof(short) << endl;
	cout << "f2所占用的内存大小为" << sizeof(f2) << endl;
	cout << "char类型所占用的内存大小为" << sizeof(char) << endl;
	cout << "str1所占用的内存大小为" << sizeof(str1) << endl;

	cout << endl;
	#pragma endregion


	
	system("pause");

	return 0;
}