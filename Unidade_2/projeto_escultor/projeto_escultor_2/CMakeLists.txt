cmake_minimum_required(VERSION 3.16)

project(projeto_escultor_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(projeto_escultor_2 main.cpp
    figurageometrica.h figurageometrica.cpp
    putvoxel.h putvoxel.cpp
    cutvoxel.h cutvoxel.cpp
    putbox.h putbox.cpp
    cutbox.h cutbox.cpp
    putsphere.h putsphere.cpp
    cutsphere.h cutsphere.cpp
    putellipsoid.h putellipsoid.cpp
    cutellipsoid.h cutellipsoid.cpp)

include(GNUInstallDirs)
install(TARGETS projeto_escultor_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
