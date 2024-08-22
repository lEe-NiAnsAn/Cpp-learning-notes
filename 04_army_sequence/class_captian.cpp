#include "class_captian.h"

Captian::Captian()
{
	//文件未创建
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "未查询至数据文件\n\n";
		cout << "开始创建文件并初始化。。。\n\n";
		sclear();
		this->m_ftNumb = 0;
		this->ftEmpty = true;
		this->m_ftArr = NULL;
		ifs.close();
		return;
	}
	//文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "数据文件为空\n\n";
		cout << "正在初始化。。。\n\n";
		sclear();
		this->m_ftNumb = 0;
		this->ftEmpty = true;
		this->m_ftArr = NULL;
		ifs.close();
		return;
	}
	//文件数据存在
	int num = this->get_Filenumb();
	cout << "现在队伍中还有" << num << "位战斗员！\n\n";
	sclear();
	this->m_ftNumb = num;
	this->m_ftArr = new Fighter * [this->m_ftNumb];
	this->read();
}
Captian::~Captian()
{
	if (this->m_ftArr != NULL)
	{
		for (int i = 0; i < this->m_ftNumb; i++)
		{
			if (this->m_ftArr[i] != NULL)
			{
				delete this->m_ftArr[i];
				m_ftArr[i] = NULL;
			}
		}
		delete[] this->m_ftArr;
		this->m_ftArr = NULL;
	}
}
void Captian::showMenu()
{
	cout << "\t _________________________________\n"
		<< "\t| # |\t 输入标题数字执行操作\t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 0 |\t       结束休整   \t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 1 |\t       请求增援   \t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 2 |\t    显示战斗员信息\t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 3 |\t      除名战斗员  \t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 4 |\t    修改战斗员信息\t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 5 |\t      查找战斗员  \t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 6 |\t       排序队伍   \t  |\n"
		<< "\t|---|-----------------------------|\n"
		<< "\t| 7 |\t       解散队伍   \t  |\n"
		<< "\t ---------------------------------\n"
		<< endl;
}
void Captian::exitMenu()
{
	cout << "回忆起战争开始前的故乡，"
		"你吹响了冲锋哨，带头冲向硝烟之中。。。\n\n";

	system("pause");
	exit(0);	//无论何处一旦调用即刻退出程序，返回0
	//空函数无法使用return
}
void Captian::ftAdd()
{
	cout << "接敌后队伍兵员缺乏！\n\n";
	cout << "所以你决定呼叫增援！\n\n";
	sclear();
	int n = 0;
	while (true)
	{
		cout << "你需要多少人手？\n";
		cin >> n;
		system("cls");
		if (cin.good())
		{
			if (n > 0)
			{
				//计算新人数
				int newsize = this->m_ftNumb + n;
				//为动态数组开辟新空间
				Fighter** newArr = new Fighter* [newsize];
				//拷贝原数据
				if (this->m_ftArr != NULL)
				{
					for (int i = 0; i < this->m_ftNumb; i++)
					{
							newArr[i] = this->m_ftArr[i];
					}
				}
				//添加新人员
				for (int i = 0; i < n;)
				{	
					int b = 1;
					int id;
					while (true)
					{
						cout << "（输入第" << i + 1 << "位战斗员编号）\n";
						cin >> id;
						system("cls");
						if(cin.good())
						{
							for (int t = 0; t < this->m_ftNumb + i; t++)
							{
								if (id == newArr[t]->f_id)
								{
									cout << "该ID已被占用\n\n";
									b = 0;
									sclear();
									break;
								}
							}
							break;
						}
						else
						{
							cin_error(0);
						}
					}
					if (b == 0)
					{
						continue;
					}
					string name;
					cout << "（输入第" << i + 1 << "位战斗员姓名）\n";
					cin >> name;
					system("cls");

					int rid;
					while (true)
					{
						cout << "（输入第" << i + 1 << "位战斗员职责）\n\n"
							<< "\t _________________________________\n"
							<< "\t| # |\t 输入标题数字执行操作\t  |\n"
							<< "\t|---|-----------------------------|\n"
							<< "\t| 1 |\t       战斗组长   \t  |\n"
							<< "\t|---|-----------------------------|\n"
							<< "\t| 2 |\t        火力手    \t  |\n"
							<< "\t|---|-----------------------------|\n"
							<< "\t| 3 |\t        供弹手    \t  |\n"
							<< "\t|---|-----------------------------|\n"
							<< "\t| 4 |\t        观察手    \t  |\n"
							<< "\t|---|-----------------------------|\n"
							<< "\t| 0 |\t        你自己    \t  |\n"
							<< "\t ---------------------------------\n\n";
						cin >> rid;
						system("cls");
						if (cin.good())
						{
							if(rid < 5 && rid > -1)
							{
								break;
							}
							cout << "（重新输入）\n";
						}
						else
						{
							cin_error(0);
						}
					}

					//通过rid创建对应类的对象
					Fighter* fighter = NULL;
					switch (rid)
					{
					case 1:
						fighter = new Commander(id, name, rid);
						break;
					case 2:
						fighter = new Fire(id, name, rid);
						break;
					case 3:
						fighter = new Feeder(id, name, rid);
						break;
					case 4:
						fighter = new Observer(id, name, rid);
						break;
					case 0:
						fighter = new You(id, name, rid);
						break;
					default:
						break;
					}

					//将指针保存至数组中
					newArr[this->m_ftNumb + i] = fighter;
					i++;
				}
				//释放原有空间
				delete[] this->m_ftArr;
				//更改新数组的指向
				this->m_ftArr = newArr;
				//更新人数
				this->m_ftNumb = newsize;
				cout << "有" << n << "位战斗员加入了你的队伍！\n\n";
				this->save();
				this->ftEmpty = false;  //标志文件为非空
				return;
			}
			else if(n == 0)
			{
				cout <<
				"你想了想，还是放弃了让更多人来送命的决定。。。\n\n";
				return;
			}
			cout << "（重新输入）\n\n";
			return;
		}
		else
		{
			cin_error(0);
		}
	}
}
void Captian::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_ftNumb; i++)
	{
		ofs << this->m_ftArr[i]->f_id << "\t\t"
			<< this->m_ftArr[i]->f_name << "\t\t"
			<< this->m_ftArr[i]->f_rid << endl;
	}

	ofs.close();
}
int Captian::get_Filenumb()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int rid;

	int n = 0;
	while (ifs >> id && ifs >> name && ifs >> rid)
		//逐词(遇空格结束)读取文件数据，读取完三项数据迭代，文件尾返回false
	{
		//迭代数即为人员数
		n++;
	}

	ifs.close();

	return n;
}
void Captian::read()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int rid;

	int i = 0;
	while (ifs >> id && ifs >> name && ifs >> rid)
	{
		Fighter* fighter = NULL;
		switch (rid)
		{
		case 1:
			fighter = new Commander(id, name, rid);
			break;
		case 2:
			fighter = new Fire(id, name, rid);
			break;
		case 3:
			fighter = new Feeder(id, name, rid);
			break;
		case 4:
			fighter = new Observer(id, name, rid);
			break;
		case 0:
			fighter = new You(id, name, rid);
			break;
		default:
			break;
		}
		this->m_ftArr[i] = fighter;
		i++;
	}

	ifs.close();
}
void Captian::show()
{
	if (this->ftEmpty)
	{
		cout << "你翻遍了身上的口袋，没能找出那本血迹斑斑的花名册。。。\n\n";
		return;
	}
	else if (m_ftNumb == 0)
	{
		cout << "花名册上一个编号都没有了。。。\n\n";
		return;
	}
	else
	{
		cout << "你从贴身衣兜里掏出了指战员塞过来的那本血迹斑斑的花名册\n\n"
			<< "你圈掉那些睡在泥泞下小伙子的名字后，还剩下" << this->m_ftNumb
			<< "个编号。。。\n\n";
		sclear();
		for (int i = 0; i < this->m_ftNumb; i++)
		{
			cout << i + 1 << "、 ";
			this->m_ftArr[i]->show_finfo();
		}
		cout << endl;
		sclear();
		cout << "战场上还有他们听你指挥！\n\n";
	}

	return;
}
void Captian::ftDel()
{
	if (this->m_ftNumb == 0)
	{
		cout << "没有花名册可没法让别人滚蛋！\n\n";
		return;
	}
	cout << "想起了自己远方的家人，你决定让某人滚蛋。。。\n\n";
	sclear();
	int id = 0;
	while (true)
	{
		cout << "（输入编号）\n";
		cin >> id;
		system("cls");
		if (cin.good())
		{
			int s = this->idSearch(id);
			if (s == -1)
			{
				cout << "编号" << id << "的小伙子或许已经睡在泥泞下了\n至少现在花名册里没有这个编号。。。\n\n";
				return;
			}
			else
			{
				for (int i = s; i < this->m_ftNumb - 1; i++)
				{
					this->m_ftArr[i] = this->m_ftArr[i + 1];
				}
				this->m_ftNumb--;
				this->save();
				cout << "尽管你让他滚蛋了，可最后是去是留还是他自己决定。。。\n\n";
				return;
			}
			sclear();
			break;
		}
		else
		{
			cin_error(0);
		}
	}
}
int Captian::idSearch(int id)
{
	int s = -1;
	for (int i = 0; i < this->m_ftNumb; i++)
	{
		if (this->m_ftArr[i]->f_id == id)
		{
			s = i;
			break;
		}
	}
	return s;
}
void Captian::ftSearch()
{
	if (this->m_ftNumb == 0)
	{
		cout << "没有花名册可没法知道战斗员编号！\n\n";
		return;
	}
	cout << "你忽然想确认一个战斗员的身份！\n\n";
	sclear();
	int id = 0;
	string name = "";
	int select = -1;
	while (true)
	{
		cout << "（选择查询方式）\n\n"
			<< "\t _________________________________\n"
			<< "\t| # |\t 输入标题数字执行操作\t  |\n"
			<< "\t|---|-----------------------------|\n"
			<< "\t| 1 |\t     通过编号查询   \t  |\n"
			<< "\t|---|-----------------------------|\n"
			<< "\t| 2 |\t     通过姓名查询   \t  |\n"
			<< "\t|---|-----------------------------|\n"
			<< "\t| 0 |\t       放弃查询    \t  |\n"
			<< "\t ---------------------------------\n\n";
		cin >> select;
		system("cls");
		if (cin.good())
		{
			switch (select)
			{
			case 1:
				while (true)
				{
					cout << "（输入编号）\n";
					cin >> id;
					system("cls");
					if (cin.good())
					{
						if (this->idSearch(id) == -1)
						{
							cout << "你的身边没有编号" << id << "的小伙子\n\n";
							return;
						}
						else
						{
							cout << "传令兵转眼的功夫就把他喊到了你身边\n\n这位战斗员向你汇报：\n\n";
							this->m_ftArr[this->idSearch(id)]->show_finfo();
						}
						sclear();
						cout << "你拍了拍他的肩膀，便让这个小伙子回到战斗岗位了。。。\n\n";
						return;
					}
					else
					{
						cin_error(0);
					}
				}
				break;
			case 2:
				while (true)
				{
					int n = 0;
					//创建临时动态数组储存查询值
					int* index = new int[1];
					int ltemp = 1;
					cout << "（输入姓名）\n";
					cin >> name;
					system("cls");
					//获取条件相符人员在战斗员数组中的下标数组
					for (int i = 0; i < this->m_ftNumb; i++)
					{
						if (name == this->m_ftArr[i]->f_name)
						{
							//条件相符人数增一
							n++;
							//将动态数组的最后一位赋值
							index[ltemp - 1] = i;
							//开辟新内存空间（长度较原动态数组增一以便存放新下标）
							int* newIndex = new int[n + 1];
							//拷贝原动态数组
							for (int j = 0; j < ltemp; j++)
							{
								newIndex[j] = index[j];
							}
							//清理原动态数组
							delete[] index;
							//更改原动态数组的指向
							index = newIndex;
							//动态数组长度标记变量增一
							ltemp = n + 1;
						}
					}
					if (n == 0)
					{
						cout << "你的身边没有名叫 " << name << " 的小伙子\n\n";
						delete[] index;
						index = NULL;
						return;
					}
					int itemp = 0;
					if (n == 1)
					{
						itemp = index[0];
						cout << "传令兵转眼的功夫就把他喊到了你身边\n\n这位战斗员向你汇报：\n\n";
						this->m_ftArr[itemp]->show_finfo();
						sclear();
						cout << "你拍了拍他的肩膀，便让这个小伙子回到战斗岗位了。。。\n\n";
						delete[] index;
						index = NULL;
						return;
					}
					if (n > 1)
					{
						cout << "居然有" << n << "个小伙子同名！\n\n"
							<< "他们一同赶到了你所在的位置\n\n这" << n
							<< "位战斗员向你汇报：\n\n";
						for (int t = 0; t < n; t++)
						{
							itemp = index[t];
							this->m_ftArr[itemp]->show_finfo();
						}
						sclear();
						cout << "你勉励了他们几句，便让小伙子们一同离开了。。。\n\n";
						delete[] index;
						index = NULL;
						return;
					}
				}
				break;
			case 0:
				cout << "考虑一番后，你还是决定没有必要让小伙子们跑来跑去了。。。\n\n";
				return;
				break;
			default:
				cout << "（重新输入）\n";
				break;
			}
		}
		else
		{
			cin_error(0);
		}
	}
}
void Captian::ftMod()
{
	if (this->m_ftNumb == 0)
	{
		cout << "没有花名册可没法人事变动！\n\n";
		return;
	}
	cout << "分析目前局势后，你决定对某个战斗员进行人事调整。。。\n\n";
	sclear();
	int id = 0;
	while (true)
	{
		cout << "（输入编号）\n";
		cin >> id;
		system("cls");
		if (cin.good())
		{
			int s = this->idSearch(id);
			if (s == -1)
			{
				cout << "花名册上没有编号" << id << "的战斗员可进行调整\n\n";
				return;
			}
			else
			{
				//创建新对象
				Fighter* fighter = NULL;
				//保存原数据
				int o_id = this->m_ftArr[s]->f_id;
				string o_name = this->m_ftArr[s]->f_name; 
				int o_rid = this->m_ftArr[s]->f_rid;
				//删除数组中对应的指针
				delete this->m_ftArr[s];
				//初始化新数据
				int newID = -1;
				string newName = "";
				int newRID = -1;

				while (true)
				{
					int select = -1;
					cout<< "（选择需要修改的内容）\n\n"
						<< "\t _________________________________\n"
						<< "\t| # |\t 输入标题数字执行操作\t  |\n"
						<< "\t|---|-----------------------------|\n"
						<< "\t| 1 |\t      战斗员编号   \t  |\n"
						<< "\t|---|-----------------------------|\n"
						<< "\t| 2 |\t      战斗员姓名   \t  |\n"
						<< "\t|---|-----------------------------|\n"
						<< "\t| 3 |\t      战斗员职责   \t  |\n"
						<< "\t|---|-----------------------------|\n"
						<< "\t| 4 |\t       修改完毕    \t  |\n"
						<< "\t|---|-----------------------------|\n"
						<< "\t| 0 |\t       放弃修改    \t  |\n"
						<< "\t ---------------------------------\n\n";
					cin >> select;
					system("cls");
					if (cin.good())
					{
						switch (select)
						{
						case 1:
							while (true)
							{
								cout << "（输入新编号）\n";
								cin >> newID;
								system("cls");
								if (cin.good())
								{
									if (newID == o_id)
									{
										cout << "你并没有改变这位战斗员的编号。。。\n\n";
										sclear();
										newID = -1;
										break;
									}
									for (int i = 0; i < this->m_ftNumb; i++)
									{
										if (newID == this->m_ftArr[i]->f_id)
										{
											cout << "该ID已被占用\n\n";
											sclear();
											break;
										}
									}
									cout << "完成！\n\n";
									sclear();
									break;
								}
								else
								{
									cin_error(0);
								}
							}
							break;
						case 2:
							cout << "（输入战斗员别名）\n";
							cin >> newName;
							system("cls");
							if (newName == o_name)
							{
								cout << "别名与原名重名。。。\n\n";
								sclear();
								newName = "";
								break;
							}
							cout << "完成！\n\n";
							sclear();
							break;
						case 3:
							while (true)
							{
								cout << "（输入战斗员新职责）\n\n"
									<< "\t _________________________________\n"
									<< "\t| # |\t 输入标题数字执行操作\t  |\n"
									<< "\t|---|-----------------------------|\n"
									<< "\t| 1 |\t       战斗组长   \t  |\n"
									<< "\t|---|-----------------------------|\n"
									<< "\t| 2 |\t        火力手    \t  |\n"
									<< "\t|---|-----------------------------|\n"
									<< "\t| 3 |\t        供弹手    \t  |\n"
									<< "\t|---|-----------------------------|\n"
									<< "\t| 4 |\t        观察手    \t  |\n"
									<< "\t|---|-----------------------------|\n"
									<< "\t| 0 |\t        你自己    \t  |\n"
									<< "\t ---------------------------------\n\n";
								cin >> newRID;
								system("cls");
								if (cin.good())
								{
									if (newRID == o_rid)
									{
										cout << "你并没有改变这位战斗员的岗位。\n\n";
										sclear();
										newRID = -1;
										break;
									}
									else if (newRID < 5 && newRID > -1)
									{
										cout << "完成！\n\n";
										sclear();
										break;
									}
									cout << "（重新输入）\n";
								}
								else
								{
									cin_error(0);
								}
							}
							break;
						case 4:
							if (newID == -1 && newName == "" && newRID == -1)
							{
								//删除case尾部break使其继续执行至case0
							}
							else
							{
								if (newID == -1)
								{
									newID = o_id;
								}
								if (newName == "")
								{
									newName = o_name;
								}
								if (newRID == -1)
								{
									newRID = o_rid;
								}
								switch (newRID)
								{
								case 1:
									fighter = new Commander(newID, newName, newRID);
									break;
								case 2:
									fighter = new Fire(newID, newName, newRID);
									break;
								case 3:
									fighter = new Feeder(newID, newName, newRID);
									break;
								case 4:
									fighter = new Observer(newID, newName, newRID);
									break;
								case 0:
									fighter = new You(newID, newName, newRID);
									break;
								default:
									break;
								}
								//更新数组
								this->m_ftArr[s] = fighter;
								//保存至外部文件
								this->save();
								cout << "下达命令后，你希望战士能够理解此次人事变动。。。\n\n";
								return;
								break;
							}
						case 0:
							newID = o_id;
							newName = o_name;
							newRID = o_rid;
							switch (newRID)
							{
							case 1:
								fighter = new Commander(newID, newName, newRID);
								break;
							case 2:
								fighter = new Fire(newID, newName, newRID);
								break;
							case 3:
								fighter = new Feeder(newID, newName, newRID);
								break;
							case 4:
								fighter = new Observer(newID, newName, newRID);
								break;
							case 0:
								fighter = new You(newID, newName, newRID);
								break;
							default:
								break;
							}
							this->m_ftArr[s] = fighter;
							this->save();
							cout << "你对目前队伍的人事情况很满意！\n\n";
							return;
							break;
						default:
							break;
						};
					}
					else
					{
						cin_error(0);
					}
				}
			}
			sclear();
			break;
		}
		else
		{
			cin_error(0);
		}
	}
}
void Captian::sort()
{
	int select = 2;
	while (true)
	{
		cout << "（选择排序方式）\n\n"
			<< "\t _________________________________\n"
			<< "\t| # |\t 输入标题数字执行操作\t  |\n"
			<< "\t|---|-----------------------------|\n"
			<< "\t| 1 |\t      按编号升序   \t  |\n"
			<< "\t|---|-----------------------------|\n"
			<< "\t|-1 |\t      按编号降序   \t  |\n"
			<< "\t|---|-----------------------------|\n"
			<< "\t| 0 |\t       放弃排序   \t  |\n"
			<< "\t ---------------------------------\n\n";
		cin >> select;
		system("cls");
		int t = 0;
		if(cin.good())
		{
			switch (select)
			{
			case 1:
				//选择排序
				for (int i = 0; i < this->m_ftNumb; i++)
				{
					int m = i;
					for (int j = i + 1; j < this->m_ftNumb; j++)
					{
						if (this->m_ftArr[m]->f_id > this->m_ftArr[j]->f_id)
						{
							//找出最小值
							m = j;
						}
					}
					//比较、替换
					if (i != m)
					{
						t = 1;
						Fighter* temp = this->m_ftArr[i];
						this->m_ftArr[i] = this->m_ftArr[m];
						this->m_ftArr[m] = temp;
					}
				}
				if(t == 1)
				{
					cout << "你按升序重新编排了花名册！\n（返回菜单查看）\n\n";
				}
				else
				{
					cout << "花名册已为升序编排格式！\n\n";
				}
				this->save();
				return;
				break;
			case -1:
				for (int i = 0; i < this->m_ftNumb; i++)
				{
					int m = i;
					for (int j = i + 1; j < this->m_ftNumb; j++)
					{
						if (this->m_ftArr[m]->f_id < this->m_ftArr[j]->f_id)
						{
							//找出最大值
							m = j;
						}
					}
					if (i != m)
					{
						t = 1;
						Fighter* temp = this->m_ftArr[i];
						this->m_ftArr[i] = this->m_ftArr[m];
						this->m_ftArr[m] = temp;

					}
				}
				if (t == 1)
				{
					cout << "你按降序重新编排了花名册！\n（返回菜单查看）\n\n";
				}
				else
				{
					cout << "花名册已为降序编排格式！\n\n";
				}
				this->save();
				return;
				break;
			case 0:
				cout << "时间紧迫，现在不是修改顺序的时候！\n\n";
				return;
				break;
			default:
				cout << "（重新输入）\n";
				break;
			}
		}
		else
		{
			cin_error(0);
		}
	}
}
void Captian::ftClear()
{
	int s = 0;
	while (true)
	{
		cout << "\t _______________________________________________\n"
			<< "\t|\t                             \t\t|\n"
			<< "\t|\t看着被炮弹犁过的泥泞，你决定。。。\t|\n"
			<< "\t|\t                             \t\t|\n"
			<< "\t|\t                             \t\t|\n"
			<< "\t|\t                             \t\t|\n"
			<< "\t|  (1)“是的!!!”    \t\t (0)“算了...” |\n"
			<< "\t _______________________________________________\n\n";
		cin >> s;
		system("cls");
		if (cin.good())
		{
			if (s == 1)
			{
				//存在文件即进行删除后创建空文件
				ofstream ofs(FILENAME, ios::trunc);
				ofs.close();
				//清空内部数组
				if (this->m_ftArr != NULL)
				{
					for (int i = 0; i < this->m_ftNumb; i++)
					{
						if (this->m_ftArr[i] != NULL)
						{
							//释放每一个非空对象
							delete this->m_ftArr[i];
							this->m_ftArr[i] = NULL;
						}
					}
					//释放数组
					delete[] this->m_ftArr;
					this->m_ftArr = NULL;
					//归零计数变量
					this->m_ftNumb = 0;
					//调整标识值
					this->ftEmpty = true;
					cout << "你受够了，这队伍爱谁带谁带！\n\n";
				}
				system("pause");
				exit(0);
			}
			else if (s == 0)
			{
				cout << "想起不久前才担在自己肩上责任，你还是选择了一往无前。。。\n\n";
				return;
			}
			cout << "（不做出选择也是一种选择。。。）\n\n";
			return;
		}
		else
		{
			cout << "error!\n\n";
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			return;
		}
	}
}