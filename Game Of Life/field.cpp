#include "field.h"

field::field()
{
	srand(time(NULL));
	m_height = 9;
	m_width = 16;
}

field::field(int h, int w) : m_height(h+2), m_width(w+2)
{
	srand(time(NULL));
}

field::~field()
{
	cout << "Game Over" << endl;
}

void field::init()
{
	vector < vector<int> > tmp(m_height, vector<int>(m_width));
	m_field = tmp;
}

void field::randomize()
{
	for (int i = 1; i < m_height-1; ++i)
	{
		for (int j = 1; j < m_width-1; ++j)
		{
			m_field[i][j] = rand() % 2;
		}
	}
}

void field::step()
{
	vector<vector<int>> tmp(m_height, vector<int>(m_width));
	auto n = [=](int h, int w) -> int
	{
		return 
			  m_field[h - 1][w - 1]
			+ m_field[h - 1][w]
			+ m_field[h - 1][w + 1]
			+ m_field[h][w - 1]
			+ m_field[h][w + 1]
			+ m_field[h + 1][w - 1]
			+ m_field[h + 1][w]
			+ m_field[h + 1][w + 1];
	};
	for (int i = 1; i < m_height - 1; ++i)
	{
		for (int j = 1; j < m_width - 1; ++j)
		{
			switch (n(i, j))
			{
			case 2:
				tmp[i][j] = m_field[i][j];
				break;
			case 3: 
				tmp[i][j] = 1;
				break;
			default:
				tmp[i][j] = 0;
				break;
			}
		}
	}
	m_field = tmp;
}

void field::setPosition(int h, int w, int state)
{
	m_field[h+1][w+1] = state;
}

int field::getPosition(int h, int w)
{
	return m_field[h+1][w+1];
}

string field::getFieldString()
{
	stringstream ss;
	for (int i = 1; i < m_height - 1; ++i)
	{
		for (int j = 1; j < m_width - 1; ++j)
		{
			ss << m_field[i][j];
		}
		ss << endl;
	}
	return ss.str();
}

vector<vector<int>> field::getField()
{
	return m_field;
}

int field::getHeight()
{
	return m_height;
}

int field::getWidth()
{
	return m_width;
}

/*
class field
{
private:
	int m_height;
	int m_width;
	vector<vector<bool>> m_field;
public:
	field();
	~field();
	void init();
	void randomize();
	void step();
	void setPosition(int h, int w);
	bool getPosition(int h, int w);
	string getField();
};

*/