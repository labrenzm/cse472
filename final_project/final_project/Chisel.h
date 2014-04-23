#pragma once

class CChisel
{
public:
	CChisel(void);
	virtual ~CChisel(void);

	void Draw();
	void SetPosition(double position) { m_position = position; }

private:
	double m_position;
};

