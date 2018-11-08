#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

vector<Mat> read_images_in_folder(cv::String pattern);

int main()
{
    cv::String pattern = "/home/chanchan/cv/test_img/*.jpg";
    vector<Mat> images = read_images_in_folder(pattern);

    return 0;   
}

vector<Mat> read_images_in_folder(cv::String pattern)
{
    vector<cv::String> fn;
    glob(pattern, fn, false);

    vector<Mat> images;
    size_t count = fn.size(); //number of jpg files in images folder
    for (size_t i = 0; i < count; i++)
    {
        images.push_back(imread(fn[i]));
        imshow("img", imread(fn[i]));
        waitKey(1000);
    }
    return images;
}
