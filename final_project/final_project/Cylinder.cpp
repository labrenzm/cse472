#include "stdafx.h"
#include "Cylinder.h"

#include <vector>
#include <cmath>
#include "gl/gl.h"

const double GR_PI = 3.1415926535897932384626433832795;

using namespace std;

struct vertex {
	vertex(double x, double y, double z) {
		m_x = x; m_y = y; m_z = z;
	}

	double m_x;
	double m_y;
	double m_z;
};

// Based heavily off of CTorus code

CCylinder::CCylinder(void)
	: m_texture(NULL)
{
	m_radius = 3;
	m_length = 50;
	m_lengthSteps = 50;
	m_circumSteps = 50;
}

CCylinder::~CCylinder(void)
{
}

void CCylinder::Draw()
{
	if(m_texture != NULL)
    {
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glBindTexture(GL_TEXTURE_2D, m_texture->TexName()); 
	}

	// How large are the angular steps in radians
	const double circumStepsR = 2. * GR_PI / m_circumSteps;
	double x = 0;

	for (int i=0; i<m_lengthSteps; i++, x+=m_length/m_lengthSteps) {
		double angle = 0;
		vector<vertex> caps;

		for (int j=0; j<m_circumSteps; j++) {
			double n[3], v[3];

			glBegin(GL_QUADS);

			// Bottom left corner
			v[0] = x;
			v[1] = sin(angle)*m_radius;
			v[2] = cos(angle)*m_radius;
			glVertex3dv(v);

			// Bottom right corner
			v[0] = x+m_length/m_lengthSteps;
			v[1] = sin(angle)*m_radius;
			v[2] = cos(angle)*m_radius;
			glVertex3dv(v);

			angle += circumStepsR;

			// Top right corner
			v[0] = x+m_length/m_lengthSteps;
			v[1] = sin(angle)*m_radius;
			v[2] = cos(angle)*m_radius;
			glVertex3dv(v);

			if (i==m_lengthSteps-1) caps.push_back(vertex(v[0],v[1],v[2]));

			// Top left corner
			v[0] = x;
			v[1] = sin(angle)*m_radius;
			v[2] = cos(angle)*m_radius;
			glVertex3dv(v);

			// Add caps
			if (i==0) caps.push_back(vertex(v[0],v[1],v[2]));

			glEnd();
		}

		if (!caps.empty()) {
			glBegin(GL_POLYGON);
			if (i==0) {
				glNormal3d(-1, 0, 0);
				for (int j=0; j<caps.size(); j++) {
					glVertex3f(caps[j].m_x,caps[j].m_y,caps[j].m_z);
				}
			} else {
				 glNormal3d(-1, 0, 0);
				 for (int j=caps.size()-1; j>=0; j--) {
					glVertex3f(caps[j].m_x,caps[j].m_y,caps[j].m_z);
				}
			}
			glEnd();
		}
	}

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