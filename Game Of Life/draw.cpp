#include "draw.h"
draw::draw(int h, int w, int fps, field f) : m_height(h), m_width(w), m_fps(fps), m_field(f)
{}

draw::draw(int h, int w, int fps, field f, int s) : m_height(h), m_width(w), m_fps(fps), m_field(f), m_scalar(s)
{}

draw::~draw()
{}

void draw::init()
{
	InitWindow(m_width*m_scalar, m_height*m_scalar, "Game of Life");
	SetTargetFPS(m_fps);
}

void draw::loop()
{
	while (!WindowShouldClose())
	{
		windowDraw();
		interaction();
		if(!m_pause)
			m_field.step();
	}
	CloseWindow();
}

void draw::windowDraw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	vector<vector<int>> tmp = m_field.getField();
	//cout << m_field.getFieldString() << endl << endl;
	for (int i = 1; i < m_field.getHeight() - 1; ++i)
	{
		for (int j = 1; j < m_field.getWidth() - 1; ++j)
		{
			DrawRectangle((j - 1) * m_scalar, (i - 1) * m_scalar, m_scalar, m_scalar, tmp[i][j] ? WHITE : BLACK);
		}
	}
	EndDrawing();
}

void draw::interaction()
{
	if (IsKeyPressed(KEY_SPACE)) m_pause = !m_pause;

	if (m_pause)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			Vector2 m = GetMousePosition();
			cout << "Mouse pressed" << endl
				<< m.x << '\t' << m.x / m_scalar << '\t' << static_cast<int>(m.x / m_scalar) << '\t' << static_cast<int>(floor(m.x / m_scalar)) << endl
				<< m.y << '\t' << m.y / m_scalar << '\t' << static_cast<int>(m.y / m_scalar) << '\t' << static_cast<int>(floor(m.y / m_scalar)) << endl
				<< m_field.getPosition(static_cast<int>(m.y / m_scalar), static_cast<int>(m.x / m_scalar)) << endl
				<< (m_field.getPosition(static_cast<int>(m.y / m_scalar), static_cast<int>(m.x / m_scalar)) ? 0 : 1) << endl;
			m_field.setPosition(static_cast<int>(m.y / m_scalar), static_cast<int>(m.x / m_scalar),
				m_field.getPosition(static_cast<int>(m.y / m_scalar), static_cast<int>(m.x / m_scalar)) ? 0 : 1);
		}
	}
}

/*
	draw(int h, int w, int fps, field f);
	draw(int h, int w, int fps, field f, int s);
	~draw();
	void init();
	void loop();
	void windowDraw();
	void interaction();
*/