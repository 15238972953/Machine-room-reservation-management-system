#pragma once
#include<iostream>
using namespace std;

class Identity {
public:
	virtual void operMenu() { return; }
	string m_Name;
	string m_Pwd;
};