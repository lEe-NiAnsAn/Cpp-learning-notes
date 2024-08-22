#include <iostream>
using namespace std;

//运算符重载
//对于语言内置数据类型，C++可调用运算符的已有功能进行运算，不可重载
//对于自定数据类型，需要重载运算符实现对象间运算
//使用内置函数名声明重载
//注意：请勿滥用运算符重载

#pragma region 加减号运算符重载
class Numb
{
public:
	int m_a;
	int m_b;
	Numb() {
		m_a = 1;
		m_b = 10;
	}
	Numb(int a,int b) {
		m_a = a;
		m_b = b;
	}
//成员函数重载
	Numb operator+ (Numb& n) {
		Numb temp;
		temp.m_a = this->m_a + n.m_a;
		temp.m_b = this->m_b + n.m_b;
		return temp;
	}
};

//全局函数重载
Numb operator- (Numb& n1,Numb& n2) 
{
	Numb temp;
	temp.m_a = n1.m_a - n2.m_a;
	temp.m_b = n1.m_b - n2.m_b;
	return temp;
}

//运算符重载也可进行普通函数的重载
Numb operator+ (Numb& n1, int a)
{
	Numb temp;
	temp.m_a = n1.m_a + a;
	temp.m_b = n1.m_b + a;
	return temp;
}

void plusOL()
{
	Numb n1;
	Numb n2;
	Numb n3 = n1 + n2;
	//成员函数重载本质调用
	n3 = n1.operator+(n2);
	cout << "n1 + n2 = n3 = (" << n3.m_a << ", " << n3.m_b << ")\n\n";
}

void subOL()
{
	Numb n1(4, 40);
	Numb n2(1, 10);
	Numb n3 = n1 - n2;
	//全局函数重载本质调用
	n3 = operator-(n1,n2);
	cout << "n1 - n2 = n3 = (" << n3.m_a << ", " << n3.m_b << ")\n\n";

}

void plusOL(int i)
{
	Numb n1;
	Numb n2 = n1 + i;
	cout << "n1 + " << i << " = n2 = (" << n2.m_a << ", " << n2.m_b << ")\n\n";
}
#pragma endregion

#pragma region 左移运算符重载
//左移运算符：输出语句中“<<”
class Person
{
	friend ostream& operator<<(ostream& cout, Person p);
	//使用友元访问私有成员
public:
	Person() {
		m_lname = "姓";
		m_fname = "名";
	}
	Person(string l, string f) {
		m_lname = l;
		m_fname = f;
	}
	//成员函数重载
	//void operator<<(cout) 
	//调用时等价于p.operator<<(cout),简化为p << cout
	//故一般不使用成员函数重载左移运算符,无法实现cout位于输出源左侧
private:
	string m_lname;
	string m_fname;
};
//全局函数重载
//通过“转到定义”可查看cout数据类型：out stream(标准输出流对象)
ostream& operator<<(ostream& cout, Person p)
//cout对象全局有且仅有一个,不可拷贝，故需使用引用传递形参

{
	cout << p.m_lname << p.m_fname;

	return cout;
}//返回值为cout引用可实现链式编程（可继续使用<<输出非Person内容）

void coutOL(string l, string f)
{
	Person p(l,f);
	cout << p << "\n\n";
}
#pragma endregion

#pragma region 递增运算符重载
class MyInt	//自定义整形变量
{
	friend ostream& operator<<(ostream& cout, MyInt i);
	friend void showMyInt();
public:
	MyInt() {
		m_num = 0;
	}
	//成员函数重载前置递增运算符
	MyInt& operator++() {
		m_num++;
		return*this;//返回自身的引用
	}
	//成员函数重载后置递增运算符
	MyInt operator++(int) {
		MyInt temp = *this;//临时寄存原值
		m_num++;
		return temp;//返回自身的值（因temp为局部变量，返回引用为非法）
	}

private:
	int m_num;
};
ostream& operator<<(ostream& cout, MyInt i)
{
	cout << i.m_num;

	return cout;
}

void showMyInt() {
	MyInt i;
	cout << "前置递增:i= " << i;
	cout << "\ti++=" << i++;
	cout << "\ti=" << i << endl;
	i.m_num = 0;
	cout << "后置递增:i= " << i;
	cout << "\t++i=" << ++i;
	cout << "\ti=" << i << "\n\n";
}
#pragma endregion

#pragma region 赋值运算符重载
//C++为类自动添加的第四个函数为赋值运算符函数：对属性进行值拷贝
class Numbe
{
	friend void show_n();
public:
	Numbe() {
		m_n = new int(0);
	}
	Numbe(int n) {
		m_n = new int(n);	//于堆区开辟内存储存n值，并使用m_n指针维护
	}						//需要手动释放

	~Numbe() {
		if (m_n != NULL) {
			delete m_n;
			m_n = NULL;
		}
	}
	//浅拷贝将引起内存重复释放的错误
	//故需重载赋值运算符防止浅拷贝m_n
	//成员函数重载赋值运算符使其进行深拷贝
	Numbe& operator=(Numbe& n) {
		//判断是否已于堆区开辟内存
		if (this->m_n != NULL) {
			delete this->m_n;
			this->m_n = NULL;
		}
		this->m_n = new int(*n.m_n);

		return*this;	//返回对象自身引用实现链式编程
	}

private:
	int* m_n;	//指针成员变量
};

void show_n()
{
	Numbe n1(10);
	Numbe n2(20);
	Numbe n3(30);
	cout << "n1.= " << *n1.m_n << endl;
	cout << "n2.= " << *n2.m_n << endl;
	cout << "n3.= " << *n3.m_n << endl;
	n1 = n2 = n3;
	cout << "n1=n2=n3后\tn1.= " << *n1.m_n 
				<< "\tn2.=" << *n2.m_n << "\n\n";
}
#pragma endregion

#pragma region 关系运算符重载
//==全局函数重载
bool operator==(Numb& n1,Numb& n2) 
{
	if ((n1.m_a == n2.m_a) && (n1.m_b == n2.m_b)) {
		return true;
	}
	return false;
}

void rela_func()
{
	Numb n1(1,2);
	Numb n2(4, 3);
	if (n1 == n2) {
		cout << "n1 == n2\n\n";
	}
	cout << "n1!= n2\n\n";
}
#pragma endregion

#pragma region 函数调用运算符重载
//函数调用运算符：()
//重载的函数调用运算符因使用方式与函数十分相似，故称为“仿函数”
//仿函数无固定写法，十分灵活
class MyPrint	//自订打印输出类
{
public:
	//重载()符
	void operator()(string text) {
		cout << text << "\n";
	}
	void operator()(int i) {
		cout << i << "\n";;
	}
};

void print_func()
{
	MyPrint mprint;
	mprint("Hello!");
//匿名函数对象：省略了创建具体仿函数对象的步骤，并在运行完此行代码后立即释放匿名对象
	MyPrint()(123);
	cout << endl;
}
#pragma endregion


int main5()
{
	plusOL(); subOL();
	plusOL(6);
	coutOL("Lee", "Niansan");
	showMyInt();
	show_n();
	rela_func();
	print_func();

	system("pause");

	return 0;
}