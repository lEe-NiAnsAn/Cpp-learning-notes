#include<iostream>
using namespace std;

#include "point.h"//����ͷ�ļ�
//Դ�ļ��н����Ա������ʵ��
//���ڳ�Ա��������д��ȫ�ֺ�������
//��Ҫ���"������::"(����::)������Ϊ��Ա����
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