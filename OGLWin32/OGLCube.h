#pragma once

#include "Renderable.h"
#include "Listener.h"
#include "Vector2D.h"
#include "ModelInstance.h"

class OGLCube : public Renderable
{
	private:
		unsigned int	m_vao;
		unsigned int	m_vbo_verts;
		unsigned int	m_vbo_colours;
		unsigned int	m_vbo_indices;

	public:

		ModelInstance m_ModelInstance; 
						OGLCube();
						~OGLCube();
		
		void			InitUnitCube();
		void			Render();
};