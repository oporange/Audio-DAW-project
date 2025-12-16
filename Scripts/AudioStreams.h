#pragma once

struct AudioStream
{
	PaStream* stream;
	PaError err;

	static int AudioBuffer( // actuall stream data - processes audio waveform to be sent to output
		const void* input, void* output,
		unsigned long frameCount,
		const PaStreamCallbackTimeInfo* timeInfo,
		PaStreamCallbackFlags statusFlags,
		void* userData)
{
		AudioData* data = (AudioData*)userData;
		float* out = (float*)output;
		(void)input; /* Prevent unused variable warning. */
		(void)timeInfo;
		(void)statusFlags;
		(void)data;
		for (unsigned long i = 0; i < frameCount; i++)
		{
			*out++ = sin(data->L); /* left */   // divide by 2 to reduce volume
			*out++ = sin(data->R); /* right */      // twice as loud on right channel

			data->L = LoadedFiles[0].samples[0][FrameCounter % LoadedFiles[0].getNumSamplesPerChannel()];
			data->R = LoadedFiles[0].samples[1][FrameCounter % LoadedFiles[0].getNumSamplesPerChannel()];

			FrameCounter++;
		}
		return paContinue;
	}

	void Init(int Channels = 0, int SampleRate = 44100, int FrameBuffer = 256)
	{
		AudioData data; // L, R stuct data
		err = Pa_OpenDefaultStream( // open a stream based on default audio device and settings
			&stream,
			Channels,          /* no input channels */
			2,          /* stereo output */
			paFloat32,  /* 32 bit floating point output */
			SampleRate,		/* sample rate */
			FrameBuffer,        /* frames per buffer */
			AudioBuffer,
			&data);		/* user data */
	}

	void Start()
	{
		err = Pa_StartStream(stream);	// start audio stream
	}
	void Stop()
	{
		Pa_StopStream(stream); // stop audio stream
	}
};