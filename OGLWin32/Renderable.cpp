#include "Renderable.h"
#include "GLEW/include/glew.h"
//
//void Renderable::SetShader(char * vertexFile, char * fragmentFile)
//{
//	//m_shader = new OGLShaderProgram();
//
//	//m_shader->CreateShaderProgram();
//	//m_shader->AttachAndCompileShaderFromFile(vertexFile, SHADER_VERTEX);
//	//m_shader->AttachAndCompileShaderFromFile(fragmentFile, SHADER_FRAGMENT);
//
//	//m_shader->BindAttributeLocation(0, "position");
//	//m_shader->BindAttributeLocation(1, "inColour");
//	//glBindFragDataLocation(m_shader->GetProgramHandle(), 0, "outFrag");
//
//	//m_shader->BuildShaderProgram();
//	////m_shader->ActivateShaderProgram();
//}

Renderable::~Renderable()
{
	//delete m_shader;
}