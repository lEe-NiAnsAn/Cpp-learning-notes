#include<iostream>
using namespace std;
#include "point.h"

const double Pi = 3.14;

#pragma region 一 类的封装
	#pragma region 类的定义
//类若无声明默认为私有		//结构体无声明则默认为公共
class Circle
{//1、公共权限：允许类内外访问
public:		
	//2、(成员)属性
	int m_r = 1;
	//3、(成员)方法
	double m_perimeter() {
		return 2 * m_r * Pi;
	}

//保护权限：允许类内访问,允许子类访问保护内容
protected:
	int m_loca_x = 1;
	int m_loca_y = 1;

//私有权限：仅允许类内访问，不允许子类访问私有内容
private:
	string m_color = "white";
};
	#pragma endregion

	#pragma region 私有化成员属性
//防止随意修改成员属性
class Squre
{
private:
	int m_len = 1;			//边长
	bool m_solid = true;	//实心
	string m_color = "red";	//颜色

public:
	//可读可写
	void m_setLen(int len) {
		if (len < 0) {		//检查数据有效性
			cout << "请输入正整数\n\n";
			return;
		}
		m_len = len;
	}
	int m_showLen() {
		return m_len;
	}
	//只读
	bool m_show() {
		if (m_solid == true) {
			cout << "该正方形边长是实心的" << "\n\n";
		}
		else{
			cout << "该正方形边长是空心的" << "\n\n";
		}

		return m_solid;
	}
	//只写
	void m_setColor(string color ) {
		m_color = color;
	}
	//计算面积
	int m_area() {
		return m_len * m_len;
	}

};
	#pragma endregion

	#pragma region 类的分文件定义
//1、于头文件中添加.h文件声明类以及成员
//2、于源文件中添加.cpp文件实现成员函数
//3、包含头文件即可使用类
class Distane
{
public:
	//使用另一类成员作为参数
	void set_p1(Point p1) {
		m_p1 = p1;
	}
	void set_p2(Point p2) {
		m_p2 = p2;
	}
	//计算距离的平方
	int func_lon() {
		return (m_p1.get_x() - m_p2.get_x()) * (m_p1.get_x() - m_p2.get_x()) +
			(m_p1.get_y() - m_p2.get_y()) * (m_p1.get_y() - m_p2.get_y());
	}
	void show() {
		m_lon = func_lon();
		cout << "两点距离的平方为" << m_lon << "\n\n";
	}

private:
	int m_lon;
	//类允许另一类的对象作为成员
	Point m_p1;
	Point m_p2;
};
	#pragma endregion

#pragma endregion

#pragma region 二 对象的初始化与清理
//对象的初始化与清理为编译器强制事项，需要初始化对象或变量，并及时清理
//(当定义一个类后，C++将自动生成三个函数：构造、析构、拷贝构造函数）
//(拷贝构造函数：对属性进行拷贝,非空实现)
	#pragma region 构造函数与析构函数的定义
//编译器将自动调用对应函数，若未主动提供，编译器则会自动提供"空实现"的构造、析构函数
class Test01
{
public:			//位于公共权限下
	//1、构造函数：在创建对象时自动调用一次为其初始化（可填写参数、发生重载）
	Test01()//函数名与类名一致，无须声明函数类型(void)
	{
		cout << "Test01类的构造函数\n";
	}			//无返回值

	//2、析构函数：在对象销毁前自动执行一次清理工作（不可填写参数、发生重载）
	~Test01()	//函数名为"~类名"，无须声明函数类型(void)
	{
		cout << "Test01类的析构函数\n\n";
	}			//无返回值

};

void test01()
{
	Test01 t;

	return;
}
	#pragma endregion

	#pragma region 构造函数的分类及调用
class Test02
{
public:	
//普通构造
	Test02() {	//无参构造（默认构造）
		m_numb = 0;
		cout << "Test02类的无参构造函数\n";
	}
	Test02(int i) {	//有参构造
		m_numb = i;
		cout << "Test02类的有参构造函数\n";
	}
//拷贝构造
	Test02(const Test02& t) {	//通过已有对象拷贝新对象
		m_numb = t.m_numb;			//拷贝所有成员属性
		cout << "Test02类的拷贝构造函数\n";
	}
//构造函数调用规则：
//1、若主动定义有参构造函数，则C++不提供默认构造函数，但仍提供默认拷贝构造函数
//(即在未主动定义拷贝构造函数时进行同拷贝构造函数的操作，C++将自动提供默认拷贝构造函数，进行值拷贝)
//(此时若使用无参构造的语句创建对象将报错)
//2、若主动定义了拷贝构造函数，则C++不会自动提供任何构造函数

	int out() {
		return m_numb;
	}

	~Test02() {
		cout << "Test02类的析构函数\n\n";
	}
private:
	int m_numb;
};

void test02_1(Test02 t)
{
	return;
}
Test02 test02_2()
{
	Test02 t;
	return Test02 (t);
}
#pragma endregion

	#pragma region 深拷贝与浅拷贝
//未自定拷贝构造函数的浅拷贝
class Test03
{
public:
	Test03() {
		m_numb = 0;
		m_pn = NULL;
		cout << "Test03类的无参构造函数\n";
	}
	Test03(int numb) {
		m_numb = numb;
		m_pn = NULL;
		cout << "Test03类的有参构造函数一\n";
	}
	Test03(int numb, int pn) {
		m_numb = numb;
		m_pn = new int(pn);	//在堆区开辟内存存放m_pn
		cout << "Test03类的有参构造函数二\n";

	}

	~Test03() {
		if(m_pn !=NULL){	//判断堆区m_pn是否存在
			delete m_pn;	//清理释放堆区内m_pn
			m_pn = NULL;	//将m_pn置空，防止野指针出现导致意外
		}
		cout << "Test03类的析构函数\n\n";
	}

	int m_numb;
	int* m_pn;
};

//自定拷贝构造函数的深拷贝
class Test04
{
public:
	Test04(int numb, int pn) {
		m_numb = numb;
		m_pn = new int(pn);	
		cout << "Test04类的有参构造函数\n";
	}
	Test04(const Test04& t) {
		m_numb = t.m_numb;
		m_pn = new int(*t.m_pn);	//重新在堆区开辟内存
		cout << "Test04类的拷贝构造函数\n";
	}

	~Test04() {
		if (m_pn != NULL) {	
			delete m_pn;	
			m_pn = NULL;	
		}
		cout << "Test04类的析构函数\n\n";
	}

	int m_numb;
	int* m_pn;
};


	#pragma endregion

	#pragma region 初始化列表
//用于初始化成员属性
class Test05
{
public:
	//m_t(0) 等价于 Test02 t = 0，调用Test02隐式构造函数创建对象作为Test05成员
	Test05():m_num1(0), m_num2(0), m_num3(0), m_t(0)	//初始化列表 
	{	
		cout << "Test05类的无参构造函数\n";
	}
	Test05(int num1, int num2, int num3, int t) //此处因先构造Test02对象已有m_t，故无须传入Test02类值
		:m_num1(num1), m_num2(num2), m_num3(num3), m_t(t){
		cout << "Test05类的有参构造函数\n";			
	}//运用初始化列表后无需在构造函数的实现内赋值(一一对应)
	Test05(const Test05& t) {
		m_num1 = t.m_num1;
		m_num2 = t.m_num2;
		m_num3 = t.m_num3;
		cout << "Test05类的拷贝构造函数\n";
	}

	~Test05() {
		cout << "Test05类的析构函数\n\n";
	}
	void show() {
		cout << "num1=" << m_num1
			<< "\tnum2=" << m_num2 
			<< "\tnum3=" << m_num3 
			<< "\tt=" << m_t.out()<< "\n\n";
	}

private:
	int m_num1;
	int m_num2;
	int m_num3;
	Test02 m_t;
};

	#pragma endregion

	#pragma region 静态成员
//在成员属性、方法前加static关键字即为静态成员
//静态成员属于类本身，不属于某一对象
class Test06
{
public:
	Test06() {
		cout << "Test06类的无参构造函数\n";
	}
	Test06(const Test06& t) {
		cout << "Test06类的拷贝构造函数\n";
	}

	void return_mB(int b) {
		mB = b;
		show_mB();
	}

	void return_mA(int a) {
		mA = a;
		show_mA();
	}

//静态成员函数
	//1、所有成员共享一个函数
	//2、静态成员函数仅可访问静态成员变量
	static void show_mB() {
		cout << "mB=" << mB << endl;
	}
	//3、拥有访问权限属性

	~Test06() {
		cout << "Test06类的析构函数\n\n";
	}

//静态成员变量：
	//1、所有对象共享一份数据（修改同步）
	//2、在编译阶段分配内存（程序运行前的全局区）
	//3、类内声明、类外初始化
	static int mA;
	//4、拥有访问权限属性
private:
	static int mB;

	static void show_mA() {
		cout << "静态成员函数访问mA=" << mA << endl;
	}
};
int Test06::mA = 1;		//类外初始化操作，需声明作用域，否则编译器会将其视为全局变量
int Test06::mB = 10;	//类外无法直接访问
	#pragma endregion

#pragma endregion

#pragma region 三 类的特性

	#pragma region this指针
//空类创建时的空对象依然占有一字节内存，目的为区分其所占内存地址
class Test07
{
};
//拥有非静态成员变量的类的对象占有的内存仅为非静态成员变量所占内存大小
//静态成员与非静态成员函数均不计入对象的内存大小
//无非静态成员变量的类的对象所占内存等于空对象内存大小
class Test08
{
	int m_v; //非静态成员变量属于对象
	void m_func() {} //非静态成员函数不属于对象
	//静态成员函不属于对象
	static int m_s_v;
	static void m_s_func() {} 
};
//非静态成员函数仅生成一份函数实例，供所有同类对象调用

class Test09
{
public:
	Test09() {
		num = 1;
		cout << "Test09类的无参构造函数\n";
	}
//this指针为指针常量
//this指针指向被调用的非静态成员函数所属的对象
//this指针隐含于每一非静态成员函数，无须定义可直接使用
	//1、区分同名形参与成员变量
	Test09(int num) {
		this->num = num; //this->num即为对象内成员num，而非形参num
		cout << "Test09类的有参构造函数\n";
	}
	//2、在非静态成员函数中使用“return* this;”返回对象本身进行修改
	//需要返回本身的引用Test09&，否则将返回拷贝值，无法更改本身的值
	Test09& m_add(Test09& t) {	//使用引用节约内存
		this->num += t.num;	//传入另一对象并将其num值与自身num相加

		return*this;	//返回类型为对象的引用，
	}

	void show() {
		cout << "num=" << num << endl;
	}

private:
	int num;
};

class Test10
{
public:
	Test10() {
		m_num = 1;
		cout << "Test10类的无参构造函数\n";
	}
	void show() {
		cout << "Test10的show函数\n";		//未调用成员变量的成员函数
	}
	void v_show() {
		cout << "m_num=" << m_num << endl;	//调用成员变量的成员函数
	}

private:
	int m_num;
};
	#pragma endregion

	#pragma region const修饰成员
//常函数：
//1、常函数内不可修改成员属性
//2、常函数即可修改加上mutable关键字后的成员属性
class Test11
{
public:
	Test11() {
		m_a = 1;
		m_b = 10;
	}
	//常函数的声明
	void c_show() const //此时该函数内调用成员属性相当于“const Test11* const this;”，不可修改this的指向与地址
	{
		//非法：this->m_a = 1;	//this指针为隐含
		m_b = 2;
	}

	void return_b(int b) {
		m_b = b;
		cout << "m_b=" << m_b << endl;
	}

	int m_a;
	mutable int m_b;	//特殊变量
};
	#pragma endregion

	#pragma region 友元
//使得类外的函数或类等访问私有成员
class Test12;
//友元类
class Test_f
{
public:
	Test_f();
	void visit();

private:
	Test12* t;
};
//友元成员函数
class Test_frind
{
public:
	Test_frind();
	void f_visit();

private:
	Test12* t;
};

class Test12
{
	//1、类作友元
	friend class Test_f;
	//2、成员函数作友元
	friend void Test_frind::f_visit();
	//3、全局函数作友元
	friend void f_func(const Test12& t);

public:
	Test12();
	int m_publ;
//private:
	int m_priv;
};

//友元全局函数
void f_func(const Test12& t)
{
	cout << "公共成员访问：" << t.m_publ << endl;
	cout << "私有成员访问：" << t.m_priv << "\n\n";
}

//类外实现成员方法
Test12::Test12()
{
	m_publ = 1;
	m_priv = 10;
	cout << "Test12类的无参构造函数\n";
}
Test_f::Test_f() {
	t = new Test12;	//new一个指向Test12类的对象的指针，调用Test12的构造函数
	cout << "Test_f类的无参构造函数\n";
}
void Test_f::visit() {
	cout << "公共成员访问：" << t->m_publ << endl;
	cout << "私有成员访问：" << t->m_priv << "\n\n";
}
Test_frind::Test_frind() {
	t = new Test12;
	cout << "Test_frind类的无参构造函数\n";
}
void Test_frind::f_visit()
{
	cout << "公共成员访问：" << t->m_publ << endl;
	cout << "私有成员访问：" << t->m_priv << "\n\n";
}
	#pragma endregion

#pragma endregion

int main4()
{
#pragma region 实例化类的对象
	Circle c1;	//声明
	c1.m_r = 2;	//初始化
	cout << "c1的周长为" << c1.m_perimeter() << "\n\n";//调用类中函数

	Squre s1;
	s1.m_setLen(2);		//写入边长
	cout << "s1的边长为" << s1.m_showLen() << "\n\n";	//读取边长
	bool s1_solid = s1.m_show();		//读取实心
	s1.m_setColor("blue");				//写入颜色
	int s1_area = s1.m_area();			//计算面积
#pragma endregion

#pragma region 分文件类的调用
	//调用Point类
	Point p1; Point p2;
	p1.set_x(1); p1.set_y(1);
	p2.set_x(4); p2.set_y(3);
	//调用Distance类
	Distane d1;
	d1.set_p1(p1); d1.set_p2(p2);
	d1.show();
#pragma endregion

#pragma region 对象的构造与析构
	Test01 t1;	//栈中数据，main函数结束销毁
	cout << endl;
	test01();	//栈中数据，test01函数结束销毁
//不同构造函数的调用
	//1、括号法
	Test02 t2;		//无参调用(注意：无须括号,否则编译器则会将其视为函数的声明）
	Test02 t3(10);	//有参调用
	Test02 t4(t3);	//拷贝调用
	//2、显示法
	Test02 t5 = Test02(20);	//有参调用
	Test02 t6 = Test02(t5);	//拷贝调用
	//Test02(20)、Test02(t5)为匿名对象，执行结束后系统将立即回收
	//(注意:请勿使用拷贝调用初始化匿名对象——>“Test02(t5);”等价于“Test02 t5;”)
	//3、隐式转换法（有时会出现bug）
	Test02 t7 = 30;//等价于 Test02 t7 = Test02(30);
	Test02 t8 = t7;//等价于 Test02 t8 = Test02(t7);

	//拷贝构造函数的调用时机
	//1、通过已有对象拷贝创建对象
	//2、值传递函数参数进行拷贝
	Test02 t9;
	test02_1(t9); //等同于括号法拷贝调用
	//由于值传递，此方式可修改拷贝值而不影响原值

	//3、以值方式返回的拷贝进行调用
	Test02 t10 = test02_2();//局部变量的返回值为拷贝值
#pragma endregion

#pragma region 对象的拷贝
	//浅拷贝：简单的赋值操作
	//使用C++自动生成的拷贝构造函数进行对象的拷贝
	Test03 t11(1);		//使用有参构造一创建对象
	cout << "numb=" << t11.m_numb << endl;
	Test03 t12(t11);	//将t11浅拷贝至t12
	cout << "numb=" << t12.m_numb << "\n\n";
	//浅拷贝将导致执行析构函数清理堆区成员时重复释放同一堆区内存
	//Test03 t13(1, 11);		//使用有参构造二创建对象
	//Test03 t14(t13);			//将t13浅拷贝至t14，包括指针数据m_np
	//cout << "numb=" << t13.m_numb << "pn=" << *t13.m_pn << endl;	
	//cout << "numb=" << t14.m_numb << "pn=" << *t14.m_pn << endl;	
	//此时调用m_pn所指向的数据将报错

	//深拷贝：在堆区重新申请空间进行拷贝
	Test04 t13(2,12);
	cout << "numb=" << t13.m_numb << "\tpn=" << *t13.m_pn << endl;
	Test04 t14(t13);
	cout << "numb=" << t14.m_numb << "\tpn=" << *t14.m_pn << "\n\n";
#pragma endregion

#pragma region 使用构造函数初始化列表创建对象
	Test05 t15;
	t15.show();
	Test05 t16(1,2,3,4);
	t16.show();
#pragma endregion

#pragma region 静态成员的调用
	Test06 t17;
	Test06 t18;
	//访问静态成员变量
	cout << "mA=" << Test06::mA << endl;
	cout << "对象一mA=" << t17.mA << endl;
	t17.mA = 2;
	//修改静态成员变量
	cout << "修改对象一后对象二mA=" << t18.mA << endl;
	//通过公共函数读写私有静态成员变量
	t18.return_mB(20);
	//调用静态成员函数
	Test06::show_mB();	//同样可通过对象t18.进行调用
	//通过公共函数读写私有静态成员变量
	t18.return_mA(30);
	cout << endl;
#pragma endregion

#pragma region 对象的内存分配
	Test07 t19;
	cout << "空对象的内存大小为" << sizeof(t19) << endl;
	Test08 t20;
	cout << "拥有非静态成员变量的对象的内存大小为" << sizeof(t20) << endl;

	Test09 t21;
	t21.show();
	Test09 t22(10);
	t22.show();
	t21.m_add(t22).m_add(t22).m_add(t22);	//实现链式编程
	t21.show();

	//空指针访问成员函数：因成员函数不属于对象，当该成员函数未调用成员变量时可于未创建具体对象时访问
	Test10* t_p = NULL;	//创建空指针
	t_p->show();		//空指针访问成员函数
	//t_p->v_show();	//非法：创建空指针并没有创建具体的对象，无法访问不存在的成员变量

#pragma endregion 

#pragma region 常对象
//常对象：
//1、常对象仅可调用常函数
//2、常对象也可访问mutable修饰的成员对象
// 常对象的创建
	const Test11 t23;
	//非法：	t23.m_a = 0;
	//		t23.return_b(12);
	t23.m_b = 12;
#pragma endregion

#pragma region 友元访问
	Test12 t24;
	f_func(t24);
	Test_f f_t;
	f_t.visit();
	Test_frind t_func;
	t_func.f_visit();
#pragma endregion


	system("pause");

	return 0;
}