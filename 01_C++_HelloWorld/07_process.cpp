#include<iostream>
using namespace std;
#include<ctime>

int main7()
{
	//程序流程
	
	//一 顺序结构
	//程序按顺序执行，不发生跳转


	#pragma region 二 选择结构
	int num0 = 0;
	cout << "你认为人类24小时内应该进食的次数：" << endl;
	cin >> num0;
	cout << endl;
		#pragma region 单行if语句
	if (num0 == 3)
	{
		cout << "一日三餐\n" << endl;
	}
		#pragma endregion

		#pragma region 多行if语句
	if (num0 < 0)
	{
		cout << "无效的次数\n" << endl;
	}
	else
	{
		cout << "有效的次数\n" << endl;
	}
		#pragma endregion

		#pragma region 多条件if语句
	if (num0 > 3)
	{
		cout << "次数是否过多？\n" << endl;
	}
	else if (num0 == 3)
	{
		cout << "赞同\n" << endl;
	}
	else if(num0 < 3 && num0 > 0)
	{
		cout << "次数是否过少？\n" << endl;
	}
	else if (num0 == 0)
	{
		cout << "大概率会导致人类死亡\n" << endl;
	}
	else
	{
		cout << "请检查输入是否正确\n" << endl;
	}
		#pragma endregion
	
		#pragma region 嵌套if语句
	if (num0 > 3)
	{
		if (num0 > 5) 
		{
			cout << "进食过于频繁\n" << endl;
			if (num0 > 6)
			{
				cout << "少食多餐并不是指如此多的进食次数\n" << endl;
			}
		}
	}
	else if (num0 == 3)
	{
		cout << "符合大多数人类的进食规律\n" << endl;
	}
	else if (num0 < 3 && num0 > 0)
	{
		if (num0 == 2)
		{
			cout << "古代人类或许符合此进食规律\n" << endl;
		}
		if (num0 == 1)
		{
			cout << "一日一餐并不是健康进食习惯\n" << endl;
		}
	}
	else if (num0 == 0)
	{
		cout << "除非使用其他手段获取营养\n" << endl;
	}
	else
	{
		cout << "谢谢\n" << endl;
	}

	cout << endl;
		#pragma endregion

		#pragma region 三目运算符
	//表达式1 ? 表达式2 : 表达式3;
	//若1为真，执行2并返回2
	//若1为假，执行3并返回3
	int n0 = 0;
	int n1 = 1;
	cout << "键入表达式1的值" << endl;
	cin >> n1;
	int n2 = 2;
	int n3 = 3;
	n0 = n1 == 2 ? n2 : n3;
	cout << "输出的是表达式" << n0 << "\n" << endl;
	//三目运算返回值为变量，因此可继续赋值

		#pragma endregion

		#pragma region switch语句
	int sw_num = 0;
	cout << "请为最近上映的一部电影评分\n" ;
	cout << "分数应为 0 ~ 5 的整数" << endl;
	cin >> sw_num;
	switch (sw_num)
	{
	case 5:
		cout << "你给出了最高分！\n";
		break;
	case 4:
		cout << "你给出了四分的高分！\n";
		break;
	case 3:
		cout << "你给出了中等评分！\n";
		break;
	case 2:
		cout << "你给出了两分的低分！\n";
		break;
	case 1:
		cout << "你给出了很低的评分！\n";
		break;
	case 0:
		cout << "你给出了最低分！\n";
		break;
	default:
		cout << "无效评分" << endl;
		break;
	}
	//若无break则程序将继续执行下一case内语句
	cout << endl;
		#pragma endregion

	#pragma endregion


	#pragma region 三 循环结构
	int i = 0;
	srand((unsigned int)time(NULL));
	//此语句需要头文件 #include<ctime>
	//加入此语句后便可使rand()随时间变化挑选序列中的数，而不是以调用次数为准
		#pragma region while循环语句
	cout << "随机输出一到十个从零开始的整数\n";
	int rn = rand() % 10 + 1;
	//rand()函数会生成0~MAX中随机一个数，%取模后则等同于改变了其生成范围（上述代码示例中“ %10 ”即为0~10）（伪随机数）
	//若无srand语句，rand()只会按固定序列生成数，程序中第一次调用rand()生成的数永远为同一个数(上述代码%后则为42)
	while (i <= rn)
	{
		cout << i << "\t";
		i++;
	}
	cout << "\n";

	cout << endl;
		#pragma endregion

		#pragma region do...while循环语句
	//与while循环不同之处为该语句会先进行一次循环再进行循环判断
	cout << "再次输出\n";
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
		
		#pragma region for循环
	cout << "再次输出\n";
	for (i = 0; i <= rn; i++)
	{
		cout << i << "\t";
	}
	cout << "\n";
	
	cout << endl;
		#pragma endregion

		#pragma region 嵌套循环
	cout << "打印7*7星图\n";
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


	#pragma region 四 跳转语句
		#pragma region break语句
	//1、在switch中终止case并跳出switch
		//用法见 “二 选择结构\switch语句”
	//2、在循环结构中跳出所在级循环语句
	cout << "打印直角星图\n";
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

		#pragma region continue语句
	//在循环语句中跳过本次循环并直接执行下次循环
	cout << "再次打印\n";
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

		#pragma region goto语句
	//无条件跳转到指定标记处
	cout << "打印5*5星图\n";
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