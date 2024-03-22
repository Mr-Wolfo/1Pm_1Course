cmake_minimum_required(VERSION 3.25)

set (PROJECT_NAME 5_Task)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DSFML_STATIC)
include_directories("SFML/include")
include_directories("inc")
include_directories("src")
link_directories("SFML/lib")

add_executable("${PROJECT_NAME}" main.cpp inc/Launcher.hpp inc/Circle.hpp src/Launcher.cpp src/Circle.cpp)

target_link_libraries("${PROJECT_NAME}" sfml-graphics-s-d
		sfml-window-s-d
		sfml-system-s-d
		opengl32
		freetype
		winmm
		gdi32
		sfml-audio-s-d
		openal32
		flac
		vorbisenc
		vorbisfile
		vorbis
		ogg)