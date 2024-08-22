#include<iostream>
using namespace std;
#include<string>
//文件操作需要包含头文件
#include<fstream>
//使得临时数据不将在程序结束时被自动释放，而通过文件存储实现持久化
//1、文本文件：以文本的ASCII码形式存储
//2、二进制文件：以文本的二进制形式存储
#pragma region 操作文件的三大方法
	//ios::in——>为读文件而打开
	//ios::out——>为写文件而打开
	//ios::ate——>初始位置：文件尾
	//ios::app——>追加方式写文件
	//ios::trunc——>若文件存在，则删除后创建
	//ios::binary——>二进制方式
	//注意：文件打开方式可配合使用，利用“|”操作符
	#pragma region 一 ofstream:写操作
//文本文件
void test21()
{
	//1、包含头文件：include<fstream>
	//2、创建流对象：
	ofstream ofs;//或使用 fstream ofs;
	//3、指定打开方式：(绝对/相对)打开路径(包括文件名)、打开方式
	//若未指定路径(仅填入文件名)，则默认为在.cpp同文件夹内
	ofs.open("test21.txt", ios::out);
	//4、写数据
	ofs << "test21写入的数据" << endl;
	ofs << "数据一" << endl;
	ofs << "数据二" << endl;
	ofs << "数据三" << endl;
	//5、关闭文件
	ofs.close();
}
//二进制文件
class Btext
{
public:
	int m_i;
	char m_c[64];	//使用string可能在调用其二进制文件时报错
};
void test22()
{
	//1、包含头文件：include<fstream>
	//2、创建流对象 + 指定打开方式	
	ofstream ofs("test22.txt", ios::out | ios::binary);
	//3、写数据
	Btext b = { 10,"abc" };
	//输出文件流对象.write((const char*)&目标对象,目标长度);
	//必须强转为char*型地址,二进制数据需使用char类型
	ofs.write((const char*)&b,sizeof(Btext));
	//4、关闭文件
	ofs.close();
}
	#pragma endregion 

	#pragma region 二 ifstream:读操作
//文本文件
void test21_1()
{
	//1、包含头文件：include<fstream>
	//2、创建流对象：
	ifstream ifs;//或使用 fstream ifs;
	//3、打开文件并判断能否打开
	ifs.open("test21.txt", ios::in);
	if (!ifs.is_open()) {	//若未成功打开
		cout << "文件打开失败" << endl;

		return;
	}
	//4、读数据
	//方法一：通过右移运算符逐词读取至字符列表
	char buf1[1024] = { 0 };	//声明并初始化字符串列表
	while (ifs >> buf1) {		//读取至文件尾自动返回false
		cout << buf1 << endl;	//显示读取数据
	}

	//方法二：通过输入文件流类内置getline成员函数逐行读取至字符列表
	//char buf2[1024] = { 0 };
	//while (ifs.getline(buf2,sizeof(buf2))) {	//达到最大长度自动返回false
	////对象.getline(字符列表,最大读取长度)
	//	cout << buf2 << endl;
	//}

	//方法三：通过全局函数getline逐行读取至字符串
	//string buf3;
	////需包含头文件#include<string>
	//while (getline(ifs,buf3))	//读取至文件尾自动返回false
	////getline(输入文件流对象,目标字符串)
	//{
	//	cout << buf3 << endl;
	//}

	//方法四：通过输入文件流类内置get成员函数逐字符读取至字符变量
	//char c;
	//while ((c = ifs.get()) != EOF) {	//EOF：end of file
	//	cout << c;
	//}

	//5、关闭文件
	ifs.close();
}
//二进制文件
void test22_1()
{
	//1、包含头文件：include<fstream>
	//2、创建流对象
	ifstream ifs;//或使用 fstream ifs;
	//3、打开文件并判断能否打开
	ifs.open("test22.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {	
		cout << "文件打开失败" << endl;

		return;
	}
	//4、读数据	//通过输入文件流类内置成员函数read读取二进制数据
	Btext br;	//读取数据为Btext，故创建该类对象存储读取值
	ifs.read((char*)&br, sizeof(Btext));
	cout << "test22的m_i为" << br.m_i << "\ttest22中的m_c为" << br.m_c << endl;
	//5、关闭文件
	ifs.close();
}
	#pragma endregion

	#pragma region 三 fstream:读写操作
//同ofstream与ifstream
	#pragma endregion
#pragma endregion

int main()
{
	test21();
	test21_1();
	cout << endl;
	test22();
	test22_1();
	cout << endl;



	system("pause");

	return 0;
}