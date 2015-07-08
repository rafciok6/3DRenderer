#pragma once
//Renderer class handle all rendering 
//Set Camera, Render Listo of objects taken from the scene 
#include "IRenderer.h"
#include "Renderable.h"
#include "OGLCube.h"
#include "OGLTriangle.h"
#include <memory> 
#include <vector> 

using namespace std;

class RendererOGL : public IRenderer
{
public:
	RendererOGL(); 
	~RendererOGL(); 

	//Init OpenGL 
	void Init(); 
	void Shutdown(); 

	void Render(); 
	void ClearScreen(); 

	void AddToRender(shared_ptr<Renderable> obj) { m_RenderList.push_back(obj) ; }

private: 
	std::unique_ptr<OGLCube>	m_cube;
	vector<shared_ptr<Renderable>> m_RenderList; 
};
