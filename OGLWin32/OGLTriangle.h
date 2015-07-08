#pragma once 
#include "Renderable.h"
#include "ModelInstance.h"

class OGLTriangle : public Renderable
{
public:
	OGLTriangle(int x, int y);
	~OGLTriangle(); 

	void Render(); 
	void Init(); 

	void Move(int x, int y); 


private:
	int m_x, m_y; 

	//shared_ptr<ModelInstance> m_pModelInstance; 
	ModelInstance  m_pModelInstance;

	//unsigned int m_vao; 
	//unsigned int m_vbo_verts; 
	//unsigned int m_vbo_colours; 
	//unsigned int m_vbo_indices; 
};