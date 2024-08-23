#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>	//标准算法头文件
#include<functional>	//内建函数对象

#pragma region STL基本定义
//STL（Standard Template Library）标准模板库
//广义分类：容器(container)、算法(algorithm)、迭代器(iterator)
//STL几乎所有代码采用模板编写
//STL由六大组件构成：
//1、容器：各式数据结构，用于储存数据
//2、算法：各类常用算法，用于解决问题
//3、迭代器：容器与算法间的胶合剂
//4、仿函数：算法的某种策略
//5、适配器：用于修饰容器、仿函数或迭代器接口
//6、空间配置器：配置与管理空间
#pragma region 容器
//容器分为：
//1、序列式容器：强调值的排序，容器内各元素均有固定的位置
//2、关联式容器：二叉树结构，各元素间不存在严格物理上的次序关系
//容器的调用需要声明头文件
#pragma endregion
#pragma region 算法
//算法分为：
//1、质变算法：运算过程中将更改区间内元素的内容，如拷贝、替换、删除等
//2、非质变算法：运算过程中不更改区间内元素的内容，如计数、遍历、寻找极值等
//STL算法的调用需要声明头文件
#pragma endregion
#pragma region 迭代器
//将提供一类方法，使之依序访问某容器中的元素且不暴露该容器的内部，以便算法进行操作
//每一容器均含其专属迭代器，类似与指针
//迭代器种类：
//1、输入迭代器：对数据进行只读访问（支持 ++ 、== 、!= ）
//2、输出迭代器：对数据进行只写访问（支持 ++ ）
//3、前向迭代器：对数据进行读写访问，并可向前推进迭代器（支持 ++ 、== 、!= ）
//4、双向迭代器：对数据进行读写访问，并可向前或向后操作（支持 ++ 、-- ）
//5、随机访问迭代器：对数据进行读写访问，可跳跃式访问任意数据（支持 ++ 、-- 、[n] 、-n 、< 、<= 、> 、>= ）
#pragma endregion
#pragma region vector容器示例(动态数组)
//一、存放内置数据类型
//vector：向量
void prt1(int a)	//for_each参数中的回调函数一
{
	cout << a << "   ";
}
class C302;
void prt2(C302*);	//for_each参数中的回调函数二

void test301()
{
	//创建容器对象
	vector<int> v;
	//向容器中插入数据
	for (int i = 1; i < 4; i++)
	{
		v.push_back(i);
	}
	//通过迭代器(iterator)访问
	vector<int>::iterator itBegin = v.begin();	//起始迭代器，指向容器首元素
	vector<int>::iterator itEnd = v.end();		//结束迭代器，指向容器尾元素的后一位(即为空元素，无意义)
	cout << "迭代遍历方法一" << endl;
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}
	cout << "\n迭代遍历方法二" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "\n迭代遍历方法三" << endl;
	//STL提供的遍历算法 for_each(起点, 终点, 函数名)
	//底层类似方法二的for循环，在回调函数时传入"解引用(迭代器对象)"的数据
	for_each(v.begin(), v.end(), prt1);
	cout << endl;
}
//二、存放自订数据类型
class C302
{
public:
	C302(int a, char b)
	{
		this->m_a = a;
		this->m_b = b;
	}
	C302(const C302& c)
	{
		this->m_a = c.m_a;
		this->m_b = c.m_b;
	}
	int m_a;
	char m_b;
};
void test302()
{
	vector<C302> v;

	for (int i = 1; i < 4; i++)
	{
		C302 ci(i, 'N');
		v.push_back(ci);
	}
	for (vector<C302>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).m_a << "   " << it->m_b << endl;
	}
	cout << endl;
}
//三、存放自订数据类型的指针
void test303()
{
	vector<C302*> v;
	C302 ci(11, 'N');
	for (int i = 11; i < 14; i++)
	{
		v.push_back(&ci);
	}
	//使用for_each遍历时需注意回调函数声明、类声明、回调函数实现与类实现的先后顺序
	for_each(v.begin(), v.end(), prt2);
	cout << endl;
}
void prt2(C302* cr)
{
	cout << cr->m_a << "   " << cr->m_b << endl;
}
//四、Vector容器嵌套容器
void test304()
{
	vector<vector<int>> vf;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	for (int i = 11; i < 14; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
		v3.push_back(i + 20);
	}
	vf.push_back(v1);
	vf.push_back(v2);
	vf.push_back(v3);
	for (vector<vector<int>>::iterator itf = vf.begin(); itf != vf.end(); itf++)
	{
		for (vector<int>::iterator it = itf->begin(); it != itf->end(); it++)
		{
			cout << (*it) << "   ";
		}
		cout << endl;
	}
	cout << endl;
}
#pragma endregion

#pragma endregion

#pragma region 容器
	#pragma region String容器
//string类内封装了 char*，为 char*型容器，内部亦封装了成员方法
//string管理 char*所分配的内存，不必担心越界问题，由类内部负责
#pragma region 构造
void test305()
{
	string s1;	//默认无参构造
	const char* str = "abc";	//c语言风格字符串
	string s2(str);	//有参构造（字符串为参数）
	cout << s2 << endl;
	string s3(s2);	//拷贝构造
	cout << s3 << endl;
	string s4(5, 'n');	//有参构造（int，char为参数，创建一个由数个相同字符的字符串）
	cout << s4 << "\n\n";
}
#pragma endregion
#pragma region 赋值
void test306()
{
	string s1;s1 = "abc";	//使用 = 赋值 char* 字符串
	cout << s1 << endl;
	string s2;s2 = s1;	//使用 = 赋值 string 对象
	cout << s2 << endl;
	string s3;s3 = 'n';	//使用 = 赋值 char 字符
	cout << s3 << endl;
	string s4; s4.assign("xyz");	//使用 assign 赋值 char* 字符串
	cout << s4 << endl;
	string s5; s5.assign("xyz", 1);	//使用 assign 赋值 char* 字符串中前n个字符
	cout << s5 << endl;
	string s6; s6.assign(s4);	//使用 assign 赋值 string 对象
	cout << s6 << endl;
	string s7; s7.assign(5, 'w');	//使用 assign 赋值n个 char 字符
	cout << s7 << "\n\n";

}
#pragma endregion
#pragma region string字符串拼接
void test307()
{
	string s1 = "abc";
	s1 += "def";	// += 运算符重载（参数 char*）
	cout << s1 << endl;
	s1 += 'g';	// += 运算符重载（参数 char）
	cout << s1 << endl;
	string s2 = "hij";
	s1 += s2;	// += 运算符重载（参数 string）
	cout << s1 << endl;
	s1.append("klm");	// append函数拼接c风格字符串（参数 char*）
	cout << s1 << endl;
	s1.append("nop", 1);	// append函数拼接c风格字符串前n位字符（参数 char*,int）
	cout << s1 << endl;
	string s3 = "opq";
	s1.append(s3);	// append函数拼接c++风格字符串（参数 string）
	cout << s1 << endl;
	string s4 = "0rst";
	s1.append(s4, 1, 3);	// append函数拼接c++风格字符串的第n1位开始(包括第n1位)后的n2个字符（参数 string,int,int）
							//此处第n1位为从0开始的索引
	cout << s1 << "\n\n";
}
#pragma endregion
#pragma region string字符串查找与替换
void test308()
{
	//查找
	string s1 = "lEe_NiAnsAn";
	string s2 = "sAn";
	//find为从左至右查找
	int p1 = s1.find(s2,0);	//find返回从第n位字符后开始查找字符串第一次出现的的位置（参数 string,int）——> int可省略，默认为0
							//此处第n位为从0开始的索引，返回结果亦然，返回结果包括n
							//若查找无结果，则返回-1
	cout << p1 << endl;
	int p2 = s1.find("lEe", 0);	//返回从第n位字符后开始查找字符串第一次出现的的位置（参数 char*,int）——> int可省略，默认为0
	cout << p2 << endl;
	int p3 = s1.find("lEe", 0, 2);	//返回从第n1位字符后开始查找字符串的前n2个字符第一次出现的的位置（参数 char*,int，int）
	cout << p3 << endl;
	int p4 = s1.find('n', 0);	//返回从第n位字符后开始查找字符第一次出现的的位置（参数 char,int）——> int可省略，默认为0
	cout << p4 << "\n\n";

	//rfind为从右至左查找
	int p5 = s1.rfind(s2, 10);	//返回从第n位字符前开始查找字符串最后出现的的位置（参数 string,int）——> int可省略，默认为 npos(最后一位)
	cout << p5 << endl;
	int p6 = s1.rfind("lEe", 10);	//返回从第n位字符前开始查找字符串最后出现的的位置（参数 char*,int）——> int可省略，默认为 npos
	cout << p6 << endl;
	int p7 = s1.rfind("lEe", 10, 2);	//返回从第n1位字符前开始查找字符串的前n2个字符最后出现的的位置（参数 char*,int，int）
	cout << p7 << endl;
	int p8 = s1.rfind('n', 8);	//返回从第n位字符前开始查找字符最后出现的的位置（参数 char,int）——> int可省略，默认为 npos
	cout << p8 << "\n\n";

	//替换
	string s3 = "abcdefg";
	string s4 = "123";
	s3.replace(3, 2, s4);	//将从第n1位开始(包括n1位)后n2个字符替换为c++风格字符串（参数 int，int，string）
	cout << s3 << endl;
	s3.replace(3, 2, "NNN");	//将从第n1位开始(包括n1位)后n2个字符替换为c风格字符串（参数 int，int，char*）
	cout << s3 << "\n\n";
	
}
#pragma endregion
#pragma region string字符串比较
void test309()
{
	//逐位一一对应比较字符的ASCII码，直到某位字符小于被比较字符串对应位字符时返回 "1"，大于则返回 "-1"，若所有字符均相等返回 "0"；
	string s1 = "abc";
	string s2 = "123";
	int c1 = s1.compare(s2);
	cout << c1 << endl;
	int c2 = s1.compare("abc");
	cout << c2 << "\n";
	int c3 = s1.compare("aaw");
	cout << c3 << "\n";
	int c4 = s1.compare("awa");
	cout << c4 << "\n\n";
}
#pragma endregion
#pragma region string字符串中单字符读写
void test310()
{
	string s = "abcd";
	cout << s << endl;
	//通过重载[]访问
	for (int i = 0; i < s.size(); i++)	//size()成员函数用于获取字符串长度
	{
		cout << s[s.size() - 1 - i] << " | ";
	}
	cout << endl;
	//通过at方法访问
	for (int i = 0; i < s.size(); i++)	//size()成员函数用于获取字符串长度
	{
		s.at(i) = 'X';	//不可修改为字符串
		cout << s.at(i) << " | ";
	}
	cout << "\n\n";
}
#pragma endregion
#pragma region string字符串的插入与删除
void test311()
{
	string s1 = "abg";
	string s2 = "cdef";
	//插入
	cout << s1.insert(2, s2) << endl;		//从第n位前插入C++风格字符串（参数 int,string）
	s1 = "abg";								//此处第n位为从0开始的索引
	cout << s1.insert(2, "xxxx") << endl;	//从第n位前插入C风格字符串（参数 int,char*）
	s1 = "abg";
	cout << s1.insert(2, 4, 'w') << endl;	//从第n1位前插入n2个相同字符（参数 int,int,char*）
	//删除
	cout << s1.erase(2, 4) << endl;		//删除从n1位开始的n2个字符（参数 int1,int2）——>int2可不填，默认为npos
	cout << endl;						//此处删除包括n1位字符
}
#pragma endregion
#pragma region string字串
void test312()
{
	string s1 = "abcdefg";
	string s2 = s1.substr(3,3);		//截取第n1位开始的后n2个字符为字串（参数 int1,int1）——>int1默认参数0，int2默认参数 npos
	cout << s1 << "\n" << s2 << "\n\n";	//此处n1位索引，子串中包括n1位
}
#pragma endregion

#pragma endregion

	#pragma region Vector容器
//vector容器被称为单端数组，可单向动态扩展
void test313()
{
#pragma region vector容器的构造
	vector<int> v1;	//无参构造
	for (int i = 1; i < 4; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2(v1.begin(), v1.end());	//通过 vector对象使用前闭后开区间构造
	for_each(v2.begin(), v2.end(), prt1);
	cout << endl;
	vector<int> v3(3, 6);	//通过n个相同数据构造（参数 int1,int2）——>int1为数量，int2为数据
	vector<int> v4(v3);		//拷贝构造
	for_each(v3.begin(), v3.end(), prt1);
	cout << endl;
#pragma endregion
#pragma region vector容器的赋值
	vector<int> v5 = v1;	// "="重载进行赋值
	v5.assign(v3.begin(), v3.end());	//前闭后开区间取值赋值
	v5.assign(3, 9);	//使用n个相同数值赋值
	for_each(v5.begin(), v5.end(), prt1);
	cout << "\n\n";
#pragma endregion
#pragma region vector容器的数据
	//容量
	bool eb = v5.empty();	//判断容器是否为空：真值为空，非值为非空
	int c = v5.capacity();	//获取容器容量
	int s = v5.size();		//获取容器中数据数量(大小)
	v5.resize(5, 1); //重新指定容器容量（参数 int1,int2）若大于原容量则将使用 int2填充新空间，若小于将删除超长尾数据——>int2可无，默认为0
	for_each(v5.begin(), v5.end(), prt1);
	cout << "\n";
	//删插
	v5.push_back(1);	//在容器末尾插入传入数据
	v5.pop_back();		//删除容器末位数据

	v5.insert(v5.begin()+1, 0);	//在迭代器指向位置插入数据，返回新数据位置
	for_each(v5.begin(), v5.end(), prt1);
	cout << endl;

	v5.insert(v5.begin()+4, 2, 10);	//在迭代器指向位置插入数个相同数据
	for_each(v5.begin(), v5.end(), prt1);
	cout << endl;

	v5.erase(v5.begin()+3);			//删除迭代器所指向位置数据，返回下一个数据的位置
	for_each(v5.begin(), v5.end(), prt1);
	cout << endl;

	v5.erase(v5.begin()+1, v5.end()-1);			//删除迭代器所指向区间内所有数据，返回下一个数据的位置
	for_each(v5.begin(), v5.end(), prt1);
	v5.clear();			//清除容器内所有数据
	cout << "\n\n";
	
	//存取
	vector<int> v6;
	for (int i = 1; i < 5; i++)
	{
		v6.push_back(i);
	}
	for_each(v6.begin(), v6.end(), prt1);
	cout << endl;
	cout << v6.at(1) << endl;	//成员函数返回索引所指数据
	cout << v6[2] << endl;		//[]重载返回索引所指数据
	cout << v6.front() << endl;		//返回容器中首位数据
	cout << v6.back() << "\n\n";	//返回容器中末位数据
#pragma endregion
#pragma region vector容器的互换
	cout << "互换前\n";
	vector<int> v7;
	for (int i = 1; i < 4; i++)
	{
		v7.push_back(i);
	}
	for_each(v7.begin(), v7.end(), prt1);
	cout << endl;
	vector<int> v8;
	for (int i = 9; i > 6; i--)
	{
		v8.push_back(i);
	}
	for_each(v8.begin(), v8.end(), prt1);
	cout << "\n互换后\n";
	v7.swap(v8);
	for_each(v7.begin(), v7.end(), prt1);
	cout << endl; 
	for_each(v8.begin(), v8.end(), prt1);
	cout << endl;
	//当容器大小十分庞大时，容器容量会更大以方便后续插入新数据
	//此时若重新指定大小后，容量并不会自动缩小，便会占用庞大的内存
	//灵活使用 swap成员函数即可收缩容量减少无用内存占用
	for (int i = 4; i < 10000; i++)
	{
		v8.push_back(i);
	}
	v8.resize(3);
	vector<int>(v8).swap(v8);
	//vector<int>(v)为拷贝构造匿名对象，执行完互换方法后即自动清理
#pragma endregion
#pragma region vector容器预留空间
	//预留空间：减少容器动态扩展的次数，节省性能
	v8.reserve(2);	//容器预留n个数据空间，预留位置不初始化、不可访问
	cout << endl;
#pragma endregion
}
#pragma endregion 

	#pragma region Deque容器
//deque容器被称为双端数组，可双向动态扩展
//double-ended queue(队列)
void dshow(const deque<int>&d)	//使用 const防止传入的引用被修改
{
	//传入常容器对象需使用常迭代器访问
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)	//双端迭代器，支持随机访问
	{
		cout << *it << "   ";
	}
	cout << endl;
}
void test314()
{
	//deque可直接对数组头端进行数据插入，相对而言较 vector容器头插效率高
	//而 vector容器访问元素较 deque速度更快，与其内部实现相关
	//deque内部拥有一中控器与数个缓冲区，缓冲区内存放有真实数据，而中控器维护每一缓冲区的地址，使其可连续调用
	//中控器维护的头部缓冲区前端预留数据位，尾部缓冲区末端预留数据位
	//当进行头插操作时数据将插入前端预留数据位，进行尾插操作时数据将插入末端预留数据位
#pragma region deque容器基本概念
	//vector容器示例中构造、赋值、数据内容中代码用例 deque容器同样适用——>除 capacity()成员方法，因 deque容量无容量概念
	deque<int> d1;	//构造
	for (int i = 1; i < 10; i++)
	{
		d1.push_back(i);	//赋值
	}
	dshow(d1);	//访问
	//头部删插操作
	d1.push_front(0);
	dshow(d1);
	d1.pop_front();
	//插入另一容器某区间数据
	deque<int> d2;
	for (int i = 9; i > 5; i--)
	{
		d2.push_back(i);
	}
	d1.insert(d1.begin(), d2.begin()+1, d2.end()-1);	
	dshow(d1);
	cout << endl;
#pragma endregion
#pragma region deque容器排序
	//利用sort算法排序——>默认升序排列
	sort(d1.begin(), d1.end());	//对区间内数据进行排序
	dshow(d1);
	cout << endl;
	//支持随机访问数据迭代器的容器均可使用sort算法进行排序
#pragma endregion
}
#pragma endregion

	#pragma region Stack容器
//stack栈分为栈底与栈顶，push入栈存储数据至栈，除栈顶处一个数据可直接被外界访问，其余数据需其上方所有数据依次 pop出栈后才可访问
//栈容器符合"先进后出"规则，对入栈的数据计数，且不允许遍历行为
void test315()
{
	//构造
	stack<int> stk1;	//默认构造
	for(int i = 1; i < 6; i++)
	{
		stk1.push(i);	//向栈顶添加数据
	}
	stack<int> stk2(stk1);	//拷贝构造
	stack<int> stk3;
	stk3 = stk2;	// “=”重载赋值
	//打印输出栈内数据
	cout << "栈内数据数量：" << stk2.size() <<endl;	//返回栈大小	
	while (!stk1.empty())	//判断栈内是否为空
	{
		cout << stk1.top() << "   ";	//返回栈顶处数据
		stk1.pop();	//移除栈顶处数据
	}
	cout << "\n\n";
}
#pragma endregion

	#pragma region Queue容器
//queue队列拥有一个入口与一个出口，为"先进先出"数据结构
//新数据从队尾存入(push入队)，数据由队头弹出(pop出队)，数据移动方向即为队列方向，外界仅可访问队头与队尾数据，不允许遍历
void test316()
{
	//构造
	queue<C302> que1;	//默认构造
	for (int i = 1; i < 4; i++)
	{
		C302 ci(i, 'N');
		que1.push(ci);	//向队尾添加数据
	}
	queue<C302> que2(que1);	//拷贝构造
	queue<C302> que3;
	que3 = que2;	// “=”重载赋值
	//打印输出队内数据
	cout << "队内数据数量：" << que2.size() << endl;	//返回队列大小	
	while (!que1.empty())	//判断栈内是否为空
	{
		C302 cq(que1.front());	//返回队头处数据
		cout << cq.m_a << "   " << cq.m_b << " | ";
		que1.pop();	//移除队头处数据
	}
	C302 qb = que2.back();	//返回队尾处数据
	cout << "\n\n";
}
#pragma endregion

	#pragma region List容器
//list链表为非连续存储结构，由一系列结点构成，其中数据逻辑顺序通过链表中的指针实现
//结点由一存放数据的数据域与一存储下一结点地址的指针域构成
//优点：可快速插入或删除数据	缺点：遍历速度慢、占用空间大
//STL中的链表为双向循环链表：指针域中存储的地址既含下一结点(next)又含上一结点(prev)，且链表首尾相结
//list迭代器因其为非连续存储结构故仅支持前移与后移，无法随机访问，为双向迭代器
//不同于 vector，对 list容器进行插入或删除并不导致原 list迭代器的失效
void lshow(const list<int>& lst)
{
	for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)	//迭代器
	{
		cout << *it << "   ";
	}
	cout << endl;
}
bool bc(int n1, int n2)
{
	return n1 > n2;	//实现降序：前数大于后数
}
void test317()
{
	//构造
	list<int> lst1;	//无参构造
	for (int i = 1; i < 6; i++) 
	{
		lst1.push_back(i);	//存入数据
	}
	lshow(lst1);	//遍历输出打印
	list<int> lst2(lst1);	//拷贝构造
	vector<int> v;
	for (int i = 1; i < 6; i++)
	{
		v.push_back(i);
	}
	list<int> lst3(v.begin()+1, v.end()-1);	//区间构造
	list<int> lst4(3, 6);	//数个相同数据构造

	//赋值与互换
	lst4.assign(v.begin() + 2, v.end() - 2);	//区间赋值
	lst4.assign(2, 7);	//数个相同数据赋值
	lst4 = lst3;	//"="重载赋值
	lst4.swap(lst2);	//互换

	//大小操作
	cout << "数量为：" << lst4.size() << endl;	//返回链表数据数量
	bool lb = lst4.empty();	//判断链表是否为空
	lst4.resize(5, 3);	//重新指定链表长度，若缩短则删除超长数据，若扩长则使用参数2填充——>参数2不填默认为0	

	//插入与删除
	lst4.push_back(0);	//在链表尾添加一个数据
	lst4.pop_back();	//删除链表尾一位数据
	lst4.push_front(0);	//在链表首添加一个数据
	lst4.pop_front();	//删除链表首一位数据
	lst4.insert(lst4.begin(), 0);	//在指定位置添加一个数据，返回新数据位置
	lst4.erase(lst4.begin());		//删除指定位置数据，返回下一位数据位置
	lst4.insert(lst4.begin(), 3, 0);//在指定位置添加数个相同数据
	lst4.insert(lst4.begin(), v.begin()+2, v.end()-1);	//在指定位置添加前闭后开区间数据
	lst4.remove(0);	//移除链表中与参数匹配的全部数据
	list<int>::iterator it = lst4.begin();
	for(int i = 0; i < 2; i++)
	{
		it++;	//"++"重载实现迭代器移动
	}
	lst4.erase(it, lst4.end());	//删除指定前闭后开区间内数据，返回下一位数据位置
	lst4.clear();	//清除链表内所有数据
	cout << endl;

	//存取
	cout << lst1.front() << "   ";	//返回链表首元素
	cout << lst1.back() << "\n\n";	//返回链表尾元素
	//不可使用[]或at成员方法随机访问

	//容器反转与排序
	lst1.reverse();	//成员函数反转算法
	lshow(lst1);
	lst1.sort();	//成员函数排序算法
	lshow(lst1);	//非支持随机访问迭代器容器不可使用标准算法
	lst1.sort(bc);	//通过成员函数的重载，传入回调函数实现降序排列
	lshow(lst1);	//排序自订类型时同样需主动编写匹配的回调函数
	cout << endl;
}
#pragma endregion

	#pragma region Set/Multiset容器
//set集合容器在数据插入时将自动排序，属于关联式容器，底层由二叉树实现
//set容器不允许重复元素插入，multiset容器允许重复元素插入，二者仅需包含一<set>头文件即可
void stshow(const set<int>& st)
{
	for (set<int>::const_iterator it = st.begin(); it != st.end(); it++)	//迭代器
	{
		cout << *it << "   ";
	}
	cout << endl;
}
class StP
{
public:
	StP(char c, int i)
	{
		this->m_c = c;
		this->m_i = i;
	}
	char m_c;
	int m_i;
};
class StCompr
{
public:
	bool operator()(int n1, int n2) const	//重载()运算符实现仿函数
	{								//因容器排序时调用比较仿函数无需更改其性质，故其关联容器时需强制在声明函数重载时添加 const修饰
		return n1 > n2;	//降序排列
	}
	bool operator()(const StP& stp1, const StP& stp2) const	//二次重载()运算符
	{								
		if (stp1.m_c == stp2.m_c)
		{
			return stp1.m_i < stp2.m_i;
		}
		return stp1.m_c < stp2.m_c;		//依次升序排列
	}
};
void test318()
{
#pragma region set构造，赋值，查找，数据操作
	set<int> st1;	//默认构造
	for (int i = 6; i > 0; i--)
	{
		st1.insert(i);	//插入数据(仅此)——>检测插入是否成功，成功则返回相应 pair类型
	}					//pair<set<int>::interator, bool> ret = st1.insert(i);
	stshow(st1);	//遍历输出打印——>默认升序
	set<int> st2(st1);	//拷贝构造
	set<int> st3 = st2;	//"="重载赋值
	cout << "set容器大小为：" << st1.size() << endl;	//返回数据数量
	bool bst1b = st1.empty();	//判断容器是否为空
	st2.swap(st3);	//互换操作
	st2.clear();	//清空容器
	st3.erase(st3.begin());	//删除迭代器指向数据，返回下一数据迭代器
	set<int>::iterator it3 = st3.begin();	//set迭代器不可随机访问
	it3++;									//"++"重载实现迭代器移动
	st3.erase(++it3, --st3.end());	//删前区间数据，返回下一数据迭代器
	st3.erase(2);	//删除容器内与参数匹配数据
	stshow(st3);
	st3.find(3);	//查找参数：若容器中存在即返回其迭代器，若不存在则返回.end()
	multiset<int> mst1;	//multiset容器接口与 set相同
	for (int i = 6; i > 0; i--)
	{
		mst1.insert(1);	//可重复插入相同数据，不检测是否成功
	}
	int nmst1 = mst1.count(1);	//统计返回容器内与参数匹配数据的数目
#pragma endregion
#pragma region pair类数据类型
	//pair对组：成对出现数据，利用对组可返回两个数据
	//一、对组的创建(无需包含头文件)
	pair<char, int> pr1('a', 1);	//构造
	pair<char, int> pr2 = make_pair('b',2);	//成员函数赋值
	//二、对组的访问
	cout << "对组第一位数据：" << pr1.first << "  对组第二位数据：" << pr1.second << endl;
#pragma endregion
#pragma region set容器的排序
	//利用仿函数自订排序，于插值前更改排序规则
	//一、自订排序内置数据类型
	set<int,StCompr>st4;	//比较类传入模板参数实现降序排列
	for (int i = 1; i < 7; i++)
	{
		st4.insert(i);
	}
	for (set<int,StCompr>::iterator it = st4.begin(); it != st4.end(); it++)
	{
		cout << *it << "   ";	//因模板参数发生改变故无法直接调用普通打印输出函数
	}
	cout << endl;
	//二、排序自订数据类型
	set<StP,StCompr>st5;	//使用定制的重载仿函数版本实现排列
	for (int i = 1; i < 7; i++)
	{
		int temp = i;	//寄存i实现部分对象的char值相同而int值不同
		if (i == 4 || i == 5) 
		{
			i = 3;
		}
		StP StPi('G'-i, temp);
		st5.insert(StPi);
		i = temp;
	}
	for (set<StP,StCompr>::iterator it = st5.begin(); it != st5.end(); it++)
	{
		cout << (*it).m_c << "  " << (*it).m_i << " | ";
	}
	cout << "\n\n";
#pragma endregion
}
#pragma endregion

	#pragma region Map/Multimap容器
//map容器中所有元素均为 pair，first为 key键值(索引作用)，second为 value实值，可根据键值迅速查找至实值
//其中所有数据在插入时均将按照 key值自动排序，属于关联式容器，底层由二叉树实现
//map容器不允许插入重复 key值数据，而 multimap允许插入重复 key值数据
void mpshow(const map<int, char>& mp)
{
	for (map<int, char>::const_iterator it = mp.begin(); it != mp.end(); it++)	//迭代器
	{
		cout << (*it).first << "——>" << it->second << " | ";	//对组访问
	}
	cout << endl;
}
class MpCompr
{
public:
	bool operator()(int n1, int n2) const	//仿函数
	{
		return n1 > n2;	//降序排序
	}
};
void test319()
{
#pragma region map构造，赋值，查找，数据操作
	map<int, char> mp1;		//默认构造
	map<int, char> mp2(mp1);	//拷贝构造
	for (int i = 6; i > 0; i--)
	{
		int temp = i;
		if (i == 4 || i == 5)
		{
			i = 3;
		}
		mp1.insert(pair<int, char>(temp, 'g'-i));	//插值
		i = temp;	
	}
	map<int, char> mp3 = mp1;	//赋值
	mpshow(mp3);	//遍历打印输出
	cout << "容器数据数目为：" << mp3.size() << endl;	//大小
	bool mpb = mp3.empty();	//判断容器是否为空
	mp3.swap(mp2);	//互换
	mp2.clear();	//清空容器数据
	mp1.erase(mp1.begin());	//删除迭代器所指数据，返回下一数据迭代器
	mp1.erase(++mp1.begin(), --mp1.end());	//删除前闭后开区间内数据，返回下一数据迭代器
	mp1.erase(6);	//删除容器内与参数相符键值的数据
	mp1[3] = 'd';	//[]重载插值——>可不进行赋值操作，默认为NULL值
	cout << mp1[3] << endl;	//输出键值对应实值——>注意：当mp1[10]合法出现在其它语句时，原本不存在[10]的实值亦将默认赋予NULL，故不建议使用
	mp1.insert(make_pair(4, 'a'));	//通过 pair成员函数插值
	mp1.insert(map<int,char>::value_type(5, 'b'));	//通过 map成员函数插值
	mp1.find(3);	//根据键值查找，若存在则返回对应数据迭代器，否则返回.end();
	int mpc = mp1.count(4);	//返回容器内符合参数键值数据的数目
#pragma endregion
#pragma region map容器的排序
	//通过仿函数实现内置数据类型自订排序
	map<int, char, MpCompr> mp4;	//模板参数列表传入仿函数
	for (int i = 6; i > 0; i--)
	{
		mp4.insert(pair<int, char>(i, 'g' - i));
	}
	for (map<int, char, MpCompr>::iterator it = mp4.begin(); it != mp4.end(); it++)
	{
		cout << (*it).first << "——>" << it->second << " | ";
	}
	cout << "\n\n";
	//使用map存储自订数据类型键值必须指定仿函数实现排序
#pragma endregion
}
#pragma endregion
#pragma endregion

#pragma region 函数对象
//重载函数调用操作符()的类的对象称为函数对象，使用时则称为仿函数
//函数对象(仿函数)本质为类而非函数
	#pragma region 函数对象的基本使用
//一、函数对象可同普通函数一样调用，可有参数与返回值
class Fc1
{
public:
	int operator()(int n1, int n2)
	{
		return n1 + n2;
	}
};
//二、函数对象可超出普通函数概念，拥有自身的状态(成员属性)
class Fc2
{
public:
	Fc2()
	{
		this->m_n = 0;	//置零
	}
	void operator()(string str)
	{
		cout << str;
		this->m_n++;
	}
	int m_n;	//自身状态：仿函数调用次数
};
//三、函数对象可作为参数传递
void fcprint(Fc2& fc2, string str)
{
	fc2(str);
	cout << endl;
}
void test320()
{
	Fc1 fc1;
	cout << "仿函数普通调用：" << fc1(1, 2) << endl;
	Fc2 fc2;
	fc2("仿函数调用次数：");
	for(int i = 0; i < 4; i++)
	{
		fc2("");
	}
	cout << fc2.m_n << endl;
	fcprint(fc2, "函数对象作为参数传递");
	cout << endl;
}
#pragma endregion

	#pragma region 谓词
//返回 bool值的仿函数称为谓词，若接收一个参数则为一元谓词，接收两个参数则为二元谓词
//一、一元谓词
class Cfive
{
public:
	bool operator()(int n)
	{
		return n > 5;	//大于五
	}
};
//二、二元谓词
class CdcOd
{
public:
	bool operator()(int n1, int n2)
	{
		return n1 > n2;	//降序
	}
};
void test321()
{
	//一元谓词示例：查找容器内是否存有大于五的数据,如有则返回符合的首个数据的迭代器，否则返回.end()
	vector<int> v321_1;
	for (int i = 1; i < 9; i++)
	{
		v321_1.push_back(i);
	}
	vector<int>::iterator it1;
	it1 = find_if(v321_1.begin(), v321_1.end(), Cfive());	//find_if参数：(查找区间始,查找区间末,谓词)——>谓词为匿名对象
	if (it1 == v321_1.end())								//该算法返回值为迭代器
	{
		cout << "查询无果" << endl;
	}
	else
	{
		cout << "首个大于五的数据为" << *it1 << endl;
	}
	//二元谓词示例：自订 sort算法排序规则——>降序
	vector<int> v321_2;
	for (int i = 1; i < 7; i++)
	{
		int temp = i;
		if (i == 4)
		{
			for (int i = -1; i > -4; i--)
			{
				v321_2.push_back(i);
			}
		}
		i = temp;
		v321_2.push_back(i);
	}
	cout << "原数据：\n";
	for_each(v321_2.begin(), v321_2.end(), prt1);
	cout << "\n自订 sort排序后：\n";
	sort(v321_2.begin(), v321_2.end(),CdcOd());	//若未传入第三位参数(谓词)则默认为升序排列
	for_each(v321_2.begin(), v321_2.end(), prt1);
	cout << "\n\n";
}
#pragma endregion

	#pragma region 内建函数对象
//STL内置了一些函数对象，分为：算术仿函数、关系仿函数、逻辑仿函数
//使用这些内建函数对象需要包含头文件<functional>
#pragma region 算数仿函数
void test322()
{
	//二元运算：plus加、minus减、multiplies乘、divides除、modulus模
	plus<int> pl1;
	plus<string> pl2;	//需要同种数据类型操作
	cout << "int加操作：" << pl1(2, 3) << endl;
	cout << "string加操作：" << pl2("he", "llo") << endl;
	//一元运算：negate取反
	negate<int> n1;
	negate<float> n2;
	cout << "int取反操作：" << n1(5) << endl;
	cout << "float取反操作：" << n2(3.14f) << "\n\n";

}
#pragma endregion
#pragma region 关系仿函数
void test323()
{
	//equal_to等于、not_equal_to不等于、greater大于、greater_equal大于等于、less小于、less_equal小于等于
	vector<int> v323;
	for (int i = 1; i < 7; i++)
	{
		int temp = i;
		if (i == 4)
		{
			for (int i = 13; i > 10; i--)
			{
				v323.push_back(i);
			}
		}
		i = temp;
		v323.push_back(i);
	}
	cout << "排序前：\n";
	for_each(v323.begin(), v323.end(), prt1);
	cout << "\n排序后：\n";
	sort(v323.begin(), v323.end(), greater<int>());	//传入相应模板参数即可作为谓项实现降序
	for_each(v323.begin(), v323.end(), prt1);
	cout << "\n\n";
}
#pragma endregion
#pragma region 逻辑仿函数
void test324()
{
	//logical_and逻辑与、logical_or逻辑或、logical_not逻辑非
	vector<bool> v324;
	for (int i = 1; i < 6; i++)
	{
		if (i % 2 == 0)
		{
			v324.push_back(false);
		}
		else
		{
			v324.push_back(true);
		}
	}
	for (vector<bool>::iterator it = v324.begin(); it != v324.end(); it++)
	{
		cout << *it << "   ";
	}
	cout << endl;
	//利用逻辑非实现 bool类型容器取反搬运(transform)
	vector<bool> v3242;
	v3242.resize(v324.size());	//扩充空模板至待拷贝大小
	transform(v324.begin(),v324.end(),v3242.begin(),logical_not<bool>());//transform(源区间首,源区间末,目标迭代器,操作仿函数);
	for (vector<bool>::iterator it = v3242.begin(); it != v3242.end(); it++)
	{
		cout << *it << "   ";
	}
	cout << "\n\n";

}
#pragma endregion
#pragma endregion

#pragma endregion

#pragma region 常用算法
//<algorithm>：功能最多，涉及比较、交换、查找、遍历、复制、修改等
//<numeric>：功能较少，仅包括在序列上进行简单数学运算的模板函数
//<functional>：定义了一些模板类，用以声明函数对象

#pragma region 常用遍历算法
void nprint1(int n)
{
	cout << n << "  ";
}
class Cprint1
{
public:
	void operator()(int n)
	{
		cout << n << "  ";

	}
};
class Ctransf1
{
public:
	int operator()(int n)
	{
		cout << n+10 << "  ";
		return n+10;

	}
};
void test325()
{
	//1、for_each(遍历区间始,遍历区间末,操作函数)
	vector<int> v01;
	for (int i = 1; i < 9; i++)
	{
		v01.push_back(i);
	}
	cout << "普通函数作参数：\n";;
	for_each(v01.begin(), v01.end(), nprint1);		//普通函数名
	cout << "\n仿函数作参数：\n";
	for_each(v01.begin(), v01.end(), Cprint1());	//匿名仿函数对象
	cout << "\n\n";

	//2、transform(源区间首,源区间末,目标迭代器,操作函数)
	vector<int> v02;
	v02.resize(v01.size());
	transform(v01.begin(), v01.end(), v02.begin(), Ctransf1());	//遍历赋值并打印输出
	cout << endl;

}
#pragma endregion

#pragma region 常用查找算法
class Cfind
{
public:
	Cfind(char c,int i)
	{
		this->m_c = c;
		this->m_i = i;
	}
	bool operator==(const Cfind& cf)
	{
		if (cf.m_c == this->m_c && cf.m_i == this->m_i)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	char m_c;
	int m_i;
};
class Cfind_if
{
public:
	bool operator()(const Cfind& cf)
	{
		return cf.m_i > 5;	//int大于五
	}
};
void test326()
{
	//1、find(查找区间首,查找区间末,查找值)
	//查找指定元素，成功则返回指定元素迭代器，否则返回.end()
	vector<Cfind> v3261;
	for (int i = 7; i > 2; i--)
	{
		Cfind cf('X', i);
		v3261.push_back(cf);
	}
	Cfind fcf('X',3);
	//find底层实现需将查找值与区间内数据一一进行直接==判断
	//通过重载==操作符实现自订类型查找
	vector<Cfind>::iterator it1 = find(v3261.begin(), v3261.end(), fcf);
	cout << "find查找自订类型：" << it1->m_c << "   " << it1->m_i << endl;

	//2、find_if(查找区间首,查找区间末,操作函数)
	//按条件查找指定元素，成功则返回匹配条件首个元素迭代器，否则返回.end()
	vector<Cfind>::iterator it2 = find_if(v3261.begin(), v3261.end(), Cfind_if());
	cout << "find_if查找自订类型：" << it2->m_c << "   " << it2->m_i << endl;

	//3、adjacent_find(查找区间首,查找区间末)
	//查找连续重复数据，成功则返回该数个重复数据的首迭代器，否则返回.end()
	vector<int> v3263;
	v3263.push_back(1);
	v3263.push_back(2);
	v3263.push_back(1);	//此处"1"虽重复却并不连续，不符合
	v3263.push_back(3);
	v3263.push_back(3);	//符合
	v3263.push_back(4);
	vector<int>::iterator it3 = adjacent_find(v3263.begin(), v3263.end());
	cout << "查找连续重复数据：" << *it3 << endl;

	//4、binary_search(查找区间首,查找区间末,查找值)
	//(binary 二分)查找指定数据，成功返回 true,否则返回 false，在无序序列中使用时失准——>须升/降序结构
	vector<int> v3264;
	for (int i = 1; i < 10; i++)
	{
		v3264.push_back(i);	//以升序插入数据
	}
	bool b3264 = binary_search(v3264.begin(), v3264.end(), 6);
	b3264 == true ? cout << "成功\n" : cout << "失败\n";

	//5、count(统计区间首,统计区间末,给定值)
	//统计容器内给定数据的总数
	vector<Cfind> v3265;
	for (int i = 7; i > 2; i--)
	{
		Cfind cf('X', i);
		v3265.push_back(cf);
		if (i == 4) {v3265.push_back(cf);}
	}
	Cfind fcf3265('N', 4);
	cout << "统计自订数据数量：" << count(v3265.begin(), v3265.end(), fcf3265) << endl;	//需重载==操作符

	//6、count_if(统计区间首,统计区间末,操作函数)
	//按条件统计容器内数据
	vector<Cfind> v3266;
	for (int i = 7; i > 3; i--)
	{
		Cfind cf('X', i);
		v3266.push_back(cf);
	}
	cout << "自订数据 int值大于5数量：" << count_if(v3266.begin(), v3266.end(), Cfind_if()) << endl;
}
#pragma endregion

#pragma endregion



int main()
{
	test301();
	test302();
	test303();
	test304();
	test305();
	test306();
	test307();
	test308();
	test309();
	test310();
	test311();
	test312();
	test313();
	test314();
	test315();
	test316();
	test317();
	test318();
	test319();
	test320();
	test321();
	test322();
	test323();
	test324();
	test325();
	test326();

	system("pause");

	return 0;
}