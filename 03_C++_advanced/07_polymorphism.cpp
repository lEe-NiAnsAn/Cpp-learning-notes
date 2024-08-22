#include<iostream>
using namespace std;

#pragma region 多态的基本概念
//1、静态多态：函数重载与运算符重载（复用函数名）
//静态多态函数地址早绑定——>编译阶段确定函数地址
//2、动态多态：派生类与虚函数实现运行时多态
//动态多态函数地址晚绑定——>运行阶段确定函数地址
class Base01
{
public:
	void func01() {
		cout << "父类一成员函数调用" << endl;
	}
};
class Base02
{
public:
	//通过virtual关键字创建虚函数实现地址晚绑定
	virtual void func02() {
		cout << "父类二成员函数调用" << endl;
	}
};
//v-virtual f-function ptr-pointer
//创建虚函数后类内将包含vfptr，该指针指向虚函数表(vftable)
//vftable内部记录该类的虚函数地址
class Son01 : public Base01
{
public:
	void func01() {
		cout << "子类一成员函数调用" << endl;
	}
};
class Son02 : public Base02
{
public:
	//因为继承，子类继承父类成员所有属性
	//故子类virtual关键字可有可无
	virtual void func02() {
		cout << "子类二成员函数调用" << endl;
	}//当子类重写父类虚函数时，则子类中vftable将被覆盖
	//此时vftable将记录子类的虚函数地址，而非父类虚函数地址
};

//函数地址早绑定
void dofunc01(Base01& b1)
{
	b1.func01();//绑定Weapon类
}
//函数地址晚绑定
void dofunc02(Base02& b2)
{
	b2.func02();//绑定传入的对象所属的类
}
//动态多态实现：
//1、存在继承关系
//2、子类需重写父类虚函数（同名同参对象函数）
//3、父类对象的指针(或引用)指向子类的对象——>形参：父类对象指针 / 实参：子类对象
//——>此时将调用子类的vftable，即指向子类虚函数的vfptr，故调用子类成员函数

void test11()
{
	Son01 s1;
	//调用函数为父类成员函数
	dofunc01(s1);//C++允许父类子类间非强制的自动类型转化
	//调用函数为子类成员函数
	Son02 s2;
	dofunc02(s2);
	//未使用虚函数的父类内存等于空类
	cout << "父类Base01所占内存大小为" << sizeof(Base01) << endl;
	//使用虚函数的父类内存为虚函数指针大小
	cout << "父类Base02所占内存大小为" << sizeof(Base02) << endl;
}
#pragma endregion

#pragma region 多态案例：计算器
//编程开闭原则：对扩展开放，对修改关闭
//实现计算器抽象类
class Calculator
{
public:
	int m_n1 = 0;
	int m_n2 = 0;
	virtual int result() {
		return 0;
	}
};
//加法计算器类
class Add : public Calculator
{
public:
	virtual int result() {
		return m_n1 + m_n2;
	}
};
//减法计算器类
class Sub : public Calculator
{
public:
	virtual int result() {
		return m_n1 - m_n2;
	}
};
//乘法计算器类
class Mult : public Calculator
{
public:
	virtual int result() {
		return m_n1 * m_n2;
	}
};
//除法计算器类
class Div : public Calculator
{
public:
	virtual int result() {
		return m_n1 / m_n2;
	}
};
//创建传参输出函数
void calcu_func(int n1, string op, int n2, Calculator*& cp)
{
	cp->m_n1 = n1;
	cp->m_n2 = n2;
	cout << cp->m_n1 << " " << op << " "
		<< cp->m_n2 << " = "
		<< cp->result() << endl;
	delete cp;//堆区数据及时销毁
}
void test12()
{
	//父类指针指向子类对象
	//1、加法
	Calculator* cp = new Add;
	calcu_func(10, "+", 2, cp);	
	//2、减法
	cp = new Sub;
	calcu_func(10, "-", 2, cp);
	//3、乘法
	cp = new Mult;
	calcu_func(10, "*", 2, cp);
	//4、除法
	cp = new Div;
	calcu_func(10, "/", 2, cp);
}
#pragma endregion

#pragma region 纯虚函数与抽象类
//多态中父类虚函数往往实现毫无意义，通常通过子类重写调用
//故可将其改造为纯虚函数
//一旦拥有纯虚函数的类即为抽象类
//注意：	1、抽象类不可实例化
//		2、抽象类的子类必须重写父类纯虚函数，否则亦为抽象类

class abstrct
{
public:
	//创建纯虚函数
	virtual void ifunc() = 0;
};
#pragma endregion

#pragma region 虚析构和纯虚析构
//在使用多态时对于子类仅调用其构造函数，而不调用析构函数(对于父类则均将调用)
//若子类于堆区开辟了内存，需使用虚析构或纯虚析构在多态中调用子类析构函数释放堆区内存
//虚析构与纯虚析构函数均需具体实现代码
//包含纯虚析构函数的类亦为抽象类

class Base03
{
public:
	Base03() {
		cout << "Base03的构造函数" << endl;
	}
	//创建虚析构函数
	//virtual ~Base03() {
	//	cout << "Base03的析构函数" << endl;
	//}
	//纯虚析构函数声明
	virtual ~Base03() = 0;
	virtual void ifunc03() = 0;
};
//父类外纯虚析构函数的实现
Base03:: ~Base03()
{
	cout << "Base03的纯虚析构函数" << endl;
}
class Son03 : public Base03
{
public:
	Son03(int a) {
		m_a = new int(a);//于堆区开辟内存储存数据
		cout << "Son03的构造函数" << endl;
	}
	//父类使用虚析构后将调用子类析构函数
	//子类virtual关键字为非必须的
	virtual ~Son03() {
		if (m_a != NULL) {
			cout << "Son03的析构构造函数" << endl;
			delete m_a;
			m_a = NULL;
		}
	}
	virtual void ifunc03() {
		cout << "访问Son03堆区数据：" << *m_a << endl;
		cout << "Son03的复写成员函数调用" << endl;
	}
	int* m_a;//使用指针维护创建于堆区的数据

};

void test13()
{
	Base03* b3 = new Son03(2);
	b3->ifunc03();
	delete b3;
}
#pragma endregion


int main7()
{
	test11();
	cout << endl;
	test12();
	cout << endl;
	test13();
	cout << endl;

	system("pause");

	return 0;
}