#pragma once

struct vertex {
	vertex() {
		m_x = m_y = m_z = m_angle = 0;
	}

	vertex(double x, double y, double z, double angle) {
		m_x = x; m_y = y; m_z = z; m_angle = angle;
	}

	vertex& operator=(const vertex& other)
	{
		m_x = other.m_x;
		m_y = other.m_y;
		m_z = other.m_z;
		m_angle = other.m_angle;
		return *this;
	}

	double m_x;
	double m_y;
	double m_z;
	double m_angle;
};

struct segment {
	segment(const vertex &bottom, const vertex &top) {
		m_bottom = bottom; m_top = top;
	}

	vertex m_bottom;
	vertex m_top;
};