#pragma once
#include <Windows.h> 
#include "GLEW/include/glew.h"
#include <gl\GL.h> 
#include <gl\GLU.h> 
#include "OGLShader.h"
#include <memory> 

using namespace std; 

struct Material
{

};

struct ModelAsset
{
	unique_ptr<OGLShaderProgram> shader; // handle to the shader for this model 
	//OGLShaderProgram * shader; 
	shared_ptr<Material> material; // Handle to the texture used in this model


	//data 
	//GLuint vertexBufferObject; 
	//GLuint vertexArrayObject; 
	unsigned int vao;
	unsigned int vbo_verts;
	unsigned int vbo_colours;
	unsigned int vbo_indices;

	//parameters needed to draw array; 
	GLenum drawType; //triangles or quads 
	GLint  drawStart; 
	GLint  drawCount; 


};