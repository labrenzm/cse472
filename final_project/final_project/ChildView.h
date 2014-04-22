// ChildView.h : interface of the CChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDVIEW_H__50C8628F_112A_40D0_9AB2_53368988C69B__INCLUDED_)
#define AFX_CHILDVIEW_H__50C8628F_112A_40D0_9AB2_53368988C69B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "graphics/OpenGLWnd.h"
#include "graphics/GrTexture.h"	// Added by ClassView
#include "graphics/GrCamera.h"
#include "Torus.h"
#include "Sphere.h"
#include "Organs.h"
#include "Mesh.h"
#include "graphics\grtexture.h"

/////////////////////////////////////////////////////////////////////////////
// CChildView window

class CChildView : public COpenGLWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildView)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	void OnGLDraw(CDC *pDC);
	virtual ~CChildView();

	// Generated message map functions
protected:
	//{{AFX_MSG(CChildView)
	afx_msg void OnStepSpin();
	afx_msg void OnUpdateStepSpin(CCmdUI* pCmdUI);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStepTorus();
	afx_msg void OnUpdateStepTorus(CCmdUI* pCmdUI);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnViewWireframe();
    afx_msg void OnUpdateViewWireframe(CCmdUI *pCmdUI);
    afx_msg void OnStepTorus2();
    afx_msg void OnUpdateStepTorus2(CCmdUI *pCmdUI);
    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
    afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnDrawFunky();
	afx_msg void OnUpdateStepFunky(CCmdUI *pCmdUI);
    //}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DrawFunky();
    void DrawTori();
    void Box(GLdouble p_x, GLdouble p_y, GLdouble p_z);

    bool m_wireframe;

	int m_mode;

	UINT m_spintimer;
	double m_spinangle;

    CGrCamera       m_camera;

    // The two tori...
    CTorus      m_torus1;
    CTorus      m_torus2;
	CGrTexture m_marble;
	CGrTexture m_marble2;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDVIEW_H__50C8628F_112A_40D0_9AB2_53368988C69B__INCLUDED_)
