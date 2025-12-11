#pragma once
typedef struct {
	float L;
	float R;
}
PaTestData;

static int patestCallback( // actuall stream data - processes audio waveform to be sent to output
	const void* input, void* output,
	unsigned long frameCount,
	const PaStreamCallbackTimeInfo* timeInfo,
	PaStreamCallbackFlags statusFlags,
	void* userData)
{
	PaTestData* data = (PaTestData*)userData;
	float* out = (float*)output;
	(void)input; /* Prevent unused variable warning. */
	(void)timeInfo;
	(void)statusFlags;
	(void)data;
	for (unsigned long i = 0; i < frameCount; i++)
	{
		*out++ = sin(data->L) / 2; /* left */   // divide by 2 to reduce volume
		*out++ = sin(data->R); /* right */      // twice as loud on right channel

		data->L += 3.6f * 0.0174533f;  //3.6 degrees to radians
		data->R += 3.6f * 0.0174533f;  //3.6 degrees to radians
	}
	return paContinue;
}

void RunSineWave()
{
	static PaTestData data; // L, R stuct data

	std::cout << "init" << std::endl;
	PaStream* stream; // audio stream
	PaError err; // error handling
	err = Pa_OpenDefaultStream( // open a stream based on default audio device and settings
		&stream,
		0,          /* no input channels */
		2,          /* stereo output */
		paFloat32,  /* 32 bit floating point output */
		44100,		/* sample rate */
		256,        /* frames per buffer */
		patestCallback,
		&data);		/* user data */

	err = Pa_StartStream(stream);	// start audio stream

	Pa_Sleep(5000); // sleep for 5 seconds while audio plays

	Pa_StopStream(stream); // stop audio stream
}