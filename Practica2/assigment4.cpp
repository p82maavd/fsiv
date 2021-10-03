#include <opencv2/core/core.hpp> //core routines
#include <opencv2/highgui/highgui.hpp>//imread,imshow,namedWindow,waitKey
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <iostream>
using namespace std;


void applyKernel(cv::Mat &in, cv::Mat &out, cv::Mat &kernel){
	float media=0.0;
	uchar *ptr;
	float *ptr2;
	
	for( int r=0;r<in.rows;r++){
		uchar *ptr3=out.ptr<uchar>(r);
		for( int c=0;c<in.cols;c++){
			
			for(int i=kernel.cols/2*(-1); i<=kernel.cols/2; i++){
				ptr=in.ptr<uchar>(r+i);
				ptr2=kernel.ptr<float>(i+kernel.cols/2);
				for(int j=kernel.cols/2*(-1); j<=kernel.cols/2; j++){
						
					if(r+i>=0 && r+i<=in.rows && c+j>=0 && c+j<=in.cols ){
						
						media+=(ptr[c+j]*ptr2[j+kernel.cols/2])/(kernel.cols*kernel.cols);
						
					}
				}
			}
			ptr3[c]=media;
			media=0.0;
				
		}
	}

}
int main(int argc,char **argv){
	try{
	
		if(argc!=2) {cerr<<"Usage:image"<<endl;return 0;} 

		cv::Mat image, xImage, yImage, outImage;
		
		
		float data[9]= {-1.0,0.0,1.0,-2.0,0.0,2.0,-1.0,0.0,1.0};
		cv::Mat kernelx(3, 3, CV_32FC1,data);
		
		float data2[9]= {-1.0,-2.0,-1.0,0.0,0.0,0.0,1.0,2.0,1.0};
		cv::Mat kernely(3, 3, CV_32FC1,data2);

		//Load the image 
		image=cv::imread(argv[1]);
		//Change image to grayscale 
		cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
		image.copyTo(xImage);
		image.copyTo(yImage);
		image.copyTo(outImage);

		applyKernel(image,xImage,kernelx);
		
		applyKernel(image,yImage,kernely);
		
		for( int r=0;r<xImage.rows;r++){
		
			uchar *ptr2=xImage.ptr<uchar>(r);
			uchar *ptr3=yImage.ptr<uchar>(r);
			uchar *ptr4=outImage.ptr<uchar>(r);
			for( int c=0;c<xImage.cols;c++){
				
				ptr4[c]=sqrt(pow(ptr2[c],2)+pow(ptr3[c],2));
					
			}
		}
		
		cv::imshow("Input Image",image);
		
		cv::imshow("Output Image",outImage);
		char c=0;
		while(c!=27)  //waits until ESC pressed
			c=cv::waitKey(0);

	}catch(std::exception &ex){
	  cout<<ex.what()<<endl;
	}
}
