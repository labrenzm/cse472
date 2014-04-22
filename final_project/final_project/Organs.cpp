#include "StdAfx.h"
#include "Organs.h"

#include "gl/gl.h"

COrgans::COrgans(void)
{
}


COrgans::~COrgans(void)
{
}


void COrgans::Draw()
{
	GLfloat black[] = {0, 0, 0, 1};
	GLfloat white[] = {0.8f, 0.8f, 0.8f, 1.0f};
	GLfloat liverred[] = {0.788f, .223f, .223f, 1.f};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, liverred);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialf(GL_FRONT, GL_SHININESS, 70);
	DrawLiver();
	glMaterialfv(GL_FRONT, GL_SPECULAR, black);

	GLfloat lungsblue[] = {0.0f, 0.0f, 0.8f, 1.f};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, lungsblue);
    DrawLungs();

	GLfloat pipegrey[] = {0.54f, 0.54f, 0.54f, 1.f};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, pipegrey);
    DrawWindpipe();

	GLfloat heartred[] = {0.85f, .3, .3f, 1.f};
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialf(GL_FRONT, GL_SHININESS, 70);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, heartred);
    DrawHeart();
	glMaterialfv(GL_FRONT, GL_SPECULAR, black);
	
	GLfloat stomachorange[] = {0.85f, .6, .3f, 1.f};
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, stomachorange);
    DrawStomach();
}

