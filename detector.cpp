
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "opencv2/opencv.hpp"

using namespace std;

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


bool detect(short int buff16[],length = )
{
	for (int i = 
	cout << buff16 << endl;
}



int main()
{
	FILE * infile = fopen("audio.wav","rb");		// Open wave file in read mode

	int BUFSIZE = 7168;

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


		while (!feof(infile))
		{
			nb = fread(buff16,1,BUFSIZE,infile);		// Reading data in chunks of BUFSIZE

			// OPEN CV operations on each chunk


			//			cout << count <<endl;
			count++;					// Incrementing Number of frames
			/* Insert your processing code here*/
			bool a = detect(buff16);
		}
		cout << sizeof(buff16) << endl;
		cout << " Number of frames in the input wave file are " <<count << endl;
	}
	return 0;
}

