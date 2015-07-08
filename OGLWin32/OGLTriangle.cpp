#include "OGLTriangle.h"
#include <windows.h>
#include "GLEW/include/glew.h"
#include <gl\GL.h> 
#include <gl\GLU.h> 

OGLTriangle::OGLTriangle(int x, int y)
{
//	m_pModelInstance = make_shared<ModelInstance>(new ModelInstance()); 
	//m_pModelInstance = new ModelInstance(); 
	//m_pModelInstance.Init("../data/shader/basic.vert", "../data/shader/basic.frag");
	Init();
	//Move(x, y); 

}

OGLTriangle::~OGLTriangle()
{

}

void OGLTriangle::Init()
{
	//four vertices 
	 GLfloat vertex_positions[] = 
	{
		-1.0f, -1.0f, 0.0f, 1.0f, 
		1.0f, -1.0f, 0.0f, 1.0f,
		-1.0f, 1.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, 0.0f, 1.0f,
	};

	//color for each vertex 
	 GLfloat vertex_colors[]= 
	{
		1.0f, 0.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 1.0f, 1.0f,
	};
	
	//Three indices (we are going to draw one triangle at a time) 
	 GLushort vertex_indices[] =
	{
		0, 1, 2
	};
	
	 //m_pModelInstance.SetData(vertex_positions, vertex_colors, vertex_indices);
	//glGenVertexArrays(1, &m_vao);
	//glBindVertexArray(m_vao);

	//glGenBuffers(1, &m_vbo_verts);
	//glBindBuffer(GL_ARRAY_BUFFER, m_vbo_verts);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_positions), vertex_positions, GL_STATIC_DRAW);
	////used function to comunicate with shader 
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//glEnableVertexAttribArray(0);

	//glGenBuffers(1, &m_vbo_colours);
	//glBindBuffer(GL_ARRAY_BUFFER, m_vbo_colours);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_colors), vertex_colors, GL_STATIC_DRAW);
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//glEnableVertexAttribArray(1);

	////Set up the element array buffer 
	//glGenBuffers(1, &m_vbo_indices);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vbo_indices);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vertex_indices), vertex_indices, GL_STATIC_DRAW);

	//glBindVertexArray(0);

	////The mesh data may be freed from the host memory 
	////once they are transferred to the graphics hardware.


	 //glGenVertexArrays(1, &m_pModelInstance->m_ModelAsset->vao);
	 //glBindVertexArray(m_pModelInstance->m_ModelAsset->vao);

	 //glGenBuffers(1, &m_pModelInstance->m_ModelAsset->vbo_verts);
	 //glBindBuffer(GL_ARRAY_BUFFER, m_pModelInstance->m_ModelAsset->vbo_verts);
	 //glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_positions), vertex_positions, GL_STATIC_DRAW);
	 ////used function to comunicate with shader 
	 //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	 //glEnableVertexAttribArray(0);

	 //glGenBuffers(1, &m_pModelInstance->m_ModelAsset->vbo_colours);
	 //glBindBuffer(GL_ARRAY_BUFFER, m_pModelInstance->m_ModelAsset->vbo_colours);
	 //glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_colors), vertex_colors, GL_STATIC_DRAW);
	 //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	 //glEnableVertexAttribArray(1);

	 ////Set up the element array buffer 
	 //glGenBuffers(1, &m_pModelInstance->m_ModelAsset->vbo_indices);
	 //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_pModelInstance->m_ModelAsset->vbo_indices);
	 //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vertex_indices), vertex_indices, GL_STATIC_DRAW);

	 //glBindVertexArray(0);

	 //The mesh data may be freed from the host memory 
	 //once they are transferred to the graphics hardware.


//	SetShader("../data/shader/basic.vert", "../data/shader/basic.frag");
}
void OGLTriangle::Render()
{
	//m_pModelInstance->m_ModelAsset->shader->ActivateShaderProgram();
	//GetShader()->ActivateShaderProgram();
//m_pModelInstance.Render();
	//float modelview[16];
	//float projection[16];

	//glGetFloatv(GL_MODELVIEW_MATRIX, modelview);
	//glGetFloatv(GL_PROJECTION_MATRIX, projection);

	//glUniformMatrix4fv(glGetUniformLocation(GetShader()->GetProgramHandle(), "modelview"), 1, GL_FALSE, modelview);
	//glUniformMatrix4fv(glGetUniformLocation(GetShader()->GetProgramHandle(), "projection"), 1, GL_FALSE, projection);

	///*glColor3f(1.0f, 0.0f, 0.0f);
	//glBegin(GL_TRIANGLES);
	//glVertex3f(-1.0f, 0.0f, 0.0f); 
	//glVertex3f(0.0f, 1.0f, 0.0f);
	//glVertex3f(1.0f, 0.0f, 0.0f);
	//glEnd(); */
	////glColor3f(1.0f, 0.0f, 0.0f); 
	//glBindVertexArray(m_pModelInstance->m_ModelAsset->vao);

	////SET THE MODEL MATRIX HERE AND SEND TO THE SHADER 
	//glDrawArrays(GL_TRIANGLES,  0, 3);
	////glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
	////glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (void*)(3 * sizeof(int)));
	////glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (void*)(6 * sizeof(int)));
	////glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (void*)(9 * sizeof(int)));
	//////glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, (void*)(16 * sizeof(int)));
	//////glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, (void*)(20 * sizeof(int)));

	//glBindVertexArray(0);
	////glColor3f(1.0f, 1.0f, 1.0f);

	//GetShader()->DeactivateShaderProgram();

	//m_pModelInstance->m_ModelAsset->shader->DeactivateShaderProgram();
}


void OGLTriangle::Move(int x, int y)
{

}