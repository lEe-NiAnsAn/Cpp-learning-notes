#include<iostream>
using namespace std;


//�����ķ��ļ���д

//1������.hͷ�ļ�
//2������.cppԴ�ļ�
//3����ͷ�ļ�����������
//4����Դ�ļ��ж��庯��
//ʾ������ȫƽ������squre

#include "squre.h"
//ʹ�ð���squre������ͷ�ļ�


//�����Ķ���
//n1,n2��Ϊ�β�
//Ҳ�ɶ����޲κ���
int max(int n1,int n2)
{
	int temp;
	if (n1 >= n2) {
		temp = n1;
	}
	else
	{
		temp = n2;
	}
	
	return temp;
}

//�޷���ֵ����
void swap(int n1, int n2)
{
	cout << "�βν���ǰ��\n";
	cout << n1 <<"\t" << n2 << endl;
	int temp = n1;
	n1 = n2;
	n2 = temp;
	cout << "�βν�����\n";
	cout << n1 << "\t" << n2 << endl;
	
	//�޷���ֵ�����ɲ���Ҫreturn���
	return;
}

//����������
int min(int n1, int n2);
//�������弴������main������
//���������������Σ�����������ܴ���һ��

int main9()
{
	//�����ĵ���
	int a = 2;
	int b = 4;
	int m = max(a, b);
	//a,b��Ϊʵ��
	cout << m << "\n\n";
	
	//ֵ����
	//ʵ�ν�ֵ���ݸ��βΣ��βη����ı䲻Ӱ��ԭʵ��
	swap(a, b);
	cout << "�������к�ʵ�ε�ֵ��\n";
	cout << a << "\t" << b << endl;
	cout << "\n";

	//ʹ��squre����
	int sn = squre(a, b);
	cout << sn << "\n\n";


	system("pause");

	return 0;
}

int min(int n1, int n2)
{
	int temp;
	if (n1 <= n2) {
		temp = n1;
	}
	else
	{
		temp = n1;
	}

	return temp;
}