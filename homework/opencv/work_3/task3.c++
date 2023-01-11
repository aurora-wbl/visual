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

    // 深拷贝
    Mat deepMat = Mat(srcMat.size(), srcMat.type());
    srcMat.copyTo(deepMat);
    // 浅拷贝
    Mat swallowMat = srcMat;

    int height = srcMat.rows;
    int width = srcMat.cols;

    uchar threshold = 80;

    // 把每个像素的rgb值都改为(r+g+b)/3

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int blue = srcMat.at<Vec3b>(row, col)[0];
            int green = srcMat.at<Vec3b>(row, col)[1];
            int red = srcMat.at<Vec3b>(row, col)[2];
            int aver = (blue + green + red) / 3;
            if (aver > threshold)
                aver = 255;
            else
                aver = 0;

            srcMat.at<Vec3b>(row, col)[0] = srcMat.at<Vec3b>(row, col)[1] = srcMat.at<Vec3b>(row, col)[2] = aver;
        }
    }
        // srcMat展示
        namedWindow("srcMat", WINDOW_NORMAL);
        imshow("srcMat", srcMat);
        // deepMat展示
        namedWindow("deepMat", WINDOW_NORMAL);
        imshow("deepMat", deepMat);
        // swallowMat展示
        namedWindow("swallowMat", WINDOW_NORMAL);
        imshow("swallowMat", swallowMat);

        waitKey(0);
    
    return 0;
}