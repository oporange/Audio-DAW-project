#include <stdio.h>
#include "math.h"
#include "iostream"
#include "vector"
#include "Windows.h"

#include "portaudio.h"

#include "AudioFile-master/AudioFile.h"

#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_opengles2.h"

#ifndef IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_DEFINE_MATH_OPERATORS
#endif
#include "imgui-master/imgui.h"
#include "imgui-master/imgui.cpp"
#include "imgui-master/backends/imgui_impl_sdl2.cpp"
#include "imgui-master/backends/imgui_impl_opengl3.cpp"
#include "imgui-master/backends/imgui_impl_sdl2.h"
#include "imgui-master/backends/imgui_impl_opengl3.h"

#include "Scripts/InitAndClose.h"
#include "Scripts/WindowManager.h"
#include "Scripts/AudioData.h"
#include "Scripts/AudioStreams.h"
#include "Scripts/WaveTestyStuff.h"

#undef main

int main()
{
	Init();

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
	}

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	ImGui::ShowDemoWindow();


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