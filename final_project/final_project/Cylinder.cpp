#include "stdafx.h"
#include "Cylinder.h"

#include <cmath>
#include "gl/gl.h"

const double GR_PI = 3.1415926535897932384626433832795;

using namespace std;

// Based heavily off of CTorus code

CCylinder::CCylinder(void)
	: m_texture(NULL)
{
	m_radius = 3;
	m_length = 50;
	m_lengthSteps = 50;
	m_circumSteps = 50;

	InitRings();
}

CCylinder::~CCylinder(void)
{
}

void CCylinder::InitRings()
{
	rings.clear();

	// How large are the angular steps in radians
	const double circumStepsR = 2. * GR_PI / m_circumSteps;
	double x = 0;

	for (int i=0; i<m_lengthSteps; i++, x+=m_length/m_lengthSteps) {
		double angle = 0;
		vector<segment> ring;
		for (int j=0; j<m_circumSteps; j++) {
			vertex vBottom(x,sin(angle)*m_radius,cos(angle)*m_radius,angle);
			angle += circumStepsR;
			vertex vTop(x,sin(angle)*m_radius,cos(angle)*m_radius,angle);
			segment s(vBottom,vTop);
			ring.push_back(s);
		}
		rings.push_back(ring);
	}
}

void CCylinder::Deform(double position, double depth, int vertex)
{
	if (position < 0 || position >= rings.size()) return;
	if (depth > m_radius || m_radius-(m_radius-depth)<0 ) return;

		rings[position][vertex].m_bottom.m_y = sin(rings[position][vertex].m_bottom.m_angle)*(m_radius-(m_radius-depth));
		rings[position][vertex].m_bottom.m_z = cos(rings[position][vertex].m_bottom.m_angle)*(m_radius-(m_radius-depth));
		rings[position][vertex].m_top.m_y = sin(rings[position][vertex].m_top.m_angle)*(m_radius-(m_radius-depth));
		rings[position][vertex].m_top.m_z = cos(rings[position][vertex].m_top.m_angle)*(m_radius-(m_radius-depth));
}

void CCylinder::Draw()
{
	if(m_texture != NULL)
    {
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glBindTexture(GL_TEXTURE_2D, m_texture->TexName()); 
	}

	for (int i=0; i<rings.size()-1; i++) {
		for (int j=0; j<rings[i].size(); j++) {
			glBegin(GL_QUADS);
			// Bottom left corner
			glVertex3f(rings[i][j].m_bottom.m_x,rings[i][j].m_bottom.m_y,rings[i][j].m_bottom.m_z);

			// Bottom right corner
			glVertex3f(rings[i+1][j].m_bottom.m_x,rings[i+1][j].m_bottom.m_y,rings[i+1][j].m_bottom.m_z);

			// Top right corner
			glVertex3f(rings[i+1][j].m_top.m_x,rings[i+1][j].m_top.m_y,rings[i+1][j].m_top.m_z);

			// Top left corner
			glVertex3f(rings[i][j].m_top.m_x,rings[i][j].m_top.m_y,rings[i][j].m_top.m_z);
			glEnd();
		}
	}
	
	glBegin(GL_POLYGON);
	glNormal3d(-1, 0, 0);
	for (int i=0; i<rings[0].size(); i++) {
		glVertex3f(rings[0][i].m_bottom.m_x,rings[0][i].m_bottom.m_y,rings[0][i].m_bottom.m_z);
		glVertex3f(rings[0][i].m_top.m_x,rings[0][i].m_top.m_y,rings[0][i].m_top.m_z);
	}
	glNormal3d(1, 0, 0);
	for (int i=rings[rings.size()-1].size()-1; i>=0; i--) {
		glVertex3f(rings[rings.size()-1][i].m_bottom.m_x,rings[rings.size()-1][i].m_bottom.m_y,rings[rings.size()-1][i].m_bottom.m_z);
		glVertex3f(rings[rings.size()-1][i].m_top.m_x,rings[rings.size()-1][i].m_top.m_y,rings[rings.size()-1][i].m_top.m_z);
	}
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void CCylinder::CylinderVertex(double angle, double radius, double *vertex, double *normal)
{
	// Some sines and cosines we'll need.
    double ca1 = cos(0.);
    double sa1 = sin(0.);
    double ca2 = cos(angle);
    double sa2 = sin(angle);

	// What is the center of the slice we are on.
    double centerx = radius * ca1;
    double centerz = -radius * sa1;    // Note, y is zero

	// Compute surface normal
	normal[0] = ca2 * ca1;
	normal[1] = sa2;
	normal[2] = -ca2 * sa1;

	// Compute vertex
	vertex[0] = centerx + radius * normal[0];
    vertex[1] = radius * normal[1];
    vertex[2] = centerz + radius * normal[2];
}