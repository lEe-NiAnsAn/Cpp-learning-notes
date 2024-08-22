#pragma once
#include<iostream>
using namespace std;
#include "class_fighters.h"

class Feeder : public Fighter
{
public:
	Feeder();
	Feeder(int id, string name,int rid);
	virtual void show_finfo();
	virtual string get_frole();
};