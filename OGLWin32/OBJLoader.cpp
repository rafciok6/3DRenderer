#include "OBJLoader.h"
#include <string> 
#include <iostream> 
#include <fstream> 


OBJLoader::OBJLoader()
{
	//this->m_totalConnectedTriangles = 0; //number of faces 
	//this->m_totalConnectedPoints = 0; 

	m_ModelInstance.Init("../data/shader/basic.vert", "../data/shader/basic.frag");
}

OBJLoader::~OBJLoader()
{
	/*free(this->m_pFaces_Triangles); 
	free(this->m_pNormals); 
	free(this->m_pVertexBuffer); */
}

void OBJLoader::Load(char *filename) //Load the model 
{
	int scale = 100 ;
	std::ifstream file;
	file.open(filename);
	std::string line; 
	char ch;

	float vx, vy, vz; 
	int fx, fy, fz; 

	if (file.fail())
	{
		cout << "FileFailed";
	}

	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
		//	cout << line << std::endl;
			if (line[0] == 'v')
			{
				sscanf(line.data(), "%c %f %f %f", &ch, &vx, &vy, &vz);
				m_vVertices.push_back(vx / scale);
				m_vVertices.push_back(vy /scale);
				m_vVertices.push_back(vz /scale);
			}

			if (line[0] == 'f')
			{
				sscanf(line.data(), "%c %i %i %i", &ch, &fx, &fy, &fz);
				m_vFaces.push_back(fx);
				m_vFaces.push_back(fy);
				m_vFaces.push_back(fz);
			}
		}
			
		file.close();
	}

	m_ModelInstance.SetDataVector(&m_vVertices, &m_vFaces); 



}

void OBJLoader::Render() //Render model
{
	m_ModelInstance.Render();
}

void OBJLoader::Release()// Release the model 
{

}

float * OBJLoader::CalculateNormal(float * coord1, float * coord2, float * coord3)
{
	return 0;
}