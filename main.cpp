
#include <iostream>
#include <sstream>
#include "C:\opencv-4.5.2\build\install\include\opencv2\imgcodecs.hpp"
#include "C:\opencv-4.5.2\build\install\include\opencv2\imgproc.hpp"
#include "C:\opencv-4.5.2\build\install\include\opencv2\videoio.hpp"
#include "C:\opencv-4.5.2\build\install\include\opencv2\highgui.hpp"
#include "C:\opencv-4.5.2\build\install\include\opencv2\video.hpp"
#include <conio.h>
#include <stdlib.h>
#include <chrono>
#include "D:\OOP\ImageProcessing\ImageProcessing\ceSerial.h"
#include <ctime>


using namespace cv;
using namespace std;
using namespace ce;
const char* params
    = "{ help h         |           | Print usage }"
      "{ input          | vtest.avi | Path to a video or a sequence of image }"
      "{ algo           | MOG2      | Background subtraction method (KNN, MOG2) }";

Rect Crop_jalur1(210,0,100,280);
Rect Crop_jalur2(320,220,250,160);
Rect Crop_jalur3(0,220,200,160);

Mat frame,framebg, fgMask;

//SimpleSerial serial("\\\.\\COM7",9600);

int waktu_jalur[3];
int waktu_sebelumnya[3];
#ifdef ceWINDOWS
	ceSerial com("\\\\.\\COM7",115200,8,'N',1); // Windows
#else
	ceSerial com("/dev/ttyS0",115200,8,'N',1); // Linux
#endif

char waktu[3]="";

void WaktuJalur(Mat &jalur_1,Mat &jalur_2,Mat &jalur_3,int waktu_total=60){
    int total_pixel = countNonZero(jalur_1)+countNonZero(jalur_2)+countNonZero(jalur_3);
    //rasio = int (waktu_total/total_pixel);
    //rasio = waktu_total/(countNonZero(jalur_1)+countNonZero(jalur_2)+countNonZero(jalur_3));
    waktu_jalur[0] = countNonZero(jalur_1)*waktu_total/(total_pixel+0.1);//total_pixel);
    waktu_jalur[1] = countNonZero(jalur_2)*waktu_total/(total_pixel+0.1);//total_pixel);
    waktu_jalur[2] = countNonZero(jalur_3)*waktu_total/(total_pixel+0.1);//total_pixel);
    if(waktu_jalur[0]<10){
        waktu_jalur[0]=10;
    }
    if(waktu_jalur[1]<10){
        waktu_jalur[1]=10;
    }
    if(waktu_jalur[2] <10){
        waktu_jalur[2]=10;
    }
}



int main(int argc, char* argv[])
{
    printf("Opening port %s.\n",com.GetPort().c_str());
	if (com.Open() == 0) {
		printf("OK.\n");
	}
	else {
		printf("Error.\n");
		return 1;
	}
    bool successFlag;
    bool udahterkirim=false;
    CommandLineParser parser(argc, argv, params);
    Ptr<BackgroundSubtractor> pBackSub;
    if (parser.get<String>("algo") == "MOG2")
        pBackSub = createBackgroundSubtractorMOG2(500,1000,false);
    else
        pBackSub = createBackgroundSubtractorKNN();
    VideoCapture capture(0,CAP_ANY);
    if (!capture.isOpened()){
        //error in opening the video input
        cout << "Kamera tidak bisa terbuka " << endl;
        return 0;
    }
    std::clock_t start;
    double duration;
    ulang:
    successFlag=false;
    destroyWindow("Mask");
    waktu_jalur[0]=20;
    waktu_jalur[1]=20;
    waktu_jalur[2]=20;
    cout<<"Jika sudah siap menggunakan background tekan apa saja di keyboard"<<endl;
    while (!kbhit()) {
        if(!successFlag){
            for(int i=0;i<=2;i++){
                waktu[i]=char(waktu_jalur[i]);
            }
            successFlag=com.Write(waktu);
            cout<<"Kirim data"<<endl;
            start = clock();
            cout<<"Waktu jalur 1 : "<<waktu_jalur[0]<<endl<<"Waktu jalur 2 : "<<waktu_jalur[1]<<endl<<"Waktu jalur 3 : "<<waktu_jalur[2]<<endl<<endl;
        }
        else{
            duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
            if(duration>waktu_jalur[0]+waktu_jalur[1]+waktu_jalur[2]){
                successFlag=false;
            }
        }
        capture >> frame;
        //cout<<capture.get(CAP_PROP_FRAME_WIDTH)<<endl<<capture.get(CAP_PROP_FRAME_HEIGHT);
        imshow("Frame",frame);
        Mat jalur1(frame,Crop_jalur1);
        Mat jalur2(frame,Crop_jalur2);
        Mat jalur3(frame,Crop_jalur3);
        imshow("Jalur 1",jalur1);
        imshow("Jalur 2",jalur2);
        imshow("Jalur 3",jalur3);
        int keyboard = waitKey(30);
        if (keyboard == 'q' || keyboard == 27){
            break;
        }
    }
    getch();
    successFlag=false;
    cout<<"Update background tekan Y/y"<<endl;
    framebg=frame;
    pBackSub->apply(framebg,fgMask,1);
    while (!kbhit()) {
        capture >> frame;
        if (frame.empty())
            break;
        //update the background model
        pBackSub->apply(framebg,fgMask,0);
        String pixelputih = std::to_string(countNonZero(fgMask));
        putText(frame, pixelputih, cv::Point(550, 50),FONT_HERSHEY_SIMPLEX, 0.5 , cv::Scalar(255,255,255));
        Mat jalur1(fgMask,Crop_jalur1);
        Mat jalur2(fgMask,Crop_jalur2);
        Mat jalur3(fgMask,Crop_jalur3);
        WaktuJalur(jalur1,jalur2,jalur3);
        imshow("Mask",fgMask);
        imshow("Frame",frame);
        imshow("Jalur 1",jalur1);
        imshow("Jalur 2",jalur2);
        imshow("Jalur 3",jalur3);
        //WaktuJalur(jalur1,jalur2,jalur3);
        if(!successFlag){
            for(int i=0;i<=2;i++){
                waktu[i]=char(waktu_jalur[i]);
                waktu_sebelumnya[i]=waktu_jalur[i];
            }
            successFlag=com.Write(waktu);
            cout<<"Kirim data"<<endl;
            start = clock();
            cout<<"Waktu jalur 1 : "<<waktu_jalur[0]<<endl<<"Waktu jalur 2 : "<<waktu_jalur[1]<<endl<<"Waktu jalur 3 : "<<waktu_jalur[2]<<endl<<endl;
        }
        else{
            duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
            if(duration>waktu_sebelumnya[0]+waktu_sebelumnya[1]+waktu_sebelumnya[2]){
                successFlag=false;
            }
        }
        //cout<<"Waktu jalur 1 : "<<waktu_jalur[0]<<endl<<"Waktu jalur 2 : "<<waktu_jalur[1]<<endl<<"Waktu jalur 3 : "<<waktu_jalur[2]<<endl<<endl;
        int keyboard = waitKey(30);
        if (keyboard == 'q' || keyboard == 27){
            break;
            }
        }
    char update = getch();
    if (update == 'Y'||update == 'y'){
        goto ulang;
    }
    system("pause");
    return 0;
}

/*void WaktuJalur(int waktu_total=60,Mat &jalur_1,Mat &jalur_2,Mat &jalur_3){
    float rasio = (countNonZero(jalur_1)+countNonZero(jalur_2)+countNonZero(jalur_3))/waktu_total;
    waktu_jalur1 = int(countNonZero(jalur_1)*rasio);
}*/
