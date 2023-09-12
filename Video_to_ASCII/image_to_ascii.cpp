#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace cv;

string pixelToASCII(Vec3b pixel) {

    // backwards string is : "   ._-=+*!&#%$@"
    //const string ASCII_Shaders = "@$%#&!*+=-.   ";
    const string ASCII_Shaders = " ._-=+*!&#%$@$%#&!*+=-. ";          // Muted the highlights and shadows for even look
    //const string ASCII_Shaders = "   ._-=+*!&#%$@";       // Better looking one
    //const string ASCII_Shaders = " .,'_-^=+*!)#&%$@";

    int intensity = (pixel[0] + pixel[1] + pixel[2]) / 3;
    int index = intensity * (ASCII_Shaders.length() - 1) / 255;

    return string(1, ASCII_Shaders[index]);
}

void printASCIIArt(const Mat& frame, int width, int height) {
    string ascii_frame;

    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++) 
        {
            Vec3b pixel = frame.at<Vec3b>(i, j);
            ascii_frame += pixelToASCII(pixel);
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

    int width = 120;
    int height = 50;

    Mat frame, resized_frame;

    while (true) {
        video >> frame;

        resize(frame, resized_frame, Size(width, height), 0, 0, INTER_AREA);

        printASCIIArt(resized_frame, width, height);

        this_thread::sleep_for(chrono::milliseconds(1000/CAP_PROP_FPS));
    }

    video.release();
    video.~VideoCapture();

    return 0;
}
