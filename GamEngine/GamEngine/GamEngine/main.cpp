#include "global.h"

LRESULT CALLBACK WndProc(	HWND hWnd, UINT msg,
							WPARAM wParam, LPARAM lParam )
{

	switch( msg ) {

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;

	}

	return DefWindowProc( hWnd, msg, wParam, lParam );
}

int WINAPI WinMain( HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR lpCmdLine,
					int nCmdShow )
{

	HWND hWnd;

	WNDCLASSEX wcx;

	ZeroMemory( &wcx, sizeof(WNDCLASSEX) );

	wcx.cbSize			=	sizeof( WNDCLASSEX );
	wcx.hCursor			=	LoadCursor( hInstance, IDC_ARROW );
	wcx.hIcon			=	LoadIcon( hInstance, IDI_APPLICATION);
	wcx.hIconSm			=	LoadIcon( hInstance, IDI_APPLICATION);
	wcx.hInstance		=	hInstance;
	wcx.lpszClassName	=	"GameWindow1";
	wcx.hbrBackground	=	HBRUSH( COLOR_WINDOW );
	wcx.style			=	CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc		=	WndProc;

	RegisterClassEx( &wcx );

	hWnd = CreateWindowEx(	NULL, "GameWindow1",
							"GameWindow", WS_OVERLAPPEDWINDOW,
							50, 50, 1580, 950, NULL, NULL,
							hInstance, NULL );

	if( hWnd == NULL ) {

		MessageBoxA( NULL, "Error 1:", "Failed Window Creation", MB_OK | MB_ICONEXCLAMATION );
		return 0;

	}

	ShowWindow( hWnd, nCmdShow );

	MSG msg;

	while( GetMessage( &msg, NULL, 0, 0 ) ) {

		TranslateMessage( &msg );

		DispatchMessage( &msg );

	}

	return msg.wParam;

}