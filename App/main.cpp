#include "main.h"

EGLBoolean App::h_EglSwapBuffers(EGLDisplay display, EGLSurface surface) {

    if(!egl.renderInitialized) {

        eglQuerySurface(display, surface, EGL_WIDTH, &egl.width);
        eglQuerySurface(display, surface, EGL_HEIGHT, &egl.height);

        ImGui::CreateContext();

        ImGuiIO &io = ImGui::GetIO();

        io.IniFilename = nullptr;

        ImGui_ImplAndroid_Init(ImVec2((float) egl.width, (float) egl.height));
        ImGui_ImplOpenGL3_Init();

        egl.renderInitialized = true;

    }

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame();

    ImGui::NewFrame();

    DrawWatermark();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    ImGui::EndFrame();

    return o_EglSwapBuffers(display, surface);

}

bool App::Initialize() {

    if (!IL2CPP::Initialize(true)) {
        return false;
    }

    o_EglSwapBuffers = eglSwapBuffers;

    auto* egl_symbol = reinterpret_cast<void*>(eglSwapBuffers);

    if (!egl_symbol) {
        return false;
    }

    if (DobbyHook(egl_symbol,reinterpret_cast<void*>(h_EglSwapBuffers),reinterpret_cast<void**>(&o_EglSwapBuffers)) == 0) {
        return true;
    } else {
        return false;
    }

}

__attribute__((constructor)) void init() {

    std::thread([] {

        if (!App::Initialize()) {
            LOGE("Failed to initialize hooks");
        }

    }).detach();

}