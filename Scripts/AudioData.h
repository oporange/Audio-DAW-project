#pragma once

std::vector<AudioFile<double>> LoadedFiles;
int FrameCounter = 0;

typedef struct AudioData
{
	float L;
	float R;
};

struct AudioFileDataReturn
{

};