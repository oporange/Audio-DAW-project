#pragma once

float master_volume = 0.8f;

void ImGui_Window_Master_Load()
{
	// master window create
	ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImGui::SetNextWindowViewport(viewport->ID);


	ImGui::SetNextWindowPos(ImVec2(0, 20), ImGuiCond_Once);
	ImGui::SetNextWindowSize(ImVec2(150, 800), ImGuiCond_Once);
	ImGui::Begin("Master", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove);



	ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, (ImVec4)ImColor::HSV(master_volume, master_volume, master_volume, 1.0f));
	ImGui::PopStyleColor();

	ImGui::VSliderFloat("Master Volume", ImVec2(20,150) , &master_volume, 0.0f, 1.0f, 0, ImGuiSliderFlags_NoInput);




	ImGui::End();
}