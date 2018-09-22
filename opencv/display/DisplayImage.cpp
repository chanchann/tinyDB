#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>

#include<iostream>
#include<string>

using namespace std;
using namespace cv;

int main(int argc,char** argv)
{
	 String imageName("../introduction/1.jpg");//by default
	if(argc>1)
	{
		imageName=argv[1];
	}
	Mat image;
	image=imread(imageName,IMREAD_COLOR);
	if(image.empty()) //Check for invalid input
	{
		cout<<"Could not open or find the iamge"<<endl;
		return -1;
	}
	namedWindow("Display window",WINDOW_AUTOSIZE);//Create a window for display
	imshow("Display window",image);//Show our image inside it 
	waitKey(0);//wait for a keystroke in the window
	return 0;
}
