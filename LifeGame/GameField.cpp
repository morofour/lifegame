//
//
//
#include "GameField.h"

GameField::GameField() {
	FILE * pFile;
	fopen_s(&pFile, "FieldInitialState.txt", "r");

	for (int i = 0; i < ARRAY_SIZE; i++) {
		for (int j = 0; j < ARRAY_SIZE; j++) {
			fscanf_s(pFile, "%i", &isliveornot[j][i]);
		}
	}

	fclose(pFile);

	fopen_s(&pFile, "FieldNextState.txt", "r");

	for (int i = 0; i < ARRAY_SIZE; i++) {
		for (int j = 0; j < ARRAY_SIZE; j++) {
			fscanf_s(pFile, "%i", &wasliveornot[j][i]);
		}
	}

	fclose(pFile);
}

GameField::~GameField() {

}

int GameField::CheckCellNow() {
	return isliveornot[currentcell_x][currentcell_y];
}

int GameField::CheckCellBefore() {
	return wasliveornot[currentcell_x][currentcell_y];
}

void GameField::WriteCellHWND(HWND hWnd) {
	winmatrix[currentcell_x][currentcell_y] = hWnd;
}

void GameField::SetCurrentCell(int x, int y) {
	currentcell_x = x;
	currentcell_y = y;
}

HWND GameField::ReadCellHWND() {
	return winmatrix[currentcell_x][currentcell_y];
}
