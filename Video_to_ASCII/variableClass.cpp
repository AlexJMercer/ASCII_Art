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


	controlVariables() {
		VIEWPORT_HEIGHT = 50;
		VIEWPORT_WIDTH = 3 * VIEWPORT_HEIGHT;
		USER_DEFINED_FPS = 24;
		recalculateFPS();
	}

	~controlVariables() {
		FPS_Arr.~vector();
		resolution_Arr.~vector();
	}

	void recalculateWidth(int height) {
		this->VIEWPORT_WIDTH = 3 * height;
	}

	void recalculateFPS() {
		 this->frame_time = static_cast<int>(1000 / this->USER_DEFINED_FPS);
	}

	void inreaseFPS() {
		auto iter = find(
			FPS_Arr.begin(), 
			FPS_Arr.end(), 
			this->USER_DEFINED_FPS
		);
		int index = std::distance(FPS_Arr.begin(), iter);
		
		if (index == FPS_Arr.size() - 1)
			return;

		this->USER_DEFINED_FPS = FPS_Arr[ ++index ];
		recalculateFPS();
	}

	void decreaseFPS() {
		auto iter = find(
			FPS_Arr.begin(), 
			FPS_Arr.end(), 
			this->USER_DEFINED_FPS
		);
		int index = std::distance(FPS_Arr.begin(), iter);

		if (index == 0)
			return;

		this->USER_DEFINED_FPS = FPS_Arr[ --index ];
		recalculateFPS();
	}



	void increaseResolution() {
		auto iter = find(
			resolution_Arr.begin(), 
			resolution_Arr.end(), 
			this->VIEWPORT_HEIGHT
		);

		int index = std::distance(resolution_Arr.begin(), iter);

		if (index == resolution_Arr.size() - 1)
			return;

		this->VIEWPORT_HEIGHT = resolution_Arr[ ++index ];
		recalculateWidth(this->VIEWPORT_HEIGHT);
	}

	void decreaseResolution() {
		auto iter = find(
			resolution_Arr.begin(),
			resolution_Arr.end(),
			this->VIEWPORT_HEIGHT
		);

		int index = std::distance(resolution_Arr.begin(), iter);

		if (index == 0)
			return;

		this->VIEWPORT_HEIGHT = resolution_Arr[ --index ];
		recalculateWidth(this->VIEWPORT_HEIGHT);
	}



	// This function is used to change the window size
	void changeWindowSize(WORD key) {
		INPUT input[2];

		// Press Ctrl
		input[0].type = INPUT_KEYBOARD;
		input[0].ki.wVk = VK_CONTROL;
		input[0].ki.dwFlags = 0; // 0 for key press

		// Press '+'
		input[1].type = INPUT_KEYBOARD;
		input[1].ki.wVk = key;
		input[1].ki.dwFlags = 0; // 0 for key press

		SendInput(2, input, sizeof(INPUT));

		// Release both keys
		input[0].ki.dwFlags = KEYEVENTF_KEYUP;
		input[1].ki.dwFlags = KEYEVENTF_KEYUP;

		SendInput(2, input, sizeof(INPUT));
	}

};