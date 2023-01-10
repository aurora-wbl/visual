#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


int main()
{
    Mat srcMat = imread("/home/wbl/share_dir/1.jpg", 1);
    if (srcMat.empty())
    {
        cout << "srcMat cannot found!" << endl;
        return -1;
    }
    //Mat dst[3];
    vector<Mat> dst;
    split(srcMat,dst);

    // srcMatչʾ
    namedWindow("srcMat", WINDOW_NORMAL);
    imshow("srcMat", srcMat);
    // Blueչʾ
    namedWindow("Blue", WINDOW_NORMAL);
    imshow("Blue", dst[0]);
    // Greenչʾ
    namedWindow("Green", WINDOW_NORMAL);
    imshow("Green", dst[1]);
    // Redչʾ
    namedWindow("Red", WINDOW_NORMAL);
    imshow("Red", dst[2]);

    waitKey(0);

    return 0;
}