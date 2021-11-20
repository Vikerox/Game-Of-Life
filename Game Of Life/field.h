#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <time.h>
#include <sstream>

using namespace std;

class field
{
private:
	int m_height;
	int m_width;
	vector<vector<int>> m_field;
public:
	field();
	field(int h, int w);
	~field();
	void init();
	void randomize();
	void step();
	void setPosition(int h, int w, int state);
	int	 getPosition(int h, int w);
	string getFieldString();
	vector<vector<int>> getField();
	int getHeight();
	int getWidth();
};

