#include<iostream>
using namespace std;
#include<string>

//����Ƕ�׽ṹ��
struct Caus
{
	float acc;	//��׼��
	float atrk;	//������
};

//һ �����ṹ��
struct Arms
{
	string name;	//����
	int damage;		//�˺�
	Caus pprity;	//����	//Ƕ�׽ṹ��
}arm;//�ڴ�Ҳ����������ṹ�����

//��ӡ����ṹ���������
//ֵ����
void printArm(Arms arm)
{
	cout << arm.name << "  �˺���" << arm.damage << endl;

	return;
}

//�޸Ľṹ���������
//��ַ����
void changeArm(Arms* arm)
{
	string name;
	cout << "���������ƣ�" << endl;
	cin >> name;
	int damage;
	cout << "���������˺���ֵ��" << endl;
	cin >> damage;
	arm->name = name;
	arm->damage = damage;
	cout << endl;

	return;
}

//��ӡ����ṹ���������
//ʹ��const����
//��ַ����
void cprintArm(const Arms* arm)
{
	//���ɸ��ģ�arm->damage = 100;
	cout << arm->name << "  �˺���" << arm->damage << endl;

	return;
}

int main()
{
	//�ṹ�������û��Խ����洢��ͬ����������
#pragma region �� �����������
	//����һ
	struct Arms arm1;
	arm1.name = "ˮ����";
	arm1.damage = 23;
	cout << arm1.name << "  �˺���" << arm1.damage << endl;
	//�����ṹ�����ʱstruct�ؼ��ֿ�ʡ��
	//������
	Arms arm2 = { "�˹�",42 };	//��ʼ��˳�����붨��ṹ��ʱһ��
	cout <<arm2.name << "  �˺���" << arm2.damage << endl;
	//������
	//����ṹ��ʱ�����ṹ�����
	arm.name = "ȭͷ";
	arm.damage = 5;
	cout <<arm.name << "  �˺���" << arm.damage << "\n\n";
#pragma endregion

#pragma region �� �ṹ������
	//�����ṹ������
	struct Arms armsArray[2] = {
		{"��",56},
		{"����",15}
	};
	//���Ľṹ������Ԫ��
	armsArray[1].name = "���ƿ";
	//�����ṹ������
	for (int i = 0; i < 2; i++) {
		cout << armsArray[i].name << "  �˺���" << armsArray[i].damage << endl;
	}

	cout << "\n\n";
#pragma endregion

#pragma region �� �ṹ��ָ��
	Arms* p_arm1 = &arm1;
	//ʹ��ָ����ʽṹ������е�����(->)
	cout << p_arm1->name << "  �˺���" << p_arm1->damage << endl;

#pragma endregion

#pragma region �� Ƕ�׽ṹ��
	Arms arm3;
	arm3.name = "PVC��";
	arm3.damage = 45;
	//��ʼ��Ƕ�׽ṹ����Ԫ��
	arm3.pprity.acc = 0.43f;
	arm3.pprity.atrk = 0.16f;
	cout << arm3.name 
		<< "  �˺���" << arm3.damage 
		<< "  ��׼�ȣ�" << arm3.pprity.acc 
		<< "  ������" << arm3.pprity.atrk <<"\n\n";
#pragma endregion

#pragma region �� �ṹ�庯������
	//ֵ����
	printArm(arm1);
	cout << endl;
	//��ַ����
	changeArm(&arm1);
	printArm(arm1);

	cout << endl;
#pragma endregion

#pragma region �� �ṹ���е�const
	//ʹ�õ�ַ���ݿɱ��⿽���Ӵ�Ľṹ���������ʡ�ڴ�
	//const�������ڷ�ֹ�����
	cprintArm(&arm2);

	cout << "\n\n";
#pragma endregion


	system("pause");

	return 0;
}