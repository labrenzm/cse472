#pragma once

class CChisel
{
public:
	CChisel(void);
	virtual ~CChisel(void);

	void Draw();

	double Position() { return m_position; }
	void SetPosition(double position) { m_position = position; }
	double Depth() { return m_depth; }
	void SetDepth(double depth) { m_depth = depth; }

private:
	double m_position;
	double m_depth;
};

