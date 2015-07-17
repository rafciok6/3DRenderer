#pragma once 

#include "ModelInstance.h"
#include <Windows.h> 
#include <gl\GL.h> 
#include <gl\GLU.h> 
#include <iostream> 
#include <fstream> 
#include <vector> 
#include <cmath> 
#include <memory> 
using namespace std;

class OBJLoader
{
public:
	OBJLoader(); 
	~OBJLoader(); 

	void Load(char *filename); //Load the model 
	void Render(); //Render model 
	void Release();// Release the model 
	float * CalculateNormal(float * coord1, float * coord2, float * coord3); 

private: 
	//float * m_pNormals; //store the normals 
	//int * m_pFaces_Triangles; // store the triangle faces 
	//float * m_pVertexBuffer; // Store the points which makes the object
	//int  m_totalConnectedPoints; //store the total nomber of connected vertices 
	//int  m_totalConnectedTriangles; //Store dtotal number of connected triangles

	vector<float *> m_vVertices; 
	vector<int *> m_vFaces; 

	FILE *m_FilePointer;

	ModelInstance m_ModelInstance; 
};