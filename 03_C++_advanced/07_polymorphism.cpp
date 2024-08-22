#include<iostream>
using namespace std;

#pragma region ��̬�Ļ�������
//1����̬��̬��������������������أ����ú�������
//��̬��̬������ַ��󶨡���>����׶�ȷ��������ַ
//2����̬��̬�����������麯��ʵ������ʱ��̬
//��̬��̬������ַ��󶨡���>���н׶�ȷ��������ַ
class Base01
{
public:
	void func01() {
		cout << "����һ��Ա��������" << endl;
	}
};
class Base02
{
public:
	//ͨ��virtual�ؼ��ִ����麯��ʵ�ֵ�ַ���
	virtual void func02() {
		cout << "�������Ա��������" << endl;
	}
};
//v-virtual f-function ptr-pointer
//�����麯�������ڽ�����vfptr����ָ��ָ���麯����(vftable)
//vftable�ڲ���¼������麯����ַ
class Son01 : public Base01
{
public:
	void func01() {
		cout << "����һ��Ա��������" << endl;
	}
};
class Son02 : public Base02
{
public:
	//��Ϊ�̳У�����̳и����Ա��������
	//������virtual�ؼ��ֿ��п���
	virtual void func02() {
		cout << "�������Ա��������" << endl;
	}//��������д�����麯��ʱ����������vftable��������
	//��ʱvftable����¼������麯����ַ�����Ǹ����麯����ַ
};

//������ַ���
void dofunc01(Base01& b1)
{
	b1.func01();//��Weapon��
}
//������ַ���
void dofunc02(Base02& b2)
{
	b2.func02();//�󶨴���Ķ�����������
}
//��̬��̬ʵ�֣�
//1�����ڼ̳й�ϵ
//2����������д�����麯����ͬ��ͬ�ζ�������
//3����������ָ��(������)ָ������Ķ��󡪡�>�βΣ��������ָ�� / ʵ�Σ��������
//����>��ʱ�����������vftable����ָ�������麯����vfptr���ʵ��������Ա����

void test11()
{
	Son01 s1;
	//���ú���Ϊ�����Ա����
	dofunc01(s1);//C++������������ǿ�Ƶ��Զ�����ת��
	//���ú���Ϊ�����Ա����
	Son02 s2;
	dofunc02(s2);
	//δʹ���麯���ĸ����ڴ���ڿ���
	cout << "����Base01��ռ�ڴ��СΪ" << sizeof(Base01) << endl;
	//ʹ���麯���ĸ����ڴ�Ϊ�麯��ָ���С
	cout << "����Base02��ռ�ڴ��СΪ" << sizeof(Base02) << endl;
}
#pragma endregion

#pragma region ��̬������������
//��̿���ԭ�򣺶���չ���ţ����޸Ĺر�
//ʵ�ּ�����������
class Calculator
{
public:
	int m_n1 = 0;
	int m_n2 = 0;
	virtual int result() {
		return 0;
	}
};
//�ӷ���������
class Add : public Calculator
{
public:
	virtual int result() {
		return m_n1 + m_n2;
	}
};
//������������
class Sub : public Calculator
{
public:
	virtual int result() {
		return m_n1 - m_n2;
	}
};
//�˷���������
class Mult : public Calculator
{
public:
	virtual int result() {
		return m_n1 * m_n2;
	}
};
//������������
class Div : public Calculator
{
public:
	virtual int result() {
		return m_n1 / m_n2;
	}
};
//���������������
void calcu_func(int n1, string op, int n2, Calculator*& cp)
{
	cp->m_n1 = n1;
	cp->m_n2 = n2;
	cout << cp->m_n1 << " " << op << " "
		<< cp->m_n2 << " = "
		<< cp->result() << endl;
	delete cp;//�������ݼ�ʱ����
}
void test12()
{
	//����ָ��ָ���������
	//1���ӷ�
	Calculator* cp = new Add;
	calcu_func(10, "+", 2, cp);	
	//2������
	cp = new Sub;
	calcu_func(10, "-", 2, cp);
	//3���˷�
	cp = new Mult;
	calcu_func(10, "*", 2, cp);
	//4������
	cp = new Div;
	calcu_func(10, "/", 2, cp);
}
#pragma endregion

#pragma region ���麯���������
//��̬�и����麯������ʵ�ֺ������壬ͨ��ͨ��������д����
//�ʿɽ������Ϊ���麯��
//һ��ӵ�д��麯�����༴Ϊ������
//ע�⣺	1�������಻��ʵ����
//		2������������������д���ി�麯����������Ϊ������

class abstrct
{
public:
	//�������麯��
	virtual void ifunc() = 0;
};
#pragma endregion

#pragma region �������ʹ�������
//��ʹ�ö�̬ʱ��������������乹�캯��������������������(���ڸ������������)
//�������ڶ����������ڴ棬��ʹ�����������������ڶ�̬�е����������������ͷŶ����ڴ�
//�������봿�����������������ʵ�ִ���
//����������������������Ϊ������

class Base03
{
public:
	Base03() {
		cout << "Base03�Ĺ��캯��" << endl;
	}
	//��������������
	//virtual ~Base03() {
	//	cout << "Base03����������" << endl;
	//}
	//����������������
	virtual ~Base03() = 0;
	virtual void ifunc03() = 0;
};
//�����ⴿ������������ʵ��
Base03:: ~Base03()
{
	cout << "Base03�Ĵ�����������" << endl;
}
class Son03 : public Base03
{
public:
	Son03(int a) {
		m_a = new int(a);//�ڶ��������ڴ洢������
		cout << "Son03�Ĺ��캯��" << endl;
	}
	//����ʹ���������󽫵���������������
	//����virtual�ؼ���Ϊ�Ǳ����
	virtual ~Son03() {
		if (m_a != NULL) {
			cout << "Son03���������캯��" << endl;
			delete m_a;
			m_a = NULL;
		}
	}
	virtual void ifunc03() {
		cout << "����Son03�������ݣ�" << *m_a << endl;
		cout << "Son03�ĸ�д��Ա��������" << endl;
	}
	int* m_a;//ʹ��ָ��ά�������ڶ���������

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