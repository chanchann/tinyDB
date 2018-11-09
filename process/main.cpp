#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#define Debug 1

using namespace std;
using namespace cv;
void read_images_in_folder(cv::String pattern);
int main()
{

    cv::String pattern="/home/chanchan/cv/test_img/*.jpg";
    read_images_in_folder(pattern);
    return 0;
}

void read_images_in_folder(cv::String pattern)
{
    vector<cv::String> fn;
    glob(pattern, fn, false);

    size_t cnt = fn.size(); //number of png files in images folder
    for (int i = 0; i < cnt; i++) {

        Mat srcImg = imread(fn[i], 0);
        if(Debug) imshow("src", srcImg);

        Mat temp1, temp2, temp3, temp4;
        cv::equalizeHist(srcImg, temp1);
        if(Debug) imshow("temp1", temp1);

        cv::medianBlur(temp1, temp2, 3);
        if(Debug) imshow("temp2", temp2);

        cv::threshold(temp1, temp3, 55, 255, cv::THRESH_TRUNC);
        if(Debug) imshow("temp3", temp3);

        Mat out = cv::Mat::zeros(50, 4*30, CV_8U);
        temp2(Rect(5,2,30,50)).copyTo(out(Rect(0,0,30,50)));
        temp2(Rect(65,2,30,50)).copyTo(out(Rect(30,0,30,50)));
        temp2(Rect(125,2,30,50)).copyTo(out(Rect(60,0,30,50)));
        temp2(Rect(185,2,30,50)).copyTo(out(Rect(90,0,30,50)));

        cv::threshold(out, out, 54, 255, cv::THRESH_BINARY_INV);

        if(Debug) imshow("out", out);

        Mat dstImage = Mat(out.rows, out.cols, CV_8UC3, Scalar(255,255,255));

        vector<vector<Point> > contours;
        vector<Vec4i> hierarchy;

        findContours( out, contours, hierarchy,
            CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );

        for( int index = 0; index >= 0; index = hierarchy[index][0] )
        {
            Scalar color( rand()&255, rand()&255, rand()&255 );

            Point2f center;
            float radius = 0;
            minEnclosingCircle(Mat(contours.at(index)), center, radius);

            if (radius < 4)
                continue;
            if(Debug) cout << index << ":\t" << radius << endl;

            int c = 255 - radius*20;
            if (radius > 12)
                c = 0;
            drawContours( dstImage, contours, index, Scalar(c, c, c), CV_FILLED, 8, hierarchy );

//            for( int i = 0; i < 4; i++ )
//                circle(dstImage, center, cvRound(radius), color, 1, CV_AA);
        }


        if(Debug) imshow( "dst", dstImage );
        cout << fn[i] << endl;
        cout<<typeid(fn[i]).name()<<endl;
        if(Debug) cout << "=========================" << endl;

//        cv::medianBlur(dstImage, temp4, 3);
//        Mat element = getStructuringElement(MORPH_RECT, Size(2, 2), Point(0, 0));
//        morphologyEx(dstImage, temp4, cv::MORPH_OPEN, element);
//        imshow("temp4", temp4);



        if ('c' == (char)waitKey(3)) {
            break;
        }
        else if (!Debug) {
            cout<<"correct"<<endl;
            cv::imwrite(cv::String("../train/%1"), dstImage);
        }
     }
}
