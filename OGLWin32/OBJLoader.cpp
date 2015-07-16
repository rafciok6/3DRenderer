#include "OBJLoader.h"
#include <string> 

#define POINTS_PER_VERTEX 3 
#define TOTAL_FLOATS_IN_TRIANGLES 9


OBJLoader::OBJLoader()
{
	this->m_totalConnectedTriangles = 0; 
	this->m_totalConnectedPoints = 0; 
}

OBJLoader::~OBJLoader()
{

}

void OBJLoader::Load(char *filename) //Load the model 
{
	string line; 
	ifstream objFile(filename); 

	//check if file is open 
	if (objFile.is_open())
	{

	}

}

void OBJLoader::Render() //Render model
{

}

void OBJLoader::Release()// Release the model 
{

}

float * OBJLoader::CalculateNormal(float * coord1, float * coord2, float * coord3)
{

}