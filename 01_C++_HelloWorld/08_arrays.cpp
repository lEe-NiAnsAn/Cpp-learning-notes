#include<iostream>
using namespace std;

int main8()
{
#pragma region 一维数组
	//声明、初始化
	// 方法一
	int arr1[3];
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 3;
	//方法二
	int arr2[4] = { 1,2,3,4 };
	//若数据为完全填充，则以0来填补
	//方法三
	int arr3[] = { 1,2,3,4,5 };

	//数组可视为常量，无法修改;而数组元素支持修改
	//访问数组元素
	cout << "arr3的内容为：\n";
	int arr3_length = sizeof(arr3) / sizeof(arr3[0]);
	//通过数组所占的总内存除以数组数据类型所占内存得到数组长度
	for (int i = 0; i < arr3_length; i++) {
		cout << arr3[i] << "\t";
	}
	cout << "\n\n";

	//获取首地址
	cout << "arr3的内存首地址是" << (int)arr3 << endl;
	//使用(int)将十六进制转化为十进制
	//首元素的首地址与数组的首地址相同
	cout << "arr3第二个元素的首地址" << (int)&arr3[1] << endl;
	//每一元素首地址相隔一个数据内存单位(该示例为4）
	cout << "\n\n";
#pragma endregion

#pragma region 冒泡排序
	int arr4[] = { 3,1,4,1,5,9,2,6, };
	int arr4_length = sizeof(arr4) / sizeof(arr4[0]);
	cout << "排序前数组为：\n";
	for (int i = 0; i < arr4_length; i++) {
		cout << arr4[i] << "\t";
	}
	cout << endl;
	//冒泡升序循环
	for (int j = 0; j < arr4_length - 1; j++) {
		for (int i = 0; i < arr4_length - 1 - j; i++) {
			if (arr4[i] > arr4[i + 1]) {
				int temp = arr4[i + 1];
				arr4[i + 1] = arr4[i];
				arr4[i] = temp;
			}
		}
	}
	cout << "排序后数组为：\n";
	for (int i = 0; i < arr4_length; i++) {
		cout << arr4[i] << "\t";
	}
	cout << "\n\n";

	#pragma endregion

#pragma region 二维数组 
	//声明、初始化方法
	//方法一
	int arr1_td[2][3];
	int a = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			arr1_td[i][j] = ++a;
		}
	}
	
	//方法二
	int arr2_td[2][3] = {
		{6,5,4},
		{3,2,1}
	};

	//方法三
	//初始化长度后将自动分割
	int arr3_td[2][3] = { 3,1,4,1,5,9 };

	//方法四
	//仅可省略行数
	int arr4_td[][3] = {2,3,0,3,1,6};
	//下面的方式同样合法
	//int arr4_td[][3] = {
	//	{2,3,0},
	//	{3,1,6}
	//};						


	//访问数组内容
	cout << "arr4_td的内容为：\n";
	//获取行数
	int arr4_rows = sizeof(arr4_td) / sizeof(arr4_td[0]);
	//获取列数
	int arr4_colms = sizeof(arr4_td[0]) / sizeof(arr4_td[0][0]);
	//输出循环
	for (int i = 0; i < arr4_rows; i++) {
		for (int j = 0; j < arr4_colms; j++) {
			cout << arr4_td[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";


	//首地址
	cout << "arr4_td的首地址为" << arr4_td << endl;
	//数组第一行的首地址与数组首地址相同
	cout << "arr4_td第二行的首地址为" << arr4_td[1] << endl;
	//数组第一行第一列的首地址与数组首地址也相同
	cout << "arr4_td第二行第三列的首地址为" << &arr4_td[1][2] << endl;
	cout << "\n";
#pragma endregion


	system("pause");

	return 0;
}