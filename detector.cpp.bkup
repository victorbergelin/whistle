#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

const char* FILENAME = "Sound/whistle_boing.wav";
int BUFSIZE = 716800;

// WAVE PCM soundfile format (you can find more in https://ccrma.stanford.edu/courses/422/projects/WaveFormat/ )
typedef struct header_file
{
	char chunk_id[4];
	int chunk_size;
	char format[4];
	char subchunk1_id[4];
	int subchunk1_size;
	short int audio_format;
	short int num_channels;
	int sample_rate;			// sample_rate denotes the sampling rate.
	int byte_rate;
	short int block_align;
	short int bits_per_sample;
	char subchunk2_id[4];
	int subchunk2_size;			// subchunk2_size denotes the number of samples.
} header;

typedef struct header_file* header_p;


bool detect(short int buff16[])
{
	// Convert to Mat:
	cv::Mat data_mat = cv::Mat(1, BUFSIZE, CV_16S, buff16);
	
	if(data_mat.empty())
		return -1;

	// Size:
	/* 
	cv::Size s = data_mat.size();
	int rows = s.height;
	int cols = s.width;
	*/ 

	  
	// DFT:
	cv::Mat planes[] = {Mat_<float>(data_mat), Mat::zeros(data_mat.size(), CV_32F)};
	cv::Mat complexI;
	merge(planes, 2, complexI); 
	cv::dft(complexI, complexI);

	split(complexI, planes);                   	// planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
	magnitude(planes[0], planes[1], planes[0]);	// planes[0] = magnitude
	Mat magI = planes[0];

	cv::Size s = magI.size();
	int rows = s.height;
	int cols = s.width;
	int crop = cols/2;

	// cout << rows << " " << cols << endl; // " " << magI <<  endl; 
	// NOT NEEDED // magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));

	// Save DFT:

	ofstream myfile;
	myfile.open ("dft.csv");
	myfile << magI;
		// myfile << magI(cv::Rect(0, 3608));
	myfile.close();

	// ---------------
	// Find peaks in frequencies of magI: 

	// 1. separate frequences in 1.5-2kHz band
	
	// 2. look at strong contineus signal

}

int main()
{
	// ---------
	float dummy_query_data[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	cv::Mat dummy_query = cv::Mat(2, 4, CV_32F, dummy_query_data);

	cout << dummy_query.at<float>(0,2) << endl;
	cout << dummy_query << endl;
	// ---------
	
	// FILE * infile = fopen("audio.wav","rb");		// Open wave file in read mode
	FILE * infile = fopen(FILENAME,"rb");		// Open wave file in read mode



	int count = 0;						// For counting number of frames in wave file.
	short int buff16[BUFSIZE];				// short int used for 16 bit as input data format is 16 bit PCM audio
	header_p meta = (header_p)malloc(sizeof(header));	// header_p points to a header struct that contains the wave file metadata fields
	int nb;							// variable storing number of byes returned
	if (infile)
	{
		fread(meta, 1, sizeof(header), infile);
		cout << " Size of Header file is "<<sizeof(*meta)<<" bytes" << endl;
		cout << " Sampling rate of the input wave file is "<< meta->sample_rate <<" Hz" << endl;
		cout << " Number of samples in wave file are " << meta->subchunk2_size << " samples" << endl;

		// READ Chunks of data


		//while (!feof(infile))
		//{
			nb = fread(buff16,1,BUFSIZE,infile);		// Reading data in chunks of BUFSIZE
			count++;					// Incrementing Number of frames
			bool a = detect(buff16);
		//}
		cout << sizeof(buff16) << endl;
		cout << " Number of frames in the input wave file are " << count << endl;
	}

	return 0;
}

	// FILTER: 
		//dft(complexImg, complexImg);
		// construct the filter (same size as complex image)
/*
	filter = complexI.clone();
	create_butterworth_lowpass_filter(filter, radius, order);

	// apply filter
	shiftDFT(complexImg);
	mulSpectrums(complexImg, filter, complexImg, 0);
	shiftDFT(complexImg);

	// create magnitude spectrum for display

	mag = create_spectrum_magnitude_display(complexImg, true);
*/
// create a 2-channel butterworth low-pass filter with radius D, order n
// (assumes pre-aollocated size of dft_Filter specifies dimensions)
/* 

   void create_butterworth_lowpass_filter(Mat &dft_Filter, int D, int n)
{
	Mat tmp = Mat(dft_Filter.rows, dft_Filter.cols, CV_32F);

	Point centre = Point(dft_Filter.rows / 2, dft_Filter.cols / 2);
	double radius;

	// based on the forumla in the IP notes (p. 130 of 2009/10 version)
	// see also HIPR2 on-line

	for(int i = 0; i < dft_Filter.rows; i++)
	{
		for(int j = 0; j < dft_Filter.cols; j++)
		{
			radius = (double) sqrt(pow((i - centre.x), 2.0) + pow((double) (j - centre.y), 2.0));
			tmp.at<float>(i,j) = (float)
				( 1 / (1 + pow((double) (radius /  D), (double) (2 * n))));
		}
	}

	Mat toMerge[] = {tmp, tmp};
	merge(toMerge, 2, dft_Filter);
}
*/

