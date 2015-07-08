#include "GUIElements.h"

void GUIElements::CreateGUIMenu(HWND hWnd)
{
	HMENU hMenuBar;
	HMENU hMenu;

	hMenuBar = CreateMenu();
	hMenu = CreateMenu();

	AppendMenu(hMenu, MF_STRING, 1, L"Exit");

	AppendMenuW(hMenuBar, MF_POPUP, (UINT_PTR)hMenu, L"File");
	SetMenu(hWnd, hMenuBar);
}

void	GUIElements::CreateGUIButton(HWND hWnd, LPCWSTR text, int x, int y, int width, int height, int NumberHinstance)
{
	//Create Button 
	HWND hWndButton;
	hWndButton = CreateWindowEx(NULL,
		L"BUTTON",
		text,
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		x,
		y,
		width,
		height,
		hWnd,
		(HMENU)NumberHinstance,
		GetModuleHandle(NULL),
		NULL);
}

void GUIElements::CreateGUIToolBar(HWND hwnd)
{
	HWND hTool;
	hTool = CreateWindowEx(0, TOOLBARCLASSNAME, NULL, WS_EX_RIGHT | WS_BORDER | WS_CHILD | WS_VISIBLE, 0, 0, 0, 0,
		hwnd, (HMENU)5, GetModuleHandle(NULL), NULL);

	SendMessage(hTool, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);

	//Add buttons 
	TBBUTTON tbb[3];
	TBADDBITMAP tbab;
	//And then we add the standard bitmaps to the toolbar, using the imagelist predefined in the common control library...
	tbab.hInst = HINST_COMMCTRL;
	tbab.nID = IDB_STD_SMALL_COLOR;
	SendMessage(hTool, TB_ADDBITMAP, 0, (LPARAM)&tbab);
	//Now that we have our images loaded up, we can add some buttons that use them.

	ZeroMemory(tbb, sizeof(tbb));
	tbb[0].iBitmap = STD_REPLACE;
	tbb[0].fsState = TBSTATE_ENABLED;
	tbb[0].fsStyle = TBSTYLE_BUTTON;
	tbb[0].idCommand = 8;

	tbb[1].iBitmap = STD_FILEOPEN;
	tbb[1].fsState = TBSTATE_ENABLED;
	tbb[1].fsStyle = TBSTYLE_BUTTON;
	tbb[1].idCommand = 9;

	tbb[2].iBitmap = STD_FILESAVE;
	tbb[2].fsState = TBSTATE_ENABLED;
	tbb[2].fsStyle = TBSTYLE_BUTTON;
	tbb[2].idCommand = 7;

	SendMessage(hTool, TB_ADDBUTTONS, sizeof(tbb) / sizeof(TBBUTTON), (LPARAM)&tbb);
	//__________________________________________________________________________________

	CreateWindowEx(0, STATUSCLASSNAME, NULL,
		WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP, 0, 0, 0, 0,
		hwnd, (HMENU)6, GetModuleHandle(NULL), NULL);
}