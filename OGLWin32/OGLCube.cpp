#include "OGLCube.h"

#include <windows.h>
#include "GLEW/include/glew.h"

OGLCube::OGLCube()
{
	m_ModelInstance.Init("../data/shader/basic.vert", "../data/shader/basic.frag");
	InitUnitCube();
}

OGLCube::~OGLCube()
{
	glDeleteVertexArrays( 1, &m_vao );

	glDeleteBuffers( 1, &m_vbo_verts );
	glDeleteBuffers( 1, &m_vbo_colours );
	glDeleteBuffers( 1, &m_vbo_indices );
}

void OGLCube::InitUnitCube()
{
	float* corners = new float[24];
	float* colours = new float[24];
	int* indices = new int[24];

	corners[0] = -0.5f;
	corners[1] = -0.5f;
	corners[2] = 0.5f;

	corners[3] = 0.5f;
	corners[4] = -0.5f;
	corners[5] = 0.5f;

	corners[6] = 0.5f;
	corners[7] = 0.5f;
	corners[8] = 0.5f;

	corners[9] = -0.5f;
	corners[10] = 0.5f;
	corners[11] = 0.5f;

	corners[12] = 0.5f;
	corners[13] = -0.5f;
	corners[14] = -0.5f;

	corners[15] = 0.5f;
	corners[16] = 0.5f;
	corners[17] = -0.5f;

	corners[18] = -0.5f;
	corners[19] = 0.5f;
	corners[20] = -0.5f;

	corners[21] = -0.5f;
	corners[22] = -0.5f;
	corners[23] = -0.5f;

	colours[0] = 0.0f;
	colours[1] = 0.0f;
	colours[2] = 0.0f;
colours[3] = 1.0f;
	colours[4] = 0.0f;
	colours[5] = 0.0f;

	colours[6] = 1.0f;
	colours[7] = 1.0f;
	colours[8] = 0.0f;

	colours[9] = 0.0f;
	colours[10] = 1.0f;
	colours[11] = 0.0f;

	colours[12] = 1.0f;
	colours[13] = 0.0f;
	colours[14] = 1.0f;

	colours[15] = 1.0f;
	colours[16] = 1.0f;
	colours[17] = 1.0f;

	colours[18] = 0.0f;
	colours[19] = 1.0f;
	colours[20] = 1.0f;

	colours[21] = 0.0f;
	colours[22] = 0.0f;
	colours[23] = 1.0f;

	
	indices[0] = 0; indices[1] = 1; indices[2] = 3; indices[3] = 2;
	indices[4] = 1; indices[5] = 4; indices[6] = 2; indices[7] = 5;
	indices[8] = 7; indices[9] = 0; indices[10] = 6; indices[11] = 3;
	indices[12] = 4; indices[13] = 7; indices[14] = 5; indices[15] = 6;
	indices[16] = 3; indices[17] = 2; indices[18] = 6; indices[19] = 5;
	indices[20] = 7; indices[21] = 4; indices[22] = 0; indices[23] = 1;

	m_ModelInstance.SetData(corners, 24 * sizeof(float), colours, 24 * sizeof(float), indices, 24 * sizeof(float));

	m_ModelInstance.SetTexture(L"Image.bmp"); 
	m_ModelInstance.SetTexture(L"Bitmap.bmp");
	m_ModelInstance.SetTexture(L"pustynia.bmp");
	m_ModelInstance.SetTexture(L"landscape.bmp");
	//glGenVertexArrays( 1, &m_vao );
	//glBindVertexArray( m_vao );

	//glGenBuffers( 1, &m_vbo_verts );
	//glBindBuffer( GL_ARRAY_BUFFER, m_vbo_verts );
	//glBufferData( GL_ARRAY_BUFFER, 24*sizeof(float), corners, GL_STATIC_DRAW );
	//glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0 );
	//glEnableVertexAttribArray ( 0 );

	//glGenBuffers( 1, &m_vbo_colours );
	//glBindBuffer( GL_ARRAY_BUFFER, m_vbo_colours );
	//glBufferData( GL_ARRAY_BUFFER, 24*sizeof(float), colours, GL_STATIC_DRAW );
	//glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, 0 );
	//glEnableVertexAttribArray ( 1 );

	//glGenBuffers( 1, &m_vbo_indices );
	//glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_vbo_indices);
	//glBufferData( GL_ELEMENT_ARRAY_BUFFER, 24*sizeof(int), indices, GL_STATIC_DRAW );

	//glBindVertexArray( 0 );

	////The mesh data may be freed from the host memory 
	////once they are transferred to the graphics hardware.
	//delete [] corners;
	//delete [] colours;
	//delete [] indices;



//	SetShader("../data/shader/basic.vert", "../data/shader/basic.frag");
}


void OGLCube::Render()
{
	m_ModelInstance.Render(); 

	//GetShader()->ActivateShaderProgram();

	//float modelview[16];
	//float projection[16];

	//glGetFloatv(GL_MODELVIEW_MATRIX, modelview);
	//glGetFloatv(GL_PROJECTION_MATRIX, projection);

	////glUniformMatrix4fv(glGetUniformLocation(GetShader()->GetProgramHandle(), "modelview"), 1, GL_FALSE, modelview);
	////glUniformMatrix4fv(glGetUniformLocation(GetShader()->GetProgramHandle(), "projection"), 1, GL_FALSE, projection);

	//glBindVertexArray( m_vao );
	//	
	//glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0 );
	//glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, (void*)(4*sizeof(int)) );
	//glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, (void*)(8*sizeof(int)) );
	//glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, (void*)(12*sizeof(int)) );
	//glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, (void*)(16*sizeof(int)) );
	//glDrawElements( GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, (void*)(20*sizeof(int)) );
	//
	//glBindVertexArray( 0 );

//	GetShader()->DeactivateShaderProgram();

}