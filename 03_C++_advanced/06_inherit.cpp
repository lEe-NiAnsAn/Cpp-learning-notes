#include<iostream>
using namespace std;

#pragma region 继承的基础语法
class Root	//父类
{
public:
	void scenes() {
		cout << "基础场景\n";
	}
	void element() {
		cout << "基础元素\n";
	}
	void effect() {
		cout << "基础效果\n";
	}
};

class Node : public Root	//子类公共继承
{
public:
	void object() {
		cout << "Node1基础物体\n\n";
	}
};

void test1()
{
	Node node1;
	node1.effect();
	node1.element();
	node1.scenes();
	node1.object();

}
#pragma endregion

#pragma region 继承方式

//1、公共继承:公共———>公共；保护———>保护；私有—X—>不可访问
//2、保护继承:公共———>保护；保护———>保护；私有—X—>不可访问
//3、私有继承:公共———>私有；保护———>私有；私有—X—>不可访问

//继承的对象模型：
//可在开发人员命令提示工具(Developer Command Prompt)中查看类具体的对象模型
//1、跳转盘符（D:）
//2、跳转文件路径（cd D:\user\Desktop\SourceCode\C++\...）
//3、查看文件列表（dir）
//4、查看（cl /d1 reportSingleClassLayout类名 文件名）
class Father
{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};
class Son : public Father
{
public:
	int d;
};
class Grandson : public Son
{
public:
	int e;
};
//父类中所有成员无论子类为何种继承方式均被包含至子类内存中
//父类中私有成员也被继承至子类
//一个类继承其所有父类
void test02()
{
	cout << "Father类所占内存为" << sizeof(Father) << "\n";
	cout << "Son类所占内存为" << sizeof(Son) << "\n";
	cout << "Grandson类所占内存为" << sizeof(Grandson) << "\n\n";
}

//继承中构造与析构函数
class Base
{
public:
	Base() {
		cout << "Base的构造函数\n";
	}
	~Base() {
		cout << "Base的析构函数\n";
	}
};
class Son_b : public Base
{
public:
	Son_b() {
		cout << "Son_b的构造函数\n";
	}
	~Son_b() {
		cout << "Son_b的析构函数\n";
	}
};

void test03()
{
	Son_b s_b1;
	//先构造父类
	//调用父类构造函数后才构造子类
	cout << "\n\n";
}
#pragma endregion 

#pragma region 继承中同名问题
//调用父类成员需声明父类作用域
class Bases
{
public:
	Bases() {
		m_a = 1;
	}
	void t() {
		cout << "父类成员函数\n";
	}
	void t(int a) {
		cout << "父类重载成员函数\n";
	}
	int m_a;
	static int m_b;
};
//类外声明同名静态成员变量需声明作用域
int Bases::m_b = 2;
//子类成员可直接调用
class Sons : public Bases
{
public:
	Sons() {
		m_a = 10;
	}
	void t() {
		cout << "子类成员函数\n";
	}
	int m_a;
	static int m_b;
};
int Sons::m_b = 20;
//若子类中存在父类的同名函数，则同名父类函数无论是否重载均隐藏，欲调用需声明作用域
void test04()
{
	Sons s_s;
	cout << "子类调用父类成员函数：";
	s_s.Bases::t();
	cout << "子类调用父类重载成员函数：";
	s_s.Bases::t(2);
	cout << "子类调用子类成员函数：";
	s_s.t();
	cout<< "子类调用父类成员变量：" << s_s.Bases::m_a
		<< "\n子类调用子类成员变量：" << s_s.m_a << "\n"
//通过对象访问所属类静态成员无须声明作用域，访问其上层类需声明作用域
		<< "子类对象调用父类静态成员变量：" << s_s.Bases::m_b
		<< "\n子类对象调用子类静态成员变量：" << s_s.m_b << "\n";
//通过类名访问需使用作用域进行调用，访问上层类需双层定义域
	cout << "子类通过类名调用父类同名静态成员变量：" 
		<< Sons::Bases::m_b << "\n"
		 << "子类通过类名调用子类同名静态成员变量："
		<< Sons::m_b << "\n\n";
//调用同名静态成员函数同理
}
#pragma endregion

#pragma region 多继承
//单个子类继承多个父类
//多继承可能引起父类同名成员问题，需要声明作用域区分
class father01
{
public:
	father01() {
		m_a = 1;
	}
	int m_a;
};
class father02
{
public:
	father02() {
		m_a = 2;
	}
	int m_a;
};

class Son_d :public father01, public father02
{
public:
	Son_d() {
		m_a = 0;
	}
	int m_a;
};

void test05()
{
	Son_d c;
	cout << "拥有两父类的子类所占内存：" << sizeof(c) << endl
		<< "子类中的同名成员变量：" << c.m_a << "\n"
		<< "父类一中的同名成员变量：" << c.father01::m_a << "\n"
		<< "父类二中的同名成员变量：" << c.father02::m_a << "\n\n";
}
#pragma endregion

#pragma region 菱形继承
//两派生类继承同一基类，且另一子派生类同时继承此两派生类
//问题：	1、同名成员访问
//		2、子派生类重复继承两派生类中继承的相同基类成员及同名成员
class base_c
{
public:
	/*base_c() {
		m_a = 0;
	}*/
	int m_a;
};
//使用虚继承关键字virtual解决问题
//此时son01，son02继承方式为虚继承,base_c称为虚基类
class son01 :virtual public base_c {};
class son02 : virtual public base_c {};

class g_son :public son01, public son02{};

void test06()
{
	g_son gs;
	gs.base_c::m_a = 0;
	gs.son01::m_a = 10;
	gs.son02::m_a = 20;
	//两派生类与基类中共享一个m_a成员
	//修改任一派生类中m_a将同时影响另一派生类与基类下m_a的调用
	cout << "菱形继承子派生类内存：" << sizeof(gs) << "\n"
	//此时内存占用为基类m_a，派生类一m_a的vbptr指针，派生类二m_a的vbptr指针	
	//vbptr指向vbtable
	//v-virtual虚、b-base基类、ptr-pointer指针、table-表
	//虚基类表记录了内存地址的偏移量，派生类vbptr附加偏移量后即指向基类m_a
		<< "子派生类访问派生类一所构造继承的基类成员变量："
		<< gs.son01::m_a << "\n"
		<< "子派生类访问派生类二所构造继承的基类成员变量："
		<< gs.son02::m_a << "\n"
	//此时基类与二派生类共享m_a，不会引起不明确的情况
		<< "子派生类访问基类成员变量：" << gs.m_a << "\n\n";
}
#pragma endregion


int main6()
{
	test1();
	test02();
	test03();
	test04();
	test05();
	test06();

	system("pause");

	return 0;
}