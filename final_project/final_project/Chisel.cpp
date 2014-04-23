#include "stdafx.h"
#include "Chisel.h"
#include "gl/gl.h"

CChisel::CChisel(void)
{
}


CChisel::~CChisel(void)
{
}

void CChisel::Draw()
{
	glBegin(GL_TRIANGLES);

	double n[3], v[3];

	glNormal3d(0, 1, 0);
	// Bottom left corner
	v[0] = m_position-1;
	v[1] = 0;
	v[2] = 2;
	glVertex3dv(v);

	// Bottom right corner
	v[0] = m_position+1;
	v[1] = 0;
	v[2] = 2;
	glVertex3dv(v);

	// Point
	v[0] = m_position;
	v[1] = 0;
	v[2] = 0;
	glVertex3dv(v);

	glEnd();
}