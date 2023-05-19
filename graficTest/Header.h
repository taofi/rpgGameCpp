#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "img.h"

using namespace std;

struct objForGraf
{
	short int x;
	short int y;
	const pxImage* img;
};