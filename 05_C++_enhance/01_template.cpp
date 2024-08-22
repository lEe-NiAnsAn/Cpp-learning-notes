#include <iostream>
using namespace std;


//模板为建立的通用框架，填补对应内容即可大大提高复用性（泛式编程）
#pragma region 函数模板的声明
//标识模板语句
template<typename T>//template:声明创建模板 ；typename:表明其后的字符为一种数据类型 ；T:通用数据类型(可替换为其它标识符)
//紧接函数声明
void tSwap(T& a, T& b)
{
	cout << "初始：\t" << a << "\t" << b << endl;
	T temp = a;
	a = b;
	b = temp;
	cout << "交换：\t" << a << "\t" << b << "\n\n";
}
void test01()
{
	int a = 1;
	int b = 2;
	string c = "C";
	string d = "D";
	//1、自动类型推导
	//必须为同一数据类型
	tSwap(a, b);
	//2、显式指定类型
	tSwap<string>(c, d);
}
//注意：模板必须确定T的数据类型才可调用
template<typename T>
void hello()
{
	cout << "hello!!!\n\n";
}
void test02()
{
	//无参数函数模板需要主动指定T的数据类型
	hello<int>();
}
#pragma endregion

#pragma region 函数模板与普通函数
//1、普通函数 调用时可进行隐式类型转换
void add(int n1, int n2)
{
	cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;
}
void test03()
{
	int a = 10;
	char b = 'b';
	cout << a << "   " << b << endl;
	add(a, b);
}
//2、函数模板 使用自动类型推导时无法进行隐式类型转换
template<typename T>
void add(T n1, T n2)//模板函数亦可与普通函数实现重载,若二者匹配度相等则将优先调用普通函数,但可通过空模板参数列表强制调用模板函数
{					//模板函数之间亦可实现重载，可通过形参列表的不同区分调用
	cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;
}
void test04()
{
	int a = 10;
	char b = 'b';
	cout << a << "   " << b << endl;
	//显式类型转换
	int bi = (int)b;
	add<>(a, bi);	//空模板参数列表
}
//3、函数模板 使用显式指定类型时可进行隐式类型转换
void test05()
{
	int a = 10;
	char b = 'b';
	cout << a << "   " << b << endl;
	add<int>(a, b);
	cout << endl;
}
#pragma endregion 

#pragma region 处理特定类型具体化函数模板
class Person
{
public:
	Person(int age, string name)
	{
		this->m_age = age;
		this->m_name = name;
	}
	Person()
	{
		this->m_age = 18;
		this->m_name = "name";
	}
	int m_age;
	string m_name;
	void show()
	{
		cout << "Person类成员函数调用\n";
	}
};
template<typename T>
bool tCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	return false;
}
//具体化函数模板,将优先调用
template<> bool tCompare(Person& p1, Person& p2)
{
	if (p1.m_age == p2.m_age && p1.m_name == p2.m_name)
	{
		return true;
	}
	return false;
}
void test06()
{
	int a = 10;
	int b = 20;
	bool bl = tCompare(a, b);
	if(bl)
	{
		cout << a << " == " << b << endl;
		return;
	}
	cout << a << " != " << b << endl;
}
void test07()
{
	Person p1(10, "p1");
	Person p2(20, "p2");
	bool bl = tCompare(p1, p2);
	if (bl)
	{
		cout << "p1 == p2" << endl;
		return;
	}
	cout << "p1 != p2\n\n";
}
#pragma endregion

//学习模板主要为使用STL中提供的模板

#pragma region 类模板的声明
//标识模板类语句
template<class T1, class T2>//无论在函数模板或类模板中，class与typename均可互用
//紧接类的声明
class Ct1
{
public:
	Ct1(T1 a, T2 b)
	{
		this->m1 = a;
		this->m2 = b;
	}
	T1 m1;
	T2 m2;
};
void test08()
{
	Ct1<int, char> c1(1, 'a');
	cout << c1.m1 << "   " << c1.m2 << "\n\n";
}
//注意：	1、类模板不可使用自动类型推导进行调用
//		2、类模板在模板参数列表中可填入默认参数 ——> template<class T1, class T2 = string>
#pragma endregion

#pragma region 类模板成员函数
//类模板成员函数于调用时创建
template<class T>
class Ct2
{
public:
	T obj;	// T可指定为某个类名，obj即为此类的一个对象
	void func()
	{
		obj.show();
	}
};
void test09()
{
	Ct2<Person>c2;	
	//当指定的数据类型使得c2.func()函数无法调用时，Ct类对象c2的成员函数将不会创建，即不存在c2.func()
	c2.func();	
	cout << "\n\n";
}
#pragma endregion

#pragma region 类模板对象做函数参数
template<class T1, class T2>
class Ct3
{
public:
	Ct3(T1 a, T2 b)
	{
		this->m_a = a;
		this->m_b = b;
	}
	void show()
	{
		cout << "Ct3模板类函数\n" << m_a << "   " << m_b << endl;;
	}
	T1 m_a;
	T2 m_b;
};
//1、指定传入类型
void print1(Ct3<int, char>& c)
{
	c.show();
}
void test10()
{
	Ct3<int, char>c1(1, 'a');
	print1(c1);
	cout << endl;

}
//2、模板类参数模板化传入，即配合了类模板的函数模板
template<typename T1, typename T2>
void print2(Ct3<T1, T2>& c)
{
	c.show();
	cout << "T1类型为" << typeid(T1).name() << 
		"\nT2类型为" << typeid(T2).name() << "\n\n";

}
void test11()
{
	Ct3<int, char>c1(2, 'b');
	print2(c1);

}
//3、参数以类的模板化传入，即函数模板
template<typename T>
void print3(T c)
{
	c.show();
	cout << "T类型为" << typeid(T).name() << "\n\n";
}
void test12()
{
	Ct3<int, char>c1(3, 'c');
	print3(c1);

}
#pragma endregion

#pragma region 类模板的继承
//父类为类模板时，子类继承时需指定父类模板中的类型
template<class T1>
class Ct4 
{
public:
	Ct4()
	{
		cout << "父类模板参数类型为" << typeid(T1).name() << endl;
	}
	T1 m1;
};
template<class T2, class T1>
class sC:public Ct4<T1>	//若前无模板声明语句，则必须指定明确的数据类型，如<int>，否则将无法获取父类成员所需内存大小
{
public:
	sC()
	{
		cout << "子类模板参数类型为" << typeid(T2).name();
	}
	T2 m2;
};
void test13()
{
	sC<char, int> s1;
	cout << "\n\n";
}
#pragma endregion 

#pragma region 类模板的成员函数的类外实现
//需添加模板参数列表
template<class T1, class T2>
class Ct5
{
public:
	Ct5(T1 a, T2 b);
	void show();
	T1 m_a;
	T2 m_b;
};
//类模板的构造函数的类外实现
template<class T1, class T2>
Ct5<T1, T2>::Ct5(T1 a, T2 b)
{
	this->m_a = a;
	this->m_b = b;
}
//类模板的成员函数的类外实现
template<class T1, class T2>
void Ct5<T1, T2>::show() 
{
	cout << "Ct5成员函数\nm_a = " << this->m_a << "   m_b = " << this->m_b << "\n\n";
}
void test14()
{
	Ct5<int, char> c1(1, 'a');
	c1.show();
}
#pragma endregion

#pragma region 类模板的分文件编写
//分文件编写时无法链接类模板中于调用前未创建的成员函数
//解决方法：
//1、分别编写.h头文件与.cpp源文件，直接使用.cpp源文件（不推荐）
#include "Ct6.cpp"
//2、将声明与实现编入同一份文件.hpp（hpp为约定的名称并不强制）
#include "Ct7.hpp"
void test15()
{
	Ct6<int, char> c1(1, 'a');
	c1.show();
	Ct6<int, char> c2(1, 'a');
	c2.show();
}
#pragma endregion

#pragma region 类模板与友元
template<class T1, class T2>class Ct8;					//为下行语句中函数参数内Ct8类作声明
template<class T1, class T2>void show2(Ct8<T1, T2> c);	//为Ct8类实现内友元声明作模板函数声明

template<class T1, class T2>
class Ct8
{
	//1、类模板友元的类内实现
	friend void show1(Ct8<T1, T2> c)
	{
		cout << "Ct8全局函数友元类内实现\nm_a = " << c.m_a << "   m_b = " << c.m_b << "\n";
	}
	T1 m_a;
	T2 m_b;
	friend void show2<>(Ct8<T1, T2> c);	//需添加空模板参数列表<>使其由普通函数声明转化为函数模板声明
	//需在上方类外做出函数模板声明，使得编译器识别该全局函数友元
public:
	Ct8(T1 a, T2 b)
	{
		this->m_a = a;
		this->m_b = b;
	}
};
//2、类模板友元的类外实现（见本region开头语句的声明）
template<class T1, class T2>
void show2(Ct8<T1, T2> c)	//此为函数模板的实现
{
	cout << "Ct8全局函数友元类外实现\nm_a = " << c.m_a << "   m_b = " << c.m_b << "\n\n";
}

void test16()
{
	Ct8<int, char> c1(1, 'a');
	show1(c1);
	Ct8<int, char> c2(2, 'b');
	show2(c2);
}
#pragma endregion 


int main01()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();
	test10();
	test11();
	test12();
	test13();
	test14();
	test15();
	test16();


	system("pause");

	return 0;
}