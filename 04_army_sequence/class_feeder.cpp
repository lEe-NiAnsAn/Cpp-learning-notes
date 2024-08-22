#include "class_feeder.h"

Feeder::Feeder()
{
	int f_id = 0;
	string f_name = "无名";
	int f_rid = 0;
}
Feeder :: Feeder(int id, string name, int rid)
{
	this->f_id = id;
	this->f_name = name;
	this->f_rid = rid;
}
void Feeder::show_finfo()
{
	cout << "战斗员编号：" << f_id
		<< "   战斗员姓名：" << f_name
		<< "   职能：" << get_frole()
		<< "，携带弹药警戒掩护\n\n";
}
string Feeder::get_frole()
{
	return string("装填手");
}