#include <imgui/imgui.h>
#include <iostream>

ImGuiContext* imgui_context;

int main() {
	imgui_context = ImGui::CreateContext();
	std::cout << imgui_context << '\n';
}