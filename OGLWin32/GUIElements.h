#pragma once 
#include <Windows.h> 
#include <CommCtrl.h>
//Collections of all Win32 GUI Elements 

static class GUIElements
{
private: 
	static HWND m_Handle;
public: 
	static void					CreateGUIMenu(HWND hWnd);
	static void					CreateGUIButton(HWND hWnd, LPCWSTR text, int x, int y, int width, int height, int NumberHinstance);
	static void					CreateGUIToolBar(HWND hwnd);

	static HWND GetGUIHandle(){ return m_Handle;}
	static void SetGUIHandle(HWND handle) { m_Handle = handle; }
 

};