#pragma once //防止头文件重复包含
#include<iostream>
using namespace std;

//头文件仅需成员的声明

class Point
{
public:
	void set_x(int x);
	int get_x();

	void set_y(int y);
	int get_y();

private:
	int m_x;
	int m_y;
};