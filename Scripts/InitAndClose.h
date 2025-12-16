#pragma once

void Init() 
{
	//audio stream init
	Pa_Initialize();

	//dear imgui init
	// 
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Platform/Renderer backends
	ImGui_ImplSDL2_InitForOpenGL(window, YOUR_SDL_GL_CONTEXT);
	ImGui_ImplOpenGL3_Init();
}

void Exit()
{
	//audio stream shutdown
	Pa_Terminate();


	//imgui shutdown
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
}