#include<iostream>
using namespace std;
#include "point.h"

const double Pi = 3.14;

#pragma region һ ��ķ�װ
	#pragma region ��Ķ���
//����������Ĭ��Ϊ˽��		//�ṹ����������Ĭ��Ϊ����
class Circle
{//1������Ȩ�ޣ��������������
public:		
	//2��(��Ա)����
	int m_r = 1;
	//3��(��Ա)����
	double m_perimeter() {
		return 2 * m_r * Pi;
	}

//����Ȩ�ޣ��������ڷ���,����������ʱ�������
protected:
	int m_loca_x = 1;
	int m_loca_y = 1;

//˽��Ȩ�ޣ����������ڷ��ʣ��������������˽������
private:
	string m_color = "white";
};
	#pragma endregion

	#pragma region ˽�л���Ա����
//��ֹ�����޸ĳ�Ա����
class Squre
{
private:
	int m_len = 1;			//�߳�
	bool m_solid = true;	//ʵ��
	string m_color = "red";	//��ɫ

public:
	//�ɶ���д
	void m_setLen(int len) {
		if (len < 0) {		//���������Ч��
			cout << "������������\n\n";
			return;
		}
		m_len = len;
	}
	int m_showLen() {
		return m_len;
	}
	//ֻ��
	bool m_show() {
		if (m_solid == true) {
			cout << "�������α߳���ʵ�ĵ�" << "\n\n";
		}
		else{
			cout << "�������α߳��ǿ��ĵ�" << "\n\n";
		}

		return m_solid;
	}
	//ֻд
	void m_setColor(string color ) {
		m_color = color;
	}
	//�������
	int m_area() {
		return m_len * m_len;
	}

};
	#pragma endregion

	#pragma region ��ķ��ļ�����
//1����ͷ�ļ������.h�ļ��������Լ���Ա
//2����Դ�ļ������.cpp�ļ�ʵ�ֳ�Ա����
//3������ͷ�ļ�����ʹ����
class Distane
{
public:
	//ʹ����һ���Ա��Ϊ����
	void set_p1(Point p1) {
		m_p1 = p1;
	}
	void set_p2(Point p2) {
		m_p2 = p2;
	}
	//��������ƽ��
	int func_lon() {
		return (m_p1.get_x() - m_p2.get_x()) * (m_p1.get_x() - m_p2.get_x()) +
			(m_p1.get_y() - m_p2.get_y()) * (m_p1.get_y() - m_p2.get_y());
	}
	void show() {
		m_lon = func_lon();
		cout << "��������ƽ��Ϊ" << m_lon << "\n\n";
	}

private:
	int m_lon;
	//��������һ��Ķ�����Ϊ��Ա
	Point m_p1;
	Point m_p2;
};
	#pragma endregion

#pragma endregion

#pragma region �� ����ĳ�ʼ��������
//����ĳ�ʼ��������Ϊ������ǿ�������Ҫ��ʼ����������������ʱ����
//(������һ�����C++���Զ������������������졢�������������캯����
//(�������캯���������Խ��п���,�ǿ�ʵ��)
	#pragma region ���캯�������������Ķ���
//���������Զ����ö�Ӧ��������δ�����ṩ������������Զ��ṩ"��ʵ��"�Ĺ��졢��������
class Test01
{
public:			//λ�ڹ���Ȩ����
	//1�����캯�����ڴ�������ʱ�Զ�����һ��Ϊ���ʼ��������д�������������أ�
	Test01()//������������һ�£�����������������(void)
	{
		cout << "Test01��Ĺ��캯��\n";
	}			//�޷���ֵ

	//2�������������ڶ�������ǰ�Զ�ִ��һ����������������д�������������أ�
	~Test01()	//������Ϊ"~����"������������������(void)
	{
		cout << "Test01�����������\n\n";
	}			//�޷���ֵ

};

void test01()
{
	Test01 t;

	return;
}
	#pragma endregion

	#pragma region ���캯���ķ��༰����
class Test02
{
public:	
//��ͨ����
	Test02() {	//�޲ι��죨Ĭ�Ϲ��죩
		m_numb = 0;
		cout << "Test02����޲ι��캯��\n";
	}
	Test02(int i) {	//�вι���
		m_numb = i;
		cout << "Test02����вι��캯��\n";
	}
//��������
	Test02(const Test02& t) {	//ͨ�����ж��󿽱��¶���
		m_numb = t.m_numb;			//�������г�Ա����
		cout << "Test02��Ŀ������캯��\n";
	}
//���캯�����ù���
//1�������������вι��캯������C++���ṩĬ�Ϲ��캯���������ṩĬ�Ͽ������캯��
//(����δ�������忽�����캯��ʱ����ͬ�������캯���Ĳ�����C++���Զ��ṩĬ�Ͽ������캯��������ֵ����)
//(��ʱ��ʹ���޲ι������䴴�����󽫱���)
//2�������������˿������캯������C++�����Զ��ṩ�κι��캯��

	int out() {
		return m_numb;
	}

	~Test02() {
		cout << "Test02�����������\n\n";
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

	#pragma region �����ǳ����
//δ�Զ��������캯����ǳ����
class Test03
{
public:
	Test03() {
		m_numb = 0;
		m_pn = NULL;
		cout << "Test03����޲ι��캯��\n";
	}
	Test03(int numb) {
		m_numb = numb;
		m_pn = NULL;
		cout << "Test03����вι��캯��һ\n";
	}
	Test03(int numb, int pn) {
		m_numb = numb;
		m_pn = new int(pn);	//�ڶ��������ڴ���m_pn
		cout << "Test03����вι��캯����\n";

	}

	~Test03() {
		if(m_pn !=NULL){	//�ж϶���m_pn�Ƿ����
			delete m_pn;	//�����ͷŶ�����m_pn
			m_pn = NULL;	//��m_pn�ÿգ���ֹҰָ����ֵ�������
		}
		cout << "Test03�����������\n\n";
	}

	int m_numb;
	int* m_pn;
};

//�Զ��������캯�������
class Test04
{
public:
	Test04(int numb, int pn) {
		m_numb = numb;
		m_pn = new int(pn);	
		cout << "Test04����вι��캯��\n";
	}
	Test04(const Test04& t) {
		m_numb = t.m_numb;
		m_pn = new int(*t.m_pn);	//�����ڶ��������ڴ�
		cout << "Test04��Ŀ������캯��\n";
	}

	~Test04() {
		if (m_pn != NULL) {	
			delete m_pn;	
			m_pn = NULL;	
		}
		cout << "Test04�����������\n\n";
	}

	int m_numb;
	int* m_pn;
};


	#pragma endregion

	#pragma region ��ʼ���б�
//���ڳ�ʼ����Ա����
class Test05
{
public:
	//m_t(0) �ȼ��� Test02 t = 0������Test02��ʽ���캯������������ΪTest05��Ա
	Test05():m_num1(0), m_num2(0), m_num3(0), m_t(0)	//��ʼ���б� 
	{	
		cout << "Test05����޲ι��캯��\n";
	}
	Test05(int num1, int num2, int num3, int t) //�˴����ȹ���Test02��������m_t�������봫��Test02��ֵ
		:m_num1(num1), m_num2(num2), m_num3(num3), m_t(t){
		cout << "Test05����вι��캯��\n";			
	}//���ó�ʼ���б�������ڹ��캯����ʵ���ڸ�ֵ(һһ��Ӧ)
	Test05(const Test05& t) {
		m_num1 = t.m_num1;
		m_num2 = t.m_num2;
		m_num3 = t.m_num3;
		cout << "Test05��Ŀ������캯��\n";
	}

	~Test05() {
		cout << "Test05�����������\n\n";
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

	#pragma region ��̬��Ա
//�ڳ�Ա���ԡ�����ǰ��static�ؼ��ּ�Ϊ��̬��Ա
//��̬��Ա�����౾��������ĳһ����
class Test06
{
public:
	Test06() {
		cout << "Test06����޲ι��캯��\n";
	}
	Test06(const Test06& t) {
		cout << "Test06��Ŀ������캯��\n";
	}

	void return_mB(int b) {
		mB = b;
		show_mB();
	}

	void return_mA(int a) {
		mA = a;
		show_mA();
	}

//��̬��Ա����
	//1�����г�Ա����һ������
	//2����̬��Ա�������ɷ��ʾ�̬��Ա����
	static void show_mB() {
		cout << "mB=" << mB << endl;
	}
	//3��ӵ�з���Ȩ������

	~Test06() {
		cout << "Test06�����������\n\n";
	}

//��̬��Ա������
	//1�����ж�����һ�����ݣ��޸�ͬ����
	//2���ڱ���׶η����ڴ棨��������ǰ��ȫ������
	//3�����������������ʼ��
	static int mA;
	//4��ӵ�з���Ȩ������
private:
	static int mB;

	static void show_mA() {
		cout << "��̬��Ա��������mA=" << mA << endl;
	}
};
int Test06::mA = 1;		//�����ʼ�������������������򣬷���������Ὣ����Ϊȫ�ֱ���
int Test06::mB = 10;	//�����޷�ֱ�ӷ���
	#pragma endregion

#pragma endregion

#pragma region �� �������

	#pragma region thisָ��
//���ഴ��ʱ�Ŀն�����Ȼռ��һ�ֽ��ڴ棬Ŀ��Ϊ��������ռ�ڴ��ַ
class Test07
{
};
//ӵ�зǾ�̬��Ա��������Ķ���ռ�е��ڴ��Ϊ�Ǿ�̬��Ա������ռ�ڴ��С
//��̬��Ա��Ǿ�̬��Ա�����������������ڴ��С
//�޷Ǿ�̬��Ա��������Ķ�����ռ�ڴ���ڿն����ڴ��С
class Test08
{
	int m_v; //�Ǿ�̬��Ա�������ڶ���
	void m_func() {} //�Ǿ�̬��Ա���������ڶ���
	//��̬��Ա�������ڶ���
	static int m_s_v;
	static void m_s_func() {} 
};
//�Ǿ�̬��Ա����������һ�ݺ���ʵ����������ͬ��������

class Test09
{
public:
	Test09() {
		num = 1;
		cout << "Test09����޲ι��캯��\n";
	}
//thisָ��Ϊָ�볣��
//thisָ��ָ�򱻵��õķǾ�̬��Ա���������Ķ���
//thisָ��������ÿһ�Ǿ�̬��Ա���������붨���ֱ��ʹ��
	//1������ͬ���β����Ա����
	Test09(int num) {
		this->num = num; //this->num��Ϊ�����ڳ�Աnum�������β�num
		cout << "Test09����вι��캯��\n";
	}
	//2���ڷǾ�̬��Ա������ʹ�á�return* this;�����ض���������޸�
	//��Ҫ���ر��������Test09&�����򽫷��ؿ���ֵ���޷����ı����ֵ
	Test09& m_add(Test09& t) {	//ʹ�����ý�Լ�ڴ�
		this->num += t.num;	//������һ���󲢽���numֵ������num���

		return*this;	//��������Ϊ��������ã�
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
		cout << "Test10����޲ι��캯��\n";
	}
	void show() {
		cout << "Test10��show����\n";		//δ���ó�Ա�����ĳ�Ա����
	}
	void v_show() {
		cout << "m_num=" << m_num << endl;	//���ó�Ա�����ĳ�Ա����
	}

private:
	int m_num;
};
	#pragma endregion

	#pragma region const���γ�Ա
//��������
//1���������ڲ����޸ĳ�Ա����
//2�������������޸ļ���mutable�ؼ��ֺ�ĳ�Ա����
class Test11
{
public:
	Test11() {
		m_a = 1;
		m_b = 10;
	}
	//������������
	void c_show() const //��ʱ�ú����ڵ��ó�Ա�����൱�ڡ�const Test11* const this;���������޸�this��ָ�����ַ
	{
		//�Ƿ���this->m_a = 1;	//thisָ��Ϊ����
		m_b = 2;
	}

	void return_b(int b) {
		m_b = b;
		cout << "m_b=" << m_b << endl;
	}

	int m_a;
	mutable int m_b;	//�������
};
	#pragma endregion

	#pragma region ��Ԫ
//ʹ������ĺ�������ȷ���˽�г�Ա
class Test12;
//��Ԫ��
class Test_f
{
public:
	Test_f();
	void visit();

private:
	Test12* t;
};
//��Ԫ��Ա����
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
	//1��������Ԫ
	friend class Test_f;
	//2����Ա��������Ԫ
	friend void Test_frind::f_visit();
	//3��ȫ�ֺ�������Ԫ
	friend void f_func(const Test12& t);

public:
	Test12();
	int m_publ;
//private:
	int m_priv;
};

//��Ԫȫ�ֺ���
void f_func(const Test12& t)
{
	cout << "������Ա���ʣ�" << t.m_publ << endl;
	cout << "˽�г�Ա���ʣ�" << t.m_priv << "\n\n";
}

//����ʵ�ֳ�Ա����
Test12::Test12()
{
	m_publ = 1;
	m_priv = 10;
	cout << "Test12����޲ι��캯��\n";
}
Test_f::Test_f() {
	t = new Test12;	//newһ��ָ��Test12��Ķ����ָ�룬����Test12�Ĺ��캯��
	cout << "Test_f����޲ι��캯��\n";
}
void Test_f::visit() {
	cout << "������Ա���ʣ�" << t->m_publ << endl;
	cout << "˽�г�Ա���ʣ�" << t->m_priv << "\n\n";
}
Test_frind::Test_frind() {
	t = new Test12;
	cout << "Test_frind����޲ι��캯��\n";
}
void Test_frind::f_visit()
{
	cout << "������Ա���ʣ�" << t->m_publ << endl;
	cout << "˽�г�Ա���ʣ�" << t->m_priv << "\n\n";
}
	#pragma endregion

#pragma endregion

int main4()
{
#pragma region ʵ������Ķ���
	Circle c1;	//����
	c1.m_r = 2;	//��ʼ��
	cout << "c1���ܳ�Ϊ" << c1.m_perimeter() << "\n\n";//�������к���

	Squre s1;
	s1.m_setLen(2);		//д��߳�
	cout << "s1�ı߳�Ϊ" << s1.m_showLen() << "\n\n";	//��ȡ�߳�
	bool s1_solid = s1.m_show();		//��ȡʵ��
	s1.m_setColor("blue");				//д����ɫ
	int s1_area = s1.m_area();			//�������
#pragma endregion

#pragma region ���ļ���ĵ���
	//����Point��
	Point p1; Point p2;
	p1.set_x(1); p1.set_y(1);
	p2.set_x(4); p2.set_y(3);
	//����Distance��
	Distane d1;
	d1.set_p1(p1); d1.set_p2(p2);
	d1.show();
#pragma endregion

#pragma region ����Ĺ���������
	Test01 t1;	//ջ�����ݣ�main������������
	cout << endl;
	test01();	//ջ�����ݣ�test01������������
//��ͬ���캯���ĵ���
	//1�����ŷ�
	Test02 t2;		//�޲ε���(ע�⣺��������,�����������Ὣ����Ϊ������������
	Test02 t3(10);	//�вε���
	Test02 t4(t3);	//��������
	//2����ʾ��
	Test02 t5 = Test02(20);	//�вε���
	Test02 t6 = Test02(t5);	//��������
	//Test02(20)��Test02(t5)Ϊ��������ִ�н�����ϵͳ����������
	//(ע��:����ʹ�ÿ������ó�ʼ���������󡪡�>��Test02(t5);���ȼ��ڡ�Test02 t5;��)
	//3����ʽת��������ʱ�����bug��
	Test02 t7 = 30;//�ȼ��� Test02 t7 = Test02(30);
	Test02 t8 = t7;//�ȼ��� Test02 t8 = Test02(t7);

	//�������캯���ĵ���ʱ��
	//1��ͨ�����ж��󿽱���������
	//2��ֵ���ݺ����������п���
	Test02 t9;
	test02_1(t9); //��ͬ�����ŷ���������
	//����ֵ���ݣ��˷�ʽ���޸Ŀ���ֵ����Ӱ��ԭֵ

	//3����ֵ��ʽ���صĿ������е���
	Test02 t10 = test02_2();//�ֲ������ķ���ֵΪ����ֵ
#pragma endregion

#pragma region ����Ŀ���
	//ǳ�������򵥵ĸ�ֵ����
	//ʹ��C++�Զ����ɵĿ������캯�����ж���Ŀ���
	Test03 t11(1);		//ʹ���вι���һ��������
	cout << "numb=" << t11.m_numb << endl;
	Test03 t12(t11);	//��t11ǳ������t12
	cout << "numb=" << t12.m_numb << "\n\n";
	//ǳ����������ִ�������������������Աʱ�ظ��ͷ�ͬһ�����ڴ�
	//Test03 t13(1, 11);		//ʹ���вι������������
	//Test03 t14(t13);			//��t13ǳ������t14������ָ������m_np
	//cout << "numb=" << t13.m_numb << "pn=" << *t13.m_pn << endl;	
	//cout << "numb=" << t14.m_numb << "pn=" << *t14.m_pn << endl;	
	//��ʱ����m_pn��ָ������ݽ�����

	//������ڶ�����������ռ���п���
	Test04 t13(2,12);
	cout << "numb=" << t13.m_numb << "\tpn=" << *t13.m_pn << endl;
	Test04 t14(t13);
	cout << "numb=" << t14.m_numb << "\tpn=" << *t14.m_pn << "\n\n";
#pragma endregion

#pragma region ʹ�ù��캯����ʼ���б�������
	Test05 t15;
	t15.show();
	Test05 t16(1,2,3,4);
	t16.show();
#pragma endregion

#pragma region ��̬��Ա�ĵ���
	Test06 t17;
	Test06 t18;
	//���ʾ�̬��Ա����
	cout << "mA=" << Test06::mA << endl;
	cout << "����һmA=" << t17.mA << endl;
	t17.mA = 2;
	//�޸ľ�̬��Ա����
	cout << "�޸Ķ���һ������mA=" << t18.mA << endl;
	//ͨ������������д˽�о�̬��Ա����
	t18.return_mB(20);
	//���þ�̬��Ա����
	Test06::show_mB();	//ͬ����ͨ������t18.���е���
	//ͨ������������д˽�о�̬��Ա����
	t18.return_mA(30);
	cout << endl;
#pragma endregion

#pragma region ������ڴ����
	Test07 t19;
	cout << "�ն�����ڴ��СΪ" << sizeof(t19) << endl;
	Test08 t20;
	cout << "ӵ�зǾ�̬��Ա�����Ķ�����ڴ��СΪ" << sizeof(t20) << endl;

	Test09 t21;
	t21.show();
	Test09 t22(10);
	t22.show();
	t21.m_add(t22).m_add(t22).m_add(t22);	//ʵ����ʽ���
	t21.show();

	//��ָ����ʳ�Ա���������Ա���������ڶ��󣬵��ó�Ա����δ���ó�Ա����ʱ����δ�����������ʱ����
	Test10* t_p = NULL;	//������ָ��
	t_p->show();		//��ָ����ʳ�Ա����
	//t_p->v_show();	//�Ƿ���������ָ�벢û�д�������Ķ����޷����ʲ����ڵĳ�Ա����

#pragma endregion 

#pragma region ������
//������
//1����������ɵ��ó�����
//2��������Ҳ�ɷ���mutable���εĳ�Ա����
// ������Ĵ���
	const Test11 t23;
	//�Ƿ���	t23.m_a = 0;
	//		t23.return_b(12);
	t23.m_b = 12;
#pragma endregion

#pragma region ��Ԫ����
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