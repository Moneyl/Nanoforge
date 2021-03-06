#include "StatusBar.h"

StatusBar::StatusBar()
{

}

StatusBar::~StatusBar()
{

}

void StatusBar::Update(GuiState* state, bool* open)
{
    //Parent window flags
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse
        | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove
        | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImVec2 viewSize = viewport->WorkSize;
    ImVec2 size = viewport->WorkSize;
    size.y = state->StatusBarHeight;
    ImVec2 pos = viewport->WorkPos;
    pos.y += viewSize.y - state->StatusBarHeight;

    ImGui::SetNextWindowPos(pos);
    ImGui::SetNextWindowSize(size);
    ImGui::SetNextWindowViewport(viewport->ID);


    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(4.0f, 6.0f));

    //Set color based on status
    switch (state->Status)
    {
    case Ready:
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.48f, 0.8f, 1.0f));
        break;
    case Working:
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.79f, 0.32f, 0.0f, 1.0f));
        break;
    case Error:
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.8f, 0.0f, 0.0f, 1.0f));
        break;
    default:
        throw std::out_of_range("Error! Status enum in MainGui has an invalid value!");
    }

    ImGui::Begin("Status bar window", open, window_flags);
    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2);

    //If custom message is empty, use the default ones
    if (state->CustomStatusMessage == "")
    {
        switch (state->Status)
        {
        case Ready:
            ImGui::Text(ICON_FA_CHECK " Ready");
            break;
        case Working:
            ImGui::Text(ICON_FA_SYNC " Working");
            break;
        case Error:
            ImGui::Text(ICON_FA_EXCLAMATION_TRIANGLE " Error");
            break;
        default:
            throw std::out_of_range("Error! Status enum in MainGui has an invalid value!");
        }
    }
    else //Else use custom one
    {
        ImGui::Text(state->CustomStatusMessage.c_str());
    }

    ImGui::End();
}