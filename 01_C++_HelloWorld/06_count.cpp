#include<iostream>
using namespace std;
#include<string>

int main6()
{
	int num1 = 10;
	int num2 = 2;
	#pragma region ���������
	//��\����
	int nums = num1 + num2;
	cout << "10+2=" << nums << endl;
	//��\����
	int numd = num1 - num2;
	cout << "10-2=" << numd << endl;
	//��
	int numm = num1 * num2;
	cout << "10*2=" << numm << endl;
	//����������������Ϊȡ�����㣩
	int numv = num1 / num2;
	cout << "10/2=" << numv << endl;
	//ģ(С������ȡģ��
	int numo = num1 % num2;
	cout << "10%2=" << numo << endl;

	cout << endl;

	//ǰ�õ���
	int sf1 = 1; 
	cout << "����ǰsf1Ϊ" << sf1 << endl;
	int sf2 = 2;
	int sf = ++sf1 * sf2;
	cout << "++1 * 2 = " << sf << endl;
	cout << "�����sf1Ϊ" << sf1 << endl;
	cout << endl;

	//���õ���
	int sa1 = 1;
	cout << "����ǰsa1Ϊ" << sa1 << endl;
	int sa2 = 2;
	int sa = sa1++ * sa2;
	cout << "1++ * 2 = " << sa << endl;
	cout << "�����sa1Ϊ" << sa1 << endl;
	cout << endl;

	//ǰ�õݼ�
	int df1 = 1; 
	cout << "����ǰdf1Ϊ" << df1 << endl;
	int df2 = 2;
	int df = --df1 * df2;
	cout << "--1 * 2 = " << df << endl;
	cout << "�����df1Ϊ" << df1 << endl;
	cout << endl;

	//���õݼ�
	int da1 = 1; int da2 = 2;
	cout << "����ǰda1Ϊ" << da1 << endl;
	int da = da1-- * da2;
	cout << "1-- * 2 = " << da << endl;
	cout << "�����da1Ϊ" << da1 << endl;
	cout << endl;
	#pragma endregion


	#pragma region ��ֵ�����
	//��ֵ
	int a = 2;
	cout << "a=" << a << endl;
	cout << endl;
	//�ӵ���
	int nums0 = 10;
	cout << "nums0=" << nums0 << endl;
	nums0 += a;
	cout << "nums0 += a=" << nums0 << endl;
	cout << endl;
	//������
	int numd0 = 10;
	cout << "numd0=" << numd0 << endl;
	numd0 -= a;
	cout << "numd0 -= a = " << numd0 << endl;
	cout << endl;
	//�˵���
	int numm0 = 10;
	cout << "numm0=" << numm0 << endl;
	numm0 *= a;
	cout << "numm0 *= a = " << numm0 << endl;
	cout << endl;
	//������
	int numv0 = 10;
	cout << "numv0=" << numv0 << endl;
	numv0 /= a;
	cout << "numv0 /= a = " << numv0 << endl;
	cout << endl;
	//ģ����
	int numo0 = 10;
	cout << "numo0=" << numo0 << endl;
	numo0 %= a;
	cout << "numo0 %= a = " << numo0 << endl;
	cout << endl;
	#pragma endregion


	#pragma region �Ƚ������
	bool cb = true;
	//�����
	cb = num1 == num2;
	cout << "10==2 �Ĳ���ֵΪ" << cb << endl;
	//������
	cb = num1 != num2;
	cout << "10!=2 �Ĳ���ֵΪ" << cb << endl;
	//С��
	cb = num1 < num2;
	cout << "10<2 �Ĳ���ֵΪ" << cb << endl;
	//����
	cb = num1 > num2;
	cout << "10>2 �Ĳ���ֵΪ" << cb << endl;
	//С�ڵ���
	cb = num1 <= num2;
	cout << "10<=2 �Ĳ���ֵΪ" << cb << endl;
	//���ڵ���
	cb = num1 >= num2;
	cout << "10>=2 �Ĳ���ֵΪ" << cb << endl;

	cout << endl;

	//C++����String���ԱȽ�
	string cs1 = "abc";
	string cs2 = "Abc";
	cout << "\"abc\">\"Abc\"�Ĳ���ֵΪ" << (cs1 > cs2) << endl;
	cout << "\"abc\"<\"Abc\"�Ĳ���ֵΪ" << (cs1 < cs2) << endl;
	cout << endl;
	#pragma endregion


	#pragma region �߼������
	bool lb1 = 1;
	bool lb2 = 0;
	//��
	cout << "��!�桱�Ĳ���ֵ��" << !lb1 << endl;
	//��
	cout << "���� && �١��Ĳ���ֵ��" << (lb1 && lb2) << endl;
	//��
	cout << "���� || �١��Ĳ���ֵ��" << (lb1 || lb2) << endl;

	cout << endl;
	#pragma endregion


	system("pause");

	return 0;
}