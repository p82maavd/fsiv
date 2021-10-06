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
	int min=kernel.cols/2*(-1);
	int max=kernel.cols/2;
	int size=kernel.cols*kernel.cols;
	
	for( int r=0;r<in.rows;r++){
		uchar *ptr3=out.ptr<uchar>(r);
		for( int c=0;c<in.cols;c++){
			
			for(int i=min; i<=max; i++){
				ptr=in.ptr<uchar>(r+i);
				ptr2=kernel.ptr<float>(i+kernel.cols/2);
				for(int j=min; j<=max; j++){
						
					if(r+i>=0 && r+i<=in.rows && c+j>=0 && c+j<=in.cols ){
						
						media+=(ptr[c+j]*ptr2[j+max]);
						
					}
				}
			}
			ptr3[c]=media/size;
			
			media=0.0;
			
				
		}
	}


}

/*****************
   * @param coll a collection of Comparable objects
   * @param n  the position of the desired object, using the ordering defined on the list elements
   * @return the nth smallest object
   *******************/
   
   int nth(vector<int> coll, int n) {
      int result, pivot;
      vector<int> underPivot, overPivot, equalPivot;
      
      // choosing a pivot is a whole topic in itself.
      // this implementation uses the simple strategy of grabbing something from the middle of the ArrayList.
      
      pivot = coll[n/2];
      
      // split coll into 3 lists based on comparison with the pivot
      
      for (auto obj : coll) {
         int order = obj-pivot;
         
         if (order < 0)        // obj < pivot
            underPivot.push_back(obj);
         else if (order > 0){   // obj > pivot
            overPivot.push_back(obj);
         }
         else                  // obj = pivot
            equalPivot.push_back(obj);
      } // for each obj in coll
      
      // recurse on the appropriate list
      
      if (n < underPivot.size())
         result = nth(underPivot, n);
      else if (n < underPivot.size() + equalPivot.size()) // equal to pivot; just return it
         result = pivot;
      else  // everything in underPivot and equalPivot is too small.  Adjust n accordingly in the recursion.
         result = nth(overPivot, n - underPivot.size() - equalPivot.size());
         
      return result;
   } // nth(coll, n)

/****************
   * @param coll an ArrayList of Comparable objects
   * @return the median of coll
   *****************/
   
   int medianC(vector<int> coll) {
      double result;
      int n = coll.size()/2;
      
      if (coll.size() % 2 == 0)  // even number of items; find the middle two and average them
         result = (nth(coll, n-1));
      else                      // odd number of items; return the one in the middle
         result = nth(coll, n);
         
      return result;
   } // median(coll)
   
   



void medianFilter(cv::Mat &in,cv::Mat &out, int size){


	float media=0.0;
	uchar *ptr;
	float *ptr2;
	int min=size/2*(-1);
	int max=size/2;
	
	vector<int> median;
	
	for( int r=0;r<in.rows;r++){
		uchar *ptr2=out.ptr<uchar>(r);
		for( int c=0;c<in.cols;c++){
			
			for(int i=min; i<=max; i++){
				ptr=in.ptr<uchar>(r+i);
				for(int j=min; j<=max; j++){
						
					if(r+i>=0 && r+i<=in.rows && c+j>=0 && c+j<=in.cols ){
						
						median.push_back(ptr[c+j]);
						
					}
				}
			}
			//sort (median.begin(), median.end());
			//ptr2[c]=median[median.size()/2];
			ptr2[c]=medianC(median);
			
			median.clear();
			
				
		}
	}


}
int main(int argc,char **argv){
	try{
	
		if(argc!=3) {cerr<<"Usage:image kernel_size"<<endl;return 0;} 

		if(atoi(argv[2])%2==0) {cerr<<"kernel_size must be odd"<<endl;return 0;} 
		
		cv::Mat image, boxFilterImage, medianFilterImage;
		
		
		cv::Mat kernel(atoi(argv[2]), atoi(argv[2]), CV_32FC1,1.0f);

		//Load the image 
		image=cv::imread(argv[1]);
		//Change image to grayscale 
		cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
		image.copyTo(boxFilterImage);
		image.copyTo(medianFilterImage);

		applyKernel(image,boxFilterImage,kernel);
		medianFilter(image,medianFilterImage,atoi(argv[2]));
		
		cv::imshow("Input Image",image);
		cv::imshow("Box Filter Image",boxFilterImage);
		cv::imshow("Median Filter Image",medianFilterImage);
		char c=0;
		while(c!=27)  //waits until ESC pressed
			c=cv::waitKey(0);

	}catch(std::exception &ex){
	  cout<<ex.what()<<endl;
	}
}


//https://stackoverflow.com/questions/11955728/how-to-calculate-the-median-of-an-array