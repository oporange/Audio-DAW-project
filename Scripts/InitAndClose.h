#pragma once

void Init() 
{
	Pa_Initialize();
}

void Exit()
{
	Pa_Terminate();
}