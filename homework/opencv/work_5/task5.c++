#include <opencv2/opencv.hpp>
#include <cstdio>
using namespace cv;
using namespace std;

int main()
{
    // 输入图片
    Mat srcMat = imread("/home/wbl/share_dir/1.jpg", 1);
    if (srcMat.empty())
    {
        cout << "srcMat cannot found!" << endl;
        return -1;
    }

    cout << "srcMat open success!" << endl;
    // 输出图片
    namedWindow("srcMat",WINDOW_NORMAL);
    imshow("srcMat",srcMat);
    
    // 打开摄像头
    VideoCapture cam(0);
    if (!cam.isOpened())
    {
        cout << "cam open failed!" << endl;
        getchar();
        return -1;
    }

    cout << "cam open success!" << endl;

    int fps = cam.get(CAP_PROP_FPS);
    cout << "FPS = " << fps << endl;

    namedWindow("cam");
    Mat img;

    for (;;)
    {
        cam.read(img); // 读帧
        if (img.empty())
            break;
        imshow("cam", img); // 显示每一帧

        if (waitKey(5) == 'q')
            break; // 键入q停止
    }



    return 0;
}