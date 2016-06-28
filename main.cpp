#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char ** argv)
{

	float dummy_query_data[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	Mat dummy_query = Mat(2, 4, CV_32F, dummy_query_data);

	cout << dummy_query.at<float>(0,2) << endl;
	cout << dummy_query << endl;

	// void dft(InputArray src, OutputArray dst, int flags=0, int nonzeroRows=0)
	//
	
	return 0;
}
