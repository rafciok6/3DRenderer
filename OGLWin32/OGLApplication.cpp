#include "OGLApplication.h"
#include "OGLWindow.h"
#include "Resource.h"
#include <Windowsx.h>
#include <CommCtrl.h>

#define IDC_MAIN_BUTTON 101


OGLApplication* OGLApplication::s_oglapp = NULL;

OGLApplication::OGLApplication()
{
	m_appwnd = NULL;
	m_hInst = 0;
	m_terminate = FALSE;
}

OGLApplication::~OGLApplication()
{
	if ( m_appwnd )
		delete m_appwnd;
}

BOOL OGLApplication::MyRegisterClass(HINSTANCE hinst)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= this->WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hinst;
	wcex.hIcon			= LoadIcon(hinst, MAKEINTRESOURCE(IDI_OGLWIN32));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= NULL;
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= L"OGLWindow";
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	
	if ( !RegisterClassEx ( &wcex ) )
		return FALSE;

	return TRUE;
}

OGLApplication* OGLApplication::CreateApplication(HINSTANCE hinst)
{
	if ( ! s_oglapp )
	{
		s_oglapp = new OGLApplication();

		s_oglapp->m_hInst = hinst;
		s_oglapp->MyRegisterClass(hinst);

		//Now create an OGLWindow for this application
		s_oglapp->CreateApplicationWindow(1024,768);
	}

	return s_oglapp;
}

void OGLApplication::DestroyApplication()
{
	if ( s_oglapp )
		delete s_oglapp;
}

OGLApplication* OGLApplication::GetApplication()
{
	return s_oglapp;
}

void OGLApplication::CreateApplicationWindow( int width, int height )
{
	if ( !m_appwnd  )
	{
		m_appwnd = new OGLWindow ( m_hInst, width, height );
		m_appwnd->SetVisible(TRUE);
	}
}

int OGLApplication::Run()
{
	MSG msg;

	while ( !m_terminate )
	{
		if ( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
		{
			//peek for windows message
			if ( msg.message == WM_QUIT )
			{
				Kill();
			}
			else
			{
				TranslateMessage ( &msg );
				DispatchMessage ( &msg );
			}
		}
		else
		{
			//get the OGLWindow to render stuff;
			m_appwnd->Render();
		}
	}

	return (int) msg.wParam;
}

void OGLApplication::Kill()
{
	m_terminate = TRUE;
}

LRESULT CALLBACK OGLApplication::WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	int wmId, wmEvent;

	switch ( msg )
	{
		case WM_CREATE:



			GUIElements::CreateGUIMenu(hwnd); 
			GUIElements::CreateGUIToolBar(hwnd);

			//CreateButton(hwnd, L"Change Background", 10, 40, 150, 30, IDC_MAIN_BUTTON);
			GUIElements::CreateGUIButton(hwnd, L"Change Background", 10, 40, 150, 30, IDC_MAIN_BUTTON);
			GUIElements::CreateGUIButton(hwnd, L"Exit", 10, 80, 150, 30, 102);
			break;

			//To handle menu commands 
		case WM_COMMAND: 
			switch (LOWORD(wparam))
			{
			case 1:
				SendMessage(hwnd, WM_CLOSE, 0, 0);
				break; 
			case IDC_MAIN_BUTTON:
				s_oglapp->GetApplicationWindow()->ChangeColor(1.0, 0.2, 0.0);
				break;
			case 8:
				s_oglapp->GetApplicationWindow()->ChangeColor(0.0, 0.5, 0.2);

				break;
			case 102:
				SendMessage(hwnd, WM_CLOSE, 0, 0);
				break;
			}
			break;
		case WM_SIZE:
			s_oglapp->GetApplicationWindow()->Resize( LOWORD(lparam), HIWORD(lparam) );
			break;

		case WM_CLOSE:
			s_oglapp->GetApplicationWindow()->DestroyOGLWindow();
			exit(0); 
			break;

		case WM_MOUSEMOVE:
			//inform the cursor position to OGLWindow
			s_oglapp->GetApplicationWindow()->MouseMove( GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam) );
			break;

		case WM_LBUTTONUP:
			s_oglapp->GetApplicationWindow()->MouseLBUp( GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam) );
			break;

		case WM_LBUTTONDOWN:
			s_oglapp->GetApplicationWindow()->MouseLBDown( GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam) );
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc( hwnd, msg, wparam, lparam );
	}

	return 0;
}




