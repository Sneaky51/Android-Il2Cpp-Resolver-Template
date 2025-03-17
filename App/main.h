#pragma once

// Core includes
#include <jni.h>
#include <string>
#include <thread>
#include <EGL/egl.h>

// Project-specific includes
#include "Utils/Logger.h"
#include "Dobby/Dobby.h"
#include "Resolver/IL2CPP_Resolver.hpp"

#include "ImGUI/imgui.h"
#include "ImGUI/imgui_impl_opengl3.h"
#include "ImGUI/imgui_impl_android.h"

using namespace Unity;

void DrawWatermark() {
    // Get the current ImGui draw list
    ImDrawList* draw_list = ImGui::GetBackgroundDrawList();

    // Define the watermark text
    const char* watermarkText = "Sneaky v1.0";

    // Define the size of the watermark box
    ImVec2 boxSize(150.0f, 40.0f); // Width and height of the box

    // Get the window dimensions
    ImVec2 windowSize = ImGui::GetIO().DisplaySize;

    // Define the position of the watermark box (bottom-right corner, with some padding)
    float padding = 10.0f;
    ImVec2 boxPos(windowSize.x - boxSize.x - padding, windowSize.y - boxSize.y - padding);

    // Define colors
    ImU32 boxColor = IM_COL32(0, 0, 0, 128); // Semi-transparent black
    ImU32 borderColor = IM_COL32(255, 255, 255, 255); // White border
    ImU32 textColor = IM_COL32(255, 255, 255, 255); // White text

    // Calculate the bottom-right corner of the box
    ImVec2 boxEnd(boxPos.x + boxSize.x, boxPos.y + boxSize.y);

    // Draw the background box
    draw_list->AddRectFilled(boxPos, boxEnd, boxColor, 5.0f); // Rounded corners with radius 5

    // Draw the border of the box
    draw_list->AddRect(boxPos, boxEnd, borderColor, 5.0f, 0, 2.0f); // Border thickness of 2

    // Calculate the position to center the text within the box
    ImVec2 textSize = ImGui::CalcTextSize(watermarkText);
    ImVec2 textPos(boxPos.x + (boxSize.x - textSize.x) / 2.0f, boxPos.y + (boxSize.y - textSize.y) / 2.0f);

    // Draw the text
    draw_list->AddText(textPos, textColor, watermarkText);
}

namespace App {

    struct Data {

        bool renderInitialized { false };
        EGLint width {}, height {};

    } egl;

    EGLBoolean (*o_EglSwapBuffers)(EGLDisplay, EGLSurface);

    EGLBoolean h_EglSwapBuffers(EGLDisplay display, EGLSurface surface);

    bool Initialize();

}