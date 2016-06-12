#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <tiobj.hpp>
#include <unistd.h>
#include <tiobj-cv.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;



int main(){
	//TiObj params( getenv("params") );

	Mat image;
	string buffer;
	while( cin.good() ){
		cin >> buffer;
		TiObj input(true, "image");

		if ( input.is("Mat") ){
			image << input;
			imshow("image", image);
			waitKey(20);
		} else {
			for (int i=0; i<input.size(); i++){
				TiObj node = input.box(i);
				if ( node.is("Mat") ){
					image << node;
					imshow( Join("image%s").at(i).ok, image);
					waitKey(20);
				}
			}
		}
		//cout << "#end\n";
		//fflush(stdout);
	}


	return 0;
}
