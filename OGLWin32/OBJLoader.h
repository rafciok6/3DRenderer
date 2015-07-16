#pragma once 
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
	float * m_pNormals; //store the normals 
	float * m_pFaces_Triangles; // store the triangle faces 
	float * m_pVertexBuffer; // Store the points which makes the object
	long  m_totalConnectedPoints; //store the total nomber of connected vertices 
	long  m_totalConnectedTriangles; //Store dtotal number of connected triangles
};