#include "OBJLoader.h"
#include <string> 



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
//	string line; 
//	ifstream file(filename); 
//
//	//check if file is open 
//	if (!file.is_open())
//	{
//		cout << " Cannot open file";
//	}
//	else
//	{
//	
//		file.seekg(0, ios::beg);
//		//allocate memory 
//		//m_pVertexBuffer = (float *)malloc(fileSize); //alloc memory for vertex 
//		//m_pFaces_Triangles = (int *)malloc(fileSize * sizeof(float)); // alloc memory for triangles
//		//m_pNormals = (float *)malloc(fileSize * sizeof(float)); // alloc memory for normals
//
//		float vx, vy, vz; 
//		int fx, fy, fz; 
//
//		while (!file.eof())
//		{
//			//cout << ". \n";
//			//getline(objFile, line); 
//			//if (line.c_str()[0] == 'v')
//			//{
//			//	//line[0] = ' '; //set first character to 0 
//			//	sscanf(line.c_str(), "%f %f %f", &m_pVertexBuffer[m_totalConnectedPoints],
//			//									&m_pVertexBuffer[m_totalConnectedPoints + 1],
//			//									&m_pVertexBuffer[m_totalConnectedPoints + 2]); 
//			//	m_totalConnectedPoints += POINTS_PER_VERTEX; 
//			//}
//			//if (line.c_str()[0] == 'f')
//			//{
//			////	line[0] = ' '; //set first character to 0 
//			//	sscanf(line.c_str(), "%i %i %i", m_pFaces_Triangles[m_totalConnectedTriangles],
//			//		m_pFaces_Triangles[m_totalConnectedTriangles + 1],
//			//		m_pFaces_Triangles[m_totalConnectedTriangles + 2]); 
//			//	m_totalConnectedTriangles += POINTS_PER_VERTEX; 
//			//}
//
//			cout << ". /n";
//			getline(file, line);
//			cout << line<<". /n";
//		/*	if (line[0] == 'v' && line[1] == ' ')
//			{
//				sscanf(line.data(), "v %f %f %f", &vx, &vy, &vz);
//
//				m_vVertices.push_back(&vx);
//				m_vVertices.push_back(&vy);
//				m_vVertices.push_back(&vz);
//			}
//			if (line[0] == 'f')
//			{
//
//				sscanf(line.data(), "f %i %i %i", &fx, &fy, &fz);
//
//				m_vFaces.push_back(&fx);
//				m_vFaces.push_back(&fy);
//				m_vFaces.push_back(&fz);
//			}
//*/
//
//			
//		}
//		file.close();
//
//	}
//
//	/*float * ver = new float[m_vVertices.size()]; 
//	int *fac = new int[m_vFaces.size()]; 
//
//	for (int i = 0; i < m_vVertices.size(); i++)
//	{
//		ver[i] = *m_vVertices.at(i); 
//	}
//
//	for (int j = 0; j < m_vFaces.size(); j++)
//	{
//		fac[j] = *m_vFaces.at(j);
//	}
//
//	m_ModelInstance.SetData(ver, m_vVertices.size(), NULL, NULL, fac, m_vFaces.size());
//	m_ModelInstance.SetTexture(L"Image.bmp");*/

	char strMessage[255] = { 0 };				// This will be used for error messages

	m_FilePointer = fopen(filename, "r");

	// Check to make sure we have a valid file pointer
	if (!m_FilePointer) {
		// Create an error message for the attempted file
		sprintf(strMessage, "Unable to find or open the file: %s", filename);
		MessageBox(NULL, (LPWSTR)strMessage, L"Error", MB_OK);
		return ;
	}

	char line[255] = {0}; //line buffer
	char ch, ch1 = 0;
	float vx, vy, vz;
	int fx, fy, fz; 

	while (!feof(m_FilePointer))
	{
		cout << line<<". /n";
		//fgets(line, 100, m_FilePointer); 
		//ch = fgetc(m_FilePointer);
		//ch1 = fgetc(m_FilePointer);
		

	/*	switch (ch)
		{
		case 'v':
			if (ch1 == ' ')
			{

				fscanf(m_FilePointer, "%f %f %f", &vx, &vy, &vz);

				m_vVertices.push_back(&vx);
				m_vVertices.push_back(&vy);
				m_vVertices.push_back(&vz);
			}
			break;


		case 'f': 
			if (ch1 == ' ')
			{
				fscanf(m_FilePointer, "f %i %i %i", &fx, &fy, &fz);

				m_vFaces.push_back(&fx);
				m_vFaces.push_back(&fy);
				m_vFaces.push_back(&fz);
			}
			break;

		}*/
		
	}

	// Close the .obj file that we opened
	fclose(m_FilePointer);

}

void OBJLoader::Render() //Render model
{
	//m_ModelInstance.Render();
}

void OBJLoader::Release()// Release the model 
{

}

float * OBJLoader::CalculateNormal(float * coord1, float * coord2, float * coord3)
{
	return 0;
}