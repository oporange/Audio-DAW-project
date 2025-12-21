#pragma once
void Init() 
{
	//audio stream init
	Pa_Initialize();

	//SDL INIT
	SDL_Init(SDL_INIT_EVERYTHING);

	//dear imgui init
	// 
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
}

void Exit()
{
	//audio stream shutdown
	Pa_Terminate();


	//imgui shutdown
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
}