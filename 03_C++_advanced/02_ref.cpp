#include<iostream>
using namespace std;

//���ô��ݺ���
void r_swap(int& n1, int& n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;

	return;
}

//���ô��󷵻�
int& wrong_return()
{
	int a = 10;

	return a;
}

//ͨ����̬������������
int& left_return()
{
	static int a = 10;		//��̬����λ��ȫ����������ջ��

	return a;
}

//�������������βΣ���ֹ�����
void constshow(const int& num)
{
	//�Ƿ���num++;	//��ֹ�����
	cout << num << endl;

	return;
}

int main2()
{
	//���ü�Ϊ�������塰������
	//���ñ����ʼ��
	int a = 1;
	int& r_a = a;
	cout << "r_a = a = " << r_a << "\n\n";
	//��ʼ���󲻿��޸�����ָ�򣬵������¸�ֵ
	r_a = 2;
	cout << "�޸�r_a��r_a = a = " << r_a << "\n\n";

	//���õı���ΪC++�ڲ�ʵ�ֵ�ָ�볣��
	//int& r_a = a; ����>�Զ�ת��Ϊ int* const r_a = &a;
	//r_a = 2; ����>�ڲ�ʶ��r_aΪ���ã��Զ�ת��Ϊ *r_a = 2;
	//�˹��̲����Ὺ���µ�ָ���ڴ�ռ�

	//��������Ϊ��������
	//ʹ���βο�����ʵ��
	int b = 0;
	cout << "����ǰ��\n" << a << "\t" << b << endl;
	r_swap(a, b);
	cout << "������\n" << a << "\t" << b << "\n\n";

	//ע�⣺���𷵻ؾֲ�����������
	int& wrong_ref = wrong_return();
	cout << wrong_ref << endl;		//�������Զ�����һ���ڴ�����
	cout << wrong_ref << "\n\n";	//��������

	//�������ÿ���Ϊ��ֵ
	int& left_ref = left_return();
	cout << left_ref << endl;
	cout << left_ref << "\n\n";		//�ɹ����غ�������

	left_return() = 100;
	cout << "������Ϊ��ֵ���¸�ֵ��\n" << left_ref << "\n\n";//ͨ����������ֵ�����ø���left_ref

	//��������
	const int& c_r = 18;
	//�Ƿ���int& r = 18;		//���ò���ֱ��ָ����Ȩ���޸ĵĳ����ȷǷ��ڴ�ռ�
	constshow(a);

	system("pause");

	return 0;
}