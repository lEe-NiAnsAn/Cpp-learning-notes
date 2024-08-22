#include "class_fire.h"

Fire::Fire()
{
	int f_id = 0;
	string f_name = "无名";
	int f_rid = 0;
}
Fire::Fire(int id, string name, int rid)
{
	this->f_id = id;
	this->f_name = name;
	this->f_rid = rid;
}
void Fire::show_finfo()
{
	cout << "战斗员编号：" << f_id
		<< "   战斗员姓名：" << f_name
		<< "   职能：" << get_frole()
		<< "，构成火力点压制敌人\n\n";
}
string Fire::get_frole()
{
	return string("火力手");
}