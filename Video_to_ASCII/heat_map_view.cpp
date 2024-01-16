#include "required_lib.h"

using namespace std;
using namespace cv;


string pixelToASCII(Vec3b pixel) {

    // backwards string is : "   ._-=+*!&#%$@"
    //const string ASCII_Shaders = " .,'_-^=+*!)#&%$@";
    //const string ASCII_Shaders = "@$%#&!*+=-.   ";
    //const string ASCII_Shaders = "   ._-=+*!&#%$@";       // Better looking one

    const string ASCII_Shaders = " ._-=+*!&#%$@$%#&!*+=-. ";          // Muted the highlights and shadows for even look (Best look in my opinion)

    int intensity = (pixel[0] + pixel[1] + pixel[2]) / 3;
    int index = intensity * (ASCII_Shaders.length() - 1) / 255;

    if (intensity < 85) {
        return "\033[0;31m" + string(1, ASCII_Shaders[index]);  // Red
    }
    else if (intensity < 170) {
        return "\033[0;32m" + string(1, ASCII_Shaders[index]);  // Green
    }
    else {
        return "\033[0;34m" + string(1, ASCII_Shaders[index]);  // Blue
    }

}




void printASCIIArt_heatmap(const Mat& frame, int width, int height) {
    string ascii_frame;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Vec3b pixel = frame.at<Vec3b>(i, j);
            ascii_frame += pixelToASCII(pixel) + "\033[0m";
        }
        ascii_frame += '\n';
    }

    cout << "\033[H";
    cout << ascii_frame;
}




void predatorVisionView(controlVariables* obj) {

    VideoCapture video(0);
    if (!video.isOpened()) {
        cerr << "Camera not available !" << endl;
        return;
    }

    Mat frame, resized_frame;


    int height = obj->VIEWPORT_HEIGHT;
    int width = obj->VIEWPORT_WIDTH;
    int USER_DEFINED_FPS = obj->USER_DEFINED_FPS;


    system("cls");

    while (true) {
        video >> frame;

        resize(frame, resized_frame, Size(obj->VIEWPORT_WIDTH, obj->VIEWPORT_HEIGHT), 0, 0, INTER_AREA);

        cout << "FPS : " << to_string(obj->USER_DEFINED_FPS) << "\t\t|\t\t"
            << "Frame Time : " << to_string(obj->frame_time) << "ms" << "\t\t|\t\t"
            << "Resolution : " << obj->VIEWPORT_WIDTH << " x " << obj->VIEWPORT_HEIGHT
            << "\t\t|" << endl;

        printASCIIArt_heatmap(resized_frame, obj->VIEWPORT_WIDTH, obj->VIEWPORT_HEIGHT);

        this_thread::sleep_for(chrono::milliseconds(obj->frame_time));
  
        // To increase Resolution
        if (GetAsyncKeyState(VK_ADD) & 0x8000) {
            system("cls");
            obj->changeWindowSize(VK_SUBTRACT);
            obj->increaseResolution();
        }

        // To decrease Resolution
        if (GetAsyncKeyState(VK_SUBTRACT) & 0x8000) {
            system("cls");
            obj->changeWindowSize(VK_ADD);
            obj->decreaseResolution();
        }

        // To increase FPS
        if (GetAsyncKeyState(0x56) & 0x8000) {
            obj->inreaseFPS();
        }

        // To decrease FPS
        if (GetAsyncKeyState(0x43) & 0x8000) {
            obj->decreaseFPS();
        }

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break;
        }
    }

    video.release();
    video.~VideoCapture();

    return;
}
