#include "Renderer.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl\GLU.h> 

RendererOGL::RendererOGL()
{

}

RendererOGL::~RendererOGL()
{

}

//Init OpenGL 
void RendererOGL::Init()
{
	//m_cube = std::unique_ptr<OGLCube>(new OGLCube());
	//m_renderable = make_shared<Renderable>(); 
	//m_RenderList.push_back(shared_ptr<OGLCube>(new OGLCube()));

	AddToRender(shared_ptr<OGLCube>(new OGLCube()));
	//AddToRender(shared_ptr<OGLTriangle>(new OGLTriangle(0, 0)));
}


void RendererOGL::Shutdown()
{

}

void RendererOGL::Render()
{
	for (auto r : m_RenderList)
	{
		r->Render();
	}
	//m_cube->Render();
}

void RendererOGL::ClearScreen()
{

}