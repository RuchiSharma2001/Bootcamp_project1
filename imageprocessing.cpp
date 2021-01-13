#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat rotate(Mat src, double angle)
{
    Mat dst;
    Point2f pt(src.cols/2., src.rows/2.);    
    Mat r = getRotationMatrix2D(pt, angle, 1.0);
    warpAffine(src, dst, r, Size(src.cols, src.rows));
    return dst;
}

int main()
{
    Mat src = imread("1.jpg");
    double ang;
    Mat dst;
    cout << "Enter the angle of Rotation: ";
    cin >> ang;
    dst = rotate(src, ang);

    imshow("src", src);
    imshow("dst", dst);
    waitKey(0);
    return 0;
}