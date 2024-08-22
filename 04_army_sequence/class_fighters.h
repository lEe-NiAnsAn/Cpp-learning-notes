#pragma once
#include<iostream>
using namespace std;

class Fighter	//抽象类无须.cpp文件
{
public:
	virtual void show_finfo() = 0;	//显示信息
	virtual string get_frole() = 0;	//获取职能

	int f_id;			//战斗员编号
	string f_name;		//战斗员姓名
	int f_rid;			//职能编号
};