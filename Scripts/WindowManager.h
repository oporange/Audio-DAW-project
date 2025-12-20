#pragma once

SDL_Window* SDL_WINDOW;
void OpenWindow()
{
	// SDL window creation
	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_WINDOW = SDL_CreateWindow("DAW", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 800, window_flags);

	// sdl openGL context window
	SDL_GLContext gl_context = SDL_GL_CreateContext(SDL_WINDOW);

	// Setup Platform/Renderer backends
	ImGui_ImplSDL2_InitForOpenGL(SDL_WINDOW, gl_context);
	ImGui_ImplOpenGL2_Init();
}