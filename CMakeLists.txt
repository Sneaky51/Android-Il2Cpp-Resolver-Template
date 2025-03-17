cmake_minimum_required(VERSION 3.22.1)

project("resolver") # Here you can rename the project

set(Dobby ${CMAKE_CURRENT_SOURCE_DIR}/App/Dobby/libs/${CMAKE_ANDROID_ARCH_ABI}/libdobby.a)

set(ImGUI ${CMAKE_CURRENT_SOURCE_DIR}/App/ImGUI/imgui.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/App/ImGUI/imgui_demo.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/App/ImGUI/imgui_draw.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/App/ImGUI/imgui_tables.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/App/ImGUI/imgui_widgets.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/App/ImGUI/imgui_impl_opengl3.cpp
          ${CMAKE_CURRENT_SOURCE_DIR}/App/ImGUI/imgui_impl_android.cpp
)

set(App ${CMAKE_CURRENT_SOURCE_DIR}/App/main.cpp)


add_library(${CMAKE_PROJECT_NAME} SHARED

          ${App}
          ${ImGUI}

)

target_link_libraries(${CMAKE_PROJECT_NAME} ${Dobby} android EGL GLESv3 log)