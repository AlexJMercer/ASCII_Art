#pragma once

#include <opencv2/opencv.hpp>
#include <string>

// ascii_optimized

std::string pixelToASCII_bnw(cv::Vec3b pixel);
void printASCIIArt_bnw(const cv::Mat& frame, int width, int height);
void asciiOptimized(controlVariables* obj);


// heatmap view
std::string pixelToASCII(cv::Vec3b pixel);
void printASCIIArt_heatmap(const cv::Mat& frame, int width, int height);
void predatorVisionView(controlVariables* obj);

// full color
std::string pixelToASCII(cv::Vec3b pixel, int c);
void printASCIIArt(const cv::Mat& frame, int width, int height, int funky);
void viewFullColor(controlVariables* obj, int funkyBool);
