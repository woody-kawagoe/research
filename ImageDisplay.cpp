#include "stdio.h"
#include <cv.h>
#include <highgui.h>


int main(int argc, int argv[]){
	IplImage* img;
	IplImage* full;
	//CvCapture *capture;						//	�J�����L���v�`���p�̍\����
	//IplImage *frameImage;					//	�L���v�`���摜�pIplImage

	cvNamedWindow("capture");
	HWND windowHandle = ::FindWindowA(NULL, "capture");
	// �f�B�X�v���C�T�C�Y���擾
	int mainDisplayWidth = GetSystemMetrics(SM_CXSCREEN);
	int mainDisplayHeight = GetSystemMetrics(SM_CYSCREEN);

	//	�J����������������
	/*
	if ( ( capture = cvCreateCameraCapture( -1 ) ) == NULL ) {
		//	�J������������Ȃ������ꍇ
		printf( "�J������������܂���\n" );
		return -1;
	}
	*/

	if (NULL != windowHandle) {

	// �E�B���h�E�X�^�C���ύX�i���j���[�o�[�Ȃ��A�őO�ʁj
	SetWindowLongPtr(windowHandle,  GWL_STYLE, WS_POPUP);
	SetWindowLongPtr(windowHandle, GWL_EXSTYLE, WS_EX_TOPMOST);

	// �ő剻����
	ShowWindow(windowHandle, SW_MAXIMIZE);
	cvSetWindowProperty("capture", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN );

	// �N���C�A���g�̈���f�B�X�v���C�ɍ��킹��
	SetWindowPos(windowHandle, NULL,
		0, 0, mainDisplayWidth, mainDisplayWidth,
		SWP_FRAMECHANGED | SWP_NOZORDER);
	}

	img=cvLoadImage("output/source.pbm");
	if(img==NULL){
		printf("�t�@�C�����ǂݍ��߂܂���\n");
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
		printf("�t�@�C�����ǂݍ��߂܂���\n");
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
		printf("�t�@�C�����ǂݍ��߂܂���\n");
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
		printf("�t�@�C�����ǂݍ��߂܂���\n");
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
		printf("�t�@�C�����ǂݍ��߂܂���\n");
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
		printf("�t�@�C�����ǂݍ��߂܂���\n");
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
		printf("�t�@�C�����ǂݍ��߂܂���\n");
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
		printf("�t�@�C�����ǂݍ��߂܂���\n");
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
		printf("�t�@�C�����ǂݍ��߂܂���\n");
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