#pragma once
#include "required_lib.h"


string pixelToASCII(Vec3b pixel);

string pixelToASCII(Vec3b pixel, int c);

void printASCIIArt(const Mat& frame, int width, int height, int funky);
