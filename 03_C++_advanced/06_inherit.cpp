#include<iostream>
using namespace std;

#pragma region �̳еĻ����﷨
class Root	//����
{
public:
	void scenes() {
		cout << "��������\n";
	}
	void element() {
		cout << "����Ԫ��\n";
	}
	void effect() {
		cout << "����Ч��\n";
	}
};

class Node : public Root	//���๫���̳�
{
public:
	void object() {
		cout << "Node1��������\n\n";
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

#pragma region �̳з�ʽ

//1�������̳�:����������>����������������>������˽�С�X��>���ɷ���
//2�������̳�:����������>����������������>������˽�С�X��>���ɷ���
//3��˽�м̳�:����������>˽�У�����������>˽�У�˽�С�X��>���ɷ���

//�̳еĶ���ģ�ͣ�
//���ڿ�����Ա������ʾ����(Developer Command Prompt)�в鿴�����Ķ���ģ��
//1����ת�̷���D:��
//2����ת�ļ�·����cd D:\user\Desktop\SourceCode\C++\...��
//3���鿴�ļ��б�dir��
//4���鿴��cl /d1 reportSingleClassLayout���� �ļ�����
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
//���������г�Ա��������Ϊ���ּ̳з�ʽ���������������ڴ���
//������˽�г�ԱҲ���̳�������
//һ����̳������и���
void test02()
{
	cout << "Father����ռ�ڴ�Ϊ" << sizeof(Father) << "\n";
	cout << "Son����ռ�ڴ�Ϊ" << sizeof(Son) << "\n";
	cout << "Grandson����ռ�ڴ�Ϊ" << sizeof(Grandson) << "\n\n";
}

//�̳��й�������������
class Base
{
public:
	Base() {
		cout << "Base�Ĺ��캯��\n";
	}
	~Base() {
		cout << "Base����������\n";
	}
};
class Son_b : public Base
{
public:
	Son_b() {
		cout << "Son_b�Ĺ��캯��\n";
	}
	~Son_b() {
		cout << "Son_b����������\n";
	}
};

void test03()
{
	Son_b s_b1;
	//�ȹ��츸��
	//���ø��๹�캯����Ź�������
	cout << "\n\n";
}
#pragma endregion 

#pragma region �̳���ͬ������
//���ø����Ա����������������
class Bases
{
public:
	Bases() {
		m_a = 1;
	}
	void t() {
		cout << "�����Ա����\n";
	}
	void t(int a) {
		cout << "�������س�Ա����\n";
	}
	int m_a;
	static int m_b;
};
//��������ͬ����̬��Ա����������������
int Bases::m_b = 2;
//�����Ա��ֱ�ӵ���
class Sons : public Bases
{
public:
	Sons() {
		m_a = 10;
	}
	void t() {
		cout << "�����Ա����\n";
	}
	int m_a;
	static int m_b;
};
int Sons::m_b = 20;
//�������д��ڸ����ͬ����������ͬ�����ຯ�������Ƿ����ؾ����أ�������������������
void test04()
{
	Sons s_s;
	cout << "������ø����Ա������";
	s_s.Bases::t();
	cout << "������ø������س�Ա������";
	s_s.Bases::t(2);
	cout << "������������Ա������";
	s_s.t();
	cout<< "������ø����Ա������" << s_s.Bases::m_a
		<< "\n������������Ա������" << s_s.m_a << "\n"
//ͨ��������������ྲ̬��Ա�������������򣬷������ϲ���������������
		<< "���������ø��ྲ̬��Ա������" << s_s.Bases::m_b
		<< "\n�������������ྲ̬��Ա������" << s_s.m_b << "\n";
//ͨ������������ʹ����������е��ã������ϲ�����˫�㶨����
	cout << "����ͨ���������ø���ͬ����̬��Ա������" 
		<< Sons::Bases::m_b << "\n"
		 << "����ͨ��������������ͬ����̬��Ա������"
		<< Sons::m_b << "\n\n";
//����ͬ����̬��Ա����ͬ��
}
#pragma endregion

#pragma region ��̳�
//��������̳ж������
//��̳п���������ͬ����Ա���⣬��Ҫ��������������
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
	cout << "ӵ���������������ռ�ڴ棺" << sizeof(c) << endl
		<< "�����е�ͬ����Ա������" << c.m_a << "\n"
		<< "����һ�е�ͬ����Ա������" << c.father01::m_a << "\n"
		<< "������е�ͬ����Ա������" << c.father02::m_a << "\n\n";
}
#pragma endregion

#pragma region ���μ̳�
//��������̳�ͬһ���࣬����һ��������ͬʱ�̳д���������
//���⣺	1��ͬ����Ա����
//		2�����������ظ��̳����������м̳е���ͬ�����Ա��ͬ����Ա
class base_c
{
public:
	/*base_c() {
		m_a = 0;
	}*/
	int m_a;
};
//ʹ����̳йؼ���virtual�������
//��ʱson01��son02�̳з�ʽΪ��̳�,base_c��Ϊ�����
class son01 :virtual public base_c {};
class son02 : virtual public base_c {};

class g_son :public son01, public son02{};

void test06()
{
	g_son gs;
	gs.base_c::m_a = 0;
	gs.son01::m_a = 10;
	gs.son02::m_a = 20;
	//��������������й���һ��m_a��Ա
	//�޸���һ��������m_a��ͬʱӰ����һ�������������m_a�ĵ���
	cout << "���μ̳����������ڴ棺" << sizeof(gs) << "\n"
	//��ʱ�ڴ�ռ��Ϊ����m_a��������һm_a��vbptrָ�룬�������m_a��vbptrָ��	
	//vbptrָ��vbtable
	//v-virtual�顢b-base���ࡢptr-pointerָ�롢table-��
	//�������¼���ڴ��ַ��ƫ������������vbptr����ƫ������ָ�����m_a
		<< "�����������������һ������̳еĻ����Ա������"
		<< gs.son01::m_a << "\n"
		<< "������������������������̳еĻ����Ա������"
		<< gs.son02::m_a << "\n"
	//��ʱ������������๲��m_a������������ȷ�����
		<< "����������ʻ����Ա������" << gs.m_a << "\n\n";
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