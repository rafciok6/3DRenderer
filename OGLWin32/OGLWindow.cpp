#include "OGLWindow.h"
#include "Resource.h"
#include "GLEW/include/glew.h"
#include <iostream> 


OGLWindow::OGLWindow()
{
	m_euler[0] = m_euler[1] = m_euler[2] = 0.0f;
}

OGLWindow::~OGLWindow()
{
	//Clean up the renderable
	//delete m_shader;
	delete m_pRenderer;
}

OGLWindow::OGLWindow(HINSTANCE hInstance, int width, int height)
{
	InitWindow(hInstance, width, height);
	m_euler[0] = m_euler[1] = m_euler[2] = 0.0f;
}

HGLRC OGLWindow::CreateOGLContext(HDC hdc)
{
	unsigned int pixelformat;
	HGLRC hglrc;

	static PIXELFORMATDESCRIPTOR pfd = 
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Support Window
		PFD_SUPPORT_OPENGL |						// Format Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request RGBA Format
		32,											// Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits mask
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// Z-Buffer depth
		0,											// Stencil Buffer
		0,											// Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(pixelformat=ChoosePixelFormat(hdc,&pfd)))
	{
		return 0;
	}

	if(!SetPixelFormat(hdc,pixelformat,&pfd))
	{
		return 0;
	}

	if (!(hglrc=wglCreateContext(hdc)))
	{
		return 0;
	}

	if(!wglMakeCurrent(hdc,hglrc))
	{
		return 0;
	}

	return hglrc;
}

void OGLWindow::DestroyOGLWindow()
{
	DestroyOGLContext();

	DestroyWindow( m_hwnd );

	m_hwnd = NULL;
	m_hdc = NULL;
}

BOOL OGLWindow::DestroyOGLContext()
{
	if ( m_hglrc )
	{
		wglMakeCurrent( NULL, NULL );
		wglDeleteContext( m_hglrc );
		m_hglrc = NULL;
	}
	
	if ( !ReleaseDC ( m_hwnd, m_hdc ) )
		return FALSE;

	return TRUE;
}

BOOL OGLWindow::InitWindow(HINSTANCE hInstance, int width, int height)
{
	m_hwnd = CreateWindowEx( WS_EX_APPWINDOW | WS_EX_WINDOWEDGE,
		L"OGLWindow", L"OGLWindow", WS_OVERLAPPEDWINDOW|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,
		0, 0, width, height, NULL, NULL, hInstance, NULL);

	if ( ! m_hwnd )
		return FALSE;

	m_hdc = GetDC( m_hwnd );

	if ( !(m_hglrc = CreateOGLContext( m_hdc )) )
		return FALSE;

	glewInit();

	InitOGLState();

	m_width = width;
	m_height = height;


	m_pRenderer = new RendererOGL();
	m_pRenderer->Init();

	
	return TRUE;
}

void OGLWindow::SetVisible ( BOOL visible )
{
	ShowWindow ( m_hwnd, visible? SW_SHOW : SW_HIDE );
}

void OGLWindow::Render()
{
	float modelview[16];
	float projection[16];

	m_euler[0] = m_euler[0] > 360.0 ? 0 : m_euler[0] + 1.0;
	m_euler[1] = m_euler[1] > 360.0 ? 0 : m_euler[1] + 1.0;
	m_euler[2] = m_euler[2] > 360.0 ? 0 : m_euler[2] + 1.0;

	//Renderable* prenderable = static_cast<Renderable*>(m_cube);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
	glTranslatef( 0.0, 0.0, -2.0 );
	glRotatef( m_euler[0], 1.0, 0.0, 0.0 );
	glRotatef( m_euler[1], 0.0, 1.0, 0.0 );
	glRotatef( m_euler[2], 0.0, 0.0, 1.0 );

	////m_shader->ActivateShaderProgram();
	//glGetFloatv( GL_MODELVIEW_MATRIX, modelview );
	//glGetFloatv( GL_PROJECTION_MATRIX, projection);

	//glUniformMatrix4fv( m_uniform_modelview, 1, GL_FALSE, modelview );
	//glUniformMatrix4fv( m_uniform_projection, 1, GL_FALSE, projection );

	m_pRenderer->Render();
	//m_shader->DeactivateShaderProgram();

	SwapBuffers(m_hdc);
	return;
}

void OGLWindow::Resize( int width, int height )
{
	float aspect_ratio = (float)width/(float)height;

	glViewport( 0, 0, width, height );
	
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glFrustum( -1.5*aspect_ratio, 1.5*aspect_ratio, -1.5, 1.5, 1.0, 100.0 );
	
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	return;
}

void OGLWindow::InitOGLState()
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_CULL_FACE);
	//Two sides of polygon are drawn 
	glDisable(GL_CULL_FACE);

	//Initialise OGL shader
	//m_shader = new OGLShaderProgram();

	//m_shader->CreateShaderProgram();
	//m_shader->AttachAndCompileShaderFromFile("../data/shader/basic.vert", SHADER_VERTEX);
	//m_shader->AttachAndCompileShaderFromFile("../data/shader/basic.frag", SHADER_FRAGMENT);

	//m_shader->BindAttributeLocation( 0, "position" );
	//m_shader->BindAttributeLocation( 1, "inColour" );

	//glBindFragDataLocation( m_shader->GetProgramHandle(), 0, "outFrag" );

	//m_shader->BuildShaderProgram();
	////m_shader->ActivateShaderProgram();

	//m_uniform_modelview = glGetUniformLocation(m_shader->GetProgramHandle(), "modelview");
	//m_uniform_projection = glGetUniformLocation(m_shader->GetProgramHandle(), "projection");
}

BOOL OGLWindow::MouseLBDown ( int x, int y )
{
	RendererOGL* r = static_cast<RendererOGL*> (m_pRenderer);
	r->AddToRender(shared_ptr<OGLTriangle>(new OGLTriangle(0, 0)));
/*	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3i(x, y, 1); 
	glVertex3i(x +1, y, 1);
	glVertex3i(x, y +1 , 1);
	glVertex3i(x +1, y +1, 1);
	glEnd(); 
	
	std::cout << "Moved" << std::endl;*/ 
	return TRUE;
}

BOOL OGLWindow::MouseLBUp ( int x, int y )
{
	return TRUE;
}

BOOL OGLWindow::MouseMove ( int x, int y )
{
	/*Listener *plistener = static_cast<Listener*>(m_rect);
	plistener->MouseMove( x, y );*/

	return TRUE;
}


void OGLWindow::ChangeColor(float r, float g, float b) { glClearColor(r, g, b, 1.0f); }