#include <stdio.h>
#include "math.h"
#include "iostream"
#include "vector"
#include "Windows.h"

#include "portaudio.h"

#include "AudioFile-master/AudioFile.h"

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl2.h"


#include "SDL.h"
#include "SDL_opengl.h"

#include "Scripts/InitAndClose.h"
#include "Scripts/WindowManager.h"
#include "Scripts/AudioData.h"
#include "Scripts/AudioStreams.h"
#include "Scripts/WaveTestyStuff.h"
#include "Scripts/ImGui_MainWindow.h"

#undef main

int main()
{
	Init();
	OpenWindow();

	while (true) {
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			ImGui_ImplSDL2_ProcessEvent(&event);
			if (event.type == SDL_QUIT)
				return 0;
		}
		//imgui INIT loop
		ImGui_ImplOpenGL2_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		ImGui::NewFrame();
		ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);


		ImGui_MainWindow();

		ImGui::Render();
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
		SDL_GL_SwapWindow(SDL_WINDOW);
	}

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