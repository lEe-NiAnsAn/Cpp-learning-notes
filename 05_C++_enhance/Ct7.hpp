#pragma once
#include <iostream>
using namespace std;

template<class T1, class T2>
class Ct7
{
public:
	Ct7(T1 a, T2 b);
	void show();
	T1 m_a;
	T2 m_b;
};

template<class T1, class T2>
Ct7<T1, T2>::Ct7(T1 a, T2 b)
{
	this->m_a = a;
	this->m_b = b;
}
template<class T1, class T2>
void Ct7<T1, T2>::show()
{
	cout << "Ct7成员函数\nm_a = " << this->m_a << "   m_b = " << this->m_b << "\n\n";
}