#pragma once

#include "graphics/GrTexture.h"

class CCylinder
{
public:
	CCylinder(void);
	virtual ~CCylinder(void);

	void SetTexture(CGrTexture *texture) {m_texture = texture;}
    CGrTexture *GetTexture() {return m_texture;}

	void Draw();

private:
	void CylinderVertex(double angle, double radius, double *vertex, double *normal);

	double m_radius;
	double m_length;
	double m_lengthSteps;
	double m_circumSteps;

	CGrTexture* m_texture;
};

