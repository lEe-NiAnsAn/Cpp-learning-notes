#include<iostream>
using namespace std;
#include<string>

int main4()
{
	
	//ʹ�á�#pragma region ��ʶ�� ...... #pragma endregion���۵������ʱ������ʶ������������
	#pragma region ���Σ�
	//1��short�������� -2^15 �� 2^15��һ) ���ֽ�
	short num1 = 10;
	cout << num1 << endl;
	//2��int������ -2^31 �� 2^31��һ�����ֽ�
	int num2 = 20;
	cout << num2 << endl;
	//3��long�������� 2^31 �� 2^31��һ��Windows��Ϊ���ֽڣ�Linux��Ϊ���ֽ�(32λ����ϵͳ)�����ֽ�(64λ����ϵͳ)
	long num3 = 30;
	cout << num3 << endl;
	//4��long long���������� -2^63 �� 2^63��һ�����ֽ�
	long long num4 = 40;
	cout << num4 << endl;

	cout << endl;
	#pragma endregion


	#pragma region ʵ�ͣ������ͣ�
	// 1��������float��7λ��Ч���֣����ֽڣ�С����׺��f����
	float f1 = 3.14f;
	cout << "��λ��Ч���ֵ�Բ������" << f1 << endl;
	// 2��˫����double��15��16λ��Ч���֣����ֽڣ�С���޺�׺Ĭ��Ϊ˫����С����
	double d1 = 3.1415926;
	cout << "��λ��Ч���ֵ�Բ������" << d1 << endl;
	//Ĭ�����ֻ��ʾ��λ��Ч����

	//��ѧ������
	float f2 = 3e-3;//3 * 10 ^ -3
	float f3 = 2e2;//2 * 10 ^ 2
	cout << "f2=" << f2 << ", f3=" << f3 << endl;

	cout << endl;
	#pragma endregion


	#pragma region �ַ���
	//������ʾ�����ַ���һ�ֽڣ�
	//ֻ���õ�����
	//�洢�ַ���ASCII��������ַ�����
	char ch1 = 'a';
	cout << "Ӣ����ĸ��ĵ�һ����ĸ��" << ch1 << endl;
	//�鿴�ַ���ASCII��
	cout << "a��ASCII����" << (int)ch1 << endl;
	char ch2 = 'A';
	cout << "A��ASCII����" << (int)ch2 << endl;
	//ASCII���� 0 - 31 ������˿����ַ���32 - 126 ������ɲ鿴���ַ���127ΪDEL

	cout << endl;
	#pragma endregion


	#pragma region ת���ַ�
	/*
	"\a" ����			"\b" �˸�			"\f" ��ҳ			"\n" ����			"\r" �س�	
	"\t" ˮƽ�Ʊ�		"\v" ��ֱ�Ʊ�		"\\" ��б��			"\'" ������			"\"" ˫����
	"\?" �ʺ�			"\0" ���ַ���NULL��		
	"\dddd" 1��3λ�˽�����������������ַ�
	"\xhh"  1��2λʮ������������������ַ�
	*/
	cout << "aaaa\taaaa\taaaa\taaaa\naaa\taaa\taaa\naa\taa\na\n";

	cout << endl;
	#pragma endregion


	#pragma region �ַ�����
	//1��C���
	char str1[] = "Lee";
	cout << "����Ϊ" << str1 << endl;
	//2��C++���(��Ҫͷ�ļ� #include<string> )���������ں���Ҳ��һ��Ҫ������
	string str2 = "Niansan";
	cout << "����Ϊ" << str2 << endl;
	//3���ַ���ƴ��
	str2 += str2[0];
	cout << str2 << endl;

	cout << endl;
	#pragma endregion

	
	#pragma region �������ͣ�һ�ֽڣ�
	bool flag1 = true;
	bool flag0 = false;
	cout << flag1 << endl;//(���1)
	cout << flag0 << endl;//(���0)
	//��0��Ϊ�棬��0��Ϊ��
	//��������Ϊ��

	cout << endl;
	#pragma endregion

	
	#pragma region ͳ������������ռ�ڴ��С sizeof()
	cout << "short������ռ�õ��ڴ��СΪ" << sizeof(short) << endl;
	cout << "f2��ռ�õ��ڴ��СΪ" << sizeof(f2) << endl;
	cout << "char������ռ�õ��ڴ��СΪ" << sizeof(char) << endl;
	cout << "str1��ռ�õ��ڴ��СΪ" << sizeof(str1) << endl;

	cout << endl;
	#pragma endregion


	
	system("pause");

	return 0;
}