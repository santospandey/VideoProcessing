cmake_minimum_required(VERSION 3.10.2)
project(photo-merger C CXX)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/glfw)

if(APPLE)
    list(APPEND EXTRA_LIBS 
        "-framework OpenGL"
    )
elseif(WIN32)
    list(APPEND EXTRA_LIBS
        "-lglu32 -lopengl32"
    )
    set(CMAKE_EXE_LINKER_FLAGS "-std=gnu99 -static -static-libgcc -static-libstdc++ -mwindows")
else()
    list(APPEND EXTRA_LIBS 
        "-lGL -lGLU -lX11"
    )
endif()

add_executable(photo-merger src/main.cpp)
target_link_libraries(photo-merger glfw ${EXTRA_LIBS})