#include "stdio.h"
#include <cv.h>
#include <highgui.h>


int main(int argc, int argv[]){
	IplImage* img;
	IplImage* full;
	//CvCapture *capture;						//	カメラキャプチャ用の構造体
	//IplImage *frameImage;					//	キャプチャ画像用IplImage

	cvNamedWindow("capture");
	HWND windowHandle = ::FindWindowA(NULL, "capture");
	// ディスプレイサイズを取得
	int mainDisplayWidth = GetSystemMetrics(SM_CXSCREEN);
	int mainDisplayHeight = GetSystemMetrics(SM_CYSCREEN);

	//	カメラを初期化する
	/*
	if ( ( capture = cvCreateCameraCapture( -1 ) ) == NULL ) {
		//	カメラが見つからなかった場合
		printf( "カメラが見つかりません\n" );
		return -1;
	}
	*/

	if (NULL != windowHandle) {

	// ウィンドウスタイル変更（メニューバーなし、最前面）
	SetWindowLongPtr(windowHandle,  GWL_STYLE, WS_POPUP);
	SetWindowLongPtr(windowHandle, GWL_EXSTYLE, WS_EX_TOPMOST);

	// 最大化する
	ShowWindow(windowHandle, SW_MAXIMIZE);
	cvSetWindowProperty("capture", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN );

	// クライアント領域をディスプレイに合わせる
	SetWindowPos(windowHandle, NULL,
		0, 0, mainDisplayWidth, mainDisplayWidth,
		SWP_FRAMECHANGED | SWP_NOZORDER);
	}

	img=cvLoadImage("output/source.pbm");
	if(img==NULL){
		printf("ファイルが読み込めません\n");
		cvWaitKey(0);
		return -1;
	}
	full=cvCreateImage(cvSize(mainDisplayWidth,mainDisplayHeight), IPL_DEPTH_8U, 3);
	cvResize(img, full, CV_INTER_LINEAR);
	cvShowImage("capture",full);
	//cvWaitKey(0);
	//frameImage = cvQueryFrame( capture );
	//cvSaveImage("output/source.jpg",frameImage);

	cvWaitKey(0);
	img=cvLoadImage("output/1-1.pbm");
	if(img==NULL){
		printf("ファイルが読み込めません\n");
		cvWaitKey(0);
		return -1;
	}
	//full=cvCreateImage(cvSize(mainDisplayWidth,mainDisplayHeight), IPL_DEPTH_8U, 3);
	cvResize(img, full, CV_INTER_LINEAR);
	cvShowImage("capture",full);
	//cvWaitKey(0);
	//frameImage = cvQueryFrame( capture );
	//cvSaveImage("output/1-1.jpg",frameImage);

	cvWaitKey(0);
	img=cvLoadImage("output/1-2.pbm");
	if(img==NULL){
		printf("ファイルが読み込めません\n");
		cvWaitKey(0);
		return -1;
	}
	//full=cvCreateImage(cvSize(mainDisplayWidth,mainDisplayHeight), IPL_DEPTH_8U, 3);
	cvResize(img, full, CV_INTER_LINEAR);
	cvShowImage("capture",full);
	//cvWaitKey(0);
	//frameImage = cvQueryFrame( capture );
	//cvSaveImage("output/1-2.jpg",frameImage);

	cvWaitKey(0);
	img=cvLoadImage("output/1-3.pbm");
	if(img==NULL){
		printf("ファイルが読み込めません\n");
		cvWaitKey(0);
		return -1;
	}
	//full=cvCreateImage(cvSize(mainDisplayWidth,mainDisplayHeight), IPL_DEPTH_8U, 3);
	cvResize(img, full, CV_INTER_LINEAR);
	cvShowImage("capture",full);
	//cvWaitKey(0);
	//frameImage = cvQueryFrame( capture );
	//cvSaveImage("output/1-3.jpg",frameImage);

	cvWaitKey(0);
	img=cvLoadImage("output/1-4.pbm");
	if(img==NULL){
		printf("ファイルが読み込めません\n");
		cvWaitKey(0);
		return -1;
	}
	//full=cvCreateImage(cvSize(mainDisplayWidth,mainDisplayHeight), IPL_DEPTH_8U, 3);
	cvResize(img, full, CV_INTER_LINEAR);
	cvShowImage("capture",full);
	//cvWaitKey(0);
	//frameImage = cvQueryFrame( capture );
	//cvSaveImage("output/1-4.jpg",frameImage);

	cvWaitKey(0);
	img=cvLoadImage("output/2-1.pbm");
	if(img==NULL){
		printf("ファイルが読み込めません\n");
		cvWaitKey(10);
		return -1;
	}
	//full=cvCreateImage(cvSize(mainDisplayWidth,mainDisplayHeight), IPL_DEPTH_8U, 3);
	cvResize(img, full, CV_INTER_LINEAR);
	cvShowImage("capture",full);
	//cvWaitKey(0);
	//frameImage = cvQueryFrame( capture );
	//cvSaveImage("output/2-1.jpg",frameImage);

	cvWaitKey(0);
	img=cvLoadImage("output/2-2.pbm");
	if(img==NULL){
		printf("ファイルが読み込めません\n");
		cvWaitKey(10);
		return -1;
	}
	//full=cvCreateImage(cvSize(mainDisplayWidth,mainDisplayHeight), IPL_DEPTH_8U, 3);
	cvResize(img, full, CV_INTER_LINEAR);
	cvShowImage("capture",full);
	//cvWaitKey(0);
	//frameImage = cvQueryFrame( capture );
	//cvSaveImage("output/2-2.jpg",frameImage);

	cvWaitKey(0);
	img=cvLoadImage("output/2-3.pbm");
	if(img==NULL){
		printf("ファイルが読み込めません\n");
		cvWaitKey(10);
		return -1;
	}
	//full=cvCreateImage(cvSize(mainDisplayWidth,mainDisplayHeight), IPL_DEPTH_8U, 3);
	cvResize(img, full, CV_INTER_LINEAR);
	cvShowImage("capture",full);
	//cvWaitKey(0);
	//frameImage = cvQueryFrame( capture );
	//cvSaveImage("output/2-3.jpg",frameImage);

	cvWaitKey(0);
	img=cvLoadImage("output/2-4.pbm");
	if(img==NULL){
		printf("ファイルが読み込めません\n");
		cvWaitKey(10);
		return -1;
	}
	//full=cvCreateImage(cvSize(mainDisplayWidth,mainDisplayHeight), IPL_DEPTH_8U, 3);
	cvResize(img, full, CV_INTER_LINEAR);
	cvShowImage("capture",full);
	//cvWaitKey(0);
	//frameImage = cvQueryFrame( capture );
	//cvSaveImage("output/2-4.jpg",frameImage);

	cvWaitKey(0);
	cvDestroyWindow("capture");

	//cvReleaseCapture( &capture );
	cvReleaseImage(&img);
	cvReleaseImage(&full);
	return 0;
}