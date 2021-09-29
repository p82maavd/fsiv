#include <opencv2/core/core.hpp> //core routines
#include <opencv2/highgui/highgui.hpp>//imread,imshow,namedWindow,waitKey
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <iostream>
using namespace std;



int main(int argc,char **argv){
	try{
	
		if(argc!=2) {cerr<<"Usage:image"<<endl;return 0;} 
		
		cv::Mat image, grayimage;



		//Load the image 
		image=cv::imread(argv[1]);
		//Change image to grayscale 
		cv::cvtColor(image, grayimage, cv::COLOR_BGR2GRAY);

cv::Mat im2;
		cv::equalizeHist(grayimage,im2);
		cv::imshow("equalizeHist function Image",im2);

		
		vector<int> colors(256);
		vector<int> sumcolors(256);
		//Getting the histogram
		for( int r=0;r<grayimage.rows;r++){
				uchar *ptr=grayimage.ptr<uchar>(r);
			for( int c=0;c<grayimage.cols;c++){
				colors[ptr[c]]++;
				
			}
		}

		//Getting the sum cumulative function
		int suma =0;
		for ( int i =0;i<256;i++){
			suma+=colors[i];
			sumcolors[i]=suma;
		}

		//Adjusting the sum cumulative function to have a height(y axis) of 255 
		int division=sumcolors[255]/255;
		for ( int i =0;i<256;i++){
			
			sumcolors[i]/=division;
		}

		//We change the color for 
		for( int x=0;x<grayimage.rows;x++){
				uchar *ptr=grayimage.ptr<uchar>(x);
			for( int y=0;y<grayimage.cols;y++){
				ptr[y]=sumcolors[ptr[y]];
				
			}
		}
		
		
		cv::imshow("Equalized Image",grayimage);
		char c=0;
		while(c!=27)  //waits until ESC pressed
			c=cv::waitKey(0);

	}catch(std::exception &ex){
	  cout<<ex.what()<<endl;
	}
}