#include "class_commanders.h"

Commander::Commander()
{
	int f_id = 0;
	string f_name = "无名";
	int f_rid = 0;
}
Commander::Commander(int id, string name, int rid) 
{
	this->f_id = id;
	this->f_name = name;
	this->f_rid = rid;
}
void Commander::show_finfo()
{
	cout << "战斗员编号：" << f_id
		<< "   战斗员姓名：" << f_name
		<< "   职能：" << get_frole()
		<< "，组织搭建火力网协同推进\n\n";
}
string Commander::get_frole()
{
	return string("战斗组长");
}