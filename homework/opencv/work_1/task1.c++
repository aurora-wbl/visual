#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("/home/wbl/share_dir/1.jpg", 1);
    if (image.empty())
    {
        cout << "image cannot found!" << endl;
        return -1;
    }
    // 原始图片展示
    namedWindow("origin", WINDOW_NORMAL);
    imshow("origin", image);

    // 新建一个与src大小、类型相同的空白图像
    Mat dst = Mat(image.size(), image.type());

    int height = image.rows;
    int width = image.cols;

    // 把每个像素的rgb值都改为(r+g+b)/3
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int blue = image.at<Vec3b>(row, col)[0];
            int green = image.at<Vec3b>(row, col)[1];
            int red = image.at<Vec3b>(row, col)[2];
            int aver = (blue + green + red) / 3;
            dst.at<Vec3b>(row,col)[0] = dst.at<Vec3b>(row,col)[1] = dst.at<Vec3b>(row,col)[2] = aver;
        }
    }

    // 目标图片展示
    namedWindow("destination", WINDOW_NORMAL);
    imshow("destination", dst);

    waitKey(0);
    return 0;
}