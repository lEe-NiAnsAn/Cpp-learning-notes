#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
#include "sclear.h"//确认清屏函数
#include "cin_error.h"//整型cin错误
#include "class_fighters.h"//战斗员类
#include "class_captian.h"//队长类
#include "class_feeder.h"//装填手类
#include "class_fire.h"//火力手类
#include "class_observer.h"//观察手类
#include "class_commanders.h"//战斗组长类
#include "class_you.h"//你自己


int main()
{
	cout << "一场遭遇战后，你顶替指战员成为了一个战斗单位的队长\n\n";
	sclear();
	Captian cap;
	int select = 10;
	while (true)
	{
		cap.showMenu();
		cout << "选择：";
		cin >> select;
		cout << endl;
		system("cls");
		Fighter* fighter = NULL;
		if (cin.good())
		{
			while (true)
			{
				switch (select)
				{
				case 0:	//结束休整
					cap.exitMenu();
					break;
				case 1://请求增援
					cap.ftAdd();
					sclear();
					break;
				case 2://显示战斗员信息
					cap.show();
					sclear();
					break;
				case 3://除名战斗员
					cap.ftDel();
					sclear();
					break;
				case 4://修改战斗员信息
					cap.ftMod();
					sclear();
					break;
				case 5://查找战斗员
					cap.ftSearch();
					sclear();
					break;
				case 6://排序队伍
					cap.sort();
					sclear();
					break;
				case 7://解散队伍
					cap.ftClear();
					sclear();
					break;
				default:
					cout << "（请重新输入)\n";
					break;
				}
				break;
			}

		}
		else
		{
			cin_error(0);
		}
	}


	system("pause");

	return 0;
}