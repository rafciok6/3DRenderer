#ifndef _MATERIAL_
#define _MATERIAL_
#include <Windows.h> 
#include <gl\GL.h> 
#include <gl\GLU.h> 

//class Material
//{
//public:
//	Material(); 
//
//	//This method creates a texture in OpenGL that we can texture map 
//	
//
//private: 
//};
bool CreateTexture(GLuint &textureID, LPCWSTR szFileName);
#endif