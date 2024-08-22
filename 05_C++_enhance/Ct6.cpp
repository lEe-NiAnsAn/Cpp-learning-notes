#include "Ct6.h"

template<class T1, class T2>
Ct6<T1, T2>::Ct6(T1 a, T2 b)
{
	this->m_a = a;
	this->m_b = b;
}
template<class T1, class T2>
void Ct6<T1, T2>::show()
{
	cout << "Ct6成员函数\nm_a = " << this->m_a << "   m_b = " << this->m_b << "\n\n";
}