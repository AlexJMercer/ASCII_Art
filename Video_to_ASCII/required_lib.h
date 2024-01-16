#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>

#include "variableClass.cpp"

#define LEAN_AND_MEAN
#define NOMINMAX

// Function declarations
void asciiOptimized(controlVariables* var);
void predatorVisionView(controlVariables* var);
void viewFullColor(controlVariables* var, int mode);

