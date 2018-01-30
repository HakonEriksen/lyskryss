#include "stdafx.h"
#include "Car.h"
#include "resource.h"


Car::Car()
{
}

Car::Car(int x, int y, bool d)
{
	this->xpos = x;
	this->ypos = y;
	this->dir = d;
}

int Car::getxpos()
{
	return this->xpos;
}


Car::~Car()
{
}

int Car::getypos() {
	return this->ypos;
}

bool Car::getDir() {
	return this->dir;
}

bool Car::passedLight() {
	if (this->dir)
		return (xpos > 400); // Values not necessarily right
	else
		return (ypos < 400);
}

void Car::move() {
	this->xpos += 5;
}

// Don't use this!
void DrawCar(HINSTANCE hInst, HDC hdc, int x, int y) {
	//Creates a DC in memory
	HDC hdcMem = CreateCompatibleDC(hdc);
	//Creates a bitmap to use as drawing
	HBITMAP bm = CreateCompatibleBitmap(hdc, 214, 80);
	// Adds the bitmap to the memory DC to create a drawing surface
	SelectObject(hdcMem, bm);

	//Load the bitmap
	HDC hdcCar = CreateCompatibleDC(hdc);
	HBITMAP bmCar = CreateCompatibleBitmap(hdc, 214, 80);
	//bmCar = (HBITMAP)::LoadImage(NULL, _T("car.bmp"), IMAGE_BITMAP, 0, 0, (LR_LOADFROMFILE, LR_DEFAULTSIZE));
	bmCar = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
	SelectObject(hdcCar, bmCar);

	BitBlt(hdcMem, 0, 0, 214, 80, hdcCar, 0, 0, SRCCOPY);
	//TextOut(hdcMem, 0, 0, _T("Hei"), 3);

	// Copy memory buffer to screen
	BitBlt(hdc, 0 + x, y, 214, 80, hdcMem, 0, 0, SRCCOPY);

	DeleteDC(hdcCar);
	DeleteDC(hdcMem);
	DeleteObject(bm);
	DeleteObject(bmCar);
}