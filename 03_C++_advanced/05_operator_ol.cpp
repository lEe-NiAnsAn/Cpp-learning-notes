#include <iostream>
using namespace std;

//���������
//�������������������ͣ�C++�ɵ�������������й��ܽ������㣬��������
//�����Զ��������ͣ���Ҫ���������ʵ�ֶ��������
//ʹ�����ú�������������
//ע�⣺�����������������

#pragma region �Ӽ������������
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
//��Ա��������
	Numb operator+ (Numb& n) {
		Numb temp;
		temp.m_a = this->m_a + n.m_a;
		temp.m_b = this->m_b + n.m_b;
		return temp;
	}
};

//ȫ�ֺ�������
Numb operator- (Numb& n1,Numb& n2) 
{
	Numb temp;
	temp.m_a = n1.m_a - n2.m_a;
	temp.m_b = n1.m_b - n2.m_b;
	return temp;
}

//���������Ҳ�ɽ�����ͨ����������
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
	//��Ա�������ر��ʵ���
	n3 = n1.operator+(n2);
	cout << "n1 + n2 = n3 = (" << n3.m_a << ", " << n3.m_b << ")\n\n";
}

void subOL()
{
	Numb n1(4, 40);
	Numb n2(1, 10);
	Numb n3 = n1 - n2;
	//ȫ�ֺ������ر��ʵ���
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

#pragma region �������������
//������������������С�<<��
class Person
{
	friend ostream& operator<<(ostream& cout, Person p);
	//ʹ����Ԫ����˽�г�Ա
public:
	Person() {
		m_lname = "��";
		m_fname = "��";
	}
	Person(string l, string f) {
		m_lname = l;
		m_fname = f;
	}
	//��Ա��������
	//void operator<<(cout) 
	//����ʱ�ȼ���p.operator<<(cout),��Ϊp << cout
	//��һ�㲻ʹ�ó�Ա�����������������,�޷�ʵ��coutλ�����Դ���
private:
	string m_lname;
	string m_fname;
};
//ȫ�ֺ�������
//ͨ����ת�����塱�ɲ鿴cout�������ͣ�out stream(��׼���������)
ostream& operator<<(ostream& cout, Person p)
//cout����ȫ�����ҽ���һ��,���ɿ���������ʹ�����ô����β�

{
	cout << p.m_lname << p.m_fname;

	return cout;
}//����ֵΪcout���ÿ�ʵ����ʽ��̣��ɼ���ʹ��<<�����Person���ݣ�

void coutOL(string l, string f)
{
	Person p(l,f);
	cout << p << "\n\n";
}
#pragma endregion

#pragma region �������������
class MyInt	//�Զ������α���
{
	friend ostream& operator<<(ostream& cout, MyInt i);
	friend void showMyInt();
public:
	MyInt() {
		m_num = 0;
	}
	//��Ա��������ǰ�õ��������
	MyInt& operator++() {
		m_num++;
		return*this;//�������������
	}
	//��Ա�������غ��õ��������
	MyInt operator++(int) {
		MyInt temp = *this;//��ʱ�Ĵ�ԭֵ
		m_num++;
		return temp;//���������ֵ����tempΪ�ֲ���������������Ϊ�Ƿ���
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
	cout << "ǰ�õ���:i= " << i;
	cout << "\ti++=" << i++;
	cout << "\ti=" << i << endl;
	i.m_num = 0;
	cout << "���õ���:i= " << i;
	cout << "\t++i=" << ++i;
	cout << "\ti=" << i << "\n\n";
}
#pragma endregion

#pragma region ��ֵ���������
//C++Ϊ���Զ���ӵĵ��ĸ�����Ϊ��ֵ����������������Խ���ֵ����
class Numbe
{
	friend void show_n();
public:
	Numbe() {
		m_n = new int(0);
	}
	Numbe(int n) {
		m_n = new int(n);	//�ڶ��������ڴ洢��nֵ����ʹ��m_nָ��ά��
	}						//��Ҫ�ֶ��ͷ�

	~Numbe() {
		if (m_n != NULL) {
			delete m_n;
			m_n = NULL;
		}
	}
	//ǳ�����������ڴ��ظ��ͷŵĴ���
	//�������ظ�ֵ�������ֹǳ����m_n
	//��Ա�������ظ�ֵ�����ʹ��������
	Numbe& operator=(Numbe& n) {
		//�ж��Ƿ����ڶ��������ڴ�
		if (this->m_n != NULL) {
			delete this->m_n;
			this->m_n = NULL;
		}
		this->m_n = new int(*n.m_n);

		return*this;	//���ض�����������ʵ����ʽ���
	}

private:
	int* m_n;	//ָ���Ա����
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
	cout << "n1=n2=n3��\tn1.= " << *n1.m_n 
				<< "\tn2.=" << *n2.m_n << "\n\n";
}
#pragma endregion

#pragma region ��ϵ���������
//==ȫ�ֺ�������
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

#pragma region �����������������
//���������������()
//���صĺ��������������ʹ�÷�ʽ�뺯��ʮ�����ƣ��ʳ�Ϊ���º�����
//�º����޹̶�д����ʮ�����
class MyPrint	//�Զ���ӡ�����
{
public:
	//����()��
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
//������������ʡ���˴�������º�������Ĳ��裬������������д���������ͷ���������
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