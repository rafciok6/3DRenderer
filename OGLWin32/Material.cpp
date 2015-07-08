#include "Material.h"

//This method creates a texture in OpenGL that we can texture map 
//Create texture from the BitMap File 
bool Material::CreateTexture(GLuint &textureID, LPCWSTR szFileName)
{
	HBITMAP	hBMP;  //handle to the bit map 
	BITMAP bitmap; //Bitmap structure 

	glGenTextures(1, &textureID);  //create the texture 
	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), szFileName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	if (!hBMP) //does the bitmap exist? 
	{
		return FALSE; //If not return false
	}

	GetObject(hBMP, sizeof(bitmap), &bitmap);  // Get The Object
	// hBMP:        Handle To Graphics Object
	// sizeof(bitmap): Size Of Buffer For Object Information
	// &bitmap:        Buffer For Object Information

	//Pixel Storage Mode (World Alignment / 4 Bytes) 
	glPixelStorei(GL_TEXTURE_2D, textureID);

	//Typical Texture Generation Using Data From The Bitmap 
	glBindTexture(GL_TEXTURE_2D, textureID); //Bind To Texture ID
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);  //Linear Min Filter 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);  //Linear Mag Filter
	glTexImage2D(GL_TEXTURE_2D, 0, 3, bitmap.bmWidth, bitmap.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, bitmap.bmBits);
	// MUST NOT BE INDEX BMP, BUT RGB
	DeleteObject(hBMP);                                                           // Delete The Object

	return TRUE;                                                                  // Loading Was Successful
}