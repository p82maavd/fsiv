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
			
			for(int i=-1; i<1; i++){
				ptr=in.ptr<uchar>(r+i);
				ptr2=kernel.ptr<float>(i+1);
				for(int j=-1; j<1; j++){
					
					
					if(r+i>=0 && r+i<=in.rows && c+j>=0 && c+j<=in.cols ){
						
						
						media+=ptr[c+j]*ptr2[j+1];
					}
				}
			}
			ptr3[c]=media/9;
			media=0.0;
			
				
		}
	}


}
int main(int argc,char **argv){
	try{
	
		if(argc!=2) {cerr<<"Usage:image"<<endl;return 0;} 
		
		cv::Mat image, outImage;
		//kernel.type=cv_32F
		cv::Mat kernel(3, 3, CV_32F,cvScalar(1));

		//Load the image 
		image=cv::imread(argv[1]);
		//Change image to grayscale 
		cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
		image.copyTo(outImage);
		float data=0.0;
		/*for( int r=0;r<kernel.rows;r++){
			uchar *ptr=kernel.ptr<uchar>(r);
			cout<< "Introduce los valores para el kernel: "<<endl;

			for( int c=0;c<kernel.cols;c++){
				cout <<"Valor para ["<<r<<"]["<<c<<"]: ";
				cin>>data;
				ptr[c]=data;
				
			}
		}*/

		applyKernel(image,outImage,kernel);
		
		cv::imshow("Input Image",image);
		cv::imshow("Output Image",outImage);
		char c=0;
		while(c!=27)  //waits until ESC pressed
			c=cv::waitKey(0);

	}catch(std::exception &ex){
	  cout<<ex.what()<<endl;
	}
}