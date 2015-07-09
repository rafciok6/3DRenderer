#include "ModelInstance.h"
#include "GLEW/include/glew.h"
#include <iostream>

ModelInstance::ModelInstance()
{

}

ModelInstance::~ModelInstance()
{

}

void ModelInstance::Init(const char* vertexShader, const char* fragShader)
{
	SetShader(vertexShader, fragShader); 

}

void ModelInstance::SetShader(const char* vertexShader, const char* fragShader)
{
	//m_ModelAsset = new ModelAsset(); 
	m_ModelAsset.shader = make_unique<OGLShaderProgram>();
	//m_ModelAsset.shader = new OGLShaderProgram();
	m_ModelAsset.shader->CreateShaderProgram();
	m_ModelAsset.shader->AttachAndCompileShaderFromFile(vertexShader, SHADER_VERTEX);
	m_ModelAsset.shader->AttachAndCompileShaderFromFile(fragShader, SHADER_FRAGMENT);

	m_ModelAsset.shader->BindAttributeLocation(0, "position");
	m_ModelAsset.shader->BindAttributeLocation(1, "inColour");

	glBindFragDataLocation(m_ModelAsset.shader->GetProgramHandle(), 0, "outFrag");
	m_ModelAsset.shader->BuildShaderProgram();
//	m_ModelAsset->shader->ActivateShaderProgram();
}

void ModelInstance::Render()
{
	m_ModelAsset.shader->ActivateShaderProgram();
	glGetFloatv( GL_MODELVIEW_MATRIX, m_modelview );
	glGetFloatv( GL_PROJECTION_MATRIX, m_projection);

	glUniformMatrix4fv(glGetUniformLocation(m_ModelAsset.shader->GetProgramHandle(), "modelview"), 1, GL_FALSE, m_modelview);
	glUniformMatrix4fv(glGetUniformLocation(m_ModelAsset.shader->GetProgramHandle(), "projection"), 1, GL_FALSE, m_projection);

	glActiveTexture(GL_TEXTURE0); 
	 	glBindTexture(GL_TEXTURE_2D, m_textureID.at(0));
	glUniform2f(glGetUniformLocation(m_ModelAsset.shader->GetProgramHandle(), "screenSize"), 1024.0f /8, 768.0f/ 8);
	glUniform1i(glGetUniformLocation(m_ModelAsset.shader->GetProgramHandle(), "tex"), 0); 

	glBindVertexArray(m_ModelAsset.vao);
	
	glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0 );
	glBindTexture(GL_TEXTURE_2D, m_textureID.at(1));
	//glUniform1i(glGetUniformLocation(m_ModelAsset.shader->GetProgramHandle(), "tex"), 1);
	glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, (void*)(4*sizeof(int)) );
	glBindTexture(GL_TEXTURE_2D, m_textureID.at(2));
	glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, (void*)(8*sizeof(int)) );
	//glBindTexture(GL_TEXTURE_2D, m_textureID.at(3));
	glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, (void*)(12*sizeof(int)) );

	glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, (void*)(16*sizeof(int)) );
	glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, (void*)(20*sizeof(int)) );
	//glDrawArrays(GL_TRIANGLES, 0, 24);
	glBindVertexArray(0);

	m_ModelAsset.shader->DeactivateShaderProgram();
}

void ModelInstance::SetData(const GLfloat *vertex_positions, GLsizeiptr positionSize, const GLfloat * vertex_colors, GLsizeiptr colorsSize, const int * vertex_indices, GLsizeiptr indiciesSize)
{

	glGenVertexArrays(1, &m_ModelAsset.vao);
	glBindVertexArray(m_ModelAsset.vao);

	glGenBuffers(1, &m_ModelAsset.vbo_verts);
	glBindBuffer(GL_ARRAY_BUFFER, m_ModelAsset.vbo_verts);
	glBufferData(GL_ARRAY_BUFFER, positionSize, vertex_positions, GL_STATIC_DRAW);
	//used function to comunicate with shader 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &m_ModelAsset.vbo_colours);
	glBindBuffer(GL_ARRAY_BUFFER, m_ModelAsset.vbo_colours);
	glBufferData(GL_ARRAY_BUFFER, colorsSize, vertex_colors, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	//Set up the element array buffer 
	glGenBuffers(1, &m_ModelAsset.vbo_indices);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ModelAsset.vbo_indices);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indiciesSize, vertex_indices, GL_STATIC_DRAW);

	glBindVertexArray(0);

}

void ModelInstance::SetTexture(LPWSTR filename)
{
	UINT index; 
	if (!CreateTexture(index, filename))
	{
		std::cout << "ModelInstance.cpp: Cannot Load Texture" << std::endl; 
	}
	m_textureID.push_back(index);
}
