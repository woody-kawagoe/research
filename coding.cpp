#include <stdio.h>
#include <math.h>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

#define THRESHOLD_MAX_VALUE		255	//	2�l���̍ۂɎg�p����ő�l
#define THRESHOLD_BIAS_VALUE	128 //�@2�l���̍ۂɎg�p����o�C�A�X(128)
#define IMG_WIDTH  2560
#define IMG_HEIGHT 1920

#define SIGN_WIDTH  16
#define SIGN_HEIGHT 16

#define CUT(x) ((x<0)?0:x)
#define REAL(x) ((x<0)?256+x:x)

typedef struct{
	long value;
	int length;
} signMat;

//��l��
IplImage binarization( IplImage *sourceImage);
//��ԕ�����
void coding( IplImage *Image ,CvMat *codeMat ,int code);

int main( int argc, char **argv ) {
	int x,y;
	int code=1;
	double p[3];
	int s[3],min=255;
	char windowNameCode[] = "Code";	//	�i�q��\������E�B���h�E�̖��O
	signMat signMat[SIGN_HEIGHT][SIGN_WIDTH*3]; //�@���e�ʂ̐F���

	//	�摜��ǂݍ���
	//����F
	IplImage *sourceImage = cvLoadImage( "input/source.jpg", CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR );
	//�␳�����Ƃ��̎B�e��
	IplImage *resultImage = cvLoadImage( "input/result.jpg", CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR );
	//�p�^�[�����e
	IplImage *img11 = cvLoadImage( "input/1-1.jpg", CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR );
	IplImage *img12 = cvLoadImage( "input/1-2.jpg", CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR );
	IplImage *img13 = cvLoadImage( "input/1-3.jpg", CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR );
	IplImage *img14 = cvLoadImage( "input/1-4.jpg", CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR );
	IplImage *img21 = cvLoadImage( "input/2-1.jpg", CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR );
	IplImage *img22 = cvLoadImage( "input/2-2.jpg", CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR );
	IplImage *img23 = cvLoadImage( "input/2-3.jpg", CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR );
	IplImage *img24 = cvLoadImage( "input/2-4.jpg", CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR );
	//�␳�������f��
	IplImage *showImage = cvLoadImage( "show.jpg", CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR );
	//�ő�\���p
	IplImage* full;
	FILE *fout;

	if((fout=fopen("result.csv","w"))==NULL){
		fprintf(stderr, "�t�@�C���̃I�[�v���Ɏ��s���܂���\n");
		return EXIT_FAILURE;
	}

	cvNamedWindow("capture");
	HWND windowHandle = ::FindWindowA(NULL, "capture");
	// �f�B�X�v���C�T�C�Y���擾
	int mainDisplayWidth = GetSystemMetrics(SM_CXSCREEN);
	int mainDisplayHeight = GetSystemMetrics(SM_CYSCREEN);

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
	full=cvCreateImage(cvSize(mainDisplayWidth,mainDisplayHeight), IPL_DEPTH_8U, 3);


	if ( sourceImage == NULL ) {
		//	�摜��������Ȃ������ꍇ
		printf( "�摜��������܂���\n" );
		return -1;
	}
	if ( resultImage == NULL ) {
		//	�摜��������Ȃ������ꍇ
		printf( "�摜��������܂���\n" );
		return -1;
	}
	if ( img11 == NULL ) {
		//	�摜��������Ȃ������ꍇ
		printf( "�摜��������܂���\n" );
		return -1;
	}
	if ( img12 == NULL ) {
		//	�摜��������Ȃ������ꍇ
		printf( "�摜��������܂���\n" );
		return -1;
	}
	if ( img13 == NULL ) {
		//	�摜��������Ȃ������ꍇ
		printf( "�摜��������܂���\n" );
		return -1;
	}
	if ( img14 == NULL ) {
		//	�摜��������Ȃ������ꍇ
		printf( "�摜��������܂���\n" );
		return -1;
	}
	if ( img21 == NULL ) {
		//	�摜��������Ȃ������ꍇ
		printf( "�摜��������܂���\n" );
		return -1;
	}
	if ( img22 == NULL ) {
		//	�摜��������Ȃ������ꍇ
		printf( "�摜��������܂���\n" );
		return -1;
	}
	if ( img23 == NULL ) {
		//	�摜��������Ȃ������ꍇ
		printf( "�摜��������܂���\n" );
		return -1;
	}
	if ( img24 == NULL ) {
		//	�摜��������Ȃ������ꍇ
		printf( "�摜��������܂���\n" );
		return -1;
	}
	if ( showImage == NULL ) {
		//	�摜��������Ȃ������ꍇ
		printf( "�摜��������܂���\n" );
		return -1;
	}

	CvMat *codeMat=cvCreateMat(IMG_HEIGHT,IMG_WIDTH,CV_32F);				//�����s��
	IplImage *img=cvCloneImage(sourceImage);		//���F���e�摜
	IplImage *showImage=cvCreateImage(cvSize(IMG_WIDTH,IMG_HEIGHT),IPL_DEPTH_8U,3);	//���z�摜
	IplImage *codeImage=cvCreateImage(cvSize(IMG_WIDTH,IMG_HEIGHT),IPL_DEPTH_8U,3);	//���e�ʉ摜
	IplImage *colorImage=cvCreateImage(cvSize(IMG_WIDTH,IMG_HEIGHT),IPL_DEPTH_8U,3);	//�␳�f��

	//cvResize(show,showImage,CV_INTER_NN);
	
	for (y = 0; y < codeImage->height; y++){
		for (x = 0; x < codeImage->width; x++) {
			cvmSet(codeMat,y,x,0);
		}
	}
	
	for (y = 0; y < SIGN_HEIGHT; y++) {
		 for (x = 0; x < SIGN_WIDTH*3; x++){
		 	signMat[y][x].value=0;
			signMat[y][x].length=0;
		}
	}

	//��l��
	*img=binarization(img);
	cvSaveImage("img.jpg",img);
	*img11=binarization(img11);
	cvSaveImage("img11.jpg",img11);
	*img12=binarization(img12);
	cvSaveImage("img12.jpg",img12);
	*img13=binarization(img13);
	cvSaveImage("img13.jpg",img13);
	*img14=binarization(img14);
	cvSaveImage("img14.jpg",img14);
	*img21=binarization(img21);
	cvSaveImage("img21.jpg",img21);
	*img22=binarization(img22);
	cvSaveImage("img22.jpg",img22);
	*img23=binarization(img23);
	cvSaveImage("img23.jpg",img23);
	*img24=binarization(img24);
	cvSaveImage("img24.jpg",img24);

	//������
	coding(img,codeMat,code);
	code*=2;
	coding(img14,codeMat,code);
	code*=2;
	coding(img13,codeMat,code);
	code*=2;
	coding(img12,codeMat,code);
	code*=2;
	coding(img11,codeMat,code);
	code*=2;
	coding(img24,codeMat,code);
	code*=2;
	coding(img23,codeMat,code);
	code*=2;
	coding(img22,codeMat,code);
	code*=2;
	coding(img21,codeMat,code);

	//���������̃p�����[�^�̑��a�Ɛ��̌v��
	for (y = 0; y < img->height; y++) {
		 for (x = 0; x < img->width; x++){
		 	if((int)(cvmGet(codeMat,y,x))%2==1){
		 		signMat[(int)((int)(cvmGet(codeMat,y,x))/2/SIGN_HEIGHT)][((int)((int)(cvmGet(codeMat,y,x))/2%SIGN_WIDTH))*3].value
		 		+=REAL(resultImage->imageData[resultImage->widthStep * y + x*3]);
		 		signMat[(int)((int)(cvmGet(codeMat,y,x))/2/SIGN_HEIGHT)][((int)((int)(cvmGet(codeMat,y,x))/2%SIGN_WIDTH))*3+1].value
		 		+=REAL(resultImage->imageData[resultImage->widthStep * y + x*3+1]);
		 		signMat[(int)((int)(cvmGet(codeMat,y,x))/2/SIGN_HEIGHT)][((int)((int)(cvmGet(codeMat,y,x))/2%SIGN_WIDTH))*3+2].value
		 		+=REAL(resultImage->imageData[resultImage->widthStep * y + x*3+2]);
		 		signMat[(int)(cvmGet(codeMat,y,x))/2/SIGN_HEIGHT][((int)(cvmGet(codeMat,y,x))/2%SIGN_WIDTH)*3].length++;
		 		signMat[(int)(cvmGet(codeMat,y,x))/2/SIGN_HEIGHT][((int)(cvmGet(codeMat,y,x))/2%SIGN_WIDTH)*3+1].length++;
		 		signMat[(int)(cvmGet(codeMat,y,x))/2/SIGN_HEIGHT][((int)(cvmGet(codeMat,y,x))/2%SIGN_WIDTH)*3+2].length++;
		 	}
		}
	}
	//���������̃p�����[�^�̕���
	for (y = 0; y < SIGN_HEIGHT; y++) {
		 for (x = 0; x < SIGN_WIDTH*3; x++){
		 	if(signMat[y][x].length!=0)signMat[y][x].value/=signMat[y][x].length;
		 	fprintf(fout,"%d\t", signMat[y][x].value);
		 	if((x%3)==2)fprintf(fout,"%d\t",signMat[y][x].length);
		}
		fprintf(fout,"\n");
	}
	//���e�ʃC���[�W�摜����
	for (y = 0; y < codeImage->height; y++) {
		for (x = 0; x < codeImage->width; x++){
			{
				codeImage->imageData[codeImage->widthStep * y + x * 3]
				=cvRound(signMat[(int)(y/(codeImage->height/SIGN_HEIGHT))][(int)(x/(codeImage->width/SIGN_WIDTH))*3].value);
				codeImage->imageData[codeImage->widthStep * y + x * 3+1]
				=cvRound(signMat[(int)(y/(codeImage->height/SIGN_HEIGHT))][(int)(x/(codeImage->width/SIGN_WIDTH))*3+1].value);
				codeImage->imageData[codeImage->widthStep * y + x * 3+2]
				=cvRound(signMat[(int)(y/(codeImage->height/SIGN_HEIGHT))][(int)(x/(codeImage->width/SIGN_WIDTH))*3+2].value);
			}
		}
	}

	//�摜��ۑ�����
	cvSaveImage("code.jpg",codeImage);
	
	//�ŏ��E���σp�����[�^���o
	for (y = 0; y < (colorImage->height); y++) {
		for (x = 0; x < colorImage->width; x++){
			{
				p[0]=REAL(codeImage->imageData[codeImage->widthStep * y + x * 3]);
				p[1]=REAL(codeImage->imageData[codeImage->widthStep * y + x * 3+1]);
				p[2]=REAL(codeImage->imageData[codeImage->widthStep * y + x * 3+2]);

				if((min>p[0])&&(p[0]>0))min=p[0];
				if((min>p[1])&&(p[1]>0))min=p[1];
				if((min>p[2])&&(p[2]>0))min=p[2];
				if(min==0)printf("%d,%d\n",x,y );
			}
		}
	}
	
	//�F�␳
	for (y = 0; y < colorImage->height; y++) {
		for (x = 0; x < colorImage->width; x++){
			{
				p[0]=REAL(codeImage->imageData[codeImage->widthStep * y + x * 3]);
				p[1]=REAL(codeImage->imageData[codeImage->widthStep * y + x * 3+1]);
				p[2]=REAL(codeImage->imageData[codeImage->widthStep * y + x * 3+2]);
				//�摜�␳
				s[0]=min/p[0]*REAL(showImage->imageData[showImage->widthStep * y + x * 3]);
				s[1]=min/p[1]*REAL(showImage->imageData[showImage->widthStep * y + x * 3+1]);
				s[2]=min/p[2]*REAL(showImage->imageData[showImage->widthStep * y + x * 3+2]);
				//���␳
				/*
				s[0]=min/p[0]*255;
				s[1]=min/p[1]*255;
				s[2]=min/p[2]*255;
				*/

				if(s[0]>255) printf("%d\n", s[0]);

				colorImage->imageData[colorImage->widthStep * y + x * 3]=cvRound(s[0]);
				colorImage->imageData[colorImage->widthStep * y + x * 3+1]=cvRound(s[1]);
				colorImage->imageData[colorImage->widthStep * y + x * 3+2]=cvRound(s[2]);
			}
		}
	}
	//�摜��ۑ�����
	cvSaveImage("color.jpg",colorImage);
	
	//	�摜��\������
	cvResize(colorImage, full, CV_INTER_LINEAR);
	cvShowImage("capture",full);
	
	//	�L�[���͂�҂�
    cvWaitKey( 0 );

	//	�E�B���h�E��j������
	cvDestroyWindow( "windowNameCode" );

	//	���������������
	cvReleaseImage( &img );
	cvReleaseImage( &img11 );
	cvReleaseImage( &img12 );
	cvReleaseImage( &img13 );
	cvReleaseImage( &img14 );
	cvReleaseImage( &img21 );
	cvReleaseImage( &img22 );
	cvReleaseImage( &img23 );
	cvReleaseImage( &img24 );
	cvReleaseImage( &sourceImage );
	cvReleaseImage( &resultImage );
	cvReleaseImage( &showImage );
	cvReleaseImage( &codeImage );

    return 0;
}

IplImage binarization( IplImage *sourceImage){
	IplImage *grayImage = cvCreateImage( cvGetSize(sourceImage), IPL_DEPTH_8U, 1 );
	IplImage *binaryImage = cvCreateImage( cvGetSize(sourceImage), IPL_DEPTH_8U, 1 );
	//	BGR����O���[�X�P�[���ɕϊ�����
	cvCvtColor( sourceImage, grayImage, CV_BGR2GRAY );
	//	�O���[�X�P�[������2�l�ɕϊ�����
	cvThreshold( grayImage, binaryImage, THRESHOLD_BIAS_VALUE, THRESHOLD_MAX_VALUE, CV_THRESH_BINARY );

	return *binaryImage;
}

void coding( IplImage *Image ,CvMat *codeMat ,int code){
	int x,y;
	for (y = 0; y < Image->height; y++){
		 for (x = 0; x < Image->width; x++) {
			if(Image->imageData[Image->widthStep * y + x]!=0){ 
				cvmSet(codeMat,y,x,(cvmGet(codeMat,y,x)+code));
			}
		}
	}
};