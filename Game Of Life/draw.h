#pragma once
#include <raylib.h>
#include "field.h"
class draw
{
private:
	int m_scalar = 1;
	int m_height;
	int m_width;
	int m_fps;
	bool m_pause = 0;
	field m_field;
public:
	draw(int h, int w, int fps, field f);
	draw(int h, int w, int fps, field f, int s);
	~draw();
	void init();
	void loop();
	void windowDraw();
	void interaction();
};

