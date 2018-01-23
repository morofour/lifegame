#pragma once

#include <windows.h>
#include <stdio.h>
#include "resource.h"

class GameField
{
public:
	GameField();
	~GameField();
	int CheckCellNow();
	int CheckCellBefore();
	void WriteCellHWND(HWND hWnd);
	HWND ReadCellHWND();
	void SetCurrentCell(int x, int y);
private:
	HWND winmatrix[ARRAY_SIZE][ARRAY_SIZE];
	int isliveornot[ARRAY_SIZE][ARRAY_SIZE];
	int wasliveornot[ARRAY_SIZE][ARRAY_SIZE];
	int currentcell_x = 0;
	int currentcell_y = 0;
};
