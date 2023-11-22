cmake_minimum_required(VERSION 3.22)

project(lab-2-oop-sfml LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11) # Версия стандарта C++

set(SOURCE_EXE src/main.cpp) # Установка переменной со списком исходников для исполняемого файла

set(SOURCE_LIB src/Object.cpp
               src/Entity.cpp
               src/Player.cpp
               src/Item.cpp
               src/Engine.cpp
) # Установка переменной со списком исходников для библиотеки

add_library(lib STATIC ${SOURCE_LIB}) # Создание статической библиотеки

add_executable(${PROJECT_NAME} ${SOURCE_EXE})

find_package (SFML 2.5 COMPONENTS graphics audio network REQUIRED)

target_link_libraries (${PROJECT_NAME} lib sfml-system sfml-graphics sfml-audio sfml-network)