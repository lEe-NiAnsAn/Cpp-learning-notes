#include<iostream>
using namespace std;
#include<string>

//创建嵌套结构体
struct Caus
{
	float acc;	//精准度
	float atrk;	//暴击率
};

//一 创建结构体
struct Arms
{
	string name;	//名称
	int damage;		//伤害
	Caus pprity;	//属性	//嵌套结构体
}arm;//在此也可声明多个结构体变量

//打印输出结构体变量数据
//值传递
void printArm(Arms arm)
{
	cout << arm.name << "  伤害：" << arm.damage << endl;

	return;
}

//修改结构体变量数据
//地址传递
void changeArm(Arms* arm)
{
	string name;
	cout << "输入新名称：" << endl;
	cin >> name;
	int damage;
	cout << "请输入新伤害数值：" << endl;
	cin >> damage;
	arm->name = name;
	arm->damage = damage;
	cout << endl;

	return;
}

//打印输出结构体变量数据
//使用const修饰
//地址传递
void cprintArm(const Arms* arm)
{
	//不可更改：arm->damage = 100;
	cout << arm->name << "  伤害：" << arm->damage << endl;

	return;
}

int main()
{
	//结构体允许用户自建并存储不同的数据类型
#pragma region 二 创建具体对象
	//方法一
	struct Arms arm1;
	arm1.name = "水果刀";
	arm1.damage = 23;
	cout << arm1.name << "  伤害：" << arm1.damage << endl;
	//创建结构体变量时struct关键字可省略
	//方法二
	Arms arm2 = { "撬棍",42 };	//初始化顺序须与定义结构体时一致
	cout <<arm2.name << "  伤害：" << arm2.damage << endl;
	//方法三
	//定义结构体时声明结构体变量
	arm.name = "拳头";
	arm.damage = 5;
	cout <<arm.name << "  伤害：" << arm.damage << "\n\n";
#pragma endregion

#pragma region 三 结构体数组
	//创建结构体数组
	struct Arms armsArray[2] = {
		{"柴刀",56},
		{"镰刀",15}
	};
	//更改结构体数组元素
	armsArray[1].name = "碎酒瓶";
	//遍历结构体数组
	for (int i = 0; i < 2; i++) {
		cout << armsArray[i].name << "  伤害：" << armsArray[i].damage << endl;
	}

	cout << "\n\n";
#pragma endregion

#pragma region 四 结构体指针
	Arms* p_arm1 = &arm1;
	//使用指针访问结构体变量中的数据(->)
	cout << p_arm1->name << "  伤害：" << p_arm1->damage << endl;

#pragma endregion

#pragma region 五 嵌套结构体
	Arms arm3;
	arm3.name = "PVC弓";
	arm3.damage = 45;
	//初始化嵌套结构体中元素
	arm3.pprity.acc = 0.43f;
	arm3.pprity.atrk = 0.16f;
	cout << arm3.name 
		<< "  伤害：" << arm3.damage 
		<< "  精准度：" << arm3.pprity.acc 
		<< "  暴击率" << arm3.pprity.atrk <<"\n\n";
#pragma endregion

#pragma region 六 结构体函数参数
	//值传递
	printArm(arm1);
	cout << endl;
	//地址传递
	changeArm(&arm1);
	printArm(arm1);

	cout << endl;
#pragma endregion

#pragma region 七 结构体中的const
	//使用地址传递可避免拷贝庞大的结构体变量，节省内存
	//const即可用于防止误操作
	cprintArm(&arm2);

	cout << "\n\n";
#pragma endregion


	system("pause");

	return 0;
}