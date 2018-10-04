## Mat 

Mat A,C;    //create just the header parts 

A=imread(argv[1],IMREAD_COLOR);    //allocate matrix 

Mat B(A);      //Use the copy constructor 

C=A;           //Assigment operator 

**Be careful** The copy operators only copy the headers and the pointer to the large matrix,not the data itself.

### Create the subsection 

Mat D(A,Rect(10,10,100,100);  //using a rectangle 

Mat E=A(Range::all(),Range(1,3));

### copy the matrix itself 

cv::Mat::clone()

cv::Mat::copyTo()

Mat F=A.clone();

Mat G;
A.copyTo(G);


