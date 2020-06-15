#pragma once
#include "common/Typedefs.h"
#include <imgui.h>
#include "ImGuiConfig.h"
#include <IconsFontAwesome5_c.h>

class ImGuiFont
{
public:
    ImGuiFont(f32 size) : size_(size) {}

    void SetFont(ImFont* font) { ptr_ = font; }
    ImFont* GetFont() { return ptr_; }
    [[nodiscard]] f32 Size() const { return size_; }
    void Push() const { ImGui::PushFont(ptr_); }
    void Pop() const { ImGui::PopFont(); }
    void Load(const ImGuiIO& io, const ImFontConfig* font_cfg_template, const ImWchar* glyph_ranges)
    {
        //Load normal font
        io.Fonts->AddFontFromFileTTF(gui::FontPath, size_);
        //Load FontAwesome image font and merge with normal font
        ptr_ = io.Fonts->AddFontFromFileTTF(gui::FontAwesomeFontPath, size_, font_cfg_template, glyph_ranges);
    }

private:
    ImFont* ptr_ = nullptr;
    f32 size_ = 12.0f;
};

class ImGuiFontManager
{
public:
    void RegisterFonts();

    //Default font size
    ImGuiFont FontSmall{ 17.0f };
    ImGuiFont FontDefault{ 17.0f };

    //Fonts larger than the default font //Note: Most disabled for now since not needed yet and increases load time + mem usage
    ImGuiFont FontL{ 27.0f };
    ImGuiFont FontXL{ 34.5f };
    //ImGuiFont FontXXL(42.0f);
    //ImGuiFont FontXXXL(49.5f);
    //ImGuiFont FontXXXXL(57.0f);
    //ImGuiFont FontXXXXXL(64.5f);
    //ImGuiFont FontXXXXXXL(72.0f);
};