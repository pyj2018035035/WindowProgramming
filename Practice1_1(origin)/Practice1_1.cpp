// Change the ���� ���ڵ�
// 1. Project
// 2. Practice1_1 �Ӽ�
// 3. ���� �Ӽ� - �Ϲ�
// 4. ���� ����
// 5. ��Ƽ����Ʈ ���� ���� ��� -> ��Ƽ����Ʈ ���� ���� ���

#include<windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) {
	static LPCTSTR szAppName = "EasyText";
	static LPCTSTR szTitleName = "Pratice1-1";

	HWND hwnd;
	MSG msg;
	WNDCLASSEX WndClass;

	WndClass.cbSize = sizeof(WNDCLASSEX);
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_HAND);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = szAppName;
	WndClass.hIconSm = 0;

	RegisterClassEx(&WndClass);

	int screenWidth = ::GetSystemMetrics(SM_CXFULLSCREEN);
	int screenHeight = ::GetSystemMetrics(SM_CYFULLSCREEN);
	int wndWidth = screenWidth / 2;
	int wndHeight = screenHeight / 2;
	int posX = 0;
	int poxY = 0;

	hwnd = CreateWindow(
		szAppName,
		szTitleName,
		WS_OVERLAPPEDWINDOW,
		screenWidth / 4,
		screenHeight / 4,
		wndWidth,
		wndHeight,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	RECT rect;
	PAINTSTRUCT ps;
	LPCTSTR szMsg1 = "I love Window Programming!";
	LPCTSTR szMsg2 = "Ű���尡 ���������ϴ�.";
	LPCTSTR szMsg3 = "Ű���尡 ���������ϴ�.";
	LPCTSTR szMsg4 = "���콺�� ���������ϴ�.";
	LPCTSTR szMsg5 = "���콺�� �̵� ���Դϴ�.";
	LPTSTR szMsg6 = new char[10];
	POINT MousePoint;



	switch (message) {
	case WM_CREATE:
		break;
	case WM_PAINT:
		// �������� �� �κп��� ������ ���� ������.
		// MessageBeep()�� Ȱ���Ͽ� �Ҹ��� ������.
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 10, 10, szMsg1, strlen(szMsg1));
		EndPaint(hwnd, &ps);
		break;
	case WM_KEYDOWN:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg2, strlen(szMsg2), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_KEYUP:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg3, strlen(szMsg3), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_LBUTTONDBLCLK:
		MessageBox(hwnd, "���콺 ���� Ŭ��!", "���콺�޽���", MB_OKCANCEL | MB_ICONASTERISK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg4, strlen(szMsg4), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		MousePoint.x = LOWORD(lParam);
		MousePoint.y = HIWORD(lParam);
		wsprintf(szMsg6, " X:%ld, Y:%ld", MousePoint.x, MousePoint.y);
		TextOut(hdc, MousePoint.x, MousePoint.y, szMsg6, strlen(szMsg6));
		ReleaseDC(hwnd, hdc);
		break;
	case WM_LBUTTONUP:
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	case WM_MOUSEMOVE:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg5, strlen(szMsg5), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}