#include <windows.h>
#include <stdio.h>

#include "resource.h"
#include "GameField.h"

GameField gf;
HINSTANCE g_hInst;
HWND winmatrix[ARRAY_SIZE][ARRAY_SIZE];
int BID[ARRAY_SIZE][ARRAY_SIZE];

void InitInstance(HINSTANCE hInst);
INT_PTR CALLBACK DialogFunc(HWND, UINT, WPARAM, LPARAM);

int WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	InitInstance(hInst);
	DialogBox(hInst, MAKEINTRESOURCE(IDD_MAINDIALOG), NULL, DialogFunc);
}

void InitInstance(HINSTANCE hInst)
{
	g_hInst = hInst;
}

INT_PTR CALLBACK DialogFunc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		for (int i = 0; i < ARRAY_SIZE; i++) {
			for (int j = 0; j < ARRAY_SIZE; j++) {
				gf.SetCurrentCell(j, i);
				gf.WriteCellHWND(CreateWindow("BUTTON", "", WS_BORDER | WS_CHILD | WS_VISIBLE, 20 + j * 35, 20 + i *35, 30, 30, hDlg, (HMENU)BID[j][i], g_hInst, NULL));
				//SetWindowText(winmatrix[j][i], string);
			}
		}
		/*winmatrix[0][1] = CreateWindow("BUTTON", "01", WS_BORDER | WS_CHILD | WS_VISIBLE, 20, 55, 30, 30, hDlg, NULL, g_hInst, NULL);
		winmatrix[0][2] = CreateWindow("BUTTON", "02", WS_BORDER | WS_CHILD | WS_VISIBLE, 20, 90, 30, 30, hDlg, NULL, g_hInst, NULL);
		winmatrix[0][3] = CreateWindow("BUTTON", "03", WS_BORDER | WS_CHILD | WS_VISIBLE, 20, 125, 30, 30, hDlg, NULL, g_hInst, NULL);
		winmatrix[0][4] = CreateWindow("BUTTON", "04", WS_BORDER | WS_CHILD | WS_VISIBLE, 20, 160, 30, 30, hDlg, NULL, g_hInst, NULL);

		winmatrix[1][0] = CreateWindow("BUTTON", "10", WS_BORDER | WS_CHILD | WS_VISIBLE, 55, 20, 30, 30, hDlg, (HMENU)ID_10, g_hInst, NULL);
		winmatrix[1][1] = CreateWindow("BUTTON", "11", WS_BORDER | WS_CHILD | WS_VISIBLE, 55, 55, 30, 30, hDlg, NULL, g_hInst, NULL);
		winmatrix[1][2] = CreateWindow("BUTTON", "12", WS_BORDER | WS_CHILD | WS_VISIBLE, 55, 90, 30, 30, hDlg, NULL, g_hInst, NULL);
		winmatrix[1][3] = CreateWindow("BUTTON", "13", WS_BORDER | WS_CHILD | WS_VISIBLE, 55, 125, 30, 30, hDlg, NULL, g_hInst, NULL);
		winmatrix[1][4] = CreateWindow("BUTTON", "14", WS_BORDER | WS_CHILD | WS_VISIBLE, 55, 160, 30, 30, hDlg, NULL, g_hInst, NULL);

		winmatrix[2][0] = CreateWindow("BUTTON", "20", WS_BORDER | WS_CHILD | WS_VISIBLE, 90, 20, 30, 30, hDlg, NULL, g_hInst, NULL);
		winmatrix[2][1] = CreateWindow("BUTTON", "21", WS_BORDER | WS_CHILD | WS_VISIBLE, 90, 55, 30, 30, hDlg, NULL, g_hInst, NULL);
		winmatrix[2][2] = CreateWindow("BUTTON", "22", WS_BORDER | WS_CHILD | WS_VISIBLE, 90, 90, 30, 30, hDlg, NULL, g_hInst, NULL);
		winmatrix[2][3] = CreateWindow("BUTTON", "23", WS_BORDER | WS_CHILD | WS_VISIBLE, 90, 125, 30, 30, hDlg, NULL, g_hInst, NULL);
		winmatrix[2][4] = CreateWindow("BUTTON", "24", WS_BORDER | WS_CHILD | WS_VISIBLE, 90, 160, 30, 30, hDlg, NULL, g_hInst, NULL); */
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_00:
			SetParent(winmatrix[0][1], HWND_MESSAGE);
			break;
		case ID_10:
			SetParent(winmatrix[0][1], hDlg);
			break;
		case IDSETFIELD:
			for (int i = 0; i < ARRAY_SIZE; i++) {
				for (int j = 0; j < ARRAY_SIZE; j++) {
					gf.SetCurrentCell(j, i);
					if (gf.CheckCellNow()) SetParent(gf.ReadCellHWND(), HWND_MESSAGE);
					else SetParent(gf.ReadCellHWND(), hDlg);
				}
			}
			break;
		case IDRESETFIELD:
			for (int i = 0; i < ARRAY_SIZE; i++) {
				for (int j = 0; j < ARRAY_SIZE; j++) {
					gf.SetCurrentCell(j, i);
					if (gf.CheckCellBefore()) SetParent(gf.ReadCellHWND(), HWND_MESSAGE);
					else SetParent(gf.ReadCellHWND(), hDlg);
				}
			}
			break;
		case WM_TIMER:
			break;
		case IDOK:
		case IDCANCEL:
			EndDialog(hDlg, wParam);
			return TRUE;
		}
		break;
	}
	return FALSE;
}
