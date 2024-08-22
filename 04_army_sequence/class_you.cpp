#include "class_you.h"

You::You()
{
	int f_id = 0;
	string f_name = "无名";
	int f_rid = 0;
}
You::You(int id, string name, int rid)
{
	this->f_id = id;
	this->f_name = name;
	this->f_rid = rid;
}
void You::show_finfo()
{
	cout << "战斗员编号：" << f_id
		<< "   战斗员姓名：" << f_name
		<< "   职能：" << get_frole()
		<< "————其实你也不算清楚自己应该怎么做。。。\n\n";
}
string You::get_frole()
{
	return string("小队长");
}