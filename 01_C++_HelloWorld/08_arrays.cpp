#include<iostream>
using namespace std;

int main8()
{
#pragma region һά����
	//��������ʼ��
	// ����һ
	int arr1[3];
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 3;
	//������
	int arr2[4] = { 1,2,3,4 };
	//������Ϊ��ȫ��䣬����0���
	//������
	int arr3[] = { 1,2,3,4,5 };

	//�������Ϊ�������޷��޸�;������Ԫ��֧���޸�
	//��������Ԫ��
	cout << "arr3������Ϊ��\n";
	int arr3_length = sizeof(arr3) / sizeof(arr3[0]);
	//ͨ��������ռ�����ڴ������������������ռ�ڴ�õ����鳤��
	for (int i = 0; i < arr3_length; i++) {
		cout << arr3[i] << "\t";
	}
	cout << "\n\n";

	//��ȡ�׵�ַ
	cout << "arr3���ڴ��׵�ַ��" << (int)arr3 << endl;
	//ʹ��(int)��ʮ������ת��Ϊʮ����
	//��Ԫ�ص��׵�ַ��������׵�ַ��ͬ
	cout << "arr3�ڶ���Ԫ�ص��׵�ַ" << (int)&arr3[1] << endl;
	//ÿһԪ���׵�ַ���һ�������ڴ浥λ(��ʾ��Ϊ4��
	cout << "\n\n";
#pragma endregion

#pragma region ð������
	int arr4[] = { 3,1,4,1,5,9,2,6, };
	int arr4_length = sizeof(arr4) / sizeof(arr4[0]);
	cout << "����ǰ����Ϊ��\n";
	for (int i = 0; i < arr4_length; i++) {
		cout << arr4[i] << "\t";
	}
	cout << endl;
	//ð������ѭ��
	for (int j = 0; j < arr4_length - 1; j++) {
		for (int i = 0; i < arr4_length - 1 - j; i++) {
			if (arr4[i] > arr4[i + 1]) {
				int temp = arr4[i + 1];
				arr4[i + 1] = arr4[i];
				arr4[i] = temp;
			}
		}
	}
	cout << "���������Ϊ��\n";
	for (int i = 0; i < arr4_length; i++) {
		cout << arr4[i] << "\t";
	}
	cout << "\n\n";

	#pragma endregion

#pragma region ��ά���� 
	//��������ʼ������
	//����һ
	int arr1_td[2][3];
	int a = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			arr1_td[i][j] = ++a;
		}
	}
	
	//������
	int arr2_td[2][3] = {
		{6,5,4},
		{3,2,1}
	};

	//������
	//��ʼ�����Ⱥ��Զ��ָ�
	int arr3_td[2][3] = { 3,1,4,1,5,9 };

	//������
	//����ʡ������
	int arr4_td[][3] = {2,3,0,3,1,6};
	//����ķ�ʽͬ���Ϸ�
	//int arr4_td[][3] = {
	//	{2,3,0},
	//	{3,1,6}
	//};						


	//������������
	cout << "arr4_td������Ϊ��\n";
	//��ȡ����
	int arr4_rows = sizeof(arr4_td) / sizeof(arr4_td[0]);
	//��ȡ����
	int arr4_colms = sizeof(arr4_td[0]) / sizeof(arr4_td[0][0]);
	//���ѭ��
	for (int i = 0; i < arr4_rows; i++) {
		for (int j = 0; j < arr4_colms; j++) {
			cout << arr4_td[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";


	//�׵�ַ
	cout << "arr4_td���׵�ַΪ" << arr4_td << endl;
	//�����һ�е��׵�ַ�������׵�ַ��ͬ
	cout << "arr4_td�ڶ��е��׵�ַΪ" << arr4_td[1] << endl;
	//�����һ�е�һ�е��׵�ַ�������׵�ַҲ��ͬ
	cout << "arr4_td�ڶ��е����е��׵�ַΪ" << &arr4_td[1][2] << endl;
	cout << "\n";
#pragma endregion


	system("pause");

	return 0;
}