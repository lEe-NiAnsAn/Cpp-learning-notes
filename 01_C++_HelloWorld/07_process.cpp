#include<iostream>
using namespace std;
#include<ctime>

int main7()
{
	//��������
	
	//һ ˳��ṹ
	//����˳��ִ�У���������ת


	#pragma region �� ѡ��ṹ
	int num0 = 0;
	cout << "����Ϊ����24Сʱ��Ӧ�ý�ʳ�Ĵ�����" << endl;
	cin >> num0;
	cout << endl;
		#pragma region ����if���
	if (num0 == 3)
	{
		cout << "һ������\n" << endl;
	}
		#pragma endregion

		#pragma region ����if���
	if (num0 < 0)
	{
		cout << "��Ч�Ĵ���\n" << endl;
	}
	else
	{
		cout << "��Ч�Ĵ���\n" << endl;
	}
		#pragma endregion

		#pragma region ������if���
	if (num0 > 3)
	{
		cout << "�����Ƿ���ࣿ\n" << endl;
	}
	else if (num0 == 3)
	{
		cout << "��ͬ\n" << endl;
	}
	else if(num0 < 3 && num0 > 0)
	{
		cout << "�����Ƿ���٣�\n" << endl;
	}
	else if (num0 == 0)
	{
		cout << "����ʻᵼ����������\n" << endl;
	}
	else
	{
		cout << "���������Ƿ���ȷ\n" << endl;
	}
		#pragma endregion
	
		#pragma region Ƕ��if���
	if (num0 > 3)
	{
		if (num0 > 5) 
		{
			cout << "��ʳ����Ƶ��\n" << endl;
			if (num0 > 6)
			{
				cout << "��ʳ��Ͳ�����ָ��˶�Ľ�ʳ����\n" << endl;
			}
		}
	}
	else if (num0 == 3)
	{
		cout << "���ϴ��������Ľ�ʳ����\n" << endl;
	}
	else if (num0 < 3 && num0 > 0)
	{
		if (num0 == 2)
		{
			cout << "�Ŵ����������ϴ˽�ʳ����\n" << endl;
		}
		if (num0 == 1)
		{
			cout << "һ��һ�Ͳ����ǽ�����ʳϰ��\n" << endl;
		}
	}
	else if (num0 == 0)
	{
		cout << "����ʹ�������ֶλ�ȡӪ��\n" << endl;
	}
	else
	{
		cout << "лл\n" << endl;
	}

	cout << endl;
		#pragma endregion

		#pragma region ��Ŀ�����
	//���ʽ1 ? ���ʽ2 : ���ʽ3;
	//��1Ϊ�棬ִ��2������2
	//��1Ϊ�٣�ִ��3������3
	int n0 = 0;
	int n1 = 1;
	cout << "������ʽ1��ֵ" << endl;
	cin >> n1;
	int n2 = 2;
	int n3 = 3;
	n0 = n1 == 2 ? n2 : n3;
	cout << "������Ǳ��ʽ" << n0 << "\n" << endl;
	//��Ŀ���㷵��ֵΪ��������˿ɼ�����ֵ

		#pragma endregion

		#pragma region switch���
	int sw_num = 0;
	cout << "��Ϊ�����ӳ��һ����Ӱ����\n" ;
	cout << "����ӦΪ 0 ~ 5 ������" << endl;
	cin >> sw_num;
	switch (sw_num)
	{
	case 5:
		cout << "���������߷֣�\n";
		break;
	case 4:
		cout << "��������ķֵĸ߷֣�\n";
		break;
	case 3:
		cout << "��������е����֣�\n";
		break;
	case 2:
		cout << "����������ֵĵͷ֣�\n";
		break;
	case 1:
		cout << "������˺ܵ͵����֣�\n";
		break;
	case 0:
		cout << "���������ͷ֣�\n";
		break;
	default:
		cout << "��Ч����" << endl;
		break;
	}
	//����break����򽫼���ִ����һcase�����
	cout << endl;
		#pragma endregion

	#pragma endregion


	#pragma region �� ѭ���ṹ
	int i = 0;
	srand((unsigned int)time(NULL));
	//�������Ҫͷ�ļ� #include<ctime>
	//�����������ʹrand()��ʱ��仯��ѡ�����е������������Ե��ô���Ϊ׼
		#pragma region whileѭ�����
	cout << "������һ��ʮ�����㿪ʼ������\n";
	int rn = rand() % 10 + 1;
	//rand()����������0~MAX�����һ������%ȡģ�����ͬ�ڸı��������ɷ�Χ����������ʾ���С� %10 ����Ϊ0~10����α�������
	//����srand��䣬rand()ֻ�ᰴ�̶������������������е�һ�ε���rand()���ɵ�����ԶΪͬһ����(��������%����Ϊ42)
	while (i <= rn)
	{
		cout << i << "\t";
		i++;
	}
	cout << "\n";

	cout << endl;
		#pragma endregion

		#pragma region do...whileѭ�����
	//��whileѭ����֮ͬ��Ϊ�������Ƚ���һ��ѭ���ٽ���ѭ���ж�
	cout << "�ٴ����\n";
	i = 0;
	do
	{
		cout << i << "\t";
		i++;
	} 
	while (i < rn);
	cout << "\t";
	cout << "\n";

	cout << endl;
	
		#pragma endregion
		
		#pragma region forѭ��
	cout << "�ٴ����\n";
	for (i = 0; i <= rn; i++)
	{
		cout << i << "\t";
	}
	cout << "\n";
	
	cout << endl;
		#pragma endregion

		#pragma region Ƕ��ѭ��
	cout << "��ӡ7*7��ͼ\n";
	int num1 = 7;
	for (i = 0; i < num1; i++)
	{
		for (int j = 0; j < num1; j++)
		{
			cout << " * ";
		}
		cout << "\v";
	}
	cout << "\n";

	cout << endl;
		#pragma endregion

	#pragma endregion


	#pragma region �� ��ת���
		#pragma region break���
	//1����switch����ֹcase������switch
		//�÷��� ���� ѡ��ṹ\switch��䡱
	//2����ѭ���ṹ���������ڼ�ѭ�����
	cout << "��ӡֱ����ͼ\n";
	num1 = 7;
	for (i = 0; i < num1; i++)
	{
		for (int j = 0; j < num1; j++)
		{
			if (j == i + 1)
			{
				break;
			}
			cout << " * ";
		}
		cout << "\v";
	}

	cout << "\n";

	cout << endl;
		#pragma endregion

		#pragma region continue���
	//��ѭ���������������ѭ����ֱ��ִ���´�ѭ��
	cout << "�ٴδ�ӡ\n";
	num1 = 7;
	for (i = 0; i < num1; i++)
	{
		for (int j = 0; j < num1; j++)
		{
			if (j > i)
			{
				continue;
			}
			cout << " * ";
		}
		cout << "\v";
	}
	cout << "\n";

	cout << endl;
		#pragma endregion

		#pragma region goto���
	//��������ת��ָ����Ǵ�
	cout << "��ӡ5*5��ͼ\n";
	int num2 = 5;
	int j = 0;
	flag2:
	i = 0;
	flag1:
	cout << " * ";
	i++;
	if (i < num2)
	{
		goto flag1;
	}
	cout << "\n";
	j++;
	if (j < num2)
	{
		goto flag2;
	}
	cout << "\n";

	cout << endl;
		#pragma endregion

	#pragma endregion

	system("pause");

	return 0;
}