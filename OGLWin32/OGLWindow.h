#pragma once

#include <Windows.h>
//#include "OGLShader.h"
#include "Renderer.h"
#include <vector> 
#include <memory> 


class OGLWindow
{
	private:
		std::vector<Renderable*> m_renderingList; 
		float	    m_euler[3];
		HWND		m_hwnd;				//handle to a window
		HDC			m_hdc;				//handle to a device context
		HGLRC		m_hglrc;			//handle to a gl rendering context

		int			m_width;
		int			m_height;
		
		//This is not an ideal place to hold geometry data
		IRenderer* m_pRenderer; 

		//Declear an OGL shader program
		//OGLShaderProgram		*m_shader;
		int						m_uniform_modelview;
		int						m_uniform_projection;

protected:

		HGLRC CreateOGLContext (HDC hdc);
		BOOL DestroyOGLContext();
		BOOL InitWindow(HINSTANCE hInstance, int width, int height);
		void InitOGLState();

	public:
					OGLWindow();
					OGLWindow(HINSTANCE hInstance, int width, int height);
					~OGLWindow();

		void		Render();
		void		Resize( int width, int height );
		void		SetVisible( BOOL visible );
		void		DestroyOGLWindow();

		void		ChangeColor(float r, float g, float b);

		BOOL		MouseLBDown ( int x, int y );
		BOOL		MouseLBUp ( int x, int y );
		BOOL		MouseMove ( int x, int y );

		IRenderer* GetRenderer() { return m_pRenderer; }
};
