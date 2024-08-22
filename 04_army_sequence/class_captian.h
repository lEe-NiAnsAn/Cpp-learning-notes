#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include "class_fighters.h"
#include "sclear.h"
#include "cin_error.h"
#include "class_feeder.h"
#include "class_fire.h"
#include "class_observer.h"
#include "class_commanders.h"
#include "class_you.h"

#define FILENAME "ftFile.txt"  //宏常量设置文件路径
class Captian
{
public:
	Captian();
	~Captian();
	//显示菜单
	void showMenu(); 
	//退出程序
	void exitMenu(); 
	//记录战斗员人数
	int m_ftNumb;
	//人员数组的指针
	Fighter** m_ftArr;
	//呼叫增援
	void ftAdd();
	//保存文件数据
	void save();
	//读取文件数据
	void read();
	//标记文件是否为空
	bool ftEmpty;
	//获取文件中当前人数
	int get_Filenumb();
	//显示所有战斗员信息
	void show();
	//除名战斗员
	void ftDel();
	//查找战斗员所属数组下标
	int idSearch(int id);
	//查找战斗员
	void ftSearch();
	//修改战斗员
	void ftMod();
	//排序
	void sort();
	//解散队伍
	void ftClear();
};