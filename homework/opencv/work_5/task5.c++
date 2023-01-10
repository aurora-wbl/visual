#include <opencv2/opencv.hpp>
#include <cstdio>
using namespace cv;
using namespace std;

int main()
{
    // ����ͼƬ
    Mat srcMat = imread("/home/wbl/share_dir/1.jpg", 1);
    if (srcMat.empty())
    {
        cout << "srcMat cannot found!" << endl;
        return -1;
    }

    cout << "srcMat open success!" << endl;
    // ���ͼƬ
    namedWindow("srcMat",WINDOW_NORMAL);
    imshow("srcMat",srcMat);
    
    // ������ͷ
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
        cam.read(img); // ��֡
        if (img.empty())
            break;
        imshow("cam", img); // ��ʾÿһ֡

        if (waitKey(5) == 'q')
            break; // ����qֹͣ
    }



    return 0;
}