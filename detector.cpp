
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;
int BUFSIZE = 7168;

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
	int array_length = BUFSIZE;

	// *** how to build filter opencv c++
	
	float dummy_query_data[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	Mat dummy_query = Mat(2, 4, CV_32F, dummy_query_data);

	cout << dummy_query.at<float>(0,2) << endl;
	cout << dummy_query << endl;

	// 1. transform buff16 to fft
	// 2. filter fft
	// 3. classify signal from condition
	
	// float dummy_query_data[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	// cv::Mat dummy_query = cv::Mat(BUFSIZE, 1, CV_32S,buff16); // CV_32F

	// cout << dummy_query.at<float>(0,2) << endl;
	// cout << dummy_query << endl;

	// features:
	// MAX VALUE:
	/*
	cout << "-------------------------------------"  << endl;
	int i = 0;

	for (int i = 0; i <= array_length; i++) {
		cout << i << ", " << buff16[i] << endl;
	}
	*/
	return 0;
}


int main()
{
	FILE * infile = fopen("audio.wav","rb");		// Open wave file in read mode
	int count = 0;						// For counting number of frames in wave file.
	short int buff16[BUFSIZE];				// short int used for 16 bit as input data format is 16 bit PCM audio
	header_p meta = (header_p)malloc(sizeof(header));	// header_p points to a header struct that contains the wave file metadata fields
	int nb;							// variable storing number of byes returned
	if (infile)
	{
		fread(meta, 1, sizeof(header), infile);

		// READ Chunks of data
		while (!feof(infile))
		{
			nb = fread(buff16,2,BUFSIZE,infile);		// Reading data in chunks of BUFSIZE
			cout << nb << endl;
			bool a;
			count++;
			a = detect(buff16);
			if(a)
			{
				break;
			}
		}
		
		cout << " Size of Header file is "<<sizeof(*meta)<<" bytes" << endl;
		cout << " Sampling rate of the input wave file is "<< meta->sample_rate <<" Hz" << endl;
		cout << " Number of samples in wave file are " << meta->subchunk2_size << " samples" << endl;
		cout << " Number of frames in the input wave file are " <<count << endl;
	}
	return 0;
}

