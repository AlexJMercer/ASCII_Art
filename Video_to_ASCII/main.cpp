#include "required_lib.hpp"



using namespace std;
using namespace cv;



int main() {

	controlVariables* var = new controlVariables;
	
	SHORT ch;
	
	do {
		system("cls");
		cout << "|---------------- Welcome to ASCII-Cam ---------------|\n"
			<< "\n"
			<< "1. Run BnW version (2-bit color)\n"
			<< "2. Run HeatMap version (I call it Predator Vision)\n"
			<< "3. Run Full-Color mode (24-bit color)\n"
			<< "4. Funky Mode XD\n"
			<< "5. Exit\n"
			<< "\n"
			<< "Controls : [ V ] Increase FPS ( 12, 24, 30, 50, 60, 90, 144 )\n"
			<< "           [ C ] Decrease FPS ( Min. 12 )\n"
			<< "	   [ + ] Increase Resolution (More Compute)\n"
			<< "	   [ - ] Decrease Resolution (Less Compute)\n"
			<< "Choose any option : ";

		cin >> ch;

		switch (ch)
		{
		case 1:
			asciiOptimized(var);
			break;
		case 2:
			predatorVisionView(var);
			break;
		case 3:
			viewFullColor(var, 2);
			break;
		case 4:
			viewFullColor(var, 5);
			break;
		case 5:
			break;

		default:
			cout << "Invalid Input !";
			break;
		}

	} while (ch != 5);

	delete var;

	return 0;
}