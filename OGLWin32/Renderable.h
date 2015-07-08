#pragma once
#ifndef _RENDERABLE_
#define _RENDERABLE_


#include <memory>
#include "OGLShader.h"
//This is an abstract class
//It cannot be instantiated without being inherited by a concrete class
class Renderable
{
	public:

		//this is a pure virtual function
		virtual void			Render() = 0;
		virtual ~Renderable();
		//virtual void			SetShader(char * vertexFile, char * fragmentFile); 
		//OGLShaderProgram* GetShader() { return m_shader; }
		
private:
	//OGLShaderProgram  *m_shader; 
};

#endif

