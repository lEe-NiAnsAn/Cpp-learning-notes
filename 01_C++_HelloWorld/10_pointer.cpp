#include<iostream>
using namespace std;

//�Խ����õ�ָ��Ϊ�βν��е�ַ����
void swap(int* p1,int* p2) 
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;

	return;
}

//ð��������
void bublle(int* arr, int len)		//����һ�������׵�ַ		�����������鳤��
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


//��ӡ���麯��
void printArr(int* arr, int len)
{
	cout << "����Ϊ��\n";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << "\t";
	}
	cout << "\n\n";

	return;
}

int main10()
{
#pragma region ����ָ��
	int a = 10;
	//������ڱ���a��ָ��
	int* p_a = &a;
	//��ʱָ�벢��Ϊintʮ���ƣ���Ϊʮ������
	cout << "����a�ĵ�ַΪ" << &a << "\n" << "ָ��p_a��ֵΪ" << p_a << endl;
	
	cout << endl;
#pragma endregion

#pragma region ʹ��ָ��
	//ʹ�ý����÷�ʽ(* )����ָ��ָ����ڴ��ַ
	* p_a = 1000;
	cout << "����a��ֵΪ" << a << "\n" << "������ָ��(* p_a)Ϊ" << * p_a << endl;
	
	cout << endl;
#pragma endregion

#pragma region ָ����ռ�ڴ�ռ�
	//��ͬ����ϵͳ��ָ����ռ�ڴ�ռ䲻ͬ
	//32λΪ���ֽ�	64λΪ���ֽ�
	cout << "intָ����ռ�ڴ�ռ�Ϊ" << sizeof(int* ) << "\n";
	cout << "shortָ����ռ�ڴ�ռ�Ϊ" << sizeof(short* ) << "\n";
	cout << "doubleָ����ռ�ڴ�ռ�Ϊ" << sizeof(double* ) << "\n\n";

#pragma endregion

#pragma region ��ָ����Ұָ��
	//��ָ�� ָ���ڴ���Ϊ0�Ŀռ�
	//���ڳ�ʼ��ָ�룬���ɷ�����ָ����ڴ�
	//�����ʼ����int* p = 100��	//0~255�ڴ���Ϊϵͳռ�ã����ɷ���
	int* p0 = NULL;
	//������ʣ�cout << *p0 << endl;

	//Ұָ�� ָ��Ƿ��ڴ�ռ�
	//���磺int* p_error = (int* )0x1100;
	//Ұָ�����ʮ��Σ�գ��������ɷ��ʣ�

#pragma endregion

#pragma region const����ָ��
	a = 1;
	int b = 1;
	int c = 2;
	int d = 3;
	//const����ָ�룺����ָ��
	const int* p1 = &a;
	p1 = &b;	//�Ƿ���*p1 = 4;
	//ָ��ָ����޸ģ���ָ���ֵ�����޸�


	//const���γ�����ָ�볣��
	int* const p2 = &c;
	cout << "�޸�ǰ������ֵΪ" << *p2 << "\n";
	*p2 = 5;	//�Ƿ���p2 = &a;
	cout << "�޸ĺ������ֵΪ" << *p2 << "\n\n";
	//ָ��ָ�򲻿��޸ģ���ָ���ֵ���޸�

	
	//const������ָ�룬�����γ���
	const int* const p3 = &d;
	//ָ��ָ����ָ���ֵ�������޸�

#pragma endregion

#pragma region ָ��������
	int arr1[5] = { 1,2,3,4,5 };
	int l = sizeof(arr1) / sizeof(arr1[0]);
	int* p_arr1 = arr1;//arr1���������׵�ַ��Ϊ�׸�Ԫ�ص��׵�ַ
	cout << "����ָ���������" << endl;
	for (int i = 0; i < l; i++) {
		cout << "��" << i + 1 << "��Ԫ����" << *p_arr1 << endl;
		p_arr1++;//ʹָ�����ƫ��һ�ڴ浥λ�����ֽڣ�
	}

	cout << endl;
#pragma endregion

#pragma region ָ���뺯��
	//��ַ���ݣ����ú��������ı��βΣ�Ҳ�ı�ʵ��
	cout << "��������ǰʵ�ε�ֵ��\n" << c << "\t" << d << endl;
	swap(&c, &d);//����ʵ�ε�ַ
	cout << "�������к�ʵ�ε�ֵ��\n" << c << "\t" << d << endl;

	cout << endl;
#pragma endregion

#pragma region ð��������
	int arr2[9] = { 3,1,4,1,5,9,2,6 };
	int len_arr2 = sizeof(arr2) / sizeof(arr2[0]);
	bublle(arr2, len_arr2);		//������arr2��Ϊ�����׵�ַ
	printArr(arr2, len_arr2);

#pragma endregion


	system("pause");

	return 0;
}