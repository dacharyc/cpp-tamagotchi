cmake_minimum_required(VERSION 3.28.3)

project(cpp-tomagotchi)

set(CMAKE_CXX_STANDARD 17)

Include(FetchContent)

FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v5.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(cpp-tomagotchi
        main.cpp
        screens/onboarding.hpp
        screens/onboarding.cpp
        screens/pet-shop.hpp
        screens/pet-shop.cpp
        screens/menagerie.hpp
        screens/menagerie.cpp
)

target_link_libraries(cpp-tomagotchi 
        PRIVATE ftxui::dom
        PRIVATE ftxui::screen
        PRIVATE ftxui::component
)
