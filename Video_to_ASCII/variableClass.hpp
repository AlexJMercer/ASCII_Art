#pragma once

#include <vector>
#include <algorithm>
#include <Windows.h>

class controlVariables {
public:
	int VIEWPORT_HEIGHT;
	int VIEWPORT_WIDTH;
	int USER_DEFINED_FPS;
	int frame_time;

	std::vector<int> FPS_Arr { 12, 24, 30, 50, 60, 90, 144 };
	
	// Screen Height
	std::vector<int> resolution_Arr { 
		40, 50, 72, 144, 240
	};


	controlVariables();
	~controlVariables();

	
	void recalculateWidth(int height);
	void recalculateFPS();


	void inreaseFPS();
	void decreaseFPS();


	void increaseResolution();
	void decreaseResolution();


	// This function is used to change the window size
	void changeWindowSize(WORD key);

};