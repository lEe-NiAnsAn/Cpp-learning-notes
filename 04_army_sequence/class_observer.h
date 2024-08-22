#pragma once
#include<iostream>
using namespace std;
#include "class_fighters.h"

class Observer : public Fighter
{
public:
	Observer();
	Observer(int id, string name, int rid);
	virtual void show_finfo();
	virtual string get_frole();
};