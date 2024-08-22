#include "class_observer.h"

Observer::Observer()
{
	int f_id = 0;
	string f_name = "无名";
	int f_rid = 0;
}
Observer::Observer(int id, string name, int rid)
{
	this->f_id = id;
	this->f_name = name;
	this->f_rid = rid;
}
void Observer::show_finfo()
{
	cout << "战斗员编号：" << f_id
		<< "   战斗员姓名：" << f_name
		<< "   职能：" << get_frole()
		<< "，携带补给配件提供视野射击\n\n";
}
string Observer::get_frole()
{
	return string("观察手");
}