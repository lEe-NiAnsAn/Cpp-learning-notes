#pragma once
#include <iostream>
using namespace std;

template<class T1, class T2>
class Ct6
{
public:
	Ct6(T1 a, T2 b);
	void show();
	T1 m_a;
	T2 m_b;
};