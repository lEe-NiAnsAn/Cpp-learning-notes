#include<iostream>
using namespace std;

#include "point.h"//包含头文件
//源文件中仅需成员函数的实现
//由于成员函数均编写于全局函数区域
//需要添加"作用域::"(类名::)声明其为成员函数
void Point::set_x(int x) {
	m_x = x;
}
int Point::get_x() {
	return m_x;
}

void Point::set_y(int y) {
	m_y = y;
}
int Point::get_y() {
	return m_y;
}