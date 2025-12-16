#include <stdio.h>
#include "math.h"
#include "iostream"
#include "vector"

#include "portaudio.h"
#include "AudioFile-master/AudioFile.h"

#include "Scripts/InitAndClose.h"
#include "Scripts/AudioData.h"
#include "Scripts/AudioStreams.h"
#include "Scripts/WaveTestyStuff.h"


int main()
{
	Init();


	AudioFile<double> file;
	file.load("vine-boom.wav");
	file.printSummary();
	LoadedFiles.resize(1);

	AudioStream stream;
	stream.Init();
	LoadedFiles[0] = file;
	stream.Start();
	printf("Press Enter to stop\n");
	getchar();
	stream.Stop();

	Exit();
	return 0;
}