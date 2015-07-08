#pragma once 
#include "ModelAsset.h"
#include "OGLShader.h"



class ModelInstance
{
public: 
	ModelInstance();
	~ModelInstance();

	void Init(const char* vertexShader, const char* fragShader); 
	void Render(); 

	void SetData(const GLfloat *vertex_positions, GLsizeiptr positionSize, const GLfloat * vertex_colors, GLsizeiptr colorsSize, const int * vertex_indices, GLsizeiptr indiciesSize);

private: 	
	
	void SetShader(const char* vertexShader, const char* fragShader);

	ModelAsset m_ModelAsset;

	//Matrices 
	float m_modelview[16];
	float m_projection[16];

};