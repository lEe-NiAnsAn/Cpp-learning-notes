#include <iostream>
using namespace std;
#include<stdlib.h>
#include<string>
//定义最大数目
#define MAX 10


//创建武器结构体
struct Weapon
{
	string Name = "";	//名称
	int Damage = 0;		//伤害
	int Weight = 0;		//重量
};

//创建背包结构体
struct Bag
{
	Weapon WeaponArray[MAX];	//MAX为背包存放武器的最大数目
	int Num_weapon = 0;				//背包内现存放的武器数目
};


//确认进行清屏函数
void sysclear()
{
	system("pause");
	system("cls");	//清屏函数	//可能需要添加头文件#include<stdlib.h>
}

//输入武器名称函数
string inputname()
{
	string name;
	cout << "（输入武器名称）\n";
	cin >> name;
	system("cls");

	return name;
}

//封装显示menu函数
void showMenu()
{
	cout << "\t _________________________________\n"
		<< "\t| # |\t 输入标题数字执行操作\t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 1 |\t    清点背包内武器\t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 2 |\t    添加武器至背包\t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 3 |\t    查找背包内武器\t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 4 |\t    丢弃背包内武器\t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 5 |\t  修改背包内武器数值\t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 6 |\t       清空背包   \t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 0 |\t       关闭背包   \t  |\n"
		<< "\t ---------------------------------\n";

	return;
}

//添加武器函数
void addWeapon(Bag* wpBag)
{
	if (wpBag->Num_weapon == MAX) {
		cout << "已经装不下了捏~\n\n";
	}
	else
	{
		string name;
		cout << "（输入武器名称）\n";
		cin >> name;
		system("cls");
		
		//查重
		for (int i = 0; i < wpBag->Num_weapon; i++)
		{
			if (wpBag->WeaponArray[i].Name == name) {
				cout<< "背包里已经有一件名为：“" << name << "”的武器了捏~\n"
					<< "另取一个名称吧！\n\n";
				return;
			}	
		}

		wpBag->WeaponArray[wpBag->Num_weapon].Name = name;
		int damage;
		cout << "（输入武器伤害值）\n";
		cin >> damage;
		system("cls");
		while (true)
				{
					if (cin.good())	//判断cin状态是否正常
					{
						wpBag->WeaponArray[wpBag->Num_weapon].Damage = damage;
						break;
					}
					else	//cin状态异常
					{
						cout << "error!\n\n";
						sysclear();
						cout << "（重新输入武器伤害值）\n";
						cin.clear();	//清除错误状态
						cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
						//跳过缓冲区所有长度，直到遇回车符
						cin >> damage;
						system("cls");
					}
				}

		int weight;
		cout << "（输入武器重量）\n";
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
						cout << "（重新输入武器重量）\n";
						cin.clear();
						cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
						cin >> weight;
						system("cls");
					}
				}

		wpBag->Num_weapon++;	//武器数量加一	
	}
}

//通过名称查找武器下标函数
int searchwp(Bag* wpbag, string name)	//参数一：背包结构体	参数二：武器名称
{
	for (int i = 0; i < wpbag->Num_weapon; i++)
	{
		if (wpbag->WeaponArray[i].Name == name)
		{
			return i;
		}	
	}
	return -1;	//未查询到结果则返回-1
}

//丢弃武器函数
void dropWeapon(Bag* wpbag,int wp)
{
	for (int i = wp; i < wpbag->Num_weapon - 1; i++)
	{
		wpbag->WeaponArray[i] = wpbag->WeaponArray[i + 1];
	}
	wpbag->Num_weapon--;
}

//清空背包函数
void clearBag(Bag* wpbag)
{
	for (int i = 0; i < wpbag->Num_weapon; i++) {	//“i < wpbag->Num_weapon”次数无法清除所有武器
		dropWeapon(wpbag, i);
	}
	//清除最后一个武器
	wpbag->WeaponArray[0].Name = "初始名称";
	wpbag->WeaponArray[0].Damage = 0;
	wpbag->WeaponArray[0].Weight = 0;

	wpbag->Num_weapon = 0;
}
//或是直接将Num_weapon置零，作为逻辑清空操作

//修改武器数值函数
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
			cout << "（重新输入）\n" << wpbag->WeaponArray[id].Damage << " --> ";
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
			cout << "（重新输入）" << wpbag->WeaponArray[id].Weight << " --> ";
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

	cout << "不知怎么回事，你就是很~想看看你的背包!\n\n";
	sysclear();
	while (true){
		showMenu();		//进入menu
		cout << "\n选项：";
		cin >> select;	//进行选择
		cout << endl;
		system("cls");
		if (cin.good()) {
			while (true) {
				switch (select) {
				case 1:		//打开背包
					cout << "你打开了背包！\n来看看里面都有些什么吧！\n\n";
					sysclear();
					if (myBag.Num_weapon == 0) {
						cout << "空空如也捏~\n\n";
						sysclear();
					}
					else {
						cout << "背包里的宝物陈列于下！\n\n";
						for (int i = 0; i < myBag.Num_weapon; i++) {
							cout << i + 1 << "、"
								<< myBag.WeaponArray[i].Name
								<< "  伤害：" << myBag.WeaponArray[i].Damage << "点"
								<< "  重量：" << myBag.WeaponArray[i].Weight << "g\n\n";
						}
						sysclear();
					}

					break;
				case 2:		//添加武器至背包
					cout << "你正在往背包里放一件武器！\n\n";
					sysclear();
					addWeapon(&myBag);
					 if(myBag.Num_weapon <= MAX && myBag.Num_weapon > 0){
						cout << "你的包里现在有" << myBag.Num_weapon << "件武器！！\n\n";
					}
					sysclear();
					break;
				case 3:		//查找背包内武器
					weaponname = inputname();
					r = searchwp(&myBag, weaponname);
					if (r < 0){
						cout << "什么！？背包里没有“" << weaponname << "”！！！\n\n";
						sysclear();
					}
					else{
						cout << "当当当当当~！你找到了“" << weaponname << "”！\n\n";
						sysclear();
						cout << "你现在手上持有：" << myBag.WeaponArray[r].Name << "\n"
							<< "属性："
							<< "\t伤害：" << myBag.WeaponArray[r].Damage << "点 "
							<< "\t重量：" << myBag.WeaponArray[r].Weight << "g\n\n";
						sysclear();

						cout << "你现在把“" << myBag.WeaponArray[r].Name << "”放回了背包。。。\n\n";
						sysclear();
					}

					break;
				case 4:		//丢弃背包内武器
					weaponname = inputname();
					r = searchwp(&myBag, weaponname);
					if (r < 0){					
						cout << "你没办法丢掉你没有的东西捏~" << "\n\n";
					}
					else {
						cout << "你真的要丢掉“" << weaponname << "”吗？\n\n"
							<< "  1 - 是" << "     0 - 否\n\n";
						int s1;
						cin >> s1;
						system("cls");
						while (true){
							if (cin.good()){
								if (s1 == 1) {
									dropWeapon(&myBag,r);
									cout << "你把“" << weaponname << "”扔到了九霄云外！！\n\n";
								}
								else if (s1 == 0) {
									cout << "你又把“" << weaponname << "”放回了背包...\n\n";
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
				case 5:		//修改背包内武器数值
					weaponname = inputname();
					r = searchwp(&myBag, weaponname);
					if (r < 0) {
						cout << "背包里没有名称为“" << weaponname << "”的武器可以修改捏~\n\n";
						sysclear();
					}
					else {
						cout << "你运用念力，准备改变“" << weaponname << "”的数值！\n\n";
						sysclear();
						changewp(&myBag, r);
						cout<< weaponname << "修改后\n\t属性："
							<< "\t伤害：" << myBag.WeaponArray[r].Damage << "点 \n"
							<< "\t\t重量：" << myBag.WeaponArray[r].Weight << "g\n\n";
					}
					sysclear();

					break;
				case 6:		//清空背包
					cout << "你真的要清空背包吗？\n\n"
						<< "  1 - 是" << "     0 - 否\n\n";
					int s2;
					cin >> s2;
					system("cls");
					while (true) {
						if (cin.good()) {
							if (s2 == 1) {
								clearBag(&myBag);
								cout << "你把背包清了个底朝天！！\n\n";
							}
							else if (s2 == 0) {
								cout << "你打消了净身出户的念头。。。\n\n";
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
				case 0:		//关闭背包
					cout << "欣赏完背包精湛的做工，你“呲啦~”一声拉紧拉链，背上它继续前进。。。\n\n";

					system("pause");
					return 0;//此处可直接退出main函数

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