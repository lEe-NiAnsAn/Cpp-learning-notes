#include <iostream>
using namespace std;
#include<stdlib.h>
#include<string>
//���������Ŀ
#define MAX 10


//���������ṹ��
struct Weapon
{
	string Name = "";	//����
	int Damage = 0;		//�˺�
	int Weight = 0;		//����
};

//���������ṹ��
struct Bag
{
	Weapon WeaponArray[MAX];	//MAXΪ������������������Ŀ
	int Num_weapon = 0;				//�������ִ�ŵ�������Ŀ
};


//ȷ�Ͻ�����������
void sysclear()
{
	system("pause");
	system("cls");	//��������	//������Ҫ���ͷ�ļ�#include<stdlib.h>
}

//�����������ƺ���
string inputname()
{
	string name;
	cout << "�������������ƣ�\n";
	cin >> name;
	system("cls");

	return name;
}

//��װ��ʾmenu����
void showMenu()
{
	cout << "\t _________________________________\n"
		<< "\t| # |\t �����������ִ�в���\t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 1 |\t    ��㱳��������\t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 2 |\t    �������������\t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 3 |\t    ���ұ���������\t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 4 |\t    ��������������\t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 5 |\t  �޸ı�����������ֵ\t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 6 |\t       ��ձ���   \t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 0 |\t       �رձ���   \t  |\n"
		<< "\t ---------------------------------\n";

	return;
}

//�����������
void addWeapon(Bag* wpBag)
{
	if (wpBag->Num_weapon == MAX) {
		cout << "�Ѿ�װ��������~\n\n";
	}
	else
	{
		string name;
		cout << "�������������ƣ�\n";
		cin >> name;
		system("cls");
		
		//����
		for (int i = 0; i < wpBag->Num_weapon; i++)
		{
			if (wpBag->WeaponArray[i].Name == name) {
				cout<< "�������Ѿ���һ����Ϊ����" << name << "������������~\n"
					<< "��ȡһ�����ưɣ�\n\n";
				return;
			}	
		}

		wpBag->WeaponArray[wpBag->Num_weapon].Name = name;
		int damage;
		cout << "�����������˺�ֵ��\n";
		cin >> damage;
		system("cls");
		while (true)
				{
					if (cin.good())	//�ж�cin״̬�Ƿ�����
					{
						wpBag->WeaponArray[wpBag->Num_weapon].Damage = damage;
						break;
					}
					else	//cin״̬�쳣
					{
						cout << "error!\n\n";
						sysclear();
						cout << "���������������˺�ֵ��\n";
						cin.clear();	//�������״̬
						cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
						//�������������г��ȣ�ֱ�����س���
						cin >> damage;
						system("cls");
					}
				}

		int weight;
		cout << "����������������\n";
		cin >> weight;
		system("cls");
		while (true)
				{
					if (cin.good())
					{
						wpBag->WeaponArray[wpBag->Num_weapon].Weight = weight;
						break;
					}
					else
					{
						cout << "error!\n\n";
						sysclear();
						cout << "��������������������\n";
						cin.clear();
						cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
						cin >> weight;
						system("cls");
					}
				}

		wpBag->Num_weapon++;	//����������һ	
	}
}

//ͨ�����Ʋ��������±꺯��
int searchwp(Bag* wpbag, string name)	//����һ�������ṹ��	����������������
{
	for (int i = 0; i < wpbag->Num_weapon; i++)
	{
		if (wpbag->WeaponArray[i].Name == name)
		{
			return i;
		}	
	}
	return -1;	//δ��ѯ������򷵻�-1
}

//������������
void dropWeapon(Bag* wpbag,int wp)
{
	for (int i = wp; i < wpbag->Num_weapon - 1; i++)
	{
		wpbag->WeaponArray[i] = wpbag->WeaponArray[i + 1];
	}
	wpbag->Num_weapon--;
}

//��ձ�������
void clearBag(Bag* wpbag)
{
	for (int i = 0; i < wpbag->Num_weapon; i++) {	//��i < wpbag->Num_weapon�������޷������������
		dropWeapon(wpbag, i);
	}
	//������һ������
	wpbag->WeaponArray[0].Name = "��ʼ����";
	wpbag->WeaponArray[0].Damage = 0;
	wpbag->WeaponArray[0].Weight = 0;

	wpbag->Num_weapon = 0;
}
//����ֱ�ӽ�Num_weapon���㣬��Ϊ�߼���ղ���

//�޸�������ֵ����
void changewp(Bag* wpbag,int id)
{

	int damage;
	cout << wpbag->WeaponArray[id].Damage << " --> ";
	cin >> damage;
	system("cls");
	while (true)
	{
		if (cin.good())
		{
			wpbag->WeaponArray[id].Damage = damage;
			break;
		}
		else
		{
			cout << "error!\n\n";
			sysclear();
			cout << "���������룩\n" << wpbag->WeaponArray[id].Damage << " --> ";
			cin >> damage;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cin >> damage;
			system("cls");
		}
	}

	int weight;
	cout << wpbag->WeaponArray[id].Weight << " --> ";
	cin >> weight;
	system("cls");
	while (true)
	{
		if (cin.good())
		{
			wpbag->WeaponArray[id].Weight = weight;
			break;
		}
		else
		{
			cout << "error!\n\n";
			sysclear();
			cout << "���������룩" << wpbag->WeaponArray[id].Weight << " --> ";
			cin >> damage;
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cin >> weight;
			system("cls");
		}
	}
	return;
}


int main()
{
	Bag myBag;
	myBag.Num_weapon = 0;

	int r;
	int select;
	string weaponname;

	cout << "��֪��ô���£�����Ǻ�~�뿴����ı���!\n\n";
	sysclear();
	while (true){
		showMenu();		//����menu
		cout << "\nѡ�";
		cin >> select;	//����ѡ��
		cout << endl;
		system("cls");
		if (cin.good()) {
			while (true) {
				switch (select) {
				case 1:		//�򿪱���
					cout << "����˱�����\n���������涼��Щʲô�ɣ�\n\n";
					sysclear();
					if (myBag.Num_weapon == 0) {
						cout << "�տ���Ҳ��~\n\n";
						sysclear();
					}
					else {
						cout << "������ı���������£�\n\n";
						for (int i = 0; i < myBag.Num_weapon; i++) {
							cout << i + 1 << "��"
								<< myBag.WeaponArray[i].Name
								<< "  �˺���" << myBag.WeaponArray[i].Damage << "��"
								<< "  ������" << myBag.WeaponArray[i].Weight << "g\n\n";
						}
						sysclear();
					}

					break;
				case 2:		//�������������
					cout << "���������������һ��������\n\n";
					sysclear();
					addWeapon(&myBag);
					 if(myBag.Num_weapon <= MAX && myBag.Num_weapon > 0){
						cout << "��İ���������" << myBag.Num_weapon << "����������\n\n";
					}
					sysclear();
					break;
				case 3:		//���ұ���������
					weaponname = inputname();
					r = searchwp(&myBag, weaponname);
					if (r < 0){
						cout << "ʲô����������û�С�" << weaponname << "��������\n\n";
						sysclear();
					}
					else{
						cout << "����������~�����ҵ��ˡ�" << weaponname << "����\n\n";
						sysclear();
						cout << "���������ϳ��У�" << myBag.WeaponArray[r].Name << "\n"
							<< "���ԣ�"
							<< "\t�˺���" << myBag.WeaponArray[r].Damage << "�� "
							<< "\t������" << myBag.WeaponArray[r].Weight << "g\n\n";
						sysclear();

						cout << "�����ڰѡ�" << myBag.WeaponArray[r].Name << "���Ż��˱���������\n\n";
						sysclear();
					}

					break;
				case 4:		//��������������
					weaponname = inputname();
					r = searchwp(&myBag, weaponname);
					if (r < 0){					
						cout << "��û�취������û�еĶ�����~" << "\n\n";
					}
					else {
						cout << "�����Ҫ������" << weaponname << "����\n\n"
							<< "  1 - ��" << "     0 - ��\n\n";
						int s1;
						cin >> s1;
						system("cls");
						while (true){
							if (cin.good()){
								if (s1 == 1) {
									dropWeapon(&myBag,r);
									cout << "��ѡ�" << weaponname << "���ӵ��˾������⣡��\n\n";
								}
								else if (s1 == 0) {
									cout << "���ְѡ�" << weaponname << "���Ż��˱���...\n\n";
								}
								break;
							}
							else{
								cout << "error!\n\n";
								sysclear();
								cin.clear();
								cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
								break;
							}
						}
					}
					sysclear();

					break;
				case 5:		//�޸ı�����������ֵ
					weaponname = inputname();
					r = searchwp(&myBag, weaponname);
					if (r < 0) {
						cout << "������û������Ϊ��" << weaponname << "�������������޸���~\n\n";
						sysclear();
					}
					else {
						cout << "������������׼���ı䡰" << weaponname << "������ֵ��\n\n";
						sysclear();
						changewp(&myBag, r);
						cout<< weaponname << "�޸ĺ�\n\t���ԣ�"
							<< "\t�˺���" << myBag.WeaponArray[r].Damage << "�� \n"
							<< "\t\t������" << myBag.WeaponArray[r].Weight << "g\n\n";
					}
					sysclear();

					break;
				case 6:		//��ձ���
					cout << "�����Ҫ��ձ�����\n\n"
						<< "  1 - ��" << "     0 - ��\n\n";
					int s2;
					cin >> s2;
					system("cls");
					while (true) {
						if (cin.good()) {
							if (s2 == 1) {
								clearBag(&myBag);
								cout << "��ѱ������˸��׳��죡��\n\n";
							}
							else if (s2 == 0) {
								cout << "������˾����������ͷ������\n\n";
							}
							break;
						}
						else {
							cout << "error!\n\n";
							sysclear();
							cin.clear();
							cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
							break;
						}
					}
					sysclear();

					break;
				case 0:		//�رձ���
					cout << "�����걳����տ���������㡰����~��һ����������������������ǰ��������\n\n";

					system("pause");
					return 0;//�˴���ֱ���˳�main����

					break;
				default:
					break;
				}
				break;
			}
		}
		else{
			select = 10;
			cout << "error!\n\n";
			sysclear();
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		}
		
	}


	system("pause");

	return 0;
}