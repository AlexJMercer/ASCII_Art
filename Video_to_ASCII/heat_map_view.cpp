#include <opencv2/opencv.hpp>
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>

#define LEAN_AND_MEAN
#define NOMINMAX

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
    else  {
        return "\033[0;34m" + string(1, ASCII_Shaders[index]);  // Blue
    }
    
}





void printASCIIArt(const Mat& frame, int width, int height) {
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





int main() {

    VideoCapture video(0);
    if (!video.isOpened()) {
        cerr << "Camera not available !" << endl;
        return -1;
    }

    Mat frame, resized_frame;


    int height = 50;
    int width = height * 3.5;
    int USER_DEFINED_FPS = 30;

    int fixed_fps_cap = static_cast<int>(1000 / USER_DEFINED_FPS);

    system("cls");

    while (true) {
        video >> frame;

        resize(frame, resized_frame, Size(width, height), 0, 0, INTER_AREA);

        printASCIIArt(resized_frame, width, height);

        this_thread::sleep_for(chrono::milliseconds(fixed_fps_cap));
    }

    video.release();
    video.~VideoCapture();

    return 0;
}
