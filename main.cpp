#include <stdio.h>
#include "math.h"
#include "iostream"

#include "portaudio.h"
#include "AudioFile-master/AudioFile.h"

#include "Scripts/InitAndClose.h"
#include "Scripts/WaveTestyStuff.h"


int main()
{
	Init();


	AudioFile<double> file;
	file.load("vine-boom.wav");
	file.printSummary();

	Exit();
	return 0;
}