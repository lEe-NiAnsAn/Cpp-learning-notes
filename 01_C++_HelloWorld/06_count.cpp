#include<iostream>
using namespace std;
#include<string>

int main6()
{
	int num1 = 10;
	int num2 = 2;
	#pragma region 算术运算符
	//加\正号
	int nums = num1 + num2;
	cout << "10+2=" << nums << endl;
	//减\负号
	int numd = num1 - num2;
	cout << "10-2=" << numd << endl;
	//乘
	int numm = num1 * num2;
	cout << "10*2=" << numm << endl;
	//除（整数间运算则为取整运算）
	int numv = num1 / num2;
	cout << "10/2=" << numv << endl;
	//模(小数不可取模）
	int numo = num1 % num2;
	cout << "10%2=" << numo << endl;

	cout << endl;

	//前置递增
	int sf1 = 1; 
	cout << "运算前sf1为" << sf1 << endl;
	int sf2 = 2;
	int sf = ++sf1 * sf2;
	cout << "++1 * 2 = " << sf << endl;
	cout << "运算后sf1为" << sf1 << endl;
	cout << endl;

	//后置递增
	int sa1 = 1;
	cout << "运算前sa1为" << sa1 << endl;
	int sa2 = 2;
	int sa = sa1++ * sa2;
	cout << "1++ * 2 = " << sa << endl;
	cout << "运算后sa1为" << sa1 << endl;
	cout << endl;

	//前置递减
	int df1 = 1; 
	cout << "运算前df1为" << df1 << endl;
	int df2 = 2;
	int df = --df1 * df2;
	cout << "--1 * 2 = " << df << endl;
	cout << "运算后df1为" << df1 << endl;
	cout << endl;

	//后置递减
	int da1 = 1; int da2 = 2;
	cout << "运算前da1为" << da1 << endl;
	int da = da1-- * da2;
	cout << "1-- * 2 = " << da << endl;
	cout << "运算后da1为" << da1 << endl;
	cout << endl;
	#pragma endregion


	#pragma region 赋值运算符
	//赋值
	int a = 2;
	cout << "a=" << a << endl;
	cout << endl;
	//加等于
	int nums0 = 10;
	cout << "nums0=" << nums0 << endl;
	nums0 += a;
	cout << "nums0 += a=" << nums0 << endl;
	cout << endl;
	//减等于
	int numd0 = 10;
	cout << "numd0=" << numd0 << endl;
	numd0 -= a;
	cout << "numd0 -= a = " << numd0 << endl;
	cout << endl;
	//乘等于
	int numm0 = 10;
	cout << "numm0=" << numm0 << endl;
	numm0 *= a;
	cout << "numm0 *= a = " << numm0 << endl;
	cout << endl;
	//除等于
	int numv0 = 10;
	cout << "numv0=" << numv0 << endl;
	numv0 /= a;
	cout << "numv0 /= a = " << numv0 << endl;
	cout << endl;
	//模等于
	int numo0 = 10;
	cout << "numo0=" << numo0 << endl;
	numo0 %= a;
	cout << "numo0 %= a = " << numo0 << endl;
	cout << endl;
	#pragma endregion


	#pragma region 比较运算符
	bool cb = true;
	//相等于
	cb = num1 == num2;
	cout << "10==2 的布尔值为" << cb << endl;
	//不等于
	cb = num1 != num2;
	cout << "10!=2 的布尔值为" << cb << endl;
	//小于
	cb = num1 < num2;
	cout << "10<2 的布尔值为" << cb << endl;
	//大于
	cb = num1 > num2;
	cout << "10>2 的布尔值为" << cb << endl;
	//小于等于
	cb = num1 <= num2;
	cout << "10<=2 的布尔值为" << cb << endl;
	//大于等于
	cb = num1 >= num2;
	cout << "10>=2 的布尔值为" << cb << endl;

	cout << endl;

	//C++风格的String可以比较
	string cs1 = "abc";
	string cs2 = "Abc";
	cout << "\"abc\">\"Abc\"的布尔值为" << (cs1 > cs2) << endl;
	cout << "\"abc\"<\"Abc\"的布尔值为" << (cs1 < cs2) << endl;
	cout << endl;
	#pragma endregion


	#pragma region 逻辑运算符
	bool lb1 = 1;
	bool lb2 = 0;
	//非
	cout << "“!真”的布尔值是" << !lb1 << endl;
	//与
	cout << "“真 && 假”的布尔值是" << (lb1 && lb2) << endl;
	//或
	cout << "“真 || 假”的布尔值是" << (lb1 || lb2) << endl;

	cout << endl;
	#pragma endregion


	system("pause");

	return 0;
}